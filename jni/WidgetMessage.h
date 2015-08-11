#ifndef __WidgetMessage_H__
#define __WidgetMessage_H__

namespace NSDEVICE
{

class WidgetMessage : public Widget, public View::OnTouchListener
{
public:
    WidgetMessage(Wrapper* w);
    virtual ~WidgetMessage() override;

    void render();
    void update(DBObject* vDBObject);

    // View::OnTouchListener
    virtual bool onTouch(View* v, MotionEvent* event) override;

    nint mcPadding;
    nint mcCategoryId;
    bool mIsInbound;
    bool mIsEnabled;
    bool mIsBuzzed;

    LinearLayout* mLeft;
    LinearLayout* mRight;
    ImageButton* mCategory;
    Button* mText;
    ImageButton* mCheck;
    ImageButton* mBuzz;
};

} // End namespace

#endif
