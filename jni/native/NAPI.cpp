#include "native/NCommon.h"

namespace NSNATIVE
{

NReturn NAPI_nTerminate(NWrapper* w)
{
	w->env->DeleteGlobalRef(w->tFrame);
	return 0;
}

NReturn NAPI_tRun(NWrapper* w, NParam nVisitor, NParam nElement, NParam a, NParam b, NParam c, NParam d)
{
	return (NReturn)w->env->CallLongMethod(w->tFrame, w->jmidTFrameTRun, nVisitor, nElement, a, b, c, d);
}

NReturnObject NAPI_tRunObject(NWrapper* w, NParam a, NParam b)
{
	return (NReturnObject)w->env->CallObjectMethod(w->tFrame, w->jmidTFrameTRunObject, a, b);
}

NReturnObject NAPI_tRunString(NWrapper* w, CharSequence boxed)
{
	return (NReturnObject)w->env->NewStringUTF(boxed);
}

String NAPI_tGetString(NWrapper* w, NReturnObject tString)
{
	String sReturn("");
	if (tString) {
		const char* aChar = w->env->GetStringUTFChars((jstring)tString, NULL);
		sReturn = String(aChar);
		w->env->ReleaseStringUTFChars((jstring)tString, aChar);
	}
	return sReturn;
}

JNIEXPORT NReturn JNICALL Java_z_a_TFrame_nInit(JNIEnv* env, jobject tFrame, NParam nWrapper, NParam cState)
{
	jclass jclassTFrame = NULL;
	NWrapper* w = (NWrapper*)nWrapper;

	if (w == NULL) {
		w = NSDEVICE::Activity::kWrapper;
		w->env = env;
		w->tFrame = w->env->NewGlobalRef(tFrame);
		w->nFrame = new NClozer(w);

		if (w->tFrame != NULL) {
			jclassTFrame = (jclass)env->NewGlobalRef(env->GetObjectClass(w->tFrame));
		}
		if (jclassTFrame != NULL) {
			w->jmidTFrameTRun = w->env->GetMethodID(jclassTFrame, "tRun", "(JJJJJJ)J");
			w->jmidTFrameTRunObject = w->env->GetMethodID(jclassTFrame, "tRunObject", "(JJ)Ljava/lang/Object;");
		}
		w->env->DeleteGlobalRef(jclassTFrame);
	}
	return w->nFrame->nInit((NINIT)cState);
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
