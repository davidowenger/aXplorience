#ifndef __FrameLayout_H__
#define __FrameLayout_H__

namespace NSDEVICE
{

class FrameLayout : public ViewGroup
{
friend NSNATIVE::NNoObject;

public:
    FrameLayout(Context* context)
        : ViewGroup(NWrapper::w->mNNoObject->instance<ViewGroup>())
	{
        NWrapper::w->mNVisitorWidgetLayout->tRun(NWrapper::w->mNAlpha00, (NParam)this, (NParam)context);
	}

	virtual ~FrameLayout()
	{
	}

	virtual void setVisibility(int visibility)
    {
        NWrapper::w->mNVisitorWidgetLayout->tRun(NWrapper::w->mNBeta00, (NParam)this, (NParam)visibility);
    }

private:
    FrameLayout(NNoObject* vNNoObject)
        : ViewGroup(NWrapper::w->mNNoObject->instance<ViewGroup>())
    {
    }
};

} // End namespace

#endif
