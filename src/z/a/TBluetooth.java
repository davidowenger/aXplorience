package z.a;

import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.util.UUID;
import java.util.Vector;

import android.Manifest;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.Build.VERSION_CODES;

public class TBluetooth
{
	public static final int QUANTUM_TO_LOCK = 100;

	public static final int INDEX_ENABLED = 0; // CONFIG_RUN
	public static final int INDEX_DISCOVERABLE = INDEX_ENABLED + 1; // CONFIG_ALLOW_DISCOVERABLE_MODE
	public static final int INDEX_CONNECTED = INDEX_DISCOVERABLE + 1; //
	public static final int INDEX_TIMEOUT = INDEX_CONNECTED + 1; // CONFIG_ALLOW_MAX_TIMEOUT
	public static final int INDEX_BLUETOOTH = INDEX_TIMEOUT + 1; // CONFIG_AUTO_ENABLE_BT
	public static final int INDEX_LEGACY = INDEX_BLUETOOTH + 1; // CONFIG_ALLOW_LEGACY

	public TWrapper w;

	public boolean mHasBluetooth;
	public boolean mHasProxy;
	public boolean mIsSystem;

	public TConfig mPrefs;
	public TBluetoothReceiver[] mReceiver;
	public int[] mState;
	public boolean[] mConfig;
	public boolean[] mSaved;

	public BluetoothAdapter mBlueAdapter;
	public String[] mBtAction;
	public String[] mBtKey;
	public int[] mBtValue;

	public Object mBlueProxy;
	public Method mMEnable;
	public Method mMSetDiscoverableTimeout;
	public Method mMgetDiscoverableTimeout;
	public Method mMSetScanMode;

	public TBluetooth(TWrapper w)
	{
		this.w = w;

		mPrefs = w.tConfig;
		mPrefs.setb(INDEX_ENABLED, true);
		mPrefs.setb(INDEX_DISCOVERABLE, true);
		mPrefs.setb(INDEX_TIMEOUT, true);
		mPrefs.setb(INDEX_BLUETOOTH, true);
		mPrefs.setb(INDEX_LEGACY, true);

    	w.serviceName = "Proximity service";
    	w.uuid = new UUID(2001L,2000L);
    	//w.uuid = UUID.fromString("00001101-0000-1000-8000-00805F9B34FB");

		mHasBluetooth = false;
		mHasProxy = false;
		mIsSystem = false;
    	mBtAction = new String[] {
			BluetoothAdapter.ACTION_STATE_CHANGED,
			BluetoothAdapter.ACTION_SCAN_MODE_CHANGED,
			"android.bluetooth.adapter.action.CONNECTION_STATE_CHANGED",
			BluetoothAdapter.ACTION_REQUEST_DISCOVERABLE,
			BluetoothDevice.ACTION_FOUND,
    	};
    	mBtKey = new String[] {
			BluetoothAdapter.EXTRA_STATE,
			BluetoothAdapter.EXTRA_SCAN_MODE,
			"android.bluetooth.adapter.action.CONNECTION_STATE_CHANGED",
			BluetoothAdapter.EXTRA_DISCOVERABLE_DURATION,
			BluetoothDevice.EXTRA_DEVICE,
    	};
    	mBtValue = new int[] {
			BluetoothAdapter.STATE_ON,
			BluetoothAdapter.SCAN_MODE_CONNECTABLE_DISCOVERABLE,
			2,
			0,
			-1,
    	};
    	mState = new int[] {
			-1,
			-1,
			-1,
			120,
			-1,
		};
    	mConfig = new boolean[] {
			false,
			false,
			false,
			false,
			false,
		};
		mReceiver = new TBluetoothReceiver[] {
			null,
			null,
			null,
			null,
			null,
		};
	    if (w.cAPI >= VERSION_CODES.ECLAIR) {
	        // Get the bluetooth adapter
	        mBlueAdapter = BluetoothAdapter.getDefaultAdapter();
	        mHasBluetooth = (mBlueAdapter != null);
	    }
	    if (mHasBluetooth) {
	        // Get the bluetooth proxy
			try {
				Field fMService = mBlueAdapter.getClass().getDeclaredField("mService");
				fMService.setAccessible(true);
		    	mBlueProxy = fMService.get(mBlueAdapter);
			}
			catch (Exception e) {
				mBlueProxy = null;
				e.printStackTrace();
			}
			mHasProxy = (mBlueProxy != null);
	    }
	    if (mHasProxy) {
	        // Get available proxy methods
	    	mMEnable = null;
    		mMSetDiscoverableTimeout = null;
    		mMgetDiscoverableTimeout = null;

			try {
		    	mMEnable = mBlueProxy.getClass().getDeclaredMethod("enable", new Class[] {});
		    	mMEnable.setAccessible(true);
			}
			catch (Exception e) {
		    	mMEnable = null;
				e.printStackTrace();
			}
			try {
				mMSetDiscoverableTimeout = mBlueProxy.getClass().getDeclaredMethod("setDiscoverableTimeout", new Class[] {int.class});
				mMSetDiscoverableTimeout.setAccessible(true);
			}
			catch (Exception e) {
				mMSetDiscoverableTimeout = null;
				e.printStackTrace();
			}
			try {
				mMgetDiscoverableTimeout = mBlueProxy.getClass().getDeclaredMethod("getDiscoverableTimeout", new Class[] {});
				mMgetDiscoverableTimeout.setAccessible(true);
			}
			catch (Exception e) {
				mMgetDiscoverableTimeout = null;
				e.printStackTrace();
			}
			try {
				mMSetScanMode = mBlueProxy.getClass().getDeclaredMethod("setScanMode", new Class[] {int.class, int.class});
				mMSetScanMode.setAccessible(true);
			}
			catch (Exception e) {
				mMSetScanMode = null;
				e.printStackTrace();
			}
		}
		if (mHasProxy) {
			mIsSystem = w.tFrame.hasRight(Manifest.permission.WRITE_SECURE_SETTINGS);
		}
    }

