#ifndef __OpSquad_H__
#define __OpSquad_H__

namespace NSDEVICE
{

class OpSquad
{
public:
	OpSquad(int cMaxOpUnit);
	~OpSquad();
	OpUnit* add(OpUnit* opUnit);

	int mcMaxOpUnit;
	int mcOpUnit;
	OpUnit** maOpUnit;
};

} // End namespace

#endif
