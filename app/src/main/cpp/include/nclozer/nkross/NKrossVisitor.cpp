#include "NKrossCommon.h"

namespace NSNATIVE
{

NKrossVisitor::NKrossVisitor(NWrapper* vNWrapper)
    : mNWrapper(vNWrapper)
{
}

NKrossVisitor::~NKrossVisitor()
{
}

NReturn NKrossVisitor::tRun(NElement* nElement, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    LOGPRINTV("Call to TARGET with element #%d at visitor #%d", nElement->i, this->i);
    return NKrossVisitor_tRun(mNWrapper, (NParam)this, (NParam)nElement, a, b, c, d, e);
}

NReturnObject NKrossVisitor::tRunObject(NParam a, NParam b)
{
    LOGPRINTV("Call to TARGET for object at index #%llu", a);
    return NKrossSystem_tRunObject(mNWrapper, a, b);
}

} // END namespace
