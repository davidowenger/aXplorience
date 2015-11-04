#ifndef __NKrossVisitor_H__
#define __NKrossVisitor_H__

namespace NSNATIVE
{

class NKrossVisitor : public NVisitor
{
public:
    NKrossVisitor(NWrapper* vWrapper);
    virtual ~NKrossVisitor();

    NReturn tRun(NElement* nElement, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
    NReturnObject tRunObject(NParam a = 0, NParam b = -1);

    NWrapper* mNWrapper;
};

} // END namespace

#endif
