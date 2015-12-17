#include "Common.h"
#include "Theme.h"

namespace NSDEVICE
{

WidgetAR::WidgetAR(Wrapper* const w)
    : Widget(w), SurfaceHolder::Callback(), mcPadding((nint)(15*w->mcDensity))
{
    LinearLayout::LayoutParams vWidgetParams = LinearLayout::LayoutParams(0, LinearLayout::LayoutParams::MATCH_PARENT, 1);
    setLayoutParams(&vWidgetParams);
    setGravity(Gravity::TOP);
    setOrientation(LinearLayout::HORIZONTAL);
    setPadding(0, 0, 0, 0);
    setOnTouchListener(this);

    mSurfaceHolder = w->mSurfaceView->getHolder();
    mSurfaceHolder->addCallback(this);
    addView(w->mSurfaceView);
}

WidgetAR::~WidgetAR()
{
    if (w->mSurface) {
        delete w->mSurface;
    }
    delete mSurfaceHolder;
}

void WidgetAR::init()
{
}

void WidgetAR::onCreate()
{
    LOGI("Creating AR");

    if (w->mARState < 2) {
        w->mARState = 2;
        w->mOpUnitAnim->sendOp(w->mOpUnitAnimId, w->mNWrapper->mNKrossWrapper->mNBeta00, new Op());
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

    if (w->mARSurface) {
        w->mARState = 4;
    } else {
        w->mARState = 0;
    }
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
//**************************************  OnTouchListener  **********************************//
//*******************************************************************************************//
bool WidgetAR::onTouch(View* vView, MotionEvent* event)
{
    if (w->mTouchState == 3) {
        w->mTouchState = 0;
    }
    return true;
}

} // End namespace
