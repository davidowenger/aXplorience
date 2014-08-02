#ifndef __NVISITOR_H__
#define __NVISITOR_H__

namespace NNameSpace
{

class NVisitor
{
public:
	static int counter;

	NVisitor(NWrapper* w);
	virtual ~NVisitor();

	NReturn tRun(NElement* nElement, NParam a = 0, NParam b = 0, NParam c = 0);
	NReturn nRun(NElement* nElement, NParam a = 0, NParam b = 0, NParam c = 0);
	NReturn defaultVisit(NElement* nElement);

    virtual NReturn visit(NAlpha* element, NParam a = 0, NParam b = 0, NParam c = 0) { return defaultVisit(element); }
    virtual NReturn visit(NBeta* element, NParam a = 0, NParam b = 0, NParam c = 0) { return defaultVisit(element); }
    virtual NReturn visit(NGamma* element, NParam a = 0, NParam b = 0, NParam c = 0) { return defaultVisit(element); };
    virtual NReturn visit(NDelta* element, NParam a = 0, NParam b = 0, NParam c = 0) { return defaultVisit(element); };
    virtual NReturn visit(NEpsilon* element, NParam a = 0, NParam b = 0, NParam c = 0) { return defaultVisit(element); };
    virtual NReturn visit(NDzeta* element, NParam a = 0, NParam b = 0, NParam c = 0) { return defaultVisit(element); };
    virtual NReturn visit(NEta* element, NParam a = 0, NParam b = 0, NParam c = 0) { return defaultVisit(element); };
    virtual NReturn visit(NTheta* element, NParam a = 0, NParam b = 0, NParam c = 0) { return defaultVisit(element); };
    virtual NReturn visit(NIota* element, NParam a = 0, NParam b = 0, NParam c = 0) { return defaultVisit(element); };
    virtual NReturn visit(NKappa* element, NParam a = 0, NParam b = 0, NParam c = 0) { return defaultVisit(element); };
    virtual NReturn visit(NLambda* element, NParam a = 0, NParam b = 0, NParam c = 0) { return defaultVisit(element); };
    virtual NReturn visit(NMu* element, NParam a = 0, NParam b = 0, NParam c = 0) { return defaultVisit(element); };
    virtual NReturn visit(NNu* element, NParam a = 0, NParam b = 0, NParam c = 0) { return defaultVisit(element); };
    virtual NReturn visit(NXi* element, NParam a = 0, NParam b = 0, NParam c = 0) { return defaultVisit(element); };
    virtual NReturn visit(NOmicron* element, NParam a = 0, NParam b = 0, NParam c = 0) { return defaultVisit(element); };
    virtual NReturn visit(NPi* element, NParam a = 0, NParam b = 0, NParam c = 0) { return defaultVisit(element); };
    virtual NReturn visit(NRho* element, NParam a = 0, NParam b = 0, NParam c = 0) { return defaultVisit(element); };
    virtual NReturn visit(NSigma* element, NParam a = 0, NParam b = 0, NParam c = 0) { return defaultVisit(element); };
    virtual NReturn visit(NTau* element, NParam a = 0, NParam b = 0, NParam c = 0) { return defaultVisit(element); };
    virtual NReturn visit(NUpsilon* element, NParam a = 0, NParam b = 0, NParam c = 0) { return defaultVisit(element); };
    virtual NReturn visit(NPhi* element, NParam a = 0, NParam b = 0, NParam c = 0) { return defaultVisit(element); };
    virtual NReturn visit(NKhi* element, NParam a = 0, NParam b = 0, NParam c = 0) { return defaultVisit(element); };
    virtual NReturn visit(NPsi* element, NParam a = 0, NParam b = 0, NParam c = 0) { return defaultVisit(element); };
    virtual NReturn visit(NOmega* element, NParam a = 0, NParam b = 0, NParam c = 0) { return defaultVisit(element); };

    const int i;
    NWrapper* w;
};

} // END namespace

#endif
