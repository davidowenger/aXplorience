#ifndef __FragmentTransaction_H__
#define __FragmentTransaction_H__

namespace NSDEVICE
{

class FragmentTransaction : public Object
{
friend NSNATIVE::NNoObject;

public:
    virtual ~FragmentTransaction()
    {
    }

    virtual FragmentTransaction* add(int containerViewId, Fragment* fragment)
    {
        NWrapper::w->mNVisitorAppFragment->tRun(NWrapper::w->mNAlpha03, (NParam)this, (NParam)containerViewId, (NParam)fragment);
        return this;
    }

    virtual FragmentTransaction* addToBackStack(const String& name)
    {
        NWrapper::w->mNVisitorAppFragment->tRun(NWrapper::w->mNBeta03, (NParam)this, NParamBox(NWrapper::w, name).n);
        return this;
    }

    virtual FragmentTransaction* replace(int containerViewId, Fragment* fragment)
    {
        NWrapper::w->mNVisitorAppFragment->tRun(NWrapper::w->mNGamma03, (NParam)this, (NParam)containerViewId, (NParam)fragment);
        return this;
    }

    virtual int commit()
    {
        return (int)NWrapper::w->mNVisitorAppFragment->tRun(NWrapper::w->mNDelta03, (NParam)this);
    }

private:
    FragmentTransaction(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif
