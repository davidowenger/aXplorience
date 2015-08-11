#ifndef __WidgetSettings_H__
#define __WidgetSettings_H__

namespace NSDEVICE
{

struct SettingItem
{
    LinearLayout* mSettingLayout;
    TextView* mSettingLabel;
    View* mSettingView;
};

class AdapterBTState : public BaseAdapter, public AdapterView::OnItemSelectedListener
{
public:
    AdapterBTState(Wrapper* w);
    virtual ~AdapterBTState() override;

    // BaseAdapter
    virtual View* getDropDownView(int position, View* convertView, ViewGroup* parent) override;
    virtual int getCount() override;
    virtual Object* getItem(int position) override;
    virtual long long int getItemId(int position) override;
    virtual View* getView(int position, View* convertView, ViewGroup* parent) override;

    // AdapterView::OnItemSelectedListener
    virtual void onItemSelected(AdapterView* parent, View* view, int position, long id) override;
    virtual void onNothingSelected(AdapterView* parent) override;

    Wrapper* w;
    nuint mcBTStateChange;
    nuint mcTextViewIndex;
    nint mcPadding;
    TextView** mTextView;
};

class WidgetSettings : public Widget, public View::OnTouchListener
{
public:
    WidgetSettings(Wrapper* w);
    virtual ~WidgetSettings() override;

    void init();

    // View::OnTouchListener
    virtual bool onTouch(View* v, MotionEvent* event) override;

    TextView* mTextView;
    SettingItem* maSettingItem;
    AdapterBTState* mAdapterBTState;

    nint mcPadding;
};

} // End namespace

#endif
