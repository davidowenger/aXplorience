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

    if (w->mcMaxLevel == 1) {
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

bool FragmentViewDetails::onMenuItemSelected(nint id)
{
    bool ret = false;

    if (id == R::id::home) {
        w->mNActivity->sendOp(0, w->mOpUnitCoreId, w->w->mNIota00, new OpParam(Wrapper::kViewHome));
        ret = true;
    }
    if (id == Wrapper::kViewDelete) {
        w->mNActivity->sendOp(0, w->mOpUnitCoreId, w->w->mNEpsilon00, new OpParam(mcDBObjectId, true));
        ret = true;
    }
    if (id == Wrapper::kViewEdit) {
        w->mNActivity->sendOp(0, w->mOpUnitCoreId, w->w->mNIota00, new OpParam(Wrapper::kViewEdit, mcDBObjectId));
        ret = true;
    }
    if (id == Wrapper::kViewAdd) {
        w->mNActivity->sendOp(0, w->mOpUnitCoreId, w->w->mNIota00, new OpParam(Wrapper::kViewAdd, 1));
        ret = true;
    }
    return ret;
}

//*******************************************************************************************
//************************************** OnGestureListener  *********************************
//*******************************************************************************************
bool FragmentViewDetails::onDown(MotionEvent* e)
{
    return true;
}

bool FragmentViewDetails::onFling(MotionEvent* e1, MotionEvent* e2, float vVelocityX, float vVelocityY)
{
    bool ret  = false;
    float vDiffX = e2->getX() - e1->getX();

    if (
        abs(vDiffX) > Wrapper::SWIPE_MIN_DISTANCE &&
        abs(vVelocityX) > Wrapper::SWIPE_THRESHOLD_VELOCITY &&
        abs(e2->getY() - e1->getY()) < Wrapper::SWIPE_MAX_OFF_PATH
    ) {
        int vIndex = 0;
        int vSize = w->mMessageLayout->getChildCount();
        nuint vNext = mcDBObjectId;
        ret = true;

        for (vIndex = 0 ; vIndex < vSize && vNext == mcDBObjectId ; ++vIndex) {
            if (((WidgetMessage*)w->mMessageLayout->getChildAt(vIndex))->mcDBObjectId == mcDBObjectId) {
                vNext = ((WidgetMessage*)w->mMessageLayout->getChildAt((vIndex + vSize + ( vDiffX > 0 ? 1 : -1))%vSize))->mcDBObjectId;
            }
        }
        w->mNActivity->setView(Wrapper::kViewDetails, vNext);
    } else if (mTouchState == 1) {
        mViewSource->performClick();
    }
    mTouchState = 0;
    return ret;
}

void FragmentViewDetails::onLongPress(MotionEvent* e)
{
    if (mTouchState == 1) {
        mViewSource->performClick();
    }
    mTouchState = 0;
}

bool FragmentViewDetails::onScroll(MotionEvent* e1, MotionEvent* e2, float distanceX, float distanceY)
{
    mTouchState = 0;
    return false;
}

void FragmentViewDetails::onShowPress(MotionEvent* e)
{
    mTouchState = 0;
}

bool FragmentViewDetails::onSingleTapUp(MotionEvent* e)
{
    if (mTouchState == 1) {
        mViewSource->performClick();
    }
    mTouchState = 0;
    return false;
}

} // End namespace
