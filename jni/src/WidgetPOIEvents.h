#ifndef __WidgetPOIEvents_H__
#define __WidgetPOIEvents_H__

namespace NSDEVICE
{

class WidgetPOIEvents : public Widget, public View::OnTouchListener
{
public:
    WidgetPOIEvents(Wrapper* w);
    virtual ~WidgetPOIEvents() override;
    virtual void init(nuint vcView, DBObject* vDBObject);

    // View::OnTouchListener
    virtual bool onTouch(View* v, MotionEvent* event) override;

    TextView* mTextView;

    nint mcPadding;
};

} // End namespace

#endif
