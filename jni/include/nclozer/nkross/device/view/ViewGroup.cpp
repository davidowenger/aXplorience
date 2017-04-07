#include <nkross/NKrossCommon.h>

namespace NSDEVICE
{

ViewGroup::LayoutParams::LayoutParams(int width, int height)
{
    NKrossWrapper::w->mNVisitorViewViewGroup->tRun(NKrossWrapper::w->mNAlpha03, (NParam)this, (NParam)width, (NParam)height);
}

ViewGroup::LayoutParams::LayoutParams(NKrossFriend* vNKrossFriend)
{
}

ViewGroup::LayoutParams::~LayoutParams()
{
}

ViewGroup::MarginLayoutParams::MarginLayoutParams(int width, int height)
    : ViewGroup::LayoutParams(NKrossWrapper::w->mNKrossFriend->instance<ViewGroup::LayoutParams>())
{
    NKrossWrapper::w->mNVisitorViewViewGroup->tRun(NKrossWrapper::w->mNBeta03, (NParam)this, (NParam)width, (NParam)height);
}

ViewGroup::MarginLayoutParams::MarginLayoutParams(NKrossFriend* vNKrossFriend)
    : ViewGroup::LayoutParams(NKrossWrapper::w->mNKrossFriend->instance<ViewGroup::LayoutParams>())
{
}

ViewGroup::MarginLayoutParams::~MarginLayoutParams()
{
}

void ViewGroup::MarginLayoutParams::setMargins(int left, int top, int right, int bottom)
{
    NKrossWrapper::w->mNVisitorViewViewGroup->tRun(NKrossWrapper::w->mNGamma03, (NParam)this, (NParam)left, (NParam)top, (NParam)right, (NParam)bottom);
}

ViewGroup::~ViewGroup()
{
}

void ViewGroup::addView(View* view)
{
    NKrossWrapper::w->mNVisitorViewViewGroup->tRun(NKrossWrapper::w->mNAlpha00, (NParam)this, (NParam)view);
}

void ViewGroup::addView(View* view, int index)
{
    NKrossWrapper::w->mNVisitorViewViewGroup->tRun(NKrossWrapper::w->mNEta00, (NParam)this, (NParam)view, (NParam)index);
}

View* ViewGroup::getChildAt(int index)
{
    View* b = NKrossWrapper::w->mNKrossFriend->pointer<View>();
    return NKrossWrapper::w->mNKrossFriend->emplaceKey<View>(b, NKrossWrapper::w->mNVisitorViewViewGroup->tRun(NKrossWrapper::w->mNBeta00, (NParam)this, (NParam)b, (NParam)index));
}

int ViewGroup::getChildCount()
{
    return (nint)NKrossWrapper::w->mNVisitorViewViewGroup->tRun(NKrossWrapper::w->mNGamma00, (NParam)this);
}

bool ViewGroup::onInterceptTouchEvent(MotionEvent* ev)
{
    // Default implementation returns false
    return false;
}

void ViewGroup::removeAllViews()
{
    NKrossWrapper::w->mNVisitorViewViewGroup->tRun(NKrossWrapper::w->mNDelta00, (NParam)this);
}

void ViewGroup::removeViewAt(int index)
{
    NKrossWrapper::w->mNVisitorViewViewGroup->tRun(NKrossWrapper::w->mNEpsilon00, (NParam)this, (NParam)index);
}

void ViewGroup::requestLayout()
{
    NKrossWrapper::w->mNVisitorViewViewGroup->tRun(NKrossWrapper::w->mNDzeta00, (NParam)this);
}

ViewGroup::ViewGroup(NKrossFriend* vNKrossFriend)
    : View(NKrossWrapper::w->mNKrossFriend->instance<View>())
{
}

} // End namespace

