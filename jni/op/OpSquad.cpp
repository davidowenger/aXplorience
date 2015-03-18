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
    maCol = new Col<Op*>**[mcMaxOpUnit];
    maOpUnitType = new int[mcMaxOpUnit];

    for ( vIdSrc = 0 ; vIdSrc < mcMaxOpUnit ; ++vIdSrc ) {
        maOpUnit[vIdSrc] = new OpUnit(mWrapper);
        maOpUnit[vIdSrc]->init(this);
        maOpUnit[vIdSrc]->mAlive = false;
        maOpUnit[vIdSrc]->mAliveThread = false;
        maOpUnitType[vIdSrc] = 0;
    }
    for ( vIdDest = 0 ; vIdDest < mcMaxOpUnit ; ++vIdDest ) {
        maCol[vIdDest] = new Col<Op*>*[mcMaxOpUnit];

        for ( vIdSrc = 0 ; vIdSrc < mcMaxOpUnit ; ++vIdSrc ) {
            maCol[vIdDest][vIdSrc] = new Col<Op*>();
        }
    }
}

OpSquad::~OpSquad()
{
    int id = 0;
    int vIdDest = 0;

    for ( id = 0 ; id < mcMaxOpUnit ; ++id ) {
        if (maOpUnit[id]->mThread) {
        	maOpUnit[id]->cancel();
        }
    }
    for ( id = 0 ; id < mcMaxOpUnit ; ++id ) {
        if (maOpUnit[id]->mThread) {
            maOpUnit[id]->mThread->join();
        }
    }
    for ( id = 0 ; id < mcMaxOpUnit ; ++id ) {
        if (maOpUnit[id]->mThread) {
        	delete maOpUnit[id];
        }
    }
    if (maOpUnit != nullptr) {
        delete[] maOpUnit;
    }
    for ( vIdDest = 0 ; vIdDest < mcMaxOpUnit ; ++vIdDest ) {
        if (maCol[vIdDest] != nullptr) {
            for ( id = 0 ; id < mcMaxOpUnit ; ++id ) {
                if (maCol[vIdDest][id] != nullptr) {
                    delete maCol[vIdDest][id];
                }
            }
            delete[] maCol[vIdDest];
        }
    }
    if (maCol != nullptr) {
        delete[] maCol;
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
        maCol[vIdDead][id]->clear();
    }
}

} // End namespace