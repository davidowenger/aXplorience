#include "Common.h"
#include "Theme.h"

namespace NSDEVICE
{

OpUnitCore::OpUnitCore(Wrapper* const w)
    : OpUnit(w), mcProcessedDevice(0), mcTimeStampBTDiscovery(0), mcTimeStampBTState(0), mcInterruptDone(0), mcRunningInitializations(0),
      mcDiscovery(0), maMacInitializing(), maMacConnected(), mcState(0)
{
    mWrapper->dbh = new DBHandler(mWrapper);
    mWrapper->dbh->add<Table_Message>("Message");
    mWrapper->dbh->add<Table_Application>("Application");
    mWrapper->mBOHandlerMessage = new BOHandlerMessage(mWrapper);

    // Init a circular buffer
    mWrapper->maMessageBuzz = new ConcurrentCircularBuffer<String*>(25);
    mWrapper->maMessageUpdate = new ConcurrentCircularBuffer<String*>(25);
    mWrapper->maMessageAlive = new ConcurrentCircularBuffer<String*>(25);
}

OpUnitCore::~OpUnitCore()
{
    delete mWrapper->maMessageAlive;
    delete mWrapper->maMessageUpdate;
    delete mWrapper->maMessageBuzz;

    delete mWrapper->mBOHandlerMessage;
    delete mWrapper->dbh;
}

void OpUnitCore::run()
{
    LOGD((String("System timestamp is : #") + to_string(system_clock::now().time_since_epoch().count())).c_str());
    mWrapper->mc1Seconde = chrono::duration_cast<system_clock::duration>(chrono::seconds(1)).count();
    mWrapper->mMili = chrono::milliseconds(1);
    //mWrapper->dBluetoothAdapter = BluetoothAdapter::getDefaultAdapter();
    mWrapper->sServiceName = "Proximity service";
    mWrapper->sUuidService = "0000F9B3-0000-0000-0000-";
    mWrapper->mcBTState = 0;
    mWrapper->mcConnected = 0;
    mWrapper->mcRunningInitializations = 0;
    mWrapper->mcInterrupt = 0;
    mWrapper->mIsInterrupted = false;

    if (mWrapper->dBluetoothAdapter) {
        mWrapper->mac = parseMac(mWrapper->dBluetoothAdapter->getAddress());
        LOGD(("System MAC address is : #" + mWrapper->mac).c_str());
    }
    // Init database
    DBCollection* vaApplication = mWrapper->dbh->get("Application")->getCollection();
    DBCollection* vaMessage = mWrapper->dbh->get("Message")->getCollection();

    if (vaApplication->count()) {
        mWrapper->mDBObjectApplication = mWrapper->dbh->get("Application")->getInstance(1);
    } else {
        mWrapper->mDBObjectApplication = mWrapper->dbh->get("Application")->getInstance();
        mWrapper->mDBObjectApplication->set("sDBObjectId", "1");
        mWrapper->mDBObjectApplication->set("sView", "2");
        mWrapper->mDBObjectApplication->set("sSort0", "sTitle");
        mWrapper->mDBObjectApplication->set("sAscending0", kTrue);
        mWrapper->mDBObjectApplication->set("sSort1", "sIn");
        mWrapper->mDBObjectApplication->set("sAscending1", kTrue);
        mWrapper->mDBObjectApplication->set("sSort2", "sCategoryId");
        mWrapper->mDBObjectApplication->set("sAscending2", kTrue);
        mWrapper->mDBObjectApplication->set("sCategory0", kTrue);
        mWrapper->mDBObjectApplication->set("sCategory1", kTrue);
        mWrapper->mDBObjectApplication->set("sCategory2", kTrue);
        mWrapper->mDBObjectApplication->set("sCategory3", kTrue);
    }
    if (vaMessage->count()) {
        mWrapper->mDBObjectSeedEdit = mWrapper->dbh->get("Message")->getInstance(1);
    } else {
        mWrapper->mDBObjectSeedEdit = mWrapper->dbh->get("Message")->getInstance();
    }
    delete vaApplication;
    delete vaMessage;

    mWrapper->maSort.emplace_back(mWrapper->mDBObjectApplication->get("sSort0"), mWrapper->mDBObjectApplication->is("sAscending0"));
    mWrapper->maSort.emplace_back(mWrapper->mDBObjectApplication->get("sSort1"), mWrapper->mDBObjectApplication->is("sAscending1"));
    mWrapper->maSort.emplace_back(mWrapper->mDBObjectApplication->get("sSort2"), mWrapper->mDBObjectApplication->is("sAscending2"));

    // Start other threads
    mWrapper->maMessageAlive->add(new String("#2#3"));
    mWrapper->opUnitUI->start();
    //mWrapper->opUnitServer->start();
    mWrapper->mOpUnitAnim->start();

    if (mWrapper->mBluetoothManager) {
        mWrapper->mOpUnitNetwork->start();
    }
    handleOp();
    cancel();
}

void OpUnitCore::handleOp()
{
    Op* op;
    TimeStamp vcTimeStampNow;
    nuint vcBTState;

    while (mAlive) {
        vcTimeStampNow = system_clock::now().time_since_epoch().count();

        if (mWrapper->mcBTState && mcInterruptDone < mWrapper->mcInterrupt) {
            //mWrapper->dBluetoothAdapter->cancelDiscovery();
            mcTimeStampBTState = vcTimeStampNow;
            mcTimeStampBTDiscovery = vcTimeStampNow;
            mcState = 0;
            mcInterruptDone = mWrapper->mcInterrupt;
        }
        if (
            !mWrapper->mIsInterrupted && (!maMacConnected.size() || mWrapper->mcView == 2) &&
            vcTimeStampNow - mcTimeStampBTState > 10*mWrapper->mc1Seconde
        ) {
            vcBTState = mWrapper->dBluetoothAdapter->isEnabled();
            mWrapper->mcBTState = vcBTState + (vcBTState && mWrapper->dBluetoothAdapter->getScanMode() == mWrapper->dBluetoothAdapter->SCAN_MODE_CONNECTABLE_DISCOVERABLE);
            LOGD((String("Bluetooth state : #") + ( mWrapper->mcBTState == 2 ? "DISCOVERABLE" : ( mWrapper->mcBTState == 1 ? "ENABLED" : "OFF" ) )).c_str());
            sendOp(mWrapper->mOpUnitAppId, w->mNTheta01, new Op());
            mcState *= (bool)mWrapper->mcBTState;
            mcTimeStampBTState = vcTimeStampNow;
        }
//        if (
//            !mWrapper->mIsInterrupted && mcState == 0 && mWrapper->mcBTState &&
//            ((!maMacConnected.size() && mcRunningInitializations == 0) || vcTimeStampNow - mcTimeStampBTDiscovery > 120*mWrapper->mc1Seconde)
//        ) {
//            LOGD("startDiscovery");
//            mcDiscovery = mWrapper->mcDiscoveryDone + 1;
//            mWrapper->dBluetoothAdapter->startDiscovery();
//            mcState = 1;
//            mcTimeStampBTDiscovery = vcTimeStampNow;
//        }
//        if (
//            !mWrapper->mIsInterrupted && mcState == 1 && mWrapper->mcBTState &&
//            (mcDiscovery <= mWrapper->mcDiscoveryDone || vcTimeStampNow - mcTimeStampBTDiscovery > 20*mWrapper->mc1Seconde)
//        ) {
//            for (BluetoothDevice* vBluetoothDevice : mWrapper->maBluetoothDevice) {
//                requestAsClient(vBluetoothDevice);
//            }
//            mWrapper->maBluetoothDevice.clear();
//            mcState = 0;
//        }
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
        this_thread::sleep_for(200*mWrapper->mMili);
    }
}

OpCallback* OpUnitCore::sendOp(int vcOpUnitId, NElement* vNElement, Op* vOp)
{
    OpCallback* ret = nullptr;

    if (mAlive && vcOpUnitId == mWrapper->mOpUnitAppId) {
        vOp->mNElement = vNElement;
        mWrapper->mNActivity->sendMessage((NParam)vOp);
        ret = vOp->mOpCallback;
    } else if (mAlive && vcOpUnitId == mWrapper->mOpUnitNetworkId) {
        if (mWrapper->mBluetoothManager) {
            ret = OpUnit::sendOp(vcOpUnitId, vNElement, vOp);
        }
    } else if (mAlive) {
        ret = OpUnit::sendOp(vcOpUnitId, vNElement, vOp);
    }
    return ret;
}

String OpUnitCore::parseMac(const String& vMac)
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

void OpUnitCore::registerConnection(OpUnitPeer* vOpUnitPeer, const String& vsMac, nuint vcOrigin, bool vIsAlive)
{
    --mcRunningInitializations;
    LOGD(("Currently running initializations count : #" + to_string(mcRunningInitializations)).c_str());

    if (vIsAlive) {
        vIsAlive &= maMacConnected.emplace(vsMac).second;
        sendOp(vOpUnitPeer->mId, w->mNAlpha00, new OpParam(vIsAlive));
#ifdef DEBUG
        if (!vIsAlive) {
            String vDump;

            for (String vMac : maMacConnected) {
                 vDump += " " + vMac;
            }
            LOGD(("Connection failed because peer was already among connected mac : #" + vDump).c_str());
        }
#endif
    }
    if (vIsAlive) {
        ++mWrapper->mcConnected;
        sendOp(mWrapper->mOpUnitUIId, w->mNRho00, new OpParam(vOpUnitPeer->mId));
        mWrapper->opSquad->add(new OpUnitListener(mWrapper, vOpUnitPeer))->start();
    }
    if (vcOrigin == 1) {
        LOGD(("Removing mac of initialized peer : #" + vsMac).c_str());
        maMacInitializing.erase(vsMac);
    }
}

void OpUnitCore::requestAsClient(BluetoothDevice* vBluetoothDevice)
{
    String vMac;
    bool vIsAlive = (vBluetoothDevice != nullptr);

    if (vIsAlive) {
        vMac = parseMac(vBluetoothDevice->getAddress());
        //vIsAlive &= !maMacConnected.count(vMac);
#ifdef DEBUG
        if (!vIsAlive) {
            String vDump;

            for (String vMac : maMacConnected) {
                 vDump += " " + vMac;
            }
            LOGD(("Client canceled becaused server is already among connected mac : #" + vDump).c_str());
        }
#endif
    }
    if (vIsAlive) {
        //vIsAlive &= !maMacInitializing.count(vMac);
        //vIsAlive &= maMacInitializing.emplace(vMac).second;
#ifdef DEBUG
        if (!vIsAlive) {
            String vDump;

            for (String vMac : maMacInitializing) {
                 vDump += " " + vMac;
            }
            LOGD(("Client canceled becaused server is already among initializing mac : #" + vDump).c_str());
        }
#endif
    }
    if (vIsAlive) {
        //mWrapper->opSquad->add(new OpUnitPeer(mWrapper, vBluetoothDevice, vMac))->start();
        //LOGV(("Currently running initialization for MAC : #" + vMac).c_str());
        //++mcRunningInitializations;
        if (vMac == "E02A82CF0845" || vMac == "680571EDCCBE" || vMac == "E4B021A5443F" || vMac == "889B390B59E5") {
            LOGD(("Initializing server with MAC : #" + vMac).c_str());
            sendOp(mWrapper->mOpUnitNetworkId, w->mNAlpha00, new OpParam((NParam)vBluetoothDevice));
        }
        //maMacConnected.emplace(vMac);
        //maMacInitializing.erase(vMac);
    }
    if (vBluetoothDevice && !vIsAlive) {
        delete vBluetoothDevice;
    }
}

void OpUnitCore::requestAsServer(BluetoothServerSocket* vBluetoothServerSocket, BluetoothSocket* vBluetoothSocket)
{
    String vMac;
    BluetoothDevice* vBluetoothDevice = vBluetoothSocket->getRemoteDevice();
    bool vIsAlive = (vBluetoothDevice != nullptr);

    if (vIsAlive) {
        vMac = parseMac(vBluetoothDevice->getAddress());
        vIsAlive &= !maMacConnected.count(vMac);
#ifdef DEBUG
        if (!vIsAlive) {
            String vDump;

            for (String vMac : maMacConnected) {
                 vDump += " " + vMac;
            }
            LOGD(("Server canceled because client is already among connected mac : #" + vDump).c_str());
        }
#endif
    }
    if (vIsAlive) {
        vIsAlive &= maMacInitializing.emplace(vMac).second;
#ifdef DEBUG
        if (!vIsAlive) {
            String vDump;

            for (String vMac : maMacInitializing) {
                 vDump += " " + vMac;
            }
            LOGD(("Server canceled because client is already among initializing mac : #" + vDump).c_str());
        }
#endif
    }
    if (vIsAlive) {
        mWrapper->opSquad->add(new OpUnitPeer(mWrapper, vBluetoothServerSocket, vBluetoothSocket, vBluetoothDevice, vMac))->start();
        LOGV(("Currently running initialization for MAC : #" + vMac).c_str());
        //mWrapper->dBluetoothAdapter->cancelDiscovery();
        ++mcRunningInitializations;
    } else {
        sendOp( mWrapper->mOpUnitServerId, w->mNAlpha00, new Op());
    }
    if (vBluetoothDevice && !vIsAlive) {
       delete vBluetoothDevice;
    }
    if (vBluetoothSocket && !vIsAlive) {
       vBluetoothSocket->close();
       delete vBluetoothSocket;
    }
    if (vBluetoothServerSocket && !vIsAlive) {
       vBluetoothServerSocket->close();
       delete vBluetoothServerSocket;
    }
}

void OpUnitCore::setSettings(nuint vcBTState)
{
    if (vcBTState == 0 && mWrapper->mcBTState != 0) {
        mWrapper->dBluetoothAdapter->disable();
    }
    if (vcBTState == 1 && mWrapper->mcBTState == 0) {
        mWrapper->dBluetoothAdapter->enable();
        this_thread::sleep_for(1500*mWrapper->mMili);

        if (mWrapper->dBluetoothAdapter->getScanMode() == mWrapper->dBluetoothAdapter->SCAN_MODE_CONNECTABLE_DISCOVERABLE) {
            mWrapper->dBluetoothAdapter->discoverable(1);
        }
    }
    if (vcBTState == 1 && mWrapper->mcBTState == 2) {
        mWrapper->dBluetoothAdapter->discoverable(1);
        this_thread::sleep_for(1500*mWrapper->mMili);
    }
    if (vcBTState == 2 && mWrapper->mcBTState != 2) {
        mWrapper->dBluetoothAdapter->discoverable();
    }
    mWrapper->mcBTState = vcBTState;
    ++mWrapper->mcBTStateChange;
}

void OpUnitCore::unregisterConnection(const String& vsMac)
{
    LOGD(("Removing mac of disconnected peer : #" + vsMac).c_str());
    maMacConnected.erase(vsMac);
    --mWrapper->mcConnected;
}

// void onReceiveDiscoveryFinished()
NReturn OpUnitCore::visit(NAlpha00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    ++mWrapper->mcDiscoveryDone;
    return 0;
}

// void onReceiveFoundDevice(BluetoothDevice* dBluetoothDevice)
NReturn OpUnitCore::visit(NBeta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    mWrapper->maBluetoothDevice.emplace((BluetoothDevice*)a);
    return 0;
}

//void registerConnection(OpUnitPeer* vOpUnitPeer, const String& vsMac, nuint vcOrigin, bool vIsAlive);
NReturn OpUnitCore::visit(NGamma00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    registerConnection((OpUnitPeer*)b, ((OpMessage*)a)->mStringA, (nuint)c, (bool)d);
    return 0;
}

// void requestAsServer(BluetoothServerSocket* vBluetoothServerSocket, BluetoothSocket* vBluetoothSocket)
NReturn OpUnitCore::visit(NDelta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    requestAsServer((BluetoothServerSocket*)a, (BluetoothSocket*)b);
    return 0;
}

// void setSettings(bool vIsEnable, bool vIsDiscoverable)
NReturn OpUnitCore::visit(NEpsilon00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    setSettings((nuint)a);
    return 0;
}

// void unregisterConnection(const String& vsMac)
NReturn OpUnitCore::visit(NEta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    unregisterConnection(((OpMessage*)a)->mStringA);
    return 0;
}

} // End namespace
