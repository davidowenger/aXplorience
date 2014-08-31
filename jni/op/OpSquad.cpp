#include "Common.h"

namespace NSDEVICE
{

OpSquad::OpSquad(int cMaxOpUnit)
{
	int id = 0;
	mcMaxOpUnit = cMaxOpUnit;
	mcOpUnit = 0;
	maOpUnit = new OpUnit*[mcMaxOpUnit];

	for ( id = 0 ; id < mcMaxOpUnit ; ++id ) {
		maOpUnit[id] = nullptr;
	}
}

OpSquad::~OpSquad()
{
}

OpUnit* OpSquad::add(OpUnit* opUnit)
{
	Op* opEmpty;
	int id = 0;

	opUnit->mOpSquad = this;
	opUnit->maOp = new Op*[mcMaxOpUnit];
	opUnit->maLast = new Op*[mcMaxOpUnit];

	for ( id = 0 ; id < mcMaxOpUnit ; ++id ) {
		opEmpty = new Op();
		opUnit->maOp[id] = opEmpty;
		opUnit->maLast[id] = opEmpty;
	}
	while (--id >= 0 && opUnit->mId == -1) {
		if (maOpUnit[id] && maOpUnit[id]->mThread && !maOpUnit[id]->mAlive) {
			delete maOpUnit[id];
			maOpUnit[id] = nullptr;
		}
		if (!maOpUnit[id]) {
			opUnit->mId = id;
			maOpUnit[id] = opUnit;
		}
	}
	return opUnit;
}

} // End namespace
