package y.b;

import java.util.Hashtable;

import android.content.Context;

public class TWrapper
{
    public static final boolean kDoDebug = false;
    static {
        System.loadLibrary("gnustl_shared");
        System.loadLibrary("TActivity");

        // Debug
        if (TWrapper.kDoDebug) {
            try {
                Thread.sleep(5000);
            } catch (Exception vException) {
                vException.printStackTrace();
            }
        }
    }
    static TWrapper w;

    long n;

    TElement[] aTElement;

    TAlpha00   mTAlpha00;
    TBeta00    mTBeta00;
    TGamma00   mTGamma00;
    TDelta00   mTDelta00;
    TEpsilon00 mTEpsilon00;
    TDzeta00   mTDzeta00;
    TEta00     mTEta00;
    TTheta00   mTTheta00;
    TIota00    mTIota00;
    TKappa00   mTKappa00;
    TLambda00  mTLambda00;
    TMu00      mTMu00;
    TNu00      mTNu00;
    TXi00      mTXi00;
    TOmicron00 mTOmicron00;
    TPi00      mTPi00;
    TRho00     mTRho00;
    TSigma00   mTSigma00;
    TTau00     mTTau00;
    TUpsilon00 mTUpsilon00;
    TPhi00     mTPhi00;
    TKhi00     mTKhi00;
    TPsi00     mTPsi00;
    TOmega00   mTOmega00;

    TAlpha01   mTAlpha01;
    TBeta01    mTBeta01;
    TGamma01   mTGamma01;
    TDelta01   mTDelta01;
    TEpsilon01 mTEpsilon01;
    TDzeta01   mTDzeta01;
    TEta01     mTEta01;
    TTheta01   mTTheta01;
    TIota01    mTIota01;
    TKappa01   mTKappa01;
    TLambda01  mTLambda01;
    TMu01      mTMu01;
    TNu01      mTNu01;
    TXi01      mTXi01;
    TOmicron01 mTOmicron01;
    TPi01      mTPi01;
    TRho01     mTRho01;
    TSigma01   mTSigma01;
    TTau01     mTTau01;
    TUpsilon01 mTUpsilon01;
    TPhi01     mTPhi01;
    TKhi01     mTKhi01;
    TPsi01     mTPsi01;
    TOmega01   mTOmega01;

    TAlpha02   mTAlpha02;
    TBeta02    mTBeta02;
    TGamma02   mTGamma02;
    TDelta02   mTDelta02;
    TEpsilon02 mTEpsilon02;
    TDzeta02   mTDzeta02;
    TEta02     mTEta02;
    TTheta02   mTTheta02;
    TIota02    mTIota02;
    TKappa02   mTKappa02;
    TLambda02  mTLambda02;
    TMu02      mTMu02;
    TNu02      mTNu02;
    TXi02      mTXi02;
    TOmicron02 mTOmicron02;
    TPi02      mTPi02;
    TRho02     mTRho02;
    TSigma02   mTSigma02;
    TTau02     mTTau02;
    TUpsilon02 mTUpsilon02;
    TPhi02     mTPhi02;
    TKhi02     mTKhi02;
    TPsi02     mTPsi02;
    TOmega02   mTOmega02;

    TAlpha03   mTAlpha03;
    TBeta03    mTBeta03;
    TGamma03   mTGamma03;
    TDelta03   mTDelta03;
    TEpsilon03 mTEpsilon03;
    TDzeta03   mTDzeta03;
    TEta03     mTEta03;
    TTheta03   mTTheta03;
    TIota03    mTIota03;
    TKappa03   mTKappa03;
    TLambda03  mTLambda03;
    TMu03      mTMu03;
    TNu03      mTNu03;
    TXi03      mTXi03;
    TOmicron03 mTOmicron03;
    TPi03      mTPi03;
    TRho03     mTRho03;
    TSigma03   mTSigma03;
    TTau03     mTTau03;
    TUpsilon03 mTUpsilon03;
    TPhi03     mTPhi03;
    TKhi03     mTKhi03;
    TPsi03     mTPsi03;
    TOmega03   mTOmega03;

    TVisitor[] aTVisitor;
    TClozer tFrame;
    TVisitor mTVisitorApp;
    TVisitor mTVisitorAppActivity;
    TVisitor mTVisitorAppFragment;
    TVisitor mTVisitorBluetooth;
    TVisitor mTVisitorContent;
    TVisitor mTVisitorContentRes;
    TVisitor mTVisitorGraphics;
    TVisitor mTVisitorIO;
    TVisitor mTVisitorOS;
    TVisitor mTVisitorUtil;
    TVisitor mTVisitorView;
    TVisitor mTVisitorViewView;
    TVisitor mTVisitorViewViewGroup;
    TVisitor mTVisitorWidget;
    TVisitor mTVisitorWidgetLayout;
    TVisitor mTVisitorWidgetView;

    Hashtable<Long,TElement> sTElement;
    Hashtable<Long,TVisitor> sTVisitor;
    Hashtable<Long,Object> sObject;
    Hashtable<Integer,Object> aObject;
    int cObjectIndex;

    Context context;
    TActivity tActivity;
    TActivityHandler tActivityHandler;
    String[] aAction;
    TActivityReceiver[] tActivityReceiver;

    int cAPI00;
    boolean doDebug;
    boolean isStrict;
    TAndroid tAndroid;
}
