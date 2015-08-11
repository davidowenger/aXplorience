package y.b;

import android.os.ParcelUuid;

public class TVisitorOS extends TVisitor
{
    public TVisitorOS(TWrapper w) {
        super(w);
    }

    //*******************************************************************************
    //********************************* ParcelUuid **********************************
    //*******************************************************************************
    // String toString()
    public long visit(TAlpha00 element, long a, long b, long c, long d, long e)
    {
        return w.tFrame.putNext(((ParcelUuid)w.sObject.get(a)).toString());
    }
}
