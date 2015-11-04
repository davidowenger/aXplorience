#ifndef __Looper_H__
#define __Looper_H__

namespace NSDEVICE
{

class Looper : public Object
{
friend NSNATIVE::NKrossFriend;

public:
    static Looper* getMainLooper()
    {
        Looper* b = NSNKROSS::w->mNKrossFriend->pointer<Looper>();
        return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorOS->tRun(NSNKROSS::w->mNGamma00, (NParam)b));
    }

    static void loop()
    {
        NSNKROSS::w->mNVisitorOS->tRun(NSNKROSS::w->mNDelta00);
    }

    static Looper* myLooper()
    {
        Looper* b = NSNKROSS::w->mNKrossFriend->pointer<Looper>();
        return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorOS->tRun(NSNKROSS::w->mNEpsilon00, (NParam)b));
    }

    static void prepare()
    {
        NSNKROSS::w->mNVisitorOS->tRun(NSNKROSS::w->mNBeta00);
    }

    virtual ~Looper()
    {
    }

    void quit()
    {
        NSNKROSS::w->mNVisitorOS->tRun(NSNKROSS::w->mNDzeta00, (NParam)this);
    }

    void quitSafely()
    {
        NSNKROSS::w->mNVisitorOS->tRun(NSNKROSS::w->mNEta00, (NParam)this);
    }

private:
    Looper(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
