#ifndef __OpUnitCore_H__
#define __OpUnitCore_H__

namespace NSDEVICE
{

class OpUnitCore : public OpUnit
{
public:
	OpUnitCore(Wrapper* w);
   ~OpUnitCore();

    void run();
    NReturn visit(NAlpha00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0);

    Wrapper* w;
	bool mAlive;
	int mcProcessedDevice;
	BluetoothSocket* mClientSocket;
	OutputStream* mOutputStream;
	InputStream* mInputStream;
};

} // End namespace

#endif
