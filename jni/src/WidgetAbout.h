#ifndef __WidgetAbout_H__
#define __WidgetAbout_H__

namespace NSDEVICE
{

class WidgetAbout : public Widget, public View::OnTouchListener
{
public:
    WidgetAbout(Wrapper* w);
    virtual ~WidgetAbout() override;

    void init(nuint vcView, DBObject* vDBObject);

    // View::OnTouchListener
    virtual bool onTouch(View* v, MotionEvent* event) override;

    LinearLayout* mTop;
    ImageButton* mIcon;
    TextView* mTextView;
    GestureDetector* mGestureDetector;

    nint mcPadding;
};

} // End namespace

#endif
