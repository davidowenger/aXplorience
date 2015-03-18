#ifndef __NVisitorAppActivity_H__
#define __NVisitorAppActivity_H__

namespace NSNATIVE
{

class NVisitorAppActivity : public NVisitor
{
public:
    NVisitorAppActivity(NWrapper* w)
		: NVisitor(w)
	{
	}

    virtual ~NVisitorAppActivity()
	{
	}

	NReturn visit(NAlpha00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
	{
		NWrapper::getInstance()->dActivity->onCreate();
		return 0;
	}

	NReturn visit(NBeta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
	{
		NWrapper::getInstance()->dActivity->onDestroy();
		return 0;
	}

	NReturn visit(NGamma00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
	{
		NWrapper::getInstance()->dActivity->onPause();
		return 0;
	}

	NReturn visit(NDelta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
	{
		NWrapper::getInstance()->dActivity->onRestart();
		return 0;
	}

	NReturn visit(NEpsilon00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
	{
		NWrapper::getInstance()->dActivity->onResume();
		return 0;
	}

	NReturn visit(NDzeta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
	{
		NWrapper::getInstance()->dActivity->onStart();
		return 0;
	}

	NReturn visit(NEta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
	{
		NWrapper::getInstance()->dActivity->onStop();
		return 0;
	}

	NReturn visit(NTheta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
	{
		NWrapper::getInstance()->dActivity->onActivityResult(a, b, c, d);
		return 0;
	}

	NReturn visit(NOmicron00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
	{
		NWrapper::getInstance()->dActivity->onReceiveDiscoveryFinished();
		return 0;
	}

	NReturn visit(NPi00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
	{
		NWrapper::getInstance()->dActivity->onReceiveDiscoveryStarted();
		return 0;
	}

	NReturn visit(NRho00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
	{
        //FIXME: This will leak memory if "onReceiveFoundDevice" is not overloaded by the user
		if (!a) {
			a = (NParam)(new NSDEVICE::BluetoothDevice());
		} else {
			NWrapper::getInstance()->dActivity->onReceiveFoundDevice((NSDEVICE::BluetoothDevice*)a);
		}
		return (NReturn)a;
	}

	NReturn visit(NSigma00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
	{
		NWrapper::getInstance()->dActivity->onReceiveLocalName(NWrapper::getInstance()->nFrame->tGetString(NWrapper::getInstance()->nFrame->tRunObject((NParam)a)));
		return 0;
	}

	NReturn visit(NTau00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
	{
		NWrapper::getInstance()->dActivity->onReceiveScanMode(a, b);
		return 0;
	}

	NReturn visit(NUpsilon00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
	{
		NWrapper::getInstance()->dActivity->onReceiveState(a, b);
		return 0;
	}

	NReturn visit(NPhi00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
	{
		NWrapper::getInstance()->dActivity->handleMessage(a, b, c);
		return 0;
	}
};

} // END namespace

#endif
