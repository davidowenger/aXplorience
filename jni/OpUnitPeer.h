#ifndef __OpUnitPeer_H__
#define __OpUnitPeer_H__

namespace NSDEVICE
{

class OpUnitPeer : public OpUnit
{
public:
    OpUnitPeer(Wrapper* const w, BluetoothServerSocket* vBluetoothServerSocket, BluetoothSocket* vBluetoothSocket, BluetoothDevice* vBluetoothDevice, const String& vsMac);
    OpUnitPeer(Wrapper* const w, BluetoothDevice* vBluetoothDevice, const String& vsMac);
    virtual ~OpUnitPeer() override;

    virtual void run() override;
    virtual void handleOp() override;

    virtual NReturn visit(NAlpha00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NBeta00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;

    void write(const String& packet);

    bool mConnected;
    bool mAliveListener;
    nuint mcOrigin;
    nuint mBuzzIndex;
    nuint mUpdateIndex;
    nuint mcInterruptDone;
    TimeStamp mcTimeStampBroadcast;

    ConcurrentCircularBuffer<String*>* maMessageAlive;
    ConcurrentCircularBuffer<String*>* maMessageBuzz;
    ConcurrentCircularBuffer<String*>* maMessageUpdate;
    BluetoothServerSocket* mBluetoothServerSocket;
    BluetoothSocket* mBluetoothSocket;
    InputStream* mInputStream;
    OutputStream* mOutputStream;
    BluetoothDevice* mBluetoothDevice;

    String msMac;
};

} // End namespace

#endif
