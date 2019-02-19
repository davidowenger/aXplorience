#include <nkross/NKrossCommon.h>

namespace NSDEVICE
{

ViewGroup::LayoutParams::LayoutParams(int width, int height)
{
    NSNKROSS::w->mNVisitorViewViewGroup->tRun(NSNKROSS::w->mNAlpha03, (NParam)this, (NParam)width, (NParam)height);
}

ViewGroup::LayoutParams::LayoutParams(NKrossFriend* vNKrossFriend)
{
}

ViewGroup::LayoutParams::~LayoutParams()
{
}

ViewGroup::MarginLayoutParams::MarginLayoutParams(int width, int height)
    : ViewGroup::LayoutParams(NSNKROSS::w->mNKrossFriend->instance<ViewGroup::LayoutParams>())
{
    NSNKROSS::w->mNVisitorViewViewGroup->tRun(NSNKROSS::w->mNBeta03, (NParam)this, (NParam)width, (NParam)height);
}

ViewGroup::MarginLayoutParams::MarginLayoutParams(NKrossFriend* vNKrossFriend)
    : ViewGroup::LayoutParams(NSNKROSS::w->mNKrossFriend->instance<ViewGroup::LayoutParams>())
{
}

ViewGroup::MarginLayoutParams::~MarginLayoutParams()
{
}

void ViewGroup::MarginLayoutParams::setMargins(int left, int top, int right, int bottom)
{
    NSNKROSS::w->mNVisitorViewViewGroup->tRun(NSNKROSS::w->mNGamma03, (NParam)this, (NParam)left, (NParam)top, (NParam)right, (NParam)bottom);
}

ViewGroup::~ViewGroup()
{
}

void ViewGroup::addView(View* view)
{
    NSNKROSS::w->mNVisitorViewViewGroup->tRun(NSNKROSS::w->mNAlpha00, (NParam)this, (NParam)view);
}

void ViewGroup::addView(View* view, int index)
{
    NSNKROSS::w->mNVisitorViewViewGroup->tRun(NSNKROSS::w->mNEta00, (NParam)this, (NParam)view, (NParam)index);
}

View* ViewGroup::getChildAt(int index)
{
    View* b = NSNKROSS::w->mNKrossFriend->pointer<View>();
    return NSNKROSS::w->mNKrossFriend->emplaceKey<View>(b, NSNKROSS::w->mNVisitorViewViewGroup->tRun(NSNKROSS::w->mNBeta00, (NParam)this, (NParam)b, (NParam)index));
}

int ViewGroup::getChildCount()
{
    return (nint)NSNKROSS::w->mNVisitorViewViewGroup->tRun(NSNKROSS::w->mNGamma00, (NParam)this);
}

bool ViewGroup::onInterceptTouchEvent(MotionEvent* ev)
{
    // Default implementation returns false
    return false;
}

void ViewGroup::removeAllViews()
{
    NSNKROSS::w->mNVisitorViewViewGroup->tRun(NSNKROSS::w->mNDelta00, (NParam)this);
}

void ViewGroup::removeViewAt(int index)
{
    NSNKROSS::w->mNVisitorViewViewGroup->tRun(NSNKROSS::w->mNEpsilon00, (NParam)this, (NParam)index);
}

void ViewGroup::requestLayout()
{
    NSNKROSS::w->mNVisitorViewViewGroup->tRun(NSNKROSS::w->mNDzeta00, (NParam)this);
}

ViewGroup::ViewGroup(NKrossFriend* vNKrossFriend)
    : View(NSNKROSS::w->mNKrossFriend->instance<View>())
{
}

} // End namespace

