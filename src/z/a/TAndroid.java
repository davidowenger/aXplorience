package z.a;

public class TAndroid extends TFrame
{
    public TAndroid(TWrapper w)
    {
    	super(w);
    }

    public void tInit()
    {
        w.context = w.tApp.getApplication();
    	w.cAPI = getAPINumber();

    	w.dbh = new DBHandler(w);
		w.tConfig = new TConfig(w);
        w.tBluetooth = new TBluetooth(w);
        w.tAppHandler = new TAppHandler(w);
    	w.tCore = new TCore(w);
		w.mac = w.tBluetooth.mac();

		w.tConfig.init();
		w.tBluetooth.init();
    	w.tCore.start();
    }

    public void tDestroy()
    {
    	w.tBluetooth.onDestroy();
    	w.tCore.cancel();
    }
}
