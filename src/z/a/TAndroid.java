package z.a;


public class TAndroid extends TFrame
{
    public TAndroid(TWrapper w)
    {
    	super(w);
    }

    public void tInit()
    {
        w.context = w.activity.getApplication();
    	w.cAPI = getAPINumber();
    	w.tConfig = new TConfig(w);
        w.tBluetooth = new TBluetooth(w);
    	w.tCore = new TCore(w);
    	w.tCore.start();
    }

    public void tDestroy()
    {
    	w.tBluetooth.onDestroy();
    }
}
