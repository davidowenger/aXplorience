#ifndef __WidgetAR_H__
#define __WidgetAR_H__

namespace NSDEVICE
{

class WidgetAR : public Widget, public SurfaceHolder::Callback, public View::OnTouchListener
{
public:
    WidgetAR(Wrapper* w);
    virtual ~WidgetAR() override;

    void init(nuint vcView, DBObject* vDBObject);
    void onCreate();
    void onResume();
    void onPause();
    void onDestroy();
    void setState(nint vState);

    // SurfaceHolder::Callback
    void surfaceChanged(SurfaceHolder* holder, int format, int width, int height);
    void surfaceCreated(SurfaceHolder* holder);
    void surfaceDestroyed(SurfaceHolder* holder);

    // View::OnTouchListener
    bool onTouch(View* vView, MotionEvent* event);

    nint mcPadding;
    nint mState;
    SurfaceView* mSurfaceView;
    SurfaceHolder* mSurfaceHolder;
    EventManager* mEventManager;
};

} // End namespace

#endif
