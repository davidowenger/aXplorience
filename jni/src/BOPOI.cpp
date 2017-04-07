#include "Common.h"

namespace NSDEVICE
{

BOPOI::BOPOI(Wrapper* vWrapper) :
    w(vWrapper), mMac(), mId(0), mType(0), mCategoryId(0), mDistance(0.0), mTitle(), mText(),
    mIsBuzzed(false), mIsEnabled(false), mIsActive(false), mIsVisible(false),
    mAzimuth(k::MaxFloat), maEarthCoord(new nfloat[4] {}),
    mLine(0), maColor(new nfloat[4] {0.5, 0.14, 0.5, 1.0})
{
}

BOPOI::~BOPOI()
{
    delete[] maEarthCoord;
    delete[] maColor;
}

void BOPOI::setDistance(nfloat vDistance)
{
    mIsVisible = true; //((nuint)vDistance < 100000);
    mDistance = vDistance;
    mText = to_string((nuint)vDistance) + 'm';
}

void BOPOI::setAzimuth(nfloat vPrevious, nfloat vCurrent)
{
    mIsVisible = (vPrevious < k::MaxFloat);
    mAzimuth = vCurrent;
}

void BOPOI::update(DBObject* vDBObject)
{
    mIsVisible = true;
    mId = vDBObject->mId;
    mMac = vDBObject->get("MacSrc");
    mType = vDBObject->count("Type");
    mCategoryId = vDBObject->count("CategoryId");
    mTitle = vDBObject->get("Title");
    mIsEnabled = vDBObject->is("Enabled");
    mIsBuzzed = vDBObject->is("Buzzed");
    position(vDBObject);
}

void BOPOI::update(BOPOI* vBOPOI)
{
    mIsVisible = true;
    mId = vBOPOI->mId;
    mMac = vBOPOI->mMac;
    mType = vBOPOI->mType;
    mCategoryId = vBOPOI->mCategoryId;
    mTitle = vBOPOI->mTitle;
    mIsEnabled = vBOPOI->mIsEnabled;
    mIsBuzzed = vBOPOI->mIsBuzzed;
    maEarthCoord[0] = vBOPOI->maEarthCoord[0];
    maEarthCoord[1] = vBOPOI->maEarthCoord[1];
    maEarthCoord[2] = vBOPOI->maEarthCoord[2];
}

void BOPOI::position(DBObject* vDBObject)
{
    maEarthCoord[0] = to_float(vDBObject->get("EarthCoordX"));
    maEarthCoord[1] = to_float(vDBObject->get("EarthCoordY"));
    maEarthCoord[2] = to_float(vDBObject->get("EarthCoordZ"));
}

} // End namespace
