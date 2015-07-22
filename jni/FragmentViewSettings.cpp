#include "Common.h"

namespace NSDEVICE
{

FragmentViewSettings::FragmentViewSettings(Wrapper* const w)
    : FragmentView(w)
{
    setOrientation(LinearLayout::HORIZONTAL);
    setLayoutParams(new LinearLayout::LayoutParams(LinearLayout::LayoutParams::MATCH_PARENT, LinearLayout::LayoutParams::MATCH_PARENT));
    setPadding(0, 0, 0, 0);

    maContent = new Widget*[1];
    maContent[0] = new WidgetSettings(w);
    addView(maContent[0]);
}

FragmentViewSettings::~FragmentViewSettings()
{
    if (maContent[0]) {
       delete maContent[0];
    }
    delete maContent;
}

void FragmentViewSettings::init(nuint vcView, Menu* menu, nuint vcDBObjectId)
{
    mcView = vcView;
    mcDBObjectId = vcDBObjectId;
    maContent[0]->init(vcView, vcDBObjectId);

    if (w->mcMaxLevel == 1) {
        menu->removeItem(Wrapper::kViewAdd);
        menu->removeItem(Wrapper::kViewEdit);
        menu->removeItem(Wrapper::kViewDelete);
        menu->removeItem(Wrapper::kViewSave);

        w->mActionBar->setDisplayHomeAsUpEnabled(true);
        w->mActionBar->setHomeButtonEnabled(true);
    }
}

bool FragmentViewSettings::onInterceptTouchEvent(MotionEvent* ev)
{
    return w->maGestureDetector[w->mcView]->onTouchEvent(ev);
}

bool FragmentViewSettings::onMenuItemSelected(nint id)
{
    bool ret = false;

    if (id == R::id::home) {
        w->mNActivity->setView(Wrapper::kViewHome, 0);
        w->mNActivity->sendOp(0, w->mOpUnitUIId, w->w->mNIota00, new OpParam(Wrapper::kViewHome));
        ret = true;
    }
    return ret;
}

//*******************************************************************************************
//************************************** OnGestureListener  *********************************
//*******************************************************************************************
bool FragmentViewSettings::onDown(MotionEvent* e)
{
    if (w->mTouchState == 0) {
        w->mTouchState = 1;
        w->mEventAction = function<void()>([]()->void{});
        LOGV("NEW EVENT");
        mX = e->getX();
        mY = e->getY();
        mT = e->getEventTime();
    }
    return false;
}

bool FragmentViewSettings::onFling(MotionEvent* e1, MotionEvent* e2, float vVelocityX, float vVelocityY)
{
    w->mTouchState = 3;
    return true;
}

void FragmentViewSettings::onLongPress(MotionEvent* e)
{
    w->mTouchState = 3;
    w->mEventAction();
}

bool FragmentViewSettings::onScroll(MotionEvent* e1, MotionEvent* e2, float distanceX, float distanceY)
{
    nfloat vX = e2->getX() - mX;
    nfloat vY = e2->getY() - mY;
    nfloat vD = (e2->getEventTime() - mT)/1000.0;
    bool ret = abs(vX) > Wrapper::SWIPE_MIN_DISTANCE && abs(vY) < Wrapper::SWIPE_MAX_OFF_PATH && abs(vX/vD) > Wrapper::SWIPE_THRESHOLD_VELOCITY;
    w->mTouchState = 3;

    LOGV(("Duration : #" + to_string(vD)).c_str());
    LOGV(("Distance X: #" + to_string(vX) + " Y: #" + to_string(vY)).c_str());
    LOGV(("Velocity X: #" + to_string(vX/vD) + " Y: #" + to_string(vY/vD)).c_str());

    if (ret) {
        w->mNActivity->setView(Wrapper::kViewAbout, 1);
    }
    return ret;
}

void FragmentViewSettings::onShowPress(MotionEvent* e)
{
}

bool FragmentViewSettings::onSingleTapUp(MotionEvent* e)
{
    w->mTouchState = 3;
    w->mEventAction();
    return true;
}

} // End namespace
