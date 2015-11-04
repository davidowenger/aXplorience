#include "Common.h"
#include "Theme.h"

namespace NSDEVICE
{

WidgetSettings::WidgetSettings(Wrapper* const w)
    : Widget(w), mTextView(nullptr), maSettingItem(nullptr), mAdapterBTState(nullptr), mcPadding((nint)(10*w->mcDensity))
{
    nuint i;

    mTextView = new TextView(w->mApplication);
    maSettingItem = new SettingItem[1] {
        { nullptr, nullptr, new Spinner(w->mNActivity) }
    };
    mAdapterBTState = new AdapterBTState(w);

    LinearLayout::LayoutParams vLayoutParams1 = LinearLayout::LayoutParams(0, LinearLayout::LayoutParams::MATCH_PARENT, 1);
    setGravity(Gravity::LEFT|Gravity::TOP);
    setOrientation(LinearLayout::VERTICAL);
    setLayoutParams(&vLayoutParams1);
    setPadding(mcPadding,mcPadding,mcPadding,mcPadding);
    setOnTouchListener(this);

    LinearLayout::LayoutParams vLayoutParams2 = LinearLayout::LayoutParams(LinearLayout::LayoutParams::MATCH_PARENT, LinearLayout::LayoutParams::WRAP_CONTENT);
    mTextView->setGravity(Gravity::START|Gravity::TOP);
    mTextView->setLayoutParams(&vLayoutParams2);
    mTextView->setPadding(mcPadding, mcPadding, mcPadding, mcPadding);
    mTextView->setTextColor(w->maColor[Theme::kColorMessageText]);
    mTextView->setTextSize(w->mcTextSize);
    mTextView->setTypeface(Typeface::DEFAULT);
    mTextView->setText("Be sure to have Bluetooth ENABLED and VISIBLE for your device to be seen. Only VISIBLE device can connect to not VISIBLE ones.");
    mTextView->setOnTouchListener(this);

    addView(mTextView);

    for (i = 0 ; i < 1 ; ++i) {
        LinearLayout::LayoutParams vLinearLayoutParams3 =  LinearLayout::LayoutParams(LinearLayout::LayoutParams::MATCH_PARENT, LinearLayout::LayoutParams::WRAP_CONTENT);
        maSettingItem[i].mSettingView->setLayoutParams(&vLinearLayoutParams3);
        maSettingItem[i].mSettingView->setPadding(mcPadding, mcPadding, mcPadding, mcPadding);
        ((Spinner*)maSettingItem[i].mSettingView)->setGravity(Gravity::START|Gravity::TOP);
        ((Spinner*)maSettingItem[i].mSettingView)->setAdapter(mAdapterBTState);
        ((Spinner*)maSettingItem[i].mSettingView)->setOnItemSelectedListener(mAdapterBTState);

        addView(maSettingItem[i].mSettingView);
    }
}

WidgetSettings::~WidgetSettings()
{
    nint i;

    if (mTextView) {
       delete mTextView;
    }
    if (maSettingItem) {
        for (i = 0 ; i < 1 ; ++i) {
            delete maSettingItem[i].mSettingLayout;
            delete maSettingItem[i].mSettingLabel;
            delete maSettingItem[i].mSettingView;
        }
        delete[] maSettingItem;
    }
}

void WidgetSettings::init()
{
    if (mAdapterBTState->mcBTStateChange == w->mcBTStateChange) {
        ((Spinner*)maSettingItem[0].mSettingView)->setSelection(2 - w->mcBTState);
        requestLayout();
    }
}

//*******************************************************************************************
//**************************************  OnTouchListener  **********************************
//*******************************************************************************************
bool WidgetSettings::onTouch(View* vView, MotionEvent* event)
{
    if (w->mTouchState == 3) {
        w->mTouchState = 0;
    }
    return true;
}

//*******************************************************************************************
//************************************ AdapterBTState **************************************
//*******************************************************************************************
AdapterBTState::AdapterBTState(Wrapper* const w)
    : BaseAdapter(), w(w), mcBTStateChange(0), mcTextViewIndex(0), mcPadding((nint)(10*w->mcDensity)), mTextView(nullptr)
{
    nuint i = 0;
    mTextView = new TextView*[w->mcBTStateOption + 1]();

    for (i = 0 ; i < w->mcBTStateOption + 1 ; ++i) {
        mTextView[i] = new TextView(w->mNActivity);
        mTextView[i]->setLayoutParams(new AbsListView::LayoutParams(AbsListView::LayoutParams::MATCH_PARENT, AbsListView::LayoutParams::MATCH_PARENT));
        mTextView[i]->setTextColor(w->maColor[Theme::kColorMessageText]);
        mTextView[i]->setTextSize(w->mcTextSize);

        if (i) {
            mTextView[i]->setPadding(mcPadding, mcPadding, mcPadding, mcPadding);
            mTextView[i]->setText(w->maBTStateOption[i - 1]);
        }
    }
}

AdapterBTState::~AdapterBTState()
{
    nuint i = 0;

    if (mTextView) {
        for (i = 0 ; i < w->mcBTStateOption + 1 ; ++i) {
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
View* AdapterBTState::getDropDownView(int position, View* convertView, ViewGroup* parent)
{
    return mTextView[position + 1];
}

int AdapterBTState::getCount()
{
    return w->mcBTStateOption;
}

Object* AdapterBTState::getItem(int position)
{
    return nullptr;
}

long long int AdapterBTState::getItemId(int position)
{
    return position;
}

View* AdapterBTState::getView(int position, View* convertView, ViewGroup* parent)
{
    mTextView[0]->setText(w->maBTStateOption[position]);
    return mTextView[0];
}

//*******************************************************************************************
//******************** AdapterView::OnItemSelectedListener **********************************
//*******************************************************************************************
void AdapterBTState::onItemSelected(AdapterView* parent, View* view, int pos, long id)
{
    ++mcBTStateChange;
    w->mNActivity->sendOp(w->mOpUnitCoreId, w->mNWrapper->mNKrossWrapper->mNEpsilon00, new OpParam(2 - ((Spinner*)w->mWidgetSettings->maSettingItem[0].mSettingView)->getSelectedItemPosition()));
}

void AdapterBTState::onNothingSelected(AdapterView* parent)
{
}

} // End namespace
