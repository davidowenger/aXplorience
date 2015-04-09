#include "Common.h"

namespace NSDEVICE
{

FragmentViewHome::FragmentViewHome(Wrapper* const w)
    : FragmentView(w)
{
    setOrientation(LinearLayout::HORIZONTAL);
    setLayoutParams(new LinearLayout::LayoutParams(LinearLayout::LayoutParams::MATCH_PARENT, LinearLayout::LayoutParams::MATCH_PARENT));
    setPadding(0, 0, 0, 0);

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
    } else if (w->mcWidthDp >= 480 && (w->mcView == 3 || (w->mcView == 4 && w->mcMaxLevel == 2))) {
        addView(maContent[0]);
        addView(maContent[1]);
    }
}

bool FragmentViewHome::onMenuItemSelected(nint id)
{
    bool ret = false;

    if (id == Wrapper::kViewAdd) {
        w->mNActivity->sendOp(0, w->mOpUnitCoreId, w->w->mNIota00, new OpParam(Wrapper::kViewAdd, 1));
        ret = true;
    }
    return ret;
}

//*******************************************************************************************
//************************************** OnGestureListener  *********************************
//*******************************************************************************************
bool FragmentViewHome::onDown(MotionEvent* e)
{
    return true;
}

bool FragmentViewHome::onFling(MotionEvent* e1, MotionEvent* e2, float vVelocityX, float vVelocityY)
{
    bool ret  = false;
    float vDiffX = e2->getX() - e1->getX();

    if (
        abs(vDiffX) > Wrapper::SWIPE_MIN_DISTANCE &&
        abs(vVelocityX) > Wrapper::SWIPE_THRESHOLD_VELOCITY &&
        abs(e2->getY() - e1->getY()) < Wrapper::SWIPE_MAX_OFF_PATH
    ) {
//        int vIndex = 0;
//        int vSize = w->mLayoutMesssage->getChildCount();
//        String vNext = msDBObjectId;
//        ret = true;
//
//        for (vIndex = 0 ; vIndex < vSize && vNext == msDBObjectId ; ++vIndex) {
//            if (((FragmentViewHome*)w->mLayoutMesssage->getChildAt(vIndex))->msDBObjectId == msDBObjectId) {
//                vNext = ((FragmentViewHome*)w->mLayoutMesssage->getChildAt((vIndex + vSize + ( vDiffX > 0 ? 1 : -1))%vSize))->msDBObjectId;
//            }
//        }
        w->mNActivity->setView(Wrapper::kViewSettings, 1);
    } else if (mTouchState == 1) {
        mViewSource->performClick();
    }
    mTouchState = 0;
    return ret;
}

void FragmentViewHome::onLongPress(MotionEvent* e)
{
    if (mTouchState == 1) {
        mViewSource->performClick();
    }
    mTouchState = 0;
}

bool FragmentViewHome::onScroll(MotionEvent* e1, MotionEvent* e2, float distanceX, float distanceY)
{
    mTouchState = 0;
    return false;
}

void FragmentViewHome::onShowPress(MotionEvent* e)
{
    mTouchState = 0;
}

bool FragmentViewHome::onSingleTapUp(MotionEvent* e)
{
    if (mTouchState == 1) {
        mViewSource->performClick();
    }
    mTouchState = 0;
    return false;
}

} // End namespace
