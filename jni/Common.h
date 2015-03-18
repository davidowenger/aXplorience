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
#include "Network.h"
#include "OpUnitListener.h"
#include "OpUnitCore.h"
#include "OpUnitServer.h"
#include "OpUnitPeer.h"
#include "Wrapper.h"
#include "NActivity.h"

#endif
