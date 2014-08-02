#include "NCommon.h"

namespace NNameSpace
{

NClozer::NClozer(NWrapper* w)
	: NFrame(w)
{
	w->apNElement = new nlong[w->N_ELEMENT] {
		(nlong)(w->alpha = new NAlpha()),
		(nlong)(w->beta = new NBeta()),
		(nlong)(w->gamma = new NGamma()),
		(nlong)(w->delta = new NDelta()),
		(nlong)(w->epsilon = new NEpsilon()),
		(nlong)(w->dzeta = new NDzeta()),
		(nlong)(w->eta = new NEta()),
		(nlong)(w->theta = new NTheta()),
		(nlong)(w->iota = new NIota()),
		(nlong)(w->kappa = new NKappa()),
		(nlong)(w->lambda = new NLambda()),
		(nlong)(w->mu = new NMu()),
		(nlong)(w->nu = new NNu()),
		(nlong)(w->xi = new NXi()),
		(nlong)(w->omicron = new NOmicron()),
		(nlong)(w->pi = new NPi()),
		(nlong)(w->rho = new NRho()),
		(nlong)(w->sigma = new NSigma()),
		(nlong)(w->tau = new NTau()),
		(nlong)(w->upsilon = new NUpsilon()),
		(nlong)(w->phi = new NPhi()),
		(nlong)(w->khi = new NKhi()),
		(nlong)(w->psi = new NPsi()),
		(nlong)(w->omega = new NOmega())
	};
	w->apNVisitor = new nlong[w->N_VISITOR] {
		(nlong)(this),
		(nlong)(w->nVisitorApp = new NVisitorApp(w)),
		(nlong)(w->nVisitorView = new NVisitorView(w)),
		(nlong)(w->nVisitorWidget = new NVisitorWidget(w))
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
	delete w->alpha;
	delete w->beta;
	delete w->gamma;
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
		ret = (NReturn)w->alpha;
		break;
	}
	return ret;
}

NReturnObject NClozer::tRunString(CharSequence boxed)
{
	LOGI("Call to API for a new string from char sequence : %s", boxed);
	return NAPI_tRunString(w, boxed);
}

NReturn NClozer::visit(NAlpha* element, NParam a, NParam b, NParam c)
{
	nuint index;

	for (index = 1 ; index < w->N_ELEMENT; ++index) {
		tRun(w->alpha, (NParam)w->apNElement[index], index);
	}
	for (index = 1 ; index < w->N_VISITOR; ++index) {
		tRun(w->beta, (NParam)w->apNVisitor[index], index);
	}
	w->nActivity = new NNSUser::MyApplication();
	w->nActivity->w = w;

	return (NReturn)w->nActivity;
}

NReturn NClozer::visit(NOmega* element, NParam a, NParam b, NParam c)
{
	return (NReturn)(*(NReturnObject*)(a + b));
}

} // END namespace
