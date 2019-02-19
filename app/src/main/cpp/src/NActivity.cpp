#include "Common.h"
#include "Theme.h"

namespace NSDEVICE
{

Activity* Activity::getInstance(NWrapper* vNWrapper)
{
    Wrapper* w = new Wrapper();
    w->mNWrapper = vNWrapper;
    vNWrapper->mDBWrapper = new DBWrapper();
    vNWrapper->mGraphicsWrapper = new GraphicsWrapper();
    vNWrapper->mOpWrapper = new OpWrapper();
    return new NActivity(w);
}

NActivity::NActivity(Wrapper* vWrapper)
    : Activity(), OpUnit(vWrapper->mNWrapper), mState(7), mResourcesState(0), w(vWrapper)
{
    mcUnitType = OpUnit::OPUNIT_TYPE_ACTIVITY;
}

NActivity::~NActivity()
{
}

void NActivity::onCreate(Bundle* savedInstanceState)
{
    nuint i;

    Activity::onCreate(savedInstanceState);

    w->mNActivity = this;
    w->mApplication = getApplication();
    w->mFragmentManager = getFragmentManager();
    w->mWindowManager = getWindowManager();
    w->mResources = w->mApplication->getResources();
    w->mConfiguration = w->mResources->getConfiguration();
    w->mDisplayMetrics = w->mResources->getDisplayMetrics();
    w->mDisplay = w->mWindowManager->getDefaultDisplay();
    w->mcDensity = w->mDisplayMetrics->getDensity();
    w->mcScreenWidthDp = w->mConfiguration->getScreenWidthDp();
    w->maColor = new nuint[25] {
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
    w->mcRootLayoutItem = 10;
    w->maRootLayoutItem = new RootLayoutItem[w->mcRootLayoutItem];
    w->maRootLayoutItem[Wrapper::kViewNone] =     {0, {{0,0,0,0}, {0,0,0,0}, {0,0,0,0}}};
    w->maRootLayoutItem[Wrapper::kViewHome] =     {0, {{0,0,2,1}, {0,0,0,0}, {0,0,0,0}}};
    w->maRootLayoutItem[Wrapper::kViewAbout] =    {1, {{0,0,1,1}, {1,1,2,2}, {0,0,0,0}}};
    w->maRootLayoutItem[Wrapper::kViewSettings] = {1, {{0,0,1,1}, {2,0,2,3}, {0,0,0,0}}};
    w->maRootLayoutItem[Wrapper::kViewDetails] =  {1, {{0,0,2,1}, {3,1,2,4}, {0,0,0,0}}};
    w->maRootLayoutItem[Wrapper::kViewEdit] =     {2, {{0,0,2,1}, {3,1,2,4}, {4,1,2,5}}};
    w->maRootLayoutItem[Wrapper::kViewAdd] =      {1, {{0,0,2,1}, {4,1,2,6}, {0,0,0,0}}};
    w->maRootLayoutItem[Wrapper::kViewDelete] =   {0, {{0,0,2,1}, {0,0,0,0}, {0,0,0,0}}};
    w->maRootLayoutItem[Wrapper::kViewSave] =     {1, {{0,0,2,1}, {3,1,2,8}, {0,0,0,0}}};
    w->maRootLayoutItem[Wrapper::kViewAR] =       {1, {{0,0,1,1}, {5,0,2,9}, {0,0,0,0}}};

    w->mRootLayoutId = 0x001FF100;
    w->mRootLayout = new RootLayout(w);
    w->mRootLayout->setId(w->mRootLayoutId);
    setContentView((View*)w->mRootLayout);

    w->maDrawable = new Drawable*[12] {
        w->mResources->getDrawable("ic_visibility_grey"),
        w->mResources->getDrawable("ic_visibility_green"),
        w->mResources->getDrawable("ic_visibility_black_48dp"),
        w->mResources->getDrawable("ic_left_black"),
        w->mResources->getDrawable("ic_left_green"),
        w->mResources->getDrawable("ic_right_black"),
        w->mResources->getDrawable("ic_right_green"),
        w->mResources->getDrawable("ic_action_edit"),
        w->mResources->getDrawable("ic_action_delete"),
        w->mResources->getDrawable("ic_action_save"),
        w->mResources->getDrawable("ic_action_add"),
        w->mResources->getDrawable("ic_launcher"),
    };
    w->mcTextSize = (int)(27/w->mcDensity);
    w->maMenu = new String[3] {
        "Home",
        "Settings",
        "About"
    };
    w->mcCategory = 4;
    w->maCategory = new String[w->mcCategory] {
        "Listen to Music",
        "Have a Drink",
        "Play some Game",
        "See some Event"
    };
    w->mcBTStateOption = 3;
    w->maBTStateOption = new String[w->mcBTStateOption] {
        "Bluetooth ENABLED and VISIBLE",
        "Bluetooth ENABLED",
        "Bluetooth OFF",
    };
    w->mARState = 1;
    w->mARSurface = 1;
    w->mActionBar = getActionBar();
    w->mActionBar->setIcon(w->maDrawable[11]);
    w->mSurfaceView = new SurfaceView(w->mApplication);
    w->mMessageLayout = new LinearLayout(w->mApplication);
    w->mWidgetHome = new WidgetHome(w);
    w->mWidgetMessageDetails = new WidgetMessageDetails(w);
    w->mWidgetMessageEdit = new WidgetMessageEdit(w);
    w->mWidgetSettings = new WidgetSettings(w);
    w->mWidgetAbout = new WidgetAbout(w);
    w->mWidgetAR = new WidgetAR(w);

    w->mcFragmentView = 6;
    w->maGestureDetector = new GestureDetector*[w->mcFragmentView];
    w->maFragmentView = new FragmentView*[w->mcFragmentView] {
        (w->mFragmentViewHome = new FragmentViewHome(w)),
        (w->mFragmentViewAbout = new FragmentViewAbout(w)),
        (w->mFragmentViewSettings = new FragmentViewSettings(w)),
        (w->mFragmentViewDetails = new FragmentViewDetails(w)),
        (w->mFragmentViewEdit = new FragmentViewEdit(w)),
        (w->mFragmentViewAR = new FragmentViewAR(w))
    };
    for (i = 0 ; i < w->mcFragmentView ; ++i) {
        w->maGestureDetector[i] = new GestureDetector(w->mApplication, w->maFragmentView[i]);
    };
    w->mcFragmentLevel = 3;
    w->maFragmentLevel = new FragmentLevel*[w->mcFragmentLevel] {
        (w->mFragmentLevel0 = new FragmentLevel0(w)),
        (w->mFragmentLevel1 = new FragmentLevel1(w)),
        (w->mFragmentLevel2 = new FragmentLevel2(w))
    };
    w->mMenu = nullptr;
    w->cMaxOpUnit = 18;

    w->opSquad = new OpSquad(w->mNWrapper, w->cMaxOpUnit);
    w->opSquad->add(this);
    w->mOpUnitAppId = mId;

    w->opUnitCore = new OpUnitCore(w);
    w->opSquad->add(w->opUnitCore);
    w->mOpUnitCoreId = w->opUnitCore->mId;

    w->opUnitUI = new OpUnitUI(w);
    w->opSquad->add(w->opUnitUI);
    w->mOpUnitUIId = w->opUnitUI->mId;

    w->opUnitServer = new OpUnitServer(w);
    w->opSquad->add(w->opUnitServer);
    w->mOpUnitServerId = w->opUnitServer->mId;

    w->mOpUnitEvents = new OpUnitEvents(w);
    w->opSquad->add(w->mOpUnitEvents);
    w->mOpUnitEventsId = w->mOpUnitEvents->mId;

    w->mOpUnitAnim = new OpUnitAnim(w);
    w->opSquad->add(w->mOpUnitAnim);
    w->mOpUnitAnimId = w->mOpUnitAnim->mId;

    w->opUnitCore->start();
}

void NActivity::onResume()
{
    sendOp(w->mOpUnitUIId, w->mNWrapper->mNKrossWrapper->mNBeta00, new Op());
    Activity::onResume();
}

void NActivity::onPause()
{
    // Commit fragment transactions before activity state is saved
    setView(0, nullptr);
    Activity::onPause();
}

void NActivity::onStop()
{
    // Stop animations
    setResources(0);
    Activity::onStop();
}

void NActivity::onDestroy()
{
    nint i;

    // Stop all threads
    delete w->opSquad;

    w->mRootLayout->removeAllViews();

    i = 12;
    while (--i >= 0) {
        delete w->maDrawable[i];
    }
    i = 5;
    while (--i >= 0) {
        delete w->maFragmentView[i];
    }
    i = 5;
    while (--i >= 0) {
        delete w->maGestureDetector[i];
    }
    i = 3;
    while (--i >= 0) {
        delete w->maFragmentLevel[i];
    }
    for (WidgetMessage* vWidgetMessage : w->maWidgetMessageSorted) {
        delete vWidgetMessage;
    }
    if (w->mMenu) {
        delete w->mMenu;
    }
    delete[] w->maDrawable;
    delete[] w->maColor;
    delete[] w->maRootLayoutItem;
    delete[] w->maMenu;
    delete[] w->maCategory;
    delete[] w->maFragmentView;
    delete[] w->maGestureDetector;
    delete[] w->maFragmentLevel;

    delete w->mRootLayout;
    delete w->mActionBar;
    delete w->mApplication;
    delete w->mDisplayMetrics;
    delete w->mResources;
    delete w->mConfiguration;
    delete w->mMessageLayout;
    delete w->mWidgetHome;
    delete w->mWidgetMessageDetails;
    delete w->mWidgetMessageEdit;
    delete w->mWidgetSettings;
    delete w->mWidgetAbout;
    delete w->mWidgetAR;

    delete w->mFragmentManager;

    delete w;

    Activity::onDestroy();
}

void NActivity::addWidget()
{
    WidgetMessage* vWidgetMessage = new WidgetMessage(w);
    w->maWidgetMessageSorted.push_front(vWidgetMessage);
    w->mMessageLayout->addView(vWidgetMessage, 0);
}

void NActivity::handleMessage(NParam m)
{
    //LOGE("NActivity::handleMessage");
    nRun(((Op*)m)->mNElement, ((Op*)m)->a, ((Op*)m)->b, ((Op*)m)->c, ((Op*)m)->d, ((Op*)m)->e);
    delete (Op*)m;
}

void NActivity::onReceiveDiscoveryFinished()
{
    sendOp(w->mOpUnitCoreId, w->mNWrapper->mNKrossWrapper->mNAlpha00, new OpParam());
}

void NActivity::onReceiveFoundDevice(BluetoothDevice* dBluetoothDevice)
{
    sendOp(w->mOpUnitCoreId, w->mNWrapper->mNKrossWrapper->mNBeta00, new OpParam((NParam)dBluetoothDevice));
}

void NActivity::removeWidget(nuint vcDBObjectId)
{
    nuint vcIndex = 0;
    list<WidgetMessage*>::iterator vIt = w->maWidgetMessageSorted.begin();

    while (vIt != w->maWidgetMessageSorted.end()) {
        if ((*vIt)->mcDBObjectId == vcDBObjectId) {
            w->mMessageLayout->removeViewAt(vcIndex);
            delete (WidgetMessage*)(*vIt);
            vIt = w->maWidgetMessageSorted.erase(vIt);
        } else {
            ++vIt;
            ++vcIndex;
        }
    }
    w->maWidgetMessage.erase(vcDBObjectId);
}

void NActivity::renderHeader()
{
    w->mWidgetHome->initHeader();
}

void NActivity::setResources(nint vcState)
{
    if (mResourcesState == 0) {
        if (vcState == 1) {
            w->mWidgetAR->onCreate();
            mResourcesState = 1;
        }
    }
    if (mResourcesState == 1) {
        if (vcState == 2) {
            w->mWidgetAR->onPause();
            mResourcesState = 2;
        }
        if (vcState == 0) {
            w->mWidgetAR->onPause();
            w->mWidgetAR->onDestroy();
            mResourcesState = 0;
        }
    }
    if (mResourcesState == 2) {
        if (vcState == 1) {
            w->mWidgetAR->onCreate();
            mResourcesState = 1;
        }
        if (vcState == 0) {
            w->mWidgetAR->onDestroy();
            mResourcesState = 0;
        }
    }
}

void NActivity::setView(nint vcView, DBObject* vDBObject)
{
    nuint i;
    setResources(2 - 1*(vcView == Wrapper::kViewAR));

    for (i = 0 ; i < w->mcFragmentLevel ; ++i) {
        w->maFragmentLevel[i]->init(vcView, vDBObject);
    }
    if (vDBObject) {
        delete vDBObject;
    }
}

void NActivity::sort(DBCollection* vDBCollection)
{
    DBObject* vDBObject;
    WidgetMessage* vWidgetMessageNew;

    nint vcIndex = w->maWidgetMessageSorted.size();
    nint vcDBCollectionSize = vDBCollection->count();

    while (vcIndex > vcDBCollectionSize) {
        w->mMessageLayout->removeViewAt(--vcIndex);
        delete w->maWidgetMessageSorted.back();
        w->maWidgetMessageSorted.pop_back();
    }
    while (vcIndex < vcDBCollectionSize) {
        vWidgetMessageNew = new WidgetMessage(w);
        w->maWidgetMessageSorted.push_front(vWidgetMessageNew);
        w->mMessageLayout->addView(vWidgetMessageNew,0);
        ++vcIndex;
    }
    vcIndex = -1;

    for (WidgetMessage* vWidgetMessage : w->maWidgetMessageSorted) {
        vDBObject = vDBCollection->get(++vcIndex);
        vWidgetMessage->update(vDBObject);
        w->maWidgetMessage[vDBObject->mId] = vWidgetMessage;
    }
    delete vDBCollection;
}

void NActivity::tilt(nuint color)
{
    w->mRootLayout->setBackgroundColor(color);
    w->mRootLayout->invalidate();
    mState = color;
}

void NActivity::update(DBObject* vDBObject, nint vcView)
{
    map<nuint,WidgetMessage*>::iterator vIt;

    if (vcView == Wrapper::kViewNone && (vIt = w->maWidgetMessage.find(vDBObject->mId)) != w->maWidgetMessage.end()) {
        vIt->second->update(vDBObject);
    }
    if (vcView == Wrapper::kViewDetails || vcView == Wrapper::kViewSave) {
        w->mWidgetMessageDetails->update(vDBObject);
    }
    if (vcView == Wrapper::kViewEdit || vcView == Wrapper::kViewAdd) {
        w->mWidgetMessageEdit->update(vDBObject);
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
    w->mWidgetSettings->init();
    return 0;
}

} // End namespace
