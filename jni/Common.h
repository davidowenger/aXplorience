#ifndef __COMMON_H__
#define __COMMON_H__

#include "native/NCommon.h"
#include <regex>
#include <mutex>
#include <condition_variable>
#include <set>
#include <unordered_set>
#include <list>
#include <forward_list>

using namespace std::chrono;
using NSNATIVE::NWrapper;

//TODO: include base header in widget header
namespace NSDEVICE
{
typedef system_clock::duration::rep TimeStamp;

class OpSquad;
class OpUnitUI;
class Widget;
class WidgetHome;
class WidgetMessage;
class WidgetMessageDetails;
class WidgetMessageEdit;
class WidgetSettings;
class WidgetAbout;
class FragmentViewEdit;
class FragmentViewDetails;
class FragmentViewSettings;
class FragmentViewAbout;
class FragmentViewHome;
class FragmentView;
class NActivity;
class NetworkAdvertiseCallback;
class NetworkScanCallback;
class NetworkClientCallback;
class NetworkServerCallback;
class Wrapper;

typedef void(*EventAction)(Wrapper* w);
}

#include "ConcurrentCircularBuffer.h"
#include "ConcurrentQueue.h"
#include "db/DBFile.h"
#include "db/DBHandler.h"

#include "op/Op.h"
#include "op/OpUnit.h"
#include "op/OpSquad.h"

#include "Tables.h"
#include "BOMessage.h"
#include "RootLayout.h"
#include "Peer.h"
#include "OpUnitNetwork.h"
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
#include "NetworkAdvertiseCallback.h"
#include "NetworkServerCallback.h"
#include "NetworkClientCallback.h"
#include "NetworkScanCallback.h"
#include "NActivity.h"
#include "Widget.h"
#include "WidgetMessageEdit.h"
#include "WidgetMessageDetails.h"
#include "WidgetMessage.h"
#include "WidgetSettings.h"
#include "WidgetAbout.h"
#include "WidgetHome.h"
#include "FragmentView.h"
#include "FragmentViewEdit.h"
#include "FragmentViewDetails.h"
#include "FragmentViewSettings.h"
#include "FragmentViewAbout.h"
#include "FragmentViewHome.h"

#endif
