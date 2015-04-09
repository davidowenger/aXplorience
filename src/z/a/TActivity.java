package z.a;

import android.app.Activity;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.os.StrictMode;

public class TActivity extends Activity
{
	public TWrapper w;
	public long n;

	// Called when the activity is first created
	protected void onCreate(Bundle vBundle)
    {
        // Init
        w = new TWrapper();
        w.doDebug = false;
        w.isStrict = false;

        // Creeate
        if (w.isStrict) {
            StrictMode.setThreadPolicy(
                new StrictMode.ThreadPolicy.Builder()
                    .detectAll()
                    .penaltyLog()
                    .build()
            );
            StrictMode.setVmPolicy(
                new StrictMode.VmPolicy.Builder()
                    .detectAll()
                    .penaltyLog()
                    .build()
           );
        }
        TWrapper.w = w;
        w.tActivity = this;
        w.context = w.tActivity.getApplication();
        w.tActivityHandler = new TActivityHandler(w);
        w.tFrame = new TClozer(w);
        w.tFrame.tInit();

        // Call user onCreate event
        long vcKey;
        w.mTVisitorAppActivity.nRun(w.mTAlpha00, n,
            (vcKey = w.tFrame.getKey(vBundle)) != -1 ? vcKey : w.tFrame.putKey(w.mTVisitorAppActivity.nRun(w.mTAlpha00, n, -1, 1), vBundle)
        );
    }

    protected void onRestart()
    {
        w.mTVisitorAppActivity.nRun(w.mTBeta00, n);
    }

    protected void onStart()
    {
        w.mTVisitorAppActivity.nRun(w.mTGamma00, n);
    }

    protected void onResume()
    {
        w.mTVisitorAppActivity.nRun(w.mTDelta00, n);
    }

    protected void onPause()
    {
        w.mTVisitorAppActivity.nRun(w.mTEpsilon00, n);
    }

    protected void onStop()
    {
        w.mTVisitorAppActivity.nRun(w.mTDzeta00, n);
    }

    protected void onDestroy()
	{
        w.mTVisitorAppActivity.nRun(w.mTEta00, n);
        w.tFrame.tCancel();
        w.tFrame.nCancel();
        w.tActivityHandler.cancel();
        w.tActivityHandler = null;
        w.context = null;
        w.tActivity = null;
        w = null;
        TWrapper.w = null;
	}

    protected void onActivityResult(int requestCode, int resultCode, Intent intent)
    {
    	if (intent != null && intent.getAction() != null) {
	    	String action = intent.getAction();

	    	if (action.equals(BluetoothAdapter.ACTION_REQUEST_ENABLE)) {
	        	w.mTVisitorAppActivity.nRun(w.mTTheta00, n, 1, requestCode, resultCode, -1);
	    	} else if (action.equals(BluetoothAdapter.ACTION_REQUEST_DISCOVERABLE)) {
	        	w.mTVisitorAppActivity.nRun(w.mTTheta00, n, 2, requestCode, resultCode, intent.getIntExtra(BluetoothAdapter.EXTRA_DISCOVERABLE_DURATION, -1));
	    	}
    	} else {
    		w.mTVisitorAppActivity.nRun(w.mTTheta00, n, 2, requestCode, resultCode, -1);
    	}
    }

	public void discoverable(int nTimeout)
	{
		Intent intentDiscoverable = new Intent(BluetoothAdapter.ACTION_REQUEST_DISCOVERABLE);
		intentDiscoverable.putExtra(BluetoothAdapter.EXTRA_DISCOVERABLE_DURATION, nTimeout);
    	startActivityForResult(intentDiscoverable, 1);
    }

    public void onCreateParent(Bundle vBundle)
	{
    	super.onCreate(vBundle);
	}

    public void onRestartParent()
    {
        super.onRestart();
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

    public void onStopParent()
    {
        super.onStop();
    }

    public void onDestroyParent()
	{
    	super.onDestroy();
	}
}

class TActivityReceiver extends BroadcastReceiver
{
	public TWrapper w;

	public TActivityReceiver(TWrapper w)
	{
		this.w = w;
	}

    public void onReceive(Context context, Intent intent)
    {
        long vcKey;

    	if (intent != null && intent.getAction() != null) {
	    	String action = intent.getAction();

	    	if (action.equals(BluetoothAdapter.ACTION_DISCOVERY_FINISHED)) {
	        	w.mTVisitorAppActivity.nRun(w.mTOmicron00, w.tActivity.n);
	    	} else if (action.equals(BluetoothAdapter.ACTION_DISCOVERY_STARTED)) {
	        	w.mTVisitorAppActivity.nRun(w.mTPi00, w.tActivity.n);
	    	} else if (action.equals(BluetoothDevice.ACTION_FOUND)) {
                Object vObject = intent.getParcelableExtra(BluetoothDevice.EXTRA_DEVICE);
                w.mTVisitorAppActivity.nRun(w.mTRho00, w.tActivity.n,
                    (vcKey = w.tFrame.getKey(vObject)) != -1 ? vcKey : w.tFrame.putKey(w.mTVisitorAppActivity.nRun(w.mTRho00, w.tActivity.n, -1, 1), vObject)
                );
	    	} else if (action.equals(BluetoothAdapter.ACTION_LOCAL_NAME_CHANGED)) {
	    		String string = intent.getStringExtra(BluetoothAdapter.EXTRA_LOCAL_NAME);
	        	w.mTVisitorAppActivity.nRun(w.mTSigma00, w.tActivity.n, w.tFrame.putNext(string));
	    	} else if (action.equals(BluetoothAdapter.ACTION_SCAN_MODE_CHANGED)) {
	        	w.mTVisitorAppActivity.nRun(w.mTTau00, w.tActivity.n, intent.getIntExtra(BluetoothAdapter.EXTRA_SCAN_MODE, -1), intent.getIntExtra(BluetoothAdapter.EXTRA_PREVIOUS_SCAN_MODE, -1));
			} else if (action.equals(BluetoothAdapter.ACTION_STATE_CHANGED)) {
	        	w.mTVisitorAppActivity.nRun(w.mTUpsilon00,w.tActivity. w.tActivity.n, intent.getIntExtra(BluetoothAdapter.EXTRA_STATE, -1), intent.getIntExtra(BluetoothAdapter.EXTRA_PREVIOUS_STATE, -1));
	    	}
    	}
    }
}

class TActivityHandler extends Handler
{
	public TWrapper w;

	public TActivityHandler(TWrapper w)
	{
        this.w = w;
	}

    public void handleMessage(Message m)
    {
        if (m.what == 0) {
            w.mTVisitorAppActivity.nRun(w.mTPhi00, w.tActivity.n, ((long[])m.obj)[0], ((long[])m.obj)[1], ((long[])m.obj)[2], ((long[])m.obj)[3]);
        } else {
            super.handleMessage(m);
        }
    }

    public void cancel()
    {
        removeCallbacksAndMessages(null);
    }
}
