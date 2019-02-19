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
            : ViewGroup::MarginLayoutParams(NSNKROSS::w->mNKrossFriend->instance<ViewGroup::MarginLayoutParams>())
        {
            NSNKROSS::w->mNVisitorWidgetLayout->tRun(NSNKROSS::w->mNAlpha01, (NParam)this, (NParam)width, (NParam)height);
        }

        LayoutParams(int width, int height, float weight)
            : ViewGroup::MarginLayoutParams(NSNKROSS::w->mNKrossFriend->instance<ViewGroup::MarginLayoutParams>())
        {
            ndouble vcWeight = weight;
            NSNKROSS::w->mNVisitorWidgetLayout->tRun(NSNKROSS::w->mNBeta01, (NParam)this, (NParam)width, (NParam)height, *reinterpret_cast<nlong*>(&vcWeight));
        }

        virtual ~LayoutParams()
        {
        }

    private:
        LayoutParams(NKrossFriend* vNKrossFriend)
            : ViewGroup::MarginLayoutParams(NSNKROSS::w->mNKrossFriend->instance<ViewGroup::MarginLayoutParams>())
        {
        }
    };

    LinearLayout(Context* context)
        : ViewGroup(NSNKROSS::w->mNKrossFriend->instance<ViewGroup>())
    {
        NSNKROSS::w->mNVisitorWidgetLayout->tRun(NSNKROSS::w->mNGamma00, (NParam)this, (NParam)context);
    }

    virtual ~LinearLayout()
    {
    }

    virtual void invalidate()
    {
        NSNKROSS::w->mNVisitorWidgetLayout->tRun(NSNKROSS::w->mNDelta00, (NParam)this);
    }

    virtual void setGravity(int gravity)
    {
        NSNKROSS::w->mNVisitorWidgetLayout->tRun(NSNKROSS::w->mNEpsilon00, (NParam)this, (NParam)gravity);
    }

    virtual void requestLayout()
    {
        NSNKROSS::w->mNVisitorWidgetLayout->tRun(NSNKROSS::w->mNDzeta00, (NParam)this);
    }

    virtual void setOrientation(int orientation)
    {
        NSNKROSS::w->mNVisitorWidgetLayout->tRun(NSNKROSS::w->mNEta00, (NParam)this, (NParam)orientation);
    }

private:
    LinearLayout(NKrossFriend* vNKrossFriend)
        : ViewGroup(NSNKROSS::w->mNKrossFriend->instance<ViewGroup>())
    {
    }
};

} // End namespace

#endif
