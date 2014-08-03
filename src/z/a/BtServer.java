package z.a;

import android.bluetooth.BluetoothServerSocket;
import android.bluetooth.BluetoothSocket;

public class BtServer extends Thread
{
	public TWrapper w;

	public BluetoothServerSocket blueServerSocket;

	public BtServer(TWrapper w)
	{
		this.w = w;
        BluetoothServerSocket tmp = null;

    	if (w.cAPI >= 10) {
    		try {
                tmp = w.tBluetooth.mBlueAdapter.listenUsingInsecureRfcommWithServiceRecord(w.serviceName, w.uuid);
        	}
            catch (Exception e) {
            	tmp = null;
				e.printStackTrace();
            }
    	}
        blueServerSocket = tmp;
    }

    public void run()
    {
        BluetoothSocket blueSocket = null;

        try {
	        while (blueServerSocket != null) {
	            blueSocket = blueServerSocket.accept();

	            if (blueSocket != null) {
	            	w.tCore.onServerHasClient(blueSocket);
	            	blueServerSocket.close();
	            	blueServerSocket = null;
	            }
	        }
        }
        catch (Exception e) {
			e.printStackTrace();
        }
        System.out.println("BtServer thread ended - had BluetoothSocket [" + (blueSocket != null) + "]");
    }

    public void cancel()
    {
        try {
            blueServerSocket.close();
        }
        catch (Exception e) {
			e.printStackTrace();
        }
    }
}
