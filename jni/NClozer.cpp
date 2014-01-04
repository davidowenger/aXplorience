#include "Common.h"

namespace NNameSpace
{

NClozer::NClozer(NWrapper* w, JNIEnv* env, jobject tFrame)
	: w(w)
{
	int j;

	w->env = env;
	w->tFrame = tFrame;
	w->apNElement = new nlong[w->nNElement] {
		(nlong)(w->alpha = new NAlpha()),
		(nlong)(w->beta = new NBeta()),
		(nlong)(w->gamma = new NGamma())
	};

	if (w->env != NULL) {
		/*
		 * jclass FindClass(JNIEnv *env, const char *name);
		 * The name argument is a fully-qualified class name or an array type signature . For example, the fully-qualified class name for the java.lang.String class is:
		 * "java/lang/String"
		 * The array type signature of the array class java.lang.Object[] is:
		 * "[Ljava/lang/Object;"
		 * Returns a class object from a fully-qualified name, or NULL if the class cannot be found.
		 * ClassFormatError: if the class data does not specify a valid class.
		 * ClassCircularityError: if a class or interface would be its own superclass or superinterface.
		 * NoClassDefFoundError: if no definition for a requested class or interface can be found.
		 * OutOfMemoryError: if the system runs out of memory.
		 */

		w->jclassByteBuffer = w->env->FindClass("java/nio/ByteBuffer");
	}
	if (w->jclassByteBuffer != NULL) {
		/*
		 * jmethodID GetMethodID(JNIEnv *env, jclass clazz, const char *name, const char *sig);
		 * <init> as the method name and void (V) as the return type.
		 * Returns a method ID, or NULL if the specified method cannot be found.
		 * NoSuchMethodError: if the specified method cannot be found.
		 * ExceptionInInitializerError: if the class initializer fails due to an exception.
		 * OutOfMemoryError: if the system runs out of memory.
		 */
		//w->jmidBufferInit = w->env->GetMethodID(w->jclassByteBuffer, "<init>", "(V)");
		/*
		 * jmethodID GetStaticMethodID(JNIEnv *env, jclass clazz, const char *name, const char *sig);
		 * Returns the method ID for a static method of a class. The method is specified by its name and signature.
		 * GetStaticMethodID() causes an uninitialized class to be initialized.
		 * Returns a method ID, or NULL if the operation fails.
		 * NoSuchMethodError: if the specified static method cannot be found.
		 * ExceptionInInitializerError: if the class initializer fails due to an exception.
		 * OutOfMemoryError: if the system runs out of memory.
		 */
		w->jmidByteBufferAllocate = w->env->GetStaticMethodID(w->jclassByteBuffer, "allocate", "(I)Ljava/nio/ByteBuffer;");
	}
	if (w->jmidByteBufferAllocate != NULL) {
		mBufferLong = factoryBufferLong(mnLong + w->nNElement, true);
		mBufferLong->set(w->alpha, 0);
		mBufferLong->set(w->beta, w->apNElement, w->nNElement);
	}
}

NClozer::~NClozer()
{
	delete w->alpha;
	delete w->beta;
	delete w->gamma;
	delete[] w->apNElement;
	delete mBufferLong;
}

jobject NClozer::nInit(jobjectArray aTElement)
{
	int j;

	for (j = 0 ; j < w->nNElement && j <  w->env->GetArrayLength(aTElement) ; ++j) {
		((NElement*)w->apNElement[j])->t = w->env->GetObjectArrayElement(aTElement, (jsize)j);
	}
	return mBufferLong->mjBuffer;
}

jlong NClozer::nRunLong(NElement* nElement)
{
    LOGI("nRunLong");
	return nElement->acceptLong(this);
}

jlong NClozer::visitLong(NAlpha* alpha)
{
	return 0;
}

jlong NClozer::visitLong(NBeta* beta)
{
	return 0;
}

jlong NClozer::visitLong(NGamma* gamma)
{
	return 0;
}

NBufferLong* NClozer::factoryBufferLong(int nLength, bool bDirect)
{
	return new NBufferLong(w, nLength, bDirect);
}

} // END namespace
