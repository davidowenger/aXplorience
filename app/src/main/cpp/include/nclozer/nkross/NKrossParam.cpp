#include "NKrossCommon.h"

namespace NSNATIVE
{

NKrossParam::NKrossParam(const String& boxed)
    : n(0), mTString()
{
    mTString = NSNKROSS::w->mNKrossSystem->tRunString(boxed);
    n = (NParam)&mTString;
}

NKrossParam::~NKrossParam()
{
    NSNKROSS::w->mNKrossSystem->tDeleteGlobalRef(mTString);
}

} // END namespace
