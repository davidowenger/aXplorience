#ifndef __ScrollView_H__
#define __ScrollView_H__

namespace NSDEVICE
{

class ScrollView : public FrameLayout
{
friend NSNATIVE::NNoObject;

public:
    ScrollView(Context* context)
        : FrameLayout(NWrapper::w->mNNoObject->instance<FrameLayout>())
    {
        NWrapper::w->mNVisitorWidgetView->tRun(NWrapper::w->mNDzeta00, (NParam)this, (NParam)context);
    }

    virtual ~ScrollView()
    {
    }

    void addView(View* view)
    {
        NWrapper::w->mNVisitorWidgetView->tRun(NWrapper::w->mNEta00, (NParam)this, (NParam)view);
    }

    void requestLayout()
    {
        NWrapper::w->mNVisitorWidgetView->tRun(NWrapper::w->mNTheta00, (NParam)this);
    }

private:
    ScrollView(NNoObject* vNNoObject)
        : FrameLayout(NWrapper::w->mNNoObject->instance<FrameLayout>())
    {
    }
};

} // End namespace

#endif
