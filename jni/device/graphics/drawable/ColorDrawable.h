#ifndef __ColorDrawable_H__
#define __ColorDrawable_H__

namespace NSDEVICE
{

class ColorDrawable : public Drawable
{
friend NSNATIVE::NNoObject;

public:
	ColorDrawable(int color)
        : Drawable(NWrapper::w->mNNoObject->instance<Drawable>())
	{
        NWrapper::w->mNVisitorGraphics->tRun(NWrapper::w->mNEpsilon00, (NParam)this, (NParam)color);
	}

	virtual ~ColorDrawable()
	{
	}

private:
    ColorDrawable(NNoObject* vNNoObject)
        : Drawable(NWrapper::w->mNNoObject->instance<Drawable>())
    {
    }
};

} // End namespace

#endif
