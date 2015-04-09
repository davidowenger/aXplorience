#ifndef __OpUnitPeer_H__
#define __OpUnitPeer_H__

namespace NSDEVICE
{

class OpUnitPeer : public OpUnit
{
public:
	OpUnitPeer(Wrapper* w, BluetoothSocket* dPeerSocket);
	OpUnitPeer(Wrapper* const w, BluetoothDevice* dPeerDevice);
	virtual ~OpUnitPeer() override;

    virtual void run() override;
    virtual void cancel() override;
    virtual void handleOp() override;

    virtual NReturn visit(NAlpha01* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NBeta01* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NAlpha03* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;

    int write(String packet);
    int waitMessage(String& vBuffer, TimeStamp vcSecondesTimeout);

    Wrapper* mWrapper;
	int mcOrigin;
    String mUuid;
    String mBuffer;
    TimeStamp mcTimeStampBroadcast;
    nuint mcForce;

	BluetoothServerSocket* mServerSocket;
    InputStream* mInputStream;
    OutputStream* mOutputStream;
    DBTableHandler* mDropHandler;
    OpUnitListener* mOpUnitListener;
    String msMac;
    BluetoothSocket* mPeerSocket;
    BluetoothDevice* mPeerDevice;
};

} // End namespace

#endif
