#ifndef __StateListDrawable_H__
#define __StateListDrawable_H__

namespace NSDEVICE
{

class StateListDrawable : public DrawableContainer
{
friend NSNATIVE::NNoObject;

public:
    StateListDrawable()
        : DrawableContainer(NWrapper::w->mNNoObject->instance<DrawableContainer>())
	{
        NWrapper::w->mNVisitorGraphics->tRun(NWrapper::w->mNAlpha00, (NParam)this);
	}

    virtual ~StateListDrawable()
    {
    }

    void addState(vector<int> stateSet, Drawable* drawable)
    {
        long vcKey = NWrapper::w->nFrame->tRun(NWrapper::w->mNBeta01, 0, stateSet.size());
        long vcIndex = 0;

        for (int vcState : stateSet) {
            NWrapper::w->nFrame->tRun(NWrapper::w->mNBeta01, vcKey, vcIndex++, vcState);
        }
        NWrapper::w->mNVisitorGraphics->tRun(NWrapper::w->mNBeta00, (NParam)this, (NParam)vcKey, (NParam)drawable);
    }

private:
    StateListDrawable(NNoObject* vNNoObject)
        : DrawableContainer(NWrapper::w->mNNoObject->instance<DrawableContainer>())
    {
    }
};

} // End namespace

#endif
