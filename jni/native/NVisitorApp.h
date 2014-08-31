#ifndef __NVisitorApp_H__
#define __NVisitorApp_H__

namespace NSNATIVE
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

	NReturn visit(NAlpha00* element, NParam a, NParam b, NParam c, NParam d)
	{
		NWrapper::w->dActivity->onCreate();
		return 0;
	}

	NReturn visit(NBeta00* element, NParam a, NParam b, NParam c, NParam d)
	{
		NWrapper::w->dActivity->onDestroy();
		return 0;
	}

	NReturn visit(NGamma00* element, NParam a, NParam b, NParam c, NParam d)
	{
		NWrapper::w->dActivity->onPause();
		return 0;
	}

	NReturn visit(NDelta00* element, NParam a, NParam b, NParam c, NParam d)
	{
		NWrapper::w->dActivity->onRestart();
		return 0;
	}

	NReturn visit(NEpsilon00* element, NParam a, NParam b, NParam c, NParam d)
	{
		NWrapper::w->dActivity->onResume();
		return 0;
	}

	NReturn visit(NDzeta00* element, NParam a, NParam b, NParam c, NParam d)
	{
		NWrapper::w->dActivity->onStart();
		return 0;
	}

	NReturn visit(NEta00* element, NParam a, NParam b, NParam c, NParam d)
	{
		NWrapper::w->dActivity->onStop();
		return 0;
	}

	NReturn visit(NXi00* element, NParam a, NParam b, NParam c, NParam d)
	{
		NWrapper::w->dActivity->onActivityResult(a, b, c, d);
		return 0;
	}

	NReturn visit(NOmicron00* element, NParam a, NParam b, NParam c, NParam d)
	{
		NWrapper::w->dActivity->onReceiveDiscoveryFinished();
		return 0;
	}

	NReturn visit(NPi00* element, NParam a, NParam b, NParam c, NParam d)
	{
		NWrapper::w->dActivity->onReceiveDiscoveryStarted();
		return 0;
	}

	NReturn visit(NRho00* element, NParam a, NParam b, NParam c, NParam d)
	{
		if (!a) {
			a = (NParam)(new NSDEVICE::BluetoothDevice());
		} else {
			NWrapper::w->dActivity->onReceiveFoundDevice((NSDEVICE::BluetoothDevice*)a);
		}
		return (NReturn)a;
	}

	NReturn visit(NSigma00* element, NParam a, NParam b, NParam c, NParam d)
	{
		NWrapper::w->dActivity->onReceiveLocalName(NWrapper::w->nFrame->tGetString(NWrapper::w->nFrame->tRunObject((NParam)a)));
		return 0;
	}

	NReturn visit(NTau00* element, NParam a, NParam b, NParam c, NParam d)
	{
		NWrapper::w->dActivity->onReceiveScanMode(a, b);
		return 0;
	}

	NReturn visit(NUpsilon00* element, NParam a, NParam b, NParam c, NParam d)
	{
		NWrapper::w->dActivity->onReceiveState(a, b);
		return 0;
	}

	NReturn visit(NPhi00* element, NParam a, NParam b, NParam c, NParam d)
	{
		NWrapper::w->dActivity->handleMessage(a, b, c);
		return 0;
	}
};

} // END namespace

#endif
