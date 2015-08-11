#include "Common.h"

namespace NSDEVICE
{

OpSquad::OpSquad(Wrapper* vWrapper, int cMaxOpUnit)
{
    int vIdSrc = 0;
    int vIdDest = 0;

    mIdUnique = 0;
    mWrapper = vWrapper;
    mcMaxOpUnit = cMaxOpUnit;
    maOpUnit = new OpUnit*[mcMaxOpUnit];
    maConcurrentQueue = new ConcurrentQueue<Op*>**[mcMaxOpUnit];
    maOpUnitType = new int[mcMaxOpUnit];

    for ( vIdSrc = 0 ; vIdSrc < mcMaxOpUnit ; ++vIdSrc ) {
        maOpUnit[vIdSrc] = new OpUnit(mWrapper);
        maOpUnit[vIdSrc]->init(this);
        maOpUnit[vIdSrc]->mAlive = false;
        maOpUnit[vIdSrc]->mAliveThread = false;
        maOpUnitType[vIdSrc] = 0;
    }
    for ( vIdDest = 0 ; vIdDest < mcMaxOpUnit ; ++vIdDest ) {
        maConcurrentQueue[vIdDest] = new ConcurrentQueue<Op*>*[mcMaxOpUnit];

        for ( vIdSrc = 0 ; vIdSrc < mcMaxOpUnit ; ++vIdSrc ) {
            maConcurrentQueue[vIdDest][vIdSrc] = new ConcurrentQueue<Op*>();
        }
    }
}

OpSquad::~OpSquad()
{
    int id = 0;
    int vIdDest = 0;

    for ( id = 0 ; id < mcMaxOpUnit ; ++id ) {
        if (maOpUnit[id]) {
            maOpUnit[id]->cancel();
        }
    }
    for ( id = mcMaxOpUnit - 1 ; id >= 0 ; --id ) {
        if (maOpUnit[id]->mThread) {
            maOpUnit[id]->mThread->join();
        }
    }
    for ( id = mcMaxOpUnit - 1 ; id >= 0 ; --id ) {
        if (maOpUnit[id]->mThread) {
            delete maOpUnit[id];
        }
    }
    if (maOpUnit != nullptr) {
        delete[] maOpUnit;
    }
    for ( vIdDest = 0 ; vIdDest < mcMaxOpUnit ; ++vIdDest ) {
        if (maConcurrentQueue[vIdDest] != nullptr) {
            for ( id = 0 ; id < mcMaxOpUnit ; ++id ) {
                if (maConcurrentQueue[vIdDest][id] != nullptr) {
                    delete maConcurrentQueue[vIdDest][id];
                }
            }
            delete[] maConcurrentQueue[vIdDest];
        }
    }
    if (maConcurrentQueue != nullptr) {
        delete[] maConcurrentQueue;
    }
}

OpUnit* OpSquad::add(OpUnit* vOpUnit, bool autoclean)
{
    // This function is thread-safe when used by 1 unique "manager" thread
    int id;
    OpUnit* vOpUnitTemp = nullptr;

    vOpUnit->init(this);
    vOpUnit->mId = -1;

    for ( id = 0 ; id < mcMaxOpUnit && vOpUnit->mId == -1 ; ++id ) {
        //HINT: begin critical section
        if (!maOpUnit[id]->mAliveThread) {
            vOpUnitTemp = maOpUnit[id];

            if (vOpUnitTemp->mThread) {
                vOpUnitTemp->mThread->join();
            }
            vOpUnit->mId = id;
            vOpUnit->mIdUnique = ++mIdUnique;
            clear(id);
            maOpUnit[id] = vOpUnit;
            maOpUnitType[id] = vOpUnit->mcUnitType;
            delete vOpUnitTemp;
            vOpUnitTemp = vOpUnit;
        }
        //HINT: end critical section
    }
    return vOpUnitTemp;
}

void OpSquad::clear(int vIdDead)
{
    int id;

    for ( id = 0 ; id < mcMaxOpUnit ; ++id ) {
        maConcurrentQueue[vIdDead][id]->clear();
    }
}

} // End namespace
