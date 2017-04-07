#include "Common.h"
#include "Theme.h"

namespace NSDEVICE
{

WidgetAR::WidgetAR(Wrapper* const w)
    : Widget(w), SurfaceHolder::Callback(), mcPadding((nint)(15*w->mcDensity)), mState(0), mSurfaceView(nullptr), mSurfaceHolder(nullptr)
{
    LinearLayout::LayoutParams vWidgetParams = LinearLayout::LayoutParams(LinearLayout::LayoutParams::MATCH_PARENT, LinearLayout::LayoutParams::MATCH_PARENT);
    setLayoutParams(&vWidgetParams);
    setGravity(Gravity::BOTTOM);
    setOrientation(LinearLayout::VERTICAL);
    setPadding(0, 0, 0, 0);
    setOnTouchListener(this);

    mEventManager = new EventManager(w);
    mSurfaceView = new SurfaceView(w->mApplication);
    mSurfaceHolder = mSurfaceView->getHolder();
    mSurfaceHolder->addCallback(this);
    addView(mSurfaceView);
}

WidgetAR::~WidgetAR()
{
    if (w->mSurface) {
        delete w->mSurface;
    }
    delete mSurfaceHolder;
    delete mSurfaceView;
}

void WidgetAR::init(nuint vcView, DBObject* vDBObject)
{
//    w->mMenu->setGroupVisible(k::ViewDelete, false);
//    w->mMenu->setGroupVisible(k::ViewEdit, false);
//    w->mMenu->setGroupVisible(k::ViewSave, false);
//    w->mMenu->setGroupVisible(k::ViewList, true);
//    w->mMenu->setGroupVisible(k::ViewAdd, true);

    w->mMenu->setGroupVisible(k::ViewDelete, false);
    w->mMenu->setGroupVisible(k::ViewEdit, false);
    w->mMenu->setGroupVisible(k::ViewSave, false);
    w->mMenu->setGroupVisible(k::ViewList, false);
    w->mMenu->setGroupVisible(k::ViewAdd, false);

    w->mActionBar->setDisplayHomeAsUpEnabled(true);
    w->mActionBar->setHomeButtonEnabled(false);
}

void WidgetAR::setState(nint vState)
{
    w->mARState = vState;
}

void WidgetAR::onCreate()
{
    LOGI("Creating AR");

    if (w->mARState < 2) {
        w->mARState = 2;
        w->mOpUnitAR->sendOp(w->mOpUnitARId, w->mNWrapper->mNKrossWrapper->mNAlpha00, new Op());
    }
    onResume();
}

void WidgetAR::onResume()
{
    LOGI("Resuming AR");
    w->mARState = 3;
}

void WidgetAR::onPause()
{
    LOGI("Pausing AR");
    w->mARState = 4;
}

void WidgetAR::onDestroy()
{
    LOGI("Destroying AR");
    w->mARState = 0;
}

void WidgetAR::surfaceChanged(SurfaceHolder* holder, int format, int width, int height)
{
    // This callback is called from the main Activity UI thread
    LOGI("surfaceChanged");
    w->mSurfaceWidth = width;
    w->mSurfaceHeight = height;
    //FIXME: delete w->mSurface
    w->mSurface = holder->getSurface();
    w->mARSurface = 2;
}

void WidgetAR::surfaceCreated(SurfaceHolder* holder)
{
    // This callback is called from the main Activity UI thread
    LOGI("surfaceCreated");
    w->mARSurface = 1;
}

void WidgetAR::surfaceDestroyed(SurfaceHolder* holder)
{
    // This callback is called from the main Activity UI thread
    LOGI("surfaceDestroyed");
    w->mARSurface = 0;
    onDestroy();
}

//*******************************************************************************************//
//*************************************** OnTouchListener ***********************************//
//*******************************************************************************************//
bool WidgetAR::onTouch(View* vView, MotionEvent* event)
{
    if (mEventManager->onMove(vView, event)) {
       w->mOpUnitAR->sendOp(w->mOpUnitARId, w->mNWrapper->mNKrossWrapper->mNBeta00, new OpParam(
            mEventManager->mT,
            mEventManager->mX,
            mEventManager->mY,
            mEventManager->mState
       ));
    }
    return true;
}

} // End namespace
