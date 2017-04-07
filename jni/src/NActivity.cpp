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

NActivity::NActivity(Wrapper* vWrapper) :
    Activity(), OpUnit(vWrapper->mNWrapper), mLevel(0), mView(0), w(vWrapper)
{
    mcUnitType = OpUnit::OPUNIT_TYPE_ACTIVITY;
}

NActivity::~NActivity()
{
}

void NActivity::onCreate(Bundle* savedInstanceState)
{
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
    w->mRootLayout = new RootLayout(w);
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
    w->mMenu = nullptr;
    w->mActionBar = getActionBar();
    w->mActionBar->setIcon(w->maDrawable[11]);

    w->mARState = 0;
    w->mARSurface = 0;
    w->mMessageLayout = new LinearLayout(w->mApplication);
    w->maWidget = NArray<Widget*>({
        nullptr,
        (w->mWidgetAR = new WidgetAR(w)),
        (w->mWidgetAbout = new WidgetAbout(w)), //(w->mWidgetAbout = new WidgetAbout(w)),
        (w->mWidgetSettings = new WidgetSettings(w)),
        (w->mWidgetMessageList = new WidgetMessageList(w)), //(w->mWidgetMessageList = new WidgetMessageList(w)),
        (w->mWidgetMessageDetails = new WidgetMessageDetails(w)),
        (w->mWidgetMessageEdit = new WidgetMessageEdit(w))
    });

    w->mLocationManager = (LocationManager*)w->mNActivity->getSystemService(Context::LOCATION_SERVICE);
    w->mGraphicsHandler = new GraphicsHandler(w->mNWrapper);
    w->mCoordBuffer = new NConcurrentCircularBuffer<nfloat>(24);
    w->mRotationBuffer = new NConcurrentCircularBuffer<nfloat>(32);

    w->cMaxOpUnit = 18;
    w->opSquad = new OpSquad(w->mNWrapper, w->cMaxOpUnit);
    w->opSquad->add(this);
    w->mOpUnitAppId = mId;

    w->opUnitCore = new OpUnitCore(w);
    w->opSquad->add(w->opUnitCore);
    w->mOpUnitCoreId = w->opUnitCore->mId;

    w->opUnitDB = new OpUnitDB(w);
    w->opSquad->add(w->opUnitDB);
    w->mOpUnitDBId = w->opUnitDB->mId;

    w->opUnitServer = new OpUnitServer(w);
    w->opSquad->add(w->opUnitServer);
    w->mOpUnitServerId = w->opUnitServer->mId;

    w->mOpUnitEvents = new OpUnitEvents(w);
    w->opSquad->add(w->mOpUnitEvents);
    w->mOpUnitEventsId = w->mOpUnitEvents->mId;

    w->mOpUnitAnim = new OpUnitAnim(w);
    w->opSquad->add(w->mOpUnitAnim);
    w->mOpUnitAnimId = w->mOpUnitAnim->mId;

    w->mOpUnitAR = new OpUnitAR(w);
    w->opSquad->add(w->mOpUnitAR);
    w->mOpUnitARId = w->mOpUnitAR->mId;

    w->opUnitCore->start();
}

void NActivity::onStart()
{
    w->mWidgetAR->setState(1);
    Activity::onStart();
}

void NActivity::onResume()
{
    if (w->mMenu) {
        sendOp(w->mOpUnitDBId, w->mNWrapper->mNKrossWrapper->mNGamma00, new Op());
    }
    w->mWidgetAR->setState(2);
    Activity::onResume();
}

void NActivity::onPause()
{
    w->mWidgetAR->setState(3);
    Activity::onPause();
}

