#include "Common.h"
#include "Theme.h"

namespace NSDEVICE
{

WidgetMessageDetails::WidgetMessageDetails(Wrapper* const w) :
    Widget(w), mcPadding((nint)(10*w->mcDensity)), mDBObject(nullptr), mcCategoryId(0),
    mLinearLayout(nullptr), mCategory(nullptr), mTitle(nullptr), mText(nullptr), mLink(nullptr)
{
    LinearLayout::LayoutParams vLayoutMargins(LinearLayout::LayoutParams::MATCH_PARENT, LinearLayout::LayoutParams::MATCH_PARENT);

    mLinearLayout = new LinearLayout(w->mApplication);
    mCategory = new TextView(w->mApplication);
    mTitle = new TextView(w->mApplication);
    mText = new TextView(w->mApplication);
    mLink = new TextView(w->mApplication);

    vLayoutMargins.setMargins(mcPadding, mcPadding, mcPadding, mcPadding);
    setLayoutParams(&vLayoutMargins);
    setPadding(mcPadding, mcPadding, mcPadding, mcPadding);
    setBackgroundColor(w->maColor[Theme::kColorTransparent]);
    setOnTouchListener(this);

    mLinearLayout->setLayoutParams(new LinearLayout::LayoutParams(LinearLayout::LayoutParams::MATCH_PARENT, LinearLayout::LayoutParams::MATCH_PARENT));
    mLinearLayout->setGravity(Gravity::LEFT|Gravity::TOP);
    mLinearLayout->setOrientation(LinearLayout::VERTICAL);
    mLinearLayout->setBackgroundColor(w->maColor[Theme::kColorApplicationBackground]);
    mLinearLayout->setOnTouchListener(this);

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

    mLinearLayout->addView(mCategory);
    mLinearLayout->addView(mTitle);
    mLinearLayout->addView(mText);
    mLinearLayout->addView(mLink);
    addView(mLinearLayout);
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

void WidgetMessageDetails::init(nuint vcView, DBObject* vDBObject)
{
    update(vDBObject);

    w->mMenu->setGroupVisible(k::ViewDelete, true);
    w->mMenu->setGroupVisible(k::ViewEdit, true);
    w->mMenu->setGroupVisible(k::ViewSave, false);
    w->mMenu->setGroupVisible(k::ViewList, false);
    w->mMenu->setGroupVisible(k::ViewAdd, true);

    w->mActionBar->setDisplayHomeAsUpEnabled(true);
    w->mActionBar->setHomeButtonEnabled(true);
}

void WidgetMessageDetails::update(DBObject* vDBObject)
{
    mcDBObjectId = vDBObject->mId;
    mcCategoryId = vDBObject->count("CategoryId");

    mCategory->setBackgroundColor(w->maColor[Theme::kColorCategoryBackground + mcCategoryId*3]);
    mCategory->setText(w->maCategory[mcCategoryId]);
    mTitle->setText(vDBObject->get("Title"));
    mText->setText(vDBObject->get("Text"));
    mLink->setText(vDBObject->get("Link"));
    requestLayout();
}

//*******************************************************************************************
//**************************************  OnTouchListener  **********************************
//*******************************************************************************************
bool WidgetMessageDetails::onTouch(View* vView, MotionEvent* event)
{
    return true;
}

} // End namespace
