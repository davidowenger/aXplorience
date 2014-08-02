#ifndef __NAPI_H__
#define __NAPI_H__

#include <new>
#include <assert.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>

namespace NNameSpace
{

NReturn NAPI_nTerminate(NWrapper* w);
NReturn NAPI_tRun(NWrapper* w, NParam nVisitor, NParam nElement, NParam a, NParam b, NParam c);
NReturnObject NAPI_tRunString(NWrapper* w, CharSequence boxed);

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT NReturn JNICALL Java_z_a_TFrame_nInit(JNIEnv* env, jobject tFrame, NParam nWrapper, NParam cState);
JNIEXPORT NReturn JNICALL Java_z_a_TVisitor_nRun(JNIEnv* env, jobject obj, NParam nVisitor, NParam nElement, NParam a = 0, NParam b = 0, NParam c = 0);
JNIEXPORT NReturnObject JNICALL Java_z_a_TVisitor_nRunObject(JNIEnv* env, jobject obj, NParam nVisitor, NParam nElement, NParam a = 0, NParam b = 0, NParam c = 0);
JNIEXPORT NReturnObject JNICALL Java_z_a_TFrame_nGetService(JNIEnv* env, jobject obj, jobject mIBluetoothProxy);

#ifdef __cplusplus
};
#endif

} // END namespace

#endif
