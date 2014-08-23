package z.a;

import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.util.UUID;

import android.Manifest;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.Build.VERSION_CODES;

public class TBluetooth
{
	public final int QUANTUM_TO_LOCK = 100;

	public final int INDEX_ENABLED = 0; // CONFIG_RUN
	public final int INDEX_DISCOVERABLE = INDEX_ENABLED + 1; // CONFIG_ALLOW_DISCOVERABLE_MODE
	public final int INDEX_CONNECTED = INDEX_DISCOVERABLE + 1; //
	public final int INDEX_TIMEOUT = INDEX_CONNECTED + 1; // CONFIG_ALLOW_MAX_TIMEOUT
	public final int INDEX_BLUETOOTH = INDEX_TIMEOUT + 1; // CONFIG_AUTO_ENABLE_BT
	public final int INDEX_LEGACY = INDEX_BLUETOOTH + 1; // CONFIG_ALLOW_LEGACY

	public TWrapper w;

	public boolean mHasBluetooth;
	public boolean mHasProxy;
	public boolean mIsSystem;

	public String mMac;
	public TConfig mPrefs;
	public int[] mState;
	public boolean[] mConfig;
	public boolean[] mSaved;

	public BluetoothAdapter mBlueAdapter;
	public TBluetoothReceiver[] mReceiver;
	public int mcDiscoveredDevice;

	public Object mBlueProxy;
	public Method mMEnable;
	public Method mMSetDiscoverableTimeout;
	public Method mMgetDiscoverableTimeout;
	public Method mMSetScanMode;

	public String[] mBtAction;
	public String[] mBtKey;
	public int[] mBtValue;

	public TBluetooth(TWrapper w)
	{
		this.w = w;
		mPrefs = w.tConfig;

    	mcDiscoveredDevice = 0;
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
			0,
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
		w.tApp.unregisterReceiver(mReceiver[INDEX_ENABLED]);
		w.tApp.unregisterReceiver(mReceiver[INDEX_DISCOVERABLE]);
		w.tApp.unregisterReceiver(mReceiver[INDEX_CONNECTED]);
		w.tApp.unregisterReceiver(mReceiver[INDEX_TIMEOUT]);
		w.tApp.unregisterReceiver(mReceiver[INDEX_BLUETOOTH]);
    }

	public String mac()
	{
		String mac = "";

		if (mHasBluetooth) {
			mac = mBlueAdapter.getAddress();
		}
	    return mac;
    }

	public boolean isEnabled()
	{
		boolean ret = false;

		if (mHasBluetooth) {
			ret = mBlueAdapter.isEnabled();
		}
	    return ret;
    }

	public boolean isDiscoverable()
	{
	    return (isEnabled() && (mBlueAdapter.getScanMode() == mBtValue[INDEX_DISCOVERABLE]));
    }

	public void init()
	{
		mPrefs.setb(INDEX_ENABLED, true);
		mPrefs.setb(INDEX_DISCOVERABLE, true);
		mPrefs.setb(INDEX_TIMEOUT, true);
		mPrefs.setb(INDEX_BLUETOOTH, true);
		mPrefs.setb(INDEX_LEGACY, true);

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
		w.tApp.registerReceiver(receiver, new IntentFilter(mBtAction[index]));
		return receiver;
	}

	public boolean isConnected()
	{
	    return false;
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
	    if (!done && isEnabled()) {
			Intent intentDiscoverable = new Intent(BluetoothAdapter.ACTION_REQUEST_DISCOVERABLE);
			intentDiscoverable.putExtra(BluetoothAdapter.EXTRA_DISCOVERABLE_DURATION, getPreferedTimeout());
	    	w.tApp.startActivityForResult(intentDiscoverable, INDEX_DISCOVERABLE);
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

	public void startDiscovery()
	{
		if (isEnabled()) {
			mBlueAdapter.startDiscovery();
	    }
	}

	public void cancelDiscovery()
	{
		if (isEnabled()) {
			mBlueAdapter.cancelDiscovery();
	    }
	}

	public boolean discover(int durationToLock)
	{
	    durationToLock /= QUANTUM_TO_LOCK;

		while (isEnabled() && mcDiscoveredDevice == mState[INDEX_BLUETOOTH] && --durationToLock >= 0 && mBlueAdapter.isDiscovering()) {
			mReceiver[INDEX_BLUETOOTH].lock(QUANTUM_TO_LOCK);
		}
		mConfig[INDEX_BLUETOOTH] = (mcDiscoveredDevice < mState[INDEX_BLUETOOTH]);
		mcDiscoveredDevice = mState[INDEX_BLUETOOTH];

		return mConfig[INDEX_BLUETOOTH];
	}

	public boolean discover()
	{
		return discover(0);
	}

	public BluetoothSocket connect(BluetoothDevice device, UUID uuid)
	{
		BluetoothSocket clientSocket = null;
		try {
			clientSocket = device.createInsecureRfcommSocketToServiceRecord(uuid);
			clientSocket.connect();
			//00001101-0000-1000-8000-00805F9B34FB
			//tmp = mDevice.createRfcommSocketToServiceRecord(MY_UUID);
			//Method m = mDevice.getClass().getMethod("createRfcommSocket", new Class[] {int.class});
			//tmp = (BluetoothSocket) m.invoke(mDevice, 1);
    	}
        catch (Exception e) {
			e.printStackTrace();
			clientSocket = close(clientSocket);;
        }
		return clientSocket;
	}

	public BluetoothSocket close(BluetoothSocket peerSocket)
	{
        try {
        	peerSocket.close();
        }
        catch (Exception e) {
        }
        return null;
	}
}

class TBluetoothReceiver extends BroadcastReceiver
{
	public TWrapper w;

	public int mIndex;
	public String mExpectedAction;
	public String mExpectedKey;
	public int mExpectedValue;

	public TBluetoothReceiver(TWrapper w, int index)
	{
		this.w = w;
		mIndex = index;
		mExpectedAction = w.tBluetooth.mBtAction[mIndex];
		mExpectedKey = w.tBluetooth.mBtKey[mIndex];
		mExpectedValue = w.tBluetooth.mBtValue[mIndex];
	}

	public synchronized void lock(int durationToLock)
	{
    	try {
    		wait(durationToLock);
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

		System.out.println("key ["+ mExpectedKey + "] expected ["+mExpectedValue+"]");

        if (mIndex == w.tBluetooth.INDEX_BLUETOOTH) {
            device = intent.getParcelableExtra(mExpectedKey);
	        System.out.println("extra parcel ok [" + (intent.getParcelableExtra(mExpectedKey) != null) + "]");
        } else {
	    	w.tBluetooth.mState[mIndex] = intent.getIntExtra(mExpectedKey, -1);
	    	w.tBluetooth.mConfig[mIndex] = ( w.tBluetooth.mState[mIndex] == mExpectedValue );
	        System.out.println("value ["+intent.getIntExtra(mExpectedKey, -1) +"] ");
	    }
        if (device != null) {
            w.aDiscoveredDevice.add(device);
        	w.tBluetooth.mState[mIndex] = w.aDiscoveredDevice.size();
	    }
        if (device != null || w.tBluetooth.mConfig[mIndex]) {
			System.out.println("expected!");
			unlock();
        }
    }
}
