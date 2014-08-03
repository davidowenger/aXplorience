package z.a;

public abstract class TVisitor implements INVisitor, ITVisitor
{
	// Static initializer block
    static {
    	//System.loadLibrary("c++_shared");
    	//System.loadLibrary("gnustl_shared");
    	//System.loadLibrary("TApp");
    }

	public TWrapper w;
    public long n;

    public TVisitor(TWrapper w)
    {
		// Debug
        if (false) {
			try {
				Thread.sleep(5000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
        }
    	this.w = w;
    }

	public long tRun(long tVisitorN, long tElementN, long a, long b, long c)
	{
		return ((TElement)w.vTElement.get("" + tElementN)).accept((TVisitor)w.vTVisitor.get("" + tVisitorN), a, b, c);
	}

	public long visit(TAlpha element, long a, long b, long c){return 0;}
	public long visit(TBeta element, long a, long b, long c){return 0;}
	public long visit(TGamma element, long a, long b, long c){return 0;}
	public long visit(TDelta element, long a, long b, long c){return 0;}
	public long visit(TEpsilon element, long a, long b, long c){return 0;}
	public long visit(TDzeta element, long a, long b, long c){return 0;}
	public long visit(TEta element, long a, long b, long c){return 0;}
	public long visit(TTheta element, long a, long b, long c){return 0;}
	public long visit(TIota element, long a, long b, long c){return 0;}
	public long visit(TKappa element, long a, long b, long c){return 0;}
	public long visit(TLambda element, long a, long b, long c){return 0;}
	public long visit(TMu element, long a, long b, long c){return 0;}
	public long visit(TNu element, long a, long b, long c){return 0;}
	public long visit(TXi element, long a, long b, long c){return 0;}
	public long visit(TOmicron element, long a, long b, long c){return 0;}
	public long visit(TPi element, long a, long b, long c){return 0;}
	public long visit(TRho element, long a, long b, long c){return 0;}
	public long visit(TSigma element, long a, long b, long c){return 0;}
	public long visit(TTau element, long a, long b, long c){return 0;}
	public long visit(TUpsilon element, long a, long b, long c){return 0;}
	public long visit(TPhi element, long a, long b, long c){return 0;}
	public long visit(TKhi element, long a, long b, long c){return 0;}
	public long visit(TPsi element, long a, long b, long c){return 0;}
	public long visit(TOmega element, long a, long b, long c){return 0;}

	public long nRun(TElement tElement)
	{
		return nRun(tElement, 0, 0, 0);
	}

	public long nRun(TElement tElement, Number a)
	{
		return nRun(tElement, a.longValue(), 0, 0);
	}

	public long nRun(TElement tElement, Number a, Number b)
	{
		return nRun(tElement, a.longValue(), b.longValue(), 0);
	}

	public long nRun(TElement tElement, Number a, Number b, Number c)
	{
		return nRun(this.n, tElement.n, a.longValue(), b.longValue(), c.longValue());
	}

	public Object nRunObject(TElement tElement, Number a)
	{
		return nRunObject(tElement, a.longValue(), 0);
	}

	public Object nRunObject(TElement tElement, Number a, Number b)
	{
		return nRunObject(this.n, tElement.n, a.longValue(), b.longValue());
	}

    public native long nRun(long tVisitorN, long tElementN, long a, long b, long c);
    public native Object nRunObject(long tVisitorN, long tElementN, long a, long b);
}
