#include "Common.h"
#include "Theme.h"

namespace NSDEVICE
{

WidgetHome::WidgetHome(Wrapper* const w)
	: Widget(w), mHeader(nullptr), mScrollView(nullptr), mTextView(nullptr), mGestureDetector(nullptr), mcPadding((nint)(5*w->mcDensity)), mSort("")
{
    mHeader = new LinearLayout(w->mApplication);
    mTextView = new TextView(w->mApplication);
    mCategoryId = new ToggleButton(w->mApplication);
    mTitle = new ToggleButton(w->mApplication);
    mIn = new ToggleButton(w->mApplication);
    mScrollView = new ScrollView(w->mApplication);

    setGravity(Gravity::LEFT);
    setOrientation(LinearLayout::VERTICAL);
    setLayoutParams(new LinearLayout::LayoutParams(0, LinearLayout::LayoutParams::MATCH_PARENT, 1));
    setPadding(mcPadding, mcPadding, mcPadding, mcPadding);
    setOnTouchListener(this);

    mHeader->setOrientation(LinearLayout::HORIZONTAL);
    mHeader->setLayoutParams(new LinearLayout::LayoutParams(LinearLayout::LayoutParams::MATCH_PARENT, LinearLayout::LayoutParams::WRAP_CONTENT));

    mTextView->setGravity(Gravity::START);
    mTextView->setLayoutParams(new LinearLayout::LayoutParams(LinearLayout::LayoutParams::MATCH_PARENT, LinearLayout::LayoutParams::WRAP_CONTENT));
    mTextView->setPadding(mcPadding, mcPadding, mcPadding, mcPadding);
    mTextView->setTextSize(w->mcTextSize);
    mTextView->setTextColor(w->maColor[Theme::kColorMessageText]);
    mTextView->setText("Messages:");

    mCategoryId->setGravity(Gravity::CENTER);
    mCategoryId->setLayoutParams(new LinearLayout::LayoutParams(0, LinearLayout::LayoutParams::WRAP_CONTENT, 1));
    mCategoryId->setPadding(mcPadding, mcPadding, mcPadding, mcPadding);
    mCategoryId->setBackgroundDrawable(nullptr);
    mCategoryId->setEnabled(true);
    mCategoryId->setChecked(true);
    mCategoryId->setTextSize(w->mcTextSize);
    mCategoryId->setTextColor(w->maColor[Theme::kColorMessageText]);
    mCategoryId->setOnClickListener(this);
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
    mTitle->setTextSize(w->mcTextSize);
    mTitle->setTextColor(w->maColor[Theme::kColorMessageText]);
    mTitle->setOnClickListener(this);
    mTitle->setOnTouchListener(this);
    mTitle->setText("Title");
    mTitle->setTextOn("Title");
    mTitle->setTextOff("Title");

    mIn->setGravity(Gravity::CENTER);
    mIn->setLayoutParams(new LinearLayout::LayoutParams(0, LinearLayout::LayoutParams::WRAP_CONTENT, 1));
    mIn->setPadding(mcPadding, mcPadding, mcPadding, mcPadding);
    mIn->setBackgroundDrawable(nullptr);
    mIn->setEnabled(true);
    mIn->setChecked(true);
    mIn->setTextSize(w->mcTextSize);
    mIn->setTextColor(w->maColor[Theme::kColorMessageText]);
    mIn->setOnClickListener(this);
    mIn->setOnTouchListener(this);
    mIn->setText("In/Out");
    mIn->setTextOn("In/Out");
    mIn->setTextOff("In/Out");

    w->mMessageLayout->setGravity(Gravity::TOP|Gravity::LEFT);
    w->mMessageLayout->setOrientation(LinearLayout::VERTICAL);
    w->mMessageLayout->setLayoutParams(new LinearLayout::LayoutParams(LinearLayout::LayoutParams::MATCH_PARENT, LinearLayout::LayoutParams::WRAP_CONTENT));
    w->mMessageLayout->setOnTouchListener(this);

    mHeader->addView(mCategoryId);
    mHeader->addView(mTitle);
    mHeader->addView(mIn);
    mScrollView->addView(w->mMessageLayout);
    addView(mHeader);
    addView(mScrollView);
}

WidgetHome::~WidgetHome()
{
    if (mGestureDetector) {
       delete mGestureDetector;
    }
    if (mScrollView) {
       delete mScrollView;
    }
    if (mIn) {
       mIn->setButtonDrawable(nullptr);
       delete mIn;
    }
    if (mTitle) {
       mTitle->setButtonDrawable(nullptr);
       delete mTitle;
    }
    if (mCategoryId) {
       mCategoryId->setButtonDrawable(nullptr);
       delete mCategoryId;
    }
    if (mTextView) {
       delete mTextView;
    }
    if (mHeader) {
       delete mHeader;
    }
}

void WidgetHome::init(nuint vcView, nuint vcDBObjectId)
{
    mcView = vcView;
    mcDBObjectId = vcDBObjectId;

    initHeader();
}

void WidgetHome::initHeader()
{
    nint vIndex;
    String vPrefix = ( w->mDBObjectApplication->is("sAscending2") ? "\xe2\x86\x93 " :  "\xe2\x86\x91 " );
    mSort = w->mDBObjectApplication->get("sSort2");

    for (vIndex = 2 ; vIndex >= 0; --vIndex) {
        if (w->mDBObjectApplication->get("sSort" + to_string(vIndex))  == "sTitle") {
            mTitle->setText(vPrefix + "Title");
            mTitle->setTextOn(vPrefix + "Title");
            mTitle->setTextOff(vPrefix + "Title");
            mTitle->setChecked(w->mDBObjectApplication->is("sAscending" + to_string(vIndex)));
        } else if (w->mDBObjectApplication->get("sSort" + to_string(vIndex)) == "sCategoryId") {
            mCategoryId->setText(vPrefix + "Category");
            mCategoryId->setTextOn(vPrefix + "Category");
            mCategoryId->setTextOff(vPrefix + "Category");
            mCategoryId->setChecked(w->mDBObjectApplication->is("sAscending" + to_string(vIndex)));
        } else if (w->mDBObjectApplication->get("sSort" + to_string(vIndex)) == "sIn") {
            mIn->setText(vPrefix + "In/Out");
            mIn->setTextOn(vPrefix + "In/Out");
            mIn->setTextOff(vPrefix + "In/Out");
            mIn->setChecked(w->mDBObjectApplication->is("sAscending" + to_string(vIndex)));
        }
        vPrefix = "";
    }
    requestLayout();
}

//*******************************************************************************************
//**************************************  OnClickListener  **********************************
//*******************************************************************************************
void WidgetHome::onClick(View* vView)
{
    if (vView == mCategoryId) {
        w->mNActivity->sendOp(0, w->mOpUnitUIId, w->w->mNEta00, new OpMessage("sCategoryId", "", "", "" , "", mSort == "sCategoryId" ? mCategoryId->isChecked() : !mCategoryId->isChecked() ));
    }
    if (vView == mTitle) {
        w->mNActivity->sendOp(0, w->mOpUnitUIId, w->w->mNEta00, new OpMessage("sTitle", "", "", "" , "", mSort == "sTitle" ? mTitle->isChecked() : !mTitle->isChecked() ));
    }
    if (vView == mIn) {
        w->mNActivity->sendOp(0, w->mOpUnitUIId, w->w->mNEta00, new OpMessage("sIn", "", "", "" , "", mSort == "sIn" ? mIn->isChecked() : !mIn->isChecked() ));
    }
}

//*******************************************************************************************
//**************************************  OnTouchListener  **********************************
//*******************************************************************************************
bool WidgetHome::onTouch(View* vView, MotionEvent* ev)
{
    bool vIsChecked;
    Wrapper* vWrapper = w;
    String vSort = mSort;

    if (w->mTouchState == 1 && vView == mCategoryId) {
        w->mTouchState = 2;
        vIsChecked = mCategoryId->isChecked();
        w->mEventAction = function<void()>([vWrapper,vSort,vIsChecked]()->void{
            vWrapper->mNActivity->sendOp(0, vWrapper->mOpUnitUIId, vWrapper->w->mNEta00, new OpMessage("sCategoryId", "", "", "" , "", vSort == "sCategoryId" ? !vIsChecked : vIsChecked ));
        });
    }
    if (w->mTouchState == 1 && vView == mTitle) {
        w->mTouchState = 2;
        vIsChecked = mTitle->isChecked();
        w->mEventAction = function<void()>([vWrapper,vSort,vIsChecked]()->void{
            vWrapper->mNActivity->sendOp(0, vWrapper->mOpUnitUIId, vWrapper->w->mNEta00, new OpMessage("sTitle", "", "", "" , "", vSort == "sTitle" ? !vIsChecked : vIsChecked ));
        });
    }
    if (w->mTouchState == 1 && vView == mIn) {
        w->mTouchState = 2;
        vIsChecked = mIn->isChecked();
        w->mEventAction = function<void()>([vWrapper,vSort,vIsChecked]()->void{
            vWrapper->mNActivity->sendOp(0, vWrapper->mOpUnitUIId, vWrapper->w->mNEta00, new OpMessage("sIn", "", "", "" , "", vSort == "sIn" ? !vIsChecked : vIsChecked ));
        });
    }
    if (w->mTouchState == 3) {
        w->mTouchState = 0;
    }
    return true;
}

} // End namespace
