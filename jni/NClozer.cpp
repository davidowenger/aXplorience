#include "Common.h"

namespace NNameSpace
{

NClozer::NClozer(NWrapper* w, JNIEnv* env, jobject tFrame)
	: w(w)
{
	w->env = env;
	w->tFrame = tFrame;
	mnTotal = sizeof(NElementList)/sizeof(NElement*);
	mapNElement = new long[mnTotal]();
	mbbNElement = w->env->NewGlobalRef(factoryDirectBuffer((void*)mapNElement, 1, mnTotal*sizeof(long)));
}

NClozer::~NClozer()
{
	delete w->nElementList->alpha;
	delete w->nElementList->beta;
	delete w->nElementList->gamma;
	w->env->DeleteGlobalRef(mbbNElement);
}

jobject NClozer::nInit(jobjectArray aTElement)
{
	int j;

	w->nElementList->alpha = new NAlpha();
	w->nElementList->beta = new NBeta();
	w->nElementList->gamma = new NGamma();

	for (j = 0 ; j < mnTotal && j <  w->env->GetArrayLength(aTElement) ; ++j) {
		NElement* pNElement = ((NElement**)w->nElementList)[j];
		pNElement->t = w->env->GetObjectArrayElement(aTElement, (jsize)j);
		mapNElement[j] = (long)pNElement;
	}
	return mbbNElement;
}

jlong NClozer::nRunLong(NElement* nElement)
{
    LOGI("nRunLong");
	return nElement->acceptLong(this);
}

jobject NClozer::nRunObject(NElement* nElement)
{
	return nElement->acceptObject(this);
}

jlong NClozer::nVisitLong(NAlpha* alpha)
{
	return 0;
}

jobject NClozer::nVisitObject(NAlpha* alpha)
{
	return NULL;
}

jlong NClozer::nVisitLong(NBeta* beta)
{
	return 0;
}

jobject NClozer::nVisitObject(NBeta* beta)
{
	return NULL;
}

jlong NClozer::nVisitLong(NGamma* gamma)
{
	return 0;
}

jobject NClozer::nVisitObject(NGamma* gamma)
{
	return NULL;
}

jobject NClozer::factoryDirectBuffer(void* pData, long nLength, size_t nSize)
{
	return w->env->NewDirectByteBuffer(pData, (jlong)(nLength*nSize));
}

} // END namespace

























//NewGlobalRef(JNIEnv *env, jobject obj);
//w->env->DeleteGlobalRef()



