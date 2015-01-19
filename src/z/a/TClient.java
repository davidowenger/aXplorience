package z.a;

public class TClient extends Thread
{
	public TWrapper w;

	public boolean mAlive;

    public TClient(TWrapper w)
    {
		this.w = w;
		mAlive = true;
    }

    public void run()
    {
    	while (mAlive) {
	    	w.tBluetooth.startDiscovery();

	    	try {
	    		sleep(10000);
	    	}
			catch (Exception e) {
				//e.printStackTrace();
			}
	    	w.tBluetooth.cancelDiscovery();

	     	try {
	     		sleep(50000);
	     	}
	 		catch (Exception e) {
	 			//e.printStackTrace();
	 		}
    	}
    }

    public void cancel()
    {
    	mAlive = false;
    }
}
