#ifndef __MotionEvent_H__
#define __MotionEvent_H__

namespace NSDEVICE
{

class MotionEvent : public InputEvent
{
friend NSNATIVE::NNoObject;

public:
	virtual ~MotionEvent()
	{
	}

    float getX()
    {
        nlong vcX = NWrapper::w->mNVisitorView->tRun(NWrapper::w->mNTheta00, (NParam)this);
        return (nfloat)(*reinterpret_cast<ndouble*>(&vcX));
    }

    float getY()
    {
        nlong vcY = NWrapper::w->mNVisitorView->tRun(NWrapper::w->mNIota00, (NParam)this);
        return (nfloat)(*reinterpret_cast<ndouble*>(&vcY));
    }

private:
    MotionEvent(NNoObject* vNNoObject)
        : InputEvent(NWrapper::w->mNNoObject->instance<InputEvent>())
    {
    }
};

} // End namespace

#endif
