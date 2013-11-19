#ifndef __NVISITOR_H__
#define __NVISITOR_H__

namespace NNameSpace
{

class NVisitor
{
public:
	NVisitor();
   ~NVisitor();

    virtual jlong visitLong(NElement* nElement);
    virtual jobject visitObject(NElement* nElement);
    virtual jlong visitLong(NAlpha* alpha);
    virtual jobject visitObject(NAlpha* alpha);
    virtual jlong visitLong(NBeta* beta);
    virtual jobject visitObject(NBeta* beta);
    virtual jlong visitLong(NGamma* gamma);
    virtual jobject visitObject(NGamma* gamma);
};

} // END namespace

#endif
