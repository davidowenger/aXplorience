package z.a;

import java.util.Arrays;

import android.os.Handler;
import android.os.Looper;
import android.os.Message;

public class THandle extends Thread
{
	public Looper mLooper;

	public TWrapper w;

	public THandle(TWrapper w)
	{
		this.w = w;
	}

	public void run()
	{
        Looper.prepare();
        mLooper = Looper.myLooper();
        w.tHandler = new THandler();
        Looper.loop();
        System.out.println("Handler stopped");
	}
}


class THandler extends Handler
{
	public static final int MSG_READ = 0;

	public String mMessage = "BEGIN:";

	public void handleMessage(Message msg)
	{
		int bytes = msg.arg1;
        byte[] buffer = (byte[])msg.obj;
        mMessage += new String(Arrays.copyOf(buffer, bytes));
	}
}
