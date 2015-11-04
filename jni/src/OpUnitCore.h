#ifndef __OpUnitCore_H__
#define __OpUnitCore_H__

namespace NSDEVICE
{

class OpUnitCore : public OpUnit
{
public:
    OpUnitCore(Wrapper* const w);
    virtual ~OpUnitCore() override;

    virtual void run() override;
    virtual void handleOp() override;
    virtual OpCallback* sendOp(int vcOpUnitId, NElement* vNElement, Op* vOp) override;

    String parseMac(const String& vMac);
    void registerConnection(OpUnitPeer* vOpUnitPeer, const String& vsMac, nuint vcOrigin, bool vIsAlive);
    void requestAsClient(BluetoothDevice* vBluetoothDevice);
    void requestAsServer(BluetoothServerSocket* vBluetoothServerSocket, BluetoothSocket* vBluetoothSocket);
    void setSettings(nuint vcBTState);
    void unregisterConnection(const String& vsMac);

    virtual NReturn visit(NAlpha00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NBeta00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NGamma00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NDelta00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NEpsilon00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NEta00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;

    nint mcProcessedDevice;
    TimeStamp mcTimeStampBTDiscovery;
    TimeStamp mcTimeStampBTState;
    nuint mcInterruptDone;
    nuint mcRunningInitializations;
    nuint mcDiscovery;
    nuint mcDiscoveryDone;
    nuint mcState;

    Wrapper* w;
    unordered_set<String> maMacInitializing;
    unordered_set<String> maMacConnected;
    unordered_set<BluetoothDevice*> maBluetoothDevice;
};

} // End namespace

#endif
