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
    mStateListCheck = new StateListDrawable*[2]();
    mStateListBuzz = new StateListDrawable*[2]();

    mStateListCheck[0] = new StateListDrawable();
    mStateListCheck[0]->addState(vector<int>() = { R::attr::state_enabled, R::attr::state_checked }, w->maDrawable[6]);
    mStateListCheck[0]->addState(vector<int>() = { R::attr::state_enabled }, w->maDrawable[5]);

    mStateListBuzz[0] = new StateListDrawable();
    mStateListBuzz[0]->addState(vector<int>() = { R::attr::state_checked  }, w->maDrawable[1]);
    mStateListBuzz[0]->addState(vector<int>(), w->maDrawable[0]);

    mStateListCheck[1] = new StateListDrawable();
    mStateListCheck[1]->addState(vector<int>() = { R::attr::state_enabled, R::attr::state_checked }, w->maDrawable[4]);
    mStateListCheck[1]->addState(vector<int>() = { R::attr::state_enabled }, w->maDrawable[3]);

    mStateListBuzz[1] = new StateListDrawable();
    mStateListBuzz[1]->addState(vector<int>() = { R::attr::state_enabled, R::attr::state_checked  }, w->maDrawable[1]);
    mStateListBuzz[1]->addState(vector<int>() = { R::attr::state_enabled }, w->maDrawable[2]);
    mStateListBuzz[1]->addState(vector<int>(), w->maDrawable[0]);

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
        if (mStateListBuzz[0]) {
           delete mStateListBuzz[0];
        }
        if (mStateListBuzz[1]) {
           delete mStateListBuzz[1];
        }
        delete[] mStateListBuzz;
    }
    if (mStateListCheck) {
        if (mStateListCheck[0]) {
           delete mStateListCheck[0];
        }
        if (mStateListCheck[1]) {
           delete mStateListCheck[1];
        }
       delete[] mStateListCheck;
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
    if (mRight) {
       delete mRight;
    }
    if (mLeft) {
       delete mLeft;
    }
}

