#ifndef __COMMON_H__
#define __COMMON_H__

#include <limits>
#include <android/native_window.h>
#include <android/native_window_jni.h>
#include <op/OpCommon.h>
#include <db/DBCommon.h>
#include <graphics/GraphicsCommon.h>
#include <NConcurrentCircularBuffer.h>
#include <NSortList.h>

//*******************************************************************************
//************************************* ANDROID *********************************
//*******************************************************************************
#ifdef TARGET_ANDROID
#include <android/looper.h>
#include <android/sensor.h>
#endif

using namespace std::chrono;

namespace NSDEVICE
{

class OpUnitDB;
class AREngineListener;
class AREngine;
class Widget;
class WidgetAR;
class WidgetAbout;
class WidgetSettings;
class WidgetMessage;
class WidgetMessageList;
class WidgetMessageDetails;
class WidgetMessageEdit;
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
#include "EventManager.h"
#include "RootLayout.h"
#include "OpUnitEvents.h"
#include "OpUnitAnim.h"
#include "OpUnitAR.h"
#include "OpUnitDB.h"
#include "OpUnitPeer.h"
#include "OpUnitListener.h"
#include "OpUnitCore.h"
#include "OpUnitServer.h"
#include "Wrapper.h"
#include "NActivity.h"
#include "AREngine.h"
#include "Widget.h"
#include "WidgetAR.h"
#include "WidgetAbout.h"
#include "WidgetSettings.h"
#include "WidgetMessage.h"
#include "WidgetMessageList.h"
#include "WidgetMessageDetails.h"
#include "WidgetMessageEdit.h"

#endif
