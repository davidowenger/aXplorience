#ifndef __Drawable_H__
#define __Drawable_H__

namespace NSDEVICE
{

class Drawable : public Object
{
friend NSNATIVE::NNoObject;

public:
    virtual ~Drawable()
    {
    }

    virtual int getIntrinsicHeight()
    {
        return (int)NWrapper::w->mNVisitorGraphics->tRun(NWrapper::w->mNDzeta00, (NParam)this);
    }

    virtual int getIntrinsicWidth()
    {
        return (int)NWrapper::w->mNVisitorGraphics->tRun(NWrapper::w->mNEta00, (NParam)this);
    }

    virtual void invalidateSelf()
    {
        NWrapper::w->mNVisitorGraphics->tRun(NWrapper::w->mNTheta00, (NParam)this);
    }

private:
    Drawable(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif
