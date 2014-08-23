package z.a;

import java.util.UUID;

import android.bluetooth.BluetoothServerSocket;
import android.bluetooth.BluetoothSocket;

public class TServer extends Thread
{
	public TWrapper w;
	public UUID mUUID;
	public boolean mAlive;

	public TCore mCore;
	public BluetoothServerSocket mServerSocket;
	public BluetoothSocket mClientSocket;

	public TServer(TWrapper w, UUID uuid)
	{
		this.w = w;
		mUUID = uuid;
		mAlive = (w.cAPI >= 10);

		mCore = w.tCore;
    }

    public void run()
    {
        while (mAlive) {
        	mServerSocket = null;
	    	mClientSocket = null;

    		try {
	    		mServerSocket = w.tBluetooth.mBlueAdapter.listenUsingInsecureRfcommWithServiceRecord(w.serviceName, mUUID);

		        while (mClientSocket == null) {
		        	mClientSocket = mServerSocket.accept();
	            }
		        mServerSocket.close();
		        w.aTPeer.add(mCore.factoryTPeer(mClientSocket));
	        }
	        catch (Exception e) {
				e.printStackTrace();
	        }
        }
        System.out.println("BtServer thread ended - had client socket");
    }

    public void cancel()
    {
        try {
        	mAlive = false;
        	mServerSocket.close();
        }
        catch (Exception e) {
			e.printStackTrace();
        }
    }
}
