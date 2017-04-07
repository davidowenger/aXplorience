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
        Looper* b = NKrossWrapper::w->mNKrossFriend->pointer<Looper>();
        return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorOS->tRun(NKrossWrapper::w->mNGamma00, (NParam)b));
    }

    static void loop()
    {
        NKrossWrapper::w->mNVisitorOS->tRun(NKrossWrapper::w->mNDelta00);
    }

    static Looper* myLooper()
    {
        Looper* b = NKrossWrapper::w->mNKrossFriend->pointer<Looper>();
        return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorOS->tRun(NKrossWrapper::w->mNEpsilon00, (NParam)b));
    }

    static void prepare()
    {
        NKrossWrapper::w->mNVisitorOS->tRun(NKrossWrapper::w->mNBeta00);
    }

    virtual ~Looper()
    {
    }

    void quit()
    {
        NKrossWrapper::w->mNVisitorOS->tRun(NKrossWrapper::w->mNDzeta00, (NParam)this);
    }

    void quitSafely()
    {
        NKrossWrapper::w->mNVisitorOS->tRun(NKrossWrapper::w->mNEta00, (NParam)this);
    }

private:
    Looper(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
