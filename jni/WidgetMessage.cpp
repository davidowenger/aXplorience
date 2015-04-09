#include "Common.h"
#include "Theme.h"

namespace NSDEVICE
{

WidgetMessage::WidgetMessage(Wrapper* const w)
	: Widget(w), mcPadding((nint)(10*w->mcDensity)), mDBObject(nullptr), mcCategoryId(0), mIsInbound(true), mcIsEnabled(false),
	  mLeft(nullptr), mRight(nullptr), mCategory(nullptr), mText(nullptr), mCheck(nullptr), mBuzz(nullptr), mStateListCheck(nullptr), mStateListBuzz(nullptr)
{
    mLeft = new LinearLayout(w->mApplication);
    mRight = new LinearLayout(w->mApplication);
    mCategory = new ImageButton(w->mApplication);
    mText = new Button(w->mApplication);
    mCheck = new ToggleButton(w->mApplication);
    mBuzz = new ToggleButton(w->mApplication);

    LinearLayout::LayoutParams vLayoutParams = LinearLayout::LayoutParams(ViewGroup::LayoutParams::MATCH_PARENT, LinearLayout::LayoutParams::WRAP_CONTENT);
    vLayoutParams.setMargins(5, 5, 5, 5);

    setGravity(Gravity::LEFT);
    setOrientation(LinearLayout::HORIZONTAL);
    setLayoutParams(&vLayoutParams);
    setPadding(0,0,0,0);
    setBackgroundColor(w->maColor[Theme::kColorMessageBackground]);
    setOnClickListener(this);
    setOnTouchListener(this);
}

WidgetMessage::~WidgetMessage()
{
    if (mDBObject) {
       delete mDBObject;
    }
    if (mStateListBuzz) {
       delete mStateListBuzz;
    }
    if (mStateListCheck) {
       delete mStateListCheck;
    }
    if (mBuzz) {
       mBuzz->setButtonDrawable(nullptr);
       delete mBuzz;
    }
    if (mCheck) {
       mCheck->setButtonDrawable(nullptr);
       delete mCheck;
    }
    if (mText) {
       delete mText;
    }
    if (mCategory) {
       delete mCategory;
    }
}

void WidgetMessage::init(nuint vcView, nuint vcDBObjectId)
{
    mcView = vcView;
    mcDBObjectId = vcDBObjectId;

    mDBObject = w->mBOHandlerMessage->get(mcDBObjectId);
    mcCategoryId = to_long(mDBObject->get("id_cat"));

    mCategory->setImageDrawable(new ColorDrawable(w->maColor[Theme::kColorCategoryBackground + mcCategoryId*3]));
    mText->setText(mDBObject->get("title"));
    mCheck->setChecked(mDBObject->get("sEnabled") == w->dbh->TRUE);
    mBuzz->setEnabled(mIsInbound && mCheck->isChecked());
    mBuzz->setChecked(mDBObject->get("sBuzzed") == w->dbh->TRUE);

    requestLayout();
}

bool WidgetMessage::onInterceptTouchEvent(MotionEvent* ev)
{
//    return onTouch(this, ev);
    return false;
}

void WidgetMessage::render()
{
    LinearLayout::LayoutParams vLayoutParamsCategory = LinearLayout::LayoutParams((int)(27*w->mcDensity), LinearLayout::LayoutParams::MATCH_PARENT);
    vLayoutParamsCategory.setMargins(0, 0, 0, 0);

    mCategory->setLayoutParams(&vLayoutParamsCategory);
    mCategory->setPadding((int)(5*w->mcDensity), 5, (int)(15*w->mcDensity), 5);
    mCategory->setMinimumHeight(w->maDrawable[3]->getIntrinsicHeight());
    mCategory->setBackgroundDrawable(nullptr);
    mCategory->setScaleType(ImageView::ScaleType::FIT_XY);
    mCategory->setOnClickListener(this);
    mCategory->setOnTouchListener(this);

    mText->setGravity(Gravity::LEFT|Gravity::CLIP_HORIZONTAL|Gravity::CENTER_VERTICAL);
    mText->setLayoutParams(new LinearLayout::LayoutParams(0, LinearLayout::LayoutParams::WRAP_CONTENT, 1));
    mText->setPadding(5,5,5,5);
    mText->setMinimumHeight(w->maDrawable[3]->getIntrinsicHeight());
    mText->setLines(1);
    mText->setBackgroundDrawable(nullptr);
    mText->setTextColor(w->maColor[Theme::kColorMessageText]);
    mText->setTextSize(w->mcTextSize);
    mText->setOnClickListener(this);
    mText->setOnTouchListener(this);

    mCheck->setLayoutParams(new ViewGroup::LayoutParams(w->maDrawable[3]->getIntrinsicWidth(), w->maDrawable[3]->getIntrinsicHeight()));
    mCheck->setPadding(0,0,0,0);
    mCheck->setBackgroundDrawable(nullptr);
    mCheck->setButtonDrawable(mStateListCheck);
    mCheck->setText("");
    mCheck->setTextOn("");
    mCheck->setTextOff("");
    mCheck->setEnabled(true);
    mCheck->setOnClickListener(this);
    mCheck->setOnTouchListener(this);

    mBuzz->setOnClickListener(this);
    mBuzz->setLayoutParams(new ViewGroup::LayoutParams(w->maDrawable[3]->getIntrinsicWidth(), w->maDrawable[3]->getIntrinsicHeight()));
    mBuzz->setPadding(0,0,0,0);
    mBuzz->setBackgroundDrawable(nullptr);
    mBuzz->setButtonDrawable(mStateListBuzz);
    mBuzz->setText("");
    mBuzz->setTextOn("");
    mBuzz->setTextOff("");
    mBuzz->setOnClickListener(this);
    mBuzz->setOnTouchListener(this);

    mLeft->setGravity(Gravity::LEFT);
    mLeft->setOrientation(LinearLayout::HORIZONTAL);
    mLeft->setLayoutParams(new WidgetMessage::LayoutParams(0, LinearLayout::LayoutParams::WRAP_CONTENT, 1));
    mLeft->setPadding(0,0,0,0);
    mLeft->setOnTouchListener(this);

    mRight->setGravity(Gravity::LEFT);
    mRight->setOrientation(LinearLayout::HORIZONTAL);
    mRight->setLayoutParams(new WidgetMessage::LayoutParams(LinearLayout::LayoutParams::WRAP_CONTENT, LinearLayout::LayoutParams::WRAP_CONTENT));
    mRight->setPadding(0,0,0,0);
    mRight->setOnTouchListener(this);

    mLeft->addView(mCategory);
    mLeft->addView(mText);
    mRight->addView(mCheck);
    mRight->addView(mBuzz);

    addView(mLeft);
    addView(mRight);
}

WidgetMessageInbound::WidgetMessageInbound(Wrapper* const w)
    : WidgetMessage(w)
{
    mIsInbound = true;

    mStateListCheck = new StateListDrawable();
    mStateListCheck->addState(vector<int>() = { R::attr::state_enabled, R::attr::state_checked }, w->maDrawable[4]);
    mStateListCheck->addState(vector<int>() = { R::attr::state_enabled }, w->maDrawable[3]);

    mStateListBuzz = new StateListDrawable();
    mStateListBuzz->addState(vector<int>() = { R::attr::state_enabled, R::attr::state_checked  }, w->maDrawable[1]);
    mStateListBuzz->addState(vector<int>() = { R::attr::state_enabled }, w->maDrawable[2]);
    mStateListBuzz->addState(vector<int>(), w->maDrawable[0]);

    render();
}

WidgetMessageInbound::~WidgetMessageInbound()
{
}

WidgetMessageOutbound::WidgetMessageOutbound(Wrapper* const w)
	: WidgetMessage(w)
{
    mIsInbound = false;

    mStateListCheck = new StateListDrawable();
    mStateListCheck->addState(vector<int>() = { R::attr::state_enabled, R::attr::state_checked }, w->maDrawable[6]);
    mStateListCheck->addState(vector<int>() = { R::attr::state_enabled }, w->maDrawable[5]);

    mStateListBuzz = new StateListDrawable();
    mStateListBuzz->addState(vector<int>() = { R::attr::state_checked  }, w->maDrawable[1]);
    mStateListBuzz->addState(vector<int>(), w->maDrawable[0]);

    render();
}

WidgetMessageOutbound::~WidgetMessageOutbound()
{
}

//*******************************************************************************************
//**************************************  OnClickListener  **********************************
//*******************************************************************************************
void WidgetMessage::onClick(View* vView)
{
    if (vView == mText) {
        w->mNActivity->sendOp(0, w->mOpUnitCoreId, w->w->mNIota00, new OpParam(Wrapper::kViewDetails, mcDBObjectId));
    }
    if (vView == mCheck) {
        bool checked = mCheck->isChecked();
        mBuzz->setEnabled(mIsInbound && checked);
        w->mNActivity->sendOp(0, w->mOpUnitCoreId, w->w->mNXi00, new OpParam(mcDBObjectId, checked));
    }
    if (vView == mBuzz) {
        bool checked = mBuzz->isChecked();
        w->mNActivity->sendOp(0, w->mOpUnitCoreId, w->w->mNDzeta00, new OpParam(mcDBObjectId, checked));
    }
}

//*******************************************************************************************
//**************************************  OnTouchListener  **********************************
//*******************************************************************************************
bool WidgetMessage::onTouch(View* vView, MotionEvent* event)
{
    if (w->maFragmentView[w->mcView]->mTouchState == 0) {
        w->maFragmentView[w->mcView]->mTouchState = 1;
        w->maFragmentView[w->mcView]->mViewSource = vView;
    }
    return w->maGestureDetector[w->mcView]->onTouchEvent(event);
}

} // End namespace
