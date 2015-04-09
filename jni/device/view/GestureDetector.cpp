#include "Common.h"

namespace NSDEVICE
{

GestureDetector::OnGestureListener::OnGestureListener()
{
    NWrapper::w->mNVisitorView->tRun(NWrapper::w->mNAlpha02, (NParam)this);
}

GestureDetector::OnGestureListener::~OnGestureListener()
{
    NWrapper::w->nFrame->tRun(NWrapper::w->mNDelta00, (NParam)this);
}

GestureDetector::GestureDetector(Context* context, GestureDetector::OnGestureListener* listener)
{
    NWrapper::w->mNVisitorView->tRun(NWrapper::w->mNAlpha00, (NParam)this, (NParam)context, (NParam)listener);
}

GestureDetector::~GestureDetector()
{
}

bool GestureDetector::onTouchEvent(MotionEvent* ev)
{
    return (bool)NWrapper::w->mNVisitorView->tRun(NWrapper::w->mNBeta00, (NParam)this, (NParam)ev);
}

GestureDetector::GestureDetector(NNoObject* vNNoObject)
{
}

} // End namespace
