#ifndef __Wrapper_H__
#define __Wrapper_H__

namespace NSDEVICE
{

class Wrapper
{
public:
    static const int OPUNIT_TYPE_NONE = 0;
    static const int OPUNIT_TYPE_DEFAULT = OPUNIT_TYPE_NONE + 1;
    static const int OPUNIT_TYPE_PEER = OPUNIT_TYPE_DEFAULT + 1;
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

    static const int SWIPE_MAX_OFF_PATH = 250;
    static const int SWIPE_MIN_DISTANCE = 120;
    static const int SWIPE_THRESHOLD_VELOCITY = 250;

	NWrapper* w;

    Application* mApplication;
    NActivity* mNActivity;
    String sFileDir;
    DBHandler* dbh;

    TimeStamp mc10Secondes;
    std::string mac;
    std::string sServiceName;
    std::string sUuidService;
    std::string sUuidPeer;
    std::string sUuidSuffix;
    std::string sUuidMacSuffix;
	BluetoothAdapter* dBluetoothAdapter;

	nint cMaxOpUnit;
	OpSquad* opSquad;
	OpUnitCore* opUnitCore;
	OpUnitServer* opUnitServer;
	nint mOpUnitCoreId;

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

    nuint mcCategory;
	String* maCategory;

    bool* maCategorySelected;
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

    WidgetHome* mWidgetHome;

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
