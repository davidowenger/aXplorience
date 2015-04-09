#ifndef __WidgetHome_H__
#define __WidgetHome_H__

namespace NSDEVICE
{

class WidgetHome : public Widget, public View::OnTouchListener
{
public:
	WidgetHome(Wrapper* w);
	virtual ~WidgetHome() override;

    virtual void init(nuint vcView, nuint vcDBObjectId) override;

    // View::OnTouchListener
    virtual bool onTouch(View* v, MotionEvent* event) override;

    LinearLayout* mHeader;
    ScrollView* mScrollView;
    TextView* mTextView;
    GestureDetector* mGestureDetector;

    nint mcPadding;
};

} // End namespace

#endif
