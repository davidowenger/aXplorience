#ifndef __NAPI_H__
#define __NAPI_H__

#include <new>
#include <assert.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>

namespace NSNATIVE
{

NReturn NAPI_nTerminate(NWrapper* w);

JNIEnv* NAPI_tAttachCurrentThread(NWrapper* w);
NReturn NAPI_tDetachCurrentThread(NWrapper* w);
NReturn NAPI_tRun(NWrapper* w, NParam nVisitor, NParam nElement, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0);
NReturnObject NAPI_tRunObject(NWrapper* w, NParam a = 0, NParam b = -1);
NReturnObject NAPI_tRunString(NWrapper* w, CharSequence boxed);
String NAPI_tGetString(NWrapper* w, NReturnObject tString);

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT NReturn JNICALL Java_z_a_TFrame_nInit(JNIEnv* env, jobject tFrame, NParam cState);
JNIEXPORT NReturn JNICALL Java_z_a_TVisitor_nRun(JNIEnv* env, jobject obj, NParam nVisitor, NParam nElement, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0);
JNIEXPORT NReturnObject JNICALL Java_z_a_TVisitor_nRunObject(JNIEnv* env, jobject obj, NParam a = 0, NParam b = -1);

#ifdef __cplusplus
};
#endif

} // END namespace

#endif
