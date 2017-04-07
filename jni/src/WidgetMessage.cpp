#include "Common.h"
#include "Theme.h"

namespace NSDEVICE
{

WidgetMessage::WidgetMessage(Wrapper* const w) :
    Widget(w), mcPadding((nint)(10*w->mcDensity)), mcCategoryId(0), mIsInbound(true), mIsEnabled(false), mIsBuzzed(false),
    mLeft(nullptr), mRight(nullptr), mCategory(nullptr), mText(nullptr), mState(nullptr)
{
    mLeft = new LinearLayout(w->mApplication);
    mRight = new LinearLayout(w->mApplication);
    mCategory = new ImageButton(w->mApplication);
    mText = new Button(w->mApplication);
    mState = new ImageButton(w->mApplication);

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
    if (mState) {
        delete mState;
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
    mText->setAllCaps(false);
    mText->setBackgroundDrawable(nullptr);
    mText->setTypeface(Typeface::DEFAULT);
    mText->setTextColor(w->maColor[Theme::kColorMessageText]);
    mText->setTextSize(w->mcTextSize);
    mText->setOnTouchListener(this);

    ViewGroup::LayoutParams vCheckParams = ViewGroup::LayoutParams(w->maDrawable[0]->getIntrinsicWidth(), w->maDrawable[0]->getIntrinsicHeight());
    mState->setLayoutParams(&vCheckParams);
    mState->setPadding(0,0,0,0);
    mState->setBackgroundDrawable(nullptr);
    mState->setScaleType(ImageView::ScaleType::FIT_XY);
    mState->setOnTouchListener(this);

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
    mRight->addView(mState);

    addView(mLeft);
    addView(mRight);
}

void WidgetMessage::update(DBObject* vDBObject)
{
    mcDBObjectId = vDBObject->mId;
    mIsInbound = (vDBObject->get("Type") == "0");
    mIsEnabled = vDBObject->is("Enabled");
    mIsBuzzed = vDBObject->is("Buzzed");
    mcCategoryId = vDBObject->count("CategoryId");

    ColorDrawable vColorDrawable = ColorDrawable(w->maColor[Theme::kColorCategoryBackground + mcCategoryId*3]);
    mCategory->setImageDrawable(&vColorDrawable);
    mText->setText(vDBObject->get("Title"));
    mState->setImageDrawable(w->maDrawable[ mIsEnabled ? 2 - mIsBuzzed : 0 ]);
}

//*******************************************************************************************
//**************************************  OnTouchListener  **********************************
//*******************************************************************************************
bool WidgetMessage::onTouch(View* vView, MotionEvent* vEvent)
{
    if (vEvent->getActionMasked() == MotionEvent::ACTION_UP) {
        if (vView == mCategory) {
            w->mNActivity->sendOp(w->mOpUnitDBId, w->mNWrapper->mNKrossWrapper->mNBeta00, new OpParam(k::ViewDetails, mcDBObjectId));
        }
        if (vView == mText) {
            w->mNActivity->sendOp(w->mOpUnitDBId, w->mNWrapper->mNKrossWrapper->mNBeta00, new OpParam(k::ViewDetails, mcDBObjectId));
        }
        if (vView == mState) {
            mIsEnabled = !mIsEnabled;
            w->mNActivity->sendOp(w->mOpUnitDBId, w->mNWrapper->mNKrossWrapper->mNKappa00, new OpParam(mcDBObjectId, mIsEnabled));
        }
    }
    return true;
}

} // End namespace
