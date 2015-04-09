#ifndef __FragmentManager_H__
#define __FragmentManager_H__

namespace NSDEVICE
{

class FragmentManager : public Object
{
friend NSNATIVE::NNoObject;

public:
    static const int POP_BACK_STACK_INCLUSIVE = 1;

    virtual ~FragmentManager()
    {
    }

    virtual FragmentTransaction* beginTransaction()
    {
        FragmentTransaction* b = NWrapper::w->mNNoObject->pointer<FragmentTransaction>();
        return NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->mNVisitorAppFragment->tRun(NWrapper::w->mNAlpha02, (NParam)this, (NParam)b));
    }

    virtual int getBackStackEntryCount()
    {
        return (nint)NWrapper::w->mNVisitorAppFragment->tRun(NWrapper::w->mNBeta02, (NParam)this);
    }

    virtual void popBackStack()
    {
        NWrapper::w->mNVisitorAppFragment->tRun(NWrapper::w->mNGamma02, (NParam)this);
    }

    virtual void popBackStack(const String& name, int flags)
    {
        NWrapper::w->mNVisitorAppFragment->tRun(NWrapper::w->mNDelta02, (NParam)this, NParamBox(NWrapper::w, name).n, (NParam)flags);
    }

private:
    FragmentManager(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif
