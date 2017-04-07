#include "Common.h"
#include "Theme.h"

namespace NSDEVICE
{

WidgetPOIEvents::WidgetPOIEvents(Wrapper* const w)
    : Widget(w), mTextView(nullptr), mcPadding((nint)(15*w->mcDensity))
{
    mTextView = new TextView(w->mApplication);

    LinearLayout::LayoutParams vWidgetParams = LinearLayout::LayoutParams(0, LinearLayout::LayoutParams::MATCH_PARENT, 1);
    setLayoutParams(&vWidgetParams);
    setGravity(Gravity::BOTTOM);
    setOrientation(LinearLayout::VERTICAL);
    setPadding(mcPadding, mcPadding, mcPadding, mcPadding);
    setOnTouchListener(this);

    LinearLayout::LayoutParams vTextParams = LinearLayout::LayoutParams(LinearLayout::LayoutParams::MATCH_PARENT, 0, 1.6180339887);
    mTextView->setGravity(Gravity::TOP|Gravity::CENTER_HORIZONTAL);
    mTextView->setLayoutParams(&vTextParams);
    mTextView->setPadding(mcPadding, mcPadding, mcPadding, mcPadding);
    mTextView->setTextColor(w->maColor[Theme::kColorMessageText]);
    mTextView->setTextSize(w->mcTextSize);
    mTextView->setTypeface(Typeface::DEFAULT);
    mTextView->setText("aXplorience v1.0.5 BETA\nSwipe left and right to switch view\nUse + to add a message");
    mTextView->setOnTouchListener(this);

    addView(mTextView);
}

WidgetPOIEvents::~WidgetPOIEvents()
{
    if (mTextView) {
        delete mTextView;
    }
}

void WidgetPOIEvents::init(nuint vcView, DBObject* vDBObject)
{
}

//*******************************************************************************************//
//**************************************  OnTouchListener  **********************************//
//*******************************************************************************************//
bool WidgetPOIEvents::onTouch(View* vView, MotionEvent* event)
{
    if (w->mTouchState == 3) {
        w->mTouchState = 0;
    }
    return true;
}

} // End namespace
