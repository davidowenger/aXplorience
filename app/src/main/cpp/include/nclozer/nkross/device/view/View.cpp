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
    NSNKROSS::w->mNVisitorViewView->tRun(NSNKROSS::w->mNAlpha03, (NParam)this);
}

View::OnClickListener::~OnClickListener()
{
    NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNDelta00, (NParam)this);
}

View::OnCreateContextMenuListener::OnCreateContextMenuListener()
{
    NSNKROSS::w->mNVisitorViewView->tRun(NSNKROSS::w->mNBeta03, (NParam)this);
}
View::OnCreateContextMenuListener::~OnCreateContextMenuListener()
{
    NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNDelta00, (NParam)this);
}

View::OnTouchListener::OnTouchListener()
{
    NSNKROSS::w->mNVisitorViewView->tRun(NSNKROSS::w->mNGamma03, (NParam)this);
}

View::OnTouchListener::~OnTouchListener()
{
    NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNDelta00, (NParam)this);
}

View::View(Context* context)
{
    NSNKROSS::w->mNVisitorViewView->tRun(NSNKROSS::w->mNAlpha00, (NParam)this);
}

View::~View()
{
}

Drawable* View::getBackground()
{
    Drawable* b = NSNKROSS::w->mNKrossFriend->pointer<Drawable>();
    return NSNKROSS::w->mNKrossFriend->emplaceKey<Drawable>(b, NSNKROSS::w->mNVisitorViewView->tRun(NSNKROSS::w->mNOmicron00, (NParam)this, (NParam)b));
}

int View::getId()
{
    return (nint)NSNKROSS::w->mNVisitorViewView->tRun(NSNKROSS::w->mNBeta00, (NParam)this);
}

void View::invalidate()
{
    NSNKROSS::w->mNVisitorViewView->tRun(NSNKROSS::w->mNGamma00, (NParam)this);
}

bool View::performClick()
{
    return NSNKROSS::w->mNVisitorViewView->tRun(NSNKROSS::w->mNPi00, (NParam)this);
}

void View::requestLayout()
{
    NSNKROSS::w->mNVisitorViewView->tRun(NSNKROSS::w->mNDelta00, (NParam)this);
}

void View::setBackgroundColor(int color)
{
    NSNKROSS::w->mNVisitorViewView->tRun(NSNKROSS::w->mNEpsilon00, (NParam)this, (NParam)color);
}

void View::setBackgroundDrawable(Drawable* background)
{
    NSNKROSS::w->mNVisitorViewView->tRun(NSNKROSS::w->mNDzeta00, (NParam)this, (NParam)background);
}

void View::setBackgroundResource(int resid)
{
    NSNKROSS::w->mNVisitorViewView->tRun(NSNKROSS::w->mNRho00, (NParam)this, (NParam)resid);
}

void View::setId(int id)
{
    NSNKROSS::w->mNVisitorViewView->tRun(NSNKROSS::w->mNEta00, (NParam)this, (NParam)id);
}

void View::setLayoutParams(View::LayoutParams* params)
{
    NSNKROSS::w->mNVisitorViewView->tRun(NSNKROSS::w->mNTheta00, (NParam)this, (NParam)params);
}

void View::setMinimumHeight(int minHeight)
{
    NSNKROSS::w->mNVisitorViewView->tRun(NSNKROSS::w->mNMu00, (NParam)this, (NParam)minHeight);
}

void View::setMinimumWidth(int minWidth)
{
    NSNKROSS::w->mNVisitorViewView->tRun(NSNKROSS::w->mNNu00, (NParam)this, (NParam)minWidth);
}

void View::setOnClickListener(View::OnClickListener* l)
{
    NSNKROSS::w->mNVisitorViewView->tRun(NSNKROSS::w->mNIota00, (NParam)this, (NParam)l);
}

void View::setOnTouchListener(View::OnTouchListener* l)
{
    NSNKROSS::w->mNVisitorViewView->tRun(NSNKROSS::w->mNXi00, (NParam)this, (NParam)l);
}

void View::setPadding(int left, int top, int right, int bottom)
{
    NSNKROSS::w->mNVisitorViewView->tRun(NSNKROSS::w->mNKappa00, (NParam)this, (NParam)left, (NParam)top, (NParam)right, (NParam)bottom);
}

void View::setVisibility(int visibility)
{
    NSNKROSS::w->mNVisitorViewView->tRun(NSNKROSS::w->mNLambda00, (NParam)this, (NParam)visibility);
}

View::View(NKrossFriend* vNKrossFriend)
{
}

} // End namespace
