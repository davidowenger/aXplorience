#ifndef __NVISITOR_H__
#define __NVISITOR_H__

namespace NNameSpace
{

class NVisitorLong
{
public:
	NVisitorLong();
	virtual ~NVisitorLong();

	virtual jlong nRunLong(NElement* nElement) = 0;
    virtual jlong visitLong(NAlpha* alpha) = 0;
    virtual jlong visitLong(NBeta* beta) = 0;
    virtual jlong visitLong(NGamma* gamma) = 0;
};
/*
class NVisitorObject
{
public:
	NVisitorObject();
	virtual ~NVisitorObject();

	virtual jobject nRunObject(NElement* nElement) = 0;
    virtual jobject visitObject(NAlpha* alpha) = 0;
    virtual jobject visitObject(NBeta* beta) = 0;
    virtual jobject visitObject(NGamma* gamma) = 0;
};
*/
} // END namespace

#endif
