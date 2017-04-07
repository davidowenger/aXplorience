#ifndef __FrameLayout_H__
#define __FrameLayout_H__

namespace NSDEVICE
{

class FrameLayout : public ViewGroup
{
friend NSNATIVE::NKrossFriend;

public:
    FrameLayout(Context* context)
        : ViewGroup(NKrossWrapper::w->mNKrossFriend->instance<ViewGroup>())
    {
        NKrossWrapper::w->mNVisitorWidgetLayout->tRun(NKrossWrapper::w->mNAlpha00, (NParam)this, (NParam)context);
    }

    virtual ~FrameLayout()
    {
    }

    virtual void setVisibility(int visibility)
    {
        NKrossWrapper::w->mNVisitorWidgetLayout->tRun(NKrossWrapper::w->mNBeta00, (NParam)this, (NParam)visibility);
    }

private:
    FrameLayout(NKrossFriend* vNKrossFriend)
        : ViewGroup(NKrossWrapper::w->mNKrossFriend->instance<ViewGroup>())
    {
    }
};

} // End namespace

#endif
