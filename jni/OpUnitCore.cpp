#include "Common.h"
#include "Theme.h"

namespace NSDEVICE
{

OpUnitCore::OpUnitCore(Wrapper* const w)
	: OpUnit(w), mcProcessedDevice(0), mcTimeStampBroadcast(0), mcForce(0), mcRunningInitializations(0), mcDiscovery(0), mcDiscoveryDone(0), maMac(), maBluetoothDevice(), mcState(0)
{
    mWrapper->dbh = new DBHandler(mWrapper);
    mWrapper->dbh->add<Table_Message>("Message");
    mWrapper->dbh->add<Table_Application>("Application");
    mWrapper->mBOHandlerMessage = new BOHandlerMessage(mWrapper);
}

OpUnitCore::~OpUnitCore()
{
    delete mWrapper->dbh;
    delete mWrapper->mBOHandlerMessage;
}

void OpUnitCore::run()
{
    mWrapper->mOpUnitCoreId = mId;

    mWrapper->dBluetoothAdapter = BluetoothAdapter::getDefaultAdapter();
    mWrapper->opUnitUI = new OpUnitUI(mWrapper);
    mWrapper->opUnitServer = new OpUnitServer(mWrapper);

    DBCollection* vaApplication = mWrapper->dbh->get("Application")->getCollection();
    DBCollection* vaMessage = mWrapper->dbh->get("Message")->getCollection();

	if (vaApplication->count()) {
		mWrapper->mDBObjectApplication = mWrapper->dbh->get("Application")->getInstance("1");
	} else {
		mWrapper->mDBObjectApplication = mWrapper->dbh->get("Application")->getInstance();
        mWrapper->mDBObjectApplication->set("sDBObjectId", "0");
        mWrapper->mDBObjectApplication->set("sView", "0");
        mWrapper->mDBObjectApplication->set("sSort0", "sTitle");
        mWrapper->mDBObjectApplication->set("sAscending0", mWrapper->dbh->TRUE);
        mWrapper->mDBObjectApplication->set("sSort1", "sCategoryId");
        mWrapper->mDBObjectApplication->set("sAscending1", mWrapper->dbh->TRUE);
        mWrapper->mDBObjectApplication->set("sSort2", "sIn");
        mWrapper->mDBObjectApplication->set("sAscending2", mWrapper->dbh->TRUE);
		mWrapper->mDBObjectApplication->set("sCategory0", mWrapper->dbh->TRUE);
		mWrapper->mDBObjectApplication->set("sCategory1", mWrapper->dbh->TRUE);
		mWrapper->mDBObjectApplication->set("sCategory2", mWrapper->dbh->TRUE);
		mWrapper->mDBObjectApplication->set("sCategory3", mWrapper->dbh->TRUE);
		mWrapper->mDBObjectApplication->commit();
	}
	if (vaMessage->count()) {
		mWrapper->mDBObjectSeedEdit = mWrapper->dbh->get("Message")->getInstance("1");
	} else {
		mWrapper->mDBObjectSeedEdit = mWrapper->dbh->get("Message")->getInstance();
		mWrapper->mDBObjectSeedEdit->commit();
	}
    delete vaApplication;
	delete vaMessage;

    mWrapper->mac = mWrapper->dBluetoothAdapter->getAddress();
    mWrapper->mc10Secondes = chrono::duration_cast<system_clock::duration>(chrono::seconds(10)).count();
    mWrapper->mc375Mili = chrono::duration_cast<system_clock::duration>(chrono::milliseconds(375)).count();
    mWrapper->mcSleep = chrono::milliseconds(20);
	mWrapper->sServiceName = "Proximity service";
	mWrapper->sUuidService = "0000F9B3-";
	mWrapper->sUuidPeer = "0002F9B3-";
	mWrapper->sUuidSuffix = "0000-0000-0000-000000000000";
    mWrapper->sUuidMacSuffix = parseMac(mWrapper->mac);

    LOGD((String("System timestamp is : #") + to_string(system_clock::now().time_since_epoch().count())).c_str());

    mWrapper->opSquad->add(mWrapper->mNActivity);
    mWrapper->opSquad->add(mWrapper->opUnitUI)->start();
    mWrapper->opSquad->add(mWrapper->opUnitServer)->start();

	handleOp();
    cancel();
}

void OpUnitCore::handleOp()
{
    Op* op;
    TimeStamp vcTimeStampNow;

    while (mAlive) {
        //LOGE("OpUnitCore::handleOp");
        vcTimeStampNow = system_clock::now().time_since_epoch().count();

        if (mcState == 0 && mcDiscovery <= mcDiscoveryDone) {
            for (BluetoothDevice* vBluetoothDevice : maBluetoothDevice) {
                if (requestAsClient(vBluetoothDevice)) {
                    mWrapper->opSquad->add(new OpUnitPeer(mWrapper, vBluetoothDevice))->start();
                }
            }
            maBluetoothDevice = forward_list<BluetoothDevice*>();
            mcTimeStampBroadcast = vcTimeStampNow;
            mcState = 1;
        }
        if (mcState == 1 && mcRunningInitializations == 0 && vcTimeStampNow - mcTimeStampBroadcast > mWrapper->mc10Secondes) {
            mcDiscovery = mcDiscoveryDone + 1;
            LOGD("startDiscovery");
            mWrapper->dBluetoothAdapter->startDiscovery();
            mcState = 0;
        }
        op = nextOp();

        if (op) {
            execOp(op);
            //HINT: use op->result here, before calling nextOp again
        }
        this_thread::sleep_for(mWrapper->mcSleep*8);
    }
}

void OpUnitCore::cancel()
{
    mAlive = false;
}

bool OpUnitCore::requestAsClient(BluetoothDevice* vBluetoothDevice)
{
    bool vIsAlive = (vBluetoothDevice != nullptr);

    if (vIsAlive) {
        String vMac = parseMac(vBluetoothDevice->getAddress());
        vIsAlive &= !maMac.count(vMac);
    }
    if (vIsAlive) {
        LOGV(("Currently running initialization for MAC : #" + parseMac(vBluetoothDevice->getAddress())).c_str());
        ++mcRunningInitializations;
    }
    return vIsAlive;
}

bool OpUnitCore::requestAsServer(BluetoothDevice* vBluetoothDevice)
{
    bool vIsAlive = (vBluetoothDevice != nullptr);

    if (vIsAlive) {
        String vMac = parseMac(vBluetoothDevice->getAddress());
        vIsAlive &= !maMac.count(vMac);
    }
    if (vIsAlive) {
        LOGV(("Currently running initialization for MAC : #" + parseMac(vBluetoothDevice->getAddress())).c_str());
        ++mcRunningInitializations;
        mWrapper->dBluetoothAdapter->cancelDiscovery();
    }
    return vIsAlive;
}

bool OpUnitCore::registerAsClient(BluetoothDevice* vBluetoothDevice)
{
    bool vIsAlive = (vBluetoothDevice != nullptr);

    if (vIsAlive) {
        String vMac = parseMac(vBluetoothDevice->getAddress());
        std::pair<unordered_set<String>::iterator, bool> vEmplace = maMac.emplace(vMac);
        vIsAlive &= vEmplace.second;
    }
    if (vIsAlive) {
        LOGV(("Connection registered for MAC : #" + parseMac(vBluetoothDevice->getAddress())).c_str());
    }
    return vIsAlive;
}

void OpUnitCore::registerAsServer(BluetoothSocket* vBluetoothSocket)
{
    bool vIsAlive = (vBluetoothSocket->getRemoteDevice() != nullptr);

    if (vIsAlive) {
        String vMac = parseMac(vBluetoothSocket->getRemoteDevice()->getAddress());
        std::pair<unordered_set<String>::iterator, bool> vEmplace = maMac.emplace(vMac);
        vIsAlive &= vEmplace.second;
    }
    if (vIsAlive) {
        LOGV(("Connection registered for MAC : #" + parseMac(vBluetoothSocket->getRemoteDevice()->getAddress())).c_str());
        mWrapper->opSquad->add(new OpUnitPeer(mWrapper, vBluetoothSocket))->start();
    }
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

void OpUnitCore::setState(bool vIsEnabled, bool vIsDiscoverable)
{
    if (!vIsEnabled) {
        mWrapper->dBluetoothAdapter->disable();
    }
    if (vIsEnabled) {
        mWrapper->dBluetoothAdapter->enable();
    }
    if (vIsEnabled && vIsDiscoverable) {
        mWrapper->dBluetoothAdapter->discoverable();
    }
    if (vIsEnabled && !vIsDiscoverable) {
        mWrapper->dBluetoothAdapter->discoverable(1);
    }
}

void OpUnitCore::setSettings(bool vIsEnabled, bool vIsDiscoverable)
{
    setState(vIsEnabled, vIsDiscoverable);
}

void OpUnitCore::tilt(nint vcDBObjectId)
{
    LOGD("******* TILTING *******");
    nuint i;
    nuint j;
    nuint k;
    nuint vaAnim[3] = {3,5,0};

    mWrapper->w->dActivity->sendMessage((NParam)mWrapper->w->mNEpsilon01, mWrapper->maColor[1]);
    while (mAlive && mWrapper->mNActivity->mState != mWrapper->maColor[1]) {}
    this_thread::sleep_for(chrono::milliseconds(700));

    for (k = 0 ; k < 1 ; ++k) {
        for (j = 0 ; j < sizeof(vaAnim)/sizeof(nuint) ; ++j) {
            nuint index = vaAnim[j]*3 + 6;
            mWrapper->w->dActivity->sendMessage((NParam)mWrapper->w->mNEpsilon01, mWrapper->maColor[1]);
            while (mAlive && mWrapper->mNActivity->mState != mWrapper->maColor[1]) {}
            this_thread::sleep_for(chrono::milliseconds(20));

            for (i = index ; i < index + 3 ; ++i) {
                mWrapper->w->dActivity->sendMessage((NParam)mWrapper->w->mNEpsilon01, mWrapper->maColor[i]);
                while (mAlive && mWrapper->mNActivity->mState != mWrapper->maColor[i]) {}
                this_thread::sleep_for(chrono::milliseconds(20));
            }
            this_thread::sleep_for(chrono::milliseconds(240));
        }
        this_thread::sleep_for(chrono::milliseconds(460));

//        if (!k) {
//            mWrapper->w->dActivity->sendMessage((NParam)mWrapper->w->mNEpsilon01, mWrapper->maColor[1]);
//            while (mAlive && mWrapper->mNActivity->mState != mWrapper->maColor[1]) {}
//            this_thread::sleep_for(chrono::milliseconds(720));
//            mWrapper->w->dActivity->sendMessage((NParam)mWrapper->w->mNEpsilon01, mWrapper->maColor[20]);
//            while (mAlive && mWrapper->mNActivity->mState != mWrapper->maColor[20]) {}
//            this_thread::sleep_for(chrono::milliseconds(760));
//        }
        mWrapper->w->dActivity->sendMessage((NParam)mWrapper->w->mNEpsilon01, mWrapper->maColor[1]);
        while (mAlive && mWrapper->mNActivity->mState != mWrapper->maColor[1]) {}
        this_thread::sleep_for(chrono::milliseconds(700));
    }
    mWrapper->w->dActivity->sendMessage((NParam)mWrapper->w->mNEpsilon01, mWrapper->maColor[Theme::kColorApplicationBackground]);
    while (mAlive && mWrapper->mNActivity->mState != mWrapper->maColor[Theme::kColorApplicationBackground]) {}

    if (vcDBObjectId) {
        sendOp(0, mWrapper->mOpUnitUIId, w->w->mNDzeta00, new OpParam(vcDBObjectId, false));
    }
}

// void connectAsClient(BluetoothDevice* vBluetoothDevice)
NReturn OpUnitCore::visit(NAlpha00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    //connectAsClient((BluetoothDevice*)a);
    maBluetoothDevice.push_front((BluetoothDevice*)a);
    return 0;
}

// Add a listener
NReturn OpUnitCore::visit(NPi00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    mWrapper->opSquad->add(new OpUnitListener(mWrapper, (OpUnit*)a, (InputStream*)b))->start();
    return 0;
}

// void void setSettings(bool vIsEnable, bool vIsDiscoverable);
NReturn OpUnitCore::visit(NOmicron00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    setSettings((bool)a, (bool)b);
    return 0;
}

// initialization ended
NReturn OpUnitCore::visit(NRho00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    mWrapper->opUnitCore->maMac.erase(((OpMessage*)a)->mStringA);
    return 0;
}

// initialization count
NReturn OpUnitCore::visit(NKappa00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    --mcRunningInitializations;
    LOGD(("Currently running initializations count : #" + to_string(mcRunningInitializations)).c_str());
  //if (mcRunningInitializations == 0) {
  //    this_thread::sleep_for(chrono::milliseconds(3500));
  //    mWrapper->dBluetoothAdapter->startDiscovery();
  //}
    return 0;
}

// startdiscovery
NReturn OpUnitCore::visit(NSigma00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    ++mcDiscoveryDone;
    //LOGD("startDiscovery");
    //this_thread::sleep_for(chrono::milliseconds(3500));
    //mWrapper->dBluetoothAdapter->startDiscovery();
    return 0;
}

// tilt
NReturn OpUnitCore::visit(NMu00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
   tilt((nint)a);
   return 0;
}

// requestAsServer
NReturn OpUnitCore::visit(NTau00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
   return requestAsServer((BluetoothDevice*)a);
}

// registerAsClient
NReturn OpUnitCore::visit(NUpsilon00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
   return registerAsClient((BluetoothDevice*)a);
}

// registerAsServer
NReturn OpUnitCore::visit(NPhi00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
   registerAsServer((BluetoothSocket*)a);
   return 0;
}

} // End namespace
