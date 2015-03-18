package z.a;

import android.app.Activity;
import android.app.Fragment;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;

public class TFragment extends Fragment
{
    public TWrapper w;
    public long n;

    //*******************************************************************************************
    //******************************************* Fragment **************************************
    //*******************************************************************************************

    public TFragment(TWrapper w, long n)
    {
        this.w = w;
        this.n = n;
    }

    //******************************************************************************************
    //************************************* Fragment events ************************************
    //* This passes the call back to the default implementation if the method is not overriden *
    //******************************************************************************************
    @Override
    public void onAttach(Activity vActivity)
    {
        w.mTVisitorAppFragment.nRun(w.mTAlpha01, n,
            w.tFrame.putKey(w.mTVisitorAppFragment.nRun(w.mTAlpha01, n, -1, 1), vActivity)
        );
    }

    @Override
    public void onCreate(Bundle vBundle)
    {
        w.mTVisitorAppFragment.nRun(w.mTBeta01, n,
            w.tFrame.putKey(w.mTVisitorAppFragment.nRun(w.mTBeta01, n, -1, 1), vBundle)
        );
    }

    @Override
    public View onCreateView(LayoutInflater vLayoutInflater, ViewGroup vViewGroup, Bundle vBundle)
    {
        return (View)w.sObject.get("" + w.mTVisitorAppFragment.nRun(w.mTBeta01,n,
            w.tFrame.putKey(w.mTVisitorAppFragment.nRun(w.mTGamma01, n, -1, 3), vLayoutInflater),
            w.tFrame.putKey(w.mTVisitorAppFragment.nRun(w.mTGamma01, n, -1, 2), vViewGroup),
            w.tFrame.putKey(w.mTVisitorAppFragment.nRun(w.mTGamma01, n, -1, 1), vBundle)
        ));
    }

    @Override
    public void onActivityCreated(Bundle vBundle)
    {
        w.mTVisitorAppFragment.nRun(w.mTDelta01, n,
            w.tFrame.putKey(w.mTVisitorAppFragment.nRun(w.mTDelta01, n, -1, 1), vBundle)
        );
    }

    @Override
    public void onViewStateRestored(Bundle vBundle)
    {
        w.mTVisitorAppFragment.nRun(w.mTEpsilon01, n,
            w.tFrame.putKey(w.mTVisitorAppFragment.nRun(w.mTEpsilon01, n, -1, 1), vBundle)
        );
    }

    @Override
    public void onStart()
    {
        w.mTVisitorAppFragment.nRun(w.mTDzeta01, n);
    }

    @Override
    public void onResume()
    {
        w.mTVisitorAppFragment.nRun(w.mTEta01, n);
    }

    @Override
    public void onPause()
    {
        w.mTVisitorAppFragment.nRun(w.mTTheta01, n);
    }

    @Override
    public void onSaveInstanceState(Bundle vBundle)
    {
        w.mTVisitorAppFragment.nRun(w.mTIota01, n,
            w.tFrame.putKey(w.mTVisitorAppFragment.nRun(w.mTIota01, n, -1, 1), vBundle)
        );
    }

    @Override
    public void onStop()
    {
        w.mTVisitorAppFragment.nRun(w.mTKappa01, n);
    }

    @Override
    public void onDestroyView()
    {
        w.mTVisitorAppFragment.nRun(w.mTLambda01, n);
    }

    @Override
    public void onDestroy()
    {
        w.mTVisitorAppFragment.nRun(w.mTMu01, n);
    }

    @Override
    public void onDetach()
    {
        w.mTVisitorAppFragment.nRun(w.mTNu01, n);
    }

    @Override
    public void onCreateOptionsMenu(Menu vMenu, MenuInflater vMenuInflater)
    {
        w.mTVisitorAppFragment.nRun(w.mTXi01, n,
            w.tFrame.putKey(w.mTVisitorAppFragment.nRun(w.mTXi01, n, -1, 2), vMenu),
            w.tFrame.putKey(w.mTVisitorAppFragment.nRun(w.mTXi01, n, -1, 1), vMenuInflater)
        );
    }

    @Override
    public void onPrepareOptionsMenu(Menu vMenu)
    {
        w.mTVisitorAppFragment.nRun(w.mTOmicron01, n,
            w.tFrame.putKey(w.mTVisitorAppFragment.nRun(w.mTOmicron01, n, -1, 1), vMenu)
        );
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem vMenuItem)
    {
        return w.mTVisitorAppFragment.nRun(w.mTPi01, n,
            w.tFrame.putKey(w.mTVisitorAppFragment.nRun(w.mTPi01, n, -1, 1), vMenuItem)
        ) != 0;
    }

    //*******************************************************************************************//
    //**************************************** Fragment : super  ********************************//
    //*******************************************************************************************//
    public void onAttachParent(Activity vActivity)
    {
        super.onAttach(vActivity);
    }

    public void onCreateParent(Bundle vBundle)
    {
        super.onCreate(vBundle);
    }

    public View onCreateViewParent(LayoutInflater vLayoutInflater, ViewGroup vViewGroup, Bundle vBundle)
    {
        return super.onCreateView(vLayoutInflater, vViewGroup, vBundle);
    }

    public void onActivityCreatedParent(Bundle vBundle)
    {
        super.onActivityCreated(vBundle);
    }

    public void onViewStateRestoredParent(Bundle vBundle)
    {
        super.onViewStateRestored(vBundle);
    }

    public void onStartParent()
    {
        super.onStart();
    }

    public void onResumeParent()
    {
        super.onResume();
    }

    public void onPauseParent()
    {
        super.onPause();
    }

    public void onSaveInstanceStateParent(Bundle vBundle)
    {
        super.onSaveInstanceState(vBundle);
    }

    public void onStopParent()
    {
        super.onStop();
    }

    public void onDestroyViewParent()
    {
        super.onDestroyView();
    }

    public void onDestroyParent()
    {
        super.onDestroy();
    }

    public void onDetachParent()
    {
        super.onDetach();
    }

    public void onCreateOptionsMenuParent(Menu vMenu, MenuInflater vMenuInflater)
    {
        super.onCreateOptionsMenu(vMenu, vMenuInflater);
    }

    public void onPrepareOptionsMenuParent(Menu vMenu)
    {
        super.onPrepareOptionsMenu(vMenu);
    }

    public boolean onOptionsItemSelectedParent(MenuItem item)
    {
      return super.onOptionsItemSelected(item);
    }
}
