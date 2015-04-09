#include "Common.h"
#include "Theme.h"

namespace NSDEVICE
{

OpUnitCore::OpUnitCore(Wrapper* const w)
	: OpUnit(w), mWrapper(w), mcProcessedDevice(0), mcTimeStampBroadcast(0), mcForce(0), mcRunningInitializations(0), maMac()
{
}

OpUnitCore::~OpUnitCore()
{
    delete mWrapper->dbh;
    delete mWrapper->mBOHandlerMessage;
}

void OpUnitCore::run()
{
	//00000000-0000-07da-0000-0000000007d0
    //00001101-0000-1000-8000-00805F9B34FB
	//UUID(2010L,2000L);

    mWrapper->mOpUnitCoreId = mId;
    mWrapper->dBluetoothAdapter = BluetoothAdapter::getDefaultAdapter();

    mWrapper->dbh = new DBHandler(mWrapper);
	mWrapper->dbh->add<Table_Message>("Message");
	mWrapper->dbh->add<Table_Application>("Application");
	mWrapper->mBOHandlerMessage = new BOHandlerMessage(mWrapper);
	mWrapper->opUnitServer = new OpUnitServer(mWrapper);

    // DEBUG
    mWrapper->dbh->get("Application")->drop();
    // DEBUG

    DBCollection* vaApplication = mWrapper->dbh->get("Application")->getCollection();
    DBCollection* vaMessage = mWrapper->dbh->get("Message")->getCollection();

	if (vaApplication->count()) {
		mWrapper->mDBObjectApplication = mWrapper->dbh->get("Application")->getInstance("1");
	} else {
		mWrapper->mDBObjectApplication = mWrapper->dbh->get("Application")->getInstance();
        mWrapper->mDBObjectApplication->set("sDBObjectId", "0");
        mWrapper->mDBObjectApplication->set("sView", "0");
        mWrapper->mDBObjectApplication->set("sSort", "in");
        mWrapper->mDBObjectApplication->set("sAscending", mWrapper->dbh->TRUE);
		mWrapper->mDBObjectApplication->set("sBluetooth", mWrapper->dbh->TRUE);
		mWrapper->mDBObjectApplication->set("sDiscoverable", mWrapper->dbh->TRUE);
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
    clear();
    setView(Wrapper::kViewHome, 1);

    mWrapper->mc10Secondes = chrono::duration_cast<steady_clock::duration>(chrono::seconds(10)).count();
	mWrapper->sServiceName = "Proximity service";
	mWrapper->sUuidService = "0001F9B3-";
	mWrapper->sUuidPeer = "0002F9B3-";
	mWrapper->sUuidSuffix = "0000-0000-0000-000000000000";
    mWrapper->sUuidMacSuffix = parseMac(mWrapper->mac);

    if (!mWrapper->dBluetoothAdapter->isEnabled()) {
        mWrapper->dBluetoothAdapter->enable();
    }
    if (mWrapper->dBluetoothAdapter->getScanMode() != mWrapper->dBluetoothAdapter->SCAN_MODE_CONNECTABLE_DISCOVERABLE) {
        mWrapper->dBluetoothAdapter->discoverable();
    }
    //mWrapper->dBluetoothAdapter->startDiscovery();
    mWrapper->opSquad->add(mWrapper->opUnitServer)->start();
	handleOp();
    cancel();
}

void OpUnitCore::handleOp()
{
    Op* op;
    nint i = 0;
    TimeStamp vcTimeStampNow;

    while (mAlive) {
        vcTimeStampNow = steady_clock::now().time_since_epoch().count();

        if (vcTimeStampNow - mcTimeStampBroadcast > mWrapper->mc10Secondes) {
            mcTimeStampBroadcast = vcTimeStampNow;
            DBCollection* vaMessage = mWrapper->mBOHandlerMessage->getMessagesToBroadcast()->filter("in", mWrapper->dbh->FALSE, "=");

            for (i = 0 ; i < vaMessage->count() ; ++i) {
                vaMessage->get(i)->set("date", vcTimeStampNow)->commit();
            }
            delete vaMessage;
        }
        op = nextOp();

        if (op) {
            execOp(op);
            //Hnint: use op->result here, before calling nextOp again
        } else {
            this_thread::sleep_for(chrono::milliseconds(300));
        }
    }
}

void OpUnitCore::addDrop(const String& packed)
{
    DBObject* vDBObject = mWrapper->mBOHandlerMessage->get(mWrapper->mBOHandlerMessage->addDrop(packed));
    clear();

    if (!vDBObject->is("in") && vDBObject->is("sBuzzed")) {
        tilt();
        vDBObject->set("sBuzzed", false);
        vDBObject->commit();
        render();
    }
    delete vDBObject;
}

void OpUnitCore::addSeed(const String& id_cat, const String& title, const String& text, const String& link)
{
    nint vcDBObjectId = mWrapper->mBOHandlerMessage->addSeed(id_cat, title, text, link);
    clear();
    setView(Wrapper::kViewDetails, vcDBObjectId);
}

void OpUnitCore::archive(nint vcDBObjectId, bool vIsArchived)
{
    DBObject* vDBObject = mWrapper->mBOHandlerMessage->get(vcDBObjectId);
    vDBObject->set("sArchivedAuto", vIsArchived);
    vDBObject->set("date", steady_clock::now().time_since_epoch().count());
    vDBObject->commit();
    clear();
    setView(Wrapper::kViewHome);
}

void OpUnitCore::buzz(nint vcDBObjectId, bool vIsBuzzed)
{
    DBObject* vDBObject = mWrapper->mBOHandlerMessage->get(vcDBObjectId);
    vDBObject->set("sBuzzed", vIsBuzzed);
    vDBObject->set("date", steady_clock::now().time_since_epoch().count());
    vDBObject->commit();

    mcForce = mcForce + 1;
    mWrapper->w->dActivity->sendMessage((NParam)mWrapper->w->mNAlpha01, (NParam)mWrapper->mBOHandlerMessage->getMessagesSorted());

    delete vDBObject;
}

void OpUnitCore::cancel()
{
    mAlive = false;
}

void OpUnitCore::clear()
{
    mWrapper->w->dActivity->sendMessage((NParam)mWrapper->w->mNBeta01, (NParam)mWrapper->mBOHandlerMessage->getMessagesSorted());
}

void OpUnitCore::discard(nint vcDBObjectId, bool vIsDeleted)
{
    DBObject* vDBObject = mWrapper->mBOHandlerMessage->get(vcDBObjectId);
    vDBObject->set("sDeleted", vIsDeleted);
    vDBObject->set("date", steady_clock::now().time_since_epoch().count());

    if (!vDBObject->is("in")) {
        vDBObject->set("sArchivedUser", !vDBObject->is("sEnabled") || vDBObject->is("sDeleted"));
    }
    vDBObject->commit();

    mcForce = mcForce + 1;
    clear();
    setView(Wrapper::kViewHome);
    delete vDBObject;
}

void OpUnitCore::enable(nint vcDBObjectId, bool vIsEnabled)
{
    DBObject* vDBObject = mWrapper->mBOHandlerMessage->get(vcDBObjectId);
    vDBObject->set("sEnabled", vIsEnabled);
    vDBObject->set("date", steady_clock::now().time_since_epoch().count());

    if (!vDBObject->is("in")) {
        vDBObject->set("sArchivedUser", !vDBObject->is("sEnabled") || vDBObject->is("sDeleted"));
    }
    vDBObject->commit();

    mcForce = mcForce + 1;
    delete vDBObject;
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

void OpUnitCore::render()
{
    mWrapper->w->dActivity->sendMessage((NParam)mWrapper->w->mNGamma01, (NParam)mWrapper->mBOHandlerMessage->getMessagesSorted());
}

void OpUnitCore::setSeed(nint vcDBObjectId, const String& id_cat, const String& title, const String& text, const String& link)
{
    mWrapper->mBOHandlerMessage->setMessage(vcDBObjectId, id_cat, title, text, link);
    clear();
    setView(Wrapper::kViewDetails, vcDBObjectId);
}

void OpUnitCore::setView(nint vcView, nint vcDBObjectId)
{
    if (vcView == Wrapper::kViewDetails && vcDBObjectId == 1) {
        vcView = Wrapper::kViewHome;
    }
    mWrapper->mDBObjectApplication->set("sView", vcView);
    mWrapper->mDBObjectApplication->set("sDBObjectId", vcDBObjectId);
    mWrapper->mDBObjectApplication->commit();
    mWrapper->w->dActivity->sendMessage((NParam)mWrapper->w->mNDelta01, (NParam)vcView, (NParam)vcDBObjectId);
}

void OpUnitCore::sort(const String& vColumn, bool vIsAscending)
{
    mWrapper->mDBObjectApplication->set("sSort", vColumn)->set("sAscending", vIsAscending)->commit();
    render();
}

void OpUnitCore::tilt()
{
    LOGV("******* TILTING *******");
    nuint i;
    nuint j;
    nuint k;
    nuint vaAnim[3] = {3,5,0};

    mWrapper->w->dActivity->sendMessage((NParam)mWrapper->w->mNEpsilon01, mWrapper->maColor[1]);
    while (mAlive && mWrapper->mNActivity->mState != mWrapper->maColor[1]) {}
    this_thread::sleep_for(chrono::milliseconds(700));

    for (k = 0 ; k < 2 ; ++k) {
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

        if (!k) {
            mWrapper->w->dActivity->sendMessage((NParam)mWrapper->w->mNEpsilon01, mWrapper->maColor[1]);
            while (mAlive && mWrapper->mNActivity->mState != mWrapper->maColor[1]) {}
            this_thread::sleep_for(chrono::milliseconds(720));
            mWrapper->w->dActivity->sendMessage((NParam)mWrapper->w->mNEpsilon01, mWrapper->maColor[20]);
            while (mAlive && mWrapper->mNActivity->mState != mWrapper->maColor[20]) {}
            this_thread::sleep_for(chrono::milliseconds(760));
        }
        mWrapper->w->dActivity->sendMessage((NParam)mWrapper->w->mNEpsilon01, mWrapper->maColor[1]);
        while (mAlive && mWrapper->mNActivity->mState != mWrapper->maColor[1]) {}
        this_thread::sleep_for(chrono::milliseconds(700));
    }
    mWrapper->w->dActivity->sendMessage((NParam)mWrapper->w->mNEpsilon01, mWrapper->maColor[Theme::kColorApplicationBackground]);
    while (mAlive && mWrapper->mNActivity->mState != mWrapper->maColor[Theme::kColorApplicationBackground]) {}
}

// Add a peer server
NReturn OpUnitCore::visit(NAlpha00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    BluetoothDevice* vBluetoothDevice = (BluetoothDevice*)a;
    bool vIsAlive = (vBluetoothDevice != nullptr);

    if (vIsAlive) {
        vector<ParcelUuid*> vaParcelUuid = vBluetoothDevice->getUuids();
        bool vHasUuid = false;

        for (ParcelUuid* vParcelUuid : vaParcelUuid) {
            vHasUuid |= (vParcelUuid->toString() == mWrapper->sUuidService + mWrapper->sUuidSuffix);
        }
        vIsAlive &= vaParcelUuid.empty() || vHasUuid;
    }
    if (vIsAlive) {
        String vMac = parseMac(vBluetoothDevice->getAddress());
        std::pair<unordered_set<String>::iterator, bool> vEmplace = maMac.emplace(vMac);
        vIsAlive &= vEmplace.second;
        //vIsAlive &= maMac.emplace(parseMac(vBluetoothDevice->getAddress())).second;
    }
    if (vIsAlive) {
        LOGV(("Currently running initialization for MAC : #" + parseMac(vBluetoothDevice->getAddress())).c_str());
        ++mcRunningInitializations;
        mWrapper->dBluetoothAdapter->cancelDiscovery();
        mWrapper->opSquad->add(new OpUnitPeer(mWrapper, vBluetoothDevice))->start();
    }
    return 0;
}

// Add a peer client
NReturn OpUnitCore::visit(NBeta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    BluetoothSocket* vBluetoothSocket = (BluetoothSocket*)a;
    bool vIsAlive = (vBluetoothSocket != nullptr);

    if (vIsAlive) {
        String vMac = parseMac(vBluetoothSocket->getRemoteDevice()->getAddress());
        std::pair<unordered_set<String>::iterator, bool> vEmplace = maMac.emplace(vMac);
        vIsAlive &= vEmplace.second;
        //vIsAlive &= maMac.emplace(parseMac(vBluetoothSocket->getRemoteDevice()->getAddress())).second;
    }
    if (vIsAlive) {
        LOGV(("Currently running initialization for MAC : #" + parseMac(vBluetoothSocket->getRemoteDevice()->getAddress())).c_str());
        ++mcRunningInitializations;
        mWrapper->dBluetoothAdapter->cancelDiscovery();
        mWrapper->opSquad->add(new OpUnitPeer(mWrapper, vBluetoothSocket))->start();
    }
    return 0;
}

// nint addDrop(const String& packed)
NReturn OpUnitCore::visit(NGamma00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    addDrop(((OpMessage*)a)->mStringA);
    return 0;
}

// nint addSeed(const String& id_cat, const String& title, const String& text, const String& link)
NReturn OpUnitCore::visit(NDelta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    addSeed(((OpMessage*)a)->mStringA, ((OpMessage*)a)->mStringB, ((OpMessage*)a)->mStringC, ((OpMessage*)a)->mStringD);
    return 0;
}

// void archive(nint vcDBObjectId, bool vIsArchived)
NReturn OpUnitCore::visit(NNu00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    archive((nint)a, (nint)b);
    return 0;
}

// void buzz(nint vcDBObjectId, bool vIsBuzzed)
NReturn OpUnitCore::visit(NDzeta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    buzz((nint)a, (nint)b);
    return 0;
}

// void discard(nint vcDBObjectId, bool vIsArchived)
NReturn OpUnitCore::visit(NEpsilon00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    discard((nint)a, (nint)b);
    return 0;
}

// void void setSeed(nint vcDBObjectId, const String& id_cat, const String& title, const String& text, const String& link)
NReturn OpUnitCore::visit(NXi00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    enable((nint)a, (nint)b);
    return 0;
}

// void void setSeed(nint vcDBObjectId, const String& id_cat, const String& title, const String& text, const String& link)
NReturn OpUnitCore::visit(NTheta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    setSeed(b, ((OpMessage*)a)->mStringA, ((OpMessage*)a)->mStringB, ((OpMessage*)a)->mStringC, ((OpMessage*)a)->mStringD);
    return 0;
}

// void setView(nint vIndex, nint vcDBObjectId = 1)
NReturn OpUnitCore::visit(NIota00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    setView((nint)a, (nint)b);
    return 0;
}

// void sort(const String& vColumn, bool vIsAscending)
NReturn OpUnitCore::visit(NEta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    sort(((OpMessage*)a)->mStringA, (bool)b);
    return 0;
}

// startdiscovery
NReturn OpUnitCore::visit(NKappa00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    LOGV(("Currently running initializations count : #" + to_string(mcRunningInitializations - 1)).c_str());
    mWrapper->opUnitCore->maMac.erase(((OpMessage*)a)->mStringA);
    if (--mcRunningInitializations == 0) {
        //mWrapper->dBluetoothAdapter->startDiscovery();
    }
    return 0;
}

// get messages for braodcast
NReturn OpUnitCore::visit(NLambda00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    return (NReturn)mWrapper->mBOHandlerMessage->getMessagesToBroadcast();
}

// tilt
NReturn OpUnitCore::visit(NMu00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
   tilt();
   return 0;
}

} // End namespace
