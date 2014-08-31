package z.a;

import java.io.IOException;
import java.util.UUID;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothServerSocket;
import android.bluetooth.BluetoothSocket;
import android.content.Intent;

public class TVisitorBluetooth extends TVisitor
{
	public TVisitorBluetooth(TWrapper w) {
		super(w);
	}

	//*******************************************************************************
	//**************************** BluetoothAdapter *********************************
	//*******************************************************************************

    //static BluetoothAdapter* getDefaultAdapter()
	public long visit(TAlpha00 element, long a, long b, long c, long d)
	{
		w.sObject.put("" + a, BluetoothAdapter.getDefaultAdapter());
		return 0;
	}

	//BluetoothDevice* getRemoteDevice(String address)
	public long visit(TBeta00 element, long a, long b, long c, long d)
	{
		w.sObject.put("" + b, ((BluetoothAdapter)w.sObject.get("" + a)).getRemoteDevice((String)w.tFrame.nRunObject(c)));
		return 0;
	}

	//bool isEnabled()
	public long visit(TGamma00 element, long a, long b, long c, long d)
    {
		return ( ((BluetoothAdapter)w.sObject.get("" + a)).isEnabled() ? 1 : 0 );
    }

	//int getState()
	public long visit(TDelta00 element, long a, long b, long c, long d)
    {
		return ((BluetoothAdapter)w.sObject.get("" + a)).getState();
    }

	//bool enable()
	public long visit(TEpsilon00 element, long a, long b, long c, long d)
    {
		return ( ((BluetoothAdapter)w.sObject.get("" + a)).enable() ? 1 : 0 );
    }

	//bool disable()
	public long visit(TDzeta00 element, long a, long b, long c, long d)
    {
		return ( ((BluetoothAdapter)w.sObject.get("" + a)).disable() ? 1 : 0 );
    }

    //String getAddress()
	public long visit(TEta00 element, long a, long b, long c, long d)
    {
		Object o = ((BluetoothAdapter)w.sObject.get("" + a)).getAddress();
		w.aObject.add(o);
		return w.aObject.lastIndexOf(o);
    }

    //String getName()
	public long visit(TTheta00 element, long a, long b, long c, long d)
    {
		Object o = ((BluetoothAdapter)w.sObject.get("" + a)).getName();
		w.aObject.add(o);
		return w.aObject.lastIndexOf(o);
    }

    //bool setName(String name)
	public long visit(TIota00 element, long a, long b, long c, long d)
    {
		return ( ((BluetoothAdapter)w.sObject.get("" + a)).setName((String)w.tFrame.nRunObject(b)) ? 1 : 0 );
    }

    //int getScanMode()
	public long visit(TKappa00 element, long a, long b, long c, long d)
    {
		return ((BluetoothAdapter)w.sObject.get("" + a)).getScanMode();
    }

    //bool startDiscovery()
	public long visit(TLambda00 element, long a, long b, long c, long d)
    {
		return ( ((BluetoothAdapter)w.sObject.get("" + a)).startDiscovery() ? 1 : 0 );
    }

    //bool cancelDiscovery()
	public long visit(TMu00 element, long a, long b, long c, long d)
    {
		return ( ((BluetoothAdapter)w.sObject.get("" + a)).cancelDiscovery() ? 1 : 0 );
    }

    //bool isDiscovering()
	public long visit(TNu00 element, long a, long b, long c, long d)
    {
		return ( ((BluetoothAdapter)w.sObject.get("" + a)).isDiscovering() ? 1 : 0 );
    }

    //Set<BluetoothDevice> getBondedDevices()
	public long visit(TXi00 element, long a, long b, long c, long d)
	{
		//TODO: implements
		//w.sObject.put("" + b, ((BluetoothAdapter)w.sObject.get("" + a)).getBondedDevices());
		return 0;
	}

	//BluetoothServerSocket* listenUsingRfcommWithServiceRecord(String name, String uuid)
	public long visit(TOmicron00 element, long a, long b, long c, long d)
    {
		BluetoothServerSocket ret;
		try {
			ret = ((BluetoothAdapter)w.sObject.get("" + a)).listenUsingRfcommWithServiceRecord((String)w.tFrame.nRunObject(c), UUID.fromString((String)w.tFrame.nRunObject(d)));
			w.sObject.put("" + b, ret);
		}
		catch (IOException e) {
			if (w.doDebug) e.printStackTrace();
			ret = null;
		}
		return ( ret == null ? 1 : 0 );
    }

