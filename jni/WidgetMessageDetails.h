#ifndef __WidgetMessageDetails_H__
#define __WidgetMessageDetails_H__

namespace NSDEVICE
{

class WidgetMessageDetails : public Widget, public View::OnTouchListener
{
public:
    WidgetMessageDetails(Wrapper* w);
    virtual ~WidgetMessageDetails() override;

    void update(DBObject* vDBObject);

    // View::OnTouchListener
    virtual bool onTouch(View* v, MotionEvent* event) override;

    nint mcPadding;
    DBObject* mDBObject;
    nint mcCategoryId;

    TextView* mCategory;
    TextView* mTitle;
    TextView* mText;
    TextView* mLink;
};

} // End namespace

#endif
