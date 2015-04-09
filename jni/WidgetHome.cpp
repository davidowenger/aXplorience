#include "Common.h"
#include "Theme.h"

namespace NSDEVICE
{

WidgetHome::WidgetHome(Wrapper* const w)
	: Widget(w), mHeader(nullptr), mScrollView(nullptr), mTextView(nullptr), mGestureDetector(nullptr), mcPadding((nint)(5*w->mcDensity))
{
    mHeader = new LinearLayout(w->mApplication);
    mScrollView = new ScrollView(w->mApplication);
    mTextView = new TextView(w->mApplication);

    setGravity(Gravity::LEFT);
    setOrientation(LinearLayout::VERTICAL);
    setLayoutParams(new LinearLayout::LayoutParams(0, LinearLayout::LayoutParams::MATCH_PARENT, 1));
    setPadding(mcPadding, mcPadding, mcPadding, mcPadding);
    setBackgroundColor(w->maColor[Theme::kColorApplicationBackground]);
    setOnTouchListener(this);

    mHeader->setOrientation(LinearLayout::HORIZONTAL);
    mHeader->setLayoutParams(new LinearLayout::LayoutParams(LinearLayout::LayoutParams::MATCH_PARENT, LinearLayout::LayoutParams::WRAP_CONTENT));

    mTextView->setGravity(Gravity::START);
    mTextView->setLayoutParams(new LinearLayout::LayoutParams(LinearLayout::LayoutParams::MATCH_PARENT, LinearLayout::LayoutParams::WRAP_CONTENT));
    mTextView->setPadding(mcPadding, mcPadding, mcPadding, mcPadding);
    mTextView->setTextSize(w->mcTextSize);
    mTextView->setTextColor(w->maColor[Theme::kColorMessageText]);
    mTextView->setText("Messages:");

    w->mMessageLayout->setGravity(Gravity::TOP|Gravity::LEFT);
    w->mMessageLayout->setOrientation(LinearLayout::VERTICAL);
    w->mMessageLayout->setLayoutParams(new LinearLayout::LayoutParams(LinearLayout::LayoutParams::MATCH_PARENT, LinearLayout::LayoutParams::WRAP_CONTENT));

    mHeader->addView(mTextView);
    mScrollView->addView(w->mMessageLayout);
    addView(mHeader);
    addView(mScrollView);
}

WidgetHome::~WidgetHome()
{
    if (mGestureDetector) {
       delete mGestureDetector;
    }
    if (mTextView) {
       delete mTextView;
    }
    if (mScrollView) {
       delete mScrollView;
    }
    if (mHeader) {
       delete mHeader;
    }
}

void WidgetHome::init(nuint vcView, nuint vcDBObjectId)
{
    mcView = vcView;
    mcDBObjectId = vcDBObjectId;
    requestLayout();
}

//*******************************************************************************************
//**************************************  OnTouchListener  **********************************
//*******************************************************************************************
bool WidgetHome::onTouch(View* vView, MotionEvent* event)
{
    if (w->maFragmentView[w->mcView]->mTouchState == 0) {
        w->maFragmentView[w->mcView]->mTouchState = 1;
        w->maFragmentView[w->mcView]->mViewSource = vView;
    }
    return w->maGestureDetector[w->mcView]->onTouchEvent(event);
}

} // End namespace
