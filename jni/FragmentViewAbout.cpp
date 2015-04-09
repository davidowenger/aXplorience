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

bool FragmentViewAbout::onMenuItemSelected(nint id)
{
    return false;
}

//*******************************************************************************************
//************************************** OnGestureListener  *********************************
//*******************************************************************************************
bool FragmentViewAbout::onDown(MotionEvent* e)
{
    return true;
}

bool FragmentViewAbout::onFling(MotionEvent* e1, MotionEvent* e2, float vVelocityX, float vVelocityY)
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
//            if (((FragmentViewAbout*)w->mLayoutMesssage->getChildAt(vIndex))->msDBObjectId == msDBObjectId) {
//                vNext = ((FragmentViewAbout*)w->mLayoutMesssage->getChildAt((vIndex + vSize + ( vDiffX > 0 ? 1 : -1))%vSize))->msDBObjectId;
//            }
//        }
        w->mNActivity->setView(Wrapper::kViewHome, 1);
    } else if (mTouchState == 1) {
        mViewSource->performClick();
    }
    mTouchState = 0;
    return ret;
}

void FragmentViewAbout::onLongPress(MotionEvent* e)
{
    if (mTouchState == 1) {
        mViewSource->performClick();
    }
    mTouchState = 0;
}

bool FragmentViewAbout::onScroll(MotionEvent* e1, MotionEvent* e2, float distanceX, float distanceY)
{
    mTouchState = 0;
    return false;
}

void FragmentViewAbout::onShowPress(MotionEvent* e)
{
    mTouchState = 0;
}

bool FragmentViewAbout::onSingleTapUp(MotionEvent* e)
{
    if (mTouchState == 1) {
        mViewSource->performClick();
    }
    mTouchState = 0;
    return false;
}

} // End namespace
