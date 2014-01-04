#include "Common.h"

namespace NNameSpace
{

NElement::~NElement()
{
}

jlong NAlpha::acceptLong(NVisitorLong* visitor)
{
	return visitor->visitLong(this);
}

jlong NBeta::acceptLong(NVisitorLong* visitor)
{
	return visitor->visitLong(this);
}

jlong NGamma::acceptLong(NVisitorLong* visitor)
{
	return visitor->visitLong(this);
}

} // END namespace
