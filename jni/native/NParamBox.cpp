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
    JNIEnv* jniEnv = nullptr;

    if (w->vm->AttachCurrentThread(&jniEnv, NULL)) {
        jniEnv = nullptr;
    }
    if (jniEnv && mTString) {
        jniEnv->DeleteLocalRef(mTString);
    }
}

} // END namespace
