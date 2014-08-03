package z.a;

import java.io.InputStream;
import java.io.OutputStream;

import android.bluetooth.BluetoothSocket;
import android.os.Handler;
import android.os.Message;

public class BtConnected extends Thread
{
	public TWrapper w;

    public Handler mHandler;
	public BluetoothSocket mmSocket;
	public InputStream mmInStream;
	public OutputStream mmOutStream;

    public BtConnected(TWrapper w, BluetoothSocket socket)
    {
        mmSocket = socket;
        InputStream tmpIn = null;
        OutputStream tmpOut = null;

        try {
            tmpIn = socket.getInputStream();
            tmpOut = socket.getOutputStream();
        }
        catch (Exception e) {
            tmpIn = null;
            tmpOut = null;
			e.printStackTrace();
        }
        mmInStream = tmpIn;
        mmOutStream = tmpOut;
    }

    public void run()
    {
        byte[] buffer = new byte[1024];
        int bytes;

        while (mmInStream != null) {
            try {
                bytes = mmInStream.read(buffer);
                Message.obtain(w.tHandler, THandler.MSG_READ, bytes, -1, buffer).sendToTarget();
            }
            catch (Exception e) {
            	mmInStream = null;
    			e.printStackTrace();
            }
        }
    }

    public void write(byte[] bytes)
    {
        try {
            mmOutStream.write(bytes);
        }
        catch (Exception e) {
			e.printStackTrace();
        }
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
