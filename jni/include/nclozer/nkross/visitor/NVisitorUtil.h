#ifndef __NVisitorUtil_H__
#define __NVisitorUtil_H__

namespace NSNATIVE
{

class NVisitorUtil : public NKrossVisitor
{
public:
    NVisitorUtil(NWrapper* w)
        : NKrossVisitor(w)
    {
    }

   ~NVisitorUtil()
    {
    }
};

} // END namespace

#endif
