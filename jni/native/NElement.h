#ifndef __NELEMENT_H__
#define __NELEMENT_H__

namespace NSNATIVE
{

class NElement
{
public:
    static int counter;

    NElement();
    virtual ~NElement();

    virtual NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) = 0;

    const int i;
};

class NAlpha00 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NBeta00 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NGamma00 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NDelta00: public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NEpsilon00: public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NDzeta00: public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NEta00: public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NTheta00: public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NIota00 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NKappa00 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NLambda00 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NMu00 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NNu00 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NXi00 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NOmicron00 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NPi00 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NRho00 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NSigma00 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NTau00 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NUpsilon00 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NPhi00 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NKhi00 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NPsi00 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NOmega00 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};



class NAlpha01 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NBeta01 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NGamma01 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NDelta01: public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NEpsilon01: public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NDzeta01: public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NEta01: public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NTheta01: public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NIota01 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NKappa01 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NLambda01 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NMu01 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NNu01 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NXi01 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NOmicron01 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NPi01 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NRho01 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NSigma01 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NTau01 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NUpsilon01 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NPhi01 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NKhi01 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NPsi01 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NOmega01 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};


class NAlpha02 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NBeta02 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NGamma02 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NDelta02: public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NEpsilon02: public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NDzeta02: public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NEta02: public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NTheta02: public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NIota02 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NKappa02 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NLambda02 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NMu02 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NNu02 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NXi02 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NOmicron02 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NPi02 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NRho02 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NSigma02 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NTau02 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NUpsilon02 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NPhi02 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NKhi02 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NPsi02 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NOmega02 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};


class NAlpha03 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NBeta03 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NGamma03 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NDelta03: public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NEpsilon03: public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NDzeta03: public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NEta03: public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NTheta03: public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NIota03 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NKappa03 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NLambda03 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NMu03 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NNu03 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NXi03 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NOmicron03 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NPi03 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NRho03 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NSigma03 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NTau03 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NUpsilon03 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NPhi03 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NKhi03 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NPsi03 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

class NOmega03 : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

} // END namespace

#endif
