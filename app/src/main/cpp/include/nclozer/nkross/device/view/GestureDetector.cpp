#include <nkross/NKrossCommon.h>

namespace NSDEVICE
{

GestureDetector::OnGestureListener::OnGestureListener()
{
    NSNKROSS::w->mNVisitorView->tRun(NSNKROSS::w->mNAlpha02, (NParam)this);
}

GestureDetector::OnGestureListener::~OnGestureListener()
{
    NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNDelta00, (NParam)this);
}

GestureDetector::GestureDetector(Context* context, GestureDetector::OnGestureListener* listener)
{
    NSNKROSS::w->mNVisitorView->tRun(NSNKROSS::w->mNAlpha00, (NParam)this, (NParam)context, (NParam)listener);
}

GestureDetector::~GestureDetector()
{
}

bool GestureDetector::onTouchEvent(MotionEvent* ev)
{
    return (bool)NSNKROSS::w->mNVisitorView->tRun(NSNKROSS::w->mNBeta00, (NParam)this, (NParam)ev);
}

GestureDetector::GestureDetector(NKrossFriend* vNKrossFriend)
{
}

} // End namespace
