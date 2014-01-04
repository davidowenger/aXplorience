#include "Common.h"

namespace NNameSpace
{

NBufferLong::NBufferLong(NWrapper* w, int nLength, bool bDirect)
	: w(w), mbDirect(bDirect)
{
	maBufferMem = new nlong[nLength];
	mjBuffer = w->env->NewDirectByteBuffer((void*)maBufferMem, (jlong)(nLength*sizeof(nlong)));

	if (mjBuffer == NULL) {
		/*
		 * jobject NewObject(JNIEnv *env, jclass clazz, jmethodID methodID, ...);
		 * Constructs a new Java object. The method ID indicates which constructor method to invoke. This ID must be obtained by calling GetMethodID() with <init> as the method name and void (V) as the return type.
		 * The clazz argument must not refer to an array class.
		 * Programmers place all arguments that are to be passed to the constructor immediately following the methodID argument. NewObject() accepts these arguments and passes them to the Java method that the programmer wishes to invoke.
		 * Returns a Java object, or NULL if the object cannot be constructed.
		 * InstantiationException: if the class is an interface or an abstract class.
		 * OutOfMemoryError: if the system runs out of memory.
		 * Any exceptions thrown by the constructor.
		 */
		//mjBuffer = w->env->NewObject(w->jclassBuffer, w->jmidBufferInit);

		/*
		 * NativeType CallStatic<type>Method(JNIEnv *env, jclass clazz, jmethodID methodID, ...);
		 * This family of operations invokes a static method on a Java object, according to the specified method ID. The methodID argument must be obtained by calling GetStaticMethodID().
		 * The method ID must be derived from clazz, not from one of its superclasses.
		 * Programmers should place all arguments that are to be passed to the method immediately following the methodID argument. The CallStatic<type>Method routine accepts these arguments and passes them to the Java method that the programmer wishes to invoke.
		 * CallStaticVoidMethod()
		 * CallStaticObjectMethod()
		 * CallStaticBooleanMethod()
		 * CallStaticByteMethod()
		 * CallStaticCharMethod()
		 * CallStaticShortMethod()
		 * CallStaticShortMethodA()
		 * CallStaticIntMethod()
		 * CallStaticLongMethod()
		 * CallStaticFloatMethod()
		 * CallStaticDoubleMethod()
		 * Returns the result of calling the static Java method.
		 * Exceptions raised during the execution of the Java method.
		 * jmidByteBufferAllocate
		 */

		mjBuffer = w->env->CallStaticObjectMethod(w->jclassByteBuffer, w->jmidByteBufferAllocate);
	}
	mjBuffer = w->env->NewGlobalRef(mjBuffer);
}

NBufferLong::~NBufferLong()
{
	delete[] maBufferMem;
	w->env->DeleteGlobalRef(mjBuffer);
}

nlong NBufferLong::get(NElement* e)
{
	return maBufferMem[e->i];
}

nlong NBufferLong::get(NElement* e, const nlong* aNlong, int nLength)
{
	//TODO
	return maBufferMem[e->i];
}

void NBufferLong::set(NElement* e, nlong nValue)
{
	maBufferMem[e->i] = nValue;
}

void NBufferLong::set(NElement* e, nlong* const aNlong, int nLength)
{
	memcpy((void*)(&maBufferMem[e->i]), (void*)aNlong, nLength);
}

} // END namespace
