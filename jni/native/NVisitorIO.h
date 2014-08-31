#ifndef __NVisitorIO_H__
#define __NVisitorIO_H__

namespace NSNATIVE
{

class NVisitorIO : public NVisitor
{
public:
	NVisitorIO(NWrapper* w)
		: NVisitor(w)
	{
	}

   ~NVisitorIO()
	{
	}
};

} // END namespace

#endif
