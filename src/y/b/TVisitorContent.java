package y.b;

import android.content.Context;
import android.content.ContextWrapper;

public class TVisitorContent extends TVisitor
{
    public TVisitorContent(TWrapper w) {
        super(w);
    }

    //*******************************************************************************
    //**************************** Context ******************************************
    //*******************************************************************************
    //  Context* getApplicationContext()
    public long visit(TAlpha00 element, long a, long b, long c, long d, long e)
    {
        return w.tFrame.emplaceKey(b, ((Context)w.sObject.get(a)).getApplicationContext());
    }

    // Object* getSystemService(const String& name)
    public long visit(TGamma00 element, long a, long b, long c, long d, long e)
    {
        return w.tFrame.emplaceKey(b, ((Context)w.sObject.get(a)).getSystemService((String)w.tFrame.nRunObject(c)));
    }

    //*******************************************************************************
    //**************************** ContextWrapper ***********************************
    //*******************************************************************************
    // Resources* getResources()
    public long visit(TBeta00 element, long a, long b, long c, long d, long e)
    {
        return w.tFrame.emplaceKey(b, ((ContextWrapper)w.sObject.get(a)).getResources());
    }
}
