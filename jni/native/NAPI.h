#ifndef __NAPI_H__
#define __NAPI_H__

namespace NSNATIVE
{

NReturn NAPI_tAttachCurrentThread(NWrapper* w);
NReturn NAPI_tDetachCurrentThread(NWrapper* w);
NReturn NAPI_tRun(NWrapper* w, NParam nVisitor, NParam nElement, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
NReturnObject NAPI_tRunObject(NWrapper* w, NParam a = 0, NParam b = -1);
NReturnObject NAPI_tRunString(NWrapper* w, const String& boxed);
String NAPI_tGetString(NWrapper* w, NReturnObject tString);
NReturn NAPI_tDeleteGlobalRef(NWrapper* w, NParamObject vGlobalRef);

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT NReturn JNICALL Java_z_a_TFrame_nInit(JNIEnv* env, jobject tFrame, NParam cState);
JNIEXPORT NReturn JNICALL Java_z_a_TFrame_nCancel(JNIEnv* env, jobject tFrame);
JNIEXPORT NReturn JNICALL Java_z_a_TVisitor_nRun(JNIEnv* env, jobject obj, NParam nVisitor, NParam nElement, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
JNIEXPORT NReturnObject JNICALL Java_z_a_TVisitor_nRunObject(JNIEnv* env, jobject obj, NParam a = 0, NParam b = -1);

#ifdef __cplusplus
}
#endif

} // END namespace

#endif

//JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* jvm, void* reserved);
//JNIEXPORT void JNICALL JNI_OnUnload(JavaVM* jvm, void* reserved);
