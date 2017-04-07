#include "Common.h"

namespace NSDEVICE
{

FragmentViewDetails::FragmentViewDetails(Wrapper* const w)
    : FragmentView(w)
{
    mWidget = new Widget(w);

    setOrientation(LinearLayout::HORIZONTAL);
    setLayoutParams(new LinearLayout::LayoutParams(LinearLayout::LayoutParams::MATCH_PARENT, LinearLayout::LayoutParams::MATCH_PARENT));
    setPadding(0, 0, 0, 0);
}

FragmentViewDetails::~FragmentViewDetails()
{
}

void FragmentViewDetails::init(nuint vcView, DBObject* vDBObject)
{
    mcView = vcView;

    if (vDBObject) {
        mcDBObjectId = vDBObject->mId;
        mIsInbound = vDBObject->is("sIn");
        w->mWidgetMessageDetails->update(vDBObject);
    }
    if (w->mMenu) {
        removeAllViews();

        if (w->mcMaxLevel == 1) {
            if (w->mcScreenWidthDp >= 480) {
                addView(mWidget);
            }
            addView(w->mWidgetMessageDetails);

            w->mMenu->removeItem(k::ViewAdd);
            w->mMenu->removeItem(k::ViewEdit);
            w->mMenu->removeItem(k::ViewDelete);
            w->mMenu->removeItem(k::ViewSave);

            MenuItem* vMenuItemDelete = w->mMenu->add(Menu::NONE, k::ViewDelete, 1, "Delete");
            vMenuItemDelete->setIcon(w->maDrawable[8]);
            vMenuItemDelete->setShowAsAction(MenuItem::SHOW_AS_ACTION_IF_ROOM);
            delete vMenuItemDelete;

            if (!mIsInbound) {
                MenuItem* vMenuItemEdit = w->mMenu->add(Menu::NONE, k::ViewEdit, 2, "Edit");
                vMenuItemEdit->setIcon(w->maDrawable[7]);
                vMenuItemEdit->setShowAsAction(MenuItem::SHOW_AS_ACTION_IF_ROOM);
                delete vMenuItemEdit;
            }
            MenuItem* vMenuItemAdd = w->mMenu->add(Menu::NONE, k::ViewAdd, 3, "Add");
            vMenuItemAdd->setIcon(w->maDrawable[10]);
            vMenuItemAdd->setShowAsAction(MenuItem::SHOW_AS_ACTION_IF_ROOM);
            delete vMenuItemAdd;

            w->mActionBar->setDisplayHomeAsUpEnabled(true);
            w->mActionBar->setHomeButtonEnabled(true);
        }
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
        w->mNActivity->sendOp(w->mOpUnitDBId, w->mNWrapper->mNKrossWrapper->mNIota00, new OpParam(k::ViewAR));
        ret = true;
    }
    if (id == k::ViewDelete) {
        w->mNActivity->sendOp(w->mOpUnitDBId, w->mNWrapper->mNKrossWrapper->mNEpsilon00, new OpParam(mcDBObjectId, true));
        ret = true;
    }
    if (id == k::ViewEdit) {
        w->mNActivity->sendOp(w->mOpUnitDBId, w->mNWrapper->mNKrossWrapper->mNIota00, new OpParam(k::ViewEdit, mcDBObjectId));
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
bool FragmentViewDetails::onDown(MotionEvent* e)
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

bool FragmentViewDetails::onFling(MotionEvent* e1, MotionEvent* e2, float vVelocityX, float vVelocityY)
{
    w->mTouchState = ( w->mTouchState == 2 ? 3 : 0 );
    return true;
}

void FragmentViewDetails::onLongPress(MotionEvent* e)
{
    w->mTouchState = ( w->mTouchState == 2 ? 3 : 0 );
    w->mEventAction(w);
}

bool FragmentViewDetails::onScroll(MotionEvent* e1, MotionEvent* e2, float distanceX, float distanceY)
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
        int vIndex = 0;
        int vSize = w->mMessageLayout->getChildCount();
        nuint vNext = mcDBObjectId;

        for (vIndex = 0 ; vIndex < vSize && vNext == mcDBObjectId ; ++vIndex) {
            if (((WidgetMessage*)w->mMessageLayout->getChildAt(vIndex))->mcDBObjectId == mcDBObjectId) {
                vNext = ((WidgetMessage*)w->mMessageLayout->getChildAt((vIndex + vSize + ( vX > 0 ? 1 : -1))%vSize))->mcDBObjectId;
            }
        }
        w->mNActivity->sendOp(w->mOpUnitDBId, w->mNWrapper->mNKrossWrapper->mNIota00, new OpParam(k::ViewDetails, vNext));
    }
    return ret;
}

void FragmentViewDetails::onShowPress(MotionEvent* e)
{
    w->mTouchState = ( w->mTouchState == 2 ? 3 : 0 );
}

bool FragmentViewDetails::onSingleTapUp(MotionEvent* e)
{
    w->mTouchState = ( w->mTouchState == 2 ? 3 : 0 );
    w->mEventAction(w);
    return true;
}

} // End namespace
