#include "NKrossCommon.h"

int NSDEVICE::Build::VERSION::SDK_INT = 0;

namespace NSNATIVE
{

NKrossSystem::NKrossSystem(NWrapper* vNWrapper)
    : NKrossVisitor(vNWrapper)
{
    mNWrapper->mNKrossWrapper->mNKrossFriend = new NKrossFriend();

    mNWrapper->mNKrossWrapper->mcNElement = 96;
    mNWrapper->mNKrossWrapper->maNElement = new nlong[mNWrapper->mNKrossWrapper->mcNElement] {
        (nlong)(mNWrapper->mNKrossWrapper->mNAlpha00 = new NAlpha00()),
        (nlong)(mNWrapper->mNKrossWrapper->mNBeta00 = new NBeta00()),
        (nlong)(mNWrapper->mNKrossWrapper->mNGamma00 = new NGamma00()),
        (nlong)(mNWrapper->mNKrossWrapper->mNDelta00 = new NDelta00()),
        (nlong)(mNWrapper->mNKrossWrapper->mNEpsilon00 = new NEpsilon00()),
        (nlong)(mNWrapper->mNKrossWrapper->mNDzeta00 = new NDzeta00()),
        (nlong)(mNWrapper->mNKrossWrapper->mNEta00 = new NEta00()),
        (nlong)(mNWrapper->mNKrossWrapper->mNTheta00 = new NTheta00()),
        (nlong)(mNWrapper->mNKrossWrapper->mNIota00 = new NIota00()),
        (nlong)(mNWrapper->mNKrossWrapper->mNKappa00 = new NKappa00()),
        (nlong)(mNWrapper->mNKrossWrapper->mNLambda00 = new NLambda00()),
        (nlong)(mNWrapper->mNKrossWrapper->mNMu00 = new NMu00()),
        (nlong)(mNWrapper->mNKrossWrapper->mNNu00 = new NNu00()),
        (nlong)(mNWrapper->mNKrossWrapper->mNXi00 = new NXi00()),
        (nlong)(mNWrapper->mNKrossWrapper->mNOmicron00 = new NOmicron00()),
        (nlong)(mNWrapper->mNKrossWrapper->mNPi00 = new NPi00()),
        (nlong)(mNWrapper->mNKrossWrapper->mNRho00 = new NRho00()),
        (nlong)(mNWrapper->mNKrossWrapper->mNSigma00 = new NSigma00()),
        (nlong)(mNWrapper->mNKrossWrapper->mNTau00 = new NTau00()),
        (nlong)(mNWrapper->mNKrossWrapper->mNUpsilon00 = new NUpsilon00()),
        (nlong)(mNWrapper->mNKrossWrapper->mNPhi00 = new NPhi00()),
        (nlong)(mNWrapper->mNKrossWrapper->mNKhi00 = new NKhi00()),
        (nlong)(mNWrapper->mNKrossWrapper->mNPsi00 = new NPsi00()),
        (nlong)(mNWrapper->mNKrossWrapper->mNOmega00 = new NOmega00()),

        (nlong)(mNWrapper->mNKrossWrapper->mNAlpha01 = new NAlpha01()),
        (nlong)(mNWrapper->mNKrossWrapper->mNBeta01 = new NBeta01()),
        (nlong)(mNWrapper->mNKrossWrapper->mNGamma01 = new NGamma01()),
        (nlong)(mNWrapper->mNKrossWrapper->mNDelta01 = new NDelta01()),
        (nlong)(mNWrapper->mNKrossWrapper->mNEpsilon01 = new NEpsilon01()),
        (nlong)(mNWrapper->mNKrossWrapper->mNDzeta01 = new NDzeta01()),
        (nlong)(mNWrapper->mNKrossWrapper->mNEta01 = new NEta01()),
        (nlong)(mNWrapper->mNKrossWrapper->mNTheta01 = new NTheta01()),
        (nlong)(mNWrapper->mNKrossWrapper->mNIota01 = new NIota01()),
        (nlong)(mNWrapper->mNKrossWrapper->mNKappa01 = new NKappa01()),
        (nlong)(mNWrapper->mNKrossWrapper->mNLambda01 = new NLambda01()),
        (nlong)(mNWrapper->mNKrossWrapper->mNMu01 = new NMu01()),
        (nlong)(mNWrapper->mNKrossWrapper->mNNu01 = new NNu01()),
        (nlong)(mNWrapper->mNKrossWrapper->mNXi01 = new NXi01()),
        (nlong)(mNWrapper->mNKrossWrapper->mNOmicron01 = new NOmicron01()),
        (nlong)(mNWrapper->mNKrossWrapper->mNPi01 = new NPi01()),
        (nlong)(mNWrapper->mNKrossWrapper->mNRho01 = new NRho01()),
        (nlong)(mNWrapper->mNKrossWrapper->mNSigma01 = new NSigma01()),
        (nlong)(mNWrapper->mNKrossWrapper->mNTau01 = new NTau01()),
        (nlong)(mNWrapper->mNKrossWrapper->mNUpsilon01 = new NUpsilon01()),
        (nlong)(mNWrapper->mNKrossWrapper->mNPhi01 = new NPhi01()),
        (nlong)(mNWrapper->mNKrossWrapper->mNKhi01 = new NKhi01()),
        (nlong)(mNWrapper->mNKrossWrapper->mNPsi01 = new NPsi01()),
        (nlong)(mNWrapper->mNKrossWrapper->mNOmega01 = new NOmega01()),

        (nlong)(mNWrapper->mNKrossWrapper->mNAlpha02 = new NAlpha02()),
        (nlong)(mNWrapper->mNKrossWrapper->mNBeta02 = new NBeta02()),
        (nlong)(mNWrapper->mNKrossWrapper->mNGamma02 = new NGamma02()),
        (nlong)(mNWrapper->mNKrossWrapper->mNDelta02 = new NDelta02()),
        (nlong)(mNWrapper->mNKrossWrapper->mNEpsilon02 = new NEpsilon02()),
        (nlong)(mNWrapper->mNKrossWrapper->mNDzeta02 = new NDzeta02()),
        (nlong)(mNWrapper->mNKrossWrapper->mNEta02 = new NEta02()),
        (nlong)(mNWrapper->mNKrossWrapper->mNTheta02 = new NTheta02()),
        (nlong)(mNWrapper->mNKrossWrapper->mNIota02 = new NIota02()),
        (nlong)(mNWrapper->mNKrossWrapper->mNKappa02 = new NKappa02()),
        (nlong)(mNWrapper->mNKrossWrapper->mNLambda02 = new NLambda02()),
        (nlong)(mNWrapper->mNKrossWrapper->mNMu02 = new NMu02()),
        (nlong)(mNWrapper->mNKrossWrapper->mNNu02 = new NNu02()),
        (nlong)(mNWrapper->mNKrossWrapper->mNXi02 = new NXi02()),
        (nlong)(mNWrapper->mNKrossWrapper->mNOmicron02 = new NOmicron02()),
        (nlong)(mNWrapper->mNKrossWrapper->mNPi02 = new NPi02()),
        (nlong)(mNWrapper->mNKrossWrapper->mNRho02 = new NRho02()),
        (nlong)(mNWrapper->mNKrossWrapper->mNSigma02 = new NSigma02()),
        (nlong)(mNWrapper->mNKrossWrapper->mNTau02 = new NTau02()),
        (nlong)(mNWrapper->mNKrossWrapper->mNUpsilon02 = new NUpsilon02()),
        (nlong)(mNWrapper->mNKrossWrapper->mNPhi02 = new NPhi02()),
        (nlong)(mNWrapper->mNKrossWrapper->mNKhi02 = new NKhi02()),
        (nlong)(mNWrapper->mNKrossWrapper->mNPsi02 = new NPsi02()),
        (nlong)(mNWrapper->mNKrossWrapper->mNOmega02 = new NOmega02()),

        (nlong)(mNWrapper->mNKrossWrapper->mNAlpha03 = new NAlpha03()),
        (nlong)(mNWrapper->mNKrossWrapper->mNBeta03 = new NBeta03()),
        (nlong)(mNWrapper->mNKrossWrapper->mNGamma03 = new NGamma03()),
        (nlong)(mNWrapper->mNKrossWrapper->mNDelta03 = new NDelta03()),
        (nlong)(mNWrapper->mNKrossWrapper->mNEpsilon03 = new NEpsilon03()),
        (nlong)(mNWrapper->mNKrossWrapper->mNDzeta03 = new NDzeta03()),
        (nlong)(mNWrapper->mNKrossWrapper->mNEta03 = new NEta03()),
        (nlong)(mNWrapper->mNKrossWrapper->mNTheta03 = new NTheta03()),
        (nlong)(mNWrapper->mNKrossWrapper->mNIota03 = new NIota03()),
        (nlong)(mNWrapper->mNKrossWrapper->mNKappa03 = new NKappa03()),
        (nlong)(mNWrapper->mNKrossWrapper->mNLambda03 = new NLambda03()),
        (nlong)(mNWrapper->mNKrossWrapper->mNMu03 = new NMu03()),
        (nlong)(mNWrapper->mNKrossWrapper->mNNu03 = new NNu03()),
        (nlong)(mNWrapper->mNKrossWrapper->mNXi03 = new NXi03()),
        (nlong)(mNWrapper->mNKrossWrapper->mNOmicron03 = new NOmicron03()),
        (nlong)(mNWrapper->mNKrossWrapper->mNPi03 = new NPi03()),
        (nlong)(mNWrapper->mNKrossWrapper->mNRho03 = new NRho03()),
        (nlong)(mNWrapper->mNKrossWrapper->mNSigma03 = new NSigma03()),
        (nlong)(mNWrapper->mNKrossWrapper->mNTau03 = new NTau03()),
        (nlong)(mNWrapper->mNKrossWrapper->mNUpsilon03 = new NUpsilon03()),
        (nlong)(mNWrapper->mNKrossWrapper->mNPhi03 = new NPhi03()),
        (nlong)(mNWrapper->mNKrossWrapper->mNKhi03 = new NKhi03()),
        (nlong)(mNWrapper->mNKrossWrapper->mNPsi03 = new NPsi03()),
        (nlong)(mNWrapper->mNKrossWrapper->mNOmega03 = new NOmega03())
    };

    mNWrapper->mNKrossWrapper->mcNVisitor = 23;
    mNWrapper->mNKrossWrapper->maNVisitor = new nlong[mNWrapper->mNKrossWrapper->mcNVisitor] {
        (nlong)(this),
        (nlong)(mNWrapper->mNKrossWrapper->mNVisitorApp = new NVisitorApp(mNWrapper)),
        (nlong)(mNWrapper->mNKrossWrapper->mNVisitorAppActivity = new NVisitorAppActivity(mNWrapper)),
        (nlong)(mNWrapper->mNKrossWrapper->mNVisitorAppFragment = new NVisitorAppFragment(mNWrapper)),
        (nlong)(mNWrapper->mNKrossWrapper->mNVisitorBluetooth = new NVisitorBluetooth(mNWrapper)),
        (nlong)(mNWrapper->mNKrossWrapper->mNVisitorBluetoothGatt = new NVisitorBluetoothGatt(mNWrapper)),
        (nlong)(mNWrapper->mNKrossWrapper->mNVisitorBluetoothLe = new NVisitorBluetoothLe(mNWrapper)),
        (nlong)(mNWrapper->mNKrossWrapper->mNVisitorContent = new NVisitorContent(mNWrapper)),
        (nlong)(mNWrapper->mNKrossWrapper->mNVisitorContentRes = new NVisitorContentRes(mNWrapper)),
        (nlong)(mNWrapper->mNKrossWrapper->mNVisitorGraphics = new NVisitorGraphics(mNWrapper)),
        (nlong)(mNWrapper->mNKrossWrapper->mNVisitorHardware = new NVisitorHardware(mNWrapper)),
        (nlong)(mNWrapper->mNKrossWrapper->mNVisitorIO = new NVisitorIO(mNWrapper)),
        (nlong)(mNWrapper->mNKrossWrapper->mNVisitorLocation = new NVisitorLocation(mNWrapper)),
        (nlong)(mNWrapper->mNKrossWrapper->mNVisitorMicroedition = new NVisitorMicroedition(mNWrapper)),
        (nlong)(mNWrapper->mNKrossWrapper->mNVisitorOpengl = new NVisitorOpengl(mNWrapper)),
        (nlong)(mNWrapper->mNKrossWrapper->mNVisitorOS = new NVisitorOS(mNWrapper)),
        (nlong)(mNWrapper->mNKrossWrapper->mNVisitorUtil = new NVisitorUtil(mNWrapper)),
        (nlong)(mNWrapper->mNKrossWrapper->mNVisitorView = new NVisitorView(mNWrapper)),
        (nlong)(mNWrapper->mNKrossWrapper->mNVisitorViewView = new NVisitorViewView(mNWrapper)),
        (nlong)(mNWrapper->mNKrossWrapper->mNVisitorViewViewGroup = new NVisitorViewViewGroup(mNWrapper)),
        (nlong)(mNWrapper->mNKrossWrapper->mNVisitorWidget = new NVisitorWidget(mNWrapper)),
        (nlong)(mNWrapper->mNKrossWrapper->mNVisitorWidgetLayout = new NVisitorWidgetLayout(mNWrapper)),
        (nlong)(mNWrapper->mNKrossWrapper->mNVisitorWidgetView = new NVisitorWidgetView(mNWrapper))
    };
}

NKrossSystem::~NKrossSystem()
{
    delete mNWrapper->mNKrossWrapper->mActivity;

    delete Typeface::DEFAULT;
    delete Typeface::DEFAULT_BOLD;
    delete Typeface::SANS_SERIF;
    delete Typeface::SERIF;
    delete Typeface::MONOSPACE;

    //TODO
    delete mNWrapper->mNKrossWrapper->mNVisitorApp;
    delete mNWrapper->mNKrossWrapper->mNVisitorAppActivity;
    delete mNWrapper->mNKrossWrapper->mNVisitorAppFragment;
    delete mNWrapper->mNKrossWrapper->mNVisitorBluetooth;
    delete mNWrapper->mNKrossWrapper->mNVisitorContentRes;
    delete mNWrapper->mNKrossWrapper->mNVisitorIO;
    delete mNWrapper->mNKrossWrapper->mNVisitorView;
    delete mNWrapper->mNKrossWrapper->mNVisitorWidget;
    delete[] mNWrapper->mNKrossWrapper->maNVisitor;

    //TODO
    delete mNWrapper->mNKrossWrapper->mNAlpha00;
    delete mNWrapper->mNKrossWrapper->mNBeta00;
    delete mNWrapper->mNKrossWrapper->mNGamma00;
    delete[] mNWrapper->mNKrossWrapper->maNElement;

    delete mNWrapper->mNKrossWrapper->mNKrossFriend;
}

NReturn NKrossSystem::nInit(nint cState)
{
    NReturn ret = 0;

    switch (cState) {
    case GET_VISITOR:
        ret = (NReturn)this;
        break;
    case GET_ELEMENT:
        ret = (NReturn)mNWrapper->mNKrossWrapper->mNAlpha00;
        break;
    }
    return ret;
}

NReturnObject NKrossSystem::tRunString(const String& boxed)
{
    LOGPRINTV("Call to NAPI for a new string from char sequence : %s", boxed.c_str());
    return NKrossSystem_tRunString(mNWrapper, boxed);
}

String NKrossSystem::tGetString(NReturnObject tString)
{
    LOGPRINTV("Call to NAPI to get the string from jstring : %llu", (unsigned long long)tString);
    return NKrossSystem_tGetString(mNWrapper, tString);
}

NReturn NKrossSystem::tDeleteGlobalRef(NParamObject vGlobalRef)
{
    LOGPRINTV("Call to NAPI to delete the global reference : %llu", (unsigned long long)vGlobalRef);
    return NKrossSystem_tDeleteGlobalRef(mNWrapper, vGlobalRef);
}

NReturn NKrossSystem::visit(NAlpha00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    nuint index;

    for (index = 1 ; index < mNWrapper->mNKrossWrapper->mcNElement ; ++index) {
        tRun(mNWrapper->mNKrossWrapper->mNAlpha00, (NParam)mNWrapper->mNKrossWrapper->maNElement[index], index);
    }
    for (index = 1 ; index < mNWrapper->mNKrossWrapper->mcNVisitor; ++index) {
        tRun(mNWrapper->mNKrossWrapper->mNBeta00, (NParam)mNWrapper->mNKrossWrapper->maNVisitor[index], index);
    }
    Build::VERSION::SDK_INT = a;
    Typeface::DEFAULT = Typeface::create("", Typeface::NORMAL);
    Typeface::DEFAULT_BOLD = Typeface::create("", Typeface::BOLD);
    Typeface::SANS_SERIF = Typeface::create("sans-serif", Typeface::NORMAL);
    Typeface::SERIF = Typeface::create("serif", Typeface::NORMAL);
    Typeface::MONOSPACE = Typeface::create("monospace", Typeface::NORMAL);

    mNWrapper->mAssetDir = "nclozer/";
    mNWrapper->mFileDir = tGetString(tRunObject(1)) + "/";
    mNWrapper->mAAssetManager = AAssetManager_fromJava(mNWrapper->mNKrossWrapper->mEnv, tRunObject(2));
    mNWrapper->mNKrossWrapper->mActivity = mNWrapper->mNKrossWrapper->mNKrossFriend->instance<Activity>().getInstance(mNWrapper);

    return (NReturn)mNWrapper->mNKrossWrapper->mActivity;
}

NReturn NKrossSystem::tAttachCurrentThread()
{
    LOGPRINTV("Call to NAPI to attach the current thread");
    return NKrossSystem_tAttachCurrentThread(mNWrapper);
}

NReturn NKrossSystem::tDetachCurrentThread()
{
    LOGPRINTV("Call to NAPI to detach the current thread");
    return NKrossSystem_tDetachCurrentThread(mNWrapper);
}

} // END namespace
