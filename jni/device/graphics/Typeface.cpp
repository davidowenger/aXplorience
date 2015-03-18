#include "native/NCommon.h"

namespace NSDEVICE
{

const Typeface* Typeface::DEFAULT = Typeface::create("", NORMAL);
const Typeface* Typeface::DEFAULT_BOLD = Typeface::create("", BOLD);
const Typeface* Typeface::SANS_SERIF = Typeface::create("sans-serif", NORMAL);
const Typeface* Typeface::SERIF = Typeface::create("serif", NORMAL);
const Typeface* Typeface::MONOSPACE = Typeface::create("monospace", NORMAL);

} // End namespace
