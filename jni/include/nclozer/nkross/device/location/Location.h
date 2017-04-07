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
        nlong vcValue = (nint)NKrossWrapper::w->mNVisitorLocation->tRun(NKrossWrapper::w->mNAlpha00, (NParam)this);
        return (nfloat)*reinterpret_cast<ndouble*>(&vcValue);
    }

    double getAltitude()
    {
        nlong vcValue = (nlong)NKrossWrapper::w->mNVisitorLocation->tRun(NKrossWrapper::w->mNBeta00, (NParam)this);
        return *reinterpret_cast<ndouble*>(&vcValue);
    }

    double getLatitude()
    {
        nlong vcValue = (nlong)NKrossWrapper::w->mNVisitorLocation->tRun(NKrossWrapper::w->mNGamma00, (NParam)this);
        return *reinterpret_cast<ndouble*>(&vcValue);
    }

    double getLongitude()
    {
        nlong vcValue = (nlong)NKrossWrapper::w->mNVisitorLocation->tRun(NKrossWrapper::w->mNDelta00, (NParam)this);
        return *reinterpret_cast<ndouble*>(&vcValue);
    }

    long long int getTime()
    {
        return NKrossWrapper::w->mNVisitorLocation->tRun(NKrossWrapper::w->mNEpsilon00, (NParam)this);
    }

    bool hasAltitude()
    {
        return NKrossWrapper::w->mNVisitorLocation->tRun(NKrossWrapper::w->mNDzeta00, (NParam)this);
    }

private:
    Location(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
