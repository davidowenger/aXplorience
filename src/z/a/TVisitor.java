package z.a;

public abstract class TVisitor implements INVisitor, ITVisitor
{
	// Static initializer block
    static {
    	//System.loadLibrary("c++_shared");
    	System.loadLibrary("gnustl_shared");
        System.loadLibrary("TActivity");
		// Debug
        if (true) {
			try {
				Thread.sleep(10000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
        }
    }
	public static int counter = 0;

	public TWrapper w;
    public long n;
    public int i;

    public TVisitor(TWrapper w)
    {
    	this.w = w;
		this.i = counter++;
    }

    public long defaultVisit(TElement tElement)
	{
		System.err.println("Empty TARGET visit method called for element #" + tElement.i + " at visitor #" + this.i);
		return 1;
	}

	public long tRun(long tVisitorN, long tElementN, long a, long b, long c, long d)
	{
		long ret = (-1 >>> 1) + 1;
		
		try {
			ret = ((TElement)w.sTElement.get("" + tElementN)).accept((TVisitor)w.sTVisitor.get("" + tVisitorN), a, b, c, d);
		}
		catch (Exception e) {
			e.printStackTrace();
			ret = (-1 >>> 1) + 1;
		}
		return ret;
	}

	public Object tRunObject(long a, long b)
	{
		return null;
	}

	public long visit(TAlpha00 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TBeta00 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TGamma00 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TDelta00 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TEpsilon00 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TDzeta00 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TEta00 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TTheta00 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TIota00 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TKappa00 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TLambda00 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TMu00 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TNu00 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TXi00 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TOmicron00 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TPi00 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TRho00 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TSigma00 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TTau00 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TUpsilon00 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TPhi00 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TKhi00 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TPsi00 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TOmega00 element, long a, long b, long c, long d){return defaultVisit(element);}

	public long visit(TAlpha01 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TBeta01 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TGamma01 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TDelta01 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TEpsilon01 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TDzeta01 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TEta01 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TTheta01 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TIota01 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TKappa01 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TLambda01 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TMu01 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TNu01 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TXi01 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TOmicron01 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TPi01 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TRho01 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TSigma01 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TTau01 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TUpsilon01 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TPhi01 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TKhi01 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TPsi01 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TOmega01 element, long a, long b, long c, long d){return defaultVisit(element);}

	public long visit(TAlpha02 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TBeta02 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TGamma02 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TDelta02 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TEpsilon02 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TDzeta02 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TEta02 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TTheta02 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TIota02 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TKappa02 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TLambda02 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TMu02 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TNu02 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TXi02 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TOmicron02 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TPi02 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TRho02 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TSigma02 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TTau02 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TUpsilon02 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TPhi02 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TKhi02 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TPsi02 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TOmega02 element, long a, long b, long c, long d){return defaultVisit(element);}

	public long visit(TAlpha03 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TBeta03 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TGamma03 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TDelta03 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TEpsilon03 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TDzeta03 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TEta03 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TTheta03 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TIota03 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TKappa03 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TLambda03 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TMu03 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TNu03 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TXi03 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TOmicron03 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TPi03 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TRho03 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TSigma03 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TTau03 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TUpsilon03 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TPhi03 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TKhi03 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TPsi03 element, long a, long b, long c, long d){return defaultVisit(element);}
	public long visit(TOmega03 element, long a, long b, long c, long d){return defaultVisit(element);}

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
		return nRun(this.n, tElement.n, a.longValue(), b.longValue(), c.longValue(), d.longValue());
	}

	public Object nRunObject(Number a)
	{
		return nRunObject(a.longValue(), -1);
	}

	public Object nRunObject(Number a, Number b)
	{
		return nRunObject(a.longValue(), b.longValue());
	}

    public native long nRun(long tVisitorN, long tElementN, long a, long b, long c, long d);
    public native Object nRunObject(long a, long b);
}
