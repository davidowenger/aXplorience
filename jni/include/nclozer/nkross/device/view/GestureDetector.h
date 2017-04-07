#ifndef __GestureDetector_H__
#define __GestureDetector_H__

namespace NSDEVICE
{

class GestureDetector : public Object
{
friend NSNATIVE::NKrossFriend;

public:
    class OnGestureListener
    {
    protected:
        OnGestureListener();
    public:
        virtual ~OnGestureListener();
        virtual bool onDown(MotionEvent* e) = 0;
        virtual bool onFling(MotionEvent* e1, MotionEvent* e2, float velocityX, float velocityY) = 0;
        virtual void onLongPress(MotionEvent* e) = 0;
        virtual bool onScroll(MotionEvent* e1, MotionEvent* e2, float distanceX, float distanceY) = 0;
        virtual void onShowPress(MotionEvent* e) = 0;
        virtual bool onSingleTapUp(MotionEvent* e) = 0;
    };

    GestureDetector(Context* context, GestureDetector::OnGestureListener* listener);
    virtual ~GestureDetector();
    virtual bool onTouchEvent(MotionEvent* ev);
    virtual void setIsLongpressEnabled(bool enabled);
private:
    GestureDetector(NKrossFriend* vNKrossFriend);
};

} // End namespace

#endif
