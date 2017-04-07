#ifndef __StateListDrawable_H__
#define __StateListDrawable_H__

namespace NSDEVICE
{

class StateListDrawable : public DrawableContainer
{
friend NSNATIVE::NKrossFriend;

public:
    StateListDrawable()
        : DrawableContainer(NKrossWrapper::w->mNKrossFriend->instance<DrawableContainer>())
    {
        NKrossWrapper::w->mNVisitorGraphics->tRun(NKrossWrapper::w->mNAlpha00, (NParam)this);
    }

    virtual ~StateListDrawable()
    {
    }

    void addState(vector<int> stateSet, Drawable* drawable)
    {
        long vcKey = NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNBeta01, 0, stateSet.size());
        long vcIndex = 0;

        for (int vcState : stateSet) {
            NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNBeta01, vcKey, vcIndex++, vcState);
        }
        NKrossWrapper::w->mNVisitorGraphics->tRun(NKrossWrapper::w->mNBeta00, (NParam)this, (NParam)vcKey, (NParam)drawable);
    }

private:
    StateListDrawable(NKrossFriend* vNKrossFriend)
        : DrawableContainer(NKrossWrapper::w->mNKrossFriend->instance<DrawableContainer>())
    {
    }
};

} // End namespace

#endif
