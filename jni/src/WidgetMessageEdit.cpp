#include "Common.h"
#include "Theme.h"

namespace NSDEVICE
{

WidgetMessageEdit::WidgetMessageEdit(Wrapper* const w)
    : Widget(w), mcPadding((nint)(10*w->mcDensity)), mDBObject(nullptr), mcCategoryId(0),
    mAdapterCategory(nullptr), mScrollView(nullptr), mContent(nullptr), mCategory(nullptr), mTitle(nullptr), mText(nullptr), mLink(nullptr)
{
    mAdapterCategory = new AdapterCategory(w);
    mScrollView = new ScrollView(w->mApplication);
    mContent = new LinearLayout(w->mApplication);
    mCategory = new Spinner(w->mNActivity);
    mTitle = new EditText(w->mNActivity);
    mText = new EditText(w->mNActivity);
    mLink = new EditText(w->mNActivity);

    setGravity(Gravity::LEFT|Gravity::TOP);
    setOrientation(LinearLayout::VERTICAL);
    setLayoutParams(new LinearLayout::LayoutParams(LinearLayout::LayoutParams::MATCH_PARENT, LinearLayout::LayoutParams::MATCH_PARENT));
    setPadding(mcPadding, mcPadding, mcPadding, mcPadding);

    mContent->setGravity(Gravity::LEFT|Gravity::TOP);
    mContent->setOrientation(LinearLayout::VERTICAL);
    mContent->setLayoutParams(new LinearLayout::LayoutParams(LinearLayout::LayoutParams::MATCH_PARENT, LinearLayout::LayoutParams::MATCH_PARENT));
    mContent->setPadding(mcPadding, mcPadding, mcPadding, mcPadding);

    mCategory->setGravity(Gravity::START);
    mCategory->setLayoutParams(new LinearLayout::LayoutParams(LinearLayout::LayoutParams::MATCH_PARENT, LinearLayout::LayoutParams::WRAP_CONTENT));
    mCategory->setPadding(mcPadding, mcPadding, mcPadding, mcPadding);
    mCategory->setAdapter(mAdapterCategory);
    mCategory->setOnItemSelectedListener(mAdapterCategory);

    mTitle->setGravity(Gravity::START);
    mTitle->setLayoutParams(new LinearLayout::LayoutParams(LinearLayout::LayoutParams::MATCH_PARENT, LinearLayout::LayoutParams::WRAP_CONTENT));
    mTitle->setPadding(mcPadding, mcPadding, mcPadding, mcPadding);
    mTitle->setTextColor(w->maColor[Theme::kColorMessageText]);
    mTitle->setTextSize(w->mcTextSize);
    mTitle->setHint("Short message");
    mTitle->setRawInputType(InputType::TYPE_CLASS_TEXT|InputType::TYPE_TEXT_VARIATION_NORMAL);
    mTitle->setImeOptions(EditorInfo::IME_ACTION_NEXT|EditorInfo::IME_FLAG_NO_FULLSCREEN|EditorInfo::IME_FLAG_NO_EXTRACT_UI|EditorInfo::IME_FLAG_NAVIGATE_NEXT);

    mText->setGravity(Gravity::START);
    mText->setPadding(mcPadding, mcPadding, mcPadding, mcPadding);
    mText->setLayoutParams(new LinearLayout::LayoutParams(LinearLayout::LayoutParams::MATCH_PARENT, LinearLayout::LayoutParams::WRAP_CONTENT));
    mText->setTextColor(w->maColor[Theme::kColorMessageText]);
    mText->setTextSize(w->mcTextSize);
    mText->setLines(3);
    mText->setHint("More description ...");
    mText->setRawInputType(InputType::TYPE_CLASS_TEXT|InputType::TYPE_TEXT_VARIATION_LONG_MESSAGE);
    mText->setImeOptions(EditorInfo::IME_ACTION_NEXT|EditorInfo::IME_FLAG_NO_FULLSCREEN|EditorInfo::IME_FLAG_NO_EXTRACT_UI|EditorInfo::IME_FLAG_NAVIGATE_NEXT); //|EditorInfo::IME_FLAG_NO_ENTER_ACTION|EditorInfo::IME_MASK_ACTION

    mLink->setGravity(Gravity::START);
    mLink->setPadding(mcPadding, mcPadding, mcPadding, mcPadding);
    mLink->setLayoutParams(new LinearLayout::LayoutParams(LinearLayout::LayoutParams::MATCH_PARENT, LinearLayout::LayoutParams::WRAP_CONTENT));
    mLink->setTextColor(w->maColor[Theme::kColorMessageText]);
    mLink->setTextSize(w->mcTextSize);
    mLink->setHint("Your url");
    mLink->setRawInputType(InputType::TYPE_CLASS_TEXT|InputType::TYPE_TEXT_VARIATION_URI|InputType::TYPE_TEXT_FLAG_NO_SUGGESTIONS);
    mLink->setImeOptions(EditorInfo::IME_ACTION_DONE|EditorInfo::IME_FLAG_NO_FULLSCREEN|EditorInfo::IME_FLAG_NO_EXTRACT_UI);

    mContent->addView(mCategory);
    mContent->addView(mTitle);
    mContent->addView(mText);
    mContent->addView(mLink);
    mScrollView->addView(mContent);
    addView(mScrollView);
}

WidgetMessageEdit::~WidgetMessageEdit()
{
    mContent->removeAllViews();
    mScrollView->removeAllViews();

    if (mDBObject) {
       delete mDBObject;
    }
    if (mLink) {
       delete mLink;
    }
    if (mText) {
       delete mText;
    }
    if (mTitle) {
       delete mTitle;
    }
    if (mCategory) {
       delete mCategory;
    }
    if (mContent) {
       delete mContent;
    }
    if (mScrollView) {
       delete mScrollView;
    }
    if (mAdapterCategory) {
       delete mAdapterCategory;
    }
}

void WidgetMessageEdit::update(DBObject* vDBObject)
{
    mcDBObjectId = vDBObject->mId;
    mcCategoryId = vDBObject->count("sCategoryId");

    mCategory->setSelection(mcCategoryId);
    mTitle->setText(vDBObject->get("sTitle"), TextView::NORMAL);
    mText->setText(vDBObject->get("text"), TextView::NORMAL);
    mLink->setText(vDBObject->get("link"), TextView::NORMAL);
    requestLayout();
}

//*******************************************************************************************
//************************************ AdapterCategory **************************************
//*******************************************************************************************
AdapterCategory::AdapterCategory(Wrapper* const w)
    : BaseAdapter(), w(w), mcPadding((nint)(10*w->mcDensity)), mTextView(nullptr)
{
    nuint i = 0;
    mTextView = new TextView*[w->mcCategory + 1]();

    for (i = 0 ; i < w->mcCategory + 1 ; ++i) {
        mTextView[i] = new TextView(w->mNActivity);
        mTextView[i]->setLayoutParams(new AbsListView::LayoutParams(AbsListView::LayoutParams::MATCH_PARENT, AbsListView::LayoutParams::WRAP_CONTENT));
        mTextView[i]->setTextColor(w->maColor[Theme::kColorMessageText]);
        //mTextView[i]->setTypeface(Typeface::DEFAULT);
        mTextView[i]->setTextSize(w->mcTextSize);

        if (i) {
            mTextView[i]->setPadding(mcPadding, mcPadding, mcPadding, mcPadding);
            mTextView[i]->setText(w->maCategory[i - 1]);
        }
    }

}

AdapterCategory::~AdapterCategory()
{
    nuint i = 0;

    if (mTextView) {
        for (i = 0 ; i < w->mcCategory + 1 ; ++i) {
            if (mTextView[i]) {
                delete mTextView[i];
            }
        }
        delete[] mTextView;
    }
}

//*******************************************************************************************
//************************************ BaseAdapter ******************************************
//*******************************************************************************************
View* AdapterCategory::getDropDownView(int position, View* convertView, ViewGroup* parent)
{
    return mTextView[position + 1];
}

int AdapterCategory::getCount()
{
    return 4;
}

Object* AdapterCategory::getItem(int position)
{
    return nullptr;
}

long long int AdapterCategory::getItemId(int position)
{
    return position;
}

View* AdapterCategory::getView(int position, View* convertView, ViewGroup* parent)
{
    mTextView[0]->setText(w->maCategory[position]);
    return mTextView[0];
}

//*******************************************************************************************
//******************** AdapterView::OnItemSelectedListener **********************************
//*******************************************************************************************
void AdapterCategory::onItemSelected(AdapterView* parent, View* view, int pos, long id)
{
}

void AdapterCategory::onNothingSelected(AdapterView* parent)
{
}

} // End namespace
