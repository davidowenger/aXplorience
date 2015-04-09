#include "Common.h"

namespace NSDEVICE
{

FragmentViewEdit::FragmentViewEdit(Wrapper* const w)
    : FragmentView(w)
{
    setOrientation(LinearLayout::HORIZONTAL);
    setLayoutParams(new LinearLayout::LayoutParams(LinearLayout::LayoutParams::MATCH_PARENT, LinearLayout::LayoutParams::MATCH_PARENT));
    setPadding(0, 0, 0, 0);

    maContent = new Widget*[1];
    maContent[0] = new WidgetMessageEdit(w);
    addView(maContent[0]);
}

FragmentViewEdit::~FragmentViewEdit()
{
    if (maContent[0]) {
       delete maContent[0];
    }
    delete maContent;
}

void FragmentViewEdit::init(nuint vcView, Menu* menu, nuint vcDBObjectId)
{
    mcView = vcView;
    mcDBObjectId = vcDBObjectId;
    maContent[0]->init(vcView, vcDBObjectId);

    menu->removeItem(Wrapper::kViewAdd);
    menu->removeItem(Wrapper::kViewEdit);
    menu->removeItem(Wrapper::kViewDelete);
    menu->removeItem(Wrapper::kViewSave);

    MenuItem* vMenuItemDelete = menu->add(Menu::NONE, Wrapper::kViewDelete, 1, "Delete");
    vMenuItemDelete->setIcon(w->maDrawable[8]);
    vMenuItemDelete->setShowAsAction(MenuItem::SHOW_AS_ACTION_IF_ROOM);

    MenuItem* vMenuItemSave = menu->add(Menu::NONE, Wrapper::kViewSave, 2, "Save");
    vMenuItemSave->setIcon(w->maDrawable[9]);
    vMenuItemSave->setShowAsAction(MenuItem::SHOW_AS_ACTION_IF_ROOM);

    w->mActionBar->setDisplayHomeAsUpEnabled(true);
    w->mActionBar->setHomeButtonEnabled(true);
}

bool FragmentViewEdit::onMenuItemSelected(nint id)
{
    bool ret = false;

    if (id == R::id::home && mcDBObjectId == 1) {
        w->mNActivity->sendOp(0, w->mOpUnitCoreId, w->w->mNIota00, new OpParam(Wrapper::kViewHome));
        ret = true;
    }
    if (id == R::id::home && mcDBObjectId > 1) {
        w->mNActivity->sendOp(0, w->mOpUnitCoreId, w->w->mNIota00, new OpParam(Wrapper::kViewDetails, mcDBObjectId));
        ret = true;
    }
    if (id == Wrapper::kViewSave && mcDBObjectId == 1) {
        // ADD
        w->mNActivity->sendOp(0, w->mOpUnitCoreId, w->w->mNDelta00, new OpMessage(
           to_string(((WidgetMessageEdit*)maContent[0])->mCategory->getSelectedItemPosition()),
           ((WidgetMessageEdit*)maContent[0])->mTitle->getText(),
           ((WidgetMessageEdit*)maContent[0])->mText->getText(),
           ((WidgetMessageEdit*)maContent[0])->mLink->getText()
        ));
        ret = true;
    }
    if (id == Wrapper::kViewSave && mcDBObjectId != 1) {
        // EDIT
        w->mNActivity->sendOp(0, w->mOpUnitCoreId, w->w->mNTheta00, new OpMessage(
           to_string(((WidgetMessageEdit*)maContent[0])->mCategory->getSelectedItemPosition()),
           ((WidgetMessageEdit*)maContent[0])->mTitle->getText(),
           ((WidgetMessageEdit*)maContent[0])->mText->getText(),
           ((WidgetMessageEdit*)maContent[0])->mLink->getText(),
           "",
           mcDBObjectId
        ));
        ret = true;
    }
    if (id == Wrapper::kViewDelete) {
        w->mNActivity->sendOp(0, w->mOpUnitCoreId, w->w->mNEpsilon00, new OpParam(mcDBObjectId, true));
        ret = true;
    }
    return ret;
}

//*******************************************************************************************
//************************************** OnGestureListener  *********************************
//*******************************************************************************************
bool FragmentViewEdit::onDown(MotionEvent* e)
{
    return true;
}

bool FragmentViewEdit::onFling(MotionEvent* e1, MotionEvent* e2, float vVelocityX, float vVelocityY)
{
    mTouchState = 0;
    return false;
}

void FragmentViewEdit::onLongPress(MotionEvent* e)
{
    mTouchState = 0;
}

bool FragmentViewEdit::onScroll(MotionEvent* e1, MotionEvent* e2, float distanceX, float distanceY)
{
    mTouchState = 0;
    return false;
}

void FragmentViewEdit::onShowPress(MotionEvent* e)
{
    mTouchState = 0;
}

bool FragmentViewEdit::onSingleTapUp(MotionEvent* e)
{
    mTouchState = 0;
    return false;
}

} // End namespace
