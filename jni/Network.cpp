#include "Common.h"

namespace NSDEVICE
{

Network::Network(Wrapper* vWrapper)
{
    mWrapper = vWrapper;
}

Network::~Network()
{
}

void Network::onReceivePacket(String vPacked)
{
}

void Network::sendBrodcast(String vPacked)
{
}

} // End namespace
