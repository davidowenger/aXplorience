#ifndef __NVisitorViewGroup_H__
#define __NVisitorViewGroup_H__

namespace NSNATIVE
{

class NVisitorViewViewGroup : public NVisitor
{
public:
	NVisitorViewViewGroup(NWrapper* w)
		: NVisitor(w)
	{
	}

    virtual ~NVisitorViewViewGroup()
	{
	}
};

} // END namespace

#endif
