#ifndef __EventManager_H__
#define __EventManager_H__

namespace NSDEVICE
{

class EventManager : public View::OnTouchListener
{
public:
    EventManager(Wrapper* w);
    virtual ~EventManager();

    virtual bool onMove(View* vView, MotionEvent* event);

    // View::OnTouchListener
    virtual bool onTouch(View* v, MotionEvent* event) override;

    Wrapper* w;
    nlong mT0;
    nuint mX0;
    nuint mY0;
    nlong mT;
    nuint mX;
    nuint mY;
    nuint mState;
};

} // End namespace

#endif
