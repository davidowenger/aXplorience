package z.a;

import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;

public class TPeer extends Thread
{
	public TWrapper w;
	public TPeerListener mTPeerListener;
	public BluetoothSocket mPeerSocket;
	public BluetoothDevice mPeerDevice;
	public DBTableHandler mDropHandler;
	public int mcProcessedPacket;

	public boolean mAlive;

	public TPeer(TWrapper w, TPeerListener tPeerListener)
	{
		this.w = w;
		mTPeerListener = tPeerListener;
		mPeerSocket = mTPeerListener.mPeerSocket;
		mcProcessedPacket = 0;
	    mAlive = true;
	    mDropHandler = w.dbh.get("Drop");
	}

	public void run()
	{
		mPeerDevice = mPeerSocket.getRemoteDevice();
        System.out.println("have BluetoothDevice - peer address [" + mPeerDevice.getAddress() + "]");

        for (BO_Drop b : w.aBOSeed) {
        	mTPeerListener.write(b.pack());
        }
        while (mAlive && mTPeerListener.mAlive) {
        	if (mTPeerListener.maPacket.size() > mcProcessedPacket) {
        		drop(mTPeerListener.maPacket.elementAt(mcProcessedPacket));
        		mcProcessedPacket++;
        	}
        	try {
        		Thread.sleep(300);
        	}
    		catch (Exception e) {
    			e.printStackTrace();
    		}
        }
        mTPeerListener.cancel();
	}

    public void drop(String packet)
    {
    	BO_Drop boDrop = w.boSeed.unpack(packet);
    	w.aBODrop.add(boDrop);
    	w.tAppHandler.obtainMessage(w.tAppHandler.DROP_RECEIVED, -1, -1, boDrop).sendToTarget();
    }

    public void cancel()
    {
    	mTPeerListener.cancel();
    	mAlive = false;
    }
}
