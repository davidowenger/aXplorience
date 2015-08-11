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
    //HINT: Prevent receiving too many additional Op since this thread is dead
    mOpSquad->maOpUnitType[mId] = 0;
    //HINT: Op sent AFTER clear() by some concurrent thread WILL be deleted when the OpSquad is deleted
    mOpSquad->clear(mId);
    w->nFrame->tDetachCurrentThread();
    mAliveThread = false;
}

void OpUnit::run()
{
    handleOp();
    cancel();
}

void OpUnit::cancel()
{
    mAlive = false;
}

Op* OpUnit::nextOp()
{
    Op* vOp = nullptr;
    nint id = -1;
    while (mAlive && ++id < mOpSquad->mcMaxOpUnit && !(vOp = mOpSquad->maConcurrentQueue[mId][id]->next())) { }
    return vOp;
}

OpCallback* OpUnit::sendOp(int vcOpUnitId, NElement* vNElement, Op* vOp)
{
    OpCallback* vOpCallback = nullptr;

    if (mAlive && mOpSquad->maOpUnitType[vcOpUnitId]) {
        vOp->mNElement = vNElement;
        mOpSquad->maConcurrentQueue[vcOpUnitId][mId]->add(vOp);
        vOpCallback = vOp->mOpCallback;
    }
    return vOpCallback;
}

NReturn OpUnit::sendOpForResult(int vcOpUnitType, int vcOpUnitId, NElement* vNElement, Op* vOp)
{
    OpCallback* vOpCallback = sendOp(vcOpUnitId, vNElement, vOp);

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
        }
        this_thread::sleep_for(chrono::milliseconds(200));
    }
}

bool OpUnit::waitOp(TimeStamp vcMilisecondes, NElement* vNElement)
{
    return false;
}

void OpUnit::execOp(Op* vOp)
{
    NReturn vNReturn = nRun(vOp->mNElement, vOp->a, vOp->b, vOp->c, vOp->d, vOp->e);

    if (vOp->mOpCallback) {
        *vOp->mOpCallback->mNReturn = vNReturn;
        *vOp->mOpCallback->mDone = true;
    }
    delete vOp;
}

} // End namespace
