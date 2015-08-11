#ifndef __DrawableContainer_H__
#define __DrawableContainer_H__

namespace NSDEVICE
{

class DrawableContainer : public Drawable
{
friend NSNATIVE::NNoObject;

public:
    virtual ~DrawableContainer()
    {
    }

private:
    DrawableContainer(NNoObject* vNNoObject)
        : Drawable(NWrapper::w->mNNoObject->instance<Drawable>())
    {
    }
};

} // End namespace

#endif
