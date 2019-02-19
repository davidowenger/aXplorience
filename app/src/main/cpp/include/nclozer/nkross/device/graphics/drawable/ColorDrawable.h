#ifndef __ColorDrawable_H__
#define __ColorDrawable_H__

namespace NSDEVICE
{

class ColorDrawable : public Drawable
{
friend NSNATIVE::NKrossFriend;

public:
    ColorDrawable(int color)
        : Drawable(NSNKROSS::w->mNKrossFriend->instance<Drawable>())
    {
        NSNKROSS::w->mNVisitorGraphics->tRun(NSNKROSS::w->mNEpsilon00, (NParam)this, (NParam)color);
    }

    virtual ~ColorDrawable()
    {
    }

private:
    ColorDrawable(NKrossFriend* vNKrossFriend)
        : Drawable(NSNKROSS::w->mNKrossFriend->instance<Drawable>())
    {
    }
};

} // End namespace

#endif
