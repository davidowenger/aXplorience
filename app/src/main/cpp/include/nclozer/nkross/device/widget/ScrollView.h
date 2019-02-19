#ifndef __ScrollView_H__
#define __ScrollView_H__

namespace NSDEVICE
{

class ScrollView : public FrameLayout
{
friend NSNATIVE::NKrossFriend;

public:
    ScrollView(Context* context)
        : FrameLayout(NSNKROSS::w->mNKrossFriend->instance<FrameLayout>())
    {
        NSNKROSS::w->mNVisitorWidgetView->tRun(NSNKROSS::w->mNDzeta00, (NParam)this, (NParam)context);
    }

    virtual ~ScrollView()
    {
    }

    void addView(View* view)
    {
        NSNKROSS::w->mNVisitorWidgetView->tRun(NSNKROSS::w->mNEta00, (NParam)this, (NParam)view);
    }

    void requestLayout()
    {
        NSNKROSS::w->mNVisitorWidgetView->tRun(NSNKROSS::w->mNTheta00, (NParam)this);
    }

private:
    ScrollView(NKrossFriend* vNKrossFriend)
        : FrameLayout(NSNKROSS::w->mNKrossFriend->instance<FrameLayout>())
    {
    }
};

} // End namespace

#endif
