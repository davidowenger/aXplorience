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
        : View(NKrossWrapper::w->mNKrossFriend->instance<View>())
    {
        NKrossWrapper::w->mNVisitorWidgetView->tRun(NKrossWrapper::w->mNGamma00, (NParam)this, (NParam)context);
    }

    virtual ~ImageView()
    {
    }

    void setImageDrawable(Drawable* drawable)
    {
        NKrossWrapper::w->mNVisitorWidgetView->tRun(NKrossWrapper::w->mNDelta00, (NParam)this, (NParam)drawable);
    }

    void setScaleType(ScaleType scaleType)
    {
        NKrossWrapper::w->mNVisitorWidgetView->tRun(NKrossWrapper::w->mNEpsilon00, (NParam)this, (NParam)scaleType);
    }

private:
    ImageView(NKrossFriend* vNKrossFriend)
        : View(NKrossWrapper::w->mNKrossFriend->instance<View>())
    {
    }
};

} // End namespace

#endif
