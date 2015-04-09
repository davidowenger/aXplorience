#include "native/NCommon.h"

namespace NSNATIVE
{

NClozer::NClozer(NWrapper* w)
	: NFrame(w)
{
    w->mNNoObject = new NNoObject();
	w->apNElement = new nlong[w->N_ELEMENT] {
		(nlong)(w->mNAlpha00 = new NAlpha00()),
		(nlong)(w->mNBeta00 = new NBeta00()),
		(nlong)(w->mNGamma00 = new NGamma00()),
		(nlong)(w->mNDelta00 = new NDelta00()),
		(nlong)(w->mNEpsilon00 = new NEpsilon00()),
		(nlong)(w->mNDzeta00 = new NDzeta00()),
		(nlong)(w->mNEta00 = new NEta00()),
		(nlong)(w->mNTheta00 = new NTheta00()),
		(nlong)(w->mNIota00 = new NIota00()),
		(nlong)(w->mNKappa00 = new NKappa00()),
		(nlong)(w->mNLambda00 = new NLambda00()),
		(nlong)(w->mNMu00 = new NMu00()),
		(nlong)(w->mNNu00 = new NNu00()),
		(nlong)(w->mNXi00 = new NXi00()),
		(nlong)(w->mNOmicron00 = new NOmicron00()),
		(nlong)(w->mNPi00 = new NPi00()),
		(nlong)(w->mNRho00 = new NRho00()),
		(nlong)(w->mNSigma00 = new NSigma00()),
		(nlong)(w->mNTau00 = new NTau00()),
		(nlong)(w->mNUpsilon00 = new NUpsilon00()),
		(nlong)(w->mNPhi00 = new NPhi00()),
		(nlong)(w->mNKhi00 = new NKhi00()),
		(nlong)(w->mNPsi00 = new NPsi00()),
		(nlong)(w->mNOmega00 = new NOmega00()),

		(nlong)(w->mNAlpha01 = new NAlpha01()),
		(nlong)(w->mNBeta01 = new NBeta01()),
		(nlong)(w->mNGamma01 = new NGamma01()),
		(nlong)(w->mNDelta01 = new NDelta01()),
		(nlong)(w->mNEpsilon01 = new NEpsilon01()),
		(nlong)(w->mNDzeta01 = new NDzeta01()),
		(nlong)(w->mNEta01 = new NEta01()),
		(nlong)(w->mNTheta01 = new NTheta01()),
		(nlong)(w->mNIota01 = new NIota01()),
		(nlong)(w->mNKappa01 = new NKappa01()),
		(nlong)(w->mNLambda01 = new NLambda01()),
		(nlong)(w->mNMu01 = new NMu01()),
		(nlong)(w->mNNu01 = new NNu01()),
		(nlong)(w->mNXi01 = new NXi01()),
		(nlong)(w->mNOmicron01 = new NOmicron01()),
		(nlong)(w->mNPi01 = new NPi01()),
		(nlong)(w->mNRho01 = new NRho01()),
		(nlong)(w->mNSigma01 = new NSigma01()),
		(nlong)(w->mNTau01 = new NTau01()),
		(nlong)(w->mNUpsilon01 = new NUpsilon01()),
		(nlong)(w->mNPhi01 = new NPhi01()),
		(nlong)(w->mNKhi01 = new NKhi01()),
		(nlong)(w->mNPsi01 = new NPsi01()),
		(nlong)(w->mNOmega01 = new NOmega01()),

		(nlong)(w->mNAlpha02 = new NAlpha02()),
		(nlong)(w->mNBeta02 = new NBeta02()),
		(nlong)(w->mNGamma02 = new NGamma02()),
		(nlong)(w->mNDelta02 = new NDelta02()),
		(nlong)(w->mNEpsilon02 = new NEpsilon02()),
		(nlong)(w->mNDzeta02 = new NDzeta02()),
		(nlong)(w->mNEta02 = new NEta02()),
		(nlong)(w->mNTheta02 = new NTheta02()),
		(nlong)(w->mNIota02 = new NIota02()),
		(nlong)(w->mNKappa02 = new NKappa02()),
		(nlong)(w->mNLambda02 = new NLambda02()),
		(nlong)(w->mNMu02 = new NMu02()),
		(nlong)(w->mNNu02 = new NNu02()),
		(nlong)(w->mNXi02 = new NXi02()),
		(nlong)(w->mNOmicron02 = new NOmicron02()),
		(nlong)(w->mNPi02 = new NPi02()),
		(nlong)(w->mNRho02 = new NRho02()),
		(nlong)(w->mNSigma02 = new NSigma02()),
		(nlong)(w->mNTau02 = new NTau02()),
		(nlong)(w->mNUpsilon02 = new NUpsilon02()),
		(nlong)(w->mNPhi02 = new NPhi02()),
		(nlong)(w->mNKhi02 = new NKhi02()),
		(nlong)(w->mNPsi02 = new NPsi02()),
		(nlong)(w->mNOmega02 = new NOmega02()),

		(nlong)(w->mNAlpha03 = new NAlpha03()),
		(nlong)(w->mNBeta03 = new NBeta03()),
		(nlong)(w->mNGamma03 = new NGamma03()),
		(nlong)(w->mNDelta03 = new NDelta03()),
		(nlong)(w->mNEpsilon03 = new NEpsilon03()),
		(nlong)(w->mNDzeta03 = new NDzeta03()),
		(nlong)(w->mNEta03 = new NEta03()),
		(nlong)(w->mNTheta03 = new NTheta03()),
		(nlong)(w->mNIota03 = new NIota03()),
		(nlong)(w->mNKappa03 = new NKappa03()),
		(nlong)(w->mNLambda03 = new NLambda03()),
		(nlong)(w->mNMu03 = new NMu03()),
		(nlong)(w->mNNu03 = new NNu03()),
		(nlong)(w->mNXi03 = new NXi03()),
		(nlong)(w->mNOmicron03 = new NOmicron03()),
		(nlong)(w->mNPi03 = new NPi03()),
		(nlong)(w->mNRho03 = new NRho03()),
		(nlong)(w->mNSigma03 = new NSigma03()),
		(nlong)(w->mNTau03 = new NTau03()),
		(nlong)(w->mNUpsilon03 = new NUpsilon03()),
		(nlong)(w->mNPhi03 = new NPhi03()),
		(nlong)(w->mNKhi03 = new NKhi03()),
		(nlong)(w->mNPsi03 = new NPsi03()),
		(nlong)(w->mNOmega03 = new NOmega03())
	};
    w->mcNVisitor = 17;
    w->maNVisitor = new nlong[w->mcNVisitor] {
        (nlong)(this),
        (nlong)(w->mNVisitorApp = new NVisitorApp(w)),
        (nlong)(w->mNVisitorAppActivity = new NVisitorAppActivity(w)),
        (nlong)(w->mNVisitorAppFragment = new NVisitorAppFragment(w)),
        (nlong)(w->mNVisitorBluetooth = new NVisitorBluetooth(w)),
        (nlong)(w->mNVisitorContent = new NVisitorContent(w)),
        (nlong)(w->mNVisitorContentRes = new NVisitorContentRes(w)),
        (nlong)(w->mNVisitorGraphics = new NVisitorGraphics(w)),
        (nlong)(w->mNVisitorIO = new NVisitorIO(w)),
        (nlong)(w->mNVisitorOS = new NVisitorOS(w)),
        (nlong)(w->mNVisitorUtil = new NVisitorUtil(w)),
        (nlong)(w->mNVisitorView = new NVisitorView(w)),
        (nlong)(w->mNVisitorViewView = new NVisitorViewView(w)),
        (nlong)(w->mNVisitorViewViewGroup = new NVisitorViewViewGroup(w)),
        (nlong)(w->mNVisitorWidget = new NVisitorWidget(w)),
        (nlong)(w->mNVisitorWidgetLayout = new NVisitorWidgetLayout(w)),
        (nlong)(w->mNVisitorWidgetView = new NVisitorWidgetView(w))
    };
}

NClozer::~NClozer()
{
    delete w->dActivity;

    //TODO
    delete w->mNVisitorApp;
    delete w->mNVisitorAppActivity;
    delete w->mNVisitorAppFragment;
    delete w->mNVisitorBluetooth;
    delete w->mNVisitorContentRes;
    delete w->mNVisitorIO;
    delete w->mNVisitorView;
	delete w->mNVisitorWidget;
	delete[] w->maNVisitor;

	//TODO
	delete w->mNAlpha00;
	delete w->mNBeta00;
	delete w->mNGamma00;
    delete[] w->apNElement;

    delete w->mNNoObject;
}

NReturn NClozer::nInit(nint cState)
{
	NReturn ret = 0;

	switch (cState) {
	case GET_W:
		ret = (NReturn)w;
		break;
	case GET_VISITOR:
		ret = (NReturn)w->nFrame;
		break;
	case GET_ELEMENT:
		ret = (NReturn)w->mNAlpha00;
		break;
	}
	return ret;
}

NReturnObject NClozer::tRunString(const String& boxed)
{
	LOGPRINTD("Call to NAPI for a new string from char sequence : %s", boxed.c_str());
	return NAPI_tRunString(w, boxed);
}

String NClozer::tGetString(NReturnObject tString)
{
    LOGPRINTV("Call to NAPI to get the string from jstring : %llu", (unsigned long long)tString);
    return NAPI_tGetString(w, tString);
}

NReturn NClozer::tDeleteGlobalRef(NParamObject vGlobalRef)
{
    LOGPRINTV("Call to NAPI to delete the global reference : %llu", (unsigned long long)vGlobalRef);
    return NAPI_tDeleteGlobalRef(w, vGlobalRef);
}

NReturn NClozer::visit(NAlpha00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
	nuint index;

	for (index = 1 ; index < w->N_ELEMENT; ++index) {
		tRun(w->mNAlpha00, (NParam)w->apNElement[index], index);
	}
	for (index = 1 ; index < w->mcNVisitor; ++index) {
		tRun(w->mNBeta00, (NParam)w->maNVisitor[index], index);
	}
	Typeface::DEFAULT = Typeface::create("", Typeface::NORMAL);
	Typeface::DEFAULT_BOLD = Typeface::create("", Typeface::BOLD);
	Typeface::SANS_SERIF = Typeface::create("sans-serif", Typeface::NORMAL);
	Typeface::SERIF = Typeface::create("serif", Typeface::NORMAL);
	Typeface::MONOSPACE = Typeface::create("monospace", Typeface::NORMAL);

	w->dActivity = NWrapper::w->mNNoObject->instance<Activity>().getInstance(w);

	return (NReturn)w->dActivity;
}

NReturn NClozer::tAttachCurrentThread()
{
    LOGPRINTV("Call to NAPI to attach the current thread");
	return NAPI_tAttachCurrentThread(w);
}

NReturn NClozer::tDetachCurrentThread()
{
    LOGPRINTV("Call to NAPI to detach the current thread");
    return NAPI_tDetachCurrentThread(w);
}

} // END namespace
