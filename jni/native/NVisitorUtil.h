#ifndef __NVisitorUtil_H__
#define __NVisitorUtil_H__

namespace NSNATIVE
{

class NVisitorUtil : public NVisitor
{
public:
    NVisitorUtil(NWrapper* w)
        : NVisitor(w)
    {
    }

   ~NVisitorUtil()
    {
    }
};

} // END namespace

#endif
