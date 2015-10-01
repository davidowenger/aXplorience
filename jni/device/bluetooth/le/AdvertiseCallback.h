#ifndef __AdvertiseCallback_H__
#define __AdvertiseCallback_H__

namespace NSDEVICE
{

class AdvertiseCallback : public Object
{
friend NSNATIVE::NNoObject;

public:
    static const int ADVERTISE_FAILED_ALREADY_STARTED = 0x00000003;
    static const int ADVERTISE_FAILED_DATA_TOO_LARGE = 0x00000001;
    static const int ADVERTISE_FAILED_FEATURE_UNSUPPORTED = 0x00000005;
    static const int ADVERTISE_FAILED_INTERNAL_ERROR = 0x00000004;
    static const int ADVERTISE_FAILED_TOO_MANY_ADVERTISERS = 0x00000002;

    AdvertiseCallback()
    {
        NWrapper::w->mNVisitorBluetoothLe->tRun(NWrapper::w->mNAlpha00, (NParam)this);
    }

    virtual ~AdvertiseCallback()
    {
    }

    virtual void onStartFailure(int errorCode) = 0;
    virtual void onStartSuccess(AdvertiseSettings* settingsInEffect) = 0;

private:
    AdvertiseCallback(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif
