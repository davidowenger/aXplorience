package z.a;

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
    
    public long tRunLong(TElement tElement) {
    	return nRunLong(tElement.n);
    }

    public Object tRunObject(TElement tElement) {
    	return nRunObject(tElement.n);
    }

	public native long 		nRunLong(long nElement);
	public native Object    nRunObject(long nElement);
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
