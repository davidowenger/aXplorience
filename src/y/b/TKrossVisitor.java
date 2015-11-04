package y.b;

public abstract class TKrossVisitor extends TVisitor implements INVisitor
{
    public long n;

    public TKrossVisitor(TWrapper w)
    {
        super(w);
    }

    public long nRun(TElement tElement)
    {
        return nRun(tElement, 0);
    }

    public long nRun(TElement tElement, Number a)
    {
        return nRun(tElement, a.longValue(), 0);
    }

    public long nRun(TElement tElement, Number a, Number b)
    {
        return nRun(tElement, a.longValue(), b.longValue(), 0);
    }

    public long nRun(TElement tElement, Number a, Number b, Number c)
    {
        return nRun(tElement, a.longValue(), b.longValue(), c.longValue(), 0);
    }

    public long nRun(TElement tElement, Number a, Number b, Number c, Number d)
    {
        return nRun(tElement, a.longValue(), b.longValue(), c.longValue(), d.longValue(), 0);
    }

    public long nRun(TElement tElement, Number a, Number b, Number c, Number d, Number e)
    {
        return nRun(this.n, tElement.n, a.longValue(), b.longValue(), c.longValue(), d.longValue(), e.longValue());
    }

    public native long nRun(long tVisitorN, long tElementN, long a, long b, long c, long d, long e);
}
