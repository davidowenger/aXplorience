#include "native/NCommon.h"

namespace NSNATIVE
{

NClozer::NClozer(NWrapper* w)
	: NFrame(w)
{
	w->apNElement = new nlong[w->N_ELEMENT] {
		(nlong)(w->alpha00 = new NAlpha00()),
		(nlong)(w->beta00 = new NBeta00()),
		(nlong)(w->gamma00 = new NGamma00()),
		(nlong)(w->delta00 = new NDelta00()),
		(nlong)(w->epsilon00 = new NEpsilon00()),
		(nlong)(w->dzeta00 = new NDzeta00()),
		(nlong)(w->eta00 = new NEta00()),
		(nlong)(w->theta00 = new NTheta00()),
		(nlong)(w->iota00 = new NIota00()),
		(nlong)(w->kappa00 = new NKappa00()),
		(nlong)(w->lambda00 = new NLambda00()),
		(nlong)(w->mu00 = new NMu00()),
		(nlong)(w->nu00 = new NNu00()),
		(nlong)(w->xi00 = new NXi00()),
		(nlong)(w->omicron00 = new NOmicron00()),
		(nlong)(w->pi00 = new NPi00()),
		(nlong)(w->rho00 = new NRho00()),
		(nlong)(w->sigma00 = new NSigma00()),
		(nlong)(w->tau00 = new NTau00()),
		(nlong)(w->upsilon00 = new NUpsilon00()),
		(nlong)(w->phi00 = new NPhi00()),
		(nlong)(w->khi00 = new NKhi00()),
		(nlong)(w->psi00 = new NPsi00()),
		(nlong)(w->omega00 = new NOmega00()),

		(nlong)(w->alpha01 = new NAlpha01()),
		(nlong)(w->beta01 = new NBeta01()),
		(nlong)(w->gamma01 = new NGamma01()),
		(nlong)(w->delta01 = new NDelta01()),
		(nlong)(w->epsilon01 = new NEpsilon01()),
		(nlong)(w->dzeta01 = new NDzeta01()),
		(nlong)(w->eta01 = new NEta01()),
		(nlong)(w->theta01 = new NTheta01()),
		(nlong)(w->iota01 = new NIota01()),
		(nlong)(w->kappa01 = new NKappa01()),
		(nlong)(w->lambda01 = new NLambda01()),
		(nlong)(w->mu01 = new NMu01()),
		(nlong)(w->nu01 = new NNu01()),
		(nlong)(w->xi01 = new NXi01()),
		(nlong)(w->omicron01 = new NOmicron01()),
		(nlong)(w->pi01 = new NPi01()),
		(nlong)(w->rho01 = new NRho01()),
		(nlong)(w->sigma01 = new NSigma01()),
		(nlong)(w->tau01 = new NTau01()),
		(nlong)(w->upsilon01 = new NUpsilon01()),
		(nlong)(w->phi01 = new NPhi01()),
		(nlong)(w->khi01 = new NKhi01()),
		(nlong)(w->psi01 = new NPsi01()),
		(nlong)(w->omega01 = new NOmega01()),

		(nlong)(w->alpha02 = new NAlpha02()),
		(nlong)(w->beta02 = new NBeta02()),
		(nlong)(w->gamma02 = new NGamma02()),
		(nlong)(w->delta02 = new NDelta02()),
		(nlong)(w->epsilon02 = new NEpsilon02()),
		(nlong)(w->dzeta02 = new NDzeta02()),
		(nlong)(w->eta02 = new NEta02()),
		(nlong)(w->theta02 = new NTheta02()),
		(nlong)(w->iota02 = new NIota02()),
		(nlong)(w->kappa02 = new NKappa02()),
		(nlong)(w->lambda02 = new NLambda02()),
		(nlong)(w->mu02 = new NMu02()),
		(nlong)(w->nu02 = new NNu02()),
		(nlong)(w->xi02 = new NXi02()),
		(nlong)(w->omicron02 = new NOmicron02()),
		(nlong)(w->pi02 = new NPi02()),
		(nlong)(w->rho02 = new NRho02()),
		(nlong)(w->sigma02 = new NSigma02()),
		(nlong)(w->tau02 = new NTau02()),
		(nlong)(w->upsilon02 = new NUpsilon02()),
		(nlong)(w->phi02 = new NPhi02()),
		(nlong)(w->khi02 = new NKhi02()),
		(nlong)(w->psi02 = new NPsi02()),
		(nlong)(w->omega02 = new NOmega02()),

		(nlong)(w->alpha03 = new NAlpha03()),
		(nlong)(w->beta03 = new NBeta03()),
		(nlong)(w->gamma03 = new NGamma03()),
		(nlong)(w->delta03 = new NDelta03()),
		(nlong)(w->epsilon03 = new NEpsilon03()),
		(nlong)(w->dzeta03 = new NDzeta03()),
		(nlong)(w->eta03 = new NEta03()),
		(nlong)(w->theta03 = new NTheta03()),
		(nlong)(w->iota03 = new NIota03()),
		(nlong)(w->kappa03 = new NKappa03()),
		(nlong)(w->lambda03 = new NLambda03()),
		(nlong)(w->mu03 = new NMu03()),
		(nlong)(w->nu03 = new NNu03()),
		(nlong)(w->xi03 = new NXi03()),
		(nlong)(w->omicron03 = new NOmicron03()),
		(nlong)(w->pi03 = new NPi03()),
		(nlong)(w->rho03 = new NRho03()),
		(nlong)(w->sigma03 = new NSigma03()),
		(nlong)(w->tau03 = new NTau03()),
		(nlong)(w->upsilon03 = new NUpsilon03()),
		(nlong)(w->phi03 = new NPhi03()),
		(nlong)(w->khi03 = new NKhi03()),
		(nlong)(w->psi03 = new NPsi03()),
		(nlong)(w->omega03 = new NOmega03()),
	};
	w->apNVisitor = new nlong[w->N_VISITOR] {
		(nlong)(this),
		(nlong)(w->nVisitorApp = new NVisitorApp(w)),
		(nlong)(w->nVisitorBluetooth = new NVisitorBluetooth(w)),
		(nlong)(w->nVisitorIO = new NVisitorIO(w)),
		(nlong)(w->nVisitorView = new NVisitorView(w)),
		(nlong)(w->nVisitorWidget = new NVisitorWidget(w)),
	};
}

NClozer::~NClozer()
{
	NAPI_nTerminate(w);

	delete w->nVisitorApp;
	delete w->nVisitorView;
	delete w->nVisitorWidget;
	delete[] w->apNVisitor;

	//TODO
	delete w->alpha00;
	delete w->beta00;
	delete w->gamma00;
	delete[] w->apNElement;
}

NReturn NClozer::nInit(NINIT cState)
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
		ret = (NReturn)w->alpha00;
		break;
	}
	return ret;
}

NReturnObject NClozer::tRunString(CharSequence boxed)
{
	LOGI("Call to NAPI for a new string from char sequence : %s", boxed);
	return NAPI_tRunString(w, boxed);
}

String NClozer::tGetString(NReturnObject tString)
{
	LOGI("Call to NAPI to get the string from jstring : %llu", (unsigned long long)tString);
	return NAPI_tGetString(w, tString);
}

NReturn NClozer::visit(NAlpha00* element, NParam a, NParam b, NParam c, NParam d)
{
	nuint index;

	for (index = 1 ; index < w->N_ELEMENT; ++index) {
		tRun(w->alpha00, (NParam)w->apNElement[index], index);
	}
	for (index = 1 ; index < w->N_VISITOR; ++index) {
		tRun(w->beta00, (NParam)w->apNVisitor[index], index);
	}
	w->sFileDir = tGetString(tRunObject(0));
	//w->dBluetoothAdapter = new NSDEVICE::BluetoothAdapter();
    w->dActivity = NSDEVICE::Activity::kActivity;

	return (NReturn)w->dActivity;
}

} // END namespace
