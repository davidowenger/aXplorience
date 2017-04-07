#include "Common.h"

namespace NSDEVICE
{

FragmentViewAR::FragmentViewAR(Wrapper* const w)
    : FragmentView(w)
{
    mWidget = new Widget(w);

    setOrientation(LinearLayout::HORIZONTAL);
    setLayoutParams(new LinearLayout::LayoutParams(LinearLayout::LayoutParams::MATCH_PARENT, LinearLayout::LayoutParams::MATCH_PARENT));
    setPadding(0, 0, 0, 0);

    //addView(w->mWidgetAR);
}

FragmentViewAR::~FragmentViewAR()
{
}

void FragmentViewAR::init(nuint vcView, DBObject* vDBObject)
{
    mcView = vcView;

    if (w->mMenu) {
        w->maGestureDetector[w->mcView]->setIsLongpressEnabled(false);

        w->mMenu->removeItem(k::ViewAdd);
        w->mMenu->removeItem(k::ViewEdit);
        w->mMenu->removeItem(k::ViewDelete);
        w->mMenu->removeItem(k::ViewSave);

        w->mActionBar->setDisplayHomeAsUpEnabled(true);
        w->mActionBar->setHomeButtonEnabled(true);
    }
}

bool FragmentViewAR::onInterceptTouchEvent(MotionEvent* ev)
{
    return w->maGestureDetector[w->mcView]->onTouchEvent(ev);
}

bool FragmentViewAR::onMenuItemSelected(nint id)
{
    bool ret = false;

    if (id == R::id::home) {
        w->mNActivity->sendOp(w->mOpUnitDBId, w->mNWrapper->mNKrossWrapper->mNIota00, new OpParam(k::ViewAR, 0));
        ret = true;
    }
    return ret;
}

//*******************************************************************************************
//************************************** OnGestureListener  *********************************
//*******************************************************************************************
bool FragmentViewAR::onDown(MotionEvent* e)
{
    if (w->mTouchState == 0) {
        w->mTouchState = 1;
        w->mAREventState = 1;
        mX = e->getX();
        mY = e->getY();
    }
    return false;
}

bool FragmentViewAR::onFling(MotionEvent* e1, MotionEvent* e2, float vVelocityX, float vVelocityY)
{
    w->mAREventX = 0.5f*mX + 0.5f*e2->getX();
    w->mAREventY = 0.5f*mY + 0.5f*e2->getY();
    ++w->mAREventIndex;
    w->mTouchState = 2;
    return true;
}

void FragmentViewAR::onLongPress(MotionEvent* e)
{
}

bool FragmentViewAR::onScroll(MotionEvent* e1, MotionEvent* e2, float distanceX, float distanceY)
{
    w->mAREventX = 0.5f*mX + 0.5f*e2->getX();
    w->mAREventY = 0.5f*mY + 0.5f*e2->getY();
    ++w->mAREventIndex;
    return false;
}

void FragmentViewAR::onShowPress(MotionEvent* e)
{
}

bool FragmentViewAR::onSingleTapUp(MotionEvent* e)
{
    w->mAREventX = e->getX();
    w->mAREventY = e->getY();
    ++w->mAREventIndex;
    w->mTouchState = 2;
    return true;
}

} // End namespace
