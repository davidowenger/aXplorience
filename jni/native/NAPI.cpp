#include "native/NCommon.h"

namespace NSNATIVE
{

NReturn NAPI_nTerminate(NWrapper* w)
{
	w->env->DeleteGlobalRef(w->tFrame);
	return 0;
}

JNIEnv* NAPI_tAttachCurrentThread(NWrapper* w)
{
	JNIEnv* jniEnv = nullptr;

	if (w->vm->AttachCurrentThread(&jniEnv, NULL)) {
		jniEnv = nullptr;
	}
	return jniEnv;
}

NReturn NAPI_tDetachCurrentThread(NWrapper* w)
{
	return (NReturn)w->vm->DetachCurrentThread();
}

NReturn NAPI_tRun(NWrapper* w, NParam nVisitor, NParam nElement, NParam a, NParam b, NParam c, NParam d)
{
	JNIEnv* jniEnv = NAPI_tAttachCurrentThread(w);
	NReturn ret = (NReturn)jniEnv->CallLongMethod(w->tFrame, w->jmidTFrameTRun, nVisitor, nElement, a, b, c, d);
	return ret;
}

NReturnObject NAPI_tRunObject(NWrapper* w, NParam a, NParam b)
{
	JNIEnv* jniEnv = NAPI_tAttachCurrentThread(w);
	NReturnObject ret = (NReturnObject)jniEnv->CallObjectMethod(w->tFrame, w->jmidTFrameTRunObject, a, b);
	return ret;
}

NReturnObject NAPI_tRunString(NWrapper* w, CharSequence boxed)
{
	JNIEnv* jniEnv = NAPI_tAttachCurrentThread(w);
	NReturnObject ret = (NReturnObject)jniEnv->NewStringUTF(boxed);
	jniEnv->ExceptionClear();
	return ret;
}

String NAPI_tGetString(NWrapper* w, NReturnObject tString)
{
	String sReturn("");
	const char* aChar = nullptr;
	JNIEnv* jniEnv = NAPI_tAttachCurrentThread(w);

	if (tString) {
		aChar = jniEnv->GetStringUTFChars((jstring)tString, NULL);
		jniEnv->ExceptionClear();
	}
	if (aChar) {
		sReturn = String(aChar);
		jniEnv->ReleaseStringUTFChars((jstring)tString, aChar);
		jniEnv->ExceptionClear();
	}
	return sReturn;
}

JNIEXPORT NReturn JNICALL Java_z_a_TFrame_nInit(JNIEnv* env, jobject tFrame, NParam cState)
{
	jclass jclassTFrame = NULL;
	NSDEVICE::Activity* activity = NSDEVICE::Activity::kActivity;

	if (!activity->w) {
		activity->w = activity->getWrapper();
		activity->w->env = env;
		activity->w->tFrame = activity->w->env->NewGlobalRef(tFrame);
		activity->w->nFrame = new NClozer(activity->w);

		if (activity->w->tFrame != NULL) {
			jclassTFrame = (jclass)env->NewGlobalRef(env->GetObjectClass(activity->w->tFrame));
		}
		if (jclassTFrame != NULL) {
			activity->w->jmidTFrameTRun = activity->w->env->GetMethodID(jclassTFrame, "tRun", "(JJJJJJ)J");
			activity->w->jmidTFrameTRunObject = activity->w->env->GetMethodID(jclassTFrame, "tRunObject", "(JJ)Ljava/lang/Object;");
		}
		activity->w->env->DeleteGlobalRef(jclassTFrame);
		activity->w->env->GetJavaVM(&activity->w->vm);
	}
	return activity->w->nFrame->nInit((NINIT)cState);
}

JNIEXPORT NReturn JNICALL Java_z_a_TVisitor_nRun(JNIEnv* env, jobject obj, NParam nVisitor, NParam nElement, NParam a, NParam b, NParam c, NParam d)
{
	LOGI("Call to NATIVE with element @%llu at visitor @%llu", (unsigned long long)nElement, (unsigned long long)nVisitor);
	return ((NVisitor*)nVisitor)->nRun((NElement*)nElement, a, b, c, d);
}

JNIEXPORT NReturnObject JNICALL Java_z_a_TVisitor_nRunObject(JNIEnv* env, jobject obj, NParam a, NParam b)
{
	LOGI("Call to NATIVE for a JOBJECT at address @%llu and index @%llu", (unsigned long long)a, (unsigned long long)b);
	return *(NReturnObject*)a;
}

} // END namespace
