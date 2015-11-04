#ifndef __NOS_H__
#define __NOS_H__

namespace NSNATIVE
{

NReturn NKrossSystem_tAttachCurrentThread(NWrapper* w);
NReturn NKrossSystem_tDeleteGlobalRef(NWrapper* w, NParamObject vGlobalRef);
NReturn NKrossSystem_tDetachCurrentThread(NWrapper* w);
String NKrossSystem_tGetString(NWrapper* w, NReturnObject tString);
NReturnObject NKrossSystem_tRunObject(NWrapper* w, NParam a = 0, NParam b = -1);
NReturnObject NKrossSystem_tRunString(NWrapper* w, const String& boxed);
NReturn NKrossVisitor_tRun(NWrapper* w, NParam nVisitor, NParam nElement, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT NReturn JNICALL Java_y_b_TKrossSystem_nCancel(JNIEnv* env, jobject vTKrossSystem, NParam vNKrossSystem);
JNIEXPORT NReturn JNICALL Java_y_b_TKrossSystem_nInit(JNIEnv* env, jobject vTKrossSystem, NParam vNKrossSystem);
JNIEXPORT NReturnObject JNICALL Java_y_b_TKrossSystem_nRunObject(JNIEnv* env, jobject obj, NParam a = 0, NParam b = -1);
JNIEXPORT NReturn JNICALL Java_y_b_TKrossVisitor_nRun(JNIEnv* env, jobject obj, NParam nVisitor, NParam nElement, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);

#ifdef __cplusplus
}
#endif

} // END namespace

#endif
