package z.a;

public abstract class TVisitor implements ITVisitor
{
	public TWrapper w;
    public long n;

    public TVisitor(TWrapper w)
    {
    	this.w = w;
    }
}
