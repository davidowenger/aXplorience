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
        FragmentTransaction* b = NKrossWrapper::w->mNKrossFriend->pointer<FragmentTransaction>();
        return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorAppFragment->tRun(NKrossWrapper::w->mNAlpha02, (NParam)this, (NParam)b));
    }

    virtual int getBackStackEntryCount()
    {
        return (nint)NKrossWrapper::w->mNVisitorAppFragment->tRun(NKrossWrapper::w->mNBeta02, (NParam)this);
    }

    virtual void popBackStack()
    {
        NKrossWrapper::w->mNVisitorAppFragment->tRun(NKrossWrapper::w->mNGamma02, (NParam)this);
    }

    virtual void popBackStack(const String& name, int flags)
    {
        NKrossWrapper::w->mNVisitorAppFragment->tRun(NKrossWrapper::w->mNDelta02, (NParam)this, NKrossParam(name).n, (NParam)flags);
    }

private:
    FragmentManager(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
