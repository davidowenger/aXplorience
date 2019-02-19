#ifndef __MotionEvent_H__
#define __MotionEvent_H__

namespace NSDEVICE
{

class MotionEvent : public InputEvent
{
friend NSNATIVE::NKrossFriend;

public:
    virtual ~MotionEvent()
    {
    }

    float getX()
    {
        nlong vcValue = NSNKROSS::w->mNVisitorView->tRun(NSNKROSS::w->mNTheta00, (NParam)this);
        return (nfloat)*reinterpret_cast<ndouble*>(&vcValue);
    }

    float getY()
    {
        nlong vcValue = NSNKROSS::w->mNVisitorView->tRun(NSNKROSS::w->mNIota00, (NParam)this);
        return (nfloat)*reinterpret_cast<ndouble*>(&vcValue);
    }

    long long int getEventTime()
    {
        return NSNKROSS::w->mNVisitorView->tRun(NSNKROSS::w->mNLambda00, (NParam)this);
    }

private:
    MotionEvent(NKrossFriend* vNKrossFriend)
        : InputEvent(NSNKROSS::w->mNKrossFriend->instance<InputEvent>())
    {
    }
};

} // End namespace

#endif
