#ifndef __WidgetAbout_H__
#define __WidgetAbout_H__

namespace NSDEVICE
{

class WidgetAbout : public Widget, public View::OnTouchListener
{
public:
	WidgetAbout(Wrapper* w);
	virtual ~WidgetAbout() override;

    virtual void init(nuint vcView, nuint vcDBObjectId) override;

    // View::OnTouchListener
    virtual bool onTouch(View* v, MotionEvent* event) override;

    TextView* mTextView;
    GestureDetector* mGestureDetector;

    nint mcPadding;
};

} // End namespace

#endif
