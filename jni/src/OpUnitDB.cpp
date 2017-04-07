#include "Common.h"
#include "Theme.h"

namespace NSDEVICE
{

OpUnitDB::OpUnitDB(Wrapper* const vWrapper)
    : OpUnit(vWrapper->mNWrapper), mcProcessedDevice(0), mcTimeStampPrevious(0), mcTimeStampNow(0), mcState(0), mcRunningInitializations(0),
      mcDiscovery(0), mcDiscoveryDone(0),
      w(vWrapper), mDBCollection(nullptr), maMac()
{
    w->mhDB = new DBHandler(w->mNWrapper);
    w->mhDB->add<Table_Message>("Message");
    w->mhDB->add<Table_Application>("Application");
}

OpUnitDB::~OpUnitDB()
{
    if (w->maMessageAlive) {
        delete w->maMessageAlive;
    }
    if (w->maMessageUpdate) {
        delete w->maMessageUpdate;
    }
    if (w->maMessageBuzz) {
        delete w->maMessageBuzz;
    }
    if (w->mBOMessageHandler) {
        delete w->mBOMessageHandler;
    }
    delete w->mhDB;
}

void OpUnitDB::run()
{
    w->mBOMessageHandler = new BOMessageHandler(w);
    w->maMessageBuzz = new NConcurrentCircularBuffer<String*>(25);
    w->maMessageUpdate = new NConcurrentCircularBuffer<String*>(25);
    w->maMessageAlive = new NConcurrentCircularBuffer<String*>(25);
    w->mAREventIndex = 1;

    // Init database
    DBCollection* vaApplication =  w->mhDB->get("Application")->getCollection();
    DBCollection* vaMessage =  w->mhDB->get("Message")->getCollection();

    if (vaApplication->count()) {
        w->mDBObjectApplication =  w->mhDB->get("Application")->getInstance(1);
    } else {
        w->mDBObjectApplication =  w->mhDB->get("Application")->getInstance();
        w->mDBObjectApplication->set("sDBObjectId", "1");
        w->mDBObjectApplication->set("sView", k::ViewAR);
        w->mDBObjectApplication->set("sSort0", "Title");
        w->mDBObjectApplication->set("sAscending0", kTrue);
        w->mDBObjectApplication->set("sSort1", "Enabled");
        w->mDBObjectApplication->set("sAscending1", kTrue);
        w->mDBObjectApplication->set("sSort2", "CategoryId");
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
        poiFill();
    };
    delete vaApplication;
    delete vaMessage;

    w->maSort.emplace_back(w->mDBObjectApplication->get("sSort0"), w->mDBObjectApplication->is("sAscending0"));
    w->maSort.emplace_back(w->mDBObjectApplication->get("sSort1"), w->mDBObjectApplication->is("sAscending1"));
    w->maSort.emplace_back(w->mDBObjectApplication->get("sSort2"), w->mDBObjectApplication->is("sAscending2"));
    sendOp(w->mOpUnitDBId, w->mNWrapper->mNKrossWrapper->mNAlpha00, new Op());
    sendOp(w->mOpUnitAppId, w->mNWrapper->mNKrossWrapper->mNBeta00, new OpParam((NParam)w->mBOMessageHandler->getMessagesToList()->sort(w->maSort)));

    handleOp();
    cancel();
}

void OpUnitDB::handleOp()
{
    Op* op;
    DBObject* vMessage;
    nfloat* vDeviceCoord;
    nint i;
    w->maMessageAlive->add(new String("#2#3"));

    while (mAlive) {
        mcTimeStampNow = system_clock::now().time_since_epoch().count();

        if (mcState == 0 && mcTimeStampNow - mcTimeStampPrevious > 20*w->mc1Seconde) {
            // Update messages time
            mcTimeStampPrevious = mcTimeStampNow;
            mDBCollection = w->mBOMessageHandler->getMessagesToBroadcast();
            i = mDBCollection->count();

            while (--i >= 0) {
                vMessage = mDBCollection->get(i);

                if (vMessage->get("Type") == "0" && !vMessage->is("ArchivedSrc")) {
                    vMessage->set("RevSrc", vMessage->count("RevSrc") + 1);
                    vMessage->set("Date", mcTimeStampNow);
                }
                if (vMessage->get("Type") == "1" && mcTimeStampNow - vMessage->count("Date") > 60*w->mc1Seconde) {
                    sendOp(w->mOpUnitARId, w->mNWrapper->mNKrossWrapper->mNDelta00, new OpParam((NParam)vMessage->mId));
                    vMessage->discardRow();
                }
            }
            delete mDBCollection;
            mcState = 1;
        }
        if (mcState == 1 && mcTimeStampNow - mcTimeStampPrevious > 5*w->mc1Seconde) {
            // Persistence
            LOGD("Persistence");
            w->mBOMessageHandler->clean();
            w->mDBObjectSeedEdit->commit();
            w->mDBObjectApplication->commit();
            mcState = 2;
        }
        if (mcState == 2 && mcTimeStampNow - mcTimeStampPrevious > 10*w->mc1Seconde) {
            // GPS position
            mDBCollection = w->mBOMessageHandler->getMessagesToPosition();
            i = mDBCollection->count();
            vDeviceCoord =  w->mCoordBuffer->getHead();

            while (--i >= 0) {
                vMessage = mDBCollection->get(i);
                vMessage->set("EarthCoordX", vDeviceCoord[0]);
                vMessage->set("EarthCoordY", vDeviceCoord[1]);
                vMessage->set("EarthCoordZ", vDeviceCoord[2]);
            }
            delete mDBCollection;
            mcState = 3;
        }
        if (mcState == 3 && mcTimeStampNow - mcTimeStampPrevious > 15*w->mc1Seconde) {
            // Broadcast alive messages
            mDBCollection = w->mBOMessageHandler->getMessagesToBroadcast();
            i = mDBCollection->count();
            String* vPacket = new String( i ? "" : "2#3#" );

            while (--i >= 0) {
                *vPacket += "2#" + w->mBOMessageHandler->packId(mDBCollection->get(i)) + "3#";
            }
            w->maMessageAlive->add(vPacket);
            delete mDBCollection;
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
    w->mBOMessageHandler->clean();
    w->mDBObjectSeedEdit->commit();
    w->mDBObjectApplication->commit();
}

void OpUnitDB::cancel()
{
    mAlive = false;
}

OpCallback* OpUnitDB::sendOp(int vcOpUnitId, NElement* vNElement, Op* vOp)
{
    OpCallback* ret = nullptr;

    if (mAlive && mOpSquad->maOpUnitType[vcOpUnitId] == OpUnit::OPUNIT_TYPE_ACTIVITY) {
        vOp->mNElement = vNElement;
        w->mNActivity->sendMessage((NParam)vOp);
        ret = vOp->mOpCallback;
    } else {
        ret = OpUnit::sendOp(vcOpUnitId, vNElement, vOp);
    }
    return ret;
}

void OpUnitDB::peerFeed(nint vOpUnitPeerId)
{
    DBCollection* vDBCollection = w->mBOMessageHandler->getMessagesToBroadcast();
    nint i = vDBCollection->count();
    String* vString = new String( i ? "" : "2#3#" );

    while (--i >= 0) {
        *vString += "2#" + w->mBOMessageHandler->pack(vDBCollection->get(i)) + "3#";
    }
    sendOp(vOpUnitPeerId, w->mNWrapper->mNKrossWrapper->mNBeta00, new OpParam((NParam)vString, w->maMessageUpdate->mHeadIndex, w->maMessageBuzz->mHeadIndex, w->mcInterrupt));
    delete vDBCollection;
}

void OpUnitDB::peerReceive(String& vPacked)
{
    nint vcStart;
    nint vcEnd;
    w->mIsInterrupted = true;
    LOGD(("Packed message received:" + vPacked).c_str());

    while (mAlive && (vcStart = vPacked.find("2#")) >= 0 && (vcEnd = vPacked.find("3#")) >= 0 && vcStart + 2 < vcEnd) {
        w->mBOMessageHandler->addDrop(this, vPacked.substr(vcStart + 2, vcEnd - (vcStart + 2)));
        vPacked = vPacked.substr(vcEnd + 2);
    }
    w->mIsInterrupted = false;
}

void OpUnitDB::poiAdd(const String& id_cat, const String& title, const String& text, const String& link)
{
    DBObject* vDBObject = w->mBOMessageHandler->addSeed(id_cat, title, text, link);
    w->maMessageUpdate->add(new String("2#" + w->mBOMessageHandler->pack(vDBObject) + "3#"));
    w->mBOMessageHandler->setMessage(w->mDBObjectSeedEdit, "0", "", "", "");
    uiFeed(k::ViewDetails, vDBObject);
}

void OpUnitDB::poiDiscard(nuint vcDBObjectId, bool vIsDeleted)
{
    DBObject* vDBObject = w->mBOMessageHandler->get(vcDBObjectId);
    vDBObject->set("RevSrc", vDBObject->count("RevSrc") + 1);
    vDBObject->set("ArchivedSrc", vIsDeleted || !vDBObject->is("Enabled"));
    vDBObject->set("Deleted", vIsDeleted);
    w->maMessageUpdate->add(new String("2#" + w->mBOMessageHandler->pack(vDBObject) + "3#"));
    sendOp(w->mOpUnitAppId, w->mNWrapper->mNKrossWrapper->mNBeta00, new OpParam((NParam)w->mBOMessageHandler->getMessagesToList()->sort(w->maSort)));
    uiFeed(k::ViewList, nullptr);
    delete vDBObject;
}

void OpUnitDB::poiEdit(nuint vcDBObjectId, const String& id_cat, const String& title, const String& text, const String& link)
{
    DBObject* vDBObject = w->mBOMessageHandler->setMessage(vcDBObjectId, id_cat, title, text, link);
    w->maMessageUpdate->add(new String("2#" + w->mBOMessageHandler->pack(vDBObject) + "3#"));
    uiFeed(k::ViewDetails, vDBObject);
}

void OpUnitDB::poiEnable(nuint vcDBObjectId, bool vIsEnabled)
{
    DBObject* vDBObject = w->mBOMessageHandler->get(vcDBObjectId);
    vIsEnabled = !vDBObject->is("Enabled");
    vDBObject->set("RevSrc", vDBObject->count("RevSrc") + 1);
    vDBObject->set("ArchivedSrc", !vIsEnabled);
    vDBObject->set("Date", mcTimeStampNow);
    vDBObject->set("Enabled", vIsEnabled);
    w->maMessageUpdate->add(new String("2#" + w->mBOMessageHandler->pack(vDBObject) + "3#"));
    sendOp(w->mOpUnitAppId, w->mNWrapper->mNKrossWrapper->mNBeta00, new OpParam((NParam)w->mBOMessageHandler->getMessagesToList()->sort(w->maSort)));
}

void OpUnitDB::poiFill()
{
    map<String,vector<String>> vaPOIata;
    NArray<nbyte> vPOISource = w->mGraphicsHandler->loadAsset("poi.csv");
    vector<String> vaPOILine = split(String(vPOISource.maData), "\n");
    nint vCount = 0;

    for (String vPOILine : vaPOILine) {
        if (vPOILine.length() && vPOILine.at(0) != '[') {
            vector<String> vaPOIField = split(vPOILine, "#");
            vaPOIata.emplace(vaPOIField[0], vaPOIField);
        }
    }
    for (pair<String,vector<String>> vPOIData : vaPOIata) {
        w->mBOMessageHandler->add(to_string(vCount++), to_float(vPOIData.second[2]), to_float(vPOIData.second[1]), vPOIData.second[0], "2");
    }
    vPOISource.discard();
}

void OpUnitDB::poiList()
{
    sendOp(w->mOpUnitAppId, w->mNWrapper->mNKrossWrapper->mNBeta00, new OpParam((NParam)w->mBOMessageHandler->getMessagesToList()->sort(w->maSort)));
    uiFeed(k::ViewList, nullptr);
}

void OpUnitDB::poiSort(const String& vField, bool vIsAscending)
{
    nuint vIndex = 0;
    list<Sort>::iterator vIt = w->maSort.begin();

    while (vIt != w->maSort.end()) {
        vIt = ( vIt->mField == vField ? w->maSort.erase(vIt) : ++vIt );
    }
    w->maSort.emplace_back(vField, vIsAscending);

    for (Sort vSort : w->maSort) {
        w->mDBObjectApplication->set("sSort" + to_string(vIndex), vSort.mField)->set("sAscending" + to_string(vIndex), vSort.mIsAscending);
        ++vIndex;
    }
    sendOp(w->mOpUnitAppId, w->mNWrapper->mNKrossWrapper->mNGamma00, new OpParam((NParam)w->mBOMessageHandler->getMessagesToList()->sort(w->maSort)));
}

void OpUnitDB::uiInit()
{
    nuint i;
    DBCollection* vaPOIStatic = w->mBOMessageHandler->getMessagesStatic();

    for (i = 0 ; i < vaPOIStatic->count() ; ++i) {
        DBObject* vDBObject = vaPOIStatic->get(i);
        BOPOI* vBOPOI = new BOPOI(w);
        vBOPOI->update(vDBObject);
        w->maPOIStatic[vDBObject->mId] = vBOPOI;
    }
    DBCollection* vaPOIDynamic = w->mBOMessageHandler->getMessagesDynamic();

    for (i = 0 ; i < vaPOIDynamic->count() ; ++i) {
        DBObject* vDBObject = vaPOIDynamic->get(i);
        BOPOI* vBOPOI = new BOPOI(w);
        vBOPOI->update(vDBObject);
        w->maPOIDynamic[vDBObject->mId] = vBOPOI;
    }
    for (i = 0 ; i < k::POICount ; ++i) {
        BOPOI* vBOPOI = new BOPOI(w);
        vBOPOI->mLine = i%4;

        if (i < vaPOIDynamic->count()) {
            DBObject* vDBObject = vaPOIDynamic->get(i);
            vBOPOI->update(vDBObject);
            w->maPOISorted.add(vBOPOI, k::MaxFloat);
        } else {
            DBObject* vDBObject = vaPOIStatic->get(i);
            vBOPOI->update(vDBObject);
            w->maPOISorted.add(vBOPOI, k::MaxFloat);
            w->maPOIStatic[vDBObject->mId]->mIsActive = true;
        }
    }
    delete vaPOIStatic;
    delete vaPOIDynamic;
    //sendOp(w->mOpUnitARId, w->mNWrapper->mNKrossWrapper->mNGamma00, new OpParam((NParam)w->mBOMessageHandler->get(vDBCollection->get(vPOIIndex)->mId)));
}

void OpUnitDB::uiFeed(nint vcView, nuint vcDBObjectId)
{
    sendOp(w->mOpUnitAppId, w->mNWrapper->mNKrossWrapper->mNAlpha00, new OpParam(vcView, (NParam)( vcDBObjectId ? w->mBOMessageHandler->get(vcDBObjectId) : nullptr )));
    uiStore(vcView, vcDBObjectId);
}

void OpUnitDB::uiFeed(nint vcView, DBObject* vDBObject)
{
    sendOp(w->mOpUnitAppId, w->mNWrapper->mNKrossWrapper->mNAlpha00, new OpParam(vcView, (NParam)vDBObject));
    uiStore(vcView, ( vDBObject ? vDBObject->mId : 0 ));
}

void OpUnitDB::uiStore(nint vcView, nuint vcDBObjectId)
{
    w->mDBObjectApplication->set("sView", vcView);
    w->mDBObjectApplication->set("sDBObjectId", vcDBObjectId);
    w->mDBObjectApplication->commit();
}

void OpUnitDB::uiRestore()
{
    uiFeed(w->mDBObjectApplication->count("sView"), w->mDBObjectApplication->count("sDBObjectId"));
}

NReturn OpUnitDB::visit(NAlpha00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    uiInit();
    return 0;
}

NReturn OpUnitDB::visit(NBeta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    uiFeed((nint)a, (nuint)b);
    return 0;
}

NReturn OpUnitDB::visit(NGamma00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    uiRestore();
    return 0;
}

NReturn OpUnitDB::visit(NEpsilon00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    peerFeed((nint)a);
    return 0;
}

NReturn OpUnitDB::visit(NDzeta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    peerReceive(((OpMessage*)a)->mStringA);
    return 0;
}

NReturn OpUnitDB::visit(NEta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    poiAdd(((OpMessage*)a)->mStringA, ((OpMessage*)a)->mStringB, ((OpMessage*)a)->mStringC, ((OpMessage*)a)->mStringD);
    return 0;
}

NReturn OpUnitDB::visit(NTheta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    poiDiscard((nuint)a, (bool)b);
    return 0;
}

NReturn OpUnitDB::visit(NIota00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    poiEdit(to_long(((OpMessage*)a)->mStringA), ((OpMessage*)a)->mStringB, ((OpMessage*)a)->mStringC, ((OpMessage*)a)->mStringD, ((OpMessage*)a)->mStringE);
    return 0;
}

NReturn OpUnitDB::visit(NKappa00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    poiEnable((nuint)a, (bool)b);
    return 0;
}

NReturn OpUnitDB::visit(NLambda00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    poiList();
    return 0;
}

NReturn OpUnitDB::visit(NMu00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    poiSort(((OpMessage*)a)->mStringA, (bool)b);
    return 0;
}

} // End namespace
