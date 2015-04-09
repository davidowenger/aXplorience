#ifndef __FragmentView_H__
#define __FragmentView_H__

namespace NSDEVICE
{

class FragmentView : public LinearLayout, public GestureDetector::OnGestureListener
{
public:
    FragmentView(Wrapper* const w)
        : LinearLayout(w->mApplication), w(w), maContent(nullptr), mViewSource(nullptr), mcView(0), mcDBObjectId(1), mTouchState(0)
    {
    }

    virtual ~FragmentView()
    {
    }

    virtual void onCreateMenu(Menu* menu)
    {
    }

    virtual bool onMenuItemSelected(nint id)
    {
        return false;
    }

    virtual void init(nuint vcView, Menu* vMenu, nuint vcDBObjectId) = 0;

    //*******************************************************************************************
    //************************************** OnGestureListener  *********************************
    //*******************************************************************************************
    virtual bool onDown(MotionEvent* e)
    {
        return false;
    }

    virtual bool onFling(MotionEvent* e1, MotionEvent* e2, float vVelocityX, float vVelocityY)
    {
        return false;
    }

    virtual void onLongPress(MotionEvent* e)
    {
    }

    virtual bool onScroll(MotionEvent* e1, MotionEvent* e2, float distanceX, float distanceY)
    {
        return false;
    }

    virtual void onShowPress(MotionEvent* e)
    {
    }

    virtual bool onSingleTapUp(MotionEvent* e)
    {
        return false;
    }

    Wrapper* w;
    Widget** maContent;
    View* mViewSource;

    nuint mcView;
    nuint mcDBObjectId;
    nuint mTouchState;
};

} // End namespace

#endif
