package y.b;

import android.app.Activity;
import android.app.Fragment;
import android.app.FragmentManager;
import android.app.FragmentTransaction;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.ViewGroup;

public class TVisitorAppFragment extends TKrossVisitor
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
        w.sObject.put(a, new TFragment(w, a));
        return 0;
    }

    //void setHasOptionsMenu()
    public long visit(TBeta00 element, long a, long b, long c, long d, long e)
    {
        ((TFragment)w.sObject.get(a)).setHasOptionsMenu(b != 0);
        return 0;
    }

    //******************************************************************************************//
    //************************************* Fragment events ************************************//
    //* This passes the call back to the default implementation if the method is not overriden *//
    //******************************************************************************************//
    //void onAttach(Activity* vActivity)
    public long visit(TAlpha01 element, long a, long b, long c, long d, long e)
    {
        ((TFragment)w.sObject.get(a)).onAttachParent(w.mTKrossSystem.getValue(b, Activity.class));
        return 0;
    }

    //void onCreate(Bundle* vBundle)
    public long visit(TBeta01 element, long a, long b, long c, long d, long e)
    {
        ((TFragment)w.sObject.get(a)).onCreateParent(w.mTKrossSystem.getValue(b, Bundle.class));
        return 0;
    }

    //View onCreateView(LayoutInflater vLayoutInflater, ViewGroup vViewGroup, Bundle vBundle)
    public long visit(TGamma01 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.emplaceKey(b, ((TFragment)w.sObject.get(a)).onCreateViewParent(w.mTKrossSystem.getValue(c, LayoutInflater.class), w.mTKrossSystem.getValue(d, ViewGroup.class), w.mTKrossSystem.getValue(e, Bundle.class)));
    }

    //void onActivityCreated(Bundle* vBundle)
    public long visit(TDelta01 element, long a, long b, long c, long d, long e)
    {
        ((TFragment)w.sObject.get(a)).onActivityCreatedParent(w.mTKrossSystem.getValue(b, Bundle.class));
        return 0;
    }

    //void onStart()
    public long visit(TDzeta01 element, long a, long b, long c, long d, long e)
    {
        ((TFragment)w.sObject.get(a)).onStartParent();
        return 0;
    }

    //void onResume()
    public long visit(TEta01 element, long a, long b, long c, long d, long e)
    {
        ((TFragment)w.sObject.get(a)).onResumeParent();
        return 0;
    }

    //void onPause()
    public long visit(TTheta01 element, long a, long b, long c, long d, long e)
    {
        ((TFragment)w.sObject.get(a)).onPauseParent();
        return 0;
    }

    //void onSaveInstanceState(Bundle vBundle)
    public long visit(TIota01 element, long a, long b, long c, long d, long e)
    {
        ((TFragment)w.sObject.get(a)).onSaveInstanceStateParent(w.mTKrossSystem.getValue(b, Bundle.class));
        return 0;
    }

    //void onStop()
    public long visit(TKappa01 element, long a, long b, long c, long d, long e)
    {
        ((TFragment)w.sObject.get(a)).onStopParent();
        return 0;
    }

    //void onDestroyView()
    public long visit(TLambda01 element, long a, long b, long c, long d, long e)
    {
        ((TFragment)w.sObject.get(a)).onDestroyViewParent();
        return 0;
    }

    //void onDestroy()
    public long visit(TMu01 element, long a, long b, long c, long d, long e)
    {
        ((TFragment)w.sObject.get(a)).onDestroyParent();
        return 0;
    }

    //void onDetach()
    public long visit(TNu01 element, long a, long b, long c, long d, long e)
    {
        ((TFragment)w.sObject.get(a)).onDetachParent();
        return 0;
    }

    //void onCreateOptionsMenu(Menu vMenu, MenuInflater vMenuInflater)
    public long visit(TXi01 element, long a, long b, long c, long d, long e)
    {
        ((TFragment)w.sObject.get(a)).onCreateOptionsMenuParent(w.mTKrossSystem.getValue(b, Menu.class), w.mTKrossSystem.getValue(c, MenuInflater.class));
        return 0;
    }

    //void onPrepareOptionsMenu(Menu vMenu)
    public long visit(TOmicron01 element, long a, long b, long c, long d, long e)
    {
        ((TFragment)w.sObject.get(a)).onPrepareOptionsMenuParent(w.mTKrossSystem.getValue(b, Menu.class));
        return 0;
    }

    //bool onOptionsItemSelected(MenuItem* item)
    public long visit(TPi01 element, long a, long b, long c, long d, long e)
    {
        //HINT: Default implementation returns false
        return ( ((TFragment)w.sObject.get(a)).onOptionsItemSelectedParent(w.mTKrossSystem.getValue(b, MenuItem.class)) ? 1 : 0 );
    }

    //*******************************************************************************
    //**************************** FragmentManager **********************************
    //*******************************************************************************
    // FragmentTransaction* beginTransaction()
    public long visit(TAlpha02 element, long a, long b, long c, long d, long e)
    {
        FragmentTransaction ret = null;
        try {
            ret = ((FragmentManager)w.sObject.get(a)).beginTransaction();
        }
        catch (Exception vException) {
            if (w.doDebug) vException.printStackTrace();
            ret = null;
        }
        return w.mTKrossSystem.emplaceKey(b, ret);
    }

    // int getBackStackEntryCount()
    public long visit(TBeta02 element, long a, long b, long c, long d, long e)
    {
        return ((FragmentManager)w.sObject.get(a)).getBackStackEntryCount();
    }

    // void popBackStack()
    public long visit(TGamma02 element, long a, long b, long c, long d, long e)
    {
        ((FragmentManager)w.sObject.get(a)).popBackStack();
        return 0;
    }

    // void popBackStack(const String& name, int flags)
    public long visit(TDelta02 element, long a, long b, long c, long d, long e)
    {
        ((FragmentManager)w.sObject.get(a)).popBackStack((String)w.mTKrossSystem.nRunObject(b), (int)c);
        return 0;
    }

    //*******************************************************************************
    //**************************** FragmentTransaction ******************************
    //*******************************************************************************
    //FragmentTransaction* add(int containerViewId, Fragment* fragment)
    public long visit(TAlpha03 element, long a, long b, long c, long d, long e)
    {
        ((FragmentTransaction)w.sObject.get(a)).add((int)b, w.mTKrossSystem.getValue(c, Fragment.class));
        return 0;
    }

    //FragmentTransaction* addToBackStack(const String& name)
    public long visit(TBeta03 element, long a, long b, long c, long d, long e)
    {
        ((FragmentTransaction)w.sObject.get(a)).addToBackStack(w.mTKrossSystem.getStringNullable(b));
        return 0;
    }

    //FragmentTransaction* remove(Fragment* fragment)
    public long visit(TGamma03 element, long a, long b, long c, long d, long e)
    {
        ((FragmentTransaction)w.sObject.get(a)).remove(w.mTKrossSystem.getValue(b, Fragment.class));
        return 0;
    }

    //FragmentTransaction* replace(int containerViewId, Fragment* fragment)
    public long visit(TDelta03 element, long a, long b, long c, long d, long e)
    {
        ((FragmentTransaction)w.sObject.get(a)).replace((int)b, w.mTKrossSystem.getValue(c, Fragment.class));
        return 0;
    }

    //int commit()
    public long visit(TEpsilon03 element, long a, long b, long c, long d, long e)
    {
        long ret = -1;
        try {
            ret = ((FragmentTransaction)w.sObject.get(a)).commit();
        }
        catch (Exception vException) {
            if (w.doDebug) vException.printStackTrace();
            ret = -1;
        }
        return ret;
    }
}
