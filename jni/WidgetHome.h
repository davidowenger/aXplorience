#ifndef __WidgetHome_H__
#define __WidgetHome_H__

namespace NSDEVICE
{

class WidgetHome : public Widget, public View::OnClickListener, public View::OnTouchListener
{
public:
	WidgetHome(Wrapper* w);
	virtual ~WidgetHome() override;

    virtual void init(nuint vcView, nuint vcDBObjectId) override;
    virtual void initHeader();

    // View::OnClickListener
    virtual void onClick(View* v) override;

    // View::OnTouchListener
    virtual bool onTouch(View* v, MotionEvent* event) override;

    LinearLayout* mHeader;
    ScrollView* mScrollView;
    TextView* mTextView;
    ToggleButton* mCategoryId;
    ToggleButton* mTitle;
    ToggleButton* mIn;
    GestureDetector* mGestureDetector;

    nint mcPadding;
    String mSort;
};

} // End namespace

#endif
