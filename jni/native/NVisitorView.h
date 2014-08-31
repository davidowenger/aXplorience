#ifndef __NVisitorView_H__
#define __NVisitorView_H__

namespace NSNATIVE
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
};

} // END namespace

#endif
