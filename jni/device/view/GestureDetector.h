#ifndef __GestureDetector_H__
#define __GestureDetector_H__

namespace NSDEVICE
{

class GestureDetector : public Object
{
friend NSNATIVE::NNoObject;

public:
    class OnGestureListener
    {
    protected:
        OnGestureListener()
        {
            NWrapper::w->mNVisitorView->tRun(NWrapper::w->mNAlpha02, (NParam)this);
        }

    public:
        virtual ~OnGestureListener()
        {
            NWrapper::w->nFrame->tRun(NWrapper::w->mNDelta00, (NParam)this);
        }

        virtual bool onDown(MotionEvent* e) = 0;
        virtual bool onFling(MotionEvent* e1, MotionEvent* e2, float velocityX, float velocityY) = 0;
        virtual void onLongPress(MotionEvent* e) = 0;
        virtual bool onScroll(MotionEvent* e1, MotionEvent* e2, float distanceX, float distanceY) = 0;
        virtual void onShowPress(MotionEvent* e) = 0;
        virtual bool onSingleTapUp(MotionEvent* e) = 0;
    };

    GestureDetector(Context* context, GestureDetector::OnGestureListener* listener)
    {
        NWrapper::w->mNVisitorView->tRun(NWrapper::w->mNAlpha00, (NParam)this);
    }

    virtual ~GestureDetector()
    {
    }

    virtual bool onTouchEvent(MotionEvent* ev)
    {
        return NWrapper::w->mNVisitorView->tRun(NWrapper::w->mNBeta00, (NParam)this, (NParam)ev);
    }

private:
    GestureDetector(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif
