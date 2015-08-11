#ifndef __NVISITOR_H__
#define __NVISITOR_H__

namespace NSNATIVE
{

class NVisitor
{
public:
    static int counter;

    NVisitor(NWrapper* const w);
    virtual ~NVisitor();

    NReturn tRun(NElement* nElement, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
    NReturnObject tRunObject(NParam a = 0, NParam b = -1);
    NReturn defaultVisit(NElement* nElement);

    NReturn nRun(NElement* nElement, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);

    virtual NReturn visit(NAlpha00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); }
    virtual NReturn visit(NBeta00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); }
    virtual NReturn visit(NGamma00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NDelta00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NEpsilon00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NDzeta00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NEta00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NTheta00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NIota00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NKappa00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NLambda00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NMu00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NNu00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NXi00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NOmicron00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NPi00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NRho00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NSigma00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NTau00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NUpsilon00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NPhi00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NKhi00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NPsi00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NOmega00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };

    virtual NReturn visit(NAlpha01* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); }
    virtual NReturn visit(NBeta01* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); }
    virtual NReturn visit(NGamma01* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NDelta01* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NEpsilon01* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NDzeta01* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NEta01* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NTheta01* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NIota01* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NKappa01* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NLambda01* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NMu01* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NNu01* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NXi01* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NOmicron01* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NPi01* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NRho01* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NSigma01* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NTau01* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NUpsilon01* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NPhi01* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NKhi01* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NPsi01* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NOmega01* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };

    virtual NReturn visit(NAlpha02* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); }
    virtual NReturn visit(NBeta02* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); }
    virtual NReturn visit(NGamma02* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NDelta02* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NEpsilon02* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NDzeta02* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NEta02* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NTheta02* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NIota02* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NKappa02* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NLambda02* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NMu02* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NNu02* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NXi02* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NOmicron02* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NPi02* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NRho02* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NSigma02* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NTau02* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NUpsilon02* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NPhi02* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NKhi02* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NPsi02* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NOmega02* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };

    virtual NReturn visit(NAlpha03* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); }
    virtual NReturn visit(NBeta03* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); }
    virtual NReturn visit(NGamma03* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NDelta03* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NEpsilon03* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NDzeta03* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NEta03* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NTheta03* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NIota03* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NKappa03* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NLambda03* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NMu03* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NNu03* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NXi03* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NOmicron03* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NPi03* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NRho03* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NSigma03* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NTau03* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NUpsilon03* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NPhi03* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NKhi03* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NPsi03* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };
    virtual NReturn visit(NOmega03* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) { return defaultVisit(element); };

    const int i;
    NWrapper* const w;
};

} // END namespace

#endif
