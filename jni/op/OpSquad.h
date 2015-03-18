#ifndef __OpSquad_H__
#define __OpSquad_H__

namespace NSDEVICE
{

class OpSquad
{
public:
	OpSquad(Wrapper* vWrapper, int cMaxOpUnit);
	~OpSquad();
	OpUnit* add(OpUnit* opUnit, bool autoclean = true);
	void clear(int vIdDead);

    int mIdUnique;
	int mcMaxOpUnit;
	int* maOpUnitType;
	Wrapper* mWrapper;
	OpUnit** maOpUnit;
    Col<Op*>*** maCol;
};

} // End namespace

#endif
