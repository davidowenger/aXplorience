package z.a;

import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;


public class TCore extends Thread
{
	public TWrapper w;

	public TCore(TWrapper w)
	{
		this.w = w;
	}

	public void run()
	{
        w.tBluetooth.init();
        w.tBluetooth.enable();

        if (w.cAPI >= 17) {
            w.tBluetooth.discoverable(10);
            System.out.println("Bluetooth is discoverable : " + w.tBluetooth.isDiscoverable());
            System.out.println("Timeout is : " + w.tBluetooth.getDiscoverableTimeout());
        	w.tBluetooth.server();
        } else {
        	w.tBluetooth.connect();
        }
        System.out.println("waiting for new message");

        String msg = "";

        while(true) {
        	if (w.tHandler.mMessage != msg) {
        		msg = w.tHandler.mMessage;
                System.out.println(msg);
        	}
        	try {
        		sleep(10000);
        	}
    		catch (Exception e) {
    			e.printStackTrace();
    		}
        }
	}

    public void onServerHasClient(BluetoothSocket blueSocket)
    {
        System.out.println("Sever has BluetoothSocket [" + (blueSocket != null) + "]");
        BluetoothDevice mClientDevice = blueSocket.getRemoteDevice();
        System.out.println("have BluetoothDevice - client address [" + mClientDevice.getAddress() + "]");

        BtConnected con = new BtConnected(w, blueSocket);
        con.start();
        int i = 0xFFFFFFFF;
        String msg = "Hello world !";

        while (true) {
        	msg = "Hello world ! " + ++i;
            con.write(msg.getBytes());

        	try {
        		sleep(10000);
        	}
    		catch (Exception e) {
    			e.printStackTrace();
    		}
        }
    }

    public void onClientHasServer(BluetoothSocket blueSocket)
    {
        System.out.println("Client has BluetoothSocket [" + (blueSocket != null) + "]");
        BluetoothDevice mServerDevice = blueSocket.getRemoteDevice();
        System.out.println("have BluetoothDevice - server address [" + mServerDevice.getAddress() + "]");

        BtConnected con = new BtConnected(w, blueSocket);
        con.start();

        while (true) {
        	try {
        		sleep(10000);
        	}
    		catch (Exception e) {
    			e.printStackTrace();
    		}
        }
    }
}
