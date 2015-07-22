#include "Common.h"

namespace NSDEVICE
{

FragmentViewDetails::FragmentViewDetails(Wrapper* const w)
    : FragmentView(w)
{
    setOrientation(LinearLayout::HORIZONTAL);
    setLayoutParams(new LinearLayout::LayoutParams(LinearLayout::LayoutParams::MATCH_PARENT, LinearLayout::LayoutParams::MATCH_PARENT));
    setPadding(0, 0, 0, 0);

    maContent = new Widget*[2];

    if (w->mcWidthDp < 480) {
        maContent[0] = new WidgetMessageDetails(w);
        maContent[1] = nullptr;
        addView(maContent[0]);
    } else {
        maContent[0] = new WidgetMessageDetails(w);
        maContent[1] = new Widget(w);
        addView(maContent[1]);
        addView(maContent[0]);
    }
}

FragmentViewDetails::~FragmentViewDetails()
{
    if (maContent[0]) {
       delete maContent[0];
    }
    if (maContent[1]) {
       delete maContent[1];
    }
    delete maContent;
}

void FragmentViewDetails::init(nuint vcView, Menu* menu, nuint vcDBObjectId)
{
    mcView = vcView;
    mcDBObjectId = vcDBObjectId;
    maContent[0]->init(vcView, vcDBObjectId);

    removeAllViews();

    if (w->mcMaxLevel == 1) {
        if (w->mcWidthDp < 480) {
            addView(maContent[0]);
        } else {
            addView(maContent[1]);
            addView(maContent[0]);
        }
        menu->removeItem(Wrapper::kViewAdd);
        menu->removeItem(Wrapper::kViewEdit);
        menu->removeItem(Wrapper::kViewDelete);
        menu->removeItem(Wrapper::kViewSave);

        MenuItem* vMenuItemDelete = menu->add(Menu::NONE, Wrapper::kViewDelete, 1, "Delete");
        vMenuItemDelete->setIcon(w->maDrawable[8]);
        vMenuItemDelete->setShowAsAction(MenuItem::SHOW_AS_ACTION_IF_ROOM);

        MenuItem* vMenuItemEdit = menu->add(Menu::NONE, Wrapper::kViewEdit, 2, "Edit");
        vMenuItemEdit->setIcon(w->maDrawable[7]);
        vMenuItemEdit->setShowAsAction(MenuItem::SHOW_AS_ACTION_IF_ROOM);

        MenuItem* vMenuItemAdd = menu->add(Menu::NONE, Wrapper::kViewAdd, 3, "Add");
        vMenuItemAdd->setIcon(w->maDrawable[10]);
        vMenuItemAdd->setShowAsAction(MenuItem::SHOW_AS_ACTION_IF_ROOM);

        w->mActionBar->setDisplayHomeAsUpEnabled(true);
        w->mActionBar->setHomeButtonEnabled(true);
    }
}

bool FragmentViewDetails::onInterceptTouchEvent(MotionEvent* ev)
{
    return w->maGestureDetector[w->mcView]->onTouchEvent(ev);
}

bool FragmentViewDetails::onMenuItemSelected(nint id)
{
    bool ret = false;

    if (id == R::id::home) {
        w->mNActivity->setView(Wrapper::kViewHome, 0);
        w->mNActivity->sendOp(0, w->mOpUnitUIId, w->w->mNIota00, new OpParam(Wrapper::kViewHome));
        ret = true;
    }
    if (id == Wrapper::kViewDelete) {
        w->mNActivity->sendOp(0, w->mOpUnitUIId, w->w->mNEpsilon00, new OpParam(mcDBObjectId, true));
        ret = true;
    }
    if (id == Wrapper::kViewEdit) {
        w->mNActivity->setView(Wrapper::kViewEdit, mcDBObjectId);
        w->mNActivity->sendOp(0, w->mOpUnitUIId, w->w->mNIota00, new OpParam(Wrapper::kViewEdit, mcDBObjectId));
        ret = true;
    }
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
bool FragmentViewDetails::onDown(MotionEvent* e)
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

bool FragmentViewDetails::onFling(MotionEvent* e1, MotionEvent* e2, float vVelocityX, float vVelocityY)
{
    w->mTouchState = 3;
    return true;
}

void FragmentViewDetails::onLongPress(MotionEvent* e)
{
    w->mTouchState = 3;
    w->mEventAction();
}

bool FragmentViewDetails::onScroll(MotionEvent* e1, MotionEvent* e2, float distanceX, float distanceY)
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
        int vIndex = 0;
        int vSize = w->mMessageLayout->getChildCount();
        nuint vNext = mcDBObjectId;

        for (vIndex = 0 ; vIndex < vSize && vNext == mcDBObjectId ; ++vIndex) {
            if (((WidgetMessage*)w->mMessageLayout->getChildAt(vIndex))->mcDBObjectId == mcDBObjectId) {
                vNext = ((WidgetMessage*)w->mMessageLayout->getChildAt((vIndex + vSize + ( vX > 0 ? 1 : -1))%vSize))->mcDBObjectId;
            }
        }
        w->mNActivity->setView(Wrapper::kViewDetails, vNext);
    }
    return ret;
}

void FragmentViewDetails::onShowPress(MotionEvent* e)
{
    w->mTouchState = 3;
}

bool FragmentViewDetails::onSingleTapUp(MotionEvent* e)
{
    w->mTouchState = 3;
    w->mEventAction();
    return true;
}

} // End namespace
