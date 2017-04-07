#ifndef __FragmentTransaction_H__
#define __FragmentTransaction_H__

namespace NSDEVICE
{

class FragmentTransaction : public Object
{
friend NSNATIVE::NKrossFriend;

public:
    virtual ~FragmentTransaction()
    {
    }

    virtual FragmentTransaction* add(int containerViewId, Fragment* fragment)
    {
        NKrossWrapper::w->mNVisitorAppFragment->tRun(NKrossWrapper::w->mNAlpha03, (NParam)this, (NParam)containerViewId, (NParam)fragment);
        return this;
    }

    virtual FragmentTransaction* addToBackStack(const String& name = "")
    {
        NKrossWrapper::w->mNVisitorAppFragment->tRun(NKrossWrapper::w->mNBeta03, (NParam)this, NKrossParam(name).n);
        return this;
    }

    virtual FragmentTransaction* remove(Fragment* fragment)
    {
        NKrossWrapper::w->mNVisitorAppFragment->tRun(NKrossWrapper::w->mNGamma03, (NParam)this, (NParam)fragment);
        return this;
    }

    virtual FragmentTransaction* replace(int containerViewId, Fragment* fragment)
    {
        NKrossWrapper::w->mNVisitorAppFragment->tRun(NKrossWrapper::w->mNDelta03, (NParam)this, (NParam)containerViewId, (NParam)fragment);
        return this;
    }

    virtual int commit()
    {
        return (int)NKrossWrapper::w->mNVisitorAppFragment->tRun(NKrossWrapper::w->mNEpsilon03, (NParam)this);
    }

private:
    FragmentTransaction(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
