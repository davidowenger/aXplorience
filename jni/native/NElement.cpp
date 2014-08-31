#include "NCommon.h"

namespace NSNATIVE
{

int NElement::counter = 0;

NElement::NElement()
	: i(counter++)
{
}

NElement::~NElement()
{
}

NReturn NAlpha00::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NBeta00::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NGamma00::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NDelta00::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NEpsilon00::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NDzeta00::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NEta00::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NTheta00::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NIota00::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NKappa00::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NLambda00::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NMu00::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NNu00::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NXi00::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NOmicron00::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NPi00::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NRho00::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NSigma00::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NTau00::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NUpsilon00::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NPhi00::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NKhi00::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NPsi00::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{
	return visitor->visit(this, a, b, c, d);
}

NReturn NOmega00::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{
	return visitor->visit(this, a, b, c, d);
}


NReturn NAlpha01::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NBeta01::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NGamma01::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NDelta01::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NEpsilon01::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NDzeta01::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NEta01::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NTheta01::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NIota01::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NKappa01::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NLambda01::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NMu01::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NNu01::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NXi01::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NOmicron01::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NPi01::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NRho01::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NSigma01::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NTau01::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NUpsilon01::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NPhi01::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NKhi01::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NPsi01::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{
	return visitor->visit(this, a, b, c, d);
}

NReturn NOmega01::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{
	return visitor->visit(this, a, b, c, d);
}


NReturn NAlpha02::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NBeta02::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NGamma02::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NDelta02::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NEpsilon02::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NDzeta02::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NEta02::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NTheta02::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NIota02::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NKappa02::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NLambda02::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NMu02::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NNu02::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NXi02::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NOmicron02::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NPi02::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NRho02::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NSigma02::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NTau02::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NUpsilon02::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NPhi02::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NKhi02::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NPsi02::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{
	return visitor->visit(this, a, b, c, d);
}

NReturn NOmega02::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{
	return visitor->visit(this, a, b, c, d);
}


NReturn NAlpha03::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NBeta03::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NGamma03::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NDelta03::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NEpsilon03::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NDzeta03::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NEta03::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NTheta03::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NIota03::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NKappa03::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NLambda03::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NMu03::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NNu03::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NXi03::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NOmicron03::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NPi03::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NRho03::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NSigma03::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NTau03::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NUpsilon03::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NPhi03::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NKhi03::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{

	return visitor->visit(this, a, b, c, d);
}

NReturn NPsi03::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{
	return visitor->visit(this, a, b, c, d);
}

NReturn NOmega03::accept(NVisitor* visitor, NParam a, NParam b, NParam c, NParam d)
{
	return visitor->visit(this, a, b, c, d);
}

} // END namespace
