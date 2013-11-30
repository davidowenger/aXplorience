#include "Common.h"

namespace NNameSpace
{

class NLib
{
public:
	NLib();
   ~NLib();

    NWrapper* w;
};

/*
 * com.android.gl2jni
 * GL2JNILib
 * gl2jni
 * public static native void init(int width, int height)
 * extern "C" {
 * JNIEXPORT void JNICALL Java_com_android_gl2jni_GL2JNILib_init(JNIEnv * env, jobject obj,  jint width, jint height);
 * JNIEXPORT void JNICALL Java_com_android_gl2jni_GL2JNILib_init(JNIEnv * env, jobject obj,  jint width, jint height) {
 */

extern "C"
{
    JNIEXPORT jobject JNICALL Java_z_a_TClozer_nInit(JNIEnv * env, jobject obj, jobjectArray aTElement);
    JNIEXPORT jlong JNICALL Java_z_a_TClozer_nRunLong(JNIEnv * env, jobject obj, jlong nElement);
    JNIEXPORT jobject JNICALL Java_z_a_TClozer_nRunObject(JNIEnv * env, jobject obj, jlong nElement);
};

} // END namespace

//nclozer_tapp_TCloze
//nclozer_tapp_TFrame
