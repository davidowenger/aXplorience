#include "Common.h"
#include "Theme.h"

namespace NSDEVICE
{
OpUnitUI::OpUnitUI(Wrapper* const w)
    : OpUnit(w), mcProcessedDevice(0), mcTimeStampPrevious(0), mcTimeStampNow(0), mcState(0), mcRunningInitializations(0),
      mcDiscovery(0), mcDiscoveryDone(0), maMac(), mDBCollection(nullptr)
{
}

OpUnitUI::~OpUnitUI()
{
}

void OpUnitUI::run()
{
    sendOp(mWrapper->mOpUnitUIId, w->mNAlpha00, new Op());
    handleOp();
    cancel();
}

void OpUnitUI::handleOp()
{
    Op* op;
    DBObject* vMessage;
    nint i;

    while (mAlive) {
        mcTimeStampNow = system_clock::now().time_since_epoch().count();

        if (mcState == 0 && mcTimeStampNow - mcTimeStampPrevious > 20*mWrapper->mc1Seconde) {
            // Update messages time
            mcTimeStampPrevious = mcTimeStampNow;
            mDBCollection = mWrapper->mBOHandlerMessage->getMessagesToBroadcast();
            i = mDBCollection->count();

            while (--i >= 0) {
                vMessage = mDBCollection->get(i);

                if (!vMessage->is("sIn") && !vMessage->is("sArchivedUser")) {
                    vMessage->set("sRevSource", vMessage->count("sRevSource") + 1);
                    vMessage->set("date", mcTimeStampNow);
                }
                if (mcTimeStampNow - vMessage->count("date") > 60*mWrapper->mc1Seconde) {
                    archive(vMessage->mId, true);
                }
            }
            delete mDBCollection;
            mcState = 1;
        }
        if (mcState == 1 && mcTimeStampNow - mcTimeStampPrevious > 5*mWrapper->mc1Seconde) {
            LOGD("Persistence");
            mWrapper->mBOHandlerMessage->clean();
            mWrapper->mDBObjectSeedEdit->commit();
            mWrapper->mDBObjectApplication->commit();
            mcState = 2;
        }
        if (mcState == 2 && mcTimeStampNow - mcTimeStampPrevious > 10*mWrapper->mc1Seconde) {
            // Broadcast alive messages
            mDBCollection = mWrapper->mBOHandlerMessage->getMessagesToBroadcast()->sort(mWrapper->maSort);
            i = mDBCollection->count();
            String* vPacket = new String( i ? "" : "2#3#" );

            while (--i >= 0) {
                *vPacket += "2#" + mWrapper->mBOHandlerMessage->packId(mDBCollection->get(i)) + "3#";
            }
            mWrapper->maMessageAlive->add(vPacket);
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
        this_thread::sleep_for(200*mWrapper->mMili);
    }
    mWrapper->mBOHandlerMessage->clean();
    mWrapper->mDBObjectSeedEdit->commit();
    mWrapper->mDBObjectApplication->commit();
}

OpCallback* OpUnitUI::sendOp(int vcOpUnitId, NElement* vNElement, Op* vOp)
{
    OpCallback* ret = nullptr;

    if (mAlive && mOpSquad->maOpUnitType[vcOpUnitId] == Wrapper::OPUNIT_TYPE_ACTIVITY) {
        vOp->mNElement = vNElement;
        mWrapper->mNActivity->sendMessage((NParam)vOp);
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
    mWrapper->mIsInterrupted = true;
    LOGD(("Packed message received : #" + vPacked).c_str());

    while (mAlive && (vcStart = vPacked.find("2#")) >= 0 && (vcEnd = vPacked.find("3#")) >= 0 && vcStart + 2 < vcEnd) {
        mWrapper->mBOHandlerMessage->addDrop(this, vPacked.substr(vcStart + 2, vcEnd - (vcStart + 2)));
        vPacked = vPacked.substr(vcEnd + 2);
    }
    mWrapper->mIsInterrupted = false;
}

void OpUnitUI::addSeed(const String& id_cat, const String& title, const String& text, const String& link)
{
    DBObject* vDBObject = mWrapper->mBOHandlerMessage->addSeed(id_cat, title, text, link);
    mWrapper->maMessageUpdate->add(new String("2#" + mWrapper->mBOHandlerMessage->pack(vDBObject) + "3#"));
    sendOp(mWrapper->mOpUnitAppId, w->mNGamma01, new OpParam((NParam)mWrapper->mBOHandlerMessage->getMessagesToDisplay()->sort(mWrapper->maSort)));
    setView(Wrapper::kViewDetails, vDBObject);
    mWrapper->mBOHandlerMessage->setMessage(mWrapper->mDBObjectSeedEdit, "0", "", "", "");
    mWrapper->mDBObjectSeedEdit->commit();
}

void OpUnitUI::archive(nuint vcDBObjectId, bool vIsArchived)
{
    DBObject* vDBObject = mWrapper->mBOHandlerMessage->get(vcDBObjectId);
    vDBObject->set("sArchivedAuto", vIsArchived);
    sendOp(mWrapper->mOpUnitAppId, w->mNGamma01, new OpParam((NParam)mWrapper->mBOHandlerMessage->getMessagesToDisplay()->sort(mWrapper->maSort)));
}

void OpUnitUI::buzz(nuint vcDBObjectId, bool vIsBuzzed)
{
    mWrapper->mIsInterrupted = true;
    DBObject* vDBObject = mWrapper->mBOHandlerMessage->get(vcDBObjectId);

    if (vIsBuzzed && vDBObject->is("sEnabled") && !vDBObject->is("sBuzzed")) {
        ++mWrapper->mcInterrupt;
        vDBObject->set("sBuzzed", true);
        vDBObject->set("sRevRemote", vDBObject->count("sRevRemote") + 1);
        mWrapper->maMessageBuzz->add(new String("2#" + mWrapper->mBOHandlerMessage->packId(vDBObject) + "3#"));
        sendOp(mWrapper->mOpUnitAppId, w->mNEta01, new OpParam((NParam)vDBObject));
        sendOp(mWrapper->mOpUnitAnimId, nullptr, new OpParam(0));
        vDBObject = nullptr;
    }
    if (!vIsBuzzed) {
        vDBObject->set("sBuzzed", false);
        sendOp(mWrapper->mOpUnitAppId, w->mNEta01, new OpParam((NParam)vDBObject));
        vDBObject = nullptr;
    }
    if (vDBObject) {
        delete vDBObject;
    }
    mWrapper->mIsInterrupted = false;
}

void OpUnitUI::cancel()
{
    mAlive = false;
}

void OpUnitUI::discard(nuint vcDBObjectId, bool vIsDeleted)
{
    DBObject* vDBObject = mWrapper->mBOHandlerMessage->get(vcDBObjectId);
    vDBObject->set("sDeleted", vIsDeleted);

    if (!vDBObject->is("sIn")) {
        vDBObject->set("sRevSource", vDBObject->count("sRevSource") + 1);
        vDBObject->set("sArchivedUser", !vDBObject->is("sEnabled") || vDBObject->is("sDeleted"));
        mWrapper->maMessageUpdate->add(new String("2#" + mWrapper->mBOHandlerMessage->pack(vDBObject) + "3#"));
    }
    setView(Wrapper::kViewHome, nullptr);
    sendOp(mWrapper->mOpUnitAppId, w->mNGamma01, new OpParam((NParam)mWrapper->mBOHandlerMessage->getMessagesToDisplay()->sort(mWrapper->maSort)));
    mWrapper->mDBObjectSeedEdit->commit();
    delete vDBObject;
}

void OpUnitUI::enable(nuint vcDBObjectId, bool vIsEnabled)
{
    DBObject* vDBObject = mWrapper->mBOHandlerMessage->get(vcDBObjectId);
    vIsEnabled = !vDBObject->is("sEnabled");
    vDBObject->set("sEnabled", vIsEnabled);

    if (!vDBObject->is("sIn") && vIsEnabled) {
        vDBObject->set("date", system_clock::now().time_since_epoch().count());
        vDBObject->set("sArchivedAuto", false);
    }
    if (!vDBObject->is("sIn")) {
        vDBObject->set("sRevSource", vDBObject->count("sRevSource") + 1);
        vDBObject->set("sArchivedUser", !vIsEnabled);
        mWrapper->maMessageUpdate->add(new String("2#" + mWrapper->mBOHandlerMessage->pack(vDBObject) + "3#"));
    }
    sendOp(mWrapper->mOpUnitAppId, w->mNEta01, new OpParam((NParam)vDBObject));
    mWrapper->mDBObjectSeedEdit->commit();
}

void OpUnitUI::initUI()
{
    DBCollection* vDBCollection = mWrapper->mBOHandlerMessage->getMessagesToDisplay()->sort(mWrapper->maSort);
    sendOp(mWrapper->mOpUnitAppId, w->mNGamma01, new OpParam((NParam)vDBCollection));
}

void OpUnitUI::initView()
{
    sendOp(mWrapper->mOpUnitAppId, w->mNDelta01, new OpParam(mWrapper->mDBObjectApplication->count("sView"), (NParam)mWrapper->mBOHandlerMessage->get(mWrapper->mDBObjectApplication->count("sDBObjectId"))));
}

void OpUnitUI::setSeed(nuint vcDBObjectId, const String& id_cat, const String& title, const String& text, const String& link)
{
    DBObject* vDBObject = mWrapper->mBOHandlerMessage->setMessage(vcDBObjectId, id_cat, title, text, link);
    mWrapper->maMessageUpdate->add(new String("2#" + mWrapper->mBOHandlerMessage->pack(vDBObject) + "3#"));
    setView(Wrapper::kViewDetails, vDBObject);
    sendOp(mWrapper->mOpUnitAppId, w->mNGamma01, new OpParam((NParam)mWrapper->mBOHandlerMessage->getMessagesToDisplay()->sort(mWrapper->maSort)));
    mWrapper->mDBObjectSeedEdit->commit();
}

void OpUnitUI::setView(nint vcView, nuint vcDBObjectId)
{
    sendOp(mWrapper->mOpUnitAppId, w->mNDelta01, new OpParam(vcView, (NParam)( vcDBObjectId ? mWrapper->mBOHandlerMessage->get(vcDBObjectId) : nullptr )));
    mWrapper->mDBObjectApplication->set("sView", vcView);
    mWrapper->mDBObjectApplication->set("sDBObjectId", vcDBObjectId);
}

void OpUnitUI::setView(nint vcView, DBObject* vDBObject)
{
    sendOp(mWrapper->mOpUnitAppId, w->mNDelta01, new OpParam(vcView, (NParam)vDBObject));
    mWrapper->mDBObjectApplication->set("sView", vcView);
    mWrapper->mDBObjectApplication->set("sDBObjectId", ( vDBObject ? vDBObject->mId : 0 ));
}

void OpUnitUI::sort(const String& vField, bool vIsAscending)
{
    nuint vIndex = 0;
    list<Sort>::iterator vIt = mWrapper->maSort.begin();

    while (vIt != mWrapper->maSort.end()) {
        vIt = ( vIt->mField == vField ? mWrapper->maSort.erase(vIt) : ++vIt );
    }
    mWrapper->maSort.emplace_back(vField, vIsAscending);

    for (Sort vSort : mWrapper->maSort) {
        mWrapper->mDBObjectApplication->set("sSort" + to_string(vIndex), vSort.mField)->set("sAscending" + to_string(vIndex), vSort.mIsAscending);
        ++vIndex;
    }
    sendOp(mWrapper->mOpUnitAppId, w->mNDzeta01, new Op());
    sendOp(mWrapper->mOpUnitAppId, w->mNGamma01, new OpParam((NParam)mWrapper->mBOHandlerMessage->getMessagesToDisplay()->sort(mWrapper->maSort)));
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
    sendOp(mWrapper->mOpUnitAppId, w->mNGamma01, new OpParam((NParam)mWrapper->mBOHandlerMessage->getMessagesToDisplay()->sort(mWrapper->maSort)));
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
    sendOp(mWrapper->mOpUnitAppId, w->mNGamma01, new OpParam((NParam)mWrapper->mBOHandlerMessage->getMessagesToDisplay()->sort(mWrapper->maSort)));
    return 0;
}

//
NReturn OpUnitUI::visit(NRho00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    DBCollection* vDBCollection = mWrapper->mBOHandlerMessage->getMessagesToBroadcast()->sort(mWrapper->maSort);
    nint i = vDBCollection->count();
    String* vString = new String( i ? "" : "2#3#" );

    while (--i >= 0) {
        *vString += "2#" + mWrapper->mBOHandlerMessage->pack(vDBCollection->get(i)) + "3#";
    }
    sendOp(a, w->mNBeta00, new OpParam((NParam)vString, mWrapper->maMessageUpdate->mWriteIndex, mWrapper->maMessageBuzz->mWriteIndex, mWrapper->mcInterrupt));
    delete vDBCollection;
    return 0;
}

} // End namespace
