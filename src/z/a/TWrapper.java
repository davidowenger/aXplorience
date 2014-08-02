package z.a;

import java.util.Hashtable;

import android.content.Context;

public class TWrapper
{
	TAndroid tAndroid;
	int cAPI;

	TElement[] aTElement;
	TAlpha   alpha;
	TBeta    beta;
	TGamma   gamma;
	TDelta   delta;
	TEpsilon epsilon;
	TDzeta   dzeta;
	TEta     eta;
	TTheta   theta;
	TIota    iota;
	TKappa   kappa;
	TLambda  lambda;
	TMu      mu;
	TNu      nu;
	TXi      xi;
	TOmicron omicron;
	TPi      pi;
	TRho     rho;
	TSigma   sigma;
	TTau     tau;
	TUpsilon upsilon;
	TPhi     phi;
	TKhi     khi;
	TPsi     psi;
	TOmega   omega;

	TVisitor[] aTVisitor;
	TFrame tFrame;
	TVisitor tVisitorApp;
	TVisitor tVisitorView;
	TVisitor tVisitorWidget;

	Hashtable<String,TElement> vTElement;
	Hashtable<String,TVisitor> vTVisitor;
	Hashtable<String,Object> vObject;

	TApp tApp;
	Context context;

	long nWrapper;
}
