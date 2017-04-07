#include <nkross/NKrossCommon.h>

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
    NKrossWrapper::w->mNVisitorViewView->tRun(NKrossWrapper::w->mNAlpha03, (NParam)this);
}

View::OnClickListener::~OnClickListener()
{
    NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNDelta00, (NParam)this);
}

View::OnCreateContextMenuListener::OnCreateContextMenuListener()
{
    NKrossWrapper::w->mNVisitorViewView->tRun(NKrossWrapper::w->mNBeta03, (NParam)this);
}
View::OnCreateContextMenuListener::~OnCreateContextMenuListener()
{
    NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNDelta00, (NParam)this);
}

View::OnTouchListener::OnTouchListener()
{
    NKrossWrapper::w->mNVisitorViewView->tRun(NKrossWrapper::w->mNGamma03, (NParam)this);
}

View::OnTouchListener::~OnTouchListener()
{
    NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNDelta00, (NParam)this);
}

View::View(Context* context)
{
    NKrossWrapper::w->mNVisitorViewView->tRun(NKrossWrapper::w->mNAlpha00, (NParam)this);
}

View::~View()
{
}

Drawable* View::getBackground()
{
    Drawable* b = NKrossWrapper::w->mNKrossFriend->pointer<Drawable>();
    return NKrossWrapper::w->mNKrossFriend->emplaceKey<Drawable>(b, NKrossWrapper::w->mNVisitorViewView->tRun(NKrossWrapper::w->mNOmicron00, (NParam)this, (NParam)b));
}

int View::getId()
{
    return (nint)NKrossWrapper::w->mNVisitorViewView->tRun(NKrossWrapper::w->mNBeta00, (NParam)this);
}

void View::invalidate()
{
    NKrossWrapper::w->mNVisitorViewView->tRun(NKrossWrapper::w->mNGamma00, (NParam)this);
}

bool View::performClick()
{
    return NKrossWrapper::w->mNVisitorViewView->tRun(NKrossWrapper::w->mNPi00, (NParam)this);
}

void View::requestLayout()
{
    NKrossWrapper::w->mNVisitorViewView->tRun(NKrossWrapper::w->mNDelta00, (NParam)this);
}

void View::setBackgroundColor(int color)
{
    NKrossWrapper::w->mNVisitorViewView->tRun(NKrossWrapper::w->mNEpsilon00, (NParam)this, (NParam)color);
}

void View::setBackgroundDrawable(Drawable* background)
{
    NKrossWrapper::w->mNVisitorViewView->tRun(NKrossWrapper::w->mNDzeta00, (NParam)this, (NParam)background);
}

void View::setBackgroundResource(int resid)
{
    NKrossWrapper::w->mNVisitorViewView->tRun(NKrossWrapper::w->mNRho00, (NParam)this, (NParam)resid);
}

void View::setId(int id)
{
    NKrossWrapper::w->mNVisitorViewView->tRun(NKrossWrapper::w->mNEta00, (NParam)this, (NParam)id);
}

void View::setLayoutParams(View::LayoutParams* params)
{
    NKrossWrapper::w->mNVisitorViewView->tRun(NKrossWrapper::w->mNTheta00, (NParam)this, (NParam)params);
}

void View::setMinimumHeight(int minHeight)
{
    NKrossWrapper::w->mNVisitorViewView->tRun(NKrossWrapper::w->mNMu00, (NParam)this, (NParam)minHeight);
}

void View::setMinimumWidth(int minWidth)
{
    NKrossWrapper::w->mNVisitorViewView->tRun(NKrossWrapper::w->mNNu00, (NParam)this, (NParam)minWidth);
}

void View::setOnClickListener(View::OnClickListener* l)
{
    NKrossWrapper::w->mNVisitorViewView->tRun(NKrossWrapper::w->mNIota00, (NParam)this, (NParam)l);
}

void View::setOnTouchListener(View::OnTouchListener* l)
{
    NKrossWrapper::w->mNVisitorViewView->tRun(NKrossWrapper::w->mNXi00, (NParam)this, (NParam)l);
}

void View::setPadding(int left, int top, int right, int bottom)
{
    NKrossWrapper::w->mNVisitorViewView->tRun(NKrossWrapper::w->mNKappa00, (NParam)this, (NParam)left, (NParam)top, (NParam)right, (NParam)bottom);
}

void View::setVisibility(int visibility)
{
    NKrossWrapper::w->mNVisitorViewView->tRun(NKrossWrapper::w->mNLambda00, (NParam)this, (NParam)visibility);
}

View::View(NKrossFriend* vNKrossFriend)
{
}

} // End namespace
