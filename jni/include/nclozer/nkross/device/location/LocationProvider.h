#ifndef __LocationProvider_H__
#define __LocationProvider_H__

namespace NSDEVICE
{

class LocationProvider : public Object
{
friend NSNATIVE::NKrossFriend;

public:
    virtual ~LocationProvider()
    {
    }

    bool hasMonetaryCost()
    {
        return NKrossWrapper::w->mNVisitorLocation->tRun(NKrossWrapper::w->mNXi00, (NParam)this);
    }

    bool supportsAltitude()
    {
        return NKrossWrapper::w->mNVisitorLocation->tRun(NKrossWrapper::w->mNOmicron00, (NParam)this);
    }

    bool supportsSpeed()
    {
        return NKrossWrapper::w->mNVisitorLocation->tRun(NKrossWrapper::w->mNPi00, (NParam)this);
    }

    bool supportsBearing()
    {
        return NKrossWrapper::w->mNVisitorLocation->tRun(NKrossWrapper::w->mNRho00, (NParam)this);
    }

private:
    LocationProvider(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
