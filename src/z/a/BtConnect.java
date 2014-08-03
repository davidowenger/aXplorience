package z.a;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;

public class BtConnect extends Thread
{
	public TWrapper w;

	public BluetoothAdapter mBlueAdapter;
	public BluetoothSocket mmSocket;

    public BtConnect(TWrapper w, BluetoothDevice device)
    {
		this.w = w;
        mBlueAdapter = w.tBluetooth.mBlueAdapter;
        BluetoothSocket tmp = null;

        try {
            tmp = device.createInsecureRfcommSocketToServiceRecord(w.uuid);
        }
        catch (Exception e) {
        	tmp = null;
			e.printStackTrace();
        }
        mmSocket = tmp;
    }

    public void run()
    {
    	boolean connected = false;

        mBlueAdapter.cancelDiscovery();

        try {
            mmSocket.connect();
            connected = true;
            w.tCore.onClientHasServer(mmSocket);
        }
        catch (Exception e) {
			e.printStackTrace();
        }
        if (!connected) {
            try {
                mmSocket.close();
            }
            catch (Exception e) {
    			e.printStackTrace();
            }
        }
        System.out.println("Client has ended - was connected [" + (connected) + "]");
    }

    public void cancel()
    {
        try {
            mmSocket.close();
        }
        catch (Exception e) {
			e.printStackTrace();
        }
    }
}
