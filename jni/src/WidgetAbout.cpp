#include "Common.h"
#include "Theme.h"

namespace NSDEVICE
{

WidgetAbout::WidgetAbout(Wrapper* const w)
    : Widget(w), mTop(nullptr), mIcon(nullptr), mTextView(nullptr), mGestureDetector(nullptr), mcPadding((nint)(15*w->mcDensity))
{
    mTop = new LinearLayout(w->mApplication);
    mIcon = new ImageButton(w->mApplication);
    mTextView = new TextView(w->mApplication);

    LinearLayout::LayoutParams vWidgetParams = LinearLayout::LayoutParams(0, LinearLayout::LayoutParams::MATCH_PARENT, 1);
    setLayoutParams(&vWidgetParams);
    setGravity(Gravity::BOTTOM);
    setOrientation(LinearLayout::VERTICAL);
    setPadding(mcPadding, mcPadding, mcPadding, mcPadding);
    setOnTouchListener(this);

    LinearLayout::LayoutParams vTopParams = LinearLayout::LayoutParams(LinearLayout::LayoutParams::MATCH_PARENT, 0, 1.0 - 1.0/1.6180339887);
    mTop->setLayoutParams(&vTopParams);
    mTop->setGravity(Gravity::BOTTOM);
    mTop->setOrientation(LinearLayout::VERTICAL);
    mTop->setPadding(0,0,0,0);
    mTop->setOnTouchListener(this);

    LinearLayout::LayoutParams vIconParams = LinearLayout::LayoutParams(ViewGroup::LayoutParams::MATCH_PARENT, 0, 1.0/1.6180339887);
    mIcon->setLayoutParams(&vIconParams);
    mIcon->setPadding(0,0,0,0);
    mIcon->setBackgroundDrawable(nullptr);
    mIcon->setScaleType(ImageView::ScaleType::FIT_CENTER);
    mIcon->setImageDrawable(w->maDrawable[11]);
    mIcon->setOnTouchListener(this);

    LinearLayout::LayoutParams vTextParams = LinearLayout::LayoutParams(LinearLayout::LayoutParams::MATCH_PARENT, 0, 1.6180339887);
    mTextView->setGravity(Gravity::TOP|Gravity::CENTER_HORIZONTAL);
    mTextView->setLayoutParams(&vTextParams);
    mTextView->setPadding(mcPadding, mcPadding, mcPadding, mcPadding);
    mTextView->setTextColor(w->maColor[Theme::kColorMessageText]);
    mTextView->setTextSize(w->mcTextSize);
    mTextView->setTypeface(Typeface::DEFAULT);
    mTextView->setText("aXplorience v0.2 BETA\nSwipe left and right to switch view\nUse + to add a message");
    mTextView->setOnTouchListener(this);

    addView(mTop);
    addView(mIcon);
    addView(mTextView);
}

WidgetAbout::~WidgetAbout()
{
    if (mTextView) {
        delete mTextView;
    }
    if (mIcon) {
        delete mIcon;
    }
    if (mTop) {
        delete mTop;
    }
}

//*******************************************************************************************//
//**************************************  OnTouchListener  **********************************//
//*******************************************************************************************//
bool WidgetAbout::onTouch(View* vView, MotionEvent* event)
{
    if (w->mTouchState == 3) {
        w->mTouchState = 0;
    }
    return true;
}

} // End namespace
