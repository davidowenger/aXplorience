package nclozer.tnamespace;

import android.view.View;
import android.widget.LinearLayout;

abstract public class TView extends View
{
	public TWrapper w;
	
    public TView(TWrapper w) {
    	super(w.context);
    	this.w = w;
    }

    abstract public View 	convert();
    
    public long callLong(TElement tElement) {
    	return callLong(tElement.n);
    }

    public Object callObject(TElement tElement) {
    	return callObject(tElement.n);
    }

	public native long 		callLong(long nElement);
	public native Object    callObject(long nElement);
}

class TLinearLayout extends TView
{
    public TLinearLayout(TWrapper w) {
    	super(w);
    }

    public View convert() {
		return new LinearLayout(w.context);
    }
}
