package z.a;

import android.app.Activity;
import android.view.View;

public class TVisitorApp extends TVisitor
{
	public TVisitorApp(TWrapper w) {
		super(w);
	}

	//*******************************************************************************
	//**************************** Activity *****************************************
	//*******************************************************************************

	//super.onCreate(Bundle* savedInstanceState)
	public long visit(TAlpha00 element, long a, long b, long c, long d)
	{
		((TActivity)w.sObject.get("" + a)).callOnCreate();
		return 0;
	}

	//super.onDestroy()
	public long visit(TBeta00 element, long a, long b, long c, long d)
	{
		((TActivity)w.sObject.get("" + a)).callOnDestroy();
		return 0;
	}

	//super.onDestroy()
	public long visit(TGamma00 element, long a, long b, long c, long d)
	{
		((TActivity)w.sObject.get("" + a)).callOnPause();
		return 0;
	}

	//super.onDestroy()
	public long visit(TDelta00 element, long a, long b, long c, long d)
	{
		((TActivity)w.sObject.get("" + a)).callOnRestart();
		return 0;
	}

	//super.onDestroy()
	public long visit(TEpsilon00 element, long a, long b, long c, long d)
	{
		((TActivity)w.sObject.get("" + a)).callOnResume();
		return 0;
	}

	//super.onDestroy()
	public long visit(TDzeta00 element, long a, long b, long c, long d)
	{
		((TActivity)w.sObject.get("" + a)).callOnStart();
		return 0;
	}

	//super.onDestroy()
	public long visit(TEta00 element, long a, long b, long c, long d)
	{
		((TActivity)w.sObject.get("" + a)).callOnStop();
		return 0;
	}

	public long visit(TTheta00 element, long a, long b, long c, long d)
	{
		((Activity)w.sObject.get("" + a)).setContentView((View)w.sObject.get("" + b));
		return 0;
	}

	public long visit(TIota00 element, long a, long b, long c, long d)
	{
		w.tActivityHandler.obtainMessage(0, -1, -1, new long[]{b,c,d}).sendToTarget();
		return 0;
	}
}
