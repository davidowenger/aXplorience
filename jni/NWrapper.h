#ifndef __NWRAPPER_H__
#define __NWRAPPER_H__

namespace NNameSpace
{

class NWrapper
{
public :
	nlong* apNElement;
	NElement* alpha;
	NElement* beta;
	NElement* gamma;
	NElement* delta;
	NElement* epsilon;
	NElement* dzeta;
	NElement* eta;
	NElement* theta;
	NElement* iota;
	NElement* kappa;
	NElement* lambda;
	NElement* mu;
	NElement* nu;
	NElement* xi;
	NElement* omicron;
	NElement* pi;
	NElement* rho;
	NElement* sigma;
	NElement* tau;
	NElement* upsilon;
	NElement* phi;
	NElement* khi;
	NElement* psi;
	NElement* omega;
    static const nuint N_ELEMENT = 24;

    nlong* apNVisitor;
	NFrame* nFrame;
	NVisitor* nVisitorApp;
	NVisitor* nVisitorView;
	NVisitor* nVisitorWidget;
    static const nuint N_VISITOR = 4;

	NNSUser::Activity* nActivity;

	JNIEnv* env;
	jobject tFrame;
	jmethodID jmidTFrameTRun;
};

} // END namespace

#endif
