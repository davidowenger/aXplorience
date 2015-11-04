#ifndef __Location_H__
#define __Location_H__

namespace NSDEVICE
{

class Location : public Object
{
friend NSNATIVE::NKrossFriend;

public:
    virtual ~Location()
    {
    }

    float getAccuracy()
    {
        nlong vcValue = (nint)NSNKROSS::w->mNVisitorLocation->tRun(NSNKROSS::w->mNAlpha00, (NParam)this);
        return (nfloat)*reinterpret_cast<ndouble*>(&vcValue);
    }

    double getAltitude()
    {
        nlong vcValue = (nlong)NSNKROSS::w->mNVisitorLocation->tRun(NSNKROSS::w->mNBeta00, (NParam)this);
        return *reinterpret_cast<ndouble*>(&vcValue);
    }

    double getLatitude()
    {
        nlong vcValue = (nlong)NSNKROSS::w->mNVisitorLocation->tRun(NSNKROSS::w->mNGamma00, (NParam)this);
        return *reinterpret_cast<ndouble*>(&vcValue);
    }

    double getLongitude()
    {
        nlong vcValue = (nlong)NSNKROSS::w->mNVisitorLocation->tRun(NSNKROSS::w->mNDelta00, (NParam)this);
        return *reinterpret_cast<ndouble*>(&vcValue);
    }

    long long int getTime()
    {
        return NSNKROSS::w->mNVisitorLocation->tRun(NSNKROSS::w->mNEpsilon00, (NParam)this);
    }

    bool hasAltitude()
    {
        return NSNKROSS::w->mNVisitorLocation->tRun(NSNKROSS::w->mNDzeta00, (NParam)this);
    }

private:
    Location(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
