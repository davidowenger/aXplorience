#include "Common.h"
#include "Theme.h"

namespace NSDEVICE
{

OpUnitAR::OpUnitAR(Wrapper* const vWrapper) :
    OpUnit(vWrapper->mNWrapper), mIsARInitialized(false), mARState(7), w(vWrapper)
{
}

OpUnitAR::~OpUnitAR()
{
    if (mIsARInitialized) {
        delete w->mLocationManager;
        delete w->mGraphicsHandler;
        delete w->mCoordBuffer;
        delete w->mRotationBuffer;
        delete w->mAREngine;
    }
}

void OpUnitAR::run()
{
    Op* vOp;
    engineCreate();

    while (mAlive) {
        vOp = nextOp();

        if (vOp) {
            execOp(vOp);
        }
        if (mARState == 0) {
            w->mAREngine->engineRun();
            mARState = (w->mARState != 2)*4;
            this_thread::sleep_for(chrono::milliseconds(10));
        } else {
            switch (mARState) {
            case 1:
                w->mAREngine->engineEnable(w->mSurface, w->mSurfaceWidth, w->mSurfaceHeight);
                mARState = 2;
                break;
            case 2:
                if (w->mARState == 2) {
                    mARState = 3;
                }
                if (w->mARState == 0 && w->mARSurface == 0) {
                    mARState = 6;
                }
                break;
            case 3:
                w->mAREngine->engineResume();
                mARState = 0;
                break;
            case 4:
                w->mAREngine->engineSleep();
                mARState = 5;
                break;
            case 5:
                if (w->mARState == 2) {
                    mARState = 3;
                }
                if (w->mARState == 0 && w->mARSurface == 0) {
                    mARState = 6;
                }
                break;
            case 6:
                w->mAREngine->engineEnd();
                mARState = 7;
                break;
            case 7:
                if (w->mARState > 0 && w->mARSurface == 2) {
                    mARState = 1;
                }
                break;
            }
            this_thread::sleep_for(chrono::milliseconds(200));
        }
    }
}

void OpUnitAR::engineCreate()
{
    w->mOpUnitEvents->start();

  //w->mGraphicsHandler = new GraphicsHandler(w->mNWrapper);
    w->mAREngine = new AREngine(w);
    w->mAREngine->engineCreate();
}

void OpUnitAR::engineRunEvent(nlong vT, nuint vX, nuint vY, nuint vState)
{
    w->mAREngine->engineRunEvent(vT, vX, vY, vState);
}

void OpUnitAR::poiAdd(DBObject* vDBObject)
{
    BOPOI* vBOPOI = new BOPOI(w);
    vBOPOI->update(vDBObject);
    w->maPOIDynamic[vDBObject->mId] = vBOPOI;
    w->mAREngine->mMaxDistance = 0;
    w->mAREngine->mMaxStatic->mIsActive = false;
    w->mAREngine->mMaxSorted->update(vDBObject);
}

void OpUnitAR::poiDiscard(nuint vDBObjectId)
{
    map<nuint,BOPOI*>::iterator vIt = w->maPOIDynamic.find(vDBObjectId);

    if (vIt != w->maPOIDynamic.end()) {
        w->maPOISorted.remove(vIt->second);
        w->maPOIDynamic.erase(vIt);
    }
}

void OpUnitAR::poiPosition(DBObject* vDBObject)
{
    w->maPOIDynamic[vDBObject->mId]->position(vDBObject);
}

void OpUnitAR::poiUpdate(DBObject* vDBObject)
{
    map<nuint,BOPOI*>::iterator vIt = w->maPOIDynamic.find(vDBObject->mId);

    if (vIt != w->maPOIDynamic.end()) {
        vIt->second->update(vDBObject);
    } else {
        poiAdd(vDBObject);
    }
}

NReturn OpUnitAR::visit(NBeta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    engineRunEvent(a, b, c, d);
    return 0;
}

NReturn OpUnitAR::visit(NGamma00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    poiAdd((DBObject*)a);
    delete (DBObject*)a;
    return 0;
}

NReturn OpUnitAR::visit(NDelta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    poiDiscard((nuint)a);
    return 0;
}

NReturn OpUnitAR::visit(NEpsilon00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    poiPosition((DBObject*)a);
    delete (DBObject*)a;
    return 0;
}

NReturn OpUnitAR::visit(NDzeta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    poiUpdate((DBObject*)a);
    delete (DBObject*)a;
    return 0;
}

} // End namespace


//void OpUnitAR::updateMessages(DBCollection* vDBCollection)
//{
//    DBObject* vDBObject;
//    BOPOI* vPOI;
//    nuint i = vDBCollection->count();
//
//    for (auto const& vPOIPair : w->maPOIStatic) {
//        vPOIPair.second->sleep();
//    }
//    while (i--) {
//        vDBObject = vDBCollection->get(i);
//        vPOI = w->maPOIStatic[vDBObject->get("MacSrc")];
//
//        if (!vPOI) {
//            vPOI = new BOPOI(w);
//            w->maPOISorted.add(vPOI, k::MaxFloat);
//        }
//        vPOI->update(vDBObject);
//    }
//    delete vDBCollection;
//
//    // updateMessages(collection)
//    for bomsg in map<BOMsg>
//        bomsg->archive()
//
//    for dbobj in collection
//        if (map.find(dbobj))
//            map<BOMsg>[dbobj->id]->update(dbobj)
//        else
//            vNewMsg =  = new BOMsg(dbobj)
//            map<BOMsg>[dbobj->id] = vNewMsg
//            sortlist->add(vNewMsg)
//
//    // run
//    for bomsg in sortlist
//        if (bomsg->archived)
//            sortlist->remove(bomsg)
//            map<BOMsg>.erase(bomsg)
//        else
//            sortlist->updateValue(azimute)
//            draw()
//        order++
//
//
//
//    nint vPOICount = w->maPOIStatic.mcData;
//    nint vMessageCount = vDBCollection->count();
//    w->mPOISortList->resize(vPOICount + vMessageCount);
//
//    while (vPOICount--) {
//        w->mPOISortList->updateObject(w->maPOIStatic[vPOICount]);
//    }
//    while (vMessageCount--) {
//        w->mPOISortList->updateObject(vDBCollection->get(vMessageCount));
//    }
//    delete vDBCollection;
//}
