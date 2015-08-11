#include "Common.h"
#include "Theme.h"

namespace NSDEVICE
{

Activity* Activity::getInstance(NWrapper* const vNWrapper)
{
    Wrapper* vWrapper = new Wrapper();
    vWrapper->w = vNWrapper;
    return new NActivity(vWrapper);
}

NActivity::NActivity(Wrapper* vWrapper)
    : Activity(), OpUnit(vWrapper), mState(7)
{
    mcUnitType = Wrapper::OPUNIT_TYPE_ACTIVITY;
}

NActivity::~NActivity()
{
}

void NActivity::onCreate(Bundle* savedInstanceState)
{
    nuint i;

    Activity::onCreate(savedInstanceState);

    mWrapper->mNActivity = this;
    mWrapper->mApplication = getApplication();
    mWrapper->mFragmentManager = getFragmentManager();
    mWrapper->mResources = mWrapper->mApplication->getResources();
    mWrapper->mDisplayMetrics = mWrapper->mResources->getDisplayMetrics();
    mWrapper->mConfiguration = mWrapper->mResources->getConfiguration();
    mWrapper->mcDensity = mWrapper->mDisplayMetrics->getDensity();
    mWrapper->mcWidthDp = mWrapper->mConfiguration->getScreenWidthDp();
    mWrapper->maColor = new nuint[25] {
        0x00FFFFFF, //transparent
        0xFF000000, //black
        0xFFFFFFFF, //white
        0xFFE8E8E8, //grey 1
        0x75E8E8E8, //grey 2
        0x50E8E8E8, //grey
        0xFFFFE4E4, //red 1
        0xFFFFCACA, //red 2
        0xFFCC0000, //red
        0xFFF0F8DB, //green 1
        0xFFE2F0B6, //green 2 // 10
        0xFF669900, //green
        0xFFE2F4FB, //blue 1
        0xFFC5EAF8, //blue 2
        0xFF0099CC, //blue
        0xFFFFF6DF, //yellow 1
        0xFFFFECC0, //yellow 2
        0xFFFF8A00, //yellow
        0xFFF5EAFA, //purple 1
        0xFFE5CAF2, //purple 2
        0xFF9933CC, //purple  // 20
        0xFFFFEED5, //orange 1
        0xFFFF8F76, //orange 2
        0xFFFF4E00, //orange
        0xFF99CC00, //green selected
    };
    mWrapper->mcRootLayoutItem = 9;
    mWrapper->maRootLayoutItem = new RootLayoutItem[mWrapper->mcRootLayoutItem];
    mWrapper->maRootLayoutItem[Wrapper::kViewNone] =     {0, {{0,0,0,0}, {0,0,0,0}, {0,0,0,0}}};
    mWrapper->maRootLayoutItem[Wrapper::kViewHome] =     {0, {{0,0,2,1}, {0,0,0,0}, {0,0,0,0}}};
    mWrapper->maRootLayoutItem[Wrapper::kViewAbout] =    {1, {{0,0,1,1}, {1,1,2,2}, {0,0,0,0}}};
    mWrapper->maRootLayoutItem[Wrapper::kViewSettings] = {1, {{0,0,1,1}, {2,0,2,3}, {0,0,0,0}}};
    mWrapper->maRootLayoutItem[Wrapper::kViewDetails] =  {1, {{0,0,2,1}, {3,1,2,4}, {0,0,0,0}}};
    mWrapper->maRootLayoutItem[Wrapper::kViewEdit] =     {2, {{0,0,2,1}, {3,1,2,4}, {4,1,2,5}}};
    mWrapper->maRootLayoutItem[Wrapper::kViewAdd] =      {1, {{0,0,2,1}, {4,1,2,6}, {0,0,0,0}}};
    mWrapper->maRootLayoutItem[Wrapper::kViewDelete] =   {0, {{0,0,2,1}, {0,0,0,0}, {0,0,0,0}}};
    mWrapper->maRootLayoutItem[Wrapper::kViewSave] =     {1, {{0,0,2,1}, {3,1,2,8}, {0,0,0,0}}};

    mWrapper->mRootLayoutId = 0x001FF100;
    mWrapper->mRootLayout = new RootLayout(mWrapper);
    mWrapper->mRootLayout->setId(mWrapper->mRootLayoutId);
    setContentView((View*)mWrapper->mRootLayout);

    //todo
    mWrapper->sFileDir = mWrapper->w->nFrame->tGetString(mWrapper->w->nFrame->tRunObject(1));

    mWrapper->maDrawable = new Drawable*[12] {
        mWrapper->mResources->getDrawable("ic_visibility_grey"),
        mWrapper->mResources->getDrawable("ic_visibility_green"),
        mWrapper->mResources->getDrawable("ic_visibility_black_48dp"),
        mWrapper->mResources->getDrawable("ic_left_black"),
        mWrapper->mResources->getDrawable("ic_left_green"),
        mWrapper->mResources->getDrawable("ic_right_black"),
        mWrapper->mResources->getDrawable("ic_right_green"),
        mWrapper->mResources->getDrawable("ic_action_edit"),
        mWrapper->mResources->getDrawable("ic_action_delete"),
        mWrapper->mResources->getDrawable("ic_action_save"),
        mWrapper->mResources->getDrawable("ic_action_add"),
        mWrapper->mResources->getDrawable("ic_launcher"),
    };
    mWrapper->mcTextSize = (int)(27/mWrapper->mcDensity);
    mWrapper->maMenu = new String[3] {
        "Home",
        "Settings",
        "About"
    };
    mWrapper->mcCategory = 4;
    mWrapper->maCategory = new String[mWrapper->mcCategory] {
        "Listen to Music",
        "Have a Drink",
        "Play some Game",
        "See some Event"
    };
    mWrapper->mcBTStateOption = 3;
    mWrapper->maBTStateOption = new String[mWrapper->mcBTStateOption] {
        "Bluetooth ENABLED and VISIBLE",
        "Bluetooth ENABLED",
        "Bluetooth OFF",
    };
    mWrapper->mActionBar = getActionBar();
    mWrapper->mActionBar->setIcon(mWrapper->maDrawable[11]);
    mWrapper->mMessageLayout = new LinearLayout(mWrapper->mApplication);
    mWrapper->mWidgetHome = new WidgetHome(mWrapper);
    mWrapper->mWidgetMessageDetails = new WidgetMessageDetails(mWrapper);
    mWrapper->mWidgetMessageEdit = new WidgetMessageEdit(mWrapper);
    mWrapper->mWidgetSettings = new WidgetSettings(mWrapper);
    mWrapper->mWidgetAbout = new WidgetAbout(mWrapper);

    mWrapper->mcFragmentView = 5;
    mWrapper->maGestureDetector = new GestureDetector*[mWrapper->mcFragmentView];
    mWrapper->maFragmentView = new FragmentView*[mWrapper->mcFragmentView] {
        (mWrapper->mFragmentViewHome = new FragmentViewHome(mWrapper)),
        (mWrapper->mFragmentViewAbout = new FragmentViewAbout(mWrapper)),
        (mWrapper->mFragmentViewSettings = new FragmentViewSettings(mWrapper)),
        (mWrapper->mFragmentViewDetails = new FragmentViewDetails(mWrapper)),
        (mWrapper->mFragmentViewEdit = new FragmentViewEdit(mWrapper))
    };
    for (i = 0 ; i < mWrapper->mcFragmentView ; ++i) {
        mWrapper->maGestureDetector[i] = new GestureDetector(mWrapper->mApplication, mWrapper->maFragmentView[i]);
    };
    mWrapper->mcFragmentLevel = 3;
    mWrapper->maFragmentLevel = new FragmentLevel*[mWrapper->mcFragmentLevel] {
        (mWrapper->mFragmentLevel0 = new FragmentLevel0(mWrapper)),
        (mWrapper->mFragmentLevel1 = new FragmentLevel1(mWrapper)),
        (mWrapper->mFragmentLevel2 = new FragmentLevel2(mWrapper))
    };
    mWrapper->mMenu = nullptr;
    mWrapper->cMaxOpUnit = 18;

    mWrapper->opSquad = new OpSquad(mWrapper, mWrapper->cMaxOpUnit);
    mWrapper->opSquad->add(this);
    mWrapper->mOpUnitAppId = mId;

    mWrapper->opUnitCore = new OpUnitCore(mWrapper);
    mWrapper->opSquad->add(mWrapper->opUnitCore);
    mWrapper->mOpUnitCoreId = mWrapper->opUnitCore->mId;

    mWrapper->opUnitUI = new OpUnitUI(mWrapper);
    mWrapper->opSquad->add(mWrapper->opUnitUI);
    mWrapper->mOpUnitUIId = mWrapper->opUnitUI->mId;

    mWrapper->opUnitServer = new OpUnitServer(mWrapper);
    mWrapper->opSquad->add(mWrapper->opUnitServer);
    mWrapper->mOpUnitServerId = mWrapper->opUnitServer->mId;

    mWrapper->mOpUnitAnim = new OpUnitAnim(mWrapper);
    mWrapper->opSquad->add(mWrapper->mOpUnitAnim);
    mWrapper->mOpUnitAnimId = mWrapper->mOpUnitAnim->mId;

    mWrapper->opUnitCore->start();
}

void NActivity::onResume()
{
    sendOp(mWrapper->mOpUnitUIId, w->mNBeta00, new Op());
    Activity::onResume();
}

void NActivity::onPause()
{
    // Commit fragment transactions before activity state is saved
    setView(0, nullptr);
    Activity::onPause();
}

void NActivity::onDestroy()
{
    nint i;

    // Stop all threads
    delete mWrapper->opSquad;

    mWrapper->mRootLayout->removeAllViews();

    i = 12;
    while (--i >= 0) {
        delete mWrapper->maDrawable[i];
    }
    i = 5;
    while (--i >= 0) {
        delete mWrapper->maFragmentView[i];
    }
    i = 5;
    while (--i >= 0) {
        delete mWrapper->maGestureDetector[i];
    }
    i = 3;
    while (--i >= 0) {
        delete mWrapper->maFragmentLevel[i];
    }
    for (WidgetMessage* vWidgetMessage : mWrapper->maWidgetMessageSorted) {
        delete vWidgetMessage;
    }
    if (mWrapper->mMenu) {
        delete mWrapper->mMenu;
    }
    delete[] mWrapper->maDrawable;
    delete[] mWrapper->maColor;
    delete[] mWrapper->maRootLayoutItem;
    delete[] mWrapper->maMenu;
    delete[] mWrapper->maCategory;
    delete[] mWrapper->maFragmentView;
    delete[] mWrapper->maGestureDetector;
    delete[] mWrapper->maFragmentLevel;

    delete mWrapper->mRootLayout;
    delete mWrapper->mActionBar;
    delete mWrapper->mApplication;
    delete mWrapper->mDisplayMetrics;
    delete mWrapper->mResources;
    delete mWrapper->mConfiguration;
    delete mWrapper->mMessageLayout;
    delete mWrapper->mWidgetHome;
    delete mWrapper->mWidgetMessageDetails;
    delete mWrapper->mWidgetMessageEdit;
    delete mWrapper->mWidgetSettings;
    delete mWrapper->mWidgetAbout;
    delete mWrapper->mFragmentManager;

    delete mWrapper;

    Activity::onDestroy();
}

void NActivity::addWidget()
{
    WidgetMessage* vWidgetMessage = new WidgetMessage(mWrapper);
    mWrapper->maWidgetMessageSorted.push_front(vWidgetMessage);
    mWrapper->mMessageLayout->addView(vWidgetMessage, 0);
}

void NActivity::handleMessage(long long int m)
{
    //LOGE("NActivity::handleMessage");
    nRun(((Op*)m)->mNElement, ((Op*)m)->a, ((Op*)m)->b, ((Op*)m)->c, ((Op*)m)->d, ((Op*)m)->e);
    delete (Op*)m;
}

void NActivity::onReceiveDiscoveryFinished()
{
    sendOp(mWrapper->mOpUnitCoreId, mWrapper->w->mNAlpha00, new OpParam());
}

void NActivity::onReceiveFoundDevice(BluetoothDevice* dBluetoothDevice)
{
    sendOp(mWrapper->mOpUnitCoreId, mWrapper->w->mNBeta00, new OpParam((NParam)dBluetoothDevice));
}

void NActivity::removeWidget(nuint vcDBObjectId)
{
    nuint vcIndex = 0;
    list<WidgetMessage*>::iterator vIt = mWrapper->maWidgetMessageSorted.begin();

    while (vIt != mWrapper->maWidgetMessageSorted.end()) {
        if ((*vIt)->mcDBObjectId == vcDBObjectId) {
            mWrapper->mMessageLayout->removeViewAt(vcIndex);
            delete (WidgetMessage*)(*vIt);
            vIt = mWrapper->maWidgetMessageSorted.erase(vIt);
        } else {
            ++vIt;
            ++vcIndex;
        }
    }
    mWrapper->maWidgetMessage.erase(vcDBObjectId);
}

void NActivity::renderHeader()
{
    mWrapper->mWidgetHome->initHeader();
}

void NActivity::setView(nint vcView, DBObject* vDBObject)
{
    nuint i;

    for (i = 0 ; i < mWrapper->mcFragmentLevel ; ++i) {
        mWrapper->maFragmentLevel[i]->init(vcView, vDBObject);
    }
    if (vDBObject) {
        delete vDBObject;
    }
}

void NActivity::sort(DBCollection* vDBCollection)
{
    DBObject* vDBObject;
    WidgetMessage* vWidgetMessageNew;

    nint vcIndex = mWrapper->maWidgetMessageSorted.size();
    nint vcDBCollectionSize = vDBCollection->count();

    while (vcIndex > vcDBCollectionSize) {
        mWrapper->mMessageLayout->removeViewAt(--vcIndex);
        delete mWrapper->maWidgetMessageSorted.back();
        mWrapper->maWidgetMessageSorted.pop_back();
    }
    while (vcIndex < vcDBCollectionSize) {
        vWidgetMessageNew = new WidgetMessage(mWrapper);
        mWrapper->maWidgetMessageSorted.push_front(vWidgetMessageNew);
        mWrapper->mMessageLayout->addView(vWidgetMessageNew,0);
        ++vcIndex;
    }
    vcIndex = -1;

    for (WidgetMessage* vWidgetMessage : mWrapper->maWidgetMessageSorted) {
        vDBObject = vDBCollection->get(++vcIndex);
        vWidgetMessage->update(vDBObject);
        mWrapper->maWidgetMessage[vDBObject->mId] = vWidgetMessage;
    }
    delete vDBCollection;
}

void NActivity::tilt(nuint color)
{
    mWrapper->mRootLayout->setBackgroundColor(color);
    mWrapper->mRootLayout->invalidate();
    mState = color;
}

void NActivity::update(DBObject* vDBObject, nint vcView)
{
    map<nuint,WidgetMessage*>::iterator vIt;

    if (vcView == Wrapper::kViewNone && (vIt = mWrapper->maWidgetMessage.find(vDBObject->mId)) != mWrapper->maWidgetMessage.end()) {
        vIt->second->update(vDBObject);
    }
    if (vcView == Wrapper::kViewDetails || vcView == Wrapper::kViewSave) {
        mWrapper->mWidgetMessageDetails->update(vDBObject);
    }
    if (vcView == Wrapper::kViewEdit || vcView == Wrapper::kViewAdd) {
        mWrapper->mWidgetMessageEdit->update(vDBObject);
    }
    delete vDBObject;
}

NReturn NActivity::visit(NAlpha01* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    addWidget();
    return 0;
}

NReturn NActivity::visit(NBeta01* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    removeWidget((nuint)a);
    return 0;
}

NReturn NActivity::visit(NGamma01* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    sort((DBCollection*)a);
    return 0;
}

NReturn NActivity::visit(NDelta01* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    setView((nint)a, (DBObject*)b);
    return 0;
}

NReturn NActivity::visit(NEpsilon01* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    tilt((nuint)a);
    return 0;
}

NReturn NActivity::visit(NDzeta01* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    renderHeader();
    return 0;
}

NReturn NActivity::visit(NEta01* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    update((DBObject*)a, (nint)b);
    return 0;
}

NReturn NActivity::visit(NTheta01* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    mWrapper->mWidgetSettings->init();
    return 0;
}

} // End namespace

