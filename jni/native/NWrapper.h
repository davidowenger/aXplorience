#ifndef __NWRAPPER_H__
#define __NWRAPPER_H__

namespace NSNATIVE
{

class NWrapper
{
public:
    static NWrapper* const w;
	static NWrapper* getInstance();

	nlong* apNElement;

	NElement* mNAlpha00;
	NElement* mNBeta00;
	NElement* mNGamma00;
	NElement* mNDelta00;
	NElement* mNEpsilon00;
	NElement* mNDzeta00;
	NElement* mNEta00;
	NElement* mNTheta00;
	NElement* mNIota00;
	NElement* mNKappa00;
	NElement* mNLambda00;
	NElement* mNMu00;
	NElement* mNNu00;
	NElement* mNXi00;
	NElement* mNOmicron00;
	NElement* mNPi00;
	NElement* mNRho00;
	NElement* mNSigma00;
	NElement* mNTau00;
	NElement* mNUpsilon00;
	NElement* mNPhi00;
	NElement* mNKhi00;
	NElement* mNPsi00;
	NElement* mNOmega00;

	NElement* mNAlpha01;
	NElement* mNBeta01;
	NElement* mNGamma01;
	NElement* mNDelta01;
	NElement* mNEpsilon01;
	NElement* mNDzeta01;
	NElement* mNEta01;
	NElement* mNTheta01;
	NElement* mNIota01;
	NElement* mNKappa01;
	NElement* mNLambda01;
	NElement* mNMu01;
	NElement* mNNu01;
	NElement* mNXi01;
	NElement* mNOmicron01;
	NElement* mNPi01;
	NElement* mNRho01;
	NElement* mNSigma01;
	NElement* mNTau01;
	NElement* mNUpsilon01;
	NElement* mNPhi01;
	NElement* mNKhi01;
	NElement* mNPsi01;
	NElement* mNOmega01;

	NElement* mNAlpha02;
	NElement* mNBeta02;
	NElement* mNGamma02;
	NElement* mNDelta02;
	NElement* mNEpsilon02;
	NElement* mNDzeta02;
	NElement* mNEta02;
	NElement* mNTheta02;
	NElement* mNIota02;
	NElement* mNKappa02;
	NElement* mNLambda02;
	NElement* mNMu02;
	NElement* mNNu02;
	NElement* mNXi02;
	NElement* mNOmicron02;
	NElement* mNPi02;
	NElement* mNRho02;
	NElement* mNSigma02;
	NElement* mNTau02;
	NElement* mNUpsilon02;
	NElement* mNPhi02;
	NElement* mNKhi02;
	NElement* mNPsi02;
	NElement* mNOmega02;

	NElement* mNAlpha03;
	NElement* mNBeta03;
	NElement* mNGamma03;
	NElement* mNDelta03;
	NElement* mNEpsilon03;
	NElement* mNDzeta03;
	NElement* mNEta03;
	NElement* mNTheta03;
	NElement* mNIota03;
	NElement* mNKappa03;
	NElement* mNLambda03;
	NElement* mNMu03;
	NElement* mNNu03;
	NElement* mNXi03;
	NElement* mNOmicron03;
	NElement* mNPi03;
	NElement* mNRho03;
	NElement* mNSigma03;
	NElement* mNTau03;
	NElement* mNUpsilon03;
	NElement* mNPhi03;
	NElement* mNKhi03;
	NElement* mNPsi03;
	NElement* mNOmega03;
	static const nuint N_ELEMENT = 96;

    nlong* apNVisitor;

	NFrame* nFrame;
    NVisitor* mNVisitorApp;
    NVisitor* mNVisitorAppActivity;
    NVisitor* mNVisitorAppFragment;
	NVisitor* mNVisitorBluetooth;
    NVisitor* mNVisitorContentRes;
    NVisitor* mNVisitorGraphics;
    NVisitor* mNVisitorIO;
    NVisitor* mNVisitorUtil;
	NVisitor* mNVisitorView;
	NVisitor* mNVisitorViewView;
	NVisitor* mNVisitorViewViewGroup;
	NVisitor* mNVisitorWidget;
    NVisitor* mNVisitorWidgetLayout;
    NVisitor* mNVisitorWidgetView;
    static const nuint N_VISITOR = 15;

    NNoObject* mNNoObject;
    Activity* dActivity;

	JavaVM* vm;
	JNIEnv* env;
	jobject tFrame;
	jmethodID jmidTFrameTRun;
	jmethodID jmidTFrameTRunObject;
};

} // END namespace

#endif
