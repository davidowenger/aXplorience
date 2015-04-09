package z.a;

public abstract class TFrame extends TVisitor
{
    public TFrame(TWrapper w) {
    	super(w);
    }

    public abstract void tInit();

    public native long nInit(long cState);
    public native long nCancel();
}
