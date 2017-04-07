#ifndef __Window_H__
#define __Window_H__

namespace NSDEVICE
{

class Window : public Object
{
friend NSNATIVE::NKrossFriend;

public:
    virtual ~Window()
    {
    }

    void setAttributes(WindowManager::LayoutParams* a)
    {
        NKrossWrapper::w->mNVisitorView->tRun(NKrossWrapper::w->mNAlpha00, (NParam)this, (NParam)a);
    }

    void addFlags(int flags)
    {
        NKrossWrapper::w->mNVisitorView->tRun(NKrossWrapper::w->mNAlpha00, (NParam)this, (NParam)flags);
    }

    void setFlags(int flags, int mask)
    {
        NKrossWrapper::w->mNVisitorView->tRun(NKrossWrapper::w->mNAlpha00, (NParam)this, (NParam)flags, (NParam)mask);
    }

    void setFormat(int format)
    {
        NKrossWrapper::w->mNVisitorView->tRun(NKrossWrapper::w->mNAlpha00, (NParam)this, (NParam)format);
    }

    void takeSurface(SurfaceHolder::Callback2* callback)
    {
        NKrossWrapper::w->mNVisitorView->tRun(NKrossWrapper::w->mNAlpha00, (NParam)this, (NParam)callback);
    }

private:
    Window(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
