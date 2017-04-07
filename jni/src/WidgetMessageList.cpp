#include "Common.h"
#include "Theme.h"

namespace NSDEVICE
{

WidgetMessageList::WidgetMessageList(Wrapper* const w) :
    Widget(w), mHeader(nullptr), mScrollView(nullptr), mTextView(nullptr), mGestureDetector(nullptr), mcPadding((nint)(5*w->mcDensity)), mSort("")
{
    LinearLayout::LayoutParams vLayoutMargins(LinearLayout::LayoutParams::MATCH_PARENT, LinearLayout::LayoutParams::MATCH_PARENT);

    mLinearLayout = new LinearLayout(w->mApplication);
    mHeader = new LinearLayout(w->mApplication);
    mCategoryId = new ToggleButton(w->mApplication);
    mTitle = new ToggleButton(w->mApplication);
    mEnabled = new ToggleButton(w->mApplication);
    mScrollView = new ScrollView(w->mApplication);

    vLayoutMargins.setMargins(mcPadding, mcPadding, mcPadding, mcPadding);
    setLayoutParams(&vLayoutMargins);
    setGravity(Gravity::LEFT);
    setOrientation(LinearLayout::VERTICAL);
    setPadding(mcPadding, mcPadding, mcPadding, mcPadding);
    setBackgroundColor(w->maColor[Theme::kColorTransparent]);
    setOnTouchListener(this);

    mLinearLayout->setLayoutParams(new LinearLayout::LayoutParams(LinearLayout::LayoutParams::MATCH_PARENT, LinearLayout::LayoutParams::MATCH_PARENT));
    mLinearLayout->setGravity(Gravity::LEFT|Gravity::TOP);
    mLinearLayout->setOrientation(LinearLayout::VERTICAL);
    mLinearLayout->setBackgroundColor(w->maColor[Theme::kColorApplicationBackground]);
    mLinearLayout->setOnTouchListener(this);

    mHeader->setOrientation(LinearLayout::HORIZONTAL);
    mHeader->setLayoutParams(new LinearLayout::LayoutParams(LinearLayout::LayoutParams::MATCH_PARENT, LinearLayout::LayoutParams::WRAP_CONTENT));

    mCategoryId->setGravity(Gravity::CENTER);
    mCategoryId->setLayoutParams(new LinearLayout::LayoutParams(0, LinearLayout::LayoutParams::WRAP_CONTENT, 1));
    mCategoryId->setPadding(mcPadding, mcPadding, mcPadding, mcPadding);
    mCategoryId->setBackgroundDrawable(nullptr);
    mCategoryId->setEnabled(true);
    mCategoryId->setChecked(true);
    mCategoryId->setAllCaps(false);
    mCategoryId->setTypeface(Typeface::DEFAULT);
    mCategoryId->setTextSize(w->mcTextSize);
    mCategoryId->setTextColor(w->maColor[Theme::kColorMessageText]);
    mCategoryId->setOnTouchListener(this);
    mCategoryId->setText("Category");
    mCategoryId->setTextOn("Category");
    mCategoryId->setTextOff("Category");

    mTitle->setGravity(Gravity::CENTER);
    mTitle->setLayoutParams(new LinearLayout::LayoutParams(0, LinearLayout::LayoutParams::WRAP_CONTENT, 1));
    mTitle->setPadding(mcPadding, mcPadding, mcPadding, mcPadding);
    mTitle->setBackgroundDrawable(nullptr);
    mTitle->setEnabled(true);
    mTitle->setChecked(true);
    mTitle->setAllCaps(false);
    mTitle->setTypeface(Typeface::DEFAULT);
    mTitle->setTextSize(w->mcTextSize);
    mTitle->setTextColor(w->maColor[Theme::kColorMessageText]);
    mTitle->setOnTouchListener(this);
    mTitle->setText("Title");
    mTitle->setTextOn("Title");
    mTitle->setTextOff("Title");

    mEnabled->setGravity(Gravity::CENTER);
    mEnabled->setLayoutParams(new LinearLayout::LayoutParams(0, LinearLayout::LayoutParams::WRAP_CONTENT, 1));
    mEnabled->setPadding(mcPadding, mcPadding, mcPadding, mcPadding);
    mEnabled->setBackgroundDrawable(nullptr);
    mEnabled->setEnabled(true);
    mEnabled->setChecked(true);
    mEnabled->setAllCaps(false);
    mEnabled->setTypeface(Typeface::DEFAULT);
    mEnabled->setTextSize(w->mcTextSize);
    mEnabled->setTextColor(w->maColor[Theme::kColorMessageText]);
    mEnabled->setOnTouchListener(this);
    mEnabled->setText("Enable");
    mEnabled->setTextOn("Enable");
    mEnabled->setTextOff("Enable");

    w->mMessageLayout->setGravity(Gravity::TOP|Gravity::LEFT);
    w->mMessageLayout->setOrientation(LinearLayout::VERTICAL);
    w->mMessageLayout->setLayoutParams(new LinearLayout::LayoutParams(LinearLayout::LayoutParams::MATCH_PARENT, LinearLayout::LayoutParams::WRAP_CONTENT));
    w->mMessageLayout->setOnTouchListener(this);

    mHeader->addView(mCategoryId);
    mHeader->addView(mTitle);
    mHeader->addView(mEnabled);
    mScrollView->addView(w->mMessageLayout);
    mLinearLayout->addView(mHeader);
    mLinearLayout->addView(mScrollView);
    addView(mLinearLayout);
}

WidgetMessageList::~WidgetMessageList()
{
    mHeader->removeAllViews();
    mScrollView->removeAllViews();

    if (mScrollView) {
       delete mScrollView;
    }
    if (mEnabled) {
       mEnabled->setButtonDrawable(nullptr);
       delete mEnabled;
    }
    if (mTitle) {
       mTitle->setButtonDrawable(nullptr);
       delete mTitle;
    }
    if (mCategoryId) {
       mCategoryId->setButtonDrawable(nullptr);
       delete mCategoryId;
    }
    if (mHeader) {
       delete mHeader;
    }
}

void WidgetMessageList::init(nuint vcView, DBObject* vDBObject)
{
    w->mMenu->setGroupVisible(k::ViewDelete, false);
    w->mMenu->setGroupVisible(k::ViewEdit, false);
    w->mMenu->setGroupVisible(k::ViewSave, false);
    w->mMenu->setGroupVisible(k::ViewList, false);
    w->mMenu->setGroupVisible(k::ViewAdd, true);

    w->mActionBar->setDisplayHomeAsUpEnabled(true);
    w->mActionBar->setHomeButtonEnabled(true);

    initHeader();
}

void WidgetMessageList::initHeader()
{
    nint vIndex;
    String vPrefix = ( w->mDBObjectApplication->is("sAscending2") ? "\xe2\x86\x93 " : "\xe2\x86\x91 " );
    mSort = w->mDBObjectApplication->get("sSort2");

    for (vIndex = 2 ; vIndex >= 0; --vIndex) {
        if (w->mDBObjectApplication->get("sSort" + to_string(vIndex)) == "Title") {
            mTitle->setChecked(w->mDBObjectApplication->is("sAscending" + to_string(vIndex)));
            mTitle->setText(vPrefix + "Title");
            mTitle->setTextOn(vPrefix + "Title");
            mTitle->setTextOff(vPrefix + "Title");
            mTitle->requestLayout();
        } else if (w->mDBObjectApplication->get("sSort" + to_string(vIndex)) == "CategoryId") {
            mCategoryId->setChecked(w->mDBObjectApplication->is("sAscending" + to_string(vIndex)));
            mCategoryId->setText(vPrefix + "Category");
            mCategoryId->setTextOn(vPrefix + "Category");
            mCategoryId->setTextOff(vPrefix + "Category");
            mCategoryId->requestLayout();
        } else if (w->mDBObjectApplication->get("sSort" + to_string(vIndex)) == "Enabled") {
            mEnabled->setChecked(w->mDBObjectApplication->is("sAscending" + to_string(vIndex)));
            mEnabled->setText(vPrefix + "Enabled");
            mEnabled->setTextOn(vPrefix + "Enabled");
            mEnabled->setTextOff(vPrefix + "Enabled");
            mEnabled->requestLayout();
        }
        vPrefix = "";
    }
}

//*******************************************************************************************
//**************************************  OnTouchListener  **********************************
//*******************************************************************************************
bool WidgetMessageList::onTouch(View* vView, MotionEvent* vEvent)
{
    if (vEvent->getActionMasked() == MotionEvent::ACTION_UP) {
        if (vView == mCategoryId) {
            w->mNActivity->sendOp(w->mOpUnitDBId, w->mNWrapper->mNKrossWrapper->mNMu00, new OpMessage("CategoryId", "", "", "" , "", mSort == "CategoryId" ? !mCategoryId->isChecked() : mCategoryId->isChecked() ));
        }
        if (vView == mTitle) {
            w->mNActivity->sendOp(w->mOpUnitDBId, w->mNWrapper->mNKrossWrapper->mNMu00, new OpMessage("Title", "", "", "" , "", mSort == "Title" ? !mTitle->isChecked() : mTitle->isChecked() ));
        }
        if (vView == mEnabled) {
            w->mNActivity->sendOp(w->mOpUnitDBId, w->mNWrapper->mNKrossWrapper->mNMu00, new OpMessage("Enabled", "", "", "" , "", mSort == "Enabled" ? !mEnabled->isChecked() : mEnabled->isChecked() ));
        }
    }
    return true;
}

} // End namespace
