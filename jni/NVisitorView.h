#ifndef __NVisitorView_H__
#define __NVisitorView_H__

namespace NNameSpace
{

class NVisitorView : public NVisitor
{
public:
	NVisitorView(NWrapper* w)
		: NVisitor(w)
	{
	}

   ~NVisitorView()
	{
	}

	NReturn visit(NAlpha* element, NParam a, NParam b, NParam c)
	{
		return 0;
	}
};

} // END namespace

#endif
