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
        return (int)NSNKROSS::w->mNVisitorGraphics->tRun(NSNKROSS::w->mNDzeta00, (NParam)this);
    }

    virtual int getIntrinsicWidth()
    {
        return (int)NSNKROSS::w->mNVisitorGraphics->tRun(NSNKROSS::w->mNEta00, (NParam)this);
    }

    virtual void invalidateSelf()
    {
        NSNKROSS::w->mNVisitorGraphics->tRun(NSNKROSS::w->mNTheta00, (NParam)this);
    }

private:
    Drawable(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
