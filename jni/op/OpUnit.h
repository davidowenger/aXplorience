#ifndef __OpUnit_H__
#define __OpUnit_H__

namespace NSDEVICE
{

class OpUnit : public NSNATIVE::NVisitor
{
public:
	OpUnit(NWrapper* w);
	~OpUnit();

	OpUnit* start();
	void onStart();
	virtual void listen();
	void send(OpUnit* unit, NElement* element = nullptr, long a = 0, long b = 0, long c = 0, long d = 0);
	Op* next();

	virtual void run() = 0;

	int mId;
	bool mAlive;
	std::thread* mThread;
	OpSquad* mOpSquad;
	Op** maOp;
	Op** maLast;
};

} // End namespace

#endif
