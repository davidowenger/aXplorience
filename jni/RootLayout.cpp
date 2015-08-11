#include "Common.h"
#include "Theme.h"

namespace NSDEVICE
{

RootLayout::RootLayout(Wrapper* const w)
    : FrameLayout(w->mApplication), w(w)
{
    setLayoutParams(new FrameLayout::LayoutParams(FrameLayout::LayoutParams::MATCH_PARENT, FrameLayout::LayoutParams::MATCH_PARENT));
    setBackgroundColor(w->maColor[Theme::kColorApplicationBackground]);
}

RootLayout::~RootLayout()
{
}

} // End namespace
