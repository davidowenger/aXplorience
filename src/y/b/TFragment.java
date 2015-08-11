package y.b;

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
    private TWrapper w;
    private long n;

    //*******************************************************************************************
    //******************************************* Fragment **************************************
    //*******************************************************************************************

    public TFragment()
    {
        this.w = null;
        this.n = 0;
    }

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
        long vcKey;
        if (n != 0) {
            w.mTVisitorAppFragment.nRun(w.mTAlpha01, n,
                (vcKey = w.tFrame.getKey(vActivity)) != -1 ? vcKey : w.tFrame.putKey(w.mTVisitorAppFragment.nRun(w.mTAlpha01, n, -1, 1), vActivity)
            );
        } else {
            super.onAttach(vActivity);
        }
    }

    @Override
    public void onCreate(Bundle vBundle)
    {
        long vcKey;
//        if (n == 0 && vBundle.containsKey("z.a.TFragment.n")) {
//            n = vBundle.getLong("z.a.TFragment.n");
//            w = TWrapper.w;
//        }
        if (n != 0) {
            w.mTVisitorAppFragment.nRun(w.mTBeta01, n,
                (vcKey = w.tFrame.getKey(vBundle)) != -1 ? vcKey : w.tFrame.putKey(w.mTVisitorAppFragment.nRun(w.mTBeta01, n, -1, 1), vBundle)
            );
        } else {
            super.onCreate(vBundle);
        }
    }

    @Override
    public View onCreateView(LayoutInflater vLayoutInflater, ViewGroup vViewGroup, Bundle vBundle)
    {
        long vcKey;
        if (n != 0) { return (View)w.sObject.get(w.mTVisitorAppFragment.nRun(w.mTGamma01,n,
            (vcKey = w.tFrame.getKey(vLayoutInflater)) != -1 ? vcKey :  w.tFrame.putKey(w.mTVisitorAppFragment.nRun(w.mTGamma01, n, -1, 3), vLayoutInflater),
            (vcKey = w.tFrame.getKey(vViewGroup)) != -1 ? vcKey : w.tFrame.putKey(w.mTVisitorAppFragment.nRun(w.mTGamma01, n, -1, 2), vViewGroup),
            (vcKey = w.tFrame.getKey(vBundle)) != -1 ? vcKey : w.tFrame.putKey(w.mTVisitorAppFragment.nRun(w.mTGamma01, n, -1, 1), vBundle)
        )); } else { return super.onCreateView(vLayoutInflater, vViewGroup, vBundle); }
    }

    @Override
    public void onActivityCreated(Bundle vBundle)
    {
        long vcKey;
        if (n != 0) { w.mTVisitorAppFragment.nRun(w.mTDelta01, n,
                (vcKey = w.tFrame.getKey(vBundle)) != -1 ? vcKey : w.tFrame.putKey(w.mTVisitorAppFragment.nRun(w.mTDelta01, n, -1, 1), vBundle)
        ); } else { super.onActivityCreated(vBundle); }
    }

    @Override
    public void onStart()
    {
        if (n != 0) { w.mTVisitorAppFragment.nRun(w.mTDzeta01, n
        ); } else { super.onStart(); }
    }

    @Override
    public void onResume()
    {
        if (n != 0) { w.mTVisitorAppFragment.nRun(w.mTEta01, n
        ); } else { super.onResume(); }
    }

    @Override
    public void onPause()
    {
        if (n != 0) { w.mTVisitorAppFragment.nRun(w.mTTheta01, n
        ); } else { super.onPause(); }
    }

    @Override
    public void onSaveInstanceState(Bundle vBundle)
    {
        long vcKey;
        if (n != 0) {
            w.mTVisitorAppFragment.nRun(w.mTIota01, n,
                (vcKey = w.tFrame.getKey(vBundle)) != -1 ? vcKey : w.tFrame.putKey(w.mTVisitorAppFragment.nRun(w.mTIota01, n, -1, 1), vBundle)
            );
//            vBundle.putLong("z.a.TFragment.n", n);
        } else {
            super.onSaveInstanceState(vBundle);
        }
    }

    @Override
    public void onStop()
    {
        if (n != 0) { w.mTVisitorAppFragment.nRun(w.mTKappa01, n
        ); } else { super.onStop(); }
    }

    @Override
    public void onDestroyView()
    {
        if (n != 0) { w.mTVisitorAppFragment.nRun(w.mTLambda01, n
        ); } else { super.onDestroyView(); }
    }

    @Override
    public void onDestroy()
    {
        if (n != 0) { w.mTVisitorAppFragment.nRun(w.mTMu01, n
        ); } else { super.onDestroy(); }
    }

    @Override
    public void onDetach()
    {
        if (n != 0) { w.mTVisitorAppFragment.nRun(w.mTNu01, n
        ); } else { super.onDetach(); }
    }

    @Override
    public void onCreateOptionsMenu(Menu vMenu, MenuInflater vMenuInflater)
    {
        long vcKey;
        if (n != 0) { w.mTVisitorAppFragment.nRun(w.mTXi01, n,
                (vcKey = w.tFrame.getKey(vMenu)) != -1 ? vcKey : w.tFrame.putKey(w.mTVisitorAppFragment.nRun(w.mTXi01, n, -1, 2), vMenu),
                (vcKey = w.tFrame.getKey(vMenuInflater)) != -1 ? vcKey : w.tFrame.putKey(w.mTVisitorAppFragment.nRun(w.mTXi01, n, -1, 1), vMenuInflater)
        ); } else { super.onCreateOptionsMenu(vMenu, vMenuInflater); }
    }

    @Override
    public void onPrepareOptionsMenu(Menu vMenu)
    {
        long vcKey;
        if (n != 0) { w.mTVisitorAppFragment.nRun(w.mTOmicron01, n,
            (vcKey = w.tFrame.getKey(vMenu)) != -1 ? vcKey : w.tFrame.putKey(w.mTVisitorAppFragment.nRun(w.mTOmicron01, n, -1, 1), vMenu)
        ); } else { super.onPrepareOptionsMenu(vMenu); }
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem vMenuItem)
    {
        long vcKey;
        if (n != 0) { return w.mTVisitorAppFragment.nRun(w.mTPi01, n,
            (vcKey = w.tFrame.getKey(vMenuItem)) != -1 ? vcKey : w.tFrame.putKey(w.mTVisitorAppFragment.nRun(w.mTPi01, n, -1, 1), vMenuItem)
        ) != 0; } else { return super.onOptionsItemSelected(vMenuItem); }
    }

    //*****************************************************************************************
    //**************************************** Fragment super  ********************************
    //*****************************************************************************************
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
