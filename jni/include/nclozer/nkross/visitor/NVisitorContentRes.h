#ifndef __NVisitorContentRes_H__
#define __NVisitorContentRes_H__

namespace NSNATIVE
{

class NVisitorContentRes : public NKrossVisitor
{
public:
    NVisitorContentRes(NWrapper* w)
        : NKrossVisitor(w)
    {
    }

    virtual ~NVisitorContentRes()
    {
    }
};

} // END namespace

#endif
