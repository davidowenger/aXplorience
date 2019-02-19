#include "Common.h"

namespace NSDEVICE
{

FragmentViewEdit::FragmentViewEdit(Wrapper* const w)
    : FragmentView(w)
{
    setOrientation(LinearLayout::HORIZONTAL);
    setLayoutParams(new LinearLayout::LayoutParams(LinearLayout::LayoutParams::MATCH_PARENT, LinearLayout::LayoutParams::MATCH_PARENT));
    setPadding(0, 0, 0, 0);

    addView(w->mWidgetMessageEdit);
}

FragmentViewEdit::~FragmentViewEdit()
{
}

void FragmentViewEdit::init(nuint vcView, DBObject* vDBObject)
{
    mcView = vcView;

    if (vDBObject) {
        mcDBObjectId = vDBObject->mId;
        w->mWidgetMessageEdit->update(vDBObject);
    }
    if (w->mMenu) {
        w->mMenu->removeItem(Wrapper::kViewAdd);
        w->mMenu->removeItem(Wrapper::kViewEdit);
        w->mMenu->removeItem(Wrapper::kViewDelete);
        w->mMenu->removeItem(Wrapper::kViewSave);

        MenuItem* vMenuItemDelete = w->mMenu->add(Menu::NONE, Wrapper::kViewDelete, 1, "Delete");
        vMenuItemDelete->setIcon(w->maDrawable[8]);
        vMenuItemDelete->setShowAsAction(MenuItem::SHOW_AS_ACTION_IF_ROOM);
        delete vMenuItemDelete;

        MenuItem* vMenuItemSave = w->mMenu->add(Menu::NONE, Wrapper::kViewSave, 2, "Save");
        vMenuItemSave->setIcon(w->maDrawable[9]);
        vMenuItemSave->setShowAsAction(MenuItem::SHOW_AS_ACTION_IF_ROOM);
        delete vMenuItemSave;

        w->mActionBar->setDisplayHomeAsUpEnabled(true);
        w->mActionBar->setHomeButtonEnabled(true);
    }
}

bool FragmentViewEdit::onMenuItemSelected(nint id)
{
    bool ret = false;

    if (id == R::id::home && mcDBObjectId == 1) {
        w->mNActivity->sendOp(w->mOpUnitUIId, w->mNWrapper->mNKrossWrapper->mNIota00, new OpParam(Wrapper::kViewHome));
        ret = true;
    }
    if (id == R::id::home && mcDBObjectId > 1) {
        w->mNActivity->sendOp(w->mOpUnitUIId, w->mNWrapper->mNKrossWrapper->mNIota00, new OpParam(Wrapper::kViewDetails, mcDBObjectId));
        ret = true;
    }
    if (id == Wrapper::kViewSave && mcDBObjectId == 1) {
        // ADD
        w->mNActivity->sendOp(w->mOpUnitUIId, w->mNWrapper->mNKrossWrapper->mNDelta00, new OpMessage(
           to_string(w->mWidgetMessageEdit->mCategory->getSelectedItemPosition()),
           w->mWidgetMessageEdit->mTitle->getText(),
           w->mWidgetMessageEdit->mText->getText(),
           w->mWidgetMessageEdit->mLink->getText()
        ));
        ret = true;
    }
    if (id == Wrapper::kViewSave && mcDBObjectId != 1) {
        // EDIT
        w->mNActivity->sendOp(w->mOpUnitUIId, w->mNWrapper->mNKrossWrapper->mNTheta00, new OpMessage(
           to_string(w->mWidgetMessageEdit->mCategory->getSelectedItemPosition()),
           w->mWidgetMessageEdit->mTitle->getText(),
           w->mWidgetMessageEdit->mText->getText(),
           w->mWidgetMessageEdit->mLink->getText(),
           "",
           mcDBObjectId
        ));
        ret = true;
    }
    if (id == Wrapper::kViewDelete) {
        w->mNActivity->sendOp(w->mOpUnitUIId, w->mNWrapper->mNKrossWrapper->mNEpsilon00, new OpParam(mcDBObjectId, true));
        ret = true;
    }
    return ret;
}

//*******************************************************************************************
//************************************** OnGestureListener  *********************************
//*******************************************************************************************
bool FragmentViewEdit::onDown(MotionEvent* e)
{
    w->mTouchState = 0;
    return true;
}

bool FragmentViewEdit::onFling(MotionEvent* e1, MotionEvent* e2, float vVelocityX, float vVelocityY)
{
    w->mTouchState = 0;
    return false;
}

void FragmentViewEdit::onLongPress(MotionEvent* e)
{
    w->mTouchState = 0;
}

bool FragmentViewEdit::onScroll(MotionEvent* e1, MotionEvent* e2, float distanceX, float distanceY)
{
    w->mTouchState = 0;
    return false;
}

void FragmentViewEdit::onShowPress(MotionEvent* e)
{
    w->mTouchState = 0;
}

bool FragmentViewEdit::onSingleTapUp(MotionEvent* e)
{
    w->mTouchState = 0;
    return false;
}

} // End namespace
