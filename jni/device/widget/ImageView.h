#ifndef __ImageView_H__
#define __ImageView_H__

namespace NSDEVICE
{

class ImageView : public View
{
friend NSNATIVE::NNoObject;

public:
    enum ScaleType { CENTER, CENTER_CROP, CENTER_INSIDE, FIT_CENTER, FIT_END, FIT_START, FIT_XY, MATRIX };

    ImageView(Context* context)
        : View(NWrapper::w->mNNoObject->instance<View>())
    {
        NWrapper::w->mNVisitorWidgetView->tRun(NWrapper::w->mNGamma00, (NParam)this, (NParam)context);
    }

    virtual ~ImageView()
    {
    }

    void setImageDrawable(Drawable* drawable)
    {
        NWrapper::w->mNVisitorWidgetView->tRun(NWrapper::w->mNDelta00, (NParam)this, (NParam)drawable);
    }

    void setScaleType(ScaleType scaleType)
    {
        NWrapper::w->mNVisitorWidgetView->tRun(NWrapper::w->mNEpsilon00, (NParam)this, (NParam)scaleType);
    }

private:
    ImageView(NNoObject* vNNoObject)
        : View(NWrapper::w->mNNoObject->instance<View>())
    {
    }
};

} // End namespace

#endif
