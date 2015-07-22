#include "Common.h"
#include "Theme.h"

namespace NSDEVICE
{

WidgetMessageDetails::WidgetMessageDetails(Wrapper* const w)
	: Widget(w), mcPadding((nint)(10*w->mcDensity)), mDBObject(nullptr), mcCategoryId(0), mCategory(nullptr), mTitle(nullptr), mText(nullptr), mLink(nullptr)
{
    mCategory = new TextView(w->mApplication);
    mTitle = new TextView(w->mApplication);
    mText = new TextView(w->mApplication);
    mLink = new TextView(w->mApplication);

    setGravity(Gravity::LEFT|Gravity::TOP);
    setOrientation(LinearLayout::VERTICAL);
    setLayoutParams(new LinearLayout::LayoutParams(0, LinearLayout::LayoutParams::MATCH_PARENT, 1));
    setPadding(mcPadding, mcPadding, mcPadding, mcPadding);
    setOnTouchListener(this);

    mCategory->setGravity(Gravity::START);
    mCategory->setPadding(mcPadding, mcPadding, mcPadding, mcPadding);
    mCategory->setLayoutParams(new LinearLayout::LayoutParams(LinearLayout::LayoutParams::MATCH_PARENT, LinearLayout::LayoutParams::WRAP_CONTENT));
    mCategory->setTextColor(w->maColor[Theme::kColorMessageText]);
    mCategory->setTextSize(w->mcTextSize);
    mCategory->setOnTouchListener(this);

    mTitle->setGravity(Gravity::START);
    mTitle->setPadding(mcPadding, mcPadding, mcPadding, mcPadding);
    mTitle->setLayoutParams(new LinearLayout::LayoutParams(LinearLayout::LayoutParams::MATCH_PARENT, LinearLayout::LayoutParams::WRAP_CONTENT));
    mTitle->setTextColor(w->maColor[Theme::kColorMessageText]);
    mTitle->setTextSize(w->mcTextSize);
    mTitle->setOnTouchListener(this);

    mText->setGravity(Gravity::START);
    mText->setPadding(mcPadding, mcPadding, mcPadding, mcPadding);
    mText->setLayoutParams(new LinearLayout::LayoutParams(LinearLayout::LayoutParams::MATCH_PARENT, LinearLayout::LayoutParams::WRAP_CONTENT));
    mText->setTextColor(w->maColor[Theme::kColorMessageText]);
    mText->setTextSize(w->mcTextSize);
    mText->setOnTouchListener(this);

    mLink->setGravity(Gravity::START);
    mLink->setPadding(mcPadding, mcPadding, mcPadding, mcPadding);
    mLink->setLayoutParams(new LinearLayout::LayoutParams(LinearLayout::LayoutParams::MATCH_PARENT, LinearLayout::LayoutParams::WRAP_CONTENT));
    mLink->setTextColor(w->maColor[Theme::kColorMessageText]);
    mLink->setTextSize(w->mcTextSize);
    mLink->setOnTouchListener(this);

    addView(mCategory);
    addView(mTitle);
    addView(mText);
    addView(mLink);
}

WidgetMessageDetails::~WidgetMessageDetails()
{
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
}

void WidgetMessageDetails::init(nuint vcView, nuint vcDBObjectId)
{
    mcView = vcView;
    mcDBObjectId = vcDBObjectId;
    mDBObject = w->mBOHandlerMessage->get(mcDBObjectId);
    mcCategoryId = (nint)to_long(mDBObject->get("sCategoryId"));

    mCategory->setBackgroundColor(w->maColor[Theme::kColorCategoryBackground + mcCategoryId*3]);
    mCategory->setText(w->maCategory[mcCategoryId]);
    mTitle->setText(mDBObject->get("sTitle"));
    mText->setText(mDBObject->get("text"));
    mLink->setText(mDBObject->get("link"));

    requestLayout();
}

//*******************************************************************************************
//**************************************  OnTouchListener  **********************************
//*******************************************************************************************
bool WidgetMessageDetails::onTouch(View* vView, MotionEvent* event)
{
    if (w->mTouchState == 3) {
        w->mTouchState = 0;
    }
    return true;
}

} // End namespace
