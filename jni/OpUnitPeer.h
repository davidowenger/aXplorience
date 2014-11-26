#ifndef __OpUnitPeer_H__
#define __OpUnitPeer_H__

namespace NSDEVICE
{

class OpUnitPeer : public OpUnit
{
public:
	OpUnitPeer(Wrapper* w, BluetoothSocket* dPeerSocket, int cNextUuid = 0);
   ~OpUnitPeer();

    void run();
    int write(String packet);
    void cancel();

	int mcUuid;
	int mcProcessedPacket;

	DBTableHandler* mDropHandler;
	BluetoothSocket* mPeerSocket;
	BluetoothDevice* mPeerDevice;
	InputStream* mInputStream;
	OutputStream* mOutputStream;
	vector<String> maPacket;
};

} // End namespace

#endif
