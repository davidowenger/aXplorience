#ifndef __WidgetMessageList_H__
#define __WidgetMessageList_H__

namespace NSDEVICE
{

class WidgetMessageList : public Widget, public View::OnTouchListener
{
public:
    WidgetMessageList(Wrapper* w);
    virtual ~WidgetMessageList() override;

    void init(nuint vcView, DBObject* vDBObject);
    void initHeader();

    // View::OnTouchListener
    virtual bool onTouch(View* v, MotionEvent* event) override;

    LinearLayout* mLinearLayout;
    LinearLayout* mHeader;
    ScrollView* mScrollView;
    TextView* mTextView;
    ToggleButton* mCategoryId;
    ToggleButton* mTitle;
    ToggleButton* mEnabled;
    GestureDetector* mGestureDetector;

    nint mcPadding;
    String mSort;
};

} // End namespace

#endif
