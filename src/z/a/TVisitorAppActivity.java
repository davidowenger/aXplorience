package z.a;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;

public class TVisitorAppActivity extends TVisitor
{
	public TVisitorAppActivity(TWrapper w) {
		super(w);
	}

    //*******************************************************************************
    //**************************** Activity *****************************************
    //*******************************************************************************

    // Activity()
    public long visit(TAlpha00 element, long a, long b, long c, long d, long e)
    {
        if (a != w.tActivity.n) w.sObject.put(a, new Activity());
        return 0;
    }

    // ActionBar* getActionBar()
    public long visit(TBeta00 element, long a, long b, long c, long d, long e)
    {
        return w.tFrame.emplaceKey(b, ((Activity)w.sObject.get(a)).getActionBar());
    }

    // Application* getApplication()
    public long visit(TGamma00 element, long a, long b, long c, long d, long e)
    {
        return w.tFrame.emplaceKey(b, ((Activity)w.sObject.get(a)).getApplication());
    }

    // FragmentManager* getFragmentManager()
    public long visit(TDelta00 element, long a, long b, long c, long d, long e)
    {
        return w.tFrame.emplaceKey(b, ((Activity)w.sObject.get(a)).getFragmentManager());
    }

    // void setContentView(View* view)
    public long visit(TEpsilon00 element, long a, long b, long c, long d, long e)
    {
        ((Activity)w.sObject.get(a)).setContentView(w.tFrame.getValue(b, View.class));
        return 0;
    }

    // void sendMessage(long a, long b, long c)
    public long visit(TDzeta00 element, long a, long b, long c, long d, long e)
    {
        w.tActivityHandler.obtainMessage(0, -1, -1, new long[]{b,c,d,e}).sendToTarget();
        return 0;
    }

    //******************************************************************************************
    //************************************* Activity events ************************************
    //* This passes the call back to the default implementation if the method is not overriden *
    //******************************************************************************************
	// super.onCreate(Bundle* savedInstanceState)
	public long visit(TAlpha03 element, long a, long b, long c, long d, long e)
	{
		((TActivity)w.sObject.get(a)).onCreateParent(w.tFrame.getValue(b, Bundle.class));
		return 0;
	}

    // super.onRestart()
    public long visit(TBeta03 element, long a, long b, long c, long d, long e)
    {
        ((TActivity)w.sObject.get(a)).onRestartParent();
        return 0;
    }

    // super.onStart()
    public long visit(TGamma03 element, long a, long b, long c, long d, long e)
    {
        ((TActivity)w.sObject.get(a)).onStartParent();
        return 0;
    }

    // super.onResume()
    public long visit(TDelta03 element, long a, long b, long c, long d, long e)
    {
        ((TActivity)w.sObject.get(a)).onResumeParent();
        return 0;
    }

	// super.onPause()
	public long visit(TEpsilon03 element, long a, long b, long c, long d, long e)
	{
		((TActivity)w.sObject.get(a)).onPauseParent();
		return 0;
	}

	// super.onStop()
	public long visit(TDzeta03 element, long a, long b, long c, long d, long e)
	{
		((TActivity)w.sObject.get(a)).onStopParent();
		return 0;
	}

    //  super.onDestroy()
    public long visit(TEta03 element, long a, long b, long c, long d, long e)
    {
        ((TActivity)w.sObject.get(a)).onDestroyParent();
        return 0;
    }
}
