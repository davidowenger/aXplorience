#include "native/NCommon.h"

namespace NSNATIVE
{

NReturn NAPI_tAttachCurrentThread(NWrapper* w)
{
	JNIEnv* jniEnv = nullptr;
	w->vm->AttachCurrentThread(&jniEnv, NULL);
	return (NReturn)jniEnv;
}

NReturn NAPI_tDetachCurrentThread(NWrapper* w)
{
	return (NReturn)w->vm->DetachCurrentThread();
}

NReturn NAPI_tRun(NWrapper* w, NParam nVisitor, NParam nElement, NParam a, NParam b, NParam c, NParam d, NParam e)
{
	JNIEnv* jniEnv = (JNIEnv*)NAPI_tAttachCurrentThread(w);
	NReturn ret = (NReturn)jniEnv->CallLongMethod(w->tFrame, w->jmidTFrameTRun, nVisitor, nElement, a, b, c, d, e);
	return ret;
}

NReturnObject NAPI_tRunObject(NWrapper* w, NParam a, NParam b)
{
	JNIEnv* jniEnv = (JNIEnv*)NAPI_tAttachCurrentThread(w);
    NReturnObject vObjectLocal = jniEnv->CallObjectMethod(w->tFrame, w->jmidTFrameTRunObject, a, b);
    jniEnv->ExceptionClear();
    NReturnObject vObjectGlobal = jniEnv->NewGlobalRef(vObjectLocal);
    jniEnv->DeleteLocalRef(vObjectLocal);
	return vObjectGlobal;
}

NReturnObject NAPI_tRunString(NWrapper* w, const String& boxed)
{
	JNIEnv* jniEnv = (JNIEnv*)NAPI_tAttachCurrentThread(w);
    NReturnObject vObjectLocal = jniEnv->NewStringUTF(boxed.c_str());
    jniEnv->ExceptionClear();
    NReturnObject vObjectGlobal = jniEnv->NewGlobalRef(vObjectLocal);
    jniEnv->DeleteLocalRef(vObjectLocal);
	return vObjectGlobal;
}

String NAPI_tGetString(NWrapper* w, NReturnObject tString)
{
	String sReturn = String("");
	const char* aChar = nullptr;
	JNIEnv* jniEnv = (JNIEnv*)NAPI_tAttachCurrentThread(w);

	if (tString) {
		aChar = jniEnv->GetStringUTFChars((jstring)tString, NULL);
		jniEnv->ExceptionClear();
	}
	if (aChar) {
		sReturn = String(aChar);
		jniEnv->ReleaseStringUTFChars((jstring)tString, aChar);
		jniEnv->ExceptionClear();
	}
	jniEnv->DeleteGlobalRef(tString);
	return sReturn;
}

NReturn NAPI_tDeleteGlobalRef(NWrapper* w, NParamObject vGlobalRef)
{
    JNIEnv* jniEnv = (JNIEnv*)NAPI_tAttachCurrentThread(w);
    jniEnv->DeleteGlobalRef(vGlobalRef);
    return 0;
}

JNIEXPORT NReturn JNICALL Java_z_a_TFrame_nInit(JNIEnv* env, jobject tFrame, NParam cState)
{
    jclass jclassTFrame = NULL;

    if (cState == NFrame::GET_VISITOR) {
        NWrapper::w->env = env;
        NWrapper::w->tFrame = NWrapper::w->env->NewGlobalRef(tFrame);
        NWrapper::w->nFrame = new NClozer(NWrapper::w);

        if (NWrapper::w->tFrame != NULL) {
            jclassTFrame = (jclass)env->NewGlobalRef(env->GetObjectClass(NWrapper::w->tFrame));
        }
        if (jclassTFrame != NULL) {
            NWrapper::w->jmidTFrameTRun = NWrapper::w->env->GetMethodID(jclassTFrame, "tRun", "(JJJJJJJ)J");
            NWrapper::w->jmidTFrameTRunObject = NWrapper::w->env->GetMethodID(jclassTFrame, "tRunObject", "(JJ)Ljava/lang/Object;");
        }
        NWrapper::w->env->DeleteGlobalRef(jclassTFrame);
        NWrapper::w->env->GetJavaVM(&NWrapper::w->vm);
    }
    return NWrapper::w->nFrame->nInit((nint)cState);
}

JNIEXPORT NReturn JNICALL Java_z_a_TFrame_nCancel(JNIEnv* env, jobject tFrame)
{
    delete NWrapper::w->nFrame;
    NWrapper::w->env->DeleteGlobalRef(NWrapper::w->tFrame);

    //HINT: shared lib will not be unloaded, except if memory needed
    //delete NWrapper::w;
    return 0;
}

JNIEXPORT NReturn JNICALL Java_z_a_TVisitor_nRun(JNIEnv* env, jobject obj, NParam nVisitor, NParam nElement, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    LOGPRINTV("Call to NATIVE with element @%llu at visitor @%llu", (unsigned long long)nElement, (unsigned long long)nVisitor);
	return ((NVisitor*)nVisitor)->nRun((NElement*)nElement, a, b, c, d, e);
}

JNIEXPORT NReturnObject JNICALL Java_z_a_TVisitor_nRunObject(JNIEnv* env, jobject obj, NParam a, NParam b)
{
    LOGPRINTV("Call to NATIVE for a JOBJECT at address @%llu and index @%llu", (unsigned long long)a, (unsigned long long)b);
	return ( a ? *(NReturnObject*)a : nullptr );
}

} // END namespace

//jint JNICALL JNI_OnLoad(JavaVM* jvm, void* reserved)
//{
//	JNIEnv* jniEnv = nullptr;
//
//	if (jvm->AttachCurrentThread(&jniEnv, NULL)) {
//		jniEnv = nullptr;
//	}
//	if (jniEnv) {
//	}
//	return JNI_VERSION_1_2;
//}

//void JNICALL JNI_OnUnload(JavaVM* jvm, void* reserved)
//{
//}
