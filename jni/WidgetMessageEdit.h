#ifndef __WidgetMessageEdit_H__
#define __WidgetMessageEdit_H__

namespace NSDEVICE
{

class WidgetMessageEdit : public Widget
{
public:
    WidgetMessageEdit(Wrapper* w);
    virtual ~WidgetMessageEdit() override;

    virtual void init(nuint vcView, nuint vcDBObjectId) override;

    nint mcPadding;
    DBObject* mDBObject;
    nint mcCategoryId;

    ScrollView* mScrollView;
    LinearLayout* mContent;
    Spinner* mCategory;
    EditText* mTitle;
    EditText* mText;
    EditText* mLink;
};

class AdapterCategory : public BaseAdapter, public AdapterView::OnItemSelectedListener
{
public:
    AdapterCategory(Wrapper* w);
    virtual ~AdapterCategory() override;

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
    nint mcPadding;
    TextView** mTextView;
};

} // End namespace

#endif