	//BluetoothServerSocket* listenUsingRfcommWithServiceRecord(String name, String uuid)
	public long visit(TPi00 element, long a, long b, long c, long d)
    {
		BluetoothServerSocket ret;
		try {
			ret = ((BluetoothAdapter)w.sObject.get("" + a)).listenUsingInsecureRfcommWithServiceRecord((String)w.tFrame.nRunObject(c), UUID.fromString((String)w.tFrame.nRunObject(d)));
			w.sObject.put("" + b, ret);
		}
		catch (IOException e) {
			if (w.doDebug) e.printStackTrace();
			ret = null;
		}
		return ( ret == null ? 1 : 0 );
    }

    //static bool checkBluetoothAddress(String address)
	public long visit(TRho00 element, long a, long b, long c, long d)
    {
		return ( BluetoothAdapter.checkBluetoothAddress((String)w.tFrame.nRunObject(a)) ? 1 : 0 );
    }

    //void discoverable(int nTimeout)
	public long visit(TSigma00 element, long a, long b, long c, long d)
	{
		Intent intentDiscoverable = new Intent(BluetoothAdapter.ACTION_REQUEST_DISCOVERABLE);
		intentDiscoverable.putExtra(BluetoothAdapter.EXTRA_DISCOVERABLE_DURATION, a);
    	w.tActivity.startActivityForResult(intentDiscoverable, 1);
		return 0;
	}

	//*******************************************************************************
	//***************************** BluetoothDevice *********************************
	//*******************************************************************************

	//bool equals(BluetoothDevice* dBluetoothDevice);
	public long visit(TAlpha01 element, long a, long b, long c, long d)
    {
		return ( ((BluetoothDevice)w.sObject.get("" + a)).equals((BluetoothDevice)w.sObject.get("" + b)) ? 1 : 0 );
    }

	//int hashCode();
	public long visit(TBeta01 element, long a, long b, long c, long d)
    {
		return ((BluetoothDevice)w.sObject.get("" + a)).hashCode();
    }

	//String toString();
	public long visit(TGamma01 element, long a, long b, long c, long d)
    {
		Object o = ((BluetoothDevice)w.sObject.get("" + a)).toString();
		w.aObject.add(o);
		return w.aObject.lastIndexOf(o);
    }

	//int describeContents();
	public long visit(TDelta01 element, long a, long b, long c, long d)
    {
		return ((BluetoothDevice)w.sObject.get("" + a)).describeContents();
    }

	//void writeToParcel(void* out, int flags);
	public long visit(TEpsilon01 element, long a, long b, long c, long d)
    {
		//TODO: implements
		return 0;
    }

	//String getAddress();
	public long visit(TDzeta01 element, long a, long b, long c, long d)
    {
		Object o = ((BluetoothDevice)w.sObject.get("" + a)).getAddress();
		w.aObject.add(o);
		return w.aObject.lastIndexOf(o);
    }

	//String getName();
	public long visit(TEta01 element, long a, long b, long c, long d)
    {
		Object o = ((BluetoothDevice)w.sObject.get("" + a)).getName();
		w.aObject.add(o);
		return w.aObject.lastIndexOf(o);
    }

	//int getBondState();
	public long visit(TTheta01 element, long a, long b, long c, long d)
    {
		return ((BluetoothDevice)w.sObject.get("" + a)).getBondState();
    }

	//BluetoothClass* getBluetoothClass();
	public long visit(TIota01 element, long a, long b, long c, long d)
    {
		w.sObject.put("" + b, ((BluetoothDevice)w.sObject.get("" + a)).getBluetoothClass());
		return 0;
    }

