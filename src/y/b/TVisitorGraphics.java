package y.b;

import android.graphics.Typeface;
import android.graphics.drawable.ColorDrawable;
import android.graphics.drawable.Drawable;
import android.graphics.drawable.StateListDrawable;

public class TVisitorGraphics extends TVisitor
{
    public TVisitorGraphics(TWrapper w) {
        super(w);
    }


    //*******************************************************************************
    //******************************** Drawable *************************************
    //*******************************************************************************
    // int getIntrinsicHeight()
    public long visit(TDzeta00 element, long a, long b, long c, long d, long e)
    {
        return ((Drawable)w.sObject.get(a)).getIntrinsicHeight();
    }

    // int getIntrinsicWidth()
    public long visit(TEta00 element, long a, long b, long c, long d, long e)
    {
        return ((Drawable)w.sObject.get(a)).getIntrinsicHeight();
    }

    // void invalidateSelf()
    public long visit(TTheta00 element, long a, long b, long c, long d, long e)
    {
        ((Drawable)w.sObject.get(a)).invalidateSelf();
        return 0;
    }

    //*******************************************************************************
    //**************************** StateListDrawable ********************************
    //*******************************************************************************
    // StateListDrawable()
    public long visit(TAlpha00 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put(a, new StateListDrawable());
        return 0;
    }

    // void addState(vector<int> stateSet, Drawable* drawable)
    public long visit(TBeta00 element, long a, long b, long c, long d, long e)
    {
        ((StateListDrawable)w.sObject.get(a)).addState((int[])w.aObject.remove((int)b), w.tFrame.getValue(c, Drawable.class));
        return 0;
    }

    //*******************************************************************************
    //******************************** Typeface *************************************
    //*******************************************************************************
    // static Typeface* create(const String& familyName, int style)
    public long visit(TGamma00 element, long a, long b, long c, long d, long e)
    {
        return w.tFrame.putKey(a, Typeface.create((String)w.tFrame.nRunObject(b), (int)c));
    }

    // static Typeface* defaultFromStyle(int style)
    public long visit(TDelta00 element, long a, long b, long c, long d, long e)
    {
        return w.tFrame.putKey(a, Typeface.defaultFromStyle((int)b));
    }

    //*******************************************************************************
    //******************************** ColorDrawable ********************************
    //*******************************************************************************
    // ColorDrawable(int color)
    public long visit(TEpsilon00 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put(a, new ColorDrawable((int)b));
        return 0;
    }
}
