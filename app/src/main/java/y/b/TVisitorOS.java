package y.b;

import android.os.Looper;
import android.os.ParcelUuid;

public class TVisitorOS extends TKrossVisitor
{
    public TVisitorOS(TWrapper w) {
        super(w);
    }

    //*******************************************************************************
    //********************************* Looper **************************************
    //*******************************************************************************

    // static Looper* getMainLooper()
    public long visit(TGamma00 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.emplaceKey(a, Looper.getMainLooper());
    }

    // static void loop()
    public long visit(TDelta00 element, long a, long b, long c, long d, long e)
    {
        Looper.loop();
        return 0;
    }

    // static Looper* myLooper()
    public long visit(TEpsilon00 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.emplaceKey(a, Looper.myLooper());
    }

    // static void prepare()
    public long visit(TBeta00 element, long a, long b, long c, long d, long e)
    {
        Looper.prepare();
        return 0;
    }

    // void quit()
    public long visit(TDzeta00 element, long a, long b, long c, long d, long e)
    {
        ((Looper)w.sObject.get(a)).quit();
        return 0;
    }

    // void quitSafely()
    public long visit(TEta00 element, long a, long b, long c, long d, long e)
    {
        ((Looper)w.sObject.get(a)).quitSafely();
        return 0;
    }

    //*******************************************************************************
    //********************************* ParcelUuid **********************************
    //*******************************************************************************
    // String toString()
    public long visit(TAlpha00 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.putNext(((ParcelUuid)w.sObject.get(a)).toString());
    }
}
