#ifndef __NKrossWrapper_H__
#define __NKrossWrapper_H__

namespace NSNATIVE
{

class NKrossWrapper
{
public:
    nuint mcNVisitor;
    nlong* maNVisitor;

    NKrossSystem* mNKrossSystem;
    NKrossVisitor* mNVisitorApp;
    NKrossVisitor* mNVisitorAppActivity;
    NKrossVisitor* mNVisitorAppFragment;
    NKrossVisitor* mNVisitorBluetooth;
    NKrossVisitor* mNVisitorBluetoothGatt;
    NKrossVisitor* mNVisitorBluetoothLe;
    NKrossVisitor* mNVisitorContent;
    NKrossVisitor* mNVisitorContentRes;
    NKrossVisitor* mNVisitorGraphics;
    NKrossVisitor* mNVisitorHardware;
    NKrossVisitor* mNVisitorIO;
    NKrossVisitor* mNVisitorLocation;
    NKrossVisitor* mNVisitorMicroedition;
    NKrossVisitor* mNVisitorOpengl;
    NKrossVisitor* mNVisitorOS;
    NKrossVisitor* mNVisitorUtil;
    NKrossVisitor* mNVisitorView;
    NKrossVisitor* mNVisitorViewView;
    NKrossVisitor* mNVisitorViewViewGroup;
    NKrossVisitor* mNVisitorWidget;
    NKrossVisitor* mNVisitorWidgetLayout;
    NKrossVisitor* mNVisitorWidgetView;

    nuint mcNElement;
    nlong* maNElement;

    NAlpha00* mNAlpha00;
    NBeta00* mNBeta00;
    NGamma00* mNGamma00;
    NDelta00* mNDelta00;
    NEpsilon00* mNEpsilon00;
    NDzeta00* mNDzeta00;
    NEta00* mNEta00;
    NTheta00* mNTheta00;
    NIota00* mNIota00;
    NKappa00* mNKappa00;
    NLambda00* mNLambda00;
    NMu00* mNMu00;
    NNu00* mNNu00;
    NXi00* mNXi00;
    NOmicron00* mNOmicron00;
    NPi00* mNPi00;
    NRho00* mNRho00;
    NSigma00* mNSigma00;
    NTau00* mNTau00;
    NUpsilon00* mNUpsilon00;
    NPhi00* mNPhi00;
    NKhi00* mNKhi00;
    NPsi00* mNPsi00;
    NOmega00* mNOmega00;

    NAlpha01* mNAlpha01;
    NBeta01* mNBeta01;
    NGamma01* mNGamma01;
    NDelta01* mNDelta01;
    NEpsilon01* mNEpsilon01;
    NDzeta01* mNDzeta01;
    NEta01* mNEta01;
    NTheta01* mNTheta01;
    NIota01* mNIota01;
    NKappa01* mNKappa01;
    NLambda01* mNLambda01;
    NMu01* mNMu01;
    NNu01* mNNu01;
    NXi01* mNXi01;
    NOmicron01* mNOmicron01;
    NPi01* mNPi01;
    NRho01* mNRho01;
    NSigma01* mNSigma01;
    NTau01* mNTau01;
    NUpsilon01* mNUpsilon01;
    NPhi01* mNPhi01;
    NKhi01* mNKhi01;
    NPsi01* mNPsi01;
    NOmega01* mNOmega01;

    NAlpha02* mNAlpha02;
    NBeta02* mNBeta02;
    NGamma02* mNGamma02;
    NDelta02* mNDelta02;
    NEpsilon02* mNEpsilon02;
    NDzeta02* mNDzeta02;
    NEta02* mNEta02;
    NTheta02* mNTheta02;
    NIota02* mNIota02;
    NKappa02* mNKappa02;
    NLambda02* mNLambda02;
    NMu02* mNMu02;
    NNu02* mNNu02;
    NXi02* mNXi02;
    NOmicron02* mNOmicron02;
    NPi02* mNPi02;
    NRho02* mNRho02;
    NSigma02* mNSigma02;
    NTau02* mNTau02;
    NUpsilon02* mNUpsilon02;
    NPhi02* mNPhi02;
    NKhi02* mNKhi02;
    NPsi02* mNPsi02;
    NOmega02* mNOmega02;

    NAlpha03* mNAlpha03;
    NBeta03* mNBeta03;
    NGamma03* mNGamma03;
    NDelta03* mNDelta03;
    NEpsilon03* mNEpsilon03;
    NDzeta03* mNDzeta03;
    NEta03* mNEta03;
    NTheta03* mNTheta03;
    NIota03* mNIota03;
    NKappa03* mNKappa03;
    NLambda03* mNLambda03;
    NMu03* mNMu03;
    NNu03* mNNu03;
    NXi03* mNXi03;
    NOmicron03* mNOmicron03;
    NPi03* mNPi03;
    NRho03* mNRho03;
    NSigma03* mNSigma03;
    NTau03* mNTau03;
    NUpsilon03* mNUpsilon03;
    NPhi03* mNPhi03;
    NKhi03* mNKhi03;
    NPsi03* mNPsi03;
    NOmega03* mNOmega03;

    NKrossFriend* mNKrossFriend;
    Activity* mActivity;

    JavaVM* mVM;
    JNIEnv* mEnv;
    jobject mTKrossSystem;
    jmethodID mhTKrossVisitorTRun;
    jmethodID mhTKrossVisitorTRunObject;
};

} // END namespace

#endif
