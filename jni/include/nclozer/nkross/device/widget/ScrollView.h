#ifndef __ScrollView_H__
#define __ScrollView_H__

namespace NSDEVICE
{

class ScrollView : public FrameLayout
{
friend NSNATIVE::NKrossFriend;

public:
    ScrollView(Context* context)
        : FrameLayout(NKrossWrapper::w->mNKrossFriend->instance<FrameLayout>())
    {
        NKrossWrapper::w->mNVisitorWidgetView->tRun(NKrossWrapper::w->mNDzeta00, (NParam)this, (NParam)context);
    }

    virtual ~ScrollView()
    {
    }

    virtual void addView(View* view)
    {
        NKrossWrapper::w->mNVisitorWidgetView->tRun(NKrossWrapper::w->mNEta00, (NParam)this, (NParam)view);
    }

    virtual void requestLayout()
    {
        NKrossWrapper::w->mNVisitorWidgetView->tRun(NKrossWrapper::w->mNTheta00, (NParam)this);
    }

    virtual void setFillViewport(bool fillViewport)
    {
        NKrossWrapper::w->mNVisitorWidgetView->tRun(NKrossWrapper::w->mNAlpha00, (NParam)this, (NParam)fillViewport);
    }

private:
    ScrollView(NKrossFriend* vNKrossFriend)
        : FrameLayout(NKrossWrapper::w->mNKrossFriend->instance<FrameLayout>())
    {
    }
};

} // End namespace

#endif
