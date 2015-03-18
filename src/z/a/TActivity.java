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

public class TActivity extends Activity
{
	public TWrapper w;
	public long n;

	// Called when the activity is first created
	protected void onCreate(Bundle savedInstanceState)
    {
        // Init
        w = new TWrapper();
        w.bundle = savedInstanceState;
        w.tActivity = this;
        w.tFrame = new TClozer(w);
        w.tFrame.tInit();

        // Call user onCreate event
        w.mTVisitorAppActivity.nRun(w.mTAlpha00);

		//00000000-0000-07da-0000-0000000007d0
		//UUID(2010L,2000L);
		//00000000-0000-07db-0000-0000000007d0
		//UUID(2010L,2000L);
		//00000000-0000-07dc-0000-0000000007d0
		//UUID(2010L,2000L);

		//LinearLayout mLayout = new LinearLayout(this);
		//mLayout.setOrientation(LinearLayout.VERTICAL);
		//mLayout.setLayoutParams(new LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.MATCH_PARENT));
		//mLayout.setGravity(Gravity.CENTER);
		//setContentView((View)mLayout);

		//TextView text = new TextView(this);
		//text.setTextSize(20);
		//text.setGravity(Gravity.CENTER_HORIZONTAL);
		//text.setTextSize(20);
		//text.setText(u1.toString() + "\n" + u2.toString() + "\n" + u3.toString());
		//mLayout.addView(text);
    }

    protected void onDestroy()
	{
        w.mTVisitorAppActivity.nRun(w.mTBeta00);
        w.tFrame.tDestroy();
	}

    protected void onPause()
    {
        w.mTVisitorAppActivity.nRun(w.mTGamma00);
    }

    protected void onRestart()
    {
        w.mTVisitorAppActivity.nRun(w.mTDelta00);
    }

    protected void onResume()
	{
        w.mTVisitorAppActivity.nRun(w.mTEpsilon00);
	}

    protected void onStart()
	{
        w.mTVisitorAppActivity.nRun(w.mTDzeta00);
	}

    protected void onStop()
	{
        w.mTVisitorAppActivity.nRun(w.mTEta00);
	}

    protected void onActivityResult(int requestCode, int resultCode, Intent intent)
    {
    	if (intent != null && intent.getAction() != null) {
	    	String action = intent.getAction();

	    	if (action.equals(BluetoothAdapter.ACTION_REQUEST_ENABLE)) {
	        	w.mTVisitorAppActivity.nRun(w.mTTheta00, 1, requestCode, resultCode, -1);
	    	} else if (action.equals(BluetoothAdapter.ACTION_REQUEST_DISCOVERABLE)) {
	        	w.mTVisitorAppActivity.nRun(w.mTTheta00, 2, requestCode, resultCode, intent.getIntExtra(BluetoothAdapter.EXTRA_DISCOVERABLE_DURATION, -1));
	    	}
    	} else {
    		w.mTVisitorAppActivity.nRun(w.mTTheta00, 2, requestCode, resultCode, -1);
    	}
    }

	public void discoverable(int nTimeout)
	{
		Intent intentDiscoverable = new Intent(BluetoothAdapter.ACTION_REQUEST_DISCOVERABLE);
		intentDiscoverable.putExtra(BluetoothAdapter.EXTRA_DISCOVERABLE_DURATION, nTimeout);
    	startActivityForResult(intentDiscoverable, 1);
    }

    public void onCreateParent()
	{
    	super.onCreate(w.bundle);
	}

    public void onDestroyParent()
	{
    	super.onDestroy();
	}

    public void onPauseParent()
    {
    	super.onPause();
    }

    public void onResumeParent()
    {
    	super.onResume();
    }

    public void onRestartParent()
	{
    	super.onRestart();
	}

    public void onStartParent()
	{
    	super.onStart();
	}

    public void onStopParent()
	{
    	super.onStop();
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
    	if (intent != null && intent.getAction() != null) {
	    	String action = intent.getAction();

	    	if (action.equals(BluetoothAdapter.ACTION_DISCOVERY_FINISHED)) {
	        	w.mTVisitorAppActivity.nRun(w.mTOmicron00);
	    	} else if (action.equals(BluetoothAdapter.ACTION_DISCOVERY_STARTED)) {
	        	w.mTVisitorAppActivity.nRun(w.mTPi00);
	    	} else if (action.equals(BluetoothDevice.ACTION_FOUND)) {
	        	long n = w.mTVisitorAppActivity.nRun(w.mTRho00, 0);
	        	w.sObject.put("" + n, intent.getParcelableExtra(BluetoothDevice.EXTRA_DEVICE));
	        	w.mTVisitorAppActivity.nRun(w.mTRho00, n);
	    	} else if (action.equals(BluetoothAdapter.ACTION_LOCAL_NAME_CHANGED)) {
	    		String string = intent.getStringExtra(BluetoothAdapter.EXTRA_LOCAL_NAME);
	        	w.mTVisitorAppActivity.nRun(w.mTSigma00, w.tFrame.putNext(string));
	    	} else if (action.equals(BluetoothAdapter.ACTION_SCAN_MODE_CHANGED)) {
	        	w.mTVisitorAppActivity.nRun(w.mTTau00, intent.getIntExtra(BluetoothAdapter.EXTRA_SCAN_MODE, -1), intent.getIntExtra(BluetoothAdapter.EXTRA_PREVIOUS_SCAN_MODE, -1));
			} else if (action.equals(BluetoothAdapter.ACTION_STATE_CHANGED)) {
	        	w.mTVisitorAppActivity.nRun(w.mTUpsilon00, intent.getIntExtra(BluetoothAdapter.EXTRA_STATE, -1), intent.getIntExtra(BluetoothAdapter.EXTRA_PREVIOUS_STATE, -1));
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
	        w.mTVisitorAppActivity.nRun(w.mTPhi00, ((long[])m.obj)[0], ((long[])m.obj)[1], ((long[])m.obj)[2]);
		} else {
			super.handleMessage(m);
		}
	}
}
