#ifndef __FrameLayout_H__
#define __FrameLayout_H__

namespace NSDEVICE
{

class FrameLayout : public ViewGroup
{
friend NSNATIVE::NKrossFriend;

public:
    FrameLayout(Context* context)
        : ViewGroup(NSNKROSS::w->mNKrossFriend->instance<ViewGroup>())
    {
        NSNKROSS::w->mNVisitorWidgetLayout->tRun(NSNKROSS::w->mNAlpha00, (NParam)this, (NParam)context);
    }

    virtual ~FrameLayout()
    {
    }

    virtual void setVisibility(int visibility)
    {
        NSNKROSS::w->mNVisitorWidgetLayout->tRun(NSNKROSS::w->mNBeta00, (NParam)this, (NParam)visibility);
    }

private:
    FrameLayout(NKrossFriend* vNKrossFriend)
        : ViewGroup(NSNKROSS::w->mNKrossFriend->instance<ViewGroup>())
    {
    }
};

} // End namespace

#endif
