#include "Common.h"

namespace NSDEVICE
{

Op::Op(NElement* element, long a, long b, long c, long d)
	: element(element), a(a), b(b), c(c), d(d)
{
	next = this;
}

Op::~Op()
{
}

} // End namespace
