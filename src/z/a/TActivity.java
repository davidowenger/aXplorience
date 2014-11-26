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
        w.tVisitorApp.nRun(w.alpha00);

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
        w.tVisitorApp.nRun(w.beta00);
	}

    protected void onPause()
    {
        w.tVisitorApp.nRun(w.gamma00);
    }

    protected void onRestart()
    {
        w.tVisitorApp.nRun(w.delta00);
    }

    protected void onResume()
	{
        w.tVisitorApp.nRun(w.epsilon00);
	}

    protected void onStart()
	{
        w.tVisitorApp.nRun(w.dzeta00);
	}

    protected void onStop()
	{
        w.tVisitorApp.nRun(w.eta00);
	}

    protected void onActivityResult(int requestCode, int resultCode, Intent intent)
    {
    	if (intent != null && intent.getAction() != null) {
	    	String action = intent.getAction();
	
	    	if (action.equals(BluetoothAdapter.ACTION_REQUEST_ENABLE)) {
	        	w.tVisitorApp.nRun(w.theta00, 1, requestCode, resultCode, -1);
	    	} else if (action.equals(BluetoothAdapter.ACTION_REQUEST_DISCOVERABLE)) {
	        	w.tVisitorApp.nRun(w.theta00, 2, requestCode, resultCode, intent.getIntExtra(BluetoothAdapter.EXTRA_DISCOVERABLE_DURATION, -1));
	    	}
    	} else {
    		w.tVisitorApp.nRun(w.theta00, 2, requestCode, resultCode, -1);
    	}
    }

	public void discoverable(int nTimeout)
	{
		Intent intentDiscoverable = new Intent(BluetoothAdapter.ACTION_REQUEST_DISCOVERABLE);
		intentDiscoverable.putExtra(BluetoothAdapter.EXTRA_DISCOVERABLE_DURATION, nTimeout);
    	startActivityForResult(intentDiscoverable, 1);
    }

    public void callOnCreate()
	{
    	super.onCreate(w.bundle);
	}

    public void callOnDestroy()
	{
    	super.onDestroy();
	}

    public void callOnPause()
    {
    	super.onPause();
    }

    public void callOnResume()
    {
    	super.onResume();
    }

    public void callOnRestart()
	{
    	super.onRestart();
	}

    public void callOnStart()
	{
    	super.onStart();
	}

    public void callOnStop()
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
	        	w.tVisitorApp.nRun(w.omicron00);
	    	} else if (action.equals(BluetoothAdapter.ACTION_DISCOVERY_STARTED)) {
	        	w.tVisitorApp.nRun(w.pi00);
	    	} else if (action.equals(BluetoothDevice.ACTION_FOUND)) {
	        	long n = w.tVisitorApp.nRun(w.rho00, 0);
	        	w.sObject.put("" + n, intent.getParcelableExtra(BluetoothDevice.EXTRA_DEVICE));
	        	w.tVisitorApp.nRun(w.rho00, n);
	    	} else if (action.equals(BluetoothAdapter.ACTION_LOCAL_NAME_CHANGED)) {
	    		String string = intent.getStringExtra(BluetoothAdapter.EXTRA_LOCAL_NAME);
	        	w.aObject.add(string);
	        	w.tVisitorApp.nRun(w.sigma00, w.aObject.lastIndexOf(string));
	    	} else if (action.equals(BluetoothAdapter.ACTION_SCAN_MODE_CHANGED)) {
	        	w.tVisitorApp.nRun(w.tau00, intent.getIntExtra(BluetoothAdapter.EXTRA_SCAN_MODE, -1), intent.getIntExtra(BluetoothAdapter.EXTRA_PREVIOUS_SCAN_MODE, -1));
			} else if (action.equals(BluetoothAdapter.ACTION_STATE_CHANGED)) {
	        	w.tVisitorApp.nRun(w.upsilon00, intent.getIntExtra(BluetoothAdapter.EXTRA_STATE, -1), intent.getIntExtra(BluetoothAdapter.EXTRA_PREVIOUS_STATE, -1));
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
	        w.tVisitorApp.nRun(w.phi00, ((long[])m.obj)[0], ((long[])m.obj)[1], ((long[])m.obj)[2]);
		} else {
			super.handleMessage(m);
		}
	}
}
