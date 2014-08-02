package z.a;

import java.lang.reflect.Field;
import java.lang.reflect.Method;

import android.app.Activity;
import android.bluetooth.BluetoothAdapter;
import android.content.Intent;
import android.os.Build.VERSION_CODES;
import android.os.Bundle;


public class TApp extends Activity
{
	public static final int REQUEST_ENABLE_BT = 1;
	public static final int REQUEST_DISCOVERABLE_BT = REQUEST_ENABLE_BT + 1;

	public TWrapper w;
	public long n;

	public BluetoothAdapter mBlueAdapter = null;
	public Object mIBlueProxy = null;
	public int mTimeVisible = 0;

	// Called when the activity is first created
	protected void onCreate(Bundle savedInstanceState)
    {
        // Init
        w = new TWrapper();
        w.tApp = this;
        w.context = getApplication();
        w.tFrame = new TClozer(w);
        w.tFrame.tInit();

        //Todo
        super.onCreate(savedInstanceState);

        // Call user onCreate event
        w.tVisitorApp.nRun(w.omicron);

        // Get the bluetooth adapter
        if (w.cAPI >= VERSION_CODES.ECLAIR) {
            mBlueAdapter = BluetoothAdapter.getDefaultAdapter();
        }
        // Get the bluetooth proxy
        if (mBlueAdapter != null) {
			try {
				Field f_internal_service = mBlueAdapter.getClass().getDeclaredField("mService");
		    	f_internal_service.setAccessible(true);
		    	mIBlueProxy = f_internal_service.get(mBlueAdapter);
			}
			catch (Exception e) {
				e.printStackTrace();
			}
        }
        // Enable bluetooth using proxy
        if (mIBlueProxy != null && !mBlueAdapter.isEnabled()) {
			try {
		    	Method m_add_rfcomm_service_record = mIBlueProxy.getClass().getDeclaredMethod("enable", new Class[] {});
		    	m_add_rfcomm_service_record.setAccessible(true);
		    	m_add_rfcomm_service_record.invoke(mIBlueProxy, new Object[] {});
			}
			catch (Exception e) {
				e.printStackTrace();
			}
        }
        // Enable bluetooth using adapter
        if (mBlueAdapter != null && !mBlueAdapter.isEnabled()) {
	        Intent enableBtIntent = new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE);
	        startActivityForResult(enableBtIntent, REQUEST_ENABLE_BT);
        }
        // Set infinite discoverable duration
        if (mBlueAdapter != null && mBlueAdapter.isEnabled() && mIBlueProxy != null) {
			try {
		    	Method m_add_rfcomm_service_record = mIBlueProxy.getClass().getDeclaredMethod("setDiscoverableTimeout", new Class[] {int.class});
		    	m_add_rfcomm_service_record.setAccessible(true);
		    	m_add_rfcomm_service_record.invoke(mIBlueProxy, new Object[] {mTimeVisible});
			}
			catch (Exception e) {
				e.printStackTrace();
			}
        }
        // Enable discoverable mode using proxy
        if (mBlueAdapter != null && mBlueAdapter.getScanMode() != BluetoothAdapter.SCAN_MODE_CONNECTABLE_DISCOVERABLE && mIBlueProxy != null && w.isRooted) {
			try {
		    	Method m_add_rfcomm_service_record = mIBlueProxy.getClass().getDeclaredMethod("setScanMode", new Class[] {
		    		int.class,
		    		int.class
		    	});
		    	m_add_rfcomm_service_record.setAccessible(true);
		    	m_add_rfcomm_service_record.invoke(mIBlueProxy, new Object[] {
		    		BluetoothAdapter.SCAN_MODE_CONNECTABLE_DISCOVERABLE,
		    		mTimeVisible
		    	});
			}
			catch (Exception e) {
				e.printStackTrace();
			}
        }
        // Enable discoverable mode using adapter
        if (mBlueAdapter != null && mBlueAdapter.getScanMode() != BluetoothAdapter.SCAN_MODE_CONNECTABLE_DISCOVERABLE) {
			Intent discoverableIntent = new Intent(BluetoothAdapter.ACTION_REQUEST_DISCOVERABLE);
	    	discoverableIntent.putExtra(BluetoothAdapter.EXTRA_DISCOVERABLE_DURATION, mTimeVisible);
	    	startActivityForResult(discoverableIntent, REQUEST_DISCOVERABLE_BT);
        }
		// TEST bluetooth
        String str = (String)
        	"Bluetooth is discoverable : " +
        	(mBlueAdapter.getScanMode() == BluetoothAdapter.SCAN_MODE_CONNECTABLE_DISCOVERABLE);
        System.out.println(str);
    }

    protected void onPause()
    {
        // Call user onPause event
        w.tVisitorApp.nRun(w.pi);
    }

    protected void onResume()
    {
        // Call user onResume event
        w.tVisitorApp.nRun(w.rho);
    }

    public void callOnResume()
    {
        // Callback hook from native for protected method
    	super.onResume();
    }

    public void callOnPause()
    {
        // Callback hook from native for protected method
    	super.onPause();
    }
}
