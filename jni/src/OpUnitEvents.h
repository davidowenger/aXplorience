#ifndef __OpUnitEvents_H__
#define __OpUnitEvents_H__

namespace NSDEVICE
{

class LocationEventListener : public LocationListener
{
public:
    LocationEventListener(Wrapper* vWrapper);
    virtual ~LocationEventListener();

    // LocationListener
    virtual void onLocationChanged(Location* location);
    virtual void onProviderDisabled(const String& provider);
    virtual void onProviderEnabled(const String& provider);
    virtual void onStatusChanged(const String& provider, int status, Bundle* extras);

    Wrapper* w;
};

class OpUnitEvents : public OpUnit
{
public:
    static nint onRotation(nint fd, nint events, void* data);

    OpUnitEvents(Wrapper* const w);
    virtual ~OpUnitEvents() override;
    virtual void cancel() override;
    virtual void run() override;

    void initLocationProvider();
    void initRotationProvider();
    void killLocationProvider();
    void killRotationProvider();
    void startEventsProduction();
    void stopEventsProduction();
    void registerLocationListener();
    void registerRotationListener();
    void releaseLocationListener();
    void releaseRotationListener();

    bool mAliveAR;
    nint mOutEvents;
    nint mOutFd;

    Looper* mLooper;
    Wrapper* mOutData;
    Wrapper* w;
};

} // End namespace

#endif
