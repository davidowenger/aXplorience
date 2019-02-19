#ifndef __NCommon_H__
#define __NCommon_H__

//*******************************************************************************
//******************************** SETTINGS *************************************
//*******************************************************************************

#define TARGET_ANDROID
#define LOG_TAG "nclozer"

//*******************************************************************************
//********************************* C++ 11 **************************************
//*******************************************************************************

#ifdef TARGET_ANDROID

#if __cplusplus < 201103L
#undef __cplusplus
#define __cplusplus 201103L
#endif

#endif // TARGET_ANDROID

#include <cmath>
#include <cstdlib>
#include <cstring>
#include <forward_list>
#include <fstream>
#include <list>
#include <map>
#include <mutex>
#include <new>
#include <regex>
#include <sstream>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

//*******************************************************************************
//********************************** LOG ****************************************
//*******************************************************************************

#ifdef NDEBUG

#define LOGPRINTV(...)
#define LOGPRINTD(...)
#define LOGPRINTI(...)
#define LOGPRINTW(...)
#define LOGPRINTE(...)
#define LOGV(...)
#define LOGD(...)
#define LOGI(...)
#define LOGW(...)
#define LOGE(...)
#define SLOGV(...)
#define SLOGI(...)
#define SLOGD(...)
#define SLOGW(...)
#define SLOGE(...)

#endif // NDEBUG

//*******************************************************************************
//*************************** LOG ANDROID  **************************************
//*******************************************************************************
#ifdef TARGET_ANDROID
#ifndef NDEBUG

#include <android/log.h>
#define DEBUG 1
#define LOGPRINTV(...)  __android_log_print(ANDROID_LOG_VERBOSE,  LOG_TAG, __VA_ARGS__)
#define LOGPRINTD(...)  __android_log_print(ANDROID_LOG_DEBUG,  LOG_TAG, __VA_ARGS__)
#define LOGPRINTI(...)  __android_log_print(ANDROID_LOG_INFO,  LOG_TAG, __VA_ARGS__)
#define LOGPRINTW(...)  __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define LOGPRINTE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define LOGV(...) __android_log_write(ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_write(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGD(...) __android_log_write(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGW(...) __android_log_write(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_write(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define SLOGV(...) LOGV((__VA_ARGS__).c_str())
#define SLOGI(...) LOGI((__VA_ARGS__).c_str())
#define SLOGD(...) LOGD((__VA_ARGS__).c_str())
#define SLOGW(...) LOGW((__VA_ARGS__).c_str())
#define SLOGE(...) LOGE((__VA_ARGS__).c_str())

#endif // NDEBUG
#endif // TARGET_ANDROID

//*******************************************************************************
//*************************** LOG WINDOWSPHONE **********************************
//*******************************************************************************
#ifdef TARGET_WINDOWSPHONE
#endif // TARGET_WINDOWSPHONE

//*******************************************************************************
//********************************** TYPES **************************************
//*******************************************************************************

namespace NSNATIVE
{
using namespace std;

typedef char nbyte;
typedef short nshort;
typedef int nint;
typedef long long int nlong;

typedef unsigned char nubyte;
typedef unsigned short nushort;
typedef unsigned int nuint;
typedef unsigned long long int nulong;

typedef float nfloat;
typedef double ndouble;

typedef string String;

typedef void GL10;

long long int to_long(const String& vsLong, int* vcError = nullptr);

vector<String> split(const String& str, const String& delimiter);

int utf8len(const String& vString);

} // END namespace

using namespace NSNATIVE;

//*******************************************************************************
//******************************* TYPES ANDROID *********************************
//*******************************************************************************
#ifdef TARGET_ANDROID

namespace NSNATIVE
{

#include <jni.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>

typedef jlong NParam;
typedef jlong NReturn;
typedef jobject NParamObject;
typedef jobject NReturnObject;
typedef JNIEnv NEnv;

template <typename T>
String to_string(T value)
{
    ostringstream os;
    os << value;
    return os.str();
}

} // END namespace

#endif // TARGET_ANDROID

//*******************************************************************************
//**************************** TYPES WINDOWSPHONE *******************************
//*******************************************************************************
#ifdef TARGET_WINDOWSPHONE
#endif // TARGET_WINDOWSPHONE

//*******************************************************************************
//******************************* COMMON ****************************************
//*******************************************************************************
#include "NWrapper.h"

#endif
