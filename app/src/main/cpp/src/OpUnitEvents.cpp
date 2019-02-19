#include "Common.h"
#include "Theme.h"

namespace NSDEVICE
{

//*******************************************************************************
//*************************** GPS ***********************************************
//*******************************************************************************

LocationEventListener::LocationEventListener(Wrapper* vWrapper) :
    LocationListener(), w(vWrapper)
{
}

LocationEventListener::~LocationEventListener()
{
}

void LocationEventListener::onLocationChanged(Location* location)
{
    nfloat vLat = location->getLatitude()*M_PI_180;
    nfloat vLong = location->getLongitude()*M_PI_180;
    nint i = (w->mCoordBuffer->mHeadIndex + 3)%w->mCoordBuffer->mSize;
    nfloat* b = w->mCoordBuffer->maBuffer + i;
    b[2] = sin(vLat);
    vLat = cos(vLat);
    b[1] = vLat*sin(vLong);
    b[0] = vLat*cos(vLong);
    w->mCoordBuffer->mHeadIndex = i;
}

void LocationEventListener::onProviderDisabled(const String& provider)
{
}

void LocationEventListener::onProviderEnabled(const String& provider)
{
}

void LocationEventListener::onStatusChanged(const String& provider, int status, Bundle* extras)
{
}

//*******************************************************************************
//*************************** Rotation Vector ***********************************
//*******************************************************************************

nint OpUnitEvents::onRotation(nint fd, nint events, void* data)
{
    Wrapper* w = (Wrapper*)data;
    nint vcEvents = ASensorEventQueue_getEvents(w->mASensorEventQueue, w->maASensorEvent, 1) - 1;
    nint i = (w->mRotationBuffer->mHeadIndex + 4)%w->mRotationBuffer->mSize;
    nfloat* b = w->mRotationBuffer->maBuffer + i;
    b[0] = -w->maASensorEvent[vcEvents].vector.v[0];
    b[1] = -w->maASensorEvent[vcEvents].vector.v[1];
    b[2] = -w->maASensorEvent[vcEvents].vector.v[2];
    b[3] = sqrt(1.0 - b[0]*b[0] - b[1]*b[1] - b[2]*b[2]);
    w->mRotationBuffer->mHeadIndex = i;
    return 1;
}

OpUnitEvents::OpUnitEvents(Wrapper* const vWrapper)
    : OpUnit(vWrapper->mNWrapper), mAliveAR(false), mOutEvents(0), mOutFd(0), mLooper(nullptr), mOutData(nullptr), w(vWrapper)
{
}

OpUnitEvents::~OpUnitEvents()
{
}

void OpUnitEvents::cancel()
{
    if (mLooper) {
        mLooper->quitSafely();
    }
}

void OpUnitEvents::run()
{
    Looper::prepare();
    mLooper = Looper::myLooper();
    initLocationProvider();
    initRotationProvider();
    Looper::loop();

    while (mAliveAR) {
        this_thread::sleep_for(chrono::milliseconds(20));
    }
    killRotationProvider();
    killLocationProvider();
    delete mLooper;
    mLooper = nullptr;
}

void OpUnitEvents::initLocationProvider()
{
    nuint i;
    nuint j;
    Location* vDeviceLocation = nullptr;
    nfloat* vDeviceCoord = w->mCoordBuffer->maBuffer;
    vector<String> vaLocationProviderName = w->mLocationManager->getAllProviders();

    vDeviceCoord[0] = 0;
    vDeviceCoord[1] = 0;
    vDeviceCoord[2] = 1.0;

    w->maLocationProviderType = NArray<String>({LocationManager::GPS_PROVIDER, LocationManager::NETWORK_PROVIDER, LocationManager::PASSIVE_PROVIDER});
    w->maLocationProvider = NArray<LocationProvider*>(w->maLocationProviderType.mcData);
    w->maLocationListener = NArray<LocationListener*>({
        new LocationEventListener(w),
        new LocationEventListener(w),
        new LocationEventListener(w),
        new LocationEventListener(w)
    });
    for (j = 0 ; j < vaLocationProviderName.size() ; ++j) {
        for (i = 0 ; i < w->maLocationProviderType.mcData ; ++i) {
            if (vaLocationProviderName[j] == w->maLocationProviderType.maData[i]) {
                if (w->mLocationManager->isProviderEnabled(w->maLocationProviderType.maData[i])) {
                    w->maLocationProvider.maData[i] = w->mLocationManager->getProvider(w->maLocationProviderType.maData[i]);
                }
                break;
            }
        }
    }
    for (i = 0 ; i < w->maLocationProvider.mcData ; ++i) {
        if (w->maLocationProvider.maData[i] && !vDeviceLocation) {
            vDeviceLocation = w->mLocationManager->getLastKnownLocation(w->maLocationProviderType.maData[i]);

            if (vDeviceLocation) {
                nfloat vLat = vDeviceLocation->getLatitude()*M_PI_180;
                nfloat vLong = vDeviceLocation->getLongitude()*M_PI_180;
                vDeviceCoord[2] = sin(vLat);
                vLat = cos(vLat);
                vDeviceCoord[1] = vLat*sin(vLong);
                vDeviceCoord[0] = vLat*cos(vLong);
            }
        }
    }
    if (!vDeviceLocation) {
        LOGI(("Using North Pole (Lat, Long) " + to_string(86.45) + " " + to_string(-136.98)).c_str());
        ndouble vLat = 0.81200770380263454; //86.45/180.0*w->mcPi;
        ndouble vLong = 0.11564977728398008; //-136.98/180.0*w->mcPi;

        vDeviceCoord[0] = cos(vLat)*cos(vLong);
        vDeviceCoord[1] = cos(vLat)*sin(vLong);
        vDeviceCoord[2] = sin(vLat);
    }
    if (vDeviceLocation) {
        LOGI(("Using LastKnownLocation (Lat, Long) " + to_string(vDeviceLocation->getLatitude()) + " " + to_string(vDeviceLocation->getLongitude())).c_str());
        delete vDeviceLocation;
    }
    if (w->maLocationProvider.maData[2]) {
        w->mLocationManager->requestSingleUpdate(w->maLocationProviderType.maData[2], w->maLocationListener.maData[2], mLooper);
    }
    if (w->maLocationProvider.maData[1]) {
        w->mLocationManager->requestSingleUpdate(w->maLocationProviderType.maData[1], w->maLocationListener.maData[1], mLooper);
    }
    if (w->maLocationProvider.maData[0]) {
        w->mLocationManager->requestSingleUpdate(w->maLocationProviderType.maData[0], w->maLocationListener.maData[0], mLooper);
    }
}

void OpUnitEvents::initRotationProvider()
{
    nuint i;
    nuint j;
    ASensorList vaSensor;
    nuint vResult;

    w->maSensorType = NArray<nint>({Sensor::TYPE_ROTATION_VECTOR, Sensor::TYPE_MAGNETIC_FIELD, Sensor::TYPE_GRAVITY, Sensor::TYPE_ACCELEROMETER});
    w->maSensor = NArray<ASensorRef>(w->maSensorType.mcData);
    w->mALooper = ALooper_prepare(0);
    w->mASensorManager = ASensorManager_getInstance();
    w->mASensorEventQueue = ASensorManager_createEventQueue(w->mASensorManager, w->mALooper, 1, OpUnitEvents::onRotation, (void*)w);
    vResult = ASensorManager_getSensorList(w->mASensorManager, &vaSensor);

    for (j = 0 ; j < vResult ; ++j) {
        for (i = 0 ; i < w->maSensorType.mcData ; ++i) {
            if (ASensor_getType(vaSensor[j]) == w->maSensorType.maData[i]) {
                if (String(ASensor_getVendor(vaSensor[j])) == String("AOSP")) {
                    w->maSensor.maData[i] = vaSensor[j];
                }
                if (!w->maSensor.maData[i]) {
                    w->maSensor.maData[i] = vaSensor[j];
                }
                break;
            }
        }
    }
    if (w->mASensorEventQueue && w->maSensor.maData[0]) {
        j = ASensor_getMinDelay(w->maSensor.maData[0]);
        j = ASensorEventQueue_setEventRate(w->mASensorEventQueue, w->maSensor.maData[0], max(j, (nuint)50000));
    }
}

void OpUnitEvents::killLocationProvider()
{
    w->maLocationProvider.discard();
    w->maLocationProviderType.discard();
    w->maLocationListener.discard();
}

void OpUnitEvents::killRotationProvider()
{
    ASensorManager_destroyEventQueue(w->mASensorManager, w->mASensorEventQueue);
    w->maSensor.discard();
    w->maSensorType.discard();
}

void OpUnitEvents::startEventsProduction()
{
    mAliveAR = true;
    registerLocationListener();
    registerRotationListener();
}

void OpUnitEvents::stopEventsProduction()
{
    releaseLocationListener();
    releaseRotationListener();
    mAliveAR = false;
}

void OpUnitEvents::registerLocationListener()
{
    if (w->maLocationProvider.maData[0]) {
        w->mLocationManager->requestLocationUpdates(w->maLocationProviderType.maData[0], 500, 0.0, w->maLocationListener.maData[3], mLooper);
    }
}

void OpUnitEvents::registerRotationListener()
{
    nint vResult = 0;

    if (w->maSensor.mcData && w->maSensor.maData[0] && w->mASensorEventQueue) {
        vResult = ASensorEventQueue_enableSensor(w->mASensorEventQueue, w->maSensor.maData[0]);
    }
    if (vResult) {
        LOGE(("Sensor TYPE_ROTATION_VECTOR cannot be enabled" + to_string(vResult)).c_str());
    }
}

void OpUnitEvents::releaseLocationListener()
{
    w->mLocationManager->removeUpdates(w->maLocationListener.maData[3]);
}

void OpUnitEvents::releaseRotationListener()
{
    if (w->maSensor.mcData && w->maSensor.maData[0] && w->mASensorEventQueue) {
        ASensorEventQueue_disableSensor(w->mASensorEventQueue, w->maSensor.maData[0]);
    }
}

} // End namespace
