#ifndef __LINEARLAYOUT_H__
#define __LINEARLAYOUT_H__

namespace NSDEVICE
{

class LinearLayout : public ViewGroup
{
friend NSNATIVE::NNoObject;

public:
    class LayoutParams : public ViewGroup::MarginLayoutParams
    {
    friend NSNATIVE::NNoObject;

    public:
        LayoutParams(int width, int height)
            : ViewGroup::MarginLayoutParams(NWrapper::w->mNNoObject->instance<ViewGroup::MarginLayoutParams>())
        {
            NWrapper::w->mNVisitorWidgetLayout->tRun(NWrapper::w->mNAlpha01, (NParam)this, (NParam)width, (NParam)height);
        }

        LayoutParams(int width, int height, float weight)
            : ViewGroup::MarginLayoutParams(NWrapper::w->mNNoObject->instance<ViewGroup::MarginLayoutParams>())
        {
            double vcWeight = weight;
            NWrapper::w->mNVisitorWidgetLayout->tRun(NWrapper::w->mNBeta01, (NParam)this, (NParam)width, (NParam)height, (NParam)*reinterpret_cast<long*>(&vcWeight));
        }

        virtual ~LayoutParams()
        {
        }

    private:
        LayoutParams(NNoObject* vNNoObject)
            : ViewGroup::MarginLayoutParams(NWrapper::w->mNNoObject->instance<ViewGroup::MarginLayoutParams>())
        {
        }
    };

	LinearLayout(Context* context)
        : ViewGroup(NWrapper::w->mNNoObject->instance<ViewGroup>())
	{
		NWrapper::w->mNVisitorWidgetLayout->tRun(NWrapper::w->mNGamma00, (NParam)this, (NParam)context);
	}

	virtual ~LinearLayout()
	{
	}

	virtual void invalidate()
    {
        NWrapper::w->mNVisitorWidgetLayout->tRun(NWrapper::w->mNDelta00, (NParam)this);
    }

    virtual void setGravity(int gravity)
    {
        NWrapper::w->mNVisitorWidgetLayout->tRun(NWrapper::w->mNEpsilon00, (NParam)this, (NParam)gravity);
    }

	virtual void requestLayout()
    {
        NWrapper::w->mNVisitorWidgetLayout->tRun(NWrapper::w->mNDzeta00, (NParam)this);
    }

	virtual void setOrientation(int orientation)
    {
        NWrapper::w->mNVisitorWidgetLayout->tRun(NWrapper::w->mNEta00, (NParam)this, (NParam)orientation);
    }

private:
	LinearLayout(NNoObject* vNNoObject)
        : ViewGroup(NWrapper::w->mNNoObject->instance<ViewGroup>())
    {
    }
};

} // End namespace

#endif
