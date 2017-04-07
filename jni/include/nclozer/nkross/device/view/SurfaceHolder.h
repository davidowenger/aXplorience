#ifndef __SurfaceHolder_H__
#define __SurfaceHolder_H__

namespace NSDEVICE
{

class SurfaceHolder
{
friend NSNATIVE::NKrossFriend;

public:
    class Callback
    {
    friend NSNATIVE::NKrossFriend;

    public:
        virtual ~Callback()
        {
            NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNDelta00, (NParam)this);
        }

        virtual void surfaceChanged(SurfaceHolder* holder, int format, int width, int height) = 0;
        virtual void surfaceCreated(SurfaceHolder* holder) = 0;
        virtual void surfaceDestroyed(SurfaceHolder* holder) = 0;

    protected:
        Callback()
        {
            NKrossWrapper::w->mNVisitorView->tRun(NKrossWrapper::w->mNOmicron00, (NParam)this);
        }

    private:
        Callback(NKrossFriend* vNKrossFriend)
        {
        }
    };

    class Callback2 : public SurfaceHolder::Callback
    {
    friend NSNATIVE::NKrossFriend;

    public:
        virtual ~Callback2()
        {
        }

        virtual void surfaceRedrawNeeded(SurfaceHolder* holder) = 0;

    protected:
        Callback2()
        {
            NKrossWrapper::w->mNVisitorView->tRun(NKrossWrapper::w->mNPi00, (NParam)this);
        }

    private:
        Callback2(NKrossFriend* vNKrossFriend)
        {
        }
    };

    virtual ~SurfaceHolder()
    {
        NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNDelta00, (NParam)this);
    }

    void addCallback(SurfaceHolder::Callback* callback)
    {
        NKrossWrapper::w->mNVisitorView->tRun(NKrossWrapper::w->mNRho00, (NParam)this, (NParam)callback);
    }

    Surface* getSurface()
    {
        Surface* b = NKrossWrapper::w->mNKrossFriend->pointer<Surface>();
        return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorView->tRun(NKrossWrapper::w->mNSigma00, (NParam)this, (NParam)b));
    }

    void removeCallback(SurfaceHolder::Callback* callback)
    {
        NKrossWrapper::w->mNVisitorView->tRun(NKrossWrapper::w->mNTau00, (NParam)this, (NParam)callback);
    }

    void setKeepScreenOn(bool screenOn)
    {
        NKrossWrapper::w->mNVisitorView->tRun(NKrossWrapper::w->mNUpsilon00, (NParam)this, (NParam)screenOn);
    }

private:
    SurfaceHolder(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
