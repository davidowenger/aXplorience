#include <nkross/NKrossCommon.h>

namespace NSDEVICE
{

GestureDetector::OnGestureListener::OnGestureListener()
{
    NKrossWrapper::w->mNVisitorView->tRun(NKrossWrapper::w->mNAlpha02, (NParam)this);
}

GestureDetector::OnGestureListener::~OnGestureListener()
{
    NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNDelta00, (NParam)this);
}

GestureDetector::GestureDetector(Context* context, GestureDetector::OnGestureListener* listener)
{
    NKrossWrapper::w->mNVisitorView->tRun(NKrossWrapper::w->mNAlpha00, (NParam)this, (NParam)context, (NParam)listener);
}

GestureDetector::~GestureDetector()
{
}

bool GestureDetector::onTouchEvent(MotionEvent* ev)
{
    return (bool)NKrossWrapper::w->mNVisitorView->tRun(NKrossWrapper::w->mNBeta00, (NParam)this, (NParam)ev);
}

void GestureDetector::setIsLongpressEnabled(bool enabled)
{
    NKrossWrapper::w->mNVisitorView->tRun(NKrossWrapper::w->mNKhi00, (NParam)this, (NParam)enabled);
}

GestureDetector::GestureDetector(NKrossFriend* vNKrossFriend)
{
}

} // End namespace
