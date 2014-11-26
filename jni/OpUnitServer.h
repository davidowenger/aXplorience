#ifndef __OpUnitServer_H__
#define __OpUnitServer_H__

namespace NSDEVICE
{

class OpUnitServer : public OpUnit
{
public:
	OpUnitServer(Wrapper* w);
   ~OpUnitServer();

    void run();
    void cancel();

    Wrapper* mw;
	BluetoothServerSocket* mServerSocket;
	BluetoothSocket* mClientSocket;
	OutputStream* mOutputStream;
	InputStream* mInputStream;

};

} // End namespace

#endif
