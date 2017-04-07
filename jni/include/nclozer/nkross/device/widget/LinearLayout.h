#ifndef __LINEARLAYOUT_H__
#define __LINEARLAYOUT_H__

namespace NSDEVICE
{

class LinearLayout : public ViewGroup
{
friend NSNATIVE::NKrossFriend;

public:
    static const int HORIZONTAL = 0;
    static const int VERTICAL = HORIZONTAL + 1;

    static const int SHOW_DIVIDER_NONE = 0;
    static const int SHOW_DIVIDER_BEGINNING = SHOW_DIVIDER_NONE + 1;
    static const int SHOW_DIVIDER_MIDDLE = SHOW_DIVIDER_BEGINNING + 1;
    static const int SHOW_DIVIDER_END = SHOW_DIVIDER_MIDDLE + 1;

    class LayoutParams : public ViewGroup::MarginLayoutParams
    {
    friend NSNATIVE::NKrossFriend;

    public:
        LayoutParams(int width, int height)
            : ViewGroup::MarginLayoutParams(NKrossWrapper::w->mNKrossFriend->instance<ViewGroup::MarginLayoutParams>())
        {
            NKrossWrapper::w->mNVisitorWidgetLayout->tRun(NKrossWrapper::w->mNAlpha01, (NParam)this, (NParam)width, (NParam)height);
        }

        LayoutParams(int width, int height, float weight)
            : ViewGroup::MarginLayoutParams(NKrossWrapper::w->mNKrossFriend->instance<ViewGroup::MarginLayoutParams>())
        {
            ndouble vcWeight = weight;
            NKrossWrapper::w->mNVisitorWidgetLayout->tRun(NKrossWrapper::w->mNBeta01, (NParam)this, (NParam)width, (NParam)height, *reinterpret_cast<nlong*>(&vcWeight));
        }

        virtual ~LayoutParams()
        {
        }

    private:
        LayoutParams(NKrossFriend* vNKrossFriend)
            : ViewGroup::MarginLayoutParams(NKrossWrapper::w->mNKrossFriend->instance<ViewGroup::MarginLayoutParams>())
        {
        }
    };

    LinearLayout(Context* context)
        : ViewGroup(NKrossWrapper::w->mNKrossFriend->instance<ViewGroup>())
    {
        NKrossWrapper::w->mNVisitorWidgetLayout->tRun(NKrossWrapper::w->mNGamma00, (NParam)this, (NParam)context);
    }

    virtual ~LinearLayout()
    {
    }

    virtual void invalidate()
    {
        NKrossWrapper::w->mNVisitorWidgetLayout->tRun(NKrossWrapper::w->mNDelta00, (NParam)this);
    }

    virtual void setGravity(int gravity)
    {
        NKrossWrapper::w->mNVisitorWidgetLayout->tRun(NKrossWrapper::w->mNEpsilon00, (NParam)this, (NParam)gravity);
    }

    virtual void requestLayout()
    {
        NKrossWrapper::w->mNVisitorWidgetLayout->tRun(NKrossWrapper::w->mNDzeta00, (NParam)this);
    }

    virtual void setOrientation(int orientation)
    {
        NKrossWrapper::w->mNVisitorWidgetLayout->tRun(NKrossWrapper::w->mNEta00, (NParam)this, (NParam)orientation);
    }

private:
    LinearLayout(NKrossFriend* vNKrossFriend)
        : ViewGroup(NKrossWrapper::w->mNKrossFriend->instance<ViewGroup>())
    {
    }
};

} // End namespace

#endif
