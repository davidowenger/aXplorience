#ifndef __Drawable_H__
#define __Drawable_H__

namespace NSDEVICE
{

class Drawable : public Object
{
friend NSNATIVE::NKrossFriend;

public:
    virtual ~Drawable()
    {
    }

    virtual int getIntrinsicHeight()
    {
        return (int)NKrossWrapper::w->mNVisitorGraphics->tRun(NKrossWrapper::w->mNDzeta00, (NParam)this);
    }

    virtual int getIntrinsicWidth()
    {
        return (int)NKrossWrapper::w->mNVisitorGraphics->tRun(NKrossWrapper::w->mNEta00, (NParam)this);
    }

    virtual void invalidateSelf()
    {
        NKrossWrapper::w->mNVisitorGraphics->tRun(NKrossWrapper::w->mNTheta00, (NParam)this);
    }

private:
    Drawable(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
