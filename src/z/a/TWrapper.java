package z.a;

import java.util.Hashtable;
import java.util.Vector;

import android.content.Context;
import android.os.Bundle;

public class TWrapper
{
	long n;

	TElement[] aTElement;

	TAlpha00   alpha00;
	TBeta00    beta00;
	TGamma00   gamma00;
	TDelta00   delta00;
	TEpsilon00 epsilon00;
	TDzeta00   dzeta00;
	TEta00     eta00;
	TTheta00   theta00;
	TIota00    iota00;
	TKappa00   kappa00;
	TLambda00  lambda00;
	TMu00      mu00;
	TNu00      nu00;
	TXi00      xi00;
	TOmicron00 omicron00;
	TPi00      pi00;
	TRho00     rho00;
	TSigma00   sigma00;
	TTau00     tau00;
	TUpsilon00 upsilon00;
	TPhi00     phi00;
	TKhi00     khi00;
	TPsi00     psi00;
	TOmega00   omega00;

	TAlpha01   alpha01;
	TBeta01    beta01;
	TGamma01   gamma01;
	TDelta01   delta01;
	TEpsilon01 epsilon01;
	TDzeta01   dzeta01;
	TEta01     eta01;
	TTheta01   theta01;
	TIota01    iota01;
	TKappa01   kappa01;
	TLambda01  lambda01;
	TMu01      mu01;
	TNu01      nu01;
	TXi01      xi01;
	TOmicron01 omicron01;
	TPi01      pi01;
	TRho01     rho01;
	TSigma01   sigma01;
	TTau01     tau01;
	TUpsilon01 upsilon01;
	TPhi01     phi01;
	TKhi01     khi01;
	TPsi01     psi01;
	TOmega01   omega01;

	TAlpha02   alpha02;
	TBeta02    beta02;
	TGamma02   gamma02;
	TDelta02   delta02;
	TEpsilon02 epsilon02;
	TDzeta02   dzeta02;
	TEta02     eta02;
	TTheta02   theta02;
	TIota02    iota02;
	TKappa02   kappa02;
	TLambda02  lambda02;
	TMu02      mu02;
	TNu02      nu02;
	TXi02      xi02;
	TOmicron02 omicron02;
	TPi02      pi02;
	TRho02     rho02;
	TSigma02   sigma02;
	TTau02     tau02;
	TUpsilon02 upsilon02;
	TPhi02     phi02;
	TKhi02     khi02;
	TPsi02     psi02;
	TOmega02   omega02;

	TAlpha03   alpha03;
	TBeta03    beta03;
	TGamma03   gamma03;
	TDelta03   delta03;
	TEpsilon03 epsilon03;
	TDzeta03   dzeta03;
	TEta03     eta03;
	TTheta03   theta03;
	TIota03    iota03;
	TKappa03   kappa03;
	TLambda03  lambda03;
	TMu03      mu03;
	TNu03      nu03;
	TXi03      xi03;
	TOmicron03 omicron03;
	TPi03      pi03;
	TRho03     rho03;
	TSigma03   sigma03;
	TTau03     tau03;
	TUpsilon03 upsilon03;
	TPhi03     phi03;
	TKhi03     khi03;
	TPsi03     psi03;
	TOmega03   omega03;

	TVisitor[] aTVisitor;
	TFrame tFrame;
	TVisitor tVisitorApp;
	TVisitor tVisitorBluetooth;
	TVisitor tVisitorIO;
	TVisitor tVisitorView;
	TVisitor tVisitorWidget;

	Hashtable<String,TElement> sTElement;
	Hashtable<String,TVisitor> sTVisitor;
	Hashtable<String,Object> sObject;
	Vector<Object> aObject;

	Bundle bundle;
	Context context;
	TActivity tActivity;
	TActivityHandler tActivityHandler;
	String[] aAction;
	TActivityReceiver[] tActivityReceiver;

	int cAPI00;
	boolean doDebug;
	TAndroid tAndroid;
}
