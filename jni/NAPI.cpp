#include "NCommon.h"
#include <typeinfo>

namespace NNameSpace
{
static int getClassName(JNIEnv* env, unsigned int obj, String& res)
{
	jthrowable exc;

	int ret = 1;
	jobject tObject = 0;
	jclass cls = 0;
	jmethodID mid = 0;
	jobject clsObj = 0;
	jclass clsCls = 0;
	jmethodID mGetName = 0;
	jstring strObj = 0;
	char const* strPtr = 0;
	String name("");

	res = "Pointer type is not global";

	if (obj) {
		exc = NULL;
		res = "Pointer Type is valid ";

		try {
			tObject = env->NewGlobalRef((jobject)obj);
		}
		catch (...) {
			tObject = 0;
		}
		exc = env->ExceptionOccurred();

		if (exc) {
			env->ExceptionClear();
			tObject = 0;
		}
	}
	if (tObject) {
		exc = NULL;
		res = "Global ref acquired ";

		try {
			cls = env->GetObjectClass((jobject)obj);
		}
		catch (...) {
			cls = 0;
		}
		exc = env->ExceptionOccurred();

		if (exc) {
			env->ExceptionClear();
			cls = 0;
		}
	}
	if (cls) {
		exc = 0;
		res += "Class found ";

		try {
			mid = env->GetMethodID(cls, "getClass", "()Ljava/lang/Class;");
		}
		catch (...) {
			mid = 0;
		}
		exc = env->ExceptionOccurred();

		if (exc) {
			env->ExceptionClear();
			mid = 0;
		}
	}
	if (mid) {
		exc = 0;
		res += "Method getClass found ";

		try {
			clsObj = env->CallObjectMethod((jobject)obj, mid);
		}
		catch (...) {
			clsObj = 0;
		}
		exc = env->ExceptionOccurred();

		if (exc) {
			env->ExceptionClear();
			clsObj = 0;
		}
	}
	if (clsObj) {
		exc = 0;
		res += "Object Class found ";

		try {
			clsCls = env->GetObjectClass(clsObj);
		}
		catch (...) {
			clsCls = 0;
		}
		exc = env->ExceptionOccurred();

		if (exc) {
			env->ExceptionClear();
			clsCls = 0;
		}
	}
	if (clsCls) {
		exc = 0;
		res += "Class Class found ";

		try {
			mGetName = env->GetMethodID(clsCls, "getName", "()Ljava/lang/String;");
		}
		catch (...) {
			mGetName = 0;
		}
		exc = env->ExceptionOccurred();

		if (exc) {
			env->ExceptionClear();
			mGetName = 0;
		}
	}
	if (mGetName) {
		exc = 0;
		res += "Method getName found ";

		try {
			strObj = (jstring)env->CallObjectMethod(clsObj, mGetName);
		}
		catch (...) {
			strObj = 0;
		}
		exc = env->ExceptionOccurred();

		if (exc) {
			env->ExceptionClear();
			strObj = 0;
		}
	}
	if (strObj) {
		exc = 0;
		res += "Object Name found ";

		try {
			const char* str = env->GetStringUTFChars(strObj, NULL);
			strPtr = str;

			if (str && strlen(str)) {
				ret = 0;
				name = String(str);
			}
		}
		catch (...) {
			name = String("");
		}
		exc = env->ExceptionOccurred();

		if (exc) {
			env->ExceptionClear();
			name = String("");
		}
	}
	if (name.size()) {
		exc = 0;
		res += "Object Name acquired :" + name + ":";

		try {
			env->ReleaseStringUTFChars(strObj, strPtr);
		}
		catch (...) {
			strPtr = 0;
		}
		exc = env->ExceptionOccurred();

		if (exc) {
			env->ExceptionClear();
			strPtr = 0;
		}
	}
	return ret;
}

NReturn NAPI_nTerminate(NWrapper* w)
{
	w->env->DeleteGlobalRef(w->tFrame);
	return 0;
}

NReturn NAPI_tRun(NWrapper* w, NParam nVisitor, NParam nElement, NParam a, NParam b, NParam c)
{
	return (NReturn)w->env->CallLongMethod(w->tFrame, w->jmidTFrameTRun, nVisitor, nElement, a, b, c);
}

NReturnObject NAPI_tRunString(NWrapper* w, CharSequence boxed)
{
	return (NReturnObject)w->env->NewStringUTF(boxed);
}

JNIEXPORT NReturn JNICALL Java_z_a_TFrame_nInit(JNIEnv* env, jobject tFrame, NParam nWrapper, NParam cState)
{
	jclass jclassTFrame = NULL;
	NWrapper* w = (NWrapper*)nWrapper;

	if (w == NULL) {
		w = new NWrapper();
		w->env = env;
		w->tFrame = w->env->NewGlobalRef(tFrame);
		w->nFrame = new NClozer(w);

		if (w->tFrame != NULL) {
			jclassTFrame = (jclass)env->NewGlobalRef(env->GetObjectClass(w->tFrame));
		}
		if (jclassTFrame != NULL) {
			w->jmidTFrameTRun = w->env->GetMethodID(jclassTFrame, "tRun", "(JJJJJ)J");
		}
		w->env->DeleteGlobalRef(jclassTFrame);
	}
	return w->nFrame->nInit((NINIT)cState);
}

JNIEXPORT NReturn JNICALL Java_z_a_TVisitor_nRun(JNIEnv* env, jobject obj, NParam nVisitor, NParam nElement, NParam a, NParam b, NParam c)
{
	return ((NVisitor*)nVisitor)->nRun((NElement*)nElement, a, b, c);
}

JNIEXPORT NReturnObject JNICALL Java_z_a_TVisitor_nRunObject(JNIEnv* env, jobject obj, NParam nVisitor, NParam nElement, NParam a, NParam b, NParam c)
{
	LOGI("Call to NATIVE for a JOBJECT at address #%llu", (unsigned long long)a);
	return (NReturnObject)((NVisitor*)nVisitor)->nRun((NElement*)nElement, a, b, c);
}

JNIEXPORT NReturnObject JNICALL Java_z_a_TFrame_nGetService(JNIEnv* env, jobject obj, jobject mIBluetoothProxy)
{
	String res("no result");

	jclass cIBluetoothProxy = env->FindClass("android/bluetooth/IBluetooth$Stub$Proxy");
	jfieldID fMRemote = env->GetFieldID(cIBluetoothProxy, "mRemote", "Landroid/os/IBinder;");
	jobject mRemote = env->GetObjectField(mIBluetoothProxy, fMRemote);

	jclass cBinderProxy = env->FindClass("android/os/BinderProxy");
	jfieldID fMObject = env->GetFieldID(cBinderProxy, "mObject", "I");
	jint mObject = env->GetIntField(mRemote, fMObject);

	void* target = (void*)mObject;
	jthrowable excep = env->ExceptionOccurred();

	if (!excep) {
		LOGI("Found: %s", res.c_str());
	} else {
		LOGE("Error: %s", res.c_str());
	}
	return (NReturnObject)env->NewStringUTF(res.c_str());
}

} // END namespace

