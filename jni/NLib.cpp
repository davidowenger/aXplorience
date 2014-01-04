#include "Common.h"

namespace NNameSpace
{

NLib::NLib()
	: w(new NWrapper())
{
}

NLib::~NLib()
{
	delete w->nFrame;
}

// Static nInitialization
NLib* nLib = new NLib();

JNIEXPORT jobject JNICALL Java_z_a_TClozer_nInit(JNIEnv* env, jobject tFrame, jobjectArray aTElement)
{
	nLib->w->nFrame = new NClozer(nLib->w, env, tFrame);
	return nLib->w->nFrame->nInit(aTElement);
}

JNIEXPORT jobject JNICALL Java_z_a_TClozer_nRunObject(JNIEnv* env, jobject obj, jlong nElement)
{
    LOGI("Java_z_a_TClozer_nRunObject");
    LOGI("nLib->w->alpha>%lld<", (nlong)nLib->w->alpha);
    LOGI("jlong nElement>%lld<", (nlong)nElement);
	return (jobject)(nLib->w->nFrame->nRunLong((NElement*)nElement));
}

} // END namespace

//z_a_TCloze
//z_a_TFrame
