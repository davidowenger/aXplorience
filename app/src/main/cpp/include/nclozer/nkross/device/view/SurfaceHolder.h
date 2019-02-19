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
            NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNDelta00, (NParam)this);
        }

        virtual void surfaceChanged(SurfaceHolder* holder, int format, int width, int height) = 0;
        virtual void surfaceCreated(SurfaceHolder* holder) = 0;
        virtual void surfaceDestroyed(SurfaceHolder* holder) = 0;

    protected:
        Callback()
        {
            NSNKROSS::w->mNVisitorView->tRun(NSNKROSS::w->mNOmicron00, (NParam)this);
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
            NSNKROSS::w->mNVisitorView->tRun(NSNKROSS::w->mNPi00, (NParam)this);
        }

    private:
        Callback2(NKrossFriend* vNKrossFriend)
        {
        }
    };

    virtual ~SurfaceHolder()
    {
        NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNDelta00, (NParam)this);
    }

    void addCallback(SurfaceHolder::Callback* callback)
    {
        NSNKROSS::w->mNVisitorView->tRun(NSNKROSS::w->mNRho00, (NParam)this, (NParam)callback);
    }

    Surface* getSurface()
    {
        Surface* b = NSNKROSS::w->mNKrossFriend->pointer<Surface>();
        return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorView->tRun(NSNKROSS::w->mNSigma00, (NParam)this, (NParam)b));
    }

    void removeCallback(SurfaceHolder::Callback* callback)
    {
        NSNKROSS::w->mNVisitorView->tRun(NSNKROSS::w->mNTau00, (NParam)this, (NParam)callback);
    }

    void setKeepScreenOn(bool screenOn)
    {
        NSNKROSS::w->mNVisitorView->tRun(NSNKROSS::w->mNUpsilon00, (NParam)this, (NParam)screenOn);
    }

private:
    SurfaceHolder(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
