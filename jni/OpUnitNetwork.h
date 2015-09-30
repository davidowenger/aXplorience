#ifndef __OpUnitNetwork_H__
#define __OpUnitNetwork_H__

namespace NSDEVICE
{

class OpUnitNetwork : public OpUnit
{
public:
    OpUnitNetwork(Wrapper* w);
    virtual ~OpUnitNetwork() override;

    virtual void run() override;
    virtual NReturn visit(NAlpha00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NBeta00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NGamma00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NDelta00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NEpsilon00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NDzeta00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;

    void addPeer(BluetoothDevice* vBluetoothDevice);
    void onClientStateChange(BluetoothDevice* device, int status, int newState);
    void onServerStateChange(Peer* vServer, int status, int newState);
    void onNotificationSent(BluetoothDevice* device, int status);
    void onServicesDiscovered(Peer* vPeer, int status);
    String parseMac(const String& vMac);
    void removePeer(Peer* vPeer);
    void scan();
    void write(const String& vPacked);

    nuint mBuzzIndex;
    nuint mUpdateIndex;
    nuint mcInterruptDone;
    nuint mcDiscovery;
    nuint mcState;
    TimeStamp mcTimeStampBroadcast;
    TimeStamp mcTimeStampBTDiscovery;

    ConcurrentCircularBuffer<String*>* maMessageAlive;
    ConcurrentCircularBuffer<String*>* maMessageBuzz;
    ConcurrentCircularBuffer<String*>* maMessageUpdate;
    unordered_set<String> maMacInitializing;
    map<String,Peer*> maMacConnected;
};

} // End namespace

#endif
