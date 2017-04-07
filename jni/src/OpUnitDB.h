#ifndef __OpUnitDB_H__
#define __OpUnitDB_H__

namespace NSDEVICE
{

class OpUnitDB : public OpUnit
{
public:
    OpUnitDB(Wrapper* const w);
    virtual ~OpUnitDB() override;

    void arFeed();
    void peerFeed(nint vOpUnitPeerId);
    void peerReceive(String& packed);
    void poiAdd(const String& id_cat, const String& title, const String& text, const String& link);
    void poiDiscard(nuint vcDBObjectId, bool vIsDeleted);
    void poiEdit(nuint vcDBObjectId, const String& id_cat, const String& title, const String& text, const String& link);
    void poiEnable(nuint vcDBObjectId, bool vIsEnabled);
    void poiFill();
    void poiList();
    void poiSort(const String& vColumn, bool vIsAscending);
    void uiInit();
    void uiFeed(nint vcView, nuint vcDBObjectId);
    void uiFeed(nint vcView, DBObject* vDBObject);
    void uiStore(nint vcView, nuint vcDBObjectId);
    void uiRestore();

    virtual void run() override;
    virtual void cancel() override;
    virtual void handleOp() override;
    virtual OpCallback* sendOp(int vcOpUnitId, NElement* vNElement, Op* vOp) override;

    virtual NReturn visit(NAlpha00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NBeta00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NGamma00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NEpsilon00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NDzeta00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NEta00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NTheta00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NIota00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NKappa00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NLambda00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NMu00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;

    nint mcProcessedDevice;
    TimeStamp mcTimeStampPrevious;
    TimeStamp mcTimeStampNow;
    nuint mcState;
    nuint mcRunningInitializations;
    nuint mcDiscovery;
    nuint mcDiscoveryDone;

    Wrapper* w;
    DBCollection* mDBCollection;

    unordered_set<String> maMac;
};

} // End namespace

#endif
