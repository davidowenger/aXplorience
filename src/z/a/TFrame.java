package z.a;

import java.util.Hashtable;
import java.util.Iterator;
import java.util.Map.Entry;

public abstract class TFrame extends TVisitor
{
	public static final int GET_W = 0;
	public static final int GET_ELEMENT = GET_W + 1;
	public static final int GET_VISITOR = GET_ELEMENT + 1;

    public TFrame(TWrapper w) {
    	super(w);
    }

    public abstract void tInit();

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

    // Native
    public native long nInit(long nWrapper, int cState);
}
