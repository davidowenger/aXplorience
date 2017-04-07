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
        NReturn index = NKrossWrapper::w->mNVisitorLocation->tRun(NKrossWrapper::w->mNTheta00, (NParam)this);
        NReturn size = NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNAlpha01, index, -1);
        vector<String> vVector(size);
        nuint i;

        for (i = 0 ; i < size ; ++i) {
            vVector[i] = NKrossWrapper::w->mNKrossSystem->tGetString(NKrossWrapper::w->mNKrossSystem->tRunObject(index, (NParam)i));
        }
        return vVector;
    }

    Location* getLastKnownLocation(const String& provider)
    {
        Location* b = NKrossWrapper::w->mNKrossFriend->pointer<Location>();
        return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorLocation->tRun(NKrossWrapper::w->mNIota00, (NParam)this, (NParam)b, NKrossParam(provider).n));
    }

    LocationProvider* getProvider(const String& name)
    {
        LocationProvider* b = NKrossWrapper::w->mNKrossFriend->pointer<LocationProvider>();
        return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorLocation->tRun(NKrossWrapper::w->mNTau00, (NParam)this, (NParam)b, NKrossParam(name).n));
    }

    bool isProviderEnabled(const String& provider)
    {
        return NKrossWrapper::w->mNVisitorLocation->tRun(NKrossWrapper::w->mNKappa00, (NParam)this, NKrossParam(provider).n);
    }

    void removeUpdates(LocationListener* listener)
    {
        NKrossWrapper::w->mNVisitorLocation->tRun(NKrossWrapper::w->mNLambda00, (NParam)this, (NParam)listener);
    }

    // Will throw RuntimeException if the calling thread has no Looper
    void requestLocationUpdates(const String& provider, int minTime, float minDistance, LocationListener* listener, Looper* looper)
    {
        nfloat vcValue = minDistance;
        NKrossWrapper::w->mNVisitorLocation->tRun(NKrossWrapper::w->mNMu00, (NParam)this, NKrossParam(provider).n, ((nlong)minTime<<32) + *reinterpret_cast<nint*>(&vcValue), (NParam)listener, (NParam)looper);
    }

    // Use null Looper to make callbacks on the calling thread, will throw RuntimeException if the calling thread has no Looper
    void requestSingleUpdate(const String& provider, LocationListener* listener, Looper* looper)
    {
        NKrossWrapper::w->mNVisitorLocation->tRun(NKrossWrapper::w->mNNu00, (NParam)this, NKrossParam(provider).n, (NParam)listener, (NParam)looper);
    }

    void enable()
    {
        NKrossWrapper::w->mNVisitorLocation->tRun(NKrossWrapper::w->mNSigma00, (NParam)this);
    }

private:
    LocationManager(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
