#ifndef __ImageView_H__
#define __ImageView_H__

namespace NSDEVICE
{

class ImageView : public View
{
friend NSNATIVE::NKrossFriend;

public:
    enum ScaleType { CENTER, CENTER_CROP, CENTER_INSIDE, FIT_CENTER, FIT_END, FIT_START, FIT_XY, MATRIX };

    ImageView(Context* context)
        : View(NSNKROSS::w->mNKrossFriend->instance<View>())
    {
        NSNKROSS::w->mNVisitorWidgetView->tRun(NSNKROSS::w->mNGamma00, (NParam)this, (NParam)context);
    }

    virtual ~ImageView()
    {
    }

    void setImageDrawable(Drawable* drawable)
    {
        NSNKROSS::w->mNVisitorWidgetView->tRun(NSNKROSS::w->mNDelta00, (NParam)this, (NParam)drawable);
    }

    void setScaleType(ScaleType scaleType)
    {
        NSNKROSS::w->mNVisitorWidgetView->tRun(NSNKROSS::w->mNEpsilon00, (NParam)this, (NParam)scaleType);
    }

private:
    ImageView(NKrossFriend* vNKrossFriend)
        : View(NSNKROSS::w->mNKrossFriend->instance<View>())
    {
    }
};

} // End namespace

#endif
