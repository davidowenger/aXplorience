#ifndef __COMMON_H__
#define __COMMON_H__

#include "native/NCommon.h"
#include <regex>

using namespace std::chrono;
using NSNATIVE::NWrapper;

#include "device/widget/LinearLayout.h"
#include "device/widget/TextView.h"

namespace NSDEVICE
{
class NActivity;
class BODrop;
class BOHandlerDrop;
class Wrapper;
}

#include "db/DBFile.h"
#include "db/DBHandler.h"

#include "op/Op.h"
#include "op/OpUnit.h"
#include "op/OpSquad.h"

#include "Tables.h"
#include "OpUnitCore.h"
#include "OpUnitServer.h"
#include "OpUnitPeer.h"
#include "Wrapper.h"
#include "BO.h"
#include "NActivity.h"

#endif
