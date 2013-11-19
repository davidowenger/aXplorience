#include "Common.h"

namespace NNameSpace
{

jlong NElement::acceptLong(NVisitor* visitor)
{
	return visitor->visitLong(this);
}

jobject NElement::acceptObject(NVisitor* visitor)
{
	return visitor->visitObject(this);
}

/*
jlong NAlpha::acceptLong(NVisitor* visitor)
{
	return visitor->visitLong(this);
}

jobject NAlpha::acceptObject(NVisitor* visitor)
{
	return visitor->visitObject(this);
}

jlong NBeta::acceptLong(NVisitor* visitor)
{
	return visitor->visitLong(this);
}

jobject NBeta::acceptObject(NVisitor* visitor)
{
	return visitor->visitObject(this);
}

jlong NGamma::acceptLong(NVisitor* visitor)
{
	return visitor->visitLong(this);
}

jobject NGamma::acceptObject(NVisitor* visitor)
{
	return visitor->visitObject(this);
}
*/

} // END namespace
