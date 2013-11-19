#include "Common.h"

namespace NNameSpace
{

NLib::NLib()
	: w(new NWrapper())
{
	w->nElementList = new NElementList();
	w->nFrame = new NClozer(w);
}

NLib::~NLib()
{
	delete w->nFrame;
	delete w->nElementList;
}

// Static initialization
NLib* nLib = new NLib();

JNIEXPORT jobject JNICALL Java_nclozer_tnamespace_TClozer_initElement(JNIEnv* env, jobject tFrame, jobjectArray aTElement)
{
	nLib->w->nFrame->initEnv(env, tFrame);

	return nLib->w->nFrame->initElement(aTElement);
}

JNIEXPORT jlong JNICALL Java_nclozer_tnamespace_TClozer_runLong(JNIEnv* env, jobject obj, jlong nElement)
{
    LOGI("Java_nclozer_tnamespace_TClozer_runLong");
    LOGI("nLib->w->nElementList->alpha>%ld<", (long)nLib->w->nElementList->alpha);
    LOGI("jlong nElement>%ld<", (long)nElement);
	return 0; //nLib->w->nFrame->runLong((NElement*)nElement);
}

JNIEXPORT jobject JNICALL Java_nclozer_tnamespace_TClozer_runObject(JNIEnv* env, jobject obj, jlong nElement)
{
    LOGI("Java_nclozer_tnamespace_TClozer_runObject");
    LOGI("nLib->w->nElementList->alpha>%ld<", (long)nLib->w->nElementList->alpha);
    LOGI("jlong nElement>%ld<", (long)nElement);
	return 0; //nLib->w->nFrame->runObject((NElement*)nElement);
}

} // END namespace

//nclozer_tnamespace_TCloze
//nclozer_tnamespace_TFrame
