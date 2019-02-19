#ifndef __Wrapper_H__
#define __Wrapper_H__

namespace NSDEVICE
{

class Wrapper
{
public:
    static const int kViewNone = 0;
    static const int kViewHome = 1;
    static const int kViewAbout = 2;
    static const int kViewSettings = 3;
    static const int kViewDetails = 4;
    static const int kViewEdit = 5;
    static const int kViewAdd = 6;
    static const int kViewDelete = 7;
    static const int kViewSave = 8;
    static const int kViewAR = kViewSave + 1;
    static const int kViewEnable = kViewAR + 1;
    static const int kViewBuzz = kViewEnable + 1;

    static const int SWIPE_MAX_OFF_PATH = 250;
    static const int SWIPE_MIN_DISTANCE = 100;
    static const int SWIPE_THRESHOLD_VELOCITY = 250;

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

    nint cMaxOpUnit;
    OpSquad* opSquad;
    OpUnitCore* opUnitCore;
    OpUnitUI* opUnitUI;
    OpUnitServer* opUnitServer;
    OpUnitEvents* mOpUnitEvents;
    OpUnitAnim* mOpUnitAnim;
    nint mOpUnitEventsId;
    nint mOpUnitServerId;
    nint mOpUnitAppId;
    nint mOpUnitCoreId;
    nint mOpUnitUIId;
    nint mOpUnitAnimId;
    nint mcConnected;
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

    BOHandlerMessage* mBOHandlerMessage;
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

    WidgetHome* mWidgetHome;
    WidgetMessageDetails* mWidgetMessageDetails;
    WidgetMessageEdit* mWidgetMessageEdit;
    WidgetSettings* mWidgetSettings;
    WidgetAbout* mWidgetAbout;
    WidgetAR* mWidgetAR;

    nuint mcFragmentView;
    FragmentView** maFragmentView;
    GestureDetector** maGestureDetector;
    FragmentViewHome* mFragmentViewHome;
    FragmentViewSettings* mFragmentViewSettings;
    FragmentViewAbout* mFragmentViewAbout;
    FragmentViewDetails* mFragmentViewDetails;
    FragmentViewEdit* mFragmentViewEdit;
    FragmentViewAR* mFragmentViewAR;

    nuint mcFragmentLevel;
    FragmentLevel** maFragmentLevel;
    FragmentLevel0* mFragmentLevel0;
    FragmentLevel1* mFragmentLevel1;
    FragmentLevel2* mFragmentLevel2;

    GraphicsHandler* mGraphicsHandler;
    SurfaceView* mSurfaceView;
    Surface* mSurface;
    nint mSurfaceWidth;
    nint mSurfaceHeight;
    nuint mARState;
    nuint mARSurface;
    AREngine* mAREngine;

    LocationManager* mLocationManager;
    NArray<String> maLocationProviderType;
    NArray<LocationProvider*> maLocationProvider;
    NArray<LocationListener*> maLocationListener;
    NArray<BOPOI*> maPOI;
    NSortList<BOPOI,nfloat>* mPOISortList;
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