void NActivity::onStop()
{
    // Stop animations
    w->mWidgetAR->setState(0);
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
    for (WidgetMessage* vWidgetMessage : w->maWidgetMessageSorted) {
        delete vWidgetMessage;
    }
    if (w->mMenu) {
        w->mMenu->removeItem(k::ViewDelete);
        w->mMenu->removeItem(k::ViewEdit);
        w->mMenu->removeItem(k::ViewSave);
        w->mMenu->removeItem(k::ViewList);
        w->mMenu->removeItem(k::ViewAdd);

        delete w->mMenuItemDelete;
        delete w->mMenuItemEdit;
        delete w->mMenuItemSave;
        delete w->mMenuItemList;
        delete w->mMenuItemAdd;
        delete w->mMenu;
    }
    delete[] w->maDrawable;
    delete[] w->maColor;
    delete[] w->maRootLayoutItem;
    delete[] w->maMenu;
    delete[] w->maCategory;

    delete w->mRootLayout;
    delete w->mActionBar;
    delete w->mApplication;
    delete w->mDisplayMetrics;
    delete w->mResources;
    delete w->mConfiguration;
    delete w->mMessageLayout;
    delete w->mWidgetMessageList;
    delete w->mWidgetMessageDetails;
    delete w->mWidgetMessageEdit;
    delete w->mWidgetSettings;
    delete w->mWidgetAbout;
    delete w->mWidgetAR;

    delete w->mFragmentManager;

    delete w;

    Activity::onDestroy();
}

void NActivity::appSetView(nint vcView, DBObject* vDBObject)
{
    mView = vcView;
    mDBObjectId = ( vDBObject ? vDBObject->mId : 0 );
    w->maWidget[vcView]->init(vcView, vDBObject);

    if (mLevel == 0) {
        mLevel = 1;
        w->mRootLayout->addView(w->maWidget[k::ViewAR], 0);
    }
    if (mLevel == 2) {
        mLevel = 1;
        w->mRootLayout->removeViewAt(1);
    }
    if (vcView != k::ViewAR) {
        mLevel = 2;
        w->mRootLayout->addView(w->maWidget[vcView], 1);
    }
}

void NActivity::handleMessage(long long int m)
{
    //LOGE("NActivity::handleMessage");
    nRun(((Op*)m)->mNElement, ((Op*)m)->a, ((Op*)m)->b, ((Op*)m)->c, ((Op*)m)->d, ((Op*)m)->e);
    delete (Op*)m;
}

void NActivity::onBackPressed()
{
        onReceiveOption(R::id::home);
//    if (mLevel == 2) {
//        onReceiveOption(R::id::home);
//    } else {
//        Activity::onBackPressed();
//    }
}

bool NActivity::onCreateOptionsMenu(Menu* vMenu)
{
    w->mMenu = vMenu;
    w->mMenuItemDelete = w->mMenu->add(k::ViewDelete, k::ViewDelete, 1, "Delete");
    w->mMenuItemDelete->setIcon(w->maDrawable[8]);
    w->mMenuItemDelete->setShowAsAction(MenuItem::SHOW_AS_ACTION_IF_ROOM);

    w->mMenuItemEdit = w->mMenu->add(k::ViewEdit, k::ViewEdit, 2, "Edit");
    w->mMenuItemEdit->setIcon(w->maDrawable[7]);
    w->mMenuItemEdit->setShowAsAction(MenuItem::SHOW_AS_ACTION_IF_ROOM);

    w->mMenuItemSave = w->mMenu->add(k::ViewSave, k::ViewSave, 3, "Save");
    w->mMenuItemSave->setIcon(w->maDrawable[9]);
    w->mMenuItemSave->setShowAsAction(MenuItem::SHOW_AS_ACTION_IF_ROOM);

    w->mMenuItemList = w->mMenu->add(k::ViewList, k::ViewList, 4, "List");
    w->mMenuItemList->setIcon(w->maDrawable[5]);
    w->mMenuItemList->setShowAsAction(MenuItem::SHOW_AS_ACTION_IF_ROOM);

    w->mMenuItemAdd = w->mMenu->add(k::ViewAdd, k::ViewAdd, 5, "Add");
    w->mMenuItemAdd->setIcon(w->maDrawable[10]);
    w->mMenuItemAdd->setShowAsAction(MenuItem::SHOW_AS_ACTION_IF_ROOM);

    sendOp(w->mOpUnitDBId, w->mNWrapper->mNKrossWrapper->mNGamma00, new Op());
    Activity::onCreateOptionsMenu(vMenu);
    return true;
}

bool NActivity::onOptionsItemSelected(MenuItem* vMenuItem)
{
    return onReceiveOption(vMenuItem->getItemId());
}

void NActivity::onReceiveDiscoveryFinished()
{
    sendOp(w->mOpUnitCoreId, w->mNWrapper->mNKrossWrapper->mNAlpha00, new OpParam());
}

