package y.b;

import android.app.ActionBar;
import android.graphics.drawable.Drawable;

public class TVisitorApp extends TKrossVisitor
{
    public TVisitorApp(TWrapper w) {
        super(w);
    }

    //*******************************************************************************
    //**************************** ActionBar ****************************************
    //*******************************************************************************

    // void setIcon(Drawable* icon)
    public long visit(TAlpha00 element, long a, long b, long c, long d, long e)
    {
        ((ActionBar)w.sObject.get(a)).setIcon(w.mTKrossSystem.getValue(b, Drawable.class));
        return 0;
    }

    // void setDisplayHomeAsUpEnabled(bool showHomeAsUp)
    public long visit(TBeta00 element, long a, long b, long c, long d, long e)
    {
        ((ActionBar)w.sObject.get(a)).setDisplayHomeAsUpEnabled(b != 0);
        return 0;
    }

    // void setHomeButtonEnabled(bool enabled)
    public long visit(TGamma00 element, long a, long b, long c, long d, long e)
    {
        ((ActionBar)w.sObject.get(a)).setHomeButtonEnabled(b != 0);
        return 0;
    }
}
