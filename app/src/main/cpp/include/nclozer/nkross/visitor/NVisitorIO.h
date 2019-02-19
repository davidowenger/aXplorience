#ifndef __NVisitorIO_H__
#define __NVisitorIO_H__

namespace NSNATIVE
{

class NVisitorIO : public NKrossVisitor
{
public:
    NVisitorIO(NWrapper* w)
        : NKrossVisitor(w)
    {
    }

   ~NVisitorIO()
    {
    }
};

} // END namespace

#endif
