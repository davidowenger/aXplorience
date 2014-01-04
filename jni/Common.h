#ifndef __COMMON_H__
#define __COMMON_H__

#include <jni.h>
#include <time.h>

#include <android/log.h>
#include <android/bitmap.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned int nuint;
typedef long long nlong;

namespace NNameSpace
{

class NVisitorLong;

} // END namespace

#include "NElement.h"
#include "NVisitor.h"
#include "NFrame.h"
#include "NWrapper.h"
#include "NBufferLong.h"
#include "NClozer.h"
#include "NView.h"
#include "NLib.h"

#define  LOG_TAG    "aXplorience"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

/* Set to 1 to enable debug log traces */
#define DEBUG 0

using namespace NNameSpace;

#endif
