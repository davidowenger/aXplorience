#ifndef __NVisitorWidget_H__
#define __NVisitorWidget_H__

namespace NSNATIVE
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
};

} // END namespace

#endif
