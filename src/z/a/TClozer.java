package z.a;

import java.util.Hashtable;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Map.Entry;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.content.IntentFilter;

public class TClozer extends TFrame
{
    public static final int GET_W = 0;
    public static final int GET_ELEMENT = GET_W + 1;
    public static final int GET_VISITOR = GET_ELEMENT + 1;

    public TClozer(TWrapper w)
    {
    	super(w);

    	// Init plateform
    	w.doDebug = false;
        w.context = w.tActivity.getApplication();
        w.tActivityHandler = new TActivityHandler(w);

    	w.sTVisitor = new Hashtable<String, TVisitor>();
    	w.sTElement = new Hashtable<String, TElement>();
    	w.sObject = new Hashtable<String, Object>();
    	w.cObjectIndex = 0;
    	w.aObject = new Hashtable<Integer,Object>();

    	w.aTElement = new TElement[] {
	        w.mTAlpha00 = new TAlpha00(),
            w.mTBeta00 = new TBeta00(),
            w.mTGamma00 = new TGamma00(),
            w.mTDelta00 = new TDelta00(),
            w.mTEpsilon00= new TEpsilon00(),
            w.mTDzeta00 = new TDzeta00(),
            w.mTEta00 = new TEta00(),
            w.mTTheta00 = new TTheta00(),
            w.mTIota00 = new TIota00(),
            w.mTKappa00 = new TKappa00(),
            w.mTLambda00 = new TLambda00(),
            w.mTMu00 = new TMu00(),
            w.mTNu00 = new TNu00(),
            w.mTXi00 = new TXi00(),
            w.mTOmicron00 = new TOmicron00(),
            w.mTPi00 = new TPi00(),
            w.mTRho00 = new TRho00(),
            w.mTSigma00 = new TSigma00(),
            w.mTTau00 = new TTau00(),
            w.mTUpsilon00 = new TUpsilon00(),
            w.mTPhi00 = new TPhi00(),
            w.mTKhi00 = new TKhi00(),
            w.mTPsi00 = new TPsi00(),
            w.mTOmega00 = new TOmega00(),

            w.mTAlpha01 = new TAlpha01(),
            w.mTBeta01 = new TBeta01(),
            w.mTGamma01 = new TGamma01(),
            w.mTDelta01 = new TDelta01(),
            w.mTEpsilon01= new TEpsilon01(),
            w.mTDzeta01 = new TDzeta01(),
            w.mTEta01 = new TEta01(),
            w.mTTheta01 = new TTheta01(),
            w.mTIota01 = new TIota01(),
            w.mTKappa01 = new TKappa01(),
            w.mTLambda01 = new TLambda01(),
            w.mTMu01 = new TMu01(),
            w.mTNu01 = new TNu01(),
            w.mTXi01 = new TXi01(),
            w.mTOmicron01 = new TOmicron01(),
            w.mTPi01 = new TPi01(),
            w.mTRho01 = new TRho01(),
            w.mTSigma01 = new TSigma01(),
            w.mTTau01 = new TTau01(),
            w.mTUpsilon01 = new TUpsilon01(),
            w.mTPhi01 = new TPhi01(),
            w.mTKhi01 = new TKhi01(),
            w.mTPsi01 = new TPsi01(),
            w.mTOmega01 = new TOmega01(),

            w.mTAlpha02 = new TAlpha02(),
            w.mTBeta02 = new TBeta02(),
            w.mTGamma02 = new TGamma02(),
            w.mTDelta02 = new TDelta02(),
            w.mTEpsilon02= new TEpsilon02(),
            w.mTDzeta02 = new TDzeta02(),
            w.mTEta02 = new TEta02(),
            w.mTTheta02 = new TTheta02(),
            w.mTIota02 = new TIota02(),
            w.mTKappa02 = new TKappa02(),
            w.mTLambda02 = new TLambda02(),
            w.mTMu02 = new TMu02(),
            w.mTNu02 = new TNu02(),
            w.mTXi02 = new TXi02(),
            w.mTOmicron02 = new TOmicron02(),
            w.mTPi02 = new TPi02(),
            w.mTRho02 = new TRho02(),
            w.mTSigma02 = new TSigma02(),
            w.mTTau02 = new TTau02(),
            w.mTUpsilon02 = new TUpsilon02(),
            w.mTPhi02 = new TPhi02(),
            w.mTKhi02 = new TKhi02(),
            w.mTPsi02 = new TPsi02(),
            w.mTOmega02 = new TOmega02(),

            w.mTAlpha03 = new TAlpha03(),
            w.mTBeta03 = new TBeta03(),
            w.mTGamma03 = new TGamma03(),
            w.mTDelta03 = new TDelta03(),
            w.mTEpsilon03= new TEpsilon03(),
            w.mTDzeta03 = new TDzeta03(),
            w.mTEta03 = new TEta03(),
            w.mTTheta03 = new TTheta03(),
            w.mTIota03 = new TIota03(),
            w.mTKappa03 = new TKappa03(),
            w.mTLambda03 = new TLambda03(),
            w.mTMu03 = new TMu03(),
            w.mTNu03 = new TNu03(),
            w.mTXi03 = new TXi03(),
            w.mTOmicron03 = new TOmicron03(),
            w.mTPi03 = new TPi03(),
            w.mTRho03 = new TRho03(),
            w.mTSigma03 = new TSigma03(),
            w.mTTau03 = new TTau03(),
            w.mTUpsilon03 = new TUpsilon03(),
            w.mTPhi03 = new TPhi03(),
            w.mTKhi03 = new TKhi03(),
            w.mTPsi03 = new TPsi03(),
            w.mTOmega03 = new TOmega03(),
    	};
    	w.aTVisitor = new TVisitor[] {
    		this,
            w.mTVisitorApp = new TVisitorApp(w),
            w.mTVisitorAppActivity = new TVisitorAppActivity(w),
            w.mTVisitorAppFragment = new TVisitorAppFragment(w),
			w.mTVisitorBluetooth = new TVisitorBluetooth(w),
	        w.mTVisitorContentRes = new TVisitorContentRes(w),
	        w.mTVisitorIO = new TVisitorIO(w),
            w.mTVisitorGraphics = new TVisitorGraphics(w),
            w.mTVisitorUtil = new TVisitorUtil(w),
            w.mTVisitorView = new TVisitorView(w),
            w.mTVisitorViewView = new TVisitorViewView(w),
            w.mTVisitorViewViewGroup = new TVisitorViewViewGroup(w),
            w.mTVisitorWidget = new TVisitorWidget(w),
            w.mTVisitorWidgetLayout = new TVisitorWidgetLayout(w),
            w.mTVisitorWidgetView = new TVisitorWidgetView(w),
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
    		null,
    		null,
    		null,
    		null,
    		null,
    		null,
    	};
    }

