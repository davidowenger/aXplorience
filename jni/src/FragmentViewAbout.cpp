#include "Common.h"

namespace NSDEVICE
{

FragmentViewAbout::FragmentViewAbout(Wrapper* const w)
    : FragmentView(w)
{
    mWidget = new Widget(w);

    setOrientation(LinearLayout::HORIZONTAL);
    setLayoutParams(new LinearLayout::LayoutParams(LinearLayout::LayoutParams::MATCH_PARENT, LinearLayout::LayoutParams::MATCH_PARENT));
    setPadding(0, 0, 0, 0);

    addView(w->mWidgetAbout);
}

FragmentViewAbout::~FragmentViewAbout()
{
}

void FragmentViewAbout::init(nuint vcView, DBObject* vDBObject)
{
    mcView = vcView;

    if (w->mMenu) {
        w->mMenu->removeItem(k::ViewAdd);
        w->mMenu->removeItem(k::ViewEdit);
        w->mMenu->removeItem(k::ViewDelete);
        w->mMenu->removeItem(k::ViewSave);

        MenuItem* vMenuItemAdd = w->mMenu->add(Menu::NONE, k::ViewAdd, 1, "Add");
        vMenuItemAdd->setIcon(w->maDrawable[10]);
        vMenuItemAdd->setShowAsAction(MenuItem::SHOW_AS_ACTION_IF_ROOM);
        delete vMenuItemAdd;

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
        w->mNActivity->sendOp(w->mOpUnitDBId, w->mNWrapper->mNKrossWrapper->mNIota00, new OpParam(k::ViewAR, 0));
        ret = true;
    }
    if (id == k::ViewAdd) {
        w->mNActivity->sendOp(w->mOpUnitDBId, w->mNWrapper->mNKrossWrapper->mNIota00, new OpParam(k::ViewAdd, 1));
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
        w->mEventAction = [](Wrapper* w)->void{};
        LOGV("NEW EVENT");
        mX = e->getX();
        mY = e->getY();
        mT = e->getEventTime();
    }
    return false;
}

bool FragmentViewAbout::onFling(MotionEvent* e1, MotionEvent* e2, float vVelocityX, float vVelocityY)
{
    w->mTouchState = ( w->mTouchState == 2 ? 3 : 0 );
    return true;
}

void FragmentViewAbout::onLongPress(MotionEvent* e)
{
    w->mTouchState = ( w->mTouchState == 2 ? 3 : 0 );
    w->mEventAction(w);
}

bool FragmentViewAbout::onScroll(MotionEvent* e1, MotionEvent* e2, float distanceX, float distanceY)
{
    nfloat vX = e2->getX() - mX;
    nfloat vY = e2->getY() - mY;
    nfloat vD = (e2->getEventTime() - mT)/1000.0;
    bool ret = abs(vX) > k::SWIPE_MIN_DISTANCE && abs(vY) < k::SWIPE_MAX_OFF_PATH && abs(vX/vD) > k::SWIPE_THRESHOLD_VELOCITY;
    w->mTouchState = ( w->mTouchState == 2 ? 3 : 0 );

    LOGV(("Duration : #" + to_string(vD)).c_str());
    LOGV(("Distance X: #" + to_string(vX) + " Y: #" + to_string(vY)).c_str());
    LOGV(("Velocity X: #" + to_string(vX/vD) + " Y: #" + to_string(vY/vD)).c_str());

    if (ret) {
        if (vX > 0) {
            w->mNActivity->sendOp(w->mOpUnitDBId, w->mNWrapper->mNKrossWrapper->mNIota00, new OpParam(k::ViewAR, 1));
        } else {
            w->mNActivity->sendOp(w->mOpUnitDBId, w->mNWrapper->mNKrossWrapper->mNIota00, new OpParam(k::ViewAR, 1));
        }
    }
    return ret;
}

void FragmentViewAbout::onShowPress(MotionEvent* e)
{
    w->mTouchState = ( w->mTouchState == 2 ? 3 : 0 );
}

bool FragmentViewAbout::onSingleTapUp(MotionEvent* e)
{
    w->mTouchState = ( w->mTouchState == 2 ? 3 : 0 );
    w->mEventAction(w);
    return true;
}

} // End namespace
