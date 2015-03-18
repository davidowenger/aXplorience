#include "NCommon.h"

namespace NSNATIVE
{

int NVisitor::counter = 0;

NVisitor::NVisitor(NWrapper* const w)
	: i(counter++), w(w)
{
}

NVisitor::~NVisitor()
{
}

NReturn NVisitor::defaultVisit(NElement* nElement)
{
    LOGPRINTE("Empty NATIVE visit method called for element #%d at visitor #%d", nElement->i, this->i);
	return 1;
}

NReturn NVisitor::tRun(NElement* nElement, NParam a, NParam b, NParam c, NParam d, NParam e)
{
	LOGPRINTI("Call to TARGET with element #%d at visitor #%d", nElement->i, this->i);
	return NAPI_tRun(w, (NParam)this, (NParam)nElement, a, b, c, d, e);
}

NReturnObject NVisitor::tRunObject(NParam a, NParam b)
{
	LOGPRINTI("Call to TARGET for object at index #%llu", a);
	return NAPI_tRunObject(w, a, b);
}

NReturn NVisitor::nRun(NElement* nElement, NParam a, NParam b, NParam c, NParam d, NParam e)
{
	LOGPRINTI("Call to NATIVE with element #%d at visitor #%d", nElement->i, this->i);
	return nElement->accept(this, a, b, c, d, e);
}

} // END namespace