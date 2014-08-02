#ifndef __NELEMENT_H__
#define __NELEMENT_H__

namespace NNameSpace
{

class NElement
{
public:
	static int counter;

	NElement();
	virtual ~NElement();

	virtual NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0) = 0;

    const int i;
};

class NAlpha : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0);
};

class NBeta : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0);
};

class NGamma : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0);
};

class NDelta: public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0);
};

class NEpsilon: public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0);
};

class NDzeta: public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0);
};

class NEta: public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0);
};

class NTheta: public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0);
};

class NIota : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0);
};

class NKappa : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0);
};

class NLambda : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0);
};

class NMu : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0);
};

class NNu : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0);
};

class NXi : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0);
};

class NOmicron : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0);
};

class NPi : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0);
};

class NRho : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0);
};

class NSigma : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0);
};

class NTau : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0);
};

class NUpsilon : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0);
};

class NPhi : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0);
};

class NKhi : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0);
};

class NPsi : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0);
};

class NOmega : public NElement
{
public:
    NReturn accept(NVisitor* visitor, NParam a = 0, NParam b = 0, NParam c = 0);
};

} // END namespace

#endif
