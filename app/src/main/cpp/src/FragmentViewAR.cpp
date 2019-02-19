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

    addView(w->mWidgetAR);
}

FragmentViewAR::~FragmentViewAR()
{
}

void FragmentViewAR::init(nuint vcView, DBObject* vDBObject)
{
    mcView = vcView;

    if (w->mMenu) {
        w->mWidgetAR->init();

        w->mMenu->removeItem(Wrapper::kViewAdd);
        w->mMenu->removeItem(Wrapper::kViewEdit);
        w->mMenu->removeItem(Wrapper::kViewDelete);
        w->mMenu->removeItem(Wrapper::kViewSave);

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
        w->mNActivity->sendOp(w->mOpUnitUIId, w->mNWrapper->mNKrossWrapper->mNIota00, new OpParam(Wrapper::kViewHome, 0));
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
        w->mEventAction = [](Wrapper* w)->void{};
        LOGV("NEW EVENT");
        mX = e->getX();
        mY = e->getY();
        mT = e->getEventTime();
    }
    return false;
}

bool FragmentViewAR::onFling(MotionEvent* e1, MotionEvent* e2, float vVelocityX, float vVelocityY)
{
    w->mTouchState = ( w->mTouchState == 2 ? 3 : 0 );
    return true;
}

void FragmentViewAR::onLongPress(MotionEvent* e)
{
    w->mTouchState = ( w->mTouchState == 2 ? 3 : 0 );
    w->mEventAction(w);
}

bool FragmentViewAR::onScroll(MotionEvent* e1, MotionEvent* e2, float distanceX, float distanceY)
{
    nfloat vX = e2->getX() - mX;
    nfloat vY = e2->getY() - mY;
    nfloat vD = (e2->getEventTime() - mT)/1000.0;
    bool ret = abs(vX) > Wrapper::SWIPE_MIN_DISTANCE && abs(vY) < Wrapper::SWIPE_MAX_OFF_PATH && abs(vX/vD) > Wrapper::SWIPE_THRESHOLD_VELOCITY;
    w->mTouchState = ( w->mTouchState == 2 ? 3 : 0 );

    LOGV(("Duration : #" + to_string(vD)).c_str());
    LOGV(("Distance X: #" + to_string(vX) + " Y: #" + to_string(vY)).c_str());
    LOGV(("Velocity X: #" + to_string(vX/vD) + " Y: #" + to_string(vY/vD)).c_str());

    if (ret) {
        if (vX > 0) {
            w->mNActivity->sendOp(w->mOpUnitUIId, w->mNWrapper->mNKrossWrapper->mNIota00, new OpParam(Wrapper::kViewAbout, 1));
        } else {
            w->mNActivity->sendOp(w->mOpUnitUIId, w->mNWrapper->mNKrossWrapper->mNIota00, new OpParam(Wrapper::kViewSettings, 1));
        }
    }
    return ret;
}

void FragmentViewAR::onShowPress(MotionEvent* e)
{
    w->mTouchState = ( w->mTouchState == 2 ? 3 : 0 );
}

bool FragmentViewAR::onSingleTapUp(MotionEvent* e)
{
    w->mTouchState = ( w->mTouchState == 2 ? 3 : 0 );
    w->mEventAction(w);
    return true;
}

} // End namespace
