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

class TAlpha extends TElement
{
	public long accept(TVisitor visitor, long a, long b, long c)
	{
		return visitor.visit(this, a, b, c);
	}
}

class TBeta extends TElement
{
	public long accept(TVisitor visitor, long a, long b, long c)
	{
		return visitor.visit(this, a, b, c);
	}
}

class TGamma extends TElement
{
	public long accept(TVisitor visitor, long a, long b, long c)
	{
		return visitor.visit(this, a, b, c);
	}
}

class TDelta extends TElement
{
	public long accept(TVisitor visitor, long a, long b, long c)
	{
		return visitor.visit(this, a, b, c);
	}
}

class TEpsilon extends TElement
{
	public long accept(TVisitor visitor, long a, long b, long c)
	{
		return visitor.visit(this, a, b, c);
	}
}

class TDzeta extends TElement
{
	public long accept(TVisitor visitor, long a, long b, long c)
	{
		return visitor.visit(this, a, b, c);
	}
}

class TEta extends TElement
{
	public long accept(TVisitor visitor, long a, long b, long c)
	{
		return visitor.visit(this, a, b, c);
	}
}

class TTheta extends TElement
{
	public long accept(TVisitor visitor, long a, long b, long c)
	{
		return visitor.visit(this, a, b, c);
	}
}

class TIota extends TElement
{
	public long accept(TVisitor visitor, long a, long b, long c)
	{
		return visitor.visit(this, a, b, c);
	}
}

class TKappa extends TElement
{
	public long accept(TVisitor visitor, long a, long b, long c)
	{
		return visitor.visit(this, a, b, c);
	}
}

class TLambda extends TElement
{
	public long accept(TVisitor visitor, long a, long b, long c)
	{
		return visitor.visit(this, a, b, c);
	}
}

class TMu extends TElement
{
	public long accept(TVisitor visitor, long a, long b, long c)
	{
		return visitor.visit(this, a, b, c);
	}
}

class TNu extends TElement
{
	public long accept(TVisitor visitor, long a, long b, long c)
	{
		return visitor.visit(this, a, b, c);
	}
}

class TXi extends TElement
{
	public long accept(TVisitor visitor, long a, long b, long c)
	{
		return visitor.visit(this, a, b, c);
	}
}

class TOmicron extends TElement
{
	public long accept(TVisitor visitor, long a, long b, long c)
	{
		return visitor.visit(this, a, b, c);
	}
}

class TPi extends TElement
{
	public long accept(TVisitor visitor, long a, long b, long c)
	{
		return visitor.visit(this, a, b, c);
	}
}

class TRho extends TElement
{
	public long accept(TVisitor visitor, long a, long b, long c)
	{
		return visitor.visit(this, a, b, c);
	}
}

class TSigma extends TElement
{
	public long accept(TVisitor visitor, long a, long b, long c)
	{
		return visitor.visit(this, a, b, c);
	}
}

class TTau extends TElement
{
	public long accept(TVisitor visitor, long a, long b, long c)
	{
		return visitor.visit(this, a, b, c);
	}
}

class TUpsilon extends TElement
{
	public long accept(TVisitor visitor, long a, long b, long c)
	{
		return visitor.visit(this, a, b, c);
	}
}

class TPhi extends TElement
{
	public long accept(TVisitor visitor, long a, long b, long c)
	{
		return visitor.visit(this, a, b, c);
	}
}

class TKhi extends TElement
{
	public long accept(TVisitor visitor, long a, long b, long c)
	{
		return visitor.visit(this, a, b, c);
	}
}

class TPsi extends TElement
{
	public long accept(TVisitor visitor, long a, long b, long c)
	{
		return visitor.visit(this, a, b, c);
	}
}

class TOmega extends TElement
{
	public long accept(TVisitor visitor, long a, long b, long c)
	{
		return visitor.visit(this, a, b, c);
	}
}
