#ifndef __ActionBar_H__
#define __ActionBar_H__

namespace NSDEVICE
{

class ActionBar : public Object
{
friend NSNATIVE::NKrossFriend;

public:
    static const int POP_BACK_STACK_INCLUSIVE = 1;

    virtual ~ActionBar()
    {
    }

    virtual void setIcon(Drawable* icon)
    {
        NKrossWrapper::w->mNVisitorApp->tRun(NKrossWrapper::w->mNAlpha00, (NParam)this, (NParam)icon);
    }

    virtual void setDisplayHomeAsUpEnabled(bool showHomeAsUp)
    {
        NKrossWrapper::w->mNVisitorApp->tRun(NKrossWrapper::w->mNBeta00, (NParam)this, (NParam)showHomeAsUp);
    }

    virtual void setHomeButtonEnabled(bool enabled)
    {
        NKrossWrapper::w->mNVisitorApp->tRun(NKrossWrapper::w->mNGamma00, (NParam)this, (NParam)enabled);
    }

private:
    ActionBar(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
