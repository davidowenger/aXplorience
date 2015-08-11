#include "native/NCommon.h"

namespace NSNATIVE
{

NWrapper* const NWrapper::w = new NWrapper();

NWrapper* NWrapper::getInstance()
{
    return w;
}

} // END namespace
