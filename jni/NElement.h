#ifndef __NELEMENT_H__
#define __NELEMENT_H__

namespace NNameSpace
{

class NElement
{
public:
	//virtual jlong acceptLong(NVisitor* visitor) = 0;
	//virtual jobject acceptObject(NVisitor* visitor) = 0;
	virtual jlong acceptLong(NVisitor* visitor);
	virtual jobject acceptObject(NVisitor* visitor);

	jobject t;
};

class NAlpha : public NElement
{
};

class NBeta : public NElement
{
};

class NGamma : public NElement
{
};

/*
class NAlpha : public NElement
{
public:
	jlong acceptLong(NVisitor* visitor);
	jobject acceptObject(NVisitor* visitor);
};

class NBeta : public NElement
{
public:
	jlong acceptLong(NVisitor* visitor);
	jobject acceptObject(NVisitor* visitor);
};

class NGamma : public NElement
{
public:
	jlong acceptLong(NVisitor* visitor);
	jobject acceptObject(NVisitor* visitor);
};
*/
} // END namespace

#endif
