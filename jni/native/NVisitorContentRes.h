#ifndef __NVisitorContentRes_H__
#define __NVisitorContentRes_H__

namespace NSNATIVE
{

class NVisitorContentRes : public NVisitor
{
public:
	NVisitorContentRes(NWrapper* w)
		: NVisitor(w)
	{
	}

    virtual ~NVisitorContentRes()
	{
	}
};

} // END namespace

#endif
