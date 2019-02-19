#include "OpCommon.h"

namespace NSNATIVE
{

OpSquad::OpSquad(NWrapper* vNWrapper, int cMaxOpUnit)
{
    int vIdSrc = 0;
    int vIdDest = 0;

    mIdUnique = 0;
    mNWrapper = vNWrapper;
    mcMaxOpUnit = cMaxOpUnit;
    maOpUnit = new OpUnit*[mcMaxOpUnit];
    maNConcurrentQueue = new NConcurrentQueue<Op*>**[mcMaxOpUnit];
    maOpUnitType = new int[mcMaxOpUnit];

    for ( vIdSrc = 0 ; vIdSrc < mcMaxOpUnit ; ++vIdSrc ) {
        maOpUnit[vIdSrc] = new OpUnit(mNWrapper);
        maOpUnit[vIdSrc]->init(this);
        maOpUnit[vIdSrc]->mAlive = false;
        maOpUnit[vIdSrc]->mAliveThread = false;
        maOpUnitType[vIdSrc] = 0;
    }
    for ( vIdDest = 0 ; vIdDest < mcMaxOpUnit ; ++vIdDest ) {
        maNConcurrentQueue[vIdDest] = new NConcurrentQueue<Op*>*[mcMaxOpUnit];

        for ( vIdSrc = 0 ; vIdSrc < mcMaxOpUnit ; ++vIdSrc ) {
            maNConcurrentQueue[vIdDest][vIdSrc] = new NConcurrentQueue<Op*>();
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
        if (maNConcurrentQueue[vIdDest] != nullptr) {
            for ( id = 0 ; id < mcMaxOpUnit ; ++id ) {
                if (maNConcurrentQueue[vIdDest][id] != nullptr) {
                    delete maNConcurrentQueue[vIdDest][id];
                }
            }
            delete[] maNConcurrentQueue[vIdDest];
        }
    }
    if (maNConcurrentQueue != nullptr) {
        delete[] maNConcurrentQueue;
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
        maNConcurrentQueue[vIdDead][id]->clear();
    }
}

} // End namespace
