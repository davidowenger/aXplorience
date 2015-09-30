#ifndef __Wrapper_H__
#define __Wrapper_H__

namespace NSDEVICE
{

class Wrapper
{
public:
    static const int OPUNIT_TYPE_NONE = 0;
    static const int OPUNIT_TYPE_DEFAULT = OPUNIT_TYPE_NONE + 1;
    static const int OPUNIT_TYPE_ACTIVITY = OPUNIT_TYPE_DEFAULT + 1;
    static const int OPUNIT_TYPE_PEER = OPUNIT_TYPE_ACTIVITY + 1;
    static const int OPUNIT_TYPE_LISTENER = OPUNIT_TYPE_PEER + 1;

    static const int kViewNone = 0;
    static const int kViewHome = 1;
    static const int kViewAbout = 2;
    static const int kViewSettings = 3;
    static const int kViewDetails = 4;
    static const int kViewEdit = 5;
    static const int kViewAdd = 6;
    static const int kViewDelete = 7;
    static const int kViewSave = 8;
    static const int kViewEnable = kViewSave + 1;
    static const int kViewBuzz = kViewEnable + 1;

    static const int SWIPE_MAX_OFF_PATH = 250;
    static const int SWIPE_MIN_DISTANCE = 100;
    static const int SWIPE_THRESHOLD_VELOCITY = 250;

    NWrapper* w;

    Application* mApplication;
    NActivity* mNActivity;
    String sFileDir;
    DBHandler* dbh;

    TimeStamp mc1Seconde;
    system_clock::duration mMili;

    std::string mac;
    std::string sServiceName;
    std::string sUuidService;
    std::string mServiceApplicationId;
    std::string mServiceGattId;
    std::string mServiceGenericAccessId;
    std::string mCharacteristicServiceChangedId;
    std::string mCharacteristicDeviceNameId;
    std::string mCharacteristicAppearanceId;
    std::string mDescriptorCCCDId;
    BluetoothManager* mBluetoothManager;
    BluetoothAdapter* dBluetoothAdapter;
    NetworkAdvertiseCallback* mNetworkAdvertiseCallback;
    BluetoothLeAdvertiser* mBluetoothLeAdvertiser;
    BluetoothGattServer* mBluetoothGattServer;
    BluetoothGattService* mBluetoothGattService;
    BluetoothGattCharacteristic* mBluetoothGattCharacteristic;
    NetworkServerCallback* mNetworkServerCallback;
    NetworkScanCallback* mNetworkScanCallback;
    mutex mMutex;
    condition_variable mConditionCharacteristicWrite;
    condition_variable mConditionNotificationSent;
    condition_variable mConditionServicesAdded;
    condition_variable mConditionServicesDiscovered;
    condition_variable mConditionStateChange;
    nuint mNetworkState;
    nuint mcDiscoveryDone;
    unordered_set<BluetoothDevice*> maBluetoothDevice;
    nuint mcRunningInitializations;

    nint cMaxOpUnit;
    OpSquad* opSquad;
    OpUnitCore* opUnitCore;
    OpUnitNetwork* mOpUnitNetwork;
    OpUnitUI* opUnitUI;
    OpUnitServer* opUnitServer;
    OpUnitAnim* mOpUnitAnim;
    nint mOpUnitServerId;
    nint mOpUnitAppId;
    nint mOpUnitCoreId;
    nint mOpUnitNetworkId;
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
    ConcurrentCircularBuffer<String*>* maMessageAlive;
    ConcurrentCircularBuffer<String*>* maMessageBuzz;
    ConcurrentCircularBuffer<String*>* maMessageUpdate;
    map<nuint,WidgetMessage*> maWidgetMessage;
    list<WidgetMessage*> maWidgetMessageSorted;

    BOHandlerMessage* mBOHandlerMessage;
    DBObject* mDBObjectApplication;
    DBObject* mDBObjectSeedEdit;

    FragmentManager* mFragmentManager;
    Resources* mResources;
    DisplayMetrics* mDisplayMetrics;
    Configuration* mConfiguration;

    nfloat mcDensity;
    nint mcWidthDp;
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

    nuint mcFragmentView;
    FragmentView** maFragmentView;
    GestureDetector** maGestureDetector;
    FragmentViewHome* mFragmentViewHome;
    FragmentViewSettings* mFragmentViewSettings;
    FragmentViewAbout* mFragmentViewAbout;
    FragmentViewDetails* mFragmentViewDetails;
    FragmentViewEdit* mFragmentViewEdit;

    nuint mcFragmentLevel;
    FragmentLevel** maFragmentLevel;
    FragmentLevel0* mFragmentLevel0;
    FragmentLevel1* mFragmentLevel1;
    FragmentLevel2* mFragmentLevel2;
};

} // End namespace

#endif
