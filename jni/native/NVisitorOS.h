#ifndef __NVisitorOS_H__
#define __NVisitorOS_H__

namespace NSNATIVE
{

class NVisitorOS : public NVisitor
{
public:
	NVisitorOS(NWrapper* w)
		: NVisitor(w)
	{
	}

   ~NVisitorOS()
	{
	}
};

} // END namespace

#endif