	public void onDestroy()
    {
		mBlueAdapter.cancelDiscovery();
		w.activity.unregisterReceiver(mReceiver[INDEX_ENABLED]);
		w.activity.unregisterReceiver(mReceiver[INDEX_DISCOVERABLE]);
		w.activity.unregisterReceiver(mReceiver[INDEX_CONNECTED]);
		w.activity.unregisterReceiver(mReceiver[INDEX_TIMEOUT]);
		w.activity.unregisterReceiver(mReceiver[INDEX_BLUETOOTH]);
    }

	public void init()
	{
		// Set current state
    	mState[INDEX_ENABLED] = ( isEnabled() ? mBtValue[INDEX_ENABLED] : -1 );
    	mState[INDEX_DISCOVERABLE] = ( isDiscoverable() ? mBtValue[INDEX_DISCOVERABLE] : -1 );
    	mState[INDEX_CONNECTED] = ( isConnected() ? mBtValue[INDEX_CONNECTED] : -1 );
    	mState[INDEX_TIMEOUT] = getDiscoverableTimeout();
    	mState[INDEX_BLUETOOTH] = 0;

		// Set current configuration
		mConfig[INDEX_ENABLED] = ( mState[INDEX_ENABLED] != -1);
		mConfig[INDEX_DISCOVERABLE] = ( mState[INDEX_DISCOVERABLE] != -1);
		mConfig[INDEX_CONNECTED] = ( mState[INDEX_CONNECTED] != -1);
		mConfig[INDEX_TIMEOUT] = (mState[INDEX_TIMEOUT] == 0);
		mConfig[INDEX_BLUETOOTH] = false;

		// Set saved configuration
		mSaved = mConfig.clone();

		// Create broadcast receiver
		mReceiver[INDEX_ENABLED] = factoryReceiver(INDEX_ENABLED);
		mReceiver[INDEX_DISCOVERABLE] = factoryReceiver(INDEX_DISCOVERABLE);
		mReceiver[INDEX_CONNECTED] = factoryReceiver(INDEX_CONNECTED);
		mReceiver[INDEX_TIMEOUT] = factoryReceiver(INDEX_TIMEOUT);
		mReceiver[INDEX_BLUETOOTH] = factoryReceiver(INDEX_BLUETOOTH);
	}

	public TBluetoothReceiver factoryReceiver(int index)
	{
		TBluetoothReceiver receiver = new TBluetoothReceiver(w, index);
		w.activity.registerReceiver(receiver, new IntentFilter(mBtAction[index]));
		return receiver;
	}

	public void server()
	{
		// Create a server
        w.btServer = new BtServer(w);
        w.btServer.start();
	}

	public void connect()
	{
		// Create a client connection
		boolean found = false;

		while (!found) {
			found = discover(15000);

        	try {
    			Thread.sleep(15000);
        	}
    		catch (Exception e) {
    			e.printStackTrace();
    		}
		}
		BluetoothDevice device = mReceiver[INDEX_BLUETOOTH].maDevice.lastElement();
        w.btConnect = new BtConnect(w, device);
        w.btConnect.start();
	}

	public boolean discover(int durationToLock)
	{
		if (mHasBluetooth && !mConfig[INDEX_BLUETOOTH]) {
			mBlueAdapter.startDiscovery();
	    }
	    durationToLock /= QUANTUM_TO_LOCK;

		while (!mConfig[INDEX_BLUETOOTH] && --durationToLock >= 0) {
			mReceiver[INDEX_BLUETOOTH].lock(QUANTUM_TO_LOCK);
		}
		mBlueAdapter.cancelDiscovery();

		return mConfig[INDEX_BLUETOOTH];
	}

	public boolean isConnected()
	{
	    return false;
    }

	public boolean isEnabled()
	{
		boolean ret = false;

		if (mHasBluetooth) {
			ret = mBlueAdapter.isEnabled();
		}
	    return ret;
    }

	public boolean enable(int durationToLock)
	{
	    // Enable bluetooth
		if (mHasBluetooth && !mConfig[INDEX_ENABLED]) {
	    	mBlueAdapter.enable();
	    }
	    durationToLock /= QUANTUM_TO_LOCK;

		while (!mConfig[INDEX_ENABLED] && --durationToLock >= 0) {
			mReceiver[INDEX_ENABLED].lock(QUANTUM_TO_LOCK);
		}
		return mConfig[INDEX_ENABLED];
    }

