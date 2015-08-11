#ifndef __OpUnitListener_H__
#define __OpUnitListener_H__

namespace NSDEVICE
{

class OpUnitListener : public OpUnit
{
public:
    OpUnitListener(Wrapper* w, OpUnitPeer* vOpUnitPeer);
   ~OpUnitListener();

    virtual void run() override;

    OpUnitPeer* mOpUnitPeer;
    InputStream* mInputStream;
    String mBuffer;
};

} // End namespace

#endif
