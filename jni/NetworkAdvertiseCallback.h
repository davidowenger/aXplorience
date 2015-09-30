#ifndef __NetworkAdvertiseCallback_H__
#define __NetworkAdvertiseCallback_H__

namespace NSDEVICE
{

class NetworkAdvertiseCallback : public AdvertiseCallback
{
public:
    NetworkAdvertiseCallback(Wrapper* vWrapper)
        : w(vWrapper)
    {
    }

    virtual ~NetworkAdvertiseCallback()
    {
    }

    virtual void onStartFailure(int errorCode)
    {
        LOGD(("Advertise Failure code : #" + to_string(errorCode)).c_str());
        unique_lock<mutex> vUniqueLock(w->mMutex);
        w->mConditionServicesAdded.notify_all();
    }

    virtual void onStartSuccess(AdvertiseSettings* settingsInEffect)
    {
        LOGD("Advertise Success");
        unique_lock<mutex> vUniqueLock(w->mMutex);
        w->mConditionServicesAdded.notify_all();
    }

    Wrapper* w;
};

} // End namespace

#endif
