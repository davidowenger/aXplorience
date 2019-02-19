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
        NSNKROSS::w->mNVisitorAppFragment->tRun(NSNKROSS::w->mNAlpha03, (NParam)this, (NParam)containerViewId, (NParam)fragment);
        return this;
    }

    virtual FragmentTransaction* addToBackStack(const String& name = "")
    {
        NSNKROSS::w->mNVisitorAppFragment->tRun(NSNKROSS::w->mNBeta03, (NParam)this, NKrossParam(name).n);
        return this;
    }

    virtual FragmentTransaction* remove(Fragment* fragment)
    {
        NSNKROSS::w->mNVisitorAppFragment->tRun(NSNKROSS::w->mNGamma03, (NParam)this, (NParam)fragment);
        return this;
    }

    virtual FragmentTransaction* replace(int containerViewId, Fragment* fragment)
    {
        NSNKROSS::w->mNVisitorAppFragment->tRun(NSNKROSS::w->mNDelta03, (NParam)this, (NParam)containerViewId, (NParam)fragment);
        return this;
    }

    virtual int commit()
    {
        return (int)NSNKROSS::w->mNVisitorAppFragment->tRun(NSNKROSS::w->mNEpsilon03, (NParam)this);
    }

private:
    FragmentTransaction(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
