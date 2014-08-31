package z.a;

import java.util.Hashtable;
import java.util.LinkedList;
import java.util.Vector;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.content.IntentFilter;

public class TClozer extends TFrame
{
    public TClozer(TWrapper w)
    {
    	super(w);

    	// Init plateform
    	w.doDebug = true;
        w.context = w.tActivity.getApplication();
        w.tActivityHandler = new TActivityHandler(w);

    	w.sTVisitor = new Hashtable<String, TVisitor>();
    	w.sTElement = new Hashtable<String, TElement>();
    	w.sObject = new Hashtable<String, Object>();
    	w.aObject = new Vector<Object>();

    	w.aTElement = new TElement[] {
			w.alpha00 = new TAlpha00(),
			w.beta00 = new TBeta00(),
			w.gamma00 = new TGamma00(),
			w.delta00 = new TDelta00(),
			w.epsilon00= new TEpsilon00(),
			w.dzeta00 = new TDzeta00(),
			w.eta00 = new TEta00(),
			w.theta00 = new TTheta00(),
			w.iota00 = new TIota00(),
			w.kappa00 = new TKappa00(),
			w.lambda00 = new TLambda00(),
			w.mu00 = new TMu00(),
			w.nu00 = new TNu00(),
			w.xi00 = new TXi00(),
			w.omicron00 = new TOmicron00(),
			w.pi00 = new TPi00(),
			w.rho00 = new TRho00(),
			w.sigma00 = new TSigma00(),
			w.tau00 = new TTau00(),
			w.upsilon00 = new TUpsilon00(),
			w.phi00 = new TPhi00(),
			w.khi00 = new TKhi00(),
			w.psi00 = new TPsi00(),
			w.omega00 = new TOmega00(),

			w.alpha01 = new TAlpha01(),
			w.beta01 = new TBeta01(),
			w.gamma01 = new TGamma01(),
			w.delta01 = new TDelta01(),
			w.epsilon01= new TEpsilon01(),
			w.dzeta01 = new TDzeta01(),
			w.eta01 = new TEta01(),
			w.theta01 = new TTheta01(),
			w.iota01 = new TIota01(),
			w.kappa01 = new TKappa01(),
			w.lambda01 = new TLambda01(),
			w.mu01 = new TMu01(),
			w.nu01 = new TNu01(),
			w.xi01 = new TXi01(),
			w.omicron01 = new TOmicron01(),
			w.pi01 = new TPi01(),
			w.rho01 = new TRho01(),
			w.sigma01 = new TSigma01(),
			w.tau01 = new TTau01(),
			w.upsilon01 = new TUpsilon01(),
			w.phi01 = new TPhi01(),
			w.khi01 = new TKhi01(),
			w.psi01 = new TPsi01(),
			w.omega01 = new TOmega01(),

			w.alpha02 = new TAlpha02(),
			w.beta02 = new TBeta02(),
			w.gamma02 = new TGamma02(),
			w.delta02 = new TDelta02(),
			w.epsilon02= new TEpsilon02(),
			w.dzeta02 = new TDzeta02(),
			w.eta02 = new TEta02(),
			w.theta02 = new TTheta02(),
			w.iota02 = new TIota02(),
			w.kappa02 = new TKappa02(),
			w.lambda02 = new TLambda02(),
			w.mu02 = new TMu02(),
			w.nu02 = new TNu02(),
			w.xi02 = new TXi02(),
			w.omicron02 = new TOmicron02(),
			w.pi02 = new TPi02(),
			w.rho02 = new TRho02(),
			w.sigma02 = new TSigma02(),
			w.tau02 = new TTau02(),
			w.upsilon02 = new TUpsilon02(),
			w.phi02 = new TPhi02(),
			w.khi02 = new TKhi02(),
			w.psi02 = new TPsi02(),
			w.omega02 = new TOmega02(),

			w.alpha03 = new TAlpha03(),
			w.beta03 = new TBeta03(),
			w.gamma03 = new TGamma03(),
			w.delta03 = new TDelta03(),
			w.epsilon03= new TEpsilon03(),
			w.dzeta03 = new TDzeta03(),
			w.eta03 = new TEta03(),
			w.theta03 = new TTheta03(),
			w.iota03 = new TIota03(),
			w.kappa03 = new TKappa03(),
			w.lambda03 = new TLambda03(),
			w.mu03 = new TMu03(),
			w.nu03 = new TNu03(),
			w.xi03 = new TXi03(),
			w.omicron03 = new TOmicron03(),
			w.pi03 = new TPi03(),
			w.rho03 = new TRho03(),
			w.sigma03 = new TSigma03(),
			w.tau03 = new TTau03(),
			w.upsilon03 = new TUpsilon03(),
			w.phi03 = new TPhi03(),
			w.khi03 = new TKhi03(),
			w.psi03 = new TPsi03(),
			w.omega03 = new TOmega03(),
    	};
    	w.aTVisitor = new TVisitor[] {
    		this,
			w.tVisitorApp = new TVisitorApp(w),
			w.tVisitorBluetooth = new TVisitorBluetooth(w),
			w.tVisitorIO = new TVisitorIO(w),
			w.tVisitorView = new TVisitorView(w),
			w.tVisitorWidget = new TVisitorWidget(w),
    	};
    	w.aAction = new String[] {
			BluetoothAdapter.ACTION_DISCOVERY_FINISHED,
	        BluetoothAdapter.ACTION_DISCOVERY_STARTED,
	        BluetoothDevice.ACTION_FOUND,
	        BluetoothAdapter.ACTION_LOCAL_NAME_CHANGED,
	        BluetoothAdapter.ACTION_SCAN_MODE_CHANGED,
	        BluetoothAdapter.ACTION_STATE_CHANGED,
    	};
    	w.tActivityReceiver = new TActivityReceiver[] {
    		new TActivityReceiver(w),
    		new TActivityReceiver(w),
    		new TActivityReceiver(w),
    		new TActivityReceiver(w),
    		new TActivityReceiver(w),
    		new TActivityReceiver(w),
    	};
    }

