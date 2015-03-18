package z.a;

import android.graphics.Typeface;
import android.graphics.drawable.Drawable;
import android.graphics.drawable.StateListDrawable;

public class TVisitorGraphics extends TVisitor
{
	public TVisitorGraphics(TWrapper w) {
		super(w);
	}

	//*******************************************************************************
	//**************************** StateListDrawable ********************************
	//*******************************************************************************
    // StateListDrawable()
	public long visit(TAlpha00 element, long a, long b, long c, long d, long e)
	{
        w.sObject.put("" + a, new StateListDrawable());
        return 0;
	}

    // void addState(vector<int> stateSet, Drawable* drawable)
	public long visit(TBeta00 element, long a, long b, long c, long d, long e)
	{
		((StateListDrawable)w.sObject.get("" + a)).addState((int[])w.aObject.remove("" + b), (Drawable)w.sObject.get("" + c));
		return 0;
	}

    //*******************************************************************************
    //******************************** Typeface *************************************
    //*******************************************************************************
    // static Typeface* create(const String& familyName, int style)
    public long visit(TAlpha01 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put("" + a, Typeface.create((String)w.tFrame.nRunObject(b), (int)c));
        return 0;
    }

    // static Typeface* defaultFromStyle(int style)
    public long visit(TBeta01 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put("" + a, Typeface.defaultFromStyle((int)c));
        return 0;
    }
}
