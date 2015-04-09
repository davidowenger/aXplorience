#include "Common.h"

namespace NSDEVICE
{

OpUnit::OpUnit(Wrapper* vWrapper)
	: NVisitor(vWrapper->w), mWrapper(vWrapper), mIdUnique(0)
{
	mId = -1;
    mcUnitType = Wrapper::OPUNIT_TYPE_DEFAULT;
    mAlive = true;
    mAliveThread = true;
	mOpSquad = nullptr;
	mThread = nullptr;
    mNEnv = nullptr;
}

OpUnit::~OpUnit()
{
    mAlive = false;
    mAliveThread = false;

    if (mThread != nullptr) {
        delete mThread;
    }
}

void OpUnit::init(OpSquad* vOpSquad)
{
    mOpSquad = vOpSquad;
}

void* OpUnit::getLocalStorage()
{
    //String sId = to_string(this_thread::get_id());
    //TODO
    return nullptr;
}

OpUnit* OpUnit::start()
{
	if (mThread == nullptr) {
		mThread = new thread(&OpUnit::onOpUnitStart, this);
	}
	return this;
}

void OpUnit::onOpUnitStart()
{
	mNEnv = (NEnv*)w->nFrame->tAttachCurrentThread();
	run();
    mAlive = false;
    //HINT: Prevent receiving too many additionnal Op since this thread is dead
	mOpSquad->maOpUnitType[mId] = 0;
    //HINT: Op sent AFTER clear() by some concurrent thread WILL be deleted when the OpSquad is deleted
    mOpSquad->clear(mId);
	w->nFrame->tDetachCurrentThread();
    mAliveThread = false;
}

void OpUnit::run()
{
}

void OpUnit::cancel()
{
    mAlive = false;
}

Op* OpUnit::nextOp()
{
    Op* vOp = nullptr;
	int id = mOpSquad->mcMaxOpUnit;
	while (mAlive && --id >= 0 && !(vOp = mOpSquad->maCol[mId][id]->next())) { }
	return vOp;
}

OpCallback* OpUnit::sendOp(int vcOpUnitType, int vcOpUnitId, NElement* vNElement, Op* vOp)
{
    OpCallback* vOpCallback = nullptr;

    if (mOpSquad->maOpUnitType[vcOpUnitId] && (!vcOpUnitType || mOpSquad->maOpUnitType[vcOpUnitId] == vcOpUnitType)) {
        vOp->mNElement = vNElement;
        mOpSquad->maCol[vcOpUnitId][mId]->add(vOp);
        vOpCallback = vOp->mOpCallback;
    }
    return vOpCallback;
}

NReturn OpUnit::sendOpForResult(int vcOpUnitType, int vcOpUnitId, NElement* vNElement, Op* vOp)
{
    OpCallback* vOpCallback = sendOp(vcOpUnitType, vcOpUnitId, vNElement, vOp);

    while (mAlive && !*vOpCallback->mDone) {
        this_thread::sleep_for(chrono::milliseconds(300));
    }
    NReturn vNReturn = *vOpCallback->mNReturn;
    delete vOpCallback;
    return vNReturn;
}

void OpUnit::handleOp()
{
    Op* op;

    while (mAlive) {
        op = nextOp();

        if (op) {
            execOp(op);
        } else {
            this_thread::sleep_for(chrono::milliseconds(300));
        }
    }
}

bool OpUnit::waitOp(TimeStamp vcMilisecondes, NElement* vNElement)
{
//    Op* vOp = nullptr;
//    bool vAlive = true;
//    TimeStamp vcTimeStampStart = steady_clock::now().time_since_epoch().count();
//    TimeStamp vcTimeStampNow;
//
//    while (vAlive && ((vcTimeStampNow = steady_clock::now().time_since_epoch().count()) - vcTimeStampStart < vcMilisecondes)) {
//        if ((vOp = nextOp()) && vOp->mNElement == vNElement) {
//            execOp(vOp);
//            vAlive = false;
//        } else {
//            this_thread::sleep_for(chrono::milliseconds(300));
//        }
//    }
//    return vAlive*1;
    return false;
}

void OpUnit::execOp(Op* vOp)
{
    NReturn vNReturn = nRun(vOp->mNElement, vOp->a, vOp->b, vOp->c, vOp->d, vOp->e);

    if (vOp->mOpCallback) {
        *vOp->mOpCallback->mNReturn = vNReturn;
        *vOp->mOpCallback->mDone = true;
    }
}

} // End namespace
