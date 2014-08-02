#include "NCommon.h"

namespace NNameSpace
{

int NElement::counter = 0;

NElement::NElement()
	: i(counter++)
{
}

NElement::~NElement()
{
}

NReturn NAlpha::accept(NVisitor* visitor, NParam a, NParam b, NParam c)
{

	return visitor->visit(this, a, b, c);
}

NReturn NBeta::accept(NVisitor* visitor, NParam a, NParam b, NParam c)
{

	return visitor->visit(this, a, b, c);
}

NReturn NGamma::accept(NVisitor* visitor, NParam a, NParam b, NParam c)
{

	return visitor->visit(this, a, b, c);
}

NReturn NDelta::accept(NVisitor* visitor, NParam a, NParam b, NParam c)
{

	return visitor->visit(this, a, b, c);
}

NReturn NEpsilon::accept(NVisitor* visitor, NParam a, NParam b, NParam c)
{

	return visitor->visit(this, a, b, c);
}

NReturn NDzeta::accept(NVisitor* visitor, NParam a, NParam b, NParam c)
{

	return visitor->visit(this, a, b, c);
}

NReturn NEta::accept(NVisitor* visitor, NParam a, NParam b, NParam c)
{

	return visitor->visit(this, a, b, c);
}

NReturn NTheta::accept(NVisitor* visitor, NParam a, NParam b, NParam c)
{

	return visitor->visit(this, a, b, c);
}

NReturn NIota::accept(NVisitor* visitor, NParam a, NParam b, NParam c)
{

	return visitor->visit(this, a, b, c);
}

NReturn NKappa::accept(NVisitor* visitor, NParam a, NParam b, NParam c)
{

	return visitor->visit(this, a, b, c);
}

NReturn NLambda::accept(NVisitor* visitor, NParam a, NParam b, NParam c)
{

	return visitor->visit(this, a, b, c);
}

NReturn NMu::accept(NVisitor* visitor, NParam a, NParam b, NParam c)
{

	return visitor->visit(this, a, b, c);
}

NReturn NNu::accept(NVisitor* visitor, NParam a, NParam b, NParam c)
{

	return visitor->visit(this, a, b, c);
}

NReturn NXi::accept(NVisitor* visitor, NParam a, NParam b, NParam c)
{

	return visitor->visit(this, a, b, c);
}

NReturn NOmicron::accept(NVisitor* visitor, NParam a, NParam b, NParam c)
{

	return visitor->visit(this, a, b, c);
}

NReturn NPi::accept(NVisitor* visitor, NParam a, NParam b, NParam c)
{

	return visitor->visit(this, a, b, c);
}

NReturn NRho::accept(NVisitor* visitor, NParam a, NParam b, NParam c)
{

	return visitor->visit(this, a, b, c);
}

NReturn NSigma::accept(NVisitor* visitor, NParam a, NParam b, NParam c)
{

	return visitor->visit(this, a, b, c);
}

NReturn NTau::accept(NVisitor* visitor, NParam a, NParam b, NParam c)
{

	return visitor->visit(this, a, b, c);
}

NReturn NUpsilon::accept(NVisitor* visitor, NParam a, NParam b, NParam c)
{

	return visitor->visit(this, a, b, c);
}

NReturn NPhi::accept(NVisitor* visitor, NParam a, NParam b, NParam c)
{

	return visitor->visit(this, a, b, c);
}

NReturn NKhi::accept(NVisitor* visitor, NParam a, NParam b, NParam c)
{

	return visitor->visit(this, a, b, c);
}

NReturn NPsi::accept(NVisitor* visitor, NParam a, NParam b, NParam c)
{
	return visitor->visit(this, a, b, c);
}

NReturn NOmega::accept(NVisitor* visitor, NParam a, NParam b, NParam c)
{
	return visitor->visit(this, a, b, c);
}

} // END namespace
