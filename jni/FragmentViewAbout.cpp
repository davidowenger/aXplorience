#include "Common.h"

namespace NSDEVICE
{

FragmentViewAbout::FragmentViewAbout(Wrapper* const w)
    : FragmentView(w)
{
    setOrientation(LinearLayout::HORIZONTAL);
    setLayoutParams(new LinearLayout::LayoutParams(LinearLayout::LayoutParams::MATCH_PARENT, LinearLayout::LayoutParams::MATCH_PARENT));
    setPadding(0, 0, 0, 0);

    maContent = new Widget*[2];

    if (w->mcWidthDp < 480) {
        maContent[0] = new WidgetAbout(w);
        maContent[1] = nullptr;
        addView(maContent[0]);
    } else {
        maContent[0] = new WidgetAbout(w);
        maContent[1] = new Widget(w);
        addView(maContent[0]);
    }
}

FragmentViewAbout::~FragmentViewAbout()
{
    if (maContent[0]) {
       delete maContent[0];
    }
    if (maContent[1]) {
       delete maContent[1];
    }
    delete maContent;
}

void FragmentViewAbout::init(nuint vcView, Menu* menu, nuint vcDBObjectId)
{
    mTouchState = 0;
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

bool FragmentViewAbout::onInterceptTouchEvent(MotionEvent* ev)
{
    return w->maGestureDetector[w->mcView]->onTouchEvent(ev);
}

bool FragmentViewAbout::onMenuItemSelected(nint id)
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
bool FragmentViewAbout::onDown(MotionEvent* e)
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

bool FragmentViewAbout::onFling(MotionEvent* e1, MotionEvent* e2, float vVelocityX, float vVelocityY)
{
    w->mTouchState = 3;
    return true;
}

void FragmentViewAbout::onLongPress(MotionEvent* e)
{
    w->mTouchState = 3;
    w->mEventAction();
}

bool FragmentViewAbout::onScroll(MotionEvent* e1, MotionEvent* e2, float distanceX, float distanceY)
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
        w->mNActivity->setView(Wrapper::kViewHome, 1);
    }
    return ret;
}

void FragmentViewAbout::onShowPress(MotionEvent* e)
{
    w->mTouchState = 3;
}

bool FragmentViewAbout::onSingleTapUp(MotionEvent* e)
{
    w->mTouchState = 3;
    w->mEventAction();
    return true;
}

} // End namespace
