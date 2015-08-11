#ifndef __OpSquad_H__
#define __OpSquad_H__

namespace NSDEVICE
{

class OpSquad
{
public:
    OpSquad(Wrapper* vWrapper, nint cMaxOpUnit);
    ~OpSquad();
    OpUnit* add(OpUnit* opUnit, bool autoclean = true);
    void clear(nint vIdDead);

    nint mIdUnique;
    nint mcMaxOpUnit;
    nint* maOpUnitType;
    Wrapper* mWrapper;
    OpUnit** maOpUnit;
    ConcurrentQueue<Op*>*** maConcurrentQueue;
};

} // End namespace

#endif
