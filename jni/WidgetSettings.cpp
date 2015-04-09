#include "Common.h"
#include "Theme.h"

namespace NSDEVICE
{

WidgetSettings::WidgetSettings(Wrapper* const w)
	: Widget(w), mTextView(nullptr), mGestureDetector(nullptr), mcPadding((nint)(10*w->mcDensity))
{
    mTextView = new TextView(w->mApplication);

    setGravity(Gravity::LEFT|Gravity::TOP);
    setOrientation(LinearLayout::VERTICAL);
    setLayoutParams(new LinearLayout::LayoutParams(0, LinearLayout::LayoutParams::MATCH_PARENT, 1));
    setPadding(mcPadding, mcPadding, mcPadding, mcPadding);
    setBackgroundColor(w->maColor[Theme::kColorApplicationBackground]);
    setOnTouchListener(this);

    mTextView->setGravity(Gravity::START);
    mTextView->setPadding(mcPadding, mcPadding, mcPadding, mcPadding);
    mTextView->setLayoutParams(new LinearLayout::LayoutParams(LinearLayout::LayoutParams::MATCH_PARENT, LinearLayout::LayoutParams::WRAP_CONTENT));
    mTextView->setTextSize(w->mcTextSize);
    mTextView->setTypeface(Typeface::DEFAULT);
    mTextView->setText("Be sure to enable Bluetooth. Use discoverability for your phone to be seen.");

    addView(mTextView);
}

WidgetSettings::~WidgetSettings()
{
    if (mTextView) {
       delete mTextView;
    }
}

void WidgetSettings::init(nuint vcView, nuint vcDBObjectId)
{
    mcView = vcView;
    mcDBObjectId = vcDBObjectId;
    requestLayout();
}

//*******************************************************************************************//
//**************************************  OnTouchListener  **********************************//
//*******************************************************************************************//
bool WidgetSettings::onTouch(View* vView, MotionEvent* event)
{
    if (w->maFragmentView[w->mcView]->mTouchState == 0) {
        w->maFragmentView[w->mcView]->mTouchState = 1;
        w->maFragmentView[w->mcView]->mViewSource = vView;
    }
    return w->maGestureDetector[w->mcView]->onTouchEvent(event);
}

} // End namespace
