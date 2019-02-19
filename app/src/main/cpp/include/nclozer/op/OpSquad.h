#ifndef __OpSquad_H__
#define __OpSquad_H__

namespace NSNATIVE
{

class OpSquad
{
public:
    OpSquad(NWrapper* vWrapper, nint cMaxOpUnit);
    ~OpSquad();
    OpUnit* add(OpUnit* opUnit, bool autoclean = true);
    void clear(nint vIdDead);

    nint mIdUnique;
    nint mcMaxOpUnit;
    nint* maOpUnitType;
    NWrapper* mNWrapper;
    OpUnit** maOpUnit;
    NConcurrentQueue<Op*>*** maNConcurrentQueue;
};

} // End namespace

#endif
