package y.b;

import android.util.DisplayMetrics;

import java.util.UUID;

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

    //*******************************************************************************
    //****************************** java.util.UUID *********************************
    //*******************************************************************************
    // static UUID randomUUID()
    public long visit(TBeta00 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.emplaceKey(a, UUID.randomUUID());
    }

    // string toString()
    public long visit(TGamma00 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.putNext(((UUID)w.sObject.get(a)).toString());
    }
}
