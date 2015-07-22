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
    virtual void cancel() override;
    virtual void handleOp() override;

    bool requestAsClient(BluetoothDevice* vBluetoothDevice);
    bool requestAsServer(BluetoothDevice* vBluetoothDevice);
    bool registerAsClient(BluetoothDevice* vBluetoothDevice);
    void registerAsServer(BluetoothSocket* vBluetoothSocket);
    String parseMac(const String& vMac);
    void setSettings(bool vIsEnable, bool vIsDiscorverable);
    void setState(bool vIsEnabled, bool vIsDiscoverable);
    void tilt(nint vcDBObjectId);

    virtual NReturn visit(NAlpha00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    //virtual NReturn visit(NBeta00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NKappa00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    //virtual NReturn visit(NLambda00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NMu00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NOmicron00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NPi00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NRho00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NSigma00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NTau00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NUpsilon00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NPhi00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;

    nint mcProcessedDevice;
    TimeStamp mcTimeStampBroadcast;
    nuint mcForce;
    nuint mcRunningInitializations;
    nuint mcDiscovery;
    nuint mcDiscoveryDone;
	unordered_set<String> maMac;
    list<Sort> maSort;
    forward_list<BluetoothDevice*> maBluetoothDevice;
    nuint mcState;
};

} // End namespace

#endif
