#include <nkross/NKrossCommon.h>

namespace NSNATIVE
{

NReturn NKrossSystem_tAttachCurrentThread(NWrapper* w)
{
    JNIEnv* jniEnv = nullptr;
    w->mNKrossWrapper->mVM->AttachCurrentThread(&jniEnv, NULL);
    return (NReturn)jniEnv;
}

NReturn NKrossSystem_tDeleteGlobalRef(NWrapper* w, NParamObject vGlobalRef)
{
    JNIEnv* jniEnv = (JNIEnv*)NKrossSystem_tAttachCurrentThread(w);
    jniEnv->DeleteGlobalRef(vGlobalRef);
    return 0;
}

NReturn NKrossSystem_tDetachCurrentThread(NWrapper* w)
{
    return (NReturn)w->mNKrossWrapper->mVM->DetachCurrentThread();
}

String NKrossSystem_tGetString(NWrapper* w, NReturnObject tString)
{
    String sReturn = String("");
    const char* aChar = nullptr;
    JNIEnv* jniEnv = (JNIEnv*)NKrossSystem_tAttachCurrentThread(w);

    if (tString) {
        aChar = jniEnv->GetStringUTFChars((jstring)tString, NULL);
        jniEnv->ExceptionClear();
    }
    if (aChar) {
        sReturn = String(aChar);
        jniEnv->ReleaseStringUTFChars((jstring)tString, aChar);
        jniEnv->ExceptionClear();
    }
    if (tString) {
        jniEnv->DeleteGlobalRef(tString);
    }
    return sReturn;
}

NReturnObject NKrossSystem_tRunObject(NWrapper* w, NParam a, NParam b)
{
    JNIEnv* jniEnv = (JNIEnv*)NKrossSystem_tAttachCurrentThread(w);
    NReturnObject vObjectLocal = jniEnv->CallObjectMethod(w->mNKrossWrapper->mTKrossSystem, w->mNKrossWrapper->mhTKrossVisitorTRunObject, a, b);
    jniEnv->ExceptionClear();
    NReturnObject vObjectGlobal = jniEnv->NewGlobalRef(vObjectLocal);
    jniEnv->DeleteLocalRef(vObjectLocal);
    return vObjectGlobal;
}

NReturnObject NKrossSystem_tRunString(NWrapper* w, const String& boxed)
{
    JNIEnv* jniEnv = (JNIEnv*)NKrossSystem_tAttachCurrentThread(w);
    NReturnObject vObjectLocal = jniEnv->NewStringUTF(boxed.c_str());
    jniEnv->ExceptionClear();
    NReturnObject vObjectGlobal = jniEnv->NewGlobalRef(vObjectLocal);
    jniEnv->DeleteLocalRef(vObjectLocal);
    return vObjectGlobal;
}

NReturn NKrossVisitor_tRun(NWrapper* w, NParam nVisitor, NParam nElement, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    JNIEnv* jniEnv = (JNIEnv*)NKrossSystem_tAttachCurrentThread(w);
    NReturn ret = (NReturn)jniEnv->CallLongMethod(w->mNKrossWrapper->mTKrossSystem, w->mNKrossWrapper->mhTKrossVisitorTRun, nVisitor, nElement, a, b, c, d, e);
    return ret;
}

JNIEXPORT NReturn JNICALL Java_y_b_TKrossSystem_nCancel(JNIEnv* vEnv, jobject vTKrossSystem, NParam vNKrossSystem)
{
    NWrapper* w = ((NKrossSystem*)vNKrossSystem)->mNWrapper;
    delete w->mNKrossWrapper->mNKrossSystem;
    vEnv->DeleteGlobalRef(w->mNKrossWrapper->mTKrossSystem);

    //HINT: shared lib will not be unloaded, except if memory needed
    //delete w;
    return 0;
}

JNIEXPORT NReturn JNICALL Java_y_b_TKrossSystem_nInit(JNIEnv* vEnv, jobject vTKrossSystem, NParam vNKrossSystem)
{
    jclass vTKrossSystemJavaClass = nullptr;
    NWrapper* w = nullptr;
    nint vcState = NKrossSystem::GET_ELEMENT;

    if (!vNKrossSystem) {
        NElement::counter = 0;
        NVisitor::counter = 0;

        w = new NWrapper();
        w->mNKrossWrapper = new NKrossWrapper();
        w->mNKrossWrapper->mEnv = vEnv;
        w->mNKrossWrapper->mTKrossSystem = vEnv->NewGlobalRef(vTKrossSystem);
        w->mNKrossWrapper->mNKrossSystem = new NKrossSystem(w);
        vcState = NKrossSystem::GET_VISITOR;

        if (w->mNKrossWrapper->mTKrossSystem) {
            vTKrossSystemJavaClass = (jclass)vEnv->NewGlobalRef(vEnv->GetObjectClass(w->mNKrossWrapper->mTKrossSystem));
        }
        if (vTKrossSystemJavaClass) {
            w->mNKrossWrapper->mhTKrossVisitorTRun = vEnv->GetMethodID(vTKrossSystemJavaClass, "tRun", "(JJJJJJJ)J");
            w->mNKrossWrapper->mhTKrossVisitorTRunObject = vEnv->GetMethodID(vTKrossSystemJavaClass, "tRunObject", "(JJ)Ljava/lang/Object;");
        }
        vEnv->DeleteGlobalRef(vTKrossSystemJavaClass);
        vEnv->GetJavaVM(&w->mNKrossWrapper->mVM);

        NKrossWrapper::w = w->mNKrossWrapper;
    } else {
        w = ((NKrossSystem*)vNKrossSystem)->mNWrapper;
    }
    return w->mNKrossWrapper->mNKrossSystem->nInit((nint)vcState);
}

JNIEXPORT NReturnObject JNICALL Java_y_b_TKrossSystem_nRunObject(JNIEnv* env, jobject obj, NParam a, NParam b)
{
    LOGPRINTV("Call to NATIVE for a JOBJECT at address @%llu and index @%llu", (unsigned long long)a, (unsigned long long)b);
    return ( a ? *(NReturnObject*)a : nullptr );
}

JNIEXPORT NReturn JNICALL Java_y_b_TKrossVisitor_nRun(JNIEnv* env, jobject obj, NParam nVisitor, NParam nElement, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    LOGPRINTV("Call to NATIVE with element @%llu at visitor @%llu", (unsigned long long)nElement, (unsigned long long)nVisitor);
    return ((NKrossVisitor*)nVisitor)->nRun((NElement*)nElement, a, b, c, d, e);
}

} // END namespace
