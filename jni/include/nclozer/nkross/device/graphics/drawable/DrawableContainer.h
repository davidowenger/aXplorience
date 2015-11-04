#ifndef __DrawableContainer_H__
#define __DrawableContainer_H__

namespace NSDEVICE
{

class DrawableContainer : public Drawable
{
friend NSNATIVE::NKrossFriend;

public:
    virtual ~DrawableContainer()
    {
    }

private:
    DrawableContainer(NKrossFriend* vNKrossFriend)
        : Drawable(NSNKROSS::w->mNKrossFriend->instance<Drawable>())
    {
    }
};

} // End namespace

#endif
