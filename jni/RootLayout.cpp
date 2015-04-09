#include "Common.h"
#include "Theme.h"

namespace NSDEVICE
{

RootLayout::RootLayout(Wrapper* const w)
    : FrameLayout(w->mApplication), w(w)
{
    setId(0x0FF20000);
    setLayoutParams(new FrameLayout::LayoutParams(FrameLayout::LayoutParams::MATCH_PARENT, FrameLayout::LayoutParams::MATCH_PARENT));
    setBackgroundColor(w->maColor[Theme::kColorApplicationBackground]);
}

RootLayout::~RootLayout()
{
    removeAllViews();
}

} // End namespace
