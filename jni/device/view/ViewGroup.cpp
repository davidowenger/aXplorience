#include "Common.h"

namespace NSDEVICE
{

ViewGroup::LayoutParams::LayoutParams(int width, int height)
{
	NWrapper::w->mNVisitorViewViewGroup->tRun(NWrapper::w->mNAlpha03, (NParam)this, (NParam)width, (NParam)height);
}

ViewGroup::LayoutParams::LayoutParams(NNoObject* vNNoObject)
{
}

ViewGroup::LayoutParams::~LayoutParams()
{
}

ViewGroup::MarginLayoutParams::MarginLayoutParams(int width, int height)
	: ViewGroup::LayoutParams(NWrapper::w->mNNoObject->instance<ViewGroup::LayoutParams>())
{
	NWrapper::w->mNVisitorViewViewGroup->tRun(NWrapper::w->mNBeta03, (NParam)this, (NParam)width, (NParam)height);
}

ViewGroup::MarginLayoutParams::MarginLayoutParams(NNoObject* vNNoObject)
	: ViewGroup::LayoutParams(NWrapper::w->mNNoObject->instance<ViewGroup::LayoutParams>())
{
}

ViewGroup::MarginLayoutParams::~MarginLayoutParams()
{
}

void ViewGroup::MarginLayoutParams::setMargins(int left, int top, int right, int bottom)
{
	NWrapper::w->mNVisitorViewViewGroup->tRun(NWrapper::w->mNGamma03, (NParam)this, (NParam)left, (NParam)top, (NParam)right, (NParam)bottom);
}

ViewGroup::~ViewGroup()
{
}

void ViewGroup::addView(View* view)
{
    NWrapper::w->mNVisitorViewViewGroup->tRun(NWrapper::w->mNAlpha00, (NParam)this, (NParam)view);
}

void ViewGroup::addView(View* view, int index)
{
    NWrapper::w->mNVisitorViewViewGroup->tRun(NWrapper::w->mNDzeta00, (NParam)this, (NParam)view, (NParam)index);
}

View* ViewGroup::getChildAt(int index)
{
    View* b = NWrapper::w->mNNoObject->pointer<View>();
    return NWrapper::w->mNNoObject->emplaceKey<View>(b, NWrapper::w->mNVisitorViewViewGroup->tRun(NWrapper::w->mNBeta00, (NParam)this, (NParam)b, (NParam)index));
}

int ViewGroup::getChildCount()
{
    return (nint)NWrapper::w->mNVisitorViewViewGroup->tRun(NWrapper::w->mNGamma00, (NParam)this);
}

bool ViewGroup::onInterceptTouchEvent(MotionEvent* ev)
{
    // Default implementation returns false
    return false;
}

void ViewGroup::removeAllViews()
{
	NWrapper::w->mNVisitorViewViewGroup->tRun(NWrapper::w->mNDelta00, (NParam)this);
}

void ViewGroup::requestLayout()
{
	NWrapper::w->mNVisitorViewViewGroup->tRun(NWrapper::w->mNEpsilon00, (NParam)this);
}

ViewGroup::ViewGroup(NNoObject* vNNoObject)
	: View(NWrapper::w->mNNoObject->instance<View>())
{
}

} // End namespace

