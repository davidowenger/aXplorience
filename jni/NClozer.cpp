#include "Common.h"

namespace NNameSpace
{

NClozer::NClozer(NWrapper* w)
	: w(w)
{
}

NClozer::~NClozer()
{
	delete w->nElementList->alpha;
	delete w->nElementList->beta;
	delete w->nElementList->gamma;
	w->env->DeleteGlobalRef(mbbNElement);
}

void NClozer::initEnv(JNIEnv* env, jobject tFrame)
{
	w->env = env;
	w->tFrame = tFrame;
}

jobject NClozer::initElement(jobjectArray aTElement)
{
	int j;
	int nTotal = sizeof(NElementList)/sizeof(NElement*);

	w->nElementList->alpha = new NAlpha();
	w->nElementList->beta = new NBeta();
	w->nElementList->gamma = new NGamma();
	maPNElement = new long[nTotal]();

	for (j = 0 ; j < nTotal && j <  w->env->GetArrayLength(aTElement) ; ++j) {
		NElement* pNElement = ((NElement**)w->nElementList)[j];
		pNElement->t = w->env->GetObjectArrayElement(aTElement, (jsize)j);
		maPNElement[j] = (long)pNElement;
	}
	mbbNElement = w->env->NewGlobalRef(factoryDirectBuffer((void*)maPNElement, 1, nTotal*sizeof(long)));

	return mbbNElement;
}

jlong NClozer::runLong(NElement* nElement)
{
    LOGI("runLong");
	return nElement->acceptLong(this);
}

jobject NClozer::runObject(NElement* nElement)
{
	return nElement->acceptObject(this);
}

jlong NClozer::visitLong(NAlpha* alpha)
{
	return 0;
}

jobject NClozer::visitObject(NAlpha* alpha)
{
	return NULL;
}

jlong NClozer::visitLong(NBeta* beta)
{
	return 0;
}

jobject NClozer::visitObject(NBeta* beta)
{
	return NULL;
}

jlong NClozer::visitLong(NGamma* gamma)
{
	return 0;
}

jobject NClozer::visitObject(NGamma* gamma)
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



