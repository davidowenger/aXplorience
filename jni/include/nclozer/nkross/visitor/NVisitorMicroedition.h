#ifndef __NVisitorMicroedition_H__
#define __NVisitorMicroedition_H__

namespace NSNATIVE
{

class NVisitorMicroedition : public NKrossVisitor
{
public:
    NVisitorMicroedition(NWrapper* w)
        : NKrossVisitor(w)
    {
    }

    virtual ~NVisitorMicroedition()
    {
    }
};

} // END namespace

#endif
