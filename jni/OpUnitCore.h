#ifndef __OpUnitCore_H__
#define __OpUnitCore_H__

namespace NSDEVICE
{

class OpUnitCore : public OpUnit
{
public:
	OpUnitCore(Wrapper* const w);
    virtual ~OpUnitCore() override;

    void addDrop(const String& packed);
    void addSeed(const String& id_cat, const String& title, const String& text, const String& link);
    void archive(nint vcDBObjectId, bool vIsArchived);
    void buzz(nint vcDBObjectId, bool vIsBuzzed);
    void discard(nint vcDBObjectId, bool vIsDeleted);
    void enable(nint vcDBObjectId, bool vIsEnabled);
    void clear();
    String parseMac(const String& vMac);
    void render();
    void tilt();
    void setSeed(nint vcDBObjectId, const String& id_cat, const String& title, const String& text, const String& link);
    void setView(nint vIndex, nint vcDBObjectId = 1);
    void sort(const String& vColumn, bool vIsAscending);

    virtual void run() override;
    virtual void cancel() override;
    virtual void handleOp() override;

    virtual NReturn visit(NAlpha00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NBeta00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NGamma00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NDelta00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NEpsilon00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NDzeta00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NEta00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NTheta00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NIota00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NKappa00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NLambda00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NMu00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NNu00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NXi00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;

    Wrapper* mWrapper;
    nint mcProcessedDevice;
    TimeStamp mcTimeStampBroadcast;
    nuint mcForce;
    TimeStamp mcRunningInitializations;
	unordered_set<String> maMac;
};

} // End namespace

#endif
