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
        long vcX = NWrapper::w->mNVisitorView->tRun(NWrapper::w->mNTheta00, (NParam)this);
        return (float)(*reinterpret_cast<double*>(&vcX));
    }

    float getY()
    {
        long vcY = NWrapper::w->mNVisitorView->tRun(NWrapper::w->mNIota00, (NParam)this);
        return (float)(*reinterpret_cast<double*>(&vcY));
    }

private:
    MotionEvent(NNoObject* vNNoObject)
        : InputEvent(NWrapper::w->mNNoObject->instance<InputEvent>())
    {
    }
};

} // End namespace

#endif