    public void tInit()
    {
    	int i = 0;

    	for ( i = 0 ; i < w.aAction.length && i < w.tActivityReceiver.length ; ++i ) {
    		w.tActivity.registerReceiver(w.tActivityReceiver[i] = new TActivityReceiver(w), new IntentFilter(w.aAction[i]));
    	}
        putNext(w.tActivity.getFilesDir().getAbsolutePath());

    	// Get native wrapper, visitors, elements, and activity
    	w.tFrame.n = nInit(GET_VISITOR);
    	w.sTVisitor.put("" + w.tFrame.n, this);

    	w.mTAlpha00.n = nInit(GET_ELEMENT);
    	w.sTElement.put("" + w.mTAlpha00.n, w.mTAlpha00);

    	w.tActivity.n = nRun(w.mTAlpha00);
    	w.sObject.put("" + w.tActivity.n, w.tActivity);
    }

    public void tDestroy()
    {
    	int i = 0;

    	for ( i = 0 ; i < w.tActivityReceiver.length ; ++i ) {
    		if (w.tActivityReceiver[i] != null) {
    			w.tActivity.unregisterReceiver(w.tActivityReceiver[i]);
    		}
    	}
    }

	public Object tRunObject(long a, long b)
	{
		Object ret = null;

		if (b < 0) {
		    ret = w.aObject.remove((int)a);
		} else {
		    Object o = w.aObject.get((int)a);

		    if (o instanceof LinkedList<?> && b < ((LinkedList<?>)o).size()) {
                ret = ((LinkedList<?>)o).get((int)b);
            }
		}
		return ret;
	}

