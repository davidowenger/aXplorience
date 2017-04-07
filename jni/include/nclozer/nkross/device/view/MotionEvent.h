#ifndef __MotionEvent_H__
#define __MotionEvent_H__

namespace NSDEVICE
{

class MotionEvent : public InputEvent
{
friend NSNATIVE::NKrossFriend;

public:
    static const int ACTION_CANCEL = 0x00000003;
    static const int ACTION_DOWN = 0x00000000;
    static const int ACTION_MASK = 0x000000ff;
    static const int ACTION_MOVE = 0x00000002;
    static const int ACTION_POINTER_DOWN = 0x00000005;
    static const int ACTION_POINTER_INDEX_MASK = 0x0000ff00;
    static const int ACTION_POINTER_INDEX_SHIFT = 0x00000008;
    static const int ACTION_POINTER_UP = 0x00000006;
    static const int ACTION_SCROLL = 0x00000008;
    static const int ACTION_UP = 0x00000001;

    virtual ~MotionEvent()
    {
    }

    int getActionIndex()
    {
        return NKrossWrapper::w->mNVisitorView->tRun(NKrossWrapper::w->mNPsi00, (NParam)this);
    }

    int getActionMasked()
    {
        return NKrossWrapper::w->mNVisitorView->tRun(NKrossWrapper::w->mNOmega00, (NParam)this);
    }

    long long int getEventTime()
    {
        return NKrossWrapper::w->mNVisitorView->tRun(NKrossWrapper::w->mNLambda00, (NParam)this);
    }

    int getPointerCount()
    {
        return NKrossWrapper::w->mNVisitorView->tRun(NKrossWrapper::w->mNGamma01, (NParam)this);
    }

    float getX()
    {
        nlong vcValue = NKrossWrapper::w->mNVisitorView->tRun(NKrossWrapper::w->mNTheta00, (NParam)this);
        return (nfloat)*reinterpret_cast<ndouble*>(&vcValue);
    }

    float getX(int pointerIndex)
    {
        nlong vcValue = NKrossWrapper::w->mNVisitorView->tRun(NKrossWrapper::w->mNAlpha01, (NParam)this, pointerIndex);
        return (nfloat)*reinterpret_cast<ndouble*>(&vcValue);
    }

    float getY()
    {
        nlong vcValue = NKrossWrapper::w->mNVisitorView->tRun(NKrossWrapper::w->mNIota00, (NParam)this);
        return (nfloat)*reinterpret_cast<ndouble*>(&vcValue);
    }

    float getY(int pointerIndex)
    {
        nlong vcValue = NKrossWrapper::w->mNVisitorView->tRun(NKrossWrapper::w->mNBeta01, (NParam)this, pointerIndex);
        return (nfloat)*reinterpret_cast<ndouble*>(&vcValue);
    }

private:
    MotionEvent(NKrossFriend* vNKrossFriend)
        : InputEvent(NKrossWrapper::w->mNKrossFriend->instance<InputEvent>())
    {
    }
};

} // End namespace

#endif
