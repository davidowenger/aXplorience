#include "Common.h"

namespace NSDEVICE
{

View::LayoutParams::LayoutParams()
{
}

View::LayoutParams::~LayoutParams()
{
}

View::OnClickListener::OnClickListener()
{
    NWrapper::w->mNVisitorViewView->tRun(NWrapper::w->mNAlpha03, (NParam)this);
}

View::OnClickListener::~OnClickListener()
{
    NWrapper::w->nFrame->tRun(NWrapper::w->mNDelta00, (NParam)this);
}

View::OnCreateContextMenuListener::OnCreateContextMenuListener()
{
    NWrapper::w->mNVisitorViewView->tRun(NWrapper::w->mNBeta03, (NParam)this);
}
View::OnCreateContextMenuListener::~OnCreateContextMenuListener()
{
    NWrapper::w->nFrame->tRun(NWrapper::w->mNDelta00, (NParam)this);
}

View::OnTouchListener::OnTouchListener()
{
    NWrapper::w->mNVisitorViewView->tRun(NWrapper::w->mNGamma03, (NParam)this);
}

View::OnTouchListener::~OnTouchListener()
{
    NWrapper::w->nFrame->tRun(NWrapper::w->mNDelta00, (NParam)this);
}

View::View(Context* context)
{
    NWrapper::w->mNVisitorViewView->tRun(NWrapper::w->mNAlpha00, (NParam)this);
}

View::~View()
{
}

Drawable* View::getBackground()
{
    Drawable* b = NWrapper::w->mNNoObject->pointer<Drawable>();
    return NWrapper::w->mNNoObject->emplaceKey<Drawable>(b, NWrapper::w->mNVisitorViewView->tRun(NWrapper::w->mNOmicron00, (NParam)this, (NParam)b));
}

int View::getId()
{
    return (nint)NWrapper::w->mNVisitorViewView->tRun(NWrapper::w->mNBeta00, (NParam)this);
}

void View::invalidate()
{
    NWrapper::w->mNVisitorViewView->tRun(NWrapper::w->mNGamma00, (NParam)this);
}

bool View::performClick()
{
    return NWrapper::w->mNVisitorViewView->tRun(NWrapper::w->mNPi00, (NParam)this);
}

void View::requestLayout()
{
    NWrapper::w->mNVisitorViewView->tRun(NWrapper::w->mNDelta00, (NParam)this);
}

void View::setBackgroundColor(int color)
{
    NWrapper::w->mNVisitorViewView->tRun(NWrapper::w->mNEpsilon00, (NParam)this, (NParam)color);
}

void View::setBackgroundDrawable(Drawable* background)
{
    NWrapper::w->mNVisitorViewView->tRun(NWrapper::w->mNDzeta00, (NParam)this, (NParam)background);
}

void View::setBackgroundResource(int resid)
{
    NWrapper::w->mNVisitorViewView->tRun(NWrapper::w->mNRho00, (NParam)this, (NParam)resid);
}

void View::setId(int id)
{
    NWrapper::w->mNVisitorViewView->tRun(NWrapper::w->mNEta00, (NParam)this, (NParam)id);
}

void View::setLayoutParams(View::LayoutParams* params)
{
    NWrapper::w->mNVisitorViewView->tRun(NWrapper::w->mNTheta00, (NParam)this, (NParam)params);
}

void View::setMinimumHeight(int minHeight)
{
    NWrapper::w->mNVisitorViewView->tRun(NWrapper::w->mNMu00, (NParam)this, (NParam)minHeight);
}

void View::setMinimumWidth(int minWidth)
{
    NWrapper::w->mNVisitorViewView->tRun(NWrapper::w->mNNu00, (NParam)this, (NParam)minWidth);
}

void View::setOnClickListener(View::OnClickListener* l)
{
    NWrapper::w->mNVisitorViewView->tRun(NWrapper::w->mNIota00, (NParam)this, (NParam)l);
}

void View::setOnTouchListener(View::OnTouchListener* l)
{
    NWrapper::w->mNVisitorViewView->tRun(NWrapper::w->mNXi00, (NParam)this, (NParam)l);
}

void View::setPadding(int left, int top, int right, int bottom)
{
    NWrapper::w->mNVisitorViewView->tRun(NWrapper::w->mNKappa00, (NParam)this, (NParam)left, (NParam)top, (NParam)right, (NParam)bottom);
}

void View::setVisibility(int visibility)
{
    NWrapper::w->mNVisitorViewView->tRun(NWrapper::w->mNLambda00, (NParam)this, (NParam)visibility);
}

View::View(NNoObject* vNNoObject)
{
}

} // End namespace
