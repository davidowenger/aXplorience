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

extern "C"
{
    JNIEXPORT jobject JNICALL Java_nclozer_tnamespace_TClozer_initElement(JNIEnv * env, jobject obj, jobjectArray aTElement);
    JNIEXPORT jlong JNICALL Java_nclozer_tnamespace_TClozer_runLong(JNIEnv * env, jobject obj, jlong nElement);
    JNIEXPORT jobject JNICALL Java_nclozer_tnamespace_TClozer_runObject(JNIEnv * env, jobject obj, jlong nElement);
};

} // END namespace

//nclozer_tapp_TCloze
//nclozer_tapp_TFrame
