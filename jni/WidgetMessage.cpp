#include "Common.h"
#include "Theme.h"

namespace NSDEVICE
{

WidgetMessage::WidgetMessage(Wrapper* const w)
    : Widget(w), mcPadding((nint)(10*w->mcDensity)), mcCategoryId(0), mIsInbound(true), mIsEnabled(false), mIsBuzzed(false),
      mLeft(nullptr), mRight(nullptr), mCategory(nullptr), mText(nullptr), mCheck(nullptr), mBuzz(nullptr)
{
    mLeft = new LinearLayout(w->mApplication);
    mRight = new LinearLayout(w->mApplication);
    mCategory = new ImageButton(w->mApplication);
    mText = new Button(w->mApplication);
    mCheck = new ImageButton(w->mApplication);
    mBuzz = new ImageButton(w->mApplication);

    LinearLayout::LayoutParams vLayoutParams = LinearLayout::LayoutParams(ViewGroup::LayoutParams::MATCH_PARENT, LinearLayout::LayoutParams::WRAP_CONTENT);
    vLayoutParams.setMargins(5, 5, 5, 5);

    setGravity(Gravity::LEFT);
    setOrientation(LinearLayout::HORIZONTAL);
    setLayoutParams(&vLayoutParams);
    setPadding(0,0,0,0);
    setBackgroundColor(w->maColor[Theme::kColorMessageBackground]);
    setOnTouchListener(this);

    render();
}

WidgetMessage::~WidgetMessage()
{
    if (mBuzz) {
        delete mBuzz;
    }
    if (mCheck) {
        delete mCheck;
    }
    if (mText) {
        delete mText;
    }
    if (mCategory) {
        delete mCategory;
    }
    if (mRight) {
        delete mRight;
    }
    if (mLeft) {
        delete mLeft;
    }
}

void WidgetMessage::render()
{
    LinearLayout::LayoutParams vCategoryParams = LinearLayout::LayoutParams((int)(27*w->mcDensity), LinearLayout::LayoutParams::MATCH_PARENT);
    vCategoryParams.setMargins(0, 0, 0, 0);
    mCategory->setLayoutParams(&vCategoryParams);
    mCategory->setPadding((int)(5*w->mcDensity), 5, (int)(15*w->mcDensity), 5);
    mCategory->setMinimumHeight(w->maDrawable[3]->getIntrinsicHeight());
    mCategory->setBackgroundDrawable(nullptr);
    mCategory->setScaleType(ImageView::ScaleType::FIT_XY);
    mCategory->setOnTouchListener(this);

    LinearLayout::LayoutParams vTextParams = LinearLayout::LayoutParams(0, LinearLayout::LayoutParams::WRAP_CONTENT, 1);
    mText->setLayoutParams(&vTextParams);
    mText->setGravity(Gravity::LEFT|Gravity::CLIP_HORIZONTAL|Gravity::CENTER_VERTICAL);
    mText->setPadding(5,5,5,5);
    mText->setMinimumHeight(w->maDrawable[3]->getIntrinsicHeight());
    mText->setLines(1);
    mText->setBackgroundDrawable(nullptr);
    mText->setTextColor(w->maColor[Theme::kColorMessageText]);
    mText->setTextSize(w->mcTextSize);
    mText->setOnTouchListener(this);

    ViewGroup::LayoutParams vCheckParams = ViewGroup::LayoutParams(w->maDrawable[3]->getIntrinsicWidth(), w->maDrawable[3]->getIntrinsicHeight());
    mCheck->setLayoutParams(&vCheckParams);
    mCheck->setPadding(0,0,0,0);
    mCheck->setBackgroundDrawable(nullptr);
    mCheck->setScaleType(ImageView::ScaleType::FIT_XY);
    mCheck->setOnTouchListener(this);

    ViewGroup::LayoutParams vBuzzParams = ViewGroup::LayoutParams(w->maDrawable[3]->getIntrinsicWidth(), w->maDrawable[3]->getIntrinsicHeight());
    mBuzz->setLayoutParams(&vBuzzParams);
    mBuzz->setPadding(0,0,0,0);
    mBuzz->setBackgroundDrawable(nullptr);
    mCheck->setScaleType(ImageView::ScaleType::FIT_XY);
    mBuzz->setOnTouchListener(this);

    LinearLayout::LayoutParams vLeftParams = LinearLayout::LayoutParams(0, LinearLayout::LayoutParams::WRAP_CONTENT, 1);
    mLeft->setLayoutParams(&vLeftParams);
    mLeft->setGravity(Gravity::LEFT);
    mLeft->setOrientation(LinearLayout::HORIZONTAL);
    mLeft->setPadding(0,0,0,0);
    mLeft->setOnTouchListener(this);

    LinearLayout::LayoutParams vRightParams = LinearLayout::LayoutParams(LinearLayout::LayoutParams::WRAP_CONTENT, LinearLayout::LayoutParams::WRAP_CONTENT);
    mRight->setLayoutParams(&vRightParams);
    mRight->setGravity(Gravity::LEFT);
    mRight->setOrientation(LinearLayout::HORIZONTAL);
    mRight->setPadding(0,0,0,0);
    mRight->setOnTouchListener(this);

    mLeft->addView(mCategory);
    mLeft->addView(mText);
    mRight->addView(mCheck);
    mRight->addView(mBuzz);

    addView(mLeft);
    addView(mRight);
}

void WidgetMessage::update(DBObject* vDBObject)
{
    mcDBObjectId = vDBObject->mId;
    mIsInbound = vDBObject->is("sIn");
    mIsEnabled = vDBObject->is("sEnabled");
    mIsBuzzed = vDBObject->is("sBuzzed");
    mcCategoryId = vDBObject->count("sCategoryId");

    ColorDrawable vColorDrawable = ColorDrawable(w->maColor[Theme::kColorCategoryBackground + mcCategoryId*3]);
    mCategory->setImageDrawable(&vColorDrawable);
    mText->setText(vDBObject->get("sTitle"));
    mCheck->setImageDrawable(w->maDrawable[ mIsInbound ? 3 + mIsEnabled : 5 + mIsEnabled ]);
    mBuzz->setImageDrawable(w->maDrawable[ mIsInbound ? ( mIsEnabled ? 2 - mIsBuzzed : 0 ) : 0 + mIsBuzzed ]);
}

//*******************************************************************************************
//**************************************  OnTouchListener  **********************************
//*******************************************************************************************
bool WidgetMessage::onTouch(View* vView, MotionEvent* event)
{
    w->mEventLong0 = mcDBObjectId;
    w->mEventLong1 = mIsInbound;

    if (w->mTouchState == 1 && vView == mText) {
        w->mTouchState = 2;
        w->mEventAction = [](Wrapper* w)->void{
            w->mNActivity->sendOp(w->mOpUnitUIId, w->w->mNIota00, new OpParam(Wrapper::kViewDetails, w->mEventLong0));
        };
    }
    if (w->mTouchState == 1 && vView == mCheck) {
        w->mTouchState = 2;
        w->mEventAction = [](Wrapper* w)->void{
            w->mNActivity->sendOp(w->mOpUnitUIId, w->w->mNXi00, new OpParam(w->mEventLong0, true));
        };
    }
    if (w->mTouchState == 1 && vView == mBuzz) {
        w->mTouchState = 2;
        w->mEventAction = [](Wrapper* w)->void{
            w->mNActivity->sendOp(w->mOpUnitUIId, w->w->mNDzeta00, new OpParam(w->mEventLong0, w->mEventLong1));
        };
    }
    if (w->mTouchState == 3) {
        w->mTouchState = 0;
    }
    return true;
}

} // End namespace
