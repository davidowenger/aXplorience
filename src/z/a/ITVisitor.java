package z.a;

public interface ITVisitor
{
	public long tRun(long tVisitorN, long tElementN, long a, long b, long c);

	public long visit(TAlpha element, long a, long b, long c);
	public long visit(TBeta element, long a, long b, long c);
	public long visit(TGamma element, long a, long b, long c);
	public long visit(TDelta element, long a, long b, long c);
	public long visit(TEpsilon element, long a, long b, long c);
	public long visit(TDzeta element, long a, long b, long c);
	public long visit(TEta element, long a, long b, long c);
	public long visit(TTheta element, long a, long b, long c);
	public long visit(TIota element, long a, long b, long c);
	public long visit(TKappa element, long a, long b, long c);
	public long visit(TLambda element, long a, long b, long c);
	public long visit(TMu element, long a, long b, long c);
	public long visit(TNu element, long a, long b, long c);
	public long visit(TXi element, long a, long b, long c);
	public long visit(TOmicron element, long a, long b, long c);
	public long visit(TPi element, long a, long b, long c);
	public long visit(TRho element, long a, long b, long c);
	public long visit(TSigma element, long a, long b, long c);
	public long visit(TTau element, long a, long b, long c);
	public long visit(TUpsilon element, long a, long b, long c);
	public long visit(TPhi element, long a, long b, long c);
	public long visit(TKhi element, long a, long b, long c);
	public long visit(TPsi element, long a, long b, long c);
	public long visit(TOmega element, long a, long b, long c);

}
