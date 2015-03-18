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

    Wrapper* mWrapper;
	BluetoothServerSocket* mServerSocket;
};

} // End namespace

#endif
