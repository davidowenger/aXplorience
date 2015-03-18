#include "native/NCommon.h"

namespace NSNATIVE
{

NReturn NAPI_nTerminate(NWrapper* w)
{
	w->env->DeleteGlobalRef(w->tFrame);
	return 0;
}

NReturn NAPI_tAttachCurrentThread(NWrapper* w)
{
	JNIEnv* jniEnv = nullptr;

	if (w->vm->AttachCurrentThread(&jniEnv, NULL)) {
		jniEnv = nullptr;
	}
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
	return jniEnv->NewGlobalRef(jniEnv->CallObjectMethod(w->tFrame, w->jmidTFrameTRunObject, a, b));
}

NReturnObject NAPI_tRunString(NWrapper* w, const String& boxed)
{
	JNIEnv* jniEnv = (JNIEnv*)NAPI_tAttachCurrentThread(w);
	NReturnObject ret = (NReturnObject)jniEnv->NewStringUTF(boxed.c_str());
	jniEnv->ExceptionClear();
	return ret;
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

JNIEXPORT NReturn JNICALL Java_z_a_TFrame_nInit(JNIEnv* env, jobject tFrame, NParam cState)
{
	jclass jclassTFrame = NULL;

	if (cState == NFrame::GET_VISITOR) {
		NWrapper::getInstance()->env = env;
		NWrapper::getInstance()->tFrame = NWrapper::getInstance()->env->NewGlobalRef(tFrame);
		NWrapper::getInstance()->nFrame = new NClozer(NWrapper::getInstance());

		if (NWrapper::getInstance()->tFrame != NULL) {
			jclassTFrame = (jclass)env->NewGlobalRef(env->GetObjectClass(NWrapper::getInstance()->tFrame));
		}
		if (jclassTFrame != NULL) {
			NWrapper::getInstance()->jmidTFrameTRun = NWrapper::getInstance()->env->GetMethodID(jclassTFrame, "tRun", "(JJJJJJJ)J");
			NWrapper::getInstance()->jmidTFrameTRunObject = NWrapper::getInstance()->env->GetMethodID(jclassTFrame, "tRunObject", "(JJ)Ljava/lang/Object;");
		}
		NWrapper::getInstance()->env->DeleteGlobalRef(jclassTFrame);
		NWrapper::getInstance()->env->GetJavaVM(&NWrapper::getInstance()->vm);
	}
	return NWrapper::getInstance()->nFrame->nInit((NINIT)cState);
}

JNIEXPORT NReturn JNICALL Java_z_a_TVisitor_nRun(JNIEnv* env, jobject obj, NParam nVisitor, NParam nElement, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    LOGPRINTI("Call to NATIVE with element @%llu at visitor @%llu", (unsigned long long)nElement, (unsigned long long)nVisitor);
	return ((NVisitor*)nVisitor)->nRun((NElement*)nElement, a, b, c, d, e);
}

JNIEXPORT NReturnObject JNICALL Java_z_a_TVisitor_nRunObject(JNIEnv* env, jobject obj, NParam a, NParam b)
{
    LOGPRINTI("Call to NATIVE for a JOBJECT at address @%llu and index @%llu", (unsigned long long)a, (unsigned long long)b);
	return ( a ? *(NReturnObject*)a : nullptr );
}

} // END namespace
