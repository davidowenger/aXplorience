#ifndef __Wrapper_H__
#define __Wrapper_H__

namespace NSDEVICE
{

namespace k
{
    const nfloat Pi = 3.14159265358979323846f;
    const nfloat PiOn2 = Pi/2.0f;
    const nfloat PiOn4 = Pi/4.0f;
    const nfloat PiOn6 = Pi/6.0f;
    const nfloat PiOn180 = Pi/180.0f;
    const nfloat MaxFloat = std::numeric_limits<nfloat>::max();

    const ndouble PiLong = 3.141592653589793238462643383279502884L;
    const ndouble PiOn180Long = PiLong/180.0L;

    const nint ViewNone = 0;
    const nint ViewAR = ViewNone + 1;
    const nint ViewAbout = ViewAR + 1;
    const nint ViewSettings = ViewAbout + 1;
    const nint ViewList = ViewSettings + 1;
    const nint ViewDetails = ViewList + 1;
    const nint ViewEdit = ViewDetails + 1;
    const nint ViewAdd = ViewEdit + 1;
    const nint ViewSave = ViewAdd + 1;
    const nint ViewDelete = ViewSave + 1;

    const nint POICount = 30;
    const nint LineCount = 4;
    const nfloat MinGroupSpace = 0.2f;

    const nint SWIPE_MAX_OFF_PATH = 250;
    const nint SWIPE_MIN_DISTANCE = 100;
    const nint SWIPE_THRESHOLD_VELOCITY = 250;
}

class Wrapper
{
public:
    NWrapper* mNWrapper;

    Application* mApplication;
    NActivity* mNActivity;
    DBHandler* mhDB;
    TimeStamp mc1Seconde;
    system_clock::duration mMili;

    std::string mac;
    std::string sServiceName;
    std::string sUuidService;
    BluetoothAdapter* dBluetoothAdapter;
    nint mcConnected;

    nint cMaxOpUnit;
    OpSquad* opSquad;
    OpUnitCore* opUnitCore;
    OpUnitDB* opUnitDB;
    OpUnitServer* opUnitServer;
    OpUnitEvents* mOpUnitEvents;
    OpUnitAnim* mOpUnitAnim;
    OpUnitAR* mOpUnitAR;
    nint mOpUnitEventsId;
    nint mOpUnitServerId;
    nint mOpUnitAppId;
    nint mOpUnitCoreId;
    nint mOpUnitDBId;
    nint mOpUnitAnimId;
    nint mOpUnitARId;
    list<Sort> maSort;

    nuint mcBTStateChange;
    nuint mcBTState;
    nuint mIsInterrupted;
    nuint mcInterrupt;
    String** mWriteBase;
    nint mcWriteIndex;
    nint mcWriteIndexMax;
    NConcurrentCircularBuffer<String*>* maMessageAlive;
    NConcurrentCircularBuffer<String*>* maMessageBuzz;
    NConcurrentCircularBuffer<String*>* maMessageUpdate;
    map<nuint,WidgetMessage*> maWidgetMessage;
    list<WidgetMessage*> maWidgetMessageSorted;

    BOMessageHandler* mBOMessageHandler;
    DBObject* mDBObjectApplication;
    DBObject* mDBObjectSeedEdit;

    WindowManager* mWindowManager;
    Display* mDisplay;
    FragmentManager* mFragmentManager;
    Resources* mResources;
    DisplayMetrics* mDisplayMetrics;
    Configuration* mConfiguration;

    nfloat mcDensity;
    nint mcScreenWidthDp;
    nint mcDeviceOrientation;
    nint mcDisplayRotation;
    nint mcTextSize;

    String* maMenu;
    String* maMenuItem;
    nuint mTouchState;
    EventAction mEventAction;
    nlong mEventLong0;
    nlong mEventLong1;
    String mEventString0;

    nuint mcCategory;
    String* maCategory;

    nuint mcBTStateOption;
    String* maBTStateOption;

    nuint* maColor;
    Drawable** maDrawable;

    ActionBar* mActionBar;
    nint mcRootLayoutItem;
    RootLayoutItem* maRootLayoutItem;
    RootLayout* mRootLayout;
    nuint mRootLayoutId;
    LinearLayout* mMessageLayout;
    nuint mcView;
    nuint mcMaxLevel;
    Menu* mMenu;
    MenuItem* mMenuItemList;
    MenuItem* mMenuItemAdd;
    MenuItem* mMenuItemEdit;
    MenuItem* mMenuItemDelete;
    MenuItem* mMenuItemSave;

    NArray<Widget*> maWidget;
    WidgetAR* mWidgetAR;
    WidgetAbout* mWidgetAbout;
    WidgetSettings* mWidgetSettings;
    WidgetMessageList* mWidgetMessageList;
    WidgetMessageDetails* mWidgetMessageDetails;
    WidgetMessageEdit* mWidgetMessageEdit;

    GraphicsHandler* mGraphicsHandler;
    Surface* mSurface;
    nint mSurfaceWidth;
    nint mSurfaceHeight;
    nuint mARState;
    nuint mARSurface;
    AREngine* mAREngine;
    nuint mAREventState;
    nuint mAREventIndex;
    nfloat mAREventX;
    nfloat mAREventY;

    LocationManager* mLocationManager;
    NArray<String> maLocationProviderType;
    NArray<LocationProvider*> maLocationProvider;
    NArray<LocationListener*> maLocationListener;
    map<nuint,BOPOI*> maPOIStatic;
    map<nuint,BOPOI*> maPOIDynamic;
    NSortList<BOPOI*,nfloat> maPOISorted;
    NConcurrentCircularBuffer<nfloat>* mCoordBuffer;
    NConcurrentCircularBuffer<nfloat>* mRotationBuffer;

    SurfaceTexture* mTexturePreview;
    Camera* mCamera;
    NArray<Camera::CameraInfo> maCameraInfo;
    NArray<nint> maCameraId;
    nfloat mcCameraFocalLength;
    nfloat mcCameraHorizontalAngle;
    nfloat mcCameraVerticalAngle;
    nfloat mcCameraAspectRatio;
    nint mcCameraMountOrientation;

    Looper* mLooper;
    ALooper* mALooper;
    NArray<nint> maSensorType;
    NArray<ASensorRef> maSensor;
    ASensorManager* mASensorManager;
    ASensorEventQueue* mASensorEventQueue;
    ASensorEvent maASensorEvent[8];
};

} // End namespace

#endif
