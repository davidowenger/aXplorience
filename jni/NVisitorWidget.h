#ifndef __NVisitorWidget_H__
#define __NVisitorWidget_H__

namespace NNameSpace
{

class NVisitorWidget : public NVisitor
{
public:
	NVisitorWidget(NWrapper* w)
		: NVisitor(w)
	{
	}

   ~NVisitorWidget()
	{
	}

	NReturn visit(NAlpha* element, NParam a, NParam b, NParam c)
	{
		return 0;
	}
};

} // END namespace

#endif
