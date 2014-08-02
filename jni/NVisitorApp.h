#ifndef __NVisitorApp_H__
#define __NVisitorApp_H__

namespace NNameSpace
{

class NVisitorApp : public NVisitor
{
public:
	NVisitorApp(NWrapper* w)
		: NVisitor(w)
	{
	}

   ~NVisitorApp()
	{
	}

	NReturn visit(NOmicron* element, NParam a, NParam b, NParam c)
	{
		w->nActivity->onCreate(NULL);
		return 0;
	}

	NReturn visit(NPi* element, NParam a, NParam b, NParam c)
	{
		w->nActivity->onPause();
		return 0;
	}

	NReturn visit(NRho* element, NParam a, NParam b, NParam c)
	{
		w->nActivity->onResume();
		return 0;
	}
};

} // END namespace

#endif
