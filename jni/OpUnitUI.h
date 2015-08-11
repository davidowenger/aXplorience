#ifndef __OpUnitUI_H__
#define __OpUnitUI_H__

namespace NSDEVICE
{

class OpUnitUI : public OpUnit
{
public:
    OpUnitUI(Wrapper* const w);
    virtual ~OpUnitUI() override;

    void addDrop(String& packed);
    void addSeed(const String& id_cat, const String& title, const String& text, const String& link);
    void archive(nuint vcDBObjectId, bool vIsArchived);
    void buzz(nuint vcDBObjectId, bool vIsBuzzed);
    void discard(nuint vcDBObjectId, bool vIsDeleted);
    void enable(nuint vcDBObjectId, bool vIsEnabled);
    void initUI();
    void initView();
    void setSeed(nuint vcDBObjectId, const String& id_cat, const String& title, const String& text, const String& link);
    void setView(nint vcView, nuint vcDBObjectId);
    void setView(nint vcView, DBObject* vDBObject);
    void sort(const String& vColumn, bool vIsAscending);

    virtual void run() override;
    virtual void cancel() override;
    virtual void handleOp() override;
    virtual OpCallback* sendOp(int vcOpUnitId, NElement* vNElement, Op* vOp) override;

    virtual NReturn visit(NAlpha00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NBeta00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NGamma00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NDelta00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NEpsilon00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NDzeta00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NEta00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NTheta00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NIota00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NNu00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NXi00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NOmicron00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NRho00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;

    nint mcProcessedDevice;
    TimeStamp mcTimeStampPrevious;
    TimeStamp mcTimeStampNow;
    nuint mcState;
    nuint mcRunningInitializations;
    nuint mcDiscovery;
    nuint mcDiscoveryDone;
    unordered_set<String> maMac;
    DBCollection* mDBCollection;
};

} // End namespace

#endif
