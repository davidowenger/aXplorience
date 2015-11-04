#ifndef __OpUnit_H__
#define __OpUnit_H__

namespace NSNATIVE
{

class OpUnit : public NVisitor
{
public:
    static const int OPUNIT_TYPE_NONE = 0;
    static const int OPUNIT_TYPE_DEFAULT = OPUNIT_TYPE_NONE + 1;
    static const int OPUNIT_TYPE_ACTIVITY = OPUNIT_TYPE_DEFAULT + 1;
    static const int OPUNIT_TYPE_PEER = OPUNIT_TYPE_ACTIVITY + 1;
    static const int OPUNIT_TYPE_LISTENER = OPUNIT_TYPE_PEER + 1;

    OpUnit(NWrapper* vWrapper);
    virtual ~OpUnit() override;

    virtual void cancel();
    virtual void handleOp();
    virtual void run();
    virtual OpCallback* sendOp(int vcOpUnitId, NElement* vNElement, Op* vOp);

    void execOp(Op* op);
    void init(OpSquad* vOpSquad);
    OpUnit* start();
    Op* nextOp();
    void onOpUnitStart();
    NReturn sendOpForResult(int vcOpUnitType, int vcOpUnitId, NElement* vNElement, Op* vOp);

    NWrapper* mNWrapper;
    nint mId;
    nint mIdUnique;
    nint mcUnitType;
    bool mAlive;
    bool mAliveThread;

    NEnv* mNEnv;
    thread* mThread;
    OpSquad* mOpSquad;
};

} // End namespace

#endif
