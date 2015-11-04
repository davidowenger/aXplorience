#ifndef __StateListDrawable_H__
#define __StateListDrawable_H__

namespace NSDEVICE
{

class StateListDrawable : public DrawableContainer
{
friend NSNATIVE::NKrossFriend;

public:
    StateListDrawable()
        : DrawableContainer(NSNKROSS::w->mNKrossFriend->instance<DrawableContainer>())
    {
        NSNKROSS::w->mNVisitorGraphics->tRun(NSNKROSS::w->mNAlpha00, (NParam)this);
    }

    virtual ~StateListDrawable()
    {
    }

    void addState(vector<int> stateSet, Drawable* drawable)
    {
        long vcKey = NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNBeta01, 0, stateSet.size());
        long vcIndex = 0;

        for (int vcState : stateSet) {
            NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNBeta01, vcKey, vcIndex++, vcState);
        }
        NSNKROSS::w->mNVisitorGraphics->tRun(NSNKROSS::w->mNBeta00, (NParam)this, (NParam)vcKey, (NParam)drawable);
    }

private:
    StateListDrawable(NKrossFriend* vNKrossFriend)
        : DrawableContainer(NSNKROSS::w->mNKrossFriend->instance<DrawableContainer>())
    {
    }
};

} // End namespace

#endif