namespace std
{

long long int to_long(const string& vsLong, int* vcError)
{
    long long int vcRet = 0;
    istringstream vistringstream(vsLong);
    vistringstream >> vcRet;
#ifdef DEBUG
    int vcErrorInternal = vsLong.empty() || vistringstream.fail();

    if (vcError) {
        *vcError = vcErrorInternal;
    }
    if (vcErrorInternal) {
        vcRet = 0;
    }
#endif
    return vcRet;
}

vector<string> split(const string& str, const string& delimiter)
{
    //FIXME: UTF8 compatibility
    int i = 0;
    int j = 0;
    const char* sString = str.c_str();
    int cString = str.size();
    int cDelimiter = delimiter.size();
    vector<string> result;
    string token("");
    string current("");

    while (i < cString && cDelimiter) {
        current = "";

        for ( j = i ; j < cString && j < i + cDelimiter ; ++j ) {
            current += sString[j];
        }
        if (current == delimiter) {
            result.push_back(token);
            token = "";
            i += cDelimiter;
        } else {
            token += sString[i];
            i += 1;
        }
    }
    result.push_back(token);
    return result;
}

int utf8len(const string& vString)
{
    int ret = 0;
    const char* c = vString.c_str();
    while (*c) ret += (*c++ & 0xc0) != 0x80;
    return ret;
}

} // End namespace
