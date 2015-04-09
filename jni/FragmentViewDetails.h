#ifndef __FragmentViewDetails_H__
#define __FragmentViewDetails_H__

namespace NSDEVICE
{

class FragmentViewDetails : public FragmentView
{
public:
    FragmentViewDetails(Wrapper* w);
    virtual ~FragmentViewDetails() override;

    virtual void init(nuint vcView, Menu* vMenu, nuint vcDBObjectId) override;
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
