#include "NCommon.h"
#include "NElement.h"
#include "NVisitor.h"

namespace NSNATIVE
{

int NVisitor::counter = 0;

NVisitor::NVisitor()
    : i(counter++)
{
}

NVisitor::~NVisitor()
{
}

NReturn NVisitor::defaultVisit(NElement* nElement)
{
    LOGPRINTW("Empty NATIVE visit method called for element #%d at visitor #%d", nElement->i, this->i);
    return 1;
}

NReturn NVisitor::nRun(NElement* nElement, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    LOGPRINTV("Call to NATIVE with element #%d at visitor #%d", nElement->i, this->i);
    return nElement->accept(this, a, b, c, d, e);
}

} // END namespace
