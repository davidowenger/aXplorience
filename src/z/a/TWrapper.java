package z.a;

import java.util.Hashtable;
import java.util.UUID;

import android.app.Activity;
import android.content.Context;

public class TWrapper
{
	int cAPI;
	Context context;
	Activity activity;

	String serviceName;
	UUID uuid;

	TFrame tFrame;
	TCore tCore;
	THandler tHandler;
	TConfig tConfig;
	TBluetooth tBluetooth;

	BtServer btServer;
	BtConnect btConnect;
	BtConnected btConnected;

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
	TVisitor tVisitorApp;
	TVisitor tVisitorView;
	TVisitor tVisitorWidget;

	Hashtable<String,TElement> vTElement;
	Hashtable<String,TVisitor> vTVisitor;
	Hashtable<String,Object> vObject;

	long nWrapper;
}
