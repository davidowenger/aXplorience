package z.a;

import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.Vector;

import android.bluetooth.BluetoothSocket;

public class TPeerListener extends Thread
{
	public TWrapper w;

	public BluetoothSocket mPeerSocket;
	public InputStream mInStream;
	public OutputStream mOutStream;
	public Vector<String> maPacket;

	public boolean mAlive;

    public TPeerListener(TWrapper w, BluetoothSocket peerSocket)
    {
        mPeerSocket = peerSocket;

        try {
        	mInStream = mPeerSocket.getInputStream();
        	mOutStream = mPeerSocket.getOutputStream();
        }
        catch (Exception e) {
			e.printStackTrace();
        	mInStream = null;
        	mOutStream = null;
        }
    	maPacket = new Vector<String>();
        mAlive = (mInStream != null);
    }

    public void run()
    {
        byte[] buffer = new byte[1024];
        int bytes;

        while (mAlive) {
            try {
                bytes = mInStream.read(buffer);
                maPacket.add(new String(Arrays.copyOf(buffer, bytes)));
            }
            catch (Exception e) {
    			e.printStackTrace();
            	mAlive = false;
            }
        }
        cancel();
        System.out.println("TPeerListener thread ended");
    }

    public void write(String packet)
    {
        try {
            mOutStream.write(packet.getBytes());
        }
        catch (Exception e) {
			e.printStackTrace();
            cancel();
        }
    }

    public void cancel()
    {
        try {
        	mAlive = false;
        	mInStream = null;
            mPeerSocket.close();
        }
        catch (Exception e) {
			e.printStackTrace();
        }
    }
}
