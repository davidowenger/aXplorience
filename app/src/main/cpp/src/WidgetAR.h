#ifndef __WidgetAR_H__
#define __WidgetAR_H__

namespace NSDEVICE
{

class WidgetAR : public Widget, public SurfaceHolder::Callback, public View::OnTouchListener
{
public:
    WidgetAR(Wrapper* w);
    virtual ~WidgetAR() override;

    void init();
    void onCreate();
    void onResume();
    void onPause();
    void onDestroy();

    // SurfaceHolder::Callback
    virtual void surfaceChanged(SurfaceHolder* holder, int format, int width, int height);
    virtual void surfaceCreated(SurfaceHolder* holder);
    virtual void surfaceDestroyed(SurfaceHolder* holder);

    // View::OnTouchListener
    virtual bool onTouch(View* v, MotionEvent* event) override;

    SurfaceHolder* mSurfaceHolder;
    nint mcPadding;
};

} // End namespace

#endif
