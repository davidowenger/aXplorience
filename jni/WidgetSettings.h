#ifndef __WidgetSettings_H__
#define __WidgetSettings_H__

namespace NSDEVICE
{

struct WidgetSettingsItem
{
    LinearLayout* mLinearLayout;
    TextView* mTextView;
    ToggleButton* mToggleButton;
};

class WidgetSettings : public Widget, public View::OnClickListener, public View::OnTouchListener
{
public:
    WidgetSettings(Wrapper* w);
    virtual ~WidgetSettings() override;

    virtual void init(nuint vcView, nuint vcDBObjectId) override;

    // View::OnClickListener
    virtual void onClick(View* v) override;

    // View::OnTouchListener
    virtual bool onTouch(View* v, MotionEvent* event) override;

    TextView* mTextView;
    WidgetSettingsItem* maWidgetSettingsItem;
    String* maWidgetSettingsLabel;

    nint mcPadding;
};

} // End namespace

#endif
