#include "Common.h"

namespace NSDEVICE
{

OpUnit::OpUnit(NWrapper* w)
	: NVisitor(w)
{
	mId = -1;
	mAlive = false;
	mOpSquad = nullptr;
	mThread = nullptr;
	maOp = nullptr;
	maLast = nullptr;
}

OpUnit::~OpUnit()
{
	if (mThread != nullptr) {
		delete mThread;
	}
}

OpUnit* OpUnit::start()
{
	if (mThread == nullptr) {
		mAlive = true;
		mThread = new std::thread(&OpUnit::onStart, this);
		mThread->detach();
	}
	return this;
}

void OpUnit::onStart()
{
	run();
	mAlive = false;
}

void OpUnit::send(OpUnit* unit, NElement* element, long a, long b, long c, long d)
{
	Op* op = new Op(element, a, b, c, d);
	maLast[unit->mId]->next = op;
	maLast[unit->mId] = op;
}

Op* OpUnit::next()
{
	int id;
	Op* op = nullptr;

	for ( id = 0 ; id < mOpSquad->mcOpUnit && !op ; ++id) {
		if (id != mId && mOpSquad->maOpUnit[id]->maOp[mId] != mOpSquad->maOpUnit[id]->maOp[mId]->next) {
			op = mOpSquad->maOpUnit[id]->maOp[mId];
			mOpSquad->maOpUnit[id]->maOp[mId] = op->next;
			delete op;
			op = mOpSquad->maOpUnit[id]->maOp[mId];
		}
	}
	return op;
}

void OpUnit::listen()
{
	int id;
	Op* op;

	while (mAlive) {
		op = next();

		if (op) {
			nRun(op->element, op->a, op->b, op->c, op->d);
		}
	}
}

void OpUnit::run()
{
	mAlive = false;
}

} // End namespace
