#include "Common.h"
#include "Theme.h"

namespace NSDEVICE
{

OpUnitCore::OpUnitCore(Wrapper* const vWrapper)
    : OpUnit(vWrapper->mNWrapper), mcProcessedDevice(0), mcTimeStampBTDiscovery(0), mcTimeStampBTState(0), mcInterruptDone(0), mcRunningInitializations(0),
      mcDiscovery(0), mcDiscoveryDone(0), mcState(0), w(vWrapper), maMacInitializing(), maMacConnected(), maBluetoothDevice()
{
    w->mhDB = new DBHandler(w->mNWrapper);
    w->mhDB->add<Table_Message>("Message");
    w->mhDB->add<Table_Application>("Application");

    nint i = Camera::getNumberOfCameras();
    w->maCameraInfo = NArray<Camera::CameraInfo>(i);
    w->maCameraId = NArray<nint>(i);

    while (i--) {
        Camera::getCameraInfo(i, w->maCameraInfo.maData[i]);
        w->maCameraId.maData[w->maCameraInfo.maData[i].facing] = i;
    }
}

OpUnitCore::~OpUnitCore()
{
    w->maCameraInfo.discard();
    w->maCameraId.discard();
    delete w->mhDB;
}

void OpUnitCore::run()
{
    LOGD((String("System timestamp is : #") + to_string(system_clock::now().time_since_epoch().count())).c_str());
    Looper::prepare();
    w->mc1Seconde = chrono::duration_cast<system_clock::duration>(chrono::seconds(1)).count();
    w->mMili = chrono::milliseconds(1);
    w->dBluetoothAdapter = BluetoothAdapter::getDefaultAdapter();
    w->mcBTState = 0;
    w->mcInterrupt = 0;
    w->mIsInterrupted = false;

    // Init database
    DBCollection* vaApplication =  w->mhDB->get("Application")->getCollection();
    DBCollection* vaMessage =  w->mhDB->get("Message")->getCollection();

    if (vaApplication->count()) {
        w->mDBObjectApplication =  w->mhDB->get("Application")->getInstance(1);
    } else {
        w->mDBObjectApplication =  w->mhDB->get("Application")->getInstance();
        w->mDBObjectApplication->set("sDBObjectId", "1");
        w->mDBObjectApplication->set("sView", "2");
        w->mDBObjectApplication->set("sSort0", "sTitle");
        w->mDBObjectApplication->set("sAscending0", kTrue);
        w->mDBObjectApplication->set("sSort1", "sIn");
        w->mDBObjectApplication->set("sAscending1", kTrue);
        w->mDBObjectApplication->set("sSort2", "sCategoryId");
        w->mDBObjectApplication->set("sAscending2", kTrue);
        w->mDBObjectApplication->set("sCategory0", kTrue);
        w->mDBObjectApplication->set("sCategory1", kTrue);
        w->mDBObjectApplication->set("sCategory2", kTrue);
        w->mDBObjectApplication->set("sCategory3", kTrue);
    }
    if (vaMessage->count()) {
        w->mDBObjectSeedEdit =  w->mhDB->get("Message")->getInstance(1);
    } else {
        w->mDBObjectSeedEdit =  w->mhDB->get("Message")->getInstance();
    }
    delete vaApplication;
    delete vaMessage;

    w->mcConnected = 0;
    w->mac = parseMac(w->dBluetoothAdapter->getAddress());
    w->sServiceName = "Proximity service";
    w->sUuidService = "0000F9B3-0000-0000-0000-";

    w->maSort.emplace_back(w->mDBObjectApplication->get("sSort0"), w->mDBObjectApplication->is("sAscending0"));
    w->maSort.emplace_back(w->mDBObjectApplication->get("sSort1"), w->mDBObjectApplication->is("sAscending1"));
    w->maSort.emplace_back(w->mDBObjectApplication->get("sSort2"), w->mDBObjectApplication->is("sAscending2"));

    // Start other threads
    w->opUnitUI->start();
    w->opUnitServer->start();
    w->mOpUnitAnim->start();

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

        if (w->mcBTState && mcInterruptDone < w->mcInterrupt) {
            w->dBluetoothAdapter->cancelDiscovery();
            mcTimeStampBTState = vcTimeStampNow;
            mcTimeStampBTDiscovery = vcTimeStampNow;
            mcState = 0;
            mcInterruptDone = w->mcInterrupt;
        }
        if (
            !w->mIsInterrupted && (!maMacConnected.size() || w->mcView == 2) &&
            vcTimeStampNow - mcTimeStampBTState > 10*w->mc1Seconde
        ) {
            vcBTState = w->dBluetoothAdapter->isEnabled();
            w->mcBTState = vcBTState + (vcBTState && w->dBluetoothAdapter->getScanMode() == w->dBluetoothAdapter->SCAN_MODE_CONNECTABLE_DISCOVERABLE);
            LOGD((String("Bluetooth state : #") + ( w->mcBTState == 2 ? "DISCOVERABLE" : ( w->mcBTState == 1 ? "ENABLED" : "OFF" ) )).c_str());
            sendOp(w->mOpUnitAppId, w->mNWrapper->mNKrossWrapper->mNTheta01, new Op());
            mcState *= (bool)w->mcBTState;
            mcTimeStampBTState = vcTimeStampNow;
        }
        if (
            !w->mIsInterrupted && mcState == 0 && w->mcBTState &&
            ((!maMacConnected.size() && mcRunningInitializations == 0) || vcTimeStampNow - mcTimeStampBTDiscovery > 120*w->mc1Seconde)
        ) {
            LOGD("startDiscovery");
            mcDiscovery = mcDiscoveryDone + 1;
            w->dBluetoothAdapter->startDiscovery();
            mcState = 1;
            mcTimeStampBTDiscovery = vcTimeStampNow;
        }
        if (
            !w->mIsInterrupted && mcState == 1 && w->mcBTState &&
            (mcDiscovery <= mcDiscoveryDone || vcTimeStampNow - mcTimeStampBTDiscovery > 20*w->mc1Seconde)
        ) {
            for (BluetoothDevice* vBluetoothDevice : maBluetoothDevice) {
                requestAsClient(vBluetoothDevice);
            }
            maBluetoothDevice.clear();
            mcState = 0;
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
        this_thread::sleep_for(200*w->mMili);
    }
}

OpCallback* OpUnitCore::sendOp(int vcOpUnitId, NElement* vNElement, Op* vOp)
{
    OpCallback* ret = nullptr;

    if (mAlive && vcOpUnitId == w->mOpUnitAppId) {
        vOp->mNElement = vNElement;
        w->mNActivity->sendMessage((NParam)vOp);
        ret = vOp->mOpCallback;
    } else {
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
        sendOp(vOpUnitPeer->mId, w->mNWrapper->mNKrossWrapper->mNAlpha00, new OpParam(vIsAlive));
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
        ++w->mcConnected;
        sendOp(w->mOpUnitUIId, w->mNWrapper->mNKrossWrapper->mNRho00, new OpParam(vOpUnitPeer->mId));
        w->opSquad->add(new OpUnitListener(w, vOpUnitPeer))->start();
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
        vIsAlive &= !maMacConnected.count(vMac);
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
        vIsAlive &= !maMacInitializing.count(vMac);
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
        w->opSquad->add(new OpUnitPeer(w, vBluetoothDevice, vMac))->start();
        LOGV(("Currently running initialization for MAC : #" + vMac).c_str());
        ++mcRunningInitializations;
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
        w->opSquad->add(new OpUnitPeer(w, vBluetoothServerSocket, vBluetoothSocket, vBluetoothDevice, vMac))->start();
        LOGV(("Currently running initialization for MAC : #" + vMac).c_str());
        //w->dBluetoothAdapter->cancelDiscovery();
        ++mcRunningInitializations;
    } else {
        sendOp(w->mOpUnitServerId, w->mNWrapper->mNKrossWrapper->mNAlpha00, new Op());
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
    if (vcBTState == 0 && w->mcBTState != 0) {
        w->dBluetoothAdapter->disable();
    }
    if (vcBTState == 1 && w->mcBTState == 0) {
        w->dBluetoothAdapter->enable();
        this_thread::sleep_for(1500*w->mMili);

        if (w->dBluetoothAdapter->getScanMode() == w->dBluetoothAdapter->SCAN_MODE_CONNECTABLE_DISCOVERABLE) {
            w->dBluetoothAdapter->discoverable(1);
        }
    }
    if (vcBTState == 1 && w->mcBTState == 2) {
        w->dBluetoothAdapter->discoverable(1);
        this_thread::sleep_for(1500*w->mMili);
    }
    if (vcBTState == 2 && w->mcBTState != 2) {
        w->dBluetoothAdapter->discoverable();
    }
    w->mcBTState = vcBTState;
    ++w->mcBTStateChange;
}

void OpUnitCore::unregisterConnection(const String& vsMac)
{
    LOGD(("Removing mac of disconnected peer : #" + vsMac).c_str());
    maMacConnected.erase(vsMac);
    --w->mcConnected;
}

// void onReceiveDiscoveryFinished()
NReturn OpUnitCore::visit(NAlpha00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    ++mcDiscoveryDone;
    return 0;
}

// void onReceiveFoundDevice(BluetoothDevice* dBluetoothDevice)
NReturn OpUnitCore::visit(NBeta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    maBluetoothDevice.emplace((BluetoothDevice*)a);
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
