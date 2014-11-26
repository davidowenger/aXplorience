#ifndef __NCOMMON_H__
#define __NCOMMON_H__

//*******************************************************************************
//******************************** SETTINGS *************************************
//*******************************************************************************

#define TARGET_ANDROID
#define CONFIG_DEBUG
#define LOG_TAG "aXplorience"

//*******************************************************************************
//********************************* ANDROID *************************************
//*******************************************************************************

#ifdef TARGET_ANDROID

#include <android/log.h>

#ifndef __cplusplus
#undef __cplusplus
#define __cplusplus 201103L
#endif

#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <thread>
#include <jni.h>
//#include <android/bitmap.h>

#ifdef CONFIG_DEBUG

#define DEBUG 1 // Set to 1 to enable debug log traces
#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO,  LOG_TAG, __VA_ARGS__)
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define LOGWI(...) __android_log_write(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define LOGWE(...) __android_log_write(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

#else // CONFIG_DEBUG

#define DEBUG 0
#define LOGI(...)
#define LOGE(...)

#endif // CONFIG_DEBUG

namespace std
{

struct Tab {
	string* a;
	int length;
};

template <typename T>
string to_string(T value)
{
    std::ostringstream os;
    os << value;
    return os.str();
};

int to_long(const string& sLong, unsigned long long& cLong);

vector<string> split(const string& str, const string& delimiter);

} // END namespace

namespace NSNATIVE
{

typedef jobject NReturnObject;
typedef jlong NReturn;
typedef jlong NParam;

} // END namespace

#endif // TARGET_ANDROID

//*******************************************************************************
//****************************** WINDOWSPHONE ***********************************
//*******************************************************************************
#ifdef TARGET_WINDOWSPHONE

#endif // TARGET_WINDOWSPHONE


//*******************************************************************************
//********************************* COMMON **************************************
//*******************************************************************************

#include <iostream>
#include <cstring>

namespace NSNATIVE
{

typedef unsigned int nuint;
typedef long long nlong;
typedef std::string String;
typedef const char* CharSequence;
typedef char byte;

typedef nuint NINIT;

class NVisitor;
class NVisitorApp;
class NVisitorBluetooth;
class NVisitorIO;
class NVisitorView;
class NVisitorWidget;
class NFrame;

} // END namespace

namespace NSDEVICE
{

class Bundle;
class Activity;
class BluetoothAdapter;
class BluetoothDevice;
class OpSquad;
class DBHandler;
class DBTable;

} // END namespace

#include "native/NElement.h"
#include "native/NWrapper.h"
#include "native/NParamBox.h"
#include "native/NVisitor.h"
#include "native/NFrame.h"
#include "native/NClozer.h"

#ifdef TARGET_ANDROID
#include "native/NAPI.h"
#endif // TARGET_ANDROID

#ifdef TARGET_WINDOWSPHONE

#endif // TARGET_WINDOWSPHONE

using namespace std;
using namespace NSNATIVE;
using NSNATIVE::NWrapper;

#include "device/os/Bundle.h"
#include "device/content/Context.h"
#include "device/content/ContextWrapper.h"
#include "device/view/ContextThemeWrapper.h"
#include "device/view/View.h"
#include "device/app/Activity.h"
#include "device/view/ViewGroup.h"
#include "device/io/InputStream.h"
#include "device/io/OutputStream.h"
#include "device/bluetooth/BluetoothSocket.h"
#include "device/bluetooth/BluetoothServerSocket.h"
#include "device/bluetooth/BluetoothDevice.h"
#include "device/bluetooth/BluetoothAdapter.h"

#include "native/NVisitorApp.h"
#include "native/NVisitorBluetooth.h"
#include "native/NVisitorIO.h"
#include "native/NVisitorView.h"
#include "native/NVisitorWidget.h"

#endif
