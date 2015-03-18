#ifndef __Network_H__
#define __Network_H__

namespace NSDEVICE
{

class Network
{
public:
    Network(Wrapper* vWrapper);
   ~Network();

    void onReceivePacket(String vPacked);
    void sendBrodcast(String vPacked);

    Wrapper* mWrapper;
};

} // End namespace

#endif