/*
	LOGI("Call to NATIVE for a JOBJECT Service at address #%llu", (unsigned long long)mRemoteObject);
	String res("no result");
	unsigned int* nObject = (unsigned int*)mRemoteObject;

	IBinder* target = (IBinder*)env->GetIntField(obj, gBinderProxyOffsets.mObject);




	JavaVM* vm;
	jint successVM = env->GetJavaVM(&vm);
	jobject tmp = env->NewGlobalRef(obj);

	int index = 28;

	JavaVM* nObjectVM = (JavaVM*)(nObject[index]);
	//JNIEnv* nObjectEnv;
	//const JNIInvokeInterface* iInvoke = nObjectVM->functions;
	//jint successEnv = iInvoke->GetEnv(nObjectVM, (void**)&nObjectEnv, JNI_VERSION_1_4);
	//jobject tBinder = (jobject)nObject[index + 1];

	//int test = nObjectEnv->GetObjectRefType((jobject)nObject[index + 1]);

	//jclass cBinder = nObjectEnv->FindClass("android/os/Binder");
	//jmethodID mExecTransact = nObjectEnv->GetMethodID(cBinder, "execTransact", "(IIII)Z");
	//jfieldID fMObject = nObjectEnv->GetFieldID(cBinder, "mObject", "I");

	//LOGI("Trying JOBJECT Service at address #%llu", (unsigned long long)nObject[6]);
	//int errCode = getClassName((JNIEnv*)nObjectEnv, nObject[13], res);

	//jboolean bores = nObjectEnv->CallBooleanMethod(tBinder, mExecTransact,0,0,0,0);
    jthrowable excep = env->ExceptionOccurred();

	if (!excep) {
		LOGI("Found: %s", res.c_str());
	} else {
		LOGE("Error: %s", res.c_str());
	}
	return (NReturnObject)env->NewStringUTF(res.c_str());
}
*/


/*
 *
	//jobjectRefType GetObjectRefType(JNIEnv* env, jobject obj);
	//JNIInvalidRefType = 0,
	//JNILocalRefType = 1,
	//JNIGlobalRefType = 2,
	//JNIWeakGlobalRefType = 3
 *
 *
 *
	jthrowable exc = NULL;
	jmethodID jmidTFrameTRun = NULL;
	void*** nJavaBBinderHolder = (void***)mRemoteObject;
	jobject tObject = (jobject)nJavaBBinderHolder[6];

	jclass jclassTFrame = env->GetObjectClass(tObject);

	exc = env->ExceptionOccurred();

	if (exc != NULL) {
		LOGE("exception occured : GetObjectClass");
		env->ExceptionDescribe();
		env->ExceptionClear();
	}
	if (jclassTFrame != NULL) {
		LOGI("ok : GetObjectClass");
		LOGI("class : #%llu", (unsigned long long)jclassTFrame);
		jmidTFrameTRun = env->GetMethodID(jclassTFrame, "setProperty", "(Ljava/lang/String;Ljava/lang/String)V");
		exc = env->ExceptionOccurred();

		if (exc != NULL) {
			LOGE("exception occured : GetMethodID");
			env->ExceptionDescribe();
			env->ExceptionClear();
		}
	}
	if (jmidTFrameTRun != NULL) {
		LOGI("ok : GetMethodID");
		LOGI("method ID : #%llu", (unsigned long long)jmidTFrameTRun);
	}
	return (NReturnObject)env->NewStringUTF("ok");
	*/
