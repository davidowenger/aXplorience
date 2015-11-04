#ifndef __LocationListener_H__
#define __LocationListener_H__

namespace NSDEVICE
{

class LocationListener
{
public:
    virtual ~LocationListener()
    {
        NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNDelta00, (NParam)this);
    }

    virtual void onLocationChanged(Location* location) = 0;
    virtual void onProviderDisabled(const String& provider) = 0;
    virtual void onProviderEnabled(const String& provider) = 0;
    virtual void onStatusChanged(const String& provider, int status, Bundle* extras) = 0;

protected:
    LocationListener()
    {
        NSNKROSS::w->mNVisitorLocation->tRun(NSNKROSS::w->mNEta00, (NParam)this);
    }
};

} // End namespace

#endif
