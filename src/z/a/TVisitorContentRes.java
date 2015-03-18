package z.a;

import android.content.res.Configuration;
import android.content.res.Resources;
import android.graphics.drawable.Drawable;

public class TVisitorContentRes extends TVisitor
{
    public TVisitorContentRes(TWrapper w) {
        super(w);
    }

    //*******************************************************************************
    //**************************** Configuration ************************************
    //*******************************************************************************
    // float getFontScale()
    public long visit(TAlpha00 element, long a, long b, long c, long d, long e)
    {
        return Double.doubleToRawLongBits((double)((Configuration)w.sObject.get("" + a)).fontScale);
    }

    // int getScreenWidthDp()
    public long visit(TBeta00 element, long a, long b, long c, long d, long e)
    {
        return ((Configuration)w.sObject.get("" + a)).screenWidthDp;
    }

    // int getSmallestScreenWidthDp()
    public long visit(TGamma00 element, long a, long b, long c, long d, long e)
    {
        return ((Configuration)w.sObject.get("" + a)).smallestScreenWidthDp;
    }

    //*******************************************************************************
    //******************************* Resources *************************************
    //*******************************************************************************
    // DisplayMetrics* getDisplayMetrics()
    public long visit(TAlpha01 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put("" + b, ((Resources)w.sObject.get("" + a)).getDisplayMetrics());
        return 0;
    }

 // Configuration* getConfiguration()
    public long visit(TBeta01 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put("" + b, ((Resources)w.sObject.get("" + a)).getConfiguration());
        return 0;
    }

 // Drawable* getDrawable(int id)
    public long visit(TGamma01 element, long a, long b, long c, long d, long e)
    {
        Drawable ret = null;
        try {
            ret = ((Resources)w.sObject.get("" + a)).getDrawable((int)c);
            w.sObject.put("" + b, ret);
        }
        catch (Resources.NotFoundException vException) {
            if (w.doDebug) vException.printStackTrace();
            ret = null;
        }
        return ( ret == null ? 1 : 0 );
    }
}
