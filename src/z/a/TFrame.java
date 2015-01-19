package z.a;

import java.util.Hashtable;
import java.util.Iterator;
import java.util.Map.Entry;

import android.content.Context;
import android.content.pm.PackageManager;
import android.os.Build.VERSION;

public abstract class TFrame extends TVisitor
{
	public static final int GET_W = 0;
	public static final int GET_ELEMENT = GET_W + 1;
	public static final int GET_VISITOR = GET_ELEMENT + 1;

    public TFrame(TWrapper w) {
    	super(w);
    }

    public abstract void tInit();
    public abstract void tDestroy();

	public int getAPINumber()
	{
		int ret = VERSION.SDK_INT;
//		String sSDK = VERSION.SDK;
//
//		if (sSDK.equals("BASE")) {
//			ret = 1;
//		} else if (sSDK.equals("BASE_1_1")) {
//			ret = 2;
//		} else if (sSDK.equals("CUPCAKE")) {
//			ret = 3;
//		}
        return ret;
	}

	public boolean hasRight(String permission)
	{
		Context c = w.context;
		int res = c.getPackageManager().checkPermission(permission, c.getPackageName());
		boolean ret = (res == PackageManager.PERMISSION_GRANTED);
		return ret;
	}

    public String search(Hashtable<String, Object> table, Object value)
    {
    	Iterator<Entry<String, Object>> it = table.entrySet().iterator();
    	String key = null;

    	while (key == null && it.hasNext()) {
    		Entry<String, Object> entry = it.next();
    		if (entry.getValue() == value) {
    			key = entry.getKey();
    		}
    	}
    	return key;
	}
	//return Long.parseLong(search(w.vObject, w.vObject.get("" + a)));

    public Object tGetService(Object o) {
    	return nGetService(o);
    }

    // Native
    public native long nInit(long nWrapper, int cState);
    public native Object nGetService(Object mIBluetoothProxy);
}
