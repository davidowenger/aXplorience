#include "Common.h"

namespace NNameSpace
{

NVisitor::NVisitor()
{
}

NVisitor::~NVisitor()
{
}

jlong NVisitor::visitLong(NElement* nElement)
{
	return 0;
}

jobject NVisitor::visitObject(NElement* nElement)
{
	return NULL;
}

jlong NVisitor::visitLong(NAlpha* alpha)
{
	return 0;
}

jobject NVisitor::visitObject(NAlpha* alpha)
{
	return NULL;
}

jlong NVisitor::visitLong(NBeta* beta)
{
	return 0;
}

jobject NVisitor::visitObject(NBeta* beta)
{
	return NULL;
}

jlong NVisitor::visitLong(NGamma* gamma)
{
	return 0;
}

jobject NVisitor::visitObject(NGamma* gamma)
{
	return NULL;
}

} // END namespace
