#ifndef __NWRAPPER_H__
#define __NWRAPPER_H__

namespace NSNATIVE
{

class NWrapper
{
public:
	static NWrapper* const w;

    static const nuint N_ELEMENT = 96;

	nlong* apNElement;

	NElement* alpha00;
	NElement* beta00;
	NElement* gamma00;
	NElement* delta00;
	NElement* epsilon00;
	NElement* dzeta00;
	NElement* eta00;
	NElement* theta00;
	NElement* iota00;
	NElement* kappa00;
	NElement* lambda00;
	NElement* mu00;
	NElement* nu00;
	NElement* xi00;
	NElement* omicron00;
	NElement* pi00;
	NElement* rho00;
	NElement* sigma00;
	NElement* tau00;
	NElement* upsilon00;
	NElement* phi00;
	NElement* khi00;
	NElement* psi00;
	NElement* omega00;

	NElement* alpha01;
	NElement* beta01;
	NElement* gamma01;
	NElement* delta01;
	NElement* epsilon01;
	NElement* dzeta01;
	NElement* eta01;
	NElement* theta01;
	NElement* iota01;
	NElement* kappa01;
	NElement* lambda01;
	NElement* mu01;
	NElement* nu01;
	NElement* xi01;
	NElement* omicron01;
	NElement* pi01;
	NElement* rho01;
	NElement* sigma01;
	NElement* tau01;
	NElement* upsilon01;
	NElement* phi01;
	NElement* khi01;
	NElement* psi01;
	NElement* omega01;

	NElement* alpha02;
	NElement* beta02;
	NElement* gamma02;
	NElement* delta02;
	NElement* epsilon02;
	NElement* dzeta02;
	NElement* eta02;
	NElement* theta02;
	NElement* iota02;
	NElement* kappa02;
	NElement* lambda02;
	NElement* mu02;
	NElement* nu02;
	NElement* xi02;
	NElement* omicron02;
	NElement* pi02;
	NElement* rho02;
	NElement* sigma02;
	NElement* tau02;
	NElement* upsilon02;
	NElement* phi02;
	NElement* khi02;
	NElement* psi02;
	NElement* omega02;

	NElement* alpha03;
	NElement* beta03;
	NElement* gamma03;
	NElement* delta03;
	NElement* epsilon03;
	NElement* dzeta03;
	NElement* eta03;
	NElement* theta03;
	NElement* iota03;
	NElement* kappa03;
	NElement* lambda03;
	NElement* mu03;
	NElement* nu03;
	NElement* xi03;
	NElement* omicron03;
	NElement* pi03;
	NElement* rho03;
	NElement* sigma03;
	NElement* tau03;
	NElement* upsilon03;
	NElement* phi03;
	NElement* khi03;
	NElement* psi03;
	NElement* omega03;

    nlong* apNVisitor;

	NFrame* nFrame;
	NVisitor* nVisitorApp;
	NVisitor* nVisitorBluetooth;
	NVisitor* nVisitorIO;
	NVisitor* nVisitorView;
	NVisitor* nVisitorWidget;

    static const nuint N_VISITOR = 6;

    String sFileDir;
    NSDEVICE::Activity* dActivity;

	JNIEnv* env;
	jobject tFrame;
	jmethodID jmidTFrameTRun;
	jmethodID jmidTFrameTRunObject;
};

} // END namespace

#endif
