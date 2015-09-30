#include "Common.h"

namespace NSDEVICE
{

OpUnitNetwork::OpUnitNetwork(Wrapper* w) :
    OpUnit(w), mBuzzIndex(0), mUpdateIndex(0), mcInterruptDone(0), mcDiscovery(0), mcState(0), mcTimeStampBroadcast(0), mcTimeStampBTDiscovery(0),
    maMessageAlive(mWrapper->maMessageAlive), maMessageBuzz(mWrapper->maMessageBuzz), maMessageUpdate(mWrapper->maMessageUpdate)
{
}

OpUnitNetwork::~OpUnitNetwork()
{
}

void OpUnitNetwork::run()
{
    Op* op;
    TimeStamp vcTimeStampNow;
    bool vIsMultipleAdvertisementSupported = false;
    bool vServiceGenericAccessExists = true;
    bool vServiceGattExists = true;

    if (Build::VERSION::SDK_INT >= 18 && Build::VERSION::SDK_INT < 21) {
        mWrapper->mNetworkScanCallback = new NetworkScanCallback(mWrapper);
    }
    if (Build::VERSION::SDK_INT >= 21 && mWrapper->mBluetoothManager) {
        mWrapper->mNetworkServerCallback = new NetworkServerCallback(mWrapper);
        mWrapper->mBluetoothGattServer = mWrapper->mBluetoothManager->openGattServer(mWrapper->mNActivity, mWrapper->mNetworkServerCallback);
        LOGD(("Gatt Server at address : @" + to_string(mWrapper->mBluetoothGattServer)).c_str());
    }
    if (Build::VERSION::SDK_INT >= 21 && mWrapper->dBluetoothAdapter) {
        vIsMultipleAdvertisementSupported = mWrapper->dBluetoothAdapter->isMultipleAdvertisementSupported();
        LOGD(("Advertisement support is : #" + to_string(vIsMultipleAdvertisementSupported)).c_str());
        mWrapper->mBluetoothLeAdvertiser = mWrapper->dBluetoothAdapter->getBluetoothLeAdvertiser();
        LOGD(("Smart advertiser at address : @" + to_string(mWrapper->mBluetoothLeAdvertiser)).c_str());
    }
    if (mWrapper->mBluetoothGattServer) {
        BluetoothGattService* vServiceGenericAccess = mWrapper->mBluetoothGattServer->getService(mWrapper->mServiceGenericAccessId);

        if (!vServiceGenericAccess) {
            vServiceGenericAccessExists = false;
            LOGD(("Add Generic Access service : #" + mWrapper->mServiceGenericAccessId).c_str());
            vServiceGenericAccess = new BluetoothGattService(mWrapper->mServiceGenericAccessId, BluetoothGattService::SERVICE_TYPE_PRIMARY);
            unique_lock<mutex> vUniqueLock(mWrapper->mMutex);
            mWrapper->mBluetoothGattServer->addService(vServiceGenericAccess);
            mWrapper->mConditionServicesAdded.wait_for(vUniqueLock, 300000*mWrapper->mMili);
            vUniqueLock.unlock();
        }
        BluetoothGattCharacteristic* vCharacteristicDeviceName = vServiceGenericAccess->getCharacteristic(mWrapper->mCharacteristicDeviceNameId);

        if (!vCharacteristicDeviceName) {
            LOGD(("Add Device Name Characteristic : #" + mWrapper->mCharacteristicDeviceNameId).c_str());
            vCharacteristicDeviceName = new BluetoothGattCharacteristic(
                mWrapper->mCharacteristicDeviceNameId,
                BluetoothGattCharacteristic::PROPERTY_READ,
                BluetoothGattCharacteristic::PERMISSION_READ
            );
            vCharacteristicDeviceName->setValue(mWrapper->dBluetoothAdapter->getName());
            vServiceGenericAccess->addCharacteristic(vCharacteristicDeviceName);
        }
        BluetoothGattCharacteristic* vCharacteristicAppearance = vServiceGenericAccess->getCharacteristic(mWrapper->mCharacteristicAppearanceId);

        if (!vCharacteristicAppearance) {
            LOGD(("Add Appearance Characteristic : #" + mWrapper->mCharacteristicAppearanceId).c_str());
            vCharacteristicAppearance = new BluetoothGattCharacteristic(
                mWrapper->mCharacteristicAppearanceId,
                BluetoothGattCharacteristic::PROPERTY_READ,
                BluetoothGattCharacteristic::PERMISSION_READ
            );
            nuint vValue = 0;
            NArray<nubyte> vNArray = NArray<nubyte>(4);
            vNArray.maData[0] = *((nubyte*)&vValue + 0);
            vNArray.maData[1] = *((nubyte*)&vValue + 1);
            vCharacteristicAppearance->setValue(vNArray);
            vServiceGenericAccess->addCharacteristic(vCharacteristicAppearance);
        }
        if (!vServiceGenericAccessExists) {
            unique_lock<mutex> vUniqueLock(mWrapper->mMutex);
            mWrapper->mBluetoothGattServer->addService(vServiceGenericAccess);
            mWrapper->mConditionServicesAdded.wait_for(vUniqueLock, 300000*mWrapper->mMili);
            vUniqueLock.unlock();
        }
        BluetoothGattService* vServiceGatt = mWrapper->mBluetoothGattServer->getService(mWrapper->mServiceGattId);

        if (!vServiceGatt) {
            vServiceGattExists = false;
            LOGD(("Add GATT service : #" + mWrapper->mServiceGattId).c_str());
            vServiceGatt = new BluetoothGattService(mWrapper->mServiceGattId, BluetoothGattService::SERVICE_TYPE_PRIMARY);
        }
        BluetoothGattCharacteristic* vCharacteristicServiceChanged = vServiceGatt->getCharacteristic(mWrapper->mCharacteristicServiceChangedId);

        if (!vCharacteristicServiceChanged) {
            LOGD(("Add Service Changed Characteristic : #" + mWrapper->mCharacteristicServiceChangedId).c_str());
            vCharacteristicServiceChanged = new BluetoothGattCharacteristic(
                mWrapper->mCharacteristicServiceChangedId,
                BluetoothGattCharacteristic::PROPERTY_INDICATE||
                BluetoothGattCharacteristic::PROPERTY_READ,
                BluetoothGattCharacteristic::PERMISSION_READ
            );
            nuint vValue = (1<<16) + 65535;
            NArray<nubyte> vNArray = NArray<nubyte>(4);
            vNArray.maData[0] = *((nubyte*)&vValue + 0);
            vNArray.maData[1] = *((nubyte*)&vValue + 1);
            vNArray.maData[2] = *((nubyte*)&vValue + 2);
            vNArray.maData[3] = *((nubyte*)&vValue + 3);
            vCharacteristicServiceChanged->setValue(vNArray);
            vServiceGatt->addCharacteristic(vCharacteristicServiceChanged);
        }
        if (!vServiceGattExists) {
            unique_lock<mutex> vUniqueLock(mWrapper->mMutex);
            mWrapper->mBluetoothGattServer->addService(vServiceGatt);;
            mWrapper->mConditionServicesAdded.wait_for(vUniqueLock, 300000*mWrapper->mMili);
            vUniqueLock.unlock();
        }
        LOGD(("Add smart service : #" + mWrapper->mServiceApplicationId).c_str());
        mWrapper->mBluetoothGattService = new BluetoothGattService(mWrapper->mServiceApplicationId, BluetoothGattService::SERVICE_TYPE_PRIMARY);
        mWrapper->mBluetoothGattCharacteristic = new BluetoothGattCharacteristic(
            mWrapper->mServiceApplicationId,
            BluetoothGattCharacteristic::PROPERTY_INDICATE||
            BluetoothGattCharacteristic::PROPERTY_READ||
            BluetoothGattCharacteristic::PROPERTY_WRITE,
          //BluetoothGattCharacteristic::PROPERTY_WRITE_NO_RESPONSE,
            BluetoothGattCharacteristic::PERMISSION_READ||
            BluetoothGattCharacteristic::PERMISSION_WRITE
        );
        mWrapper->mBluetoothGattCharacteristic->setWriteType(BluetoothGattCharacteristic::WRITE_TYPE_DEFAULT);
        mWrapper->mBluetoothGattCharacteristic->setValue("test");
        mWrapper->mBluetoothGattService->addCharacteristic(mWrapper->mBluetoothGattCharacteristic);
        unique_lock<mutex> vUniqueLock(mWrapper->mMutex);
        mWrapper->mBluetoothGattServer->addService(mWrapper->mBluetoothGattService);
        mWrapper->mConditionServicesAdded.wait_for(vUniqueLock, 300000*mWrapper->mMili);
        vUniqueLock.unlock();
    }
    if (mWrapper->mBluetoothLeAdvertiser) {
        mcState = 0xFFFFFFFF;
        LOGD("Start advertising");
        AdvertiseSettings::Builder vAdvertiseSettingsBuilder = AdvertiseSettings::Builder();
        vAdvertiseSettingsBuilder.setConnectable(true);
        vAdvertiseSettingsBuilder.setTimeout(0);
        vAdvertiseSettingsBuilder.setTxPowerLevel(AdvertiseSettings::ADVERTISE_TX_POWER_HIGH);
        AdvertiseSettings* vAdvertiseSettings = vAdvertiseSettingsBuilder.build();

        AdvertiseData::Builder vAdvertiseDataBuilder = AdvertiseData::Builder();
        vAdvertiseDataBuilder.addServiceUuid(mWrapper->mServiceGattId);
        vAdvertiseDataBuilder.addServiceUuid(mWrapper->mServiceGenericAccessId);
        vAdvertiseDataBuilder.addServiceUuid(mWrapper->mServiceApplicationId);
        AdvertiseData* vAdvertiseData = vAdvertiseDataBuilder.build();

        mWrapper->mNetworkAdvertiseCallback = new NetworkAdvertiseCallback(mWrapper);
        unique_lock<mutex> vUniqueLock(mWrapper->mMutex);
        mWrapper->mBluetoothLeAdvertiser->startAdvertising(vAdvertiseSettings, vAdvertiseData, mWrapper->mNetworkAdvertiseCallback);
        mWrapper->mConditionServicesAdded.wait_for(vUniqueLock, 300000*mWrapper->mMili);
        vUniqueLock.unlock();
    }
    while (mAlive) {
        vcTimeStampNow = system_clock::now().time_since_epoch().count();

        if (mWrapper->mcBTState && mcInterruptDone < mWrapper->mcInterrupt && mcState < 0xFFFFFFFF) {
            //mWrapper->dBluetoothAdapter->cancelDiscovery();
            //mWrapper->dBluetoothAdapter->stopLeScan(mWrapper->mNetworkScanCallback);
            mcTimeStampBTDiscovery = vcTimeStampNow;
            mcState = 0;
        }
        while (mBuzzIndex != maMessageBuzz->mWriteIndex) {
            mBuzzIndex = (mBuzzIndex + 1)%maMessageBuzz->mSize;
            write(*(maMessageBuzz->read(mBuzzIndex)));
            ++mcInterruptDone;
        }
        if (!mWrapper->mIsInterrupted && mcInterruptDone == mWrapper->mcInterrupt && mUpdateIndex != maMessageUpdate->mWriteIndex) {
            mUpdateIndex = (mUpdateIndex + 1)%maMessageUpdate->mSize;
            write(*(maMessageUpdate->read(mUpdateIndex)));
        }
        if (!mWrapper->mIsInterrupted && mcInterruptDone == mWrapper->mcInterrupt && vcTimeStampNow - mcTimeStampBroadcast > 15*mWrapper->mc1Seconde) {
            mcTimeStampBroadcast = vcTimeStampNow;
            write(*(maMessageAlive->read()));
        }
        if (
            !mWrapper->mIsInterrupted && mcState == 0 && mWrapper->mcBTState && mWrapper->mcRunningInitializations == 0  &&
            ((!maMacConnected.size() && !maMacInitializing.size()) || vcTimeStampNow - mcTimeStampBTDiscovery > 120*mWrapper->mc1Seconde)
        ) {
            LOGD("startDiscovery");
            mcTimeStampBTDiscovery = vcTimeStampNow;
            mcDiscovery = mWrapper->mcDiscoveryDone + 1;
            mWrapper->dBluetoothAdapter->startDiscovery();
            //NArray<String> vNArray = NArray<String>(1);
            //vNArray.maData[0] = mWrapper->mServiceApplicationId;
//            bool status = mWrapper->dBluetoothAdapter->startLeScan(mWrapper->mNetworkScanCallback);
//            LOGD(("Start smart scan with status : #" + to_string(status)).c_str());
            mcState = 1;
        }
        op = nextOp();

        if (op) {
            execOp(op);
            op = nextOp();

            if (op) {
                execOp(op);
                op = nextOp();

                if (op) {
                    execOp(op);
                    op = nextOp();

                    if (op) {
                        execOp(op);
                    }
                }
            }
        }
        if (!mWrapper->mIsInterrupted && mcState == 1 && mWrapper->mcBTState && (mcDiscovery <= mWrapper->mcDiscoveryDone || vcTimeStampNow - mcTimeStampBTDiscovery > 20*mWrapper->mc1Seconde)) {
            for (BluetoothDevice* vBluetoothDevice : mWrapper->maBluetoothDevice) {
                addPeer(vBluetoothDevice);
            }
            mWrapper->maBluetoothDevice.clear();
            mcState = 0;
        }
        this_thread::sleep_for(200*mWrapper->mMili);
    }
    if (mWrapper->mBluetoothLeAdvertiser) {
        mWrapper->mBluetoothLeAdvertiser->stopAdvertising(mWrapper->mNetworkAdvertiseCallback);
    }
    if (mWrapper->mBluetoothGattServer) {
        mWrapper->mBluetoothGattServer->clearServices();
        mWrapper->mBluetoothGattServer->close();
    }
}

void OpUnitNetwork::addPeer(BluetoothDevice* vBluetoothDevice)
{
    String vMac = parseMac(vBluetoothDevice->getAddress());

    //DEBUG
    if (vMac == "E02A82CF0845" || vMac == "680571EDCCBE" || vMac == "E4B021A5443F" || vMac == "889B390B59E5") {
        if (vMac.size() && maMacConnected.find(vMac) == maMacConnected.end() && maMacInitializing.emplace(vMac).second) {
            LOGD(("Initializing server with MAC : #" + vMac).c_str());
            new Peer(mWrapper, vBluetoothDevice, vMac, true);
        } else {
            LOGD(("No MAC or MAC already added for server : #" + vMac).c_str());
        }
    }
}

void OpUnitNetwork::onClientStateChange(BluetoothDevice* vBluetoothDevice, int status, int newState)
{
    String vMac = parseMac(vBluetoothDevice->getAddress());

    if (status <= BluetoothGatt::STATE_CONNECTING && newState == BluetoothGatt::STATE_CONNECTED) {
        if (maMacInitializing.find(vMac) == maMacInitializing.end()) {
            if (vMac.size() && maMacConnected.find(vMac) == maMacConnected.end()) {
                // Server received status change from client
                LOGD(("Server connected to client : #" + vMac).c_str());
                maMacConnected.emplace(vMac, new Peer(mWrapper, vBluetoothDevice, vMac, false));
            } else {
                LOGD(("No MAC or MAC already added for client : #" + vMac).c_str());
                mWrapper->mBluetoothGattServer->cancelConnection(vBluetoothDevice);
            }
        } else {
            LOGD(("MAC already initializing as client for client : #" + vMac).c_str());
            //mWrapper->mBluetoothGattServer->cancelConnection(vBluetoothDevice);
        }
    } else {
        LOGD(("Connection failure or connection lost : #" + vMac).c_str());
        if (maMacConnected[vMac] && !maMacConnected[vMac]->mAsClient) {
            delete maMacConnected[vMac];
        }
        maMacInitializing.erase(vMac);
        maMacConnected.erase(vMac);
    }
}

void OpUnitNetwork::onServerStateChange(Peer* vServer, int status, int newState)
{
    if (status <= BluetoothGatt::STATE_CONNECTING && newState == BluetoothGatt::STATE_CONNECTED) {
        if (maMacConnected.find(vServer->mMac) == maMacConnected.end() && maMacInitializing.find(vServer->mMac) != maMacInitializing.end()) {
            LOGD(("Client connected to server : #" + vServer->mMac).c_str());
            maMacConnected.emplace(vServer->mMac, vServer);
            maMacInitializing.erase(vServer->mMac);
        } else {
            LOGD(("MAC already connected for server : #" + vServer->mMac).c_str());
        }
    } else {
        LOGD(("Connection failure or connection lost with server : #" + vServer->mMac).c_str());
        vServer->mBluetoothGatt->close();
        delete vServer;
    }
}

void OpUnitNetwork::onServicesDiscovered(Peer* vPeer, int status)
{
    LOGD("onServicesDiscovered");

    if (status == BluetoothGatt::GATT_SUCCESS) {
        NArray<BluetoothGattService*> vaBluetoothGattService = vPeer->mBluetoothGatt->getServices();
        nuint i;

        for (i = 0 ; i < vaBluetoothGattService.mSize ; ++i) {
            String vUUID = vaBluetoothGattService.maData[i]->getUuid();
        }
        BluetoothGattService* vBluetoothGattService = vPeer->mBluetoothGatt->getService(mWrapper->mServiceApplicationId);
        if (vBluetoothGattService) {
            LOGD(("Service discovered : #" + mWrapper->mServiceApplicationId).c_str());
            vPeer->mBluetoothGattCharacteristic = vBluetoothGattService->getCharacteristic(mWrapper->mServiceApplicationId);
        } else {
            LOGD(("Service not found : #" + mWrapper->mServiceApplicationId).c_str());
        }
        if (vPeer->mBluetoothGattCharacteristic) {
            LOGD(("Characteristic discovered : #" + mWrapper->mServiceApplicationId).c_str());
            vPeer->mBluetoothGattCharacteristic->setWriteType(BluetoothGattCharacteristic::WRITE_TYPE_DEFAULT);
            vPeer->mBluetoothGatt->setCharacteristicNotification(vPeer->mBluetoothGattCharacteristic, true);
        } else {
            LOGD(("Characteristic not found : #" + mWrapper->mServiceApplicationId).c_str());
            //vPeer->mBluetoothGatt->disconnect();
            //vPeer->mBluetoothGatt->close();
        }
    } else {
        LOGD(("Service discovery failed with status : #" + to_string(status)).c_str());
    }
}

String OpUnitNetwork::parseMac(const String& vMac)
{
    String vMacParsed;
    try {
      vMacParsed = regex_replace(vMac,regex("[^0123456789abcdefABCDEF]+"),String(""));
    }
    catch (regex_error& vError) {
        LOGE(("Regex error with code: #" + to_string<nuint>(vError.code())).c_str());
    }
    return vMacParsed;
}

void OpUnitNetwork::removePeer(Peer* vPeer)
{
    //maServer.erase(vPeer->mMac);
}

void OpUnitNetwork::scan()
{
    NArray<String> vNArray = NArray<String>(1);
    vNArray.maData[0] = mWrapper->mServiceApplicationId;
    LOGD(("Smart scan for : #" + mWrapper->mServiceApplicationId).c_str());
    mWrapper->dBluetoothAdapter->startLeScan(vNArray, mWrapper->mNetworkScanCallback);
}

void OpUnitNetwork::write(const String& vPacked)
{
    if (mWrapper->mBluetoothGattCharacteristic) {
        mWrapper->mBluetoothGattCharacteristic->setValue(vPacked);
    }
    map<String,Peer*>::iterator it = maMacConnected.begin();

    while (it != maMacConnected.end()) {
        it->second->write(vPacked);
        ++it;
    }
}

// void addPeer(BluetoothDevice* vBluetoothDevice)
NReturn OpUnitNetwork::visit(NAlpha00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    addPeer((BluetoothDevice*)a);
    return 0;
}

// void onConnectionStateChange(BluetoothDevice* dBluetoothDevice)
NReturn OpUnitNetwork::visit(NDzeta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    onServerStateChange((Peer*)a, b, c);
    return 0;
}

// void onScan();
NReturn OpUnitNetwork::visit(NGamma00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    scan();
    return 0;
}

// void onServicesDiscovered(Peer* vPeer, int status);
NReturn OpUnitNetwork::visit(NDelta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    onServicesDiscovered((Peer*)a, b);
    return 0;
}

// void onConnectionStateChange(Peer* vPeer, int status, int newstatus);
NReturn OpUnitNetwork::visit(NEpsilon00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    onClientStateChange((BluetoothDevice*)a, (int)b, (int)c);
    return 0;
}

// void onReceiveFoundDevice(BluetoothDevice* dBluetoothDevice)
NReturn OpUnitNetwork::visit(NBeta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    mWrapper->maBluetoothDevice.emplace((BluetoothDevice*)a);
    //++mWrapper->mcRunningInitializations;
    return 0;
}

} // End namespace


