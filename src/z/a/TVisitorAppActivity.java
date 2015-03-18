package z.a;

import android.app.ActionBar;
import android.app.Activity;
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
        w.sObject.put("" + a, new Activity());
        return 0;
    }

    // ActionBar* getActionBar()
    public long visit(TBeta00 element, long a, long b, long c, long d, long e)
    {
        ActionBar vActionBar = ((Activity)w.sObject.get("" + a)).getActionBar();

        if (vActionBar != null) {
            w.sObject.put("" + b, vActionBar);
        }
        return ( vActionBar == null ? 1 : 0 );
    }

    // Resources* getResources()
    public long visit(TGamma00 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put("" + b, ((Activity)w.sObject.get("" + a)).getResources());
        return 0;
    }

    // FragmentManager* getFragmentManager()
    public long visit(TDelta00 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put("" + b, ((Activity)w.sObject.get("" + a)).getFragmentManager());
        return 0;
    }

    // void setContentView(View* view)
    public long visit(TEpsilon00 element, long a, long b, long c, long d, long e)
    {
        ((Activity)w.sObject.get("" + a)).setContentView((View)w.sObject.get("" + b));
        return 0;
    }

    // void sendMessage(long a, long b, long c)
    public long visit(TDzeta00 element, long a, long b, long c, long d, long e)
    {
        w.tActivityHandler.obtainMessage(0, -1, -1, new long[]{b,c,d}).sendToTarget();
        return 0;
    }

    //******************************************************************************************
    //************************************* Activity events ************************************
    //* This passes the call back to the default implementation if the method is not overriden *
    //******************************************************************************************
	// super.onCreate(Bundle* savedInstanceState)
	public long visit(TAlpha03 element, long a, long b, long c, long d, long e)
	{
		((TActivity)w.sObject.get("" + a)).onCreateParent();
		return 0;
	}

	//  super.onDestroy()
	public long visit(TBeta03 element, long a, long b, long c, long d, long e)
	{
		((TActivity)w.sObject.get("" + a)).onDestroyParent();
		return 0;
	}

	// super.onPause()
	public long visit(TGamma03 element, long a, long b, long c, long d, long e)
	{
		((TActivity)w.sObject.get("" + a)).onPauseParent();
		return 0;
	}

	// super.onRestart()
	public long visit(TDelta03 element, long a, long b, long c, long d, long e)
	{
		((TActivity)w.sObject.get("" + a)).onRestartParent();
		return 0;
	}

	// super.onResume()
	public long visit(TEpsilon03 element, long a, long b, long c, long d, long e)
	{
		((TActivity)w.sObject.get("" + a)).onResumeParent();
		return 0;
	}

	// super.onStart()
	public long visit(TDzeta03 element, long a, long b, long c, long d, long e)
	{
		((TActivity)w.sObject.get("" + a)).onStartParent();
		return 0;
	}

	// super.onStop()
	public long visit(TEta03 element, long a, long b, long c, long d, long e)
	{
		((TActivity)w.sObject.get("" + a)).onStopParent();
		return 0;
	}
}
