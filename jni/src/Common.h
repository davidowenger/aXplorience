#ifndef __COMMON_H__
#define __COMMON_H__

#include <android/native_window.h>
#include <android/native_window_jni.h>
#include <op/OpCommon.h>
#include <db/DBCommon.h>
#include <graphics/GraphicsCommon.h>
#include <NConcurrentCircularBuffer.h>
#include <NSortList.h>

#ifndef M_PIl
#define M_PIl 3.141592653589793238462643383279502884L
#endif
#ifndef M_PI_180
#define M_PI_180 M_PI/180.0f
#endif
#ifndef M_PI_180l
#define M_PI_180l M_PIl/180.0L
#endif

//*******************************************************************************
//************************************* ANDROID *********************************
//*******************************************************************************
#ifdef TARGET_ANDROID
#include <android/looper.h>
#include <android/sensor.h>
#endif

using namespace std::chrono;

//TODO: include base header in widget header
namespace NSDEVICE
{

class OpUnitUI;
class AREngineListener;
class AREngine;
class Widget;
class WidgetHome;
class WidgetAR;
class WidgetMessage;
class WidgetMessageDetails;
class WidgetMessageEdit;
class WidgetSettings;
class WidgetAbout;
class FragmentViewEdit;
class FragmentViewDetails;
class FragmentViewSettings;
class FragmentViewAbout;
class FragmentViewAR;
class FragmentViewHome;
class FragmentView;
class NActivity;
class Wrapper;

typedef system_clock::duration::rep TimeStamp;
typedef void(*EventAction)(Wrapper* w);

template <typename T1, typename T2, typename T3, typename T4, typename T5>
void dump(nint count, const String& vHeader, T1 vValue1, T2 vValue2, T3 vValue3, T4 vValue4, T5 vValue5)
{
    ostringstream os;
    os << vHeader;
    if (count > 0) os << " : " << vValue1;
    if (count > 1) os << " : " << vValue2;
    if (count > 2) os << " : " << vValue3;
    if (count > 3) os << " : " << vValue4;
    if (count > 4) os << " : " << vValue5;
    LOGE(os.str().c_str());
}

template <typename T1, typename T2, typename T3, typename T4, typename T5>
void dump(const String& vHeader, T1 vValue1, T2 vValue2, T3 vValue3, T4 vValue4, T5 vValue5)
{
    dump(5, vHeader, vValue1, vValue2, vValue3, vValue4, vValue5);
}

template <typename T1, typename T2, typename T3, typename T4>
void dump(const String& vHeader, T1 vValue1, T2 vValue2, T3 vValue3, T4 vValue4)
{
    dump(4, vHeader, vValue1, vValue2, vValue3, vValue4, "");
}

template <typename T1, typename T2, typename T3>
void dump(const String& vHeader, T1 vValue1, T2 vValue2, T3 vValue3)
{
    dump(3, vHeader, vValue1, vValue2, vValue3, "", "");
}

template <typename T1, typename T2>
void dump(const String& vHeader, T1 vValue1, T2 vValue2)
{
    dump(2, vHeader, vValue1, vValue2, "", "", "");
}

template <typename T1>
void dump(const String& vHeader, T1 vValue1)
{
    dump(1, vHeader, vValue1, "", "", "", "");
}

template <typename T0>
void dump(const String& vHeader)
{
    dump(0, vHeader, "", "", "", "", "");
}

}

#include "Tables.h"
#include "BOMessage.h"
#include "BOPOI.h"
#include "RootLayout.h"
#include "OpUnitEvents.h"
#include "OpUnitAnim.h"
#include "OpUnitPeer.h"
#include "OpUnitListener.h"
#include "OpUnitCore.h"
#include "OpUnitUI.h"
#include "OpUnitServer.h"
#include "FragmentLevel.h"
#include "FragmentLevel0.h"
#include "FragmentLevel1.h"
#include "FragmentLevel2.h"
#include "Wrapper.h"
#include "NActivity.h"
#include "AREngine.h"
#include "Widget.h"
#include "WidgetMessageEdit.h"
#include "WidgetMessageDetails.h"
#include "WidgetMessage.h"
#include "WidgetSettings.h"
#include "WidgetAbout.h"
#include "WidgetAR.h"
#include "WidgetHome.h"
#include "FragmentView.h"
#include "FragmentViewEdit.h"
#include "FragmentViewDetails.h"
#include "FragmentViewSettings.h"
#include "FragmentViewAbout.h"
#include "FragmentViewAR.h"
#include "FragmentViewHome.h"

#endif
