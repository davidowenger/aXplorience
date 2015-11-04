#ifndef __LocationManager_H__
#define __LocationManager_H__

namespace NSDEVICE
{

class LocationManager : public Object
{
friend NSNATIVE::NKrossFriend;

public:
    static const String GPS_PROVIDER;
    static const String NETWORK_PROVIDER;
    static const String PASSIVE_PROVIDER;

    virtual ~LocationManager()
    {
    }

    vector<String> getAllProviders()
    {
        NReturn index = NSNKROSS::w->mNVisitorLocation->tRun(NSNKROSS::w->mNTheta00, (NParam)this);
        NReturn size = NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNAlpha01, index, -1);
        vector<String> vVector(size);
        nuint i;

        for (i = 0 ; i < size ; ++i) {
            vVector[i] = NSNKROSS::w->mNKrossSystem->tGetString(NSNKROSS::w->mNKrossSystem->tRunObject(index, (NParam)i));
        }
        return vVector;
    }

    Location* getLastKnownLocation(const String& provider)
    {
        Location* b = NSNKROSS::w->mNKrossFriend->pointer<Location>();
        return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorLocation->tRun(NSNKROSS::w->mNIota00, (NParam)this, (NParam)b, NKrossParam(provider).n));
    }

    LocationProvider* getProvider(const String& name)
    {
        LocationProvider* b = NSNKROSS::w->mNKrossFriend->pointer<LocationProvider>();
        return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorLocation->tRun(NSNKROSS::w->mNTau00, (NParam)this, (NParam)b, NKrossParam(name).n));
    }

    bool isProviderEnabled(const String& provider)
    {
        return NSNKROSS::w->mNVisitorLocation->tRun(NSNKROSS::w->mNKappa00, (NParam)this, NKrossParam(provider).n);
    }

    void removeUpdates(LocationListener* listener)
    {
        NSNKROSS::w->mNVisitorLocation->tRun(NSNKROSS::w->mNLambda00, (NParam)this, (NParam)listener);
    }

    // Will throw RuntimeException if the calling thread has no Looper
    void requestLocationUpdates(const String& provider, int minTime, float minDistance, LocationListener* listener, Looper* looper)
    {
        nfloat vcValue = minDistance;
        NSNKROSS::w->mNVisitorLocation->tRun(NSNKROSS::w->mNMu00, (NParam)this, NKrossParam(provider).n, ((nlong)minTime<<32) + *reinterpret_cast<nint*>(&vcValue), (NParam)listener, (NParam)looper);
    }

    // Use null Looper to make callbacks on the calling thread, will throw RuntimeException if the calling thread has no Looper
    void requestSingleUpdate(const String& provider, LocationListener* listener, Looper* looper)
    {
        NSNKROSS::w->mNVisitorLocation->tRun(NSNKROSS::w->mNNu00, (NParam)this, NKrossParam(provider).n, (NParam)listener, (NParam)looper);
    }

    void enable()
    {
        NSNKROSS::w->mNVisitorLocation->tRun(NSNKROSS::w->mNSigma00, (NParam)this);
    }

private:
    LocationManager(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
