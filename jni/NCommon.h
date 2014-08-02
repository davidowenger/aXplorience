#ifndef __NCOMMON_H__
#define __NCOMMON_H__

/*******************************************************************************
 ******************************** SETTINGS *************************************
 *******************************************************************************/
#define TARGET_ANDROID
#define CONFIG_DEBUG
#define LOG_TAG "aXplorience"

/*******************************************************************************
 ********************************* ANDROID *************************************
 *******************************************************************************/
#ifdef TARGET_ANDROID

#include <jni.h>
#include <android/log.h>
//#include <android/bitmap.h>

#ifdef CONFIG_DEBUG

#define DEBUG 1 // Set to 1 to enable debug log traces
#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

#else // CONFIG_DEBUG

#define DEBUG 0
#define LOGI(...)
#define LOGE(...)

#endif // CONFIG_DEBUG

namespace NNameSpace
{

typedef jobject NReturnObject;
typedef jlong NReturn;
typedef jlong NParam;

} // END namespace

#endif // TARGET_ANDROID

/*******************************************************************************
 ****************************** WINDOWSPHONE ***********************************
 *******************************************************************************/
#ifdef TARGET_WINDOWSPHONE

#endif // TARGET_WINDOWSPHONE


/*******************************************************************************
 ********************************* COMMON **************************************
 *******************************************************************************/
#include <iostream>
#include <cstring>

namespace NNameSpace
{

typedef jobject NReturnObject;
typedef jlong NReturn;
typedef jlong NParam;

typedef unsigned int nuint;
typedef long long nlong;
typedef std::string String;
typedef const char* CharSequence;

typedef nuint NINIT;

class NElement;
class NVisitor;
class NVisitorApp;
class NVisitorView;
class NVisitorWidget;
class NFrame;

} // END namespace

namespace NNSUser
{

class Activity;
class MyApplication;

} // END namespace

#include "NElement.h"
#include "NWrapper.h"
#include "NParamBox.h"
#include "NVisitor.h"
#include "NFrame.h"
#include "NClozer.h"

#ifdef TARGET_ANDROID
#include "NAPI.h"
#endif // TARGET_ANDROID

#ifdef TARGET_WINDOWSPHONE

#endif // TARGET_WINDOWSPHONE

using namespace NNameSpace;

#include "os/Bundle.h"
#include "content/Context.h"
#include "content/ContextWrapper.h"
#include "view/ContextThemeWrapper.h"
#include "view/View.h"
#include "app/Activity.h"
#include "MyApplication.h"

#include "NVisitorApp.h"
#include "NVisitorView.h"
#include "NVisitorWidget.h"

#endif
