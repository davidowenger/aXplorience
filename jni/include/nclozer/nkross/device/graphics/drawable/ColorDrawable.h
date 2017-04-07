#ifndef __ColorDrawable_H__
#define __ColorDrawable_H__

namespace NSDEVICE
{

class ColorDrawable : public Drawable
{
friend NSNATIVE::NKrossFriend;

public:
    ColorDrawable(int color)
        : Drawable(NKrossWrapper::w->mNKrossFriend->instance<Drawable>())
    {
        NKrossWrapper::w->mNVisitorGraphics->tRun(NKrossWrapper::w->mNEpsilon00, (NParam)this, (NParam)color);
    }

    virtual ~ColorDrawable()
    {
    }

private:
    ColorDrawable(NKrossFriend* vNKrossFriend)
        : Drawable(NKrossWrapper::w->mNKrossFriend->instance<Drawable>())
    {
    }
};

} // End namespace

#endif
