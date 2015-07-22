#include "Common.h"
#include "Theme.h"

namespace NSDEVICE
{

WidgetSettings::WidgetSettings(Wrapper* const w)
	: Widget(w), mTextView(nullptr), mcPadding((nint)(5*w->mcDensity))
{
    nuint i;
    LinearLayout::LayoutParams* vLinearLayoutParams;

    mTextView = new TextView(w->mApplication);
    maWidgetSettingsItem = new WidgetSettingsItem[2] {
        { new LinearLayout(w->mNActivity), new TextView(w->mNActivity), new ToggleButton(w->mNActivity) },
        { new LinearLayout(w->mNActivity), new TextView(w->mNActivity), new ToggleButton(w->mNActivity) }
    };
    maWidgetSettingsLabel = new String[2] {
        "Enable Bluetooth",
        "Show device"
    };
    setGravity(Gravity::LEFT|Gravity::TOP);
    setOrientation(LinearLayout::VERTICAL);
    setLayoutParams(new LinearLayout::LayoutParams(0, LinearLayout::LayoutParams::MATCH_PARENT, 1));
    setPadding(mcPadding,mcPadding,mcPadding,mcPadding);
    setOnTouchListener(this);

    mTextView->setGravity(Gravity::START);
    mTextView->setLayoutParams(new LinearLayout::LayoutParams(LinearLayout::LayoutParams::MATCH_PARENT, LinearLayout::LayoutParams::WRAP_CONTENT));
    mTextView->setPadding(mcPadding, mcPadding, mcPadding, mcPadding);
    mTextView->setTextColor(w->maColor[Theme::kColorMessageText]);
    mTextView->setTextSize(w->mcTextSize);
    mTextView->setTypeface(Typeface::DEFAULT);
    mTextView->setText("Be sure to enable Bluetooth. When enabled, use discoverability for your device to be seen.");
    mTextView->setOnTouchListener(this);

    addView(mTextView);

    for (i = 0 ; i < 2 ; ++i) {
        vLinearLayoutParams = new LinearLayout::LayoutParams(ViewGroup::LayoutParams::MATCH_PARENT, LinearLayout::LayoutParams::WRAP_CONTENT);
        vLinearLayoutParams->setMargins(mcPadding,mcPadding,mcPadding,mcPadding);

        maWidgetSettingsItem[i].mLinearLayout->setGravity(Gravity::LEFT);
        maWidgetSettingsItem[i].mLinearLayout->setOrientation(LinearLayout::HORIZONTAL);
        maWidgetSettingsItem[i].mLinearLayout->setLayoutParams(vLinearLayoutParams);
        maWidgetSettingsItem[i].mLinearLayout->setPadding(0,0,0,0);
        maWidgetSettingsItem[i].mLinearLayout->setOnTouchListener(this);

        maWidgetSettingsItem[i].mTextView->setGravity(Gravity::LEFT|Gravity::CENTER_VERTICAL);
        maWidgetSettingsItem[i].mTextView->setLayoutParams(new LinearLayout::LayoutParams(0, LinearLayout::LayoutParams::MATCH_PARENT,1));
        maWidgetSettingsItem[i].mTextView->setPadding(mcPadding,mcPadding,mcPadding,mcPadding);
        maWidgetSettingsItem[i].mTextView->setLines(1);
        maWidgetSettingsItem[i].mTextView->setTextColor(w->maColor[Theme::kColorMessageText]);
        maWidgetSettingsItem[i].mTextView->setTextSize(w->mcTextSize);
        maWidgetSettingsItem[i].mTextView->setTypeface(Typeface::DEFAULT);
        maWidgetSettingsItem[i].mTextView->setText(maWidgetSettingsLabel[i]);
        maWidgetSettingsItem[i].mTextView->setOnTouchListener(this);

        maWidgetSettingsItem[i].mToggleButton->setMinimumHeight(w->maDrawable[0]->getIntrinsicHeight());
        maWidgetSettingsItem[i].mToggleButton->setLayoutParams(new LinearLayout::LayoutParams(0, LinearLayout::LayoutParams::MATCH_PARENT,1));
        maWidgetSettingsItem[i].mToggleButton->setPadding(0,0,0,0);
        maWidgetSettingsItem[i].mToggleButton->setEnabled(true);
        maWidgetSettingsItem[i].mToggleButton->setOnClickListener(this);
        maWidgetSettingsItem[i].mToggleButton->setOnTouchListener(this);

        maWidgetSettingsItem[i].mLinearLayout->addView(maWidgetSettingsItem[i].mTextView);
        maWidgetSettingsItem[i].mLinearLayout->addView(maWidgetSettingsItem[i].mToggleButton);

        addView(maWidgetSettingsItem[i].mLinearLayout);
        delete vLinearLayoutParams;
    }
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

    maWidgetSettingsItem[0].mToggleButton->setChecked(w->dBluetoothAdapter->isEnabled());
    maWidgetSettingsItem[1].mToggleButton->setChecked(w->dBluetoothAdapter->getScanMode() == w->dBluetoothAdapter->SCAN_MODE_CONNECTABLE_DISCOVERABLE);

    requestLayout();
}

//*******************************************************************************************
//**************************************  OnClickListener  **********************************
//*******************************************************************************************
void WidgetSettings::onClick(View* vView)
{
    if (vView == maWidgetSettingsItem[0].mToggleButton) {
        w->mNActivity->sendOp(0, w->mOpUnitCoreId, w->w->mNOmicron00, new OpParam(maWidgetSettingsItem[0].mToggleButton->isChecked(), maWidgetSettingsItem[1].mToggleButton->isChecked()));
    }
    if (vView == maWidgetSettingsItem[1].mToggleButton) {
        w->mNActivity->sendOp(0, w->mOpUnitCoreId, w->w->mNOmicron00, new OpParam(maWidgetSettingsItem[0].mToggleButton->isChecked(), maWidgetSettingsItem[1].mToggleButton->isChecked()));
    }
}

//*******************************************************************************************
//**************************************  OnTouchListener  **********************************
//*******************************************************************************************
bool WidgetSettings::onTouch(View* vView, MotionEvent* event)
{
    ToggleButton* vToggleButton0;
    ToggleButton* vToggleButton1;
    Wrapper* vWrapper = w;

    if (w->mTouchState == 1 && vView == maWidgetSettingsItem[0].mToggleButton) {
        w->mTouchState = 2;
        vToggleButton0 = maWidgetSettingsItem[0].mToggleButton;
        vToggleButton1 = maWidgetSettingsItem[1].mToggleButton;
        w->mEventAction = function<void()>([vWrapper,vToggleButton0,vToggleButton1]()->void{
            vToggleButton0->setChecked(!vToggleButton0->isChecked());
            vWrapper->mNActivity->sendOp(0, vWrapper->mOpUnitCoreId, vWrapper->w->mNOmicron00, new OpParam(vToggleButton0->isChecked(), vToggleButton1->isChecked()));
        });
    }
    if (w->mTouchState == 1 && vView == maWidgetSettingsItem[1].mToggleButton) {
        w->mTouchState = 2;
        vToggleButton0 = maWidgetSettingsItem[0].mToggleButton;
        vToggleButton1 = maWidgetSettingsItem[1].mToggleButton;
        w->mEventAction = function<void()>([vWrapper,vToggleButton0,vToggleButton1]()->void{
            vToggleButton1->setChecked(!vToggleButton1->isChecked());
            vWrapper->mNActivity->sendOp(0, vWrapper->mOpUnitCoreId, vWrapper->w->mNOmicron00, new OpParam(vToggleButton0->isChecked(), vToggleButton1->isChecked()));
        });
    }
    if (w->mTouchState == 3) {
        w->mTouchState = 0;
    }
    return true;
}

} // End namespace
