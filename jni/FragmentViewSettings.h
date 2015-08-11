#ifndef __FragmentViewSettings_H__
#define __FragmentViewSettings_H__

namespace NSDEVICE
{

class FragmentViewSettings : public FragmentView
{
public:
    FragmentViewSettings(Wrapper* w);
    virtual ~FragmentViewSettings() override;

    virtual void init(nuint vcView, DBObject* vDBObject) override;
    virtual bool onInterceptTouchEvent(MotionEvent* ev) override;
    virtual bool onMenuItemSelected(nint id) override;

    // GestureDetector::OnGestureListener
    virtual bool onDown(MotionEvent* e) override;
    virtual bool onFling(MotionEvent* e1, MotionEvent* e2, float velocityX, float velocityY) override;
    virtual void onLongPress(MotionEvent* e) override;
    virtual bool onScroll(MotionEvent* e1, MotionEvent* e2, float distanceX, float distanceY) override;
    virtual void onShowPress(MotionEvent* e) override;
    virtual bool onSingleTapUp(MotionEvent* e) override;
};

} // End namespace

#endif