void NActivity::onReceiveFoundDevice(BluetoothDevice* dBluetoothDevice)
{
    sendOp(w->mOpUnitCoreId, w->mNWrapper->mNKrossWrapper->mNBeta00, new OpParam((NParam)dBluetoothDevice));
}

bool NActivity::onReceiveOption(nint vMenuItemId)
{
    bool vRet = false;

    if (vMenuItemId == R::id::home) {
        if (mView == k::ViewEdit && mDBObjectId != 1) {
            sendOp(w->mOpUnitDBId, w->mNWrapper->mNKrossWrapper->mNBeta00, new OpParam(k::ViewDetails, mDBObjectId));
        } else if (mView == k::ViewList) {
            sendOp(w->mOpUnitDBId, w->mNWrapper->mNKrossWrapper->mNBeta00, new OpParam(k::ViewAR, 0));
        } else if (mView == k::ViewAbout) {
            sendOp(w->mOpUnitDBId, w->mNWrapper->mNKrossWrapper->mNBeta00, new OpParam(k::ViewAR, 0));
        } else {
            sendOp(w->mOpUnitDBId, w->mNWrapper->mNKrossWrapper->mNBeta00, new OpParam(k::ViewAbout, 0));
            //sendOp(w->mOpUnitDBId, w->mNWrapper->mNKrossWrapper->mNLambda00, new Op());
        }
        vRet = true;
    }
    if (vMenuItemId == k::ViewList) {
        sendOp(w->mOpUnitDBId, w->mNWrapper->mNKrossWrapper->mNLambda00, new Op());
        vRet = true;
    }
    if (vMenuItemId == k::ViewDelete) {
        sendOp(w->mOpUnitDBId, w->mNWrapper->mNKrossWrapper->mNTheta00, new OpParam(mDBObjectId, 1));
        vRet = true;
    }
    if (vMenuItemId == k::ViewEdit) {
        sendOp(w->mOpUnitDBId, w->mNWrapper->mNKrossWrapper->mNBeta00, new OpParam(k::ViewEdit, mDBObjectId));
        vRet = true;
    }
    if (vMenuItemId == k::ViewSave) {
        if (mDBObjectId == 1) {
            sendOp(w->mOpUnitDBId, w->mNWrapper->mNKrossWrapper->mNEta00, new OpMessage(
                to_string(w->mWidgetMessageEdit->mCategory->getSelectedItemPosition()),
                w->mWidgetMessageEdit->mTitle->getText(),
                w->mWidgetMessageEdit->mText->getText(),
                w->mWidgetMessageEdit->mLink->getText()
            ));
        } else {
            sendOp(w->mOpUnitDBId, w->mNWrapper->mNKrossWrapper->mNIota00, new OpMessage(
                to_string(mDBObjectId),
                to_string(w->mWidgetMessageEdit->mCategory->getSelectedItemPosition()),
                w->mWidgetMessageEdit->mTitle->getText(),
                w->mWidgetMessageEdit->mText->getText(),
                w->mWidgetMessageEdit->mLink->getText()
            ));
        }
        vRet = true;
    }
    if (vMenuItemId == k::ViewAdd) {
        sendOp(w->mOpUnitDBId, w->mNWrapper->mNKrossWrapper->mNBeta00, new OpParam(k::ViewEdit, 1));
        vRet = true;
    }
    return vRet;
}

void NActivity::poiList(DBCollection* vDBCollection)
{
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
        vWidgetMessage->update(vDBCollection->get(++vcIndex));
    }
}

void NActivity::poiSort(DBCollection* vDBCollection)
{
    poiList(vDBCollection);
    w->mWidgetMessageList->initHeader();
}

void NActivity::settingsFeed()
{
    w->mWidgetSettings->init();
}

NReturn NActivity::visit(NAlpha00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    appSetView((nint)a, (DBObject*)b);
    if (b) delete (DBObject*)b;
    return 0;
}

NReturn NActivity::visit(NBeta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    poiList((DBCollection*)a);
    delete (DBCollection*)a;
    return 0;
}

NReturn NActivity::visit(NGamma00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    poiSort((DBCollection*)a);
    delete (DBCollection*)a;
    return 0;
}

NReturn NActivity::visit(NEpsilon00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    settingsFeed();
    return 0;
}

} // End namespace
