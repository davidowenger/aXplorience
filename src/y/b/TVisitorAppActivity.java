package y.b;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;

public class TVisitorAppActivity extends TKrossVisitor
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
        if (w.tActivity.n == 0) {
            w.sObject.put(a, w.tActivity);
        } else {
            w.sObject.put(a, new Activity());
        }
        return 0;
    }

    // void finish()
    public long visit(TEta00 element, long a, long b, long c, long d, long e)
    {
        ((Activity)w.sObject.get(a)).finish();
        return 0;
    }

    // ActionBar* getActionBar()
    public long visit(TBeta00 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.emplaceKey(b, ((Activity)w.sObject.get(a)).getActionBar());
    }

    // Application* getApplication()
    public long visit(TGamma00 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.emplaceKey(b, ((Activity)w.sObject.get(a)).getApplication());
    }

    // FragmentManager* getFragmentManager()
    public long visit(TDelta00 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.emplaceKey(b, ((Activity)w.sObject.get(a)).getFragmentManager());
    }

    // WindowManager* getWindowManager()
    public long visit(TTheta00 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.emplaceKey(b, ((Activity)w.sObject.get(a)).getWindowManager());
    }

    // void setContentView(View* view)
    public long visit(TEpsilon00 element, long a, long b, long c, long d, long e)
    {
        ((Activity)w.sObject.get(a)).setContentView(w.mTKrossSystem.getValue(b, View.class));
        return 0;
    }

    // void sendMessage()
    public long visit(TDzeta00 element, long a, long b, long c, long d, long e)
    {
        //((TActivity)w.sObject.get(a)).mTActivityHandler.obtainMessage(0, -1, -1, b).sendToTarget();
        w.tActivityHandler.obtainMessage(0, -1, -1, b).sendToTarget();
        return 0;
    }

    //******************************************************************************************
    //************************************* Activity events ************************************
    //* This passes the call back to the default implementation if the method is not overriden *
    //******************************************************************************************
    // super.onCreate(Bundle* savedInstanceState)
    public long visit(TAlpha03 element, long a, long b, long c, long d, long e)
    {
        ((TActivity)w.sObject.get(a)).onCreateParent(w.mTKrossSystem.getValue(b, Bundle.class));
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

    // super.onBackPressed()
    public long visit(TMu03 element, long a, long b, long c, long d, long e)
    {
        ((TActivity)w.sObject.get(a)).onBackPressedParent();
        return 0;
    }

    // super.onCreateOptionsMenu()
    public long visit(TIota03 element, long a, long b, long c, long d, long e)
    {
        return ( ((TActivity)w.sObject.get(a)).onCreateOptionsMenuParent(w.mTKrossSystem.getValue(b, Menu.class)) ? 1 : 0 );
    }

    // super.onOptionsItemSelected()
    public long visit(TLambda03 element, long a, long b, long c, long d, long e)
    {
        return ( ((TActivity)w.sObject.get(a)).onOptionsItemSelectedParent(w.mTKrossSystem.getValue(b, MenuItem.class)) ? 1 : 0 );
    }

    // super.onPrepareOptionsMenu()
    public long visit(TKappa03 element, long a, long b, long c, long d, long e)
    {
        return ( ((TActivity)w.sObject.get(a)).onPrepareOptionsMenuParent(w.mTKrossSystem.getValue(b, Menu.class)) ? 1 : 0 );
    }
}
