#include "Common.h"
#include "Theme.h"

#include <iomanip>

namespace NSDEVICE
{

OpUnitUI::OpUnitUI(Wrapper* const w)
	: OpUnit(w), mcProcessedDevice(0), mcTimeStampBroadcast(0), mcForce(0), mcRunningInitializations(0), mcDiscovery(0), mcDiscoveryDone(0), maMac()
{
}

OpUnitUI::~OpUnitUI()
{
}

void OpUnitUI::run()
{
    mWrapper->mOpUnitUIId = mId;

    maSort.emplace_back(mWrapper->mDBObjectApplication->get("sSort0"), mWrapper->mDBObjectApplication->is("sAscending0"));
    maSort.emplace_back(mWrapper->mDBObjectApplication->get("sSort1"), mWrapper->mDBObjectApplication->is("sAscending1"));
    maSort.emplace_back(mWrapper->mDBObjectApplication->get("sSort2"), mWrapper->mDBObjectApplication->is("sAscending2"));

    clear();
    mWrapper->w->dActivity->sendMessage((NParam)mWrapper->w->mNDelta01, (NParam)Wrapper::kViewHome, (NParam)1);
    setView(Wrapper::kViewHome, 1);
	handleOp();
    cancel();
}

void OpUnitUI::handleOp()
{
    Op* op;
    DBObject* vMessage;
    TimeStamp vcTimeStampNow;
    nint i = 0;

    while (mAlive) {
        //LOGE("OpUnitUI::handleOp");
        vcTimeStampNow = system_clock::now().time_since_epoch().count();

        if (vcTimeStampNow - mcTimeStampBroadcast > 2*mWrapper->mc10Secondes) {
            mcTimeStampBroadcast = vcTimeStampNow;
            DBCollection* vaMessage = mWrapper->mBOHandlerMessage->getMessagesToBroadcast();

            for (i = 0 ; i < vaMessage->count() ; ++i) {
                vMessage = vaMessage->get(i);

                if (vMessage->is("sIn")) {
                    if (vcTimeStampNow - vMessage->count("date") > 6*mWrapper->mc10Secondes) {
                        archive(vMessage->count("id"), true);
                    }
                } else {
                    vMessage->set("date", vcTimeStampNow)->commit();
                }
            }
            delete vaMessage;
        }
        op = nextOp();

        if (op) {
            execOp(op);
            //HINT: use op->result here, before calling nextOp again
        }
        this_thread::sleep_for(mWrapper->mcSleep);
    }
}

void OpUnitUI::addDrop(const String& packed)
{
    nint vcDBObjectId = mWrapper->mBOHandlerMessage->addDrop(packed);
    DBObject* vDBObject = mWrapper->mBOHandlerMessage->get(vcDBObjectId);

    if (!vDBObject->is("sIn") && vDBObject->is("sBuzzing")) {
        vDBObject->set("sBuzzing", false);
        vDBObject->commit();
        sendOp(0, mWrapper->mOpUnitCoreId, mWrapper->w->mNMu00, new OpParam(vcDBObjectId));
    }
    render();
    delete vDBObject;
}

void OpUnitUI::addSeed(const String& id_cat, const String& title, const String& text, const String& link)
{
    nint vcDBObjectId = mWrapper->mBOHandlerMessage->addSeed(id_cat, title, text, link);
    clear();
    mWrapper->w->dActivity->sendMessage((NParam)mWrapper->w->mNDelta01, (NParam)Wrapper::kViewDetails, (NParam)vcDBObjectId);
    setView(Wrapper::kViewDetails, vcDBObjectId);
}

void OpUnitUI::archive(nint vcDBObjectId, bool vIsArchived)
{
    DBObject* vDBObject = mWrapper->mBOHandlerMessage->get(vcDBObjectId);
    vDBObject->set("sArchivedAuto", vIsArchived);
    vDBObject->commit();
    clear();
    mWrapper->w->dActivity->sendMessage((NParam)mWrapper->w->mNDelta01, (NParam)Wrapper::kViewHome, (NParam)0);
    setView(Wrapper::kViewHome);
}

void OpUnitUI::buzz(nint vcDBObjectId, bool vIsBuzzed)
{
    DBObject* vDBObject = mWrapper->mBOHandlerMessage->get(vcDBObjectId);

    if (vIsBuzzed && vDBObject->is("sEnabled") && !vDBObject->is("sBuzzed")) {
        vDBObject->set("sBuzzed", true);
        vDBObject->commit();
        render();
        sendOp(0, mWrapper->mOpUnitCoreId, mWrapper->w->mNMu00, new OpParam(0));
    }
    if (!vIsBuzzed) {
        vDBObject->set("sBuzzed", false);
        vDBObject->commit();
        mcForce = mcForce + 1;
        render();
    }
    delete vDBObject;
}

void OpUnitUI::cancel()
{
    mAlive = false;
}

void OpUnitUI::clear()
{
    mWrapper->w->dActivity->sendMessage((NParam)mWrapper->w->mNBeta01, (NParam)mWrapper->mBOHandlerMessage->getMessagesToDisplay()->sort(maSort));
}

void OpUnitUI::discard(nint vcDBObjectId, bool vIsDeleted)
{
    DBObject* vDBObject = mWrapper->mBOHandlerMessage->get(vcDBObjectId);
    vDBObject->set("sDeleted", vIsDeleted);

    if (!vDBObject->is("sIn")) {
        vDBObject->set("sArchivedUser", !vDBObject->is("sEnabled") || vDBObject->is("sDeleted"));
    }
    vDBObject->commit();

    mcForce = mcForce + 1;
    clear();
    mWrapper->w->dActivity->sendMessage((NParam)mWrapper->w->mNDelta01, (NParam)Wrapper::kViewHome, (NParam)0);
    setView(Wrapper::kViewHome);
    delete vDBObject;
}

void OpUnitUI::enable(nint vcDBObjectId, bool vIsEnabled)
{
    DBObject* vDBObject = mWrapper->mBOHandlerMessage->get(vcDBObjectId);
    vDBObject->set("sEnabled", !vDBObject->is("sEnabled"));

    if (!vDBObject->is("sIn")) {
        vDBObject->set("sArchivedUser", !vDBObject->is("sEnabled") || vDBObject->is("sDeleted"));
    }
    vDBObject->commit();
    mcForce = mcForce + 1;
    render();

    delete vDBObject;
}

void OpUnitUI::render()
{
    mWrapper->w->dActivity->sendMessage((NParam)mWrapper->w->mNGamma01, (NParam)mWrapper->mBOHandlerMessage->getMessagesToDisplay()->sort(maSort));
}

void OpUnitUI::setSeed(nint vcDBObjectId, const String& id_cat, const String& title, const String& text, const String& link)
{
    mWrapper->mBOHandlerMessage->setMessage(vcDBObjectId, id_cat, title, text, link);
    render();
    mWrapper->w->dActivity->sendMessage((NParam)mWrapper->w->mNDelta01, (NParam)Wrapper::kViewDetails, (NParam)vcDBObjectId);
    setView(Wrapper::kViewDetails, vcDBObjectId);
}

void OpUnitUI::setView(nint vcView, nint vcDBObjectId)
{
    mWrapper->mDBObjectApplication->set("sView", vcView);
    mWrapper->mDBObjectApplication->set("sDBObjectId", vcDBObjectId);
    mWrapper->mDBObjectApplication->commit();
  //mWrapper->w->dActivity->sendMessage((NParam)mWrapper->w->mNDelta01, (NParam)vcView, (NParam)vcDBObjectId);
}

void OpUnitUI::sort(const String& vField, bool vIsAscending)
{
    nuint vIndex = 0;
    list<Sort>::iterator vIt = maSort.begin();

    while (vIt != maSort.end()) {
        vIt = ( vIt->mField == vField ? maSort.erase(vIt) : ++vIt );
    }
    maSort.emplace_back(vField, vIsAscending);

    for (Sort vSort : maSort) {
        mWrapper->mDBObjectApplication->set("sSort" + to_string(vIndex), vSort.mField)->set("sAscending" + to_string(vIndex), vSort.mIsAscending)->commit();
        ++vIndex;
    }
    mWrapper->w->dActivity->sendMessage((NParam)mWrapper->w->mNDzeta01, (NParam)mWrapper->mBOHandlerMessage->getMessagesToDisplay()->sort(maSort));
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

// void archive(nint vcDBObjectId, bool vIsArchived)
//NReturn OpUnitUI::visit(NNu00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
//{
//    archive((nint)a, (nint)b);
//    return 0;
//}

// void buzz(nint vcDBObjectId, bool vIsBuzzed)
NReturn OpUnitUI::visit(NDzeta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    buzz((nint)a, (nint)b);
    return 0;
}

// void discard(nint vcDBObjectId, bool vIsArchived)
NReturn OpUnitUI::visit(NEpsilon00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    discard((nint)a, (nint)b);
    return 0;
}

// void void setSeed(nint vcDBObjectId, const String& id_cat, const String& title, const String& text, const String& link)
NReturn OpUnitUI::visit(NXi00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    enable((nint)a, (nint)b);
    return 0;
}

// void void setSeed(nint vcDBObjectId, const String& id_cat, const String& title, const String& text, const String& link)
NReturn OpUnitUI::visit(NTheta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    setSeed(b, ((OpMessage*)a)->mStringA, ((OpMessage*)a)->mStringB, ((OpMessage*)a)->mStringC, ((OpMessage*)a)->mStringD);
    return 0;
}

// void setView(nint vIndex, nint vcDBObjectId = 1)
NReturn OpUnitUI::visit(NIota00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    setView((nint)a, (nint)b);
    return 0;
}

// void sort(const String& vColumn, bool vIsAscending)
NReturn OpUnitUI::visit(NEta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    sort(((OpMessage*)a)->mStringA, (bool)b);
    return 0;
}

// get messages for braodcast
NReturn OpUnitUI::visit(NOmicron00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    return (NReturn)mWrapper->mBOHandlerMessage->getMessagesToBroadcast();
}

} // End namespace
