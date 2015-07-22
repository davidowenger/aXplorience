#include "Common.h"

namespace NSDEVICE
{

FragmentViewHome::FragmentViewHome(Wrapper* const w)
    : FragmentView(w)
{
    setOrientation(LinearLayout::HORIZONTAL);
    setLayoutParams(new LinearLayout::LayoutParams(LinearLayout::LayoutParams::MATCH_PARENT, LinearLayout::LayoutParams::MATCH_PARENT));
    setPadding(0, 0, 0, 0);
    setOnTouchListener(w->mWidgetHome);

    maContent = new Widget*[2];

    if (w->mcWidthDp < 480) {
        maContent[0] = w->mWidgetHome;
        maContent[1] = nullptr;
    } else {
        maContent[0] = w->mWidgetHome;
        maContent[1] = new Widget(w);
    }
}

FragmentViewHome::~FragmentViewHome()
{
    if (maContent[0]) {
       delete maContent[0];
    }
    if (maContent[1]) {
       delete maContent[1];
    }
}

void FragmentViewHome::init(nuint vcView, Menu* menu, nuint vcDBObjectId)
{
    mcView = vcView;
    mcDBObjectId = vcDBObjectId;
    maContent[0]->init(vcView, vcDBObjectId);

    removeAllViews();

    if (w->mcMaxLevel == 0) {
        addView(maContent[0]);

        menu->removeItem(Wrapper::kViewAdd);
        menu->removeItem(Wrapper::kViewEdit);
        menu->removeItem(Wrapper::kViewDelete);
        menu->removeItem(Wrapper::kViewSave);

        MenuItem* vMenuItemAdd = menu->add(Menu::NONE, Wrapper::kViewAdd, 1, "Add");
        vMenuItemAdd->setIcon(w->maDrawable[10]);
        vMenuItemAdd->setShowAsAction(MenuItem::SHOW_AS_ACTION_IF_ROOM);

        w->mActionBar->setDisplayHomeAsUpEnabled(false);
        w->mActionBar->setHomeButtonEnabled(false);
    } else if (w->mcWidthDp >= 480 && w->mcView == 3) {
        addView(maContent[0]);
        addView(maContent[1]);
    }
}

bool FragmentViewHome::onInterceptTouchEvent(MotionEvent* ev)
{
    return w->maGestureDetector[w->mcView]->onTouchEvent(ev);
}

bool FragmentViewHome::onMenuItemSelected(nint id)
{
    bool ret = false;

    if (id == Wrapper::kViewAdd) {
        w->mNActivity->setView(Wrapper::kViewAdd, 1);
        w->mNActivity->sendOp(0, w->mOpUnitUIId, w->w->mNIota00, new OpParam(Wrapper::kViewAdd, 1));
        ret = true;
    }
    return ret;
}

//*******************************************************************************************
//************************************** OnGestureListener  *********************************
//*******************************************************************************************
bool FragmentViewHome::onDown(MotionEvent* e)
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

bool FragmentViewHome::onFling(MotionEvent* e1, MotionEvent* e2, float vVelocityX, float vVelocityY)
{
    w->mTouchState = 3;
    return true;
}

void FragmentViewHome::onLongPress(MotionEvent* e)
{
    w->mTouchState = 3;
    w->mEventAction();
}

bool FragmentViewHome::onScroll(MotionEvent* e1, MotionEvent* e2, float distanceX, float distanceY)
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
        w->mNActivity->setView(Wrapper::kViewSettings, 1);
    }
    return ret;
}

void FragmentViewHome::onShowPress(MotionEvent* e)
{
    w->mTouchState = 3;
}

bool FragmentViewHome::onSingleTapUp(MotionEvent* e)
{
    w->mTouchState = 3;
    w->mEventAction();
    return true;
}

} // End namespace