//        int vInstanceId = mWrapper->mBluetoothGattService->getInstanceId();
//        NArray<nubyte> vValue = NArray<nubyte>(4);
//        vValue.maData[0] = vInstanceId & 0x0000FF00;
//        vValue.maData[1] = vInstanceId & 0x000000FF;
//        vValue.maData[2] = vInstanceId & 0x0000FF00;
//        vValue.maData[3] = vInstanceId & 0x000000FF;
//        vCharacteristicServiceChanged->setValue(vValue);
//
//        vValue.maData[0] = 1<<6;
//        vValue.maData[1] = 0x00;
//        vValue.maData[2] = 0x00;
//        vValue.maData[3] = 0x00;
//        vDescriptorCCCD->setValue(vValue);


//        NArray<BluetoothGattService*> vaBluetoothGattService = mWrapper->mBluetoothGattServer->getServices();
//        nuint i;
//
//        for (i = 0 ; i < vaBluetoothGattService.mSize ; ++i) {
//            String vUUID = vaBluetoothGattService.maData[i]->getUuid();
//        }
//        BluetoothGattDescriptor* vDescriptorCCCD = vCharacteristicServiceChanged->getDescriptor(mWrapper->mDescriptorCCCDId);
//
//        if (!vDescriptorCCCD) {
//            LOGD(("Add Client Characteristic Configuration Descriptor : #" + mWrapper->mDescriptorCCCDId).c_str());
//            vDescriptorCCCD = new BluetoothGattDescriptor(
//                mWrapper->mDescriptorCCCDId,
//                BluetoothGattCharacteristic::PERMISSION_READ_ENCRYPTED||
//                BluetoothGattCharacteristic::PERMISSION_READ_ENCRYPTED_MITM
//            );
//            nuint vValue = 0;
//            NArray<nubyte> vNArray = NArray<nubyte>(2);
//            vNArray.maData[0] = *((nubyte*)&vValue + 0);
//            vNArray.maData[1] = *((nubyte*)&vValue + 1);
//            vCharacteristicServiceChanged->setValue(vNArray);
//            vCharacteristicServiceChanged->addDescriptor(vDescriptorCCCD);
//        }



