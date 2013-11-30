#include "Common.h"

namespace NNameSpace
{

NLib::NLib()
	: w(new NWrapper())
{
	w->nElementList = new NElementList();
}

NLib::~NLib()
{
	delete w->nFrame;
	delete w->nElementList;
}

// Static nInitialization
NLib* nLib = new NLib();

JNIEXPORT jobject JNICALL Java_z_a_TClozer_nInit(JNIEnv* env, jobject tFrame, jobjectArray aTElement)
{
	nLib->w->nFrame = new NClozer(nLib->w, env, tFrame);
	return nLib->w->nFrame->nInit(aTElement);
}

JNIEXPORT jlong JNICALL Java_z_a_TClozer_nRunLong(JNIEnv* env, jobject obj, jlong nElement)
{
    LOGI("Java_z_a_TClozer_nRunLong");
    LOGI("nLib->w->nElementList->alpha>%ld<", (long)nLib->w->nElementList->alpha);
    LOGI("jlong nElement>%ld<", (long)nElement);
	return 0; //nLib->w->nFrame->nRunLong((NElement*)nElement);
}

JNIEXPORT jobject JNICALL Java_z_a_TClozer_nRunObject(JNIEnv* env, jobject obj, jlong nElement)
{
    LOGI("Java_z_a_TClozer_nRunObject");
    LOGI("nLib->w->nElementList->alpha>%ld<", (long)nLib->w->nElementList->alpha);
    LOGI("jlong nElement>%ld<", (long)nElement);
	return nLib->w->nFrame->nRunObject((NElement*)nElement);
}

} // END namespace

//z_a_TCloze
//z_a_TFrame
