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
        NReturn vcRet = 0;
        if (b == -1 && c == 1) vcRet = (NReturn)NWrapper::w->mNNoObject->pointer<Bundle>();
        if (b != -1) ((Activity*)a)->onCreate((Bundle*)b);
        return vcRet;
	}

	NReturn visit(NBeta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
	{
        ((Activity*)a)->onRestart();
        return 0;
	}

	NReturn visit(NGamma00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
	{
		((Activity*)a)->onStart();
		return 0;
	}

    NReturn visit(NDelta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        ((Activity*)a)->onResume();
        return 0;
    }

	NReturn visit(NEpsilon00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
	{
		((Activity*)a)->onPause();
		return 0;
	}

    NReturn visit(NDzeta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        ((Activity*)a)->onStop();
        return 0;
    }

	NReturn visit(NEta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
	{
		((Activity*)a)->onDestroy();
		return 0;
	}

	//TODO: restore Android API
	NReturn visit(NTheta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
	{
		((Activity*)a)->onActivityResult((nint)b, (nint)c, (nint)d, (nint)e);
		return 0;
	}

	NReturn visit(NOmicron00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
	{
		((Activity*)a)->onReceiveDiscoveryFinished();
		return 0;
	}

	NReturn visit(NPi00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
	{
		((Activity*)a)->onReceiveDiscoveryStarted();
		return 0;
	}

	NReturn visit(NRho00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
	{
        NReturn vcRet = 0;
        if (b == -1 && c == 1) vcRet = (NReturn)NWrapper::w->mNNoObject->pointer<BluetoothDevice>();
        if (b != -1) ((Activity*)a)->onReceiveFoundDevice((BluetoothDevice*)b);
        return vcRet;
	}

	NReturn visit(NSigma00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
	{
		((Activity*)a)->onReceiveLocalName(NWrapper::w->nFrame->tGetString(NWrapper::w->nFrame->tRunObject((NParam)b)));
		return 0;
	}

	NReturn visit(NTau00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
	{
		((Activity*)a)->onReceiveScanMode((nint)b, (nint)c);
		return 0;
	}

	NReturn visit(NUpsilon00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
	{
		((Activity*)a)->onReceiveState((nint)b, (nint)c);
		return 0;
	}

	NReturn visit(NPhi00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
	{
	    w->nFrame->tAttachCurrentThread();
		((Activity*)a)->handleMessage(b, c, d, e);
		return 0;
	}
};

} // END namespace

#endif
