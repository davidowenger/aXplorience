#ifndef __OpUnitCore_H__
#define __OpUnitCore_H__

namespace NSDEVICE
{

class OpUnitCore : public OpUnit
{
public:
	OpUnitCore(Wrapper* const w);
   ~OpUnitCore();

    virtual void run() override;
    virtual void cancel() override;
    virtual void handleOp() override;

    virtual NReturn visit(NAlpha00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NBeta00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;

    String parseMac(const String& vMac);

    Wrapper* mWrapper;
	int mcProcessedDevice;
	TimeStamp mcTimeStampBroadcast;
	unordered_set<String> maMac;
};

} // End namespace

#endif
