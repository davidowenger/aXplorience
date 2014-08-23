package z.a;

abstract public class TElement
{
	public static int counter = 0;

	public int i;
	public long n;

	public TElement()
	{
		this.i = counter++;
	}

	abstract public long accept(TVisitor visitor, long a, long b, long c);
}
