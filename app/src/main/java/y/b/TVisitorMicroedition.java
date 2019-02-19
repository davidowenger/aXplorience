package y.b;

public class TVisitorMicroedition extends TKrossVisitor
{
    public TVisitorMicroedition(TWrapper w) {
        super(w);
    }

    //*******************************************************************************
    //**************************** EGLSurface ***************************************
    //*******************************************************************************
    // EGLSurface()
    public long visit(TAlpha00 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put(a, new TEGLSurface());
        return 0;
    }
}