	//BluetoothSocket* createRfcommSocketToServiceRecord(const String& uuid);
	public long visit(TKappa01 element, long a, long b, long c, long d)
	{
		BluetoothSocket ret;
		try {
			ret = ((BluetoothDevice)w.sObject.get("" + a)).createRfcommSocketToServiceRecord(UUID.fromString((String)w.tFrame.nRunObject(d)));
			w.sObject.put("" + b, ret);
		}
		catch (IOException e) {
			if (w.doDebug) e.printStackTrace();
			ret = null;
		}
		return ( ret == null ? 1 : 0 );
	}

	//BluetoothSocket* createInsecureRfcommSocketToServiceRecord(const String& uuid);
	public long visit(TLambda01 element, long a, long b, long c, long d)
	{
		BluetoothSocket ret;
		try {
			ret = ((BluetoothDevice)w.sObject.get("" + a)).createInsecureRfcommSocketToServiceRecord(UUID.fromString((String)w.tFrame.nRunObject(d)));
			w.sObject.put("" + b, ret);
		}
		catch (IOException e) {
			if (w.doDebug) e.printStackTrace();
			ret = null;
		}
		return ( ret == null ? 1 : 0 );
	}

	//*******************************************************************************
	//************************* BluetoothServerSocket *******************************
	//*******************************************************************************

	//BluetoothSocket* accept();
	public long visit(TAlpha02 element, long a, long b, long c, long d)
	{
		BluetoothSocket ret;
		try {
			ret = ((BluetoothServerSocket)w.sObject.get("" + a)).accept();
			w.sObject.put("" + b, ret);
		}
		catch (IOException e) {
			if (w.doDebug) e.printStackTrace();
			ret = null;
		}
		return ( ret == null ? 1 : 0 );
	}

	//BluetoothSocket* accept(int timeout);
	public long visit(TBeta02 element, long a, long b, long c, long d)
	{
		BluetoothSocket ret;
		try {
			ret = ((BluetoothServerSocket)w.sObject.get("" + a)).accept((int)c);
			w.sObject.put("" + b, ret);
		}
		catch (IOException e) {
			if (w.doDebug) e.printStackTrace();
			ret = null;
		}
		return ( ret == null ? 1 : 0 );
	}

	//void close();
	public long visit(TGamma02 element, long a, long b, long c, long d)
	{
		long err = 0;
		try {
			((BluetoothServerSocket)w.sObject.get("" + a)).close();
		}
		catch (IOException e) {
			if (w.doDebug) e.printStackTrace();
			err = 1;
		}
		return err;
	}

	//*******************************************************************************
	//***************************** BluetoothSocket *********************************
	//*******************************************************************************

    //void connect()
	public long visit(TAlpha03 element, long a, long b, long c, long d)
	{
		long err = 0;
		try {
			((BluetoothSocket)w.sObject.get("" + a)).connect();
		}
		catch (IOException e) {
			if (w.doDebug) e.printStackTrace();
			err = 1;
		}
		return err;
	}

	//void close()
	public long visit(TBeta03 element, long a, long b, long c, long d)
	{
		long err = 0;
		try {
			((BluetoothSocket)w.sObject.get("" + a)).close();
		}
		catch (IOException e) {
			if (w.doDebug) e.printStackTrace();
			err = 1;
		}
		return err;
	}

    //BluetoothDevice* getRemoteDevice()
	public long visit(TGamma03 element, long a, long b, long c, long d)
    {
		w.sObject.put("" + b, ((BluetoothSocket)w.sObject.get("" + a)).getRemoteDevice());
		return 0;
    }

	//InputStream* getInputStream()
	public long visit(TDelta03 element, long a, long b, long c, long d)
    {
		long err = 0;
		try {
			w.sObject.put("" + b, ((BluetoothSocket)w.sObject.get("" + a)).getInputStream());
		}
		catch (IOException e) {
			if (w.doDebug) e.printStackTrace();
			err = 1;
		}
		return err;
    }

	//OutputStream* getOutputStream()
	public long visit(TEpsilon03 element, long a, long b, long c, long d)
    {
		long err = 0;
		try {
			w.sObject.put("" + b, ((BluetoothSocket)w.sObject.get("" + a)).getOutputStream());
		}
		catch (IOException e) {
			if (w.doDebug) e.printStackTrace();
			err = 1;
		}
		return err;
    }
}
