#ifndef __FragmentManager_H__
#define __FragmentManager_H__

namespace NSDEVICE
{

class FragmentManager : public Object
{
friend NSNATIVE::NKrossFriend;

public:
    static const int POP_BACK_STACK_INCLUSIVE = 1;

    virtual ~FragmentManager()
    {
    }

    virtual FragmentTransaction* beginTransaction()
    {
        FragmentTransaction* b = NSNKROSS::w->mNKrossFriend->pointer<FragmentTransaction>();
        return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorAppFragment->tRun(NSNKROSS::w->mNAlpha02, (NParam)this, (NParam)b));
    }

    virtual int getBackStackEntryCount()
    {
        return (nint)NSNKROSS::w->mNVisitorAppFragment->tRun(NSNKROSS::w->mNBeta02, (NParam)this);
    }

    virtual void popBackStack()
    {
        NSNKROSS::w->mNVisitorAppFragment->tRun(NSNKROSS::w->mNGamma02, (NParam)this);
    }

    virtual void popBackStack(const String& name, int flags)
    {
        NSNKROSS::w->mNVisitorAppFragment->tRun(NSNKROSS::w->mNDelta02, (NParam)this, NKrossParam(name).n, (NParam)flags);
    }

private:
    FragmentManager(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
