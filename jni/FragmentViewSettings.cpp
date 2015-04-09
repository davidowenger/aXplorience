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

bool FragmentViewSettings::onMenuItemSelected(nint id)
{
    return false;
}

//*******************************************************************************************
//************************************** OnGestureListener  *********************************
//*******************************************************************************************
bool FragmentViewSettings::onDown(MotionEvent* e)
{
    return true;
}

bool FragmentViewSettings::onFling(MotionEvent* e1, MotionEvent* e2, float vVelocityX, float vVelocityY)
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
//            if (((FragmentViewSettings*)w->mLayoutMesssage->getChildAt(vIndex))->msDBObjectId == msDBObjectId) {
//                vNext = ((FragmentViewSettings*)w->mLayoutMesssage->getChildAt((vIndex + vSize + ( vDiffX > 0 ? 1 : -1))%vSize))->msDBObjectId;
//            }
//        }
        w->mNActivity->setView(Wrapper::kViewAbout, 1);
    } else if (mTouchState == 1) {
        mViewSource->performClick();
    }
    mTouchState = 0;
    return ret;
}

void FragmentViewSettings::onLongPress(MotionEvent* e)
{
    if (mTouchState == 1) {
        mViewSource->performClick();
    }
    mTouchState = 0;
}

bool FragmentViewSettings::onScroll(MotionEvent* e1, MotionEvent* e2, float distanceX, float distanceY)
{
    mTouchState = 0;
    return false;
}

void FragmentViewSettings::onShowPress(MotionEvent* e)
{
    mTouchState = 0;
}

bool FragmentViewSettings::onSingleTapUp(MotionEvent* e)
{
    if (mTouchState == 1) {
        mViewSource->performClick();
    }
    mTouchState = 0;
    return false;
}

} // End namespace
