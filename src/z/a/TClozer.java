package z.a;

import java.util.Hashtable;

public class TClozer extends TFrame
{
    public TClozer(TWrapper w) {
    	super(w);
    }

    public void tInit()
    {
    	// Init Android plateform
    	w.tAndroid = new TAndroid(w);

    	w.cAPI = w.tAndroid.getAPINumber();

    	w.vTVisitor = new Hashtable<String, TVisitor>();
    	w.vTElement = new Hashtable<String, TElement>();
    	w.vObject = new Hashtable<String, Object>();

    	w.aTElement = new TElement[]{
			w.alpha = new TAlpha(),
			w.beta = new TBeta(),
			w.gamma = new TGamma(),
			w.delta = new TDelta(),
			w.epsilon= new TEpsilon(),
			w.dzeta = new TDzeta(),
			w.eta = new TEta(),
			w.theta = new TTheta(),
			w.iota = new TIota(),
			w.kappa = new TKappa(),
			w.lambda = new TLambda(),
			w.mu = new TMu(),
			w.nu = new TNu(),
			w.xi = new TXi(),
			w.omicron = new TOmicron(),
			w.pi = new TPi(),
			w.rho = new TRho(),
			w.sigma = new TSigma(),
			w.tau = new TTau(),
			w.upsilon = new TUpsilon(),
			w.phi = new TPhi(),
			w.khi = new TKhi(),
			w.psi = new TPsi(),
			w.omega = new TOmega()
    	};
    	w.aTVisitor = new TVisitor[]{
    		this,
			w.tVisitorApp = new TVisitorApp(w),
			w.tVisitorView = new TVisitorView(w),
			w.tVisitorWidget = new TVisitorWidget(w)
    	};

    	w.nWrapper = nInit(0, GET_W);
      //w.vObject.put("" + w.nWrapper, w);

    	w.tFrame.n = nInit(w.nWrapper, GET_VISITOR);
    	w.vTVisitor.put("" + w.tFrame.n, this);

    	w.alpha.n = nInit(w.nWrapper, GET_ELEMENT);
    	w.vTElement.put("" + w.alpha.n, w.alpha);

    	// Get all native elements plus native application
    	w.tApp.n = nRun(w.alpha);
    	w.vObject.put("" + w.tApp.n, w.tApp);
    }

	public long visit(TAlpha element, long a, long b, long c)
	{
		// Register native element
		w.aTElement[(int)b].n = a;
    	w.vTElement.put("" + a, w.aTElement[(int)b]);
		return 0;
	}

	public long visit(TBeta element, long a, long b, long c)
	{
		// Register native visitor
		w.aTVisitor[(int)b].n = a;
    	w.vTVisitor.put("" + a, w.aTVisitor[(int)b]);
		return 0;
	}

	public long visit(TDelta element, long a, long b, long c)
	{
		w.vObject.remove("" + a);
		return 0;
	}
}
