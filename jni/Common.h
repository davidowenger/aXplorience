#ifndef __COMMON_H__
#define __COMMON_H__

#include "native/NCommon.h"
#include <regex>
#include <mutex>
#include <unordered_set>

using namespace std::chrono;
using NSNATIVE::NWrapper;

//TODO: include base header in widget header
namespace NSDEVICE
{
typedef mutex Mutex;
typedef steady_clock::duration::rep TimeStamp;

class OpSquad;
class Widget;
class WidgetMessage;
class WidgetHome;
class FragmentViewEdit;
class FragmentViewDetails;
class FragmentViewSettings;
class FragmentViewAbout;
class FragmentViewHome;
class FragmentView;
class NActivity;
class Wrapper;
}

#include "CircularConcurrentList.h"
#include "db/DBFile.h"
#include "db/DBHandler.h"

#include "op/Op.h"
#include "op/OpUnit.h"
#include "op/OpSquad.h"

#include "Tables.h"
#include "BOMessage.h"
#include "RootLayout.h"
#include "Network.h"
#include "OpUnitListener.h"
#include "OpUnitCore.h"
#include "OpUnitServer.h"
#include "OpUnitPeer.h"
#include "FragmentLevel.h"
#include "FragmentLevel0.h"
#include "FragmentLevel1.h"
#include "FragmentLevel2.h"
#include "Wrapper.h"
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
