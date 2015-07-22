#ifndef __WidgetMessage_H__
#define __WidgetMessage_H__

namespace NSDEVICE
{

class WidgetMessage : public Widget, public View::OnClickListener, public View::OnTouchListener
{
public:
	WidgetMessage(Wrapper* w);
	virtual ~WidgetMessage() override;

    virtual void init(nuint vcView, nuint vcDBObjectId) override;
    virtual void render();

    // View::OnClickListener
    virtual void onClick(View* v) override;

    // View::OnTouchListener
    virtual bool onTouch(View* v, MotionEvent* event) override;

    nint mcPadding;
    DBObject* mDBObject;
    nint mcCategoryId;
    bool mIsInbound;
	bool mcIsEnabled;

    LinearLayout* mLeft;
    LinearLayout* mRight;
    ImageButton* mCategory;
	Button* mText;
	ToggleButton* mCheck;
	ToggleButton* mBuzz;
	StateListDrawable** mStateListCheck;
	StateListDrawable** mStateListBuzz;
};

class WidgetMessageOutbound : public WidgetMessage
{
public:
	WidgetMessageOutbound(Wrapper* w);
	virtual ~WidgetMessageOutbound() override;
};

class WidgetMessageInbound : public WidgetMessage
{
public:
	WidgetMessageInbound(Wrapper* w);
	virtual ~WidgetMessageInbound() override;
};

} // End namespace

#endif
