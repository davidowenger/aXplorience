#ifndef __Op_H__
#define __Op_H__

namespace NSDEVICE
{

class Op
{
public:
	Op(NElement* element = nullptr, long a = 0, long b = 0, long c = 0, long d = 0);
	~Op();

	Op* next;
	NElement* element;
	long a;
	long b;
	long c;
	long d;
};

} // End namespace

#endif
