#ifndef __OpUnitServer_H__
#define __OpUnitServer_H__

namespace NSDEVICE
{

class OpUnitServer : public OpUnit
{
public:
    OpUnitServer(Wrapper* w);
    virtual ~OpUnitServer() override;

    virtual void run() override;
    virtual void cancel() override;

    virtual NReturn visit(NAlpha00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;

    bool mIsFirst;
    Wrapper* mWrapper;
    BluetoothSocket* mBluetoothSocket;
    BluetoothServerSocket* mBluetoothServerSocket;
};

} // End namespace

#endif
