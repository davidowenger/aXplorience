package z.a;

import android.app.Activity;
import android.app.Fragment;
import android.app.FragmentManager;
import android.app.FragmentTransaction;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;

public class TVisitorAppFragment extends TVisitor
{
	public TVisitorAppFragment(TWrapper w) {
		super(w);
	}

    //*******************************************************************************************//
    //******************************************* Fragment **************************************//
    //*******************************************************************************************//
    // Fragment()
    public long visit(TAlpha00 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put("" + a, new TFragment(w, a));
        return 0;
    }

    //void setHasOptionsMenu()
    public long visit(TBeta00 element, long a, long b, long c, long d, long e)
    {
        ((TFragment)w.sObject.get("" + a)).setHasOptionsMenu(b != 0);
        return 0;
    }

    //******************************************************************************************//
    //************************************* Fragment events ************************************//
    //* This passes the call back to the default implementation if the method is not overriden *//
    //******************************************************************************************//
    //void onAttach(Activity* vActivity)
    public long visit(TAlpha01 element, long a, long b, long c, long d, long e)
    {
        ((TFragment)w.sObject.get("" + a)).onAttachParent((Activity)w.sObject.get("" + b));
        return 0;
    }

    //void onCreate(Bundle* vBundle)
    public long visit(TBeta01 element, long a, long b, long c, long d, long e)
    {
        ((TFragment)w.sObject.get("" + a)).onCreateParent((Bundle)w.sObject.get("" + b));
        return 0;
    }

    //View onCreateView(LayoutInflater vLayoutInflater, ViewGroup vViewGroup, Bundle vBundle)
    public long visit(TGamma01 element, long a, long b, long c, long d, long e)
    {
        //HINT: Default implementation returns null
        // This is never called
        ((TFragment)w.sObject.get("" + a)).onCreateParent((Bundle)w.sObject.get("" + b));
        return 0;
    }

    //void onActivityCreated(Bundle* vBundle)
    public long visit(TDelta01 element, long a, long b, long c, long d, long e)
    {
        ((TFragment)w.sObject.get("" + a)).onActivityCreatedParent((Bundle)w.sObject.get("" + b));
        return 0;
    }

    //void onViewStateRestored(Bundle* vBundle)
    public long visit(TEpsilon01 element, long a, long b, long c, long d, long e)
    {
        ((TFragment)w.sObject.get("" + a)).onViewStateRestoredParent((Bundle)w.sObject.get("" + b));
        return 0;
    }

    //void onStart()
    public long visit(TDzeta01 element, long a, long b, long c, long d, long e)
    {
        ((TFragment)w.sObject.get("" + a)).onStartParent();
        return 0;
    }

    //void onResume()
    public long visit(TEta01 element, long a, long b, long c, long d, long e)
    {
        ((TFragment)w.sObject.get("" + a)).onResumeParent();
        return 0;
    }

    //void onPause()
    public long visit(TTheta01 element, long a, long b, long c, long d, long e)
    {
        ((TFragment)w.sObject.get("" + a)).onPauseParent();
        return 0;
    }

    //void onSaveInstanceState(Bundle vBundle)
    public long visit(TIota01 element, long a, long b, long c, long d, long e)
    {
        ((TFragment)w.sObject.get("" + a)).onSaveInstanceStateParent((Bundle)w.sObject.get("" + b));
        return 0;
    }

    //void onStop()
    public long visit(TKappa01 element, long a, long b, long c, long d, long e)
    {
        ((TFragment)w.sObject.get("" + a)).onStopParent();
        return 0;
    }

    //void onDestroyView()
    public long visit(TLambda01 element, long a, long b, long c, long d, long e)
    {
        ((TFragment)w.sObject.get("" + a)).onDestroyViewParent();
        return 0;
    }

    //void onDestroy()
    public long visit(TMu01 element, long a, long b, long c, long d, long e)
    {
        ((TFragment)w.sObject.get("" + a)).onDestroyParent();
        return 0;
    }

    //void onDetach()
    public long visit(TNu01 element, long a, long b, long c, long d, long e)
    {
        ((TFragment)w.sObject.get("" + a)).onDetachParent();
        return 0;
    }

    //void onCreateOptionsMenu(Menu vMenu, MenuInflater vMenuInflater)
    public long visit(TXi01 element, long a, long b, long c, long d, long e)
    {
        ((TFragment)w.sObject.get("" + a)).onCreateOptionsMenuParent((Menu)w.sObject.get("" + b), (MenuInflater)w.sObject.get("" + c));
        return 0;
    }

    //void onPrepareOptionsMenu(Menu vMenu)
    public long visit(TOmicron01 element, long a, long b, long c, long d, long e)
    {
        ((TFragment)w.sObject.get("" + a)).onPrepareOptionsMenuParent((Menu)w.sObject.get("" + b));
        return 0;
    }

    //bool onOptionsItemSelected(MenuItem* item)
    public long visit(TPi01 element, long a, long b, long c, long d, long e)
    {
        //HINT: Default implementation returns false
        return ( ((TFragment)w.sObject.get("" + a)).onOptionsItemSelectedParent((MenuItem)w.sObject.get("" + b)) ? 1 : 0 );
    }

    //*******************************************************************************
    //**************************** FragmentManager **********************************
    //*******************************************************************************
    //void popBackStack(const String& name, int flags)
    public long visit(TAlpha02 element, long a, long b, long c, long d, long e)
    {
        ((FragmentManager)w.sObject.get("" + a)).popBackStack();
        return 0;
    }

    //void popBackStack(const String& name, int flags)
    public long visit(TBeta02 element, long a, long b, long c, long d, long e)
    {
        ((FragmentManager)w.sObject.get("" + a)).popBackStack((String)w.tFrame.nRunObject(b), (int)c);
        return 0;
    }

    //FragmentTransaction* beginTransaction()
    public long visit(TGamma02 element, long a, long b, long c, long d, long e)
    {
        FragmentTransaction ret;
        try {
            ret = ((FragmentManager)w.sObject.get("" + a)).beginTransaction();
            w.sObject.put("" + b, ret);
        }
        catch (Exception vException) {
            if (w.doDebug) vException.printStackTrace();
            ret = null;
        }
        return ( ret == null ? 1 : 0 );
    }

    //*******************************************************************************
    //**************************** FragmentTransaction ******************************
    //*******************************************************************************
    //FragmentTransaction* add(int containerViewId, Fragment* fragment)
    public long visit(TAlpha03 element, long a, long b, long c, long d, long e)
    {
        ((FragmentTransaction)w.sObject.get("" + a)).add((int)b, (Fragment)w.sObject.get("" + c));
        return 0;
    }

    //FragmentTransaction* addToBackStack(const String& name)
    public long visit(TBeta03 element, long a, long b, long c, long d, long e)
    {
        ((FragmentTransaction)w.sObject.get("" + a)).addToBackStack((String)w.tFrame.nRunObject(b));
        return 0;
    }

    //FragmentTransaction* replace(int containerViewId, Fragment* fragment)
    public long visit(TGamma03 element, long a, long b, long c, long d, long e)
    {
        ((FragmentTransaction)w.sObject.get("" + a)).add((int)b, (Fragment)w.sObject.get("" + c));
        return 0;
    }

    //int commit()
    public long visit(TDelta03 element, long a, long b, long c, long d, long e)
    {
        return ((FragmentTransaction)w.sObject.get("" + a)).commit();
    }
}
