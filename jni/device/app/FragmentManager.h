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

    virtual void popBackStack()
    {
        NWrapper::w->mNVisitorAppFragment->tRun(NWrapper::w->mNAlpha02, (NParam)this);
    }

    virtual void popBackStack(const String& name, int flags)
    {
        NWrapper::w->mNVisitorAppFragment->tRun(NWrapper::w->mNBeta02, (NParam)this, NParamBox(NWrapper::w, name).n, (NParam)flags);
    }

    virtual FragmentTransaction* beginTransaction()
    {
        FragmentTransaction* vFragmentTransaction = NWrapper::w->mNNoObject->pointer<FragmentTransaction>();
        bool error = NWrapper::w->mNVisitorAppFragment->tRun(NWrapper::w->mNGamma02, (NParam)this, (NParam)vFragmentTransaction);

        if (error) {
            delete vFragmentTransaction;
            vFragmentTransaction = nullptr;
        }
        return vFragmentTransaction;
    }

private:
    FragmentManager(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif
