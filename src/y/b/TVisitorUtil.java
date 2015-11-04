package y.b;

import android.util.DisplayMetrics;

public class TVisitorUtil extends TKrossVisitor
{
    public TVisitorUtil(TWrapper w) {
        super(w);
    }

    //*******************************************************************************
    //****************************** DisplayMetrics *********************************
    //*******************************************************************************
    // float getDensity()
    public long visit(TAlpha00 element, long a, long b, long c, long d, long e)
    {
        return Double.doubleToRawLongBits((double)((DisplayMetrics)w.sObject.get(a)).density);
    }
}
