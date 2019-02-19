#ifndef __NVisitorOS_H__
#define __NVisitorOS_H__

namespace NSNATIVE
{

class NVisitorOS : public NKrossVisitor
{
public:
    NVisitorOS(NWrapper* w)
        : NKrossVisitor(w)
    {
    }

   ~NVisitorOS()
    {
    }
};

} // END namespace

#endif
