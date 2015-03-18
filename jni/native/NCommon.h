#ifndef __NCOMMON_H__
#define __NCOMMON_H__

//*******************************************************************************
//********************************* C++ 11 **************************************
//*******************************************************************************

#if __cplusplus < 201103L
#undef __cplusplus
#define __cplusplus 201103L
#endif

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

#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <thread>
#include <jni.h>
#include <new>
//#include <assert.h>
//#include <stdint.h>
//#include <string.h>
//#include <sys/types.h>

//#include <android/bitmap.h>

#ifdef CONFIG_DEBUG

#define DEBUG 1 // Set to 1 to enable debug log traces
#define LOGPRINTV(...)  __android_log_print(ANDROID_LOG_VERBOSE,  LOG_TAG, __VA_ARGS__)
#define LOGPRINTD(...)  __android_log_print(ANDROID_LOG_DEBUG,  LOG_TAG, __VA_ARGS__)
#define LOGPRINTI(...)  __android_log_print(ANDROID_LOG_INFO,  LOG_TAG, __VA_ARGS__)
#define LOGPRINTW(...)  __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define LOGPRINTE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

#define LOGI(...) __android_log_write(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_write(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

#else // CONFIG_DEBUG

#define LOGPRINTV(...)
#define LOGPRINTD(...)
#define LOGPRINTI(...)
#define LOGPRINTW(...)
#define LOGPRINTE(...)

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
}

int to_long(const string& sLong, unsigned long long& cLong);

vector<string> split(const string& str, const string& delimiter);

int utf8len(const string& vString);

} // END namespace

namespace NSNATIVE
{

typedef long long int NLong;
typedef jobject NReturnObject;
typedef jlong NReturn;
typedef jlong NParam;
typedef JNIEnv NEnv;

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

using namespace std;

namespace NSDEVICE
{

class Bundle;
class FragmentTransaction;
class FragmentManager;
class Activity;
class View;
class ViewGroup;
class LayoutParams;
class BluetoothAdapter;
class BluetoothDevice;
class OpSquad;
class DBHandler;
class DBTable;

} // END namespace

namespace NSNATIVE
{
using namespace NSDEVICE;

typedef unsigned int nuint;
typedef long long nlong;
typedef string String;
typedef const char* CharSequence;
typedef char byte;

typedef nuint NINIT;

class NVisitor;
class NVisitorApp;
class NVisitorAppActivity;
class NVisitorAppFragment;
class NVisitorBluetooth;
class NVisitorContentRes;
class NVisitorIO;
class NVisitorView;
class NVisitorWidget;
class NFrame;

} // END namespace

using namespace NSNATIVE;

#include "native/NNoObject.h"
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

#include "device/lang/Object.h"
#include "device/util/DisplayMetrics.h"
#include "device/os/BaseBundle.h"
#include "device/os/Bundle.h"
#include "device/content/Context.h"
#include "device/content/ContextWrapper.h"
#include "device/graphics/drawable/Drawable.h"
#include "device/graphics/drawable/DrawableContainer.h"
#include "device/graphics/drawable/StateListDrawable.h"
#include "device/graphics/Typeface.h"
#include "device/content/res/Configuration.h"
#include "device/content/res/Resources.h"
#include "device/view/InputEvent.h"
#include "device/view/MotionEvent.h"
#include "device/view/GestureDetector.h"
#include "device/view/MenuItem.h"
#include "device/view/Menu.h"
#include "device/view/MenuInflater.h"
#include "device/view/LayoutInflater.h"
#include "device/view/ContextMenu.h"
#include "device/view/ContextThemeWrapper.h"
#include "device/view/View.h"
#include "device/view/ViewGroup.h"
#include "device/app/ActionBar.h"
#include "device/app/Activity.h"
#include "device/app/Fragment.h"
#include "device/app/FragmentTransaction.h"
#include "device/app/FragmentManager.h"
#include "device/io/InputStream.h"
#include "device/io/OutputStream.h"
#include "device/bluetooth/BluetoothSocket.h"
#include "device/bluetooth/BluetoothServerSocket.h"
#include "device/bluetooth/BluetoothDevice.h"
#include "device/bluetooth/BluetoothAdapter.h"

#include "device/widget/Adapter.h"
#include "device/widget/SpinnerAdapter.h"
#include "device/widget/BaseAdapter.h"
#include "device/widget/AdapterView.h"
#include "device/widget/AbsSpinner.h"
#include "device/widget/Spinner.h"
#include "device/widget/TextView.h"
#include "device/widget/Button.h"
#include "device/widget/CompoundButton.h"
#include "device/widget/ImageView.h"
#include "device/widget/EditText.h"
#include "device/widget/ImageButton.h"
#include "device/widget/ToggleButton.h"
#include "device/widget/LinearLayout.h"
#include "device/widget/FrameLayout.h"
#include "device/widget/ScrollView.h"

#include "native/NVisitorApp.h"
#include "native/NVisitorAppActivity.h"
#include "native/NVisitorAppFragment.h"
#include "native/NVisitorBluetooth.h"
#include "native/NVisitorContentRes.h"
#include "native/NVisitorIO.h"
#include "native/NVisitorGraphics.h"
#include "native/NVisitorUtil.h"
#include "native/NVisitorView.h"
#include "native/NVisitorViewView.h"
#include "native/NVisitorViewViewGroup.h"
#include "native/NVisitorWidget.h"
#include "native/NVisitorWidgetLayout.h"
#include "native/NVisitorWidgetView.h"

#endif