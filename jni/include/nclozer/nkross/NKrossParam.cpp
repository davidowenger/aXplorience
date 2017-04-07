#include "NKrossCommon.h"

namespace NSNATIVE
{

NKrossParam::NKrossParam(const String& boxed)
    : n(0), mTString()
{
    mTString = NKrossWrapper::w->mNKrossSystem->tRunString(boxed);
    n = (NParam)&mTString;
}

NKrossParam::~NKrossParam()
{
    NKrossWrapper::w->mNKrossSystem->tDeleteGlobalRef(mTString);
}

} // END namespace