void WidgetMessage::render()
{
    LinearLayout::LayoutParams vLayoutParams1 = LinearLayout::LayoutParams((int)(27*w->mcDensity), LinearLayout::LayoutParams::MATCH_PARENT);
    vLayoutParams1.setMargins(0, 0, 0, 0);
    mCategory->setLayoutParams(&vLayoutParams1);
    mCategory->setPadding((int)(5*w->mcDensity), 5, (int)(15*w->mcDensity), 5);
    mCategory->setMinimumHeight(w->maDrawable[3]->getIntrinsicHeight());
    mCategory->setBackgroundDrawable(nullptr);
    mCategory->setScaleType(ImageView::ScaleType::FIT_XY);
    mCategory->setOnClickListener(this);
    mCategory->setOnTouchListener(this);

    LinearLayout::LayoutParams vLayoutParams2 = LinearLayout::LayoutParams(0, LinearLayout::LayoutParams::WRAP_CONTENT, 1);
    mText->setLayoutParams(&vLayoutParams2);
    mText->setGravity(Gravity::LEFT|Gravity::CLIP_HORIZONTAL|Gravity::CENTER_VERTICAL);
    mText->setPadding(5,5,5,5);
    mText->setMinimumHeight(w->maDrawable[3]->getIntrinsicHeight());
    mText->setLines(1);
    mText->setBackgroundDrawable(nullptr);
    mText->setTextColor(w->maColor[Theme::kColorMessageText]);
    mText->setTextSize(w->mcTextSize);
    mText->setOnClickListener(this);
    mText->setOnTouchListener(this);

    ViewGroup::LayoutParams vLayoutParams3 = ViewGroup::LayoutParams(w->maDrawable[3]->getIntrinsicWidth(), w->maDrawable[3]->getIntrinsicHeight());
    mCheck->setLayoutParams(&vLayoutParams3);
    mCheck->setPadding(0,0,0,0);
    mCheck->setBackgroundDrawable(nullptr);
    //mCheck->setButtonDrawable(mStateListCheck);
    mCheck->setText("");
    mCheck->setTextOn("");
    mCheck->setTextOff("");
    mCheck->setEnabled(true);
    mCheck->setOnClickListener(this);
    mCheck->setOnTouchListener(this);

    ViewGroup::LayoutParams vLayoutParams4 = ViewGroup::LayoutParams(w->maDrawable[3]->getIntrinsicWidth(), w->maDrawable[3]->getIntrinsicHeight());
    mBuzz->setLayoutParams(&vLayoutParams4);
    mBuzz->setPadding(0,0,0,0);
    mBuzz->setBackgroundDrawable(nullptr);
    //mBuzz->setButtonDrawable(mStateListBuzz);
    mBuzz->setText("");
    mBuzz->setTextOn("");
    mBuzz->setTextOff("");
    mBuzz->setOnClickListener(this);
    mBuzz->setOnTouchListener(this);

    WidgetMessage::LayoutParams vLayoutParams5 = WidgetMessage::LayoutParams(0, LinearLayout::LayoutParams::WRAP_CONTENT, 1);
    mLeft->setLayoutParams(&vLayoutParams5);
    mLeft->setGravity(Gravity::LEFT);
    mLeft->setOrientation(LinearLayout::HORIZONTAL);
    mLeft->setPadding(0,0,0,0);
    mLeft->setOnTouchListener(this);

    WidgetMessage::LayoutParams vLayoutParams6 = WidgetMessage::LayoutParams(LinearLayout::LayoutParams::WRAP_CONTENT, LinearLayout::LayoutParams::WRAP_CONTENT);
    mRight->setLayoutParams(&vLayoutParams6);
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

void WidgetMessage::init(nuint vcView, nuint vcDBObjectId)
{
    mcDBObjectId = vcDBObjectId;
    mcView = vcView;

    mDBObject = w->mBOHandlerMessage->get(mcDBObjectId);
    mIsInbound = mDBObject->is("sIn");
    mcCategoryId = mDBObject->count("sCategoryId");

    mCategory->setImageDrawable(new ColorDrawable(w->maColor[Theme::kColorCategoryBackground + mcCategoryId*3]));
    mText->setText(mDBObject->get("sTitle"));
    mCheck->setChecked(mDBObject->is("sEnabled"));
    mCheck->setButtonDrawable(mStateListCheck[mIsInbound*1]);
    mBuzz->setEnabled((mIsInbound || mDBObject->is("sBuzzed")) && mDBObject->is("sEnabled"));
    mBuzz->setChecked(mDBObject->is("sBuzzed"));
    mBuzz->setButtonDrawable(mStateListBuzz[mIsInbound*1]);

    requestLayout();
}

WidgetMessageInbound::WidgetMessageInbound(Wrapper* const w)
    : WidgetMessage(w)
{
    render();
}

WidgetMessageInbound::~WidgetMessageInbound()
{
}

WidgetMessageOutbound::WidgetMessageOutbound(Wrapper* const w)
	: WidgetMessage(w)
{
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
        w->mNActivity->setView(Wrapper::kViewDetails, mcDBObjectId);
        w->mNActivity->sendOp(0, w->mOpUnitUIId, w->w->mNIota00, new OpParam(Wrapper::kViewDetails, mcDBObjectId));
    }
    if (vView == mCheck) {
        w->mNActivity->sendOp(0, w->mOpUnitUIId, w->w->mNXi00, new OpParam(mcDBObjectId, true));
    }
    if (vView == mBuzz) {
        w->mNActivity->sendOp(0, w->mOpUnitUIId, w->w->mNDzeta00, new OpParam(mcDBObjectId, mIsInbound));
    }
}

//*******************************************************************************************
//**************************************  OnTouchListener  **********************************
//*******************************************************************************************
bool WidgetMessage::onTouch(View* vView, MotionEvent* event)
{
    Wrapper* vWrapper = w;
    nuint vcDBObjectId = mcDBObjectId;
    bool vIsInbound = mIsInbound;

    if (w->mTouchState == 1 && vView == mText) {
        w->mTouchState = 2;
        w->mEventAction = function<void()>([vWrapper,vcDBObjectId,vIsInbound]()->void{
            vWrapper->mNActivity->setView(Wrapper::kViewDetails, vcDBObjectId);
            vWrapper->mNActivity->sendOp(0, vWrapper->mOpUnitUIId, vWrapper->w->mNIota00, new OpParam(Wrapper::kViewDetails, vcDBObjectId));
        });
    }
    if (w->mTouchState == 1 && vView == mCheck) {
        w->mTouchState = 2;
        w->mEventAction = function<void()>([vWrapper,vcDBObjectId,vIsInbound]()->void{
            vWrapper->mNActivity->sendOp(0, vWrapper->mOpUnitUIId, vWrapper->w->mNXi00, new OpParam(vcDBObjectId, true));
        });
    }
    if (w->mTouchState == 1 && vView == mBuzz) {
        w->mTouchState = 2;
        w->mEventAction = function<void()>([vWrapper,vcDBObjectId,vIsInbound]()->void{
            vWrapper->mNActivity->sendOp(0, vWrapper->mOpUnitUIId, vWrapper->w->mNDzeta00, new OpParam(vcDBObjectId, vIsInbound));
        });
    }
    if (w->mTouchState == 3) {
        w->mTouchState = 0;
    }
    return true;
}

} // End namespace