	public long visit(TAlpha00 element, long a, long b, long c, long d, long e)
	{
		// Register native element
		w.aTElement[(int)b].n = a;
    	w.sTElement.put("" + a, w.aTElement[(int)b]);
		return 0;
	}

	public long visit(TBeta00 element, long a, long b, long c, long d, long e)
	{
		// Register native visitor
		w.aTVisitor[(int)b].n = a;
    	w.sTVisitor.put("" + a, w.aTVisitor[(int)b]);
		return 0;
	}

//	public long visit(TGamma00 element, long a, long b, long c, long d, long e)
//	{
//		// Array
//		long ret = 0;
//		LinkedList<?> aList = ((LinkedList<?>)w.aObject.get((int)a));
//
//		if (b < 0) {
//			ret = aList.size();
//		} else if (c < 0) {
//			//TODO: Double.doubleRawByteValue()
//			ret = ((Number)aList.get((int)b)).longValue();
//		} else {
//			w.sObject.put("" + c, aList.get((int)b));
//		}
//		return ret;
//	}

	public long visit(TDelta00 element, long a, long b, long c, long d, long e)
	{
		w.sObject.remove("" + a);
		return 0;
	}

    public long visit(TAlpha01 element, long a, long b, long c, long d, long e)
    {
        // Array get
        long ret = 0;
        Object o = w.aObject.get((int)a);

        if (o instanceof LinkedList<?>) {
            if (b < 0) {
                ret = ((LinkedList<?>)o).size();
            } else {
                ret = ((Number)((LinkedList<?>)o).get((int)b)).longValue();
            }
        }
        return ret;
    }

    public long visit(TBeta01 element, long a, long b, long c, long d, long e)
    {
        // Array set
        Object o;

        if (a == 0) {
            a = putNext(o = new int[(int)d]);
        } else {
            o = w.aObject.get((int)a);
        }
        if (b >= 0 && o instanceof int[] && b < ((int[])o).length) {
            ((int[])o)[(int)b] = (int)c;
        }
        return a;
    }

    public long putNext(Object value)
    {
        //FIXME: this is not thread safe
        int vcIndex = (w.cObjectIndex = (w.cObjectIndex + 1)%Integer.MAX_VALUE);
        w.aObject.put(vcIndex, value);
        return vcIndex;
    }

    public long getKey(Object value)
    {
        long vcKey = 0;

        if (value != null) {
            vcKey = -1;
            Iterator<Entry<String, Object>> it = w.sObject.entrySet().iterator();

            while (vcKey == 0 && it.hasNext()) {
                Entry<String, Object> entry = it.next();

                if (entry.getValue() == value) {
                    vcKey = Long.parseLong(entry.getKey());
                }
            }
        }
        return vcKey;
    }

    public long putKey(long vcKey, Object value)
    {
        if (value != null) {
            w.sObject.put("" + vcKey, value);
        } else {
            vcKey = 0;
        }
        return vcKey;
    }

    public int getInt(long vcLong, int vcIndex)
    {
        if (vcIndex == 0) {
            vcLong = (vcLong>>32);
        } else {
            vcLong = (vcLong & -1>>32);
        }
        return (int)(vcLong | ( (vcLong & 1<<15) != 0 ? -1<<32 : 0 ));
    }
}

//w.tAndroid = new TAndroid(w);
//w.cAPI00 = w.tAndroid.getAPI00Number();
