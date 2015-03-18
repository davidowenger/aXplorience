#ifndef __VIEWGROUP_H__
#define __VIEWGROUP_H__

namespace NSDEVICE
{

class ViewGroup : public View
{
friend NSNATIVE::NNoObject;

public:
    class LayoutParams : public Object
    {
    friend NSNATIVE::NNoObject;

    public:
        static const int MATCH_PARENT = -1;
        static const int WRAP_CONTENT = -2;

        LayoutParams(int width, int height)
        {
            NWrapper::getInstance()->mNVisitorViewViewGroup->tRun(NWrapper::getInstance()->mNAlpha03, (NParam)this);
        }

        virtual ~LayoutParams()
        {
        }

    private:
        LayoutParams(NNoObject* vNNoObject)
        {
        }
    };

    class MarginLayoutParams : public ViewGroup::LayoutParams
    {
    friend NSNATIVE::NNoObject;

    public:
        MarginLayoutParams(int width, int height)
            : ViewGroup::LayoutParams(NWrapper::w->mNNoObject->instance<ViewGroup::LayoutParams>())
        {
            NWrapper::getInstance()->mNVisitorViewViewGroup->tRun(NWrapper::getInstance()->mNBeta03, (NParam)this);
        }

        virtual ~MarginLayoutParams()
        {
        }

        virtual void setMargins(int left, int top, int right, int bottom)
        {
            NWrapper::getInstance()->mNVisitorViewViewGroup->tRun(NWrapper::getInstance()->mNGamma03, (NParam)this, (NParam)left, (NParam)top, (NParam)right, (NParam)bottom);
        }

    private:
        MarginLayoutParams(NNoObject* vNNoObject)
            : ViewGroup::LayoutParams(NWrapper::w->mNNoObject->instance<ViewGroup::LayoutParams>())
        {
        }
    };

	virtual ~ViewGroup()
	{
	}

    virtual void addView(View* view)
    {
        NWrapper::getInstance()->mNVisitorViewViewGroup->tRun(NWrapper::getInstance()->mNAlpha00, (NParam)this, (NParam)view);
    }

    virtual void removeAllViews()
    {
        NWrapper::getInstance()->mNVisitorViewViewGroup->tRun(NWrapper::getInstance()->mNBeta00, (NParam)this);
    }

	virtual void requestLayout()
    {
        NWrapper::getInstance()->mNVisitorViewViewGroup->tRun(NWrapper::getInstance()->mNGamma00, (NParam)this);
    }

private:
    ViewGroup(NNoObject* vNNoObject)
        : View(NWrapper::w->mNNoObject->instance<View>())
    {
    }
};

} // End namespace

#endif
