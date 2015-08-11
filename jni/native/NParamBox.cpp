#include "NCommon.h"

namespace NSNATIVE
{

NParamBox::NParamBox(NWrapper* const w, const String& boxed)
    : w(w), n(0), mTString()
{
    mTString = w->nFrame->tRunString(boxed);
    n = (NParam)&mTString;
}

NParamBox::~NParamBox()
{
    w->nFrame->tDeleteGlobalRef(mTString);
}

} // END namespace