	public boolean enable()
	{
		return enable(0);
    }

	public int getDiscoverableTimeout()
	{
	    // Get discoverable duration
		int ret = mState[INDEX_TIMEOUT];

	    if (mHasProxy && mMgetDiscoverableTimeout != null) {
	    	try {
	    		ret = (Integer)mMgetDiscoverableTimeout.invoke(mBlueProxy, new Object[] {});
	    	}
			catch (Exception e) {
				ret = mState[INDEX_TIMEOUT];
				e.printStackTrace();
			}
	    }
	    mState[INDEX_TIMEOUT] = ret;

	    return mState[INDEX_TIMEOUT];
    }

	public int getPreferedTimeout()
	{
		int ret = mState[INDEX_TIMEOUT];

		if (mPrefs.getb(INDEX_TIMEOUT)) {
			ret = ( w.cAPI >= 17 ? 0 : 300 );
		}
		return ret;
	}

	public void setDiscoverableTimeout(int discoverableTimeout)
	{
	    // Set discoverable duration
	    if (mHasProxy && mMSetDiscoverableTimeout != null) {
	    	try {
		    	mMSetDiscoverableTimeout.invoke(mBlueProxy, new Object[] {discoverableTimeout});
	    	}
			catch (Exception e) {
				e.printStackTrace();
			}
	    }
    }

	public boolean isDiscoverable()
	{
	    return (mHasBluetooth && (mBlueAdapter.getScanMode() == mBtValue[INDEX_DISCOVERABLE]));
    }

	public boolean discoverable(int durationToLock)
	{
	    // Enable discoverable mode
		boolean done = mConfig[INDEX_DISCOVERABLE];

		if (!done && mIsSystem) {
	    	try {
	    		mMSetScanMode.invoke(mBlueProxy, new Object[] {mBtValue[INDEX_DISCOVERABLE], 0});
	    		done = true;
	    	}
			catch (Exception e) {
	    		done = false;
				e.printStackTrace();
			}
	    }
	    if (!done && mHasBluetooth) {
			Intent intentDiscoverable = new Intent(BluetoothAdapter.ACTION_REQUEST_DISCOVERABLE);
			intentDiscoverable.putExtra(BluetoothAdapter.EXTRA_DISCOVERABLE_DURATION, getPreferedTimeout());
	    	w.activity.startActivityForResult(intentDiscoverable, INDEX_DISCOVERABLE);
	    }
	    durationToLock /= QUANTUM_TO_LOCK;

		while (!mConfig[INDEX_DISCOVERABLE] && --durationToLock >= 0) {
			System.out.println("iter ["+durationToLock +"] mode ["+mBlueAdapter.getScanMode()+"]");
			mReceiver[INDEX_DISCOVERABLE].lock(QUANTUM_TO_LOCK);
		}
		return mConfig[INDEX_DISCOVERABLE];
    }

	public boolean discoverable()
	{
		return discoverable(0);
    }
}

class TBluetoothReceiver extends BroadcastReceiver
{
	public TWrapper w;
	public TBluetooth mTBluetooth;
	public int mIndex;
	public String mExpectedAction;
	public String mExpectedKey;
	public int mExpectedValue;
	public Vector<BluetoothDevice> maDevice;

	public TBluetoothReceiver(TWrapper w, int index)
	{
		this.w = w;
		mIndex = index;
		mTBluetooth = w.tBluetooth;
		mExpectedAction = mTBluetooth.mBtAction[mIndex];
		mExpectedKey = mTBluetooth.mBtKey[mIndex];
		mExpectedValue = mTBluetooth.mBtValue[mIndex];
	}

    public synchronized void lock(int milliToLock)
    {
    	try {
    		wait(milliToLock);
    	}
		catch (Exception e) {
			e.printStackTrace();
		}
    }

    public synchronized void unlock()
    {
    	notify();
    }

    public void onReceive(Context context, Intent intent)
    {
    	BluetoothDevice device = null;

        if (mIndex == TBluetooth.INDEX_BLUETOOTH) {
            device = intent.getParcelableExtra(mExpectedKey);
	    	mTBluetooth.mState[mIndex] = maDevice.size();
	    	mTBluetooth.mConfig[mIndex] = ( device != null );
        } else {
	    	mTBluetooth.mState[mIndex] = intent.getIntExtra(mExpectedKey, -1);
	    	mTBluetooth.mConfig[mIndex] = ( mTBluetooth.mState[mIndex] == mExpectedValue );
	    }
        if (device != null) {
            maDevice.add(device);
	    	mTBluetooth.mState[mIndex] += 1;
	    }
		System.out.println("key ["+ mExpectedKey + "] value ["+intent.getIntExtra(mExpectedKey, mExpectedValue - 1) +"] expected ["+mExpectedValue+"]");

        if (mTBluetooth.mConfig[mIndex]) {
			System.out.println("expected!");
        	unlock();
        }
    }
}
