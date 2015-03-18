#ifndef __NVisitorGraphics_H__
#define __NVisitorGraphics_H__

namespace NSNATIVE
{

class NVisitorGraphics : public NVisitor
{
public:
	NVisitorGraphics(NWrapper* w)
		: NVisitor(w)
	{
	}

    virtual ~NVisitorGraphics()
	{
	}
};

} // END namespace

#endif