    public void tInit()
    {
    	int i = 0;

    	for ( i = 0 ; i < w.aAction.length && i < w.tActivityReceiver.length ; ++i ) {
    		w.tActivity.registerReceiver(w.tActivityReceiver[i], new IntentFilter(w.aAction[i]));
    	}
    	w.aObject.add(w.tActivity.getFilesDir().getAbsolutePath());

    	// Get native wrapper, visitors, elements, and activity
    	w.n = nInit(0, GET_W);
    	w.tFrame.n = nInit(w.n, GET_VISITOR);
    	w.sTVisitor.put("" + w.tFrame.n, this);
    	w.alpha00.n = nInit(w.n, GET_ELEMENT);
    	w.sTElement.put("" + w.alpha00.n, w.alpha00);
    	w.tActivity.n = nRun(w.alpha00);
    	w.sObject.put("" + w.tActivity.n, w.tActivity);
    }

	public Object tRunObject(long a, long b)
	{
		Object o = w.aObject.get((int)a);

		if (b < 0) {
			w.aObject.remove((int)a);
		} else {
			o = ((LinkedList<?>)o).get((int)b);
		}
		return  o;
	}

	public long visit(TAlpha00 element, long a, long b, long c, long d)
	{
		// Register native element
		w.aTElement[(int)b].n = a;
    	w.sTElement.put("" + a, w.aTElement[(int)b]);
		return 0;
	}

	public long visit(TBeta00 element, long a, long b, long c, long d)
	{
		// Register native visitor
		w.aTVisitor[(int)b].n = a;
    	w.sTVisitor.put("" + a, w.aTVisitor[(int)b]);
		return 0;
	}

	public long visit(TGamma00 element, long a, long b, long c, long d)
	{
		// Array
		long ret = 0;
		LinkedList<?> aList = ((LinkedList<?>)w.aObject.get((int)a));

		if (b < 0) {
			ret = aList.size();
		} else if (c < 0) {
			//TODO: Double.doubleRawByteValue()
			ret = ((Number)aList.get((int)b)).longValue();
		} else {
			w.sObject.put("" + c, aList.get((int)b));
		}
		return ret;
	}

	public long visit(TDelta00 element, long a, long b, long c, long d)
	{
		w.sObject.remove("" + a);
		return 0;
	}
}


//w.tAndroid = new TAndroid(w);
//w.cAPI00 = w.tAndroid.getAPI00Number();
