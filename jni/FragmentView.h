#ifndef __FragmentView_H__
#define __FragmentView_H__

namespace NSDEVICE
{

class FragmentView : public LinearLayout, public GestureDetector::OnGestureListener
{
public:
    FragmentView(Wrapper* const w)
        : LinearLayout(w->mApplication), w(w), mWidget(nullptr), mcView(0), mcDBObjectId(1), mIsInbound(true), mX(0.0), mY(0.0), mT(0)
    {
    }

    virtual ~FragmentView()
    {
        if (mWidget) {
            delete mWidget;
        }
    }

    virtual void onCreateMenu(Menu* menu)
    {
    }

    virtual bool onMenuItemSelected(nint id)
    {
        return false;
    }

    virtual void init(nuint vcView, DBObject* vDBObject) = 0;

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
    Widget* mWidget;

    nuint mcView;
    nuint mcDBObjectId;
    bool mIsInbound;
    nfloat mX;
    nfloat mY;
    nlong mT;
};

} // End namespace

#endif
