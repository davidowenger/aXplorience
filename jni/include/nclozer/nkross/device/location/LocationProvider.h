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
        return NSNKROSS::w->mNVisitorLocation->tRun(NSNKROSS::w->mNXi00, (NParam)this);
    }

    bool supportsAltitude()
    {
        return NSNKROSS::w->mNVisitorLocation->tRun(NSNKROSS::w->mNOmicron00, (NParam)this);
    }

    bool supportsSpeed()
    {
        return NSNKROSS::w->mNVisitorLocation->tRun(NSNKROSS::w->mNPi00, (NParam)this);
    }

    bool supportsBearing()
    {
        return NSNKROSS::w->mNVisitorLocation->tRun(NSNKROSS::w->mNRho00, (NParam)this);
    }

private:
    LocationProvider(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
