#ifndef __OpUnitAR_H__
#define __OpUnitAR_H__

namespace NSDEVICE
{

class OpUnitAR : public OpUnit
{
public:
    OpUnitAR(Wrapper* const w);
    virtual ~OpUnitAR() override;
    virtual void run() override;

    void engineCreate();
    void enginePlay();
    void engineRunEvent(nlong vT, nuint vX, nuint vY, nuint vState);
    void poiAdd(DBObject* vDBObject);
    void poiDiscard(nuint vDBObjectId);
    void poiPosition(DBObject* vDBObject);
    void poiUpdate(DBObject* vDBObject);

    virtual NReturn visit(NBeta00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NGamma00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NDelta00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NEpsilon00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NDzeta00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;

    bool mIsARInitialized;
    nuint mARState;
    Wrapper* w;
};

} // End namespace

#endif
