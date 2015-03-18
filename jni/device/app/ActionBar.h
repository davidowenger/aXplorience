#ifndef __ActionBar_H__
#define __ActionBar_H__

namespace NSDEVICE
{

class ActionBar : public Object
{
friend NSNATIVE::NNoObject;

public:
    static const int POP_BACK_STACK_INCLUSIVE = 1;

    virtual ~ActionBar()
    {
    }

    virtual void setIcon(int resId)
    {
        NWrapper::w->mNVisitorApp->tRun(NWrapper::w->mNAlpha00, (NParam)this, (NParam)resId);
    }

    virtual void setDisplayHomeAsUpEnabled(bool showHomeAsUp)
    {
        NWrapper::w->mNVisitorApp->tRun(NWrapper::w->mNBeta00, (NParam)this, (NParam)showHomeAsUp);
    }

    virtual void setHomeButtonEnabled(bool enabled)
    {
        NWrapper::w->mNVisitorApp->tRun(NWrapper::w->mNGamma00, (NParam)this, (NParam)enabled);
    }

private:
    ActionBar(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif
