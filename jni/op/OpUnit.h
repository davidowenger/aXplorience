#ifndef __OpUnit_H__
#define __OpUnit_H__

namespace NSDEVICE
{

class OpUnit : public NSNATIVE::NVisitor
{
public:
	static void* getLocalStorage();

	OpUnit(Wrapper* vWrapper);
	virtual ~OpUnit() override;

	void init(OpSquad* vOpSquad);
	OpUnit* start();
	void onOpUnitStart();
	OpCallback* sendOp(int vcOpUnitId, NElement* vNElement, Op* vOp);
	Op* nextOp();
	void cleanOp();

    virtual void run();
    virtual void cancel();
    virtual void handleOp();
    virtual void execOp(Op* op);
    virtual bool waitOp(TimeStamp vcMilisecondes, NElement* vNElement);

	Wrapper* mWrapper;
	int mId;
	int mIdUnique;
    int mcUnitType;
	bool mAlive;
	bool mAliveThread;

    NEnv* mNEnv;
	thread* mThread;
	OpSquad* mOpSquad;
};

} // End namespace

#endif
