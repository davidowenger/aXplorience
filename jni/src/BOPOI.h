#ifndef __BOPOI_H__
#define __BOPOI_H__

namespace NSDEVICE
{

class BOPOI
{
public:
    BOPOI(Wrapper* w);
    virtual ~BOPOI();

    void setDistance(nfloat vDistance);
    void setAzimuth(nfloat vPrevious, nfloat vCurrent);
    void update(DBObject* vDBObject);
    void update(BOPOI* vBOPOI);
    void position(DBObject* vDBObject);

    Wrapper* w;
    String mMac;
    nuint mId;
    nint mType;
    nint mCategoryId;
    nfloat mDistance;
    String mTitle;
    String mText;

    bool mIsBuzzed;
    bool mIsEnabled;
    bool mIsActive;
    bool mIsVisible;
    nfloat mAzimuth;
    nfloat* maEarthCoord;
    nint mLine;
    nfloat* maColor;
};

} // End namespace

#endif
