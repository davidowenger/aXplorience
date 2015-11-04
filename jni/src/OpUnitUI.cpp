#include "Common.h"
#include "Theme.h"

namespace NSDEVICE
{
OpUnitUI::OpUnitUI(Wrapper* const vWrapper)
    : OpUnit(vWrapper->mNWrapper), mcProcessedDevice(0), mcTimeStampPrevious(0), mcTimeStampNow(0), mcState(0), mcRunningInitializations(0),
      mcDiscovery(0), mcDiscoveryDone(0),
      w(vWrapper), mDBCollection(nullptr), maMac()
{
}

OpUnitUI::~OpUnitUI()
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
    if (w->mBOHandlerMessage) {
        delete w->mBOHandlerMessage;
    }
}

void OpUnitUI::run()
{
    w->mBOHandlerMessage = new BOHandlerMessage(w);
    w->maMessageBuzz = new NConcurrentCircularBuffer<String*>(25);
    w->maMessageUpdate = new NConcurrentCircularBuffer<String*>(25);
    w->maMessageAlive = new NConcurrentCircularBuffer<String*>(25);

    sendOp(w->mOpUnitUIId, w->mNWrapper->mNKrossWrapper->mNAlpha00, new Op());
    handleOp();
    cancel();
}

void OpUnitUI::handleOp()
{
    Op* op;
    DBObject* vMessage;
    nint i;
    w->maMessageAlive->add(new String("#2#3"));

    while (mAlive) {
        mcTimeStampNow = system_clock::now().time_since_epoch().count();

        if (mcState == 0 && mcTimeStampNow - mcTimeStampPrevious > 20*w->mc1Seconde) {
            // Update messages time
            mcTimeStampPrevious = mcTimeStampNow;
            mDBCollection = w->mBOHandlerMessage->getMessagesToBroadcast();
            i = mDBCollection->count();

            while (--i >= 0) {
                vMessage = mDBCollection->get(i);

                if (!vMessage->is("sIn") && !vMessage->is("sArchivedUser")) {
                    vMessage->set("sRevSource", vMessage->count("sRevSource") + 1);
                    vMessage->set("date", mcTimeStampNow);
                }
                if (mcTimeStampNow - vMessage->count("date") > 60*w->mc1Seconde) {
                    archive(vMessage->mId, true);
                }
            }
            delete mDBCollection;
            mcState = 1;
        }
        if (mcState == 1 && mcTimeStampNow - mcTimeStampPrevious > 5*w->mc1Seconde) {
            LOGD("Persistence");
            w->mBOHandlerMessage->clean();
            w->mDBObjectSeedEdit->commit();
            w->mDBObjectApplication->commit();
            mcState = 2;
        }
        if (mcState == 2 && mcTimeStampNow - mcTimeStampPrevious > 10*w->mc1Seconde) {
            // Broadcast alive messages
            mDBCollection = w->mBOHandlerMessage->getMessagesToBroadcast()->sort(w->maSort);
            i = mDBCollection->count();
            String* vPacket = new String( i ? "" : "2#3#" );

            while (--i >= 0) {
                *vPacket += "2#" + w->mBOHandlerMessage->packId(mDBCollection->get(i)) + "3#";
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
    w->mBOHandlerMessage->clean();
    w->mDBObjectSeedEdit->commit();
    w->mDBObjectApplication->commit();
}

OpCallback* OpUnitUI::sendOp(int vcOpUnitId, NElement* vNElement, Op* vOp)
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

void OpUnitUI::addDrop(String& vPacked)
{
    nint vcStart;
    nint vcEnd;
    w->mIsInterrupted = true;
    LOGD(("Packed message received : #" + vPacked).c_str());

    while (mAlive && (vcStart = vPacked.find("2#")) >= 0 && (vcEnd = vPacked.find("3#")) >= 0 && vcStart + 2 < vcEnd) {
        w->mBOHandlerMessage->addDrop(this, vPacked.substr(vcStart + 2, vcEnd - (vcStart + 2)));
        vPacked = vPacked.substr(vcEnd + 2);
    }
    w->mIsInterrupted = false;
}

void OpUnitUI::addSeed(const String& id_cat, const String& title, const String& text, const String& link)
{
    DBObject* vDBObject = w->mBOHandlerMessage->addSeed(id_cat, title, text, link);
    w->maMessageUpdate->add(new String("2#" + w->mBOHandlerMessage->pack(vDBObject) + "3#"));
    sendOp(w->mOpUnitAppId, w->mNWrapper->mNKrossWrapper->mNGamma01, new OpParam((NParam)w->mBOHandlerMessage->getMessagesToDisplay()->sort(w->maSort)));
    setView(Wrapper::kViewDetails, vDBObject);
    w->mBOHandlerMessage->setMessage(w->mDBObjectSeedEdit, "0", "", "", "");
    w->mDBObjectSeedEdit->commit();
}

void OpUnitUI::archive(nuint vcDBObjectId, bool vIsArchived)
{
    DBObject* vDBObject = w->mBOHandlerMessage->get(vcDBObjectId);
    vDBObject->set("sArchivedAuto", vIsArchived);
    sendOp(w->mOpUnitAppId, w->mNWrapper->mNKrossWrapper->mNGamma01, new OpParam((NParam)w->mBOHandlerMessage->getMessagesToDisplay()->sort(w->maSort)));
}

void OpUnitUI::buzz(nuint vcDBObjectId, bool vIsBuzzed)
{
    w->mIsInterrupted = true;
    DBObject* vDBObject = w->mBOHandlerMessage->get(vcDBObjectId);

    if (vIsBuzzed && vDBObject->is("sEnabled") && !vDBObject->is("sBuzzed")) {
        ++w->mcInterrupt;
        vDBObject->set("sBuzzed", true);
        vDBObject->set("sRevRemote", vDBObject->count("sRevRemote") + 1);
        w->maMessageBuzz->add(new String("2#" + w->mBOHandlerMessage->packId(vDBObject) + "3#"));
        sendOp(w->mOpUnitAppId, w->mNWrapper->mNKrossWrapper->mNEta01, new OpParam((NParam)vDBObject));
        sendOp(w->mOpUnitAnimId, w->mNWrapper->mNKrossWrapper->mNAlpha00, new OpParam(0));
        vDBObject = nullptr;
    }
    if (!vIsBuzzed) {
        vDBObject->set("sBuzzed", false);
        sendOp(w->mOpUnitAppId, w->mNWrapper->mNKrossWrapper->mNEta01, new OpParam((NParam)vDBObject));
        vDBObject = nullptr;
    }
    if (vDBObject) {
        delete vDBObject;
    }
    w->mIsInterrupted = false;
}

void OpUnitUI::cancel()
{
    mAlive = false;
}

void OpUnitUI::discard(nuint vcDBObjectId, bool vIsDeleted)
{
    DBObject* vDBObject = w->mBOHandlerMessage->get(vcDBObjectId);
    vDBObject->set("sDeleted", vIsDeleted);

    if (!vDBObject->is("sIn")) {
        vDBObject->set("sRevSource", vDBObject->count("sRevSource") + 1);
        vDBObject->set("sArchivedUser", !vDBObject->is("sEnabled") || vDBObject->is("sDeleted"));
        w->maMessageUpdate->add(new String("2#" + w->mBOHandlerMessage->pack(vDBObject) + "3#"));
    }
    setView(Wrapper::kViewHome, nullptr);
    sendOp(w->mOpUnitAppId, w->mNWrapper->mNKrossWrapper->mNGamma01, new OpParam((NParam)w->mBOHandlerMessage->getMessagesToDisplay()->sort(w->maSort)));
    w->mDBObjectSeedEdit->commit();
    delete vDBObject;
}

void OpUnitUI::enable(nuint vcDBObjectId, bool vIsEnabled)
{
    DBObject* vDBObject = w->mBOHandlerMessage->get(vcDBObjectId);
    vIsEnabled = !vDBObject->is("sEnabled");
    vDBObject->set("sEnabled", vIsEnabled);

    if (!vDBObject->is("sIn") && vIsEnabled) {
        vDBObject->set("date", system_clock::now().time_since_epoch().count());
        vDBObject->set("sArchivedAuto", false);
    }
    if (!vDBObject->is("sIn")) {
        vDBObject->set("sRevSource", vDBObject->count("sRevSource") + 1);
        vDBObject->set("sArchivedUser", !vIsEnabled);
        w->maMessageUpdate->add(new String("2#" + w->mBOHandlerMessage->pack(vDBObject) + "3#"));
    }
    sendOp(w->mOpUnitAppId, w->mNWrapper->mNKrossWrapper->mNEta01, new OpParam((NParam)vDBObject));
    w->mDBObjectSeedEdit->commit();
}

void OpUnitUI::initUI()
{
    DBCollection* vDBCollection = w->mBOHandlerMessage->getMessagesToDisplay()->sort(w->maSort);
    sendOp(w->mOpUnitAppId, w->mNWrapper->mNKrossWrapper->mNGamma01, new OpParam((NParam)vDBCollection));
}

void OpUnitUI::initView()
{
    sendOp(w->mOpUnitAppId, w->mNWrapper->mNKrossWrapper->mNDelta01, new OpParam(w->mDBObjectApplication->count("sView"), (NParam)w->mBOHandlerMessage->get(w->mDBObjectApplication->count("sDBObjectId"))));
}

void OpUnitUI::setSeed(nuint vcDBObjectId, const String& id_cat, const String& title, const String& text, const String& link)
{
    DBObject* vDBObject = w->mBOHandlerMessage->setMessage(vcDBObjectId, id_cat, title, text, link);
    w->maMessageUpdate->add(new String("2#" + w->mBOHandlerMessage->pack(vDBObject) + "3#"));
    setView(Wrapper::kViewDetails, vDBObject);
    sendOp(w->mOpUnitAppId, w->mNWrapper->mNKrossWrapper->mNGamma01, new OpParam((NParam)w->mBOHandlerMessage->getMessagesToDisplay()->sort(w->maSort)));
    w->mDBObjectSeedEdit->commit();
}

void OpUnitUI::setView(nint vcView, nuint vcDBObjectId)
{
    sendOp(w->mOpUnitAppId, w->mNWrapper->mNKrossWrapper->mNDelta01, new OpParam(vcView, (NParam)( vcDBObjectId ? w->mBOHandlerMessage->get(vcDBObjectId) : nullptr )));
    w->mDBObjectApplication->set("sView", vcView);
    w->mDBObjectApplication->set("sDBObjectId", vcDBObjectId);
}

void OpUnitUI::setView(nint vcView, DBObject* vDBObject)
{
    sendOp(w->mOpUnitAppId, w->mNWrapper->mNKrossWrapper->mNDelta01, new OpParam(vcView, (NParam)vDBObject));
    w->mDBObjectApplication->set("sView", vcView);
    w->mDBObjectApplication->set("sDBObjectId", ( vDBObject ? vDBObject->mId : 0 ));
}

void OpUnitUI::sort(const String& vField, bool vIsAscending)
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
    sendOp(w->mOpUnitAppId, w->mNWrapper->mNKrossWrapper->mNDzeta01, new Op());
    sendOp(w->mOpUnitAppId, w->mNWrapper->mNKrossWrapper->mNGamma01, new OpParam((NParam)w->mBOHandlerMessage->getMessagesToDisplay()->sort(w->maSort)));
}

// void initUI()
NReturn OpUnitUI::visit(NAlpha00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    initUI();
    return 0;
}

// void initView()
NReturn OpUnitUI::visit(NBeta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    initView();
    return 0;
}

// nint addDrop(const String& packed)
NReturn OpUnitUI::visit(NGamma00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    addDrop(((OpMessage*)a)->mStringA);
    return 0;
}

// nint addSeed(const String& id_cat, const String& title, const String& text, const String& link)
NReturn OpUnitUI::visit(NDelta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    addSeed(((OpMessage*)a)->mStringA, ((OpMessage*)a)->mStringB, ((OpMessage*)a)->mStringC, ((OpMessage*)a)->mStringD);
    return 0;
}

// void render()
NReturn OpUnitUI::visit(NNu00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    //FIXME: check source
    sendOp(w->mOpUnitAppId, w->mNWrapper->mNKrossWrapper->mNGamma01, new OpParam((NParam)w->mBOHandlerMessage->getMessagesToDisplay()->sort(w->maSort)));
    return 0;
}

// void buzz(nuint vcDBObjectId, bool vIsBuzzed)
NReturn OpUnitUI::visit(NDzeta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    buzz((nuint)a, (nint)b);
    return 0;
}

// void discard(nuint vcDBObjectId, bool vIsArchived)
NReturn OpUnitUI::visit(NEpsilon00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    discard((nuint)a, (nint)b);
    return 0;
}

// void enable(nuint vcDBObjectId, bool vIsEnabled)
NReturn OpUnitUI::visit(NXi00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    enable((nuint)a, (nint)b);
    return 0;
}

// void setSeed(nuint vcDBObjectId, const String& id_cat, const String& title, const String& text, const String& link)
NReturn OpUnitUI::visit(NTheta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    setSeed((nuint)b, ((OpMessage*)a)->mStringA, ((OpMessage*)a)->mStringB, ((OpMessage*)a)->mStringC, ((OpMessage*)a)->mStringD);
    return 0;
}

// void setView(nint vIndex, nuint vcDBObjectId)
NReturn OpUnitUI::visit(NIota00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    setView((nint)a, (nuint)b);
    return 0;
}

// void sort(const String& vColumn, bool vIsAscending)
NReturn OpUnitUI::visit(NEta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    sort(((OpMessage*)a)->mStringA, (bool)b);
    return 0;
}

// void clear()
NReturn OpUnitUI::visit(NOmicron00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    //FIXME: check source
    sendOp(w->mOpUnitAppId, w->mNWrapper->mNKrossWrapper->mNGamma01, new OpParam((NParam)w->mBOHandlerMessage->getMessagesToDisplay()->sort(w->maSort)));
    return 0;
}

//
NReturn OpUnitUI::visit(NRho00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    DBCollection* vDBCollection = w->mBOHandlerMessage->getMessagesToBroadcast()->sort(w->maSort);
    nint i = vDBCollection->count();
    String* vString = new String( i ? "" : "2#3#" );

    while (--i >= 0) {
        *vString += "2#" + w->mBOHandlerMessage->pack(vDBCollection->get(i)) + "3#";
    }
    sendOp(a, w->mNWrapper->mNKrossWrapper->mNBeta00, new OpParam((NParam)vString, w->maMessageUpdate->mWriteIndex, w->maMessageBuzz->mWriteIndex, w->mcInterrupt));
    delete vDBCollection;
    return 0;
}

} // End namespace
