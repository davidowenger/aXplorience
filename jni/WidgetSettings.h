#ifndef __WidgetSettings_H__
#define __WidgetSettings_H__

namespace NSDEVICE
{

class WidgetSettings : public Widget, public View::OnTouchListener
{
public:
	WidgetSettings(Wrapper* w);
	virtual ~WidgetSettings() override;

    virtual void init(nuint vcView, nuint vcDBObjectId) override;

    // View::OnTouchListener
    virtual bool onTouch(View* v, MotionEvent* event) override;

    TextView* mTextView;
    GestureDetector* mGestureDetector;

    nint mcPadding;
};

} // End namespace

#endif
