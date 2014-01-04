#ifndef __NELEMENT_H__
#define __NELEMENT_H__

namespace NNameSpace
{

class NElement
{
public:
	virtual ~NElement();

	virtual jlong acceptLong(NVisitorLong* visitor) = 0;
//	virtual jobject acceptObject(NVisitor* visitor) = 0;

    static const int i = -1;

	jobject t;
};

class NAlpha : public NElement
{
public:
    static const int i = 0;

	jlong acceptLong(NVisitorLong* visitor);
};

class NBeta : public NElement
{
public:
    static const int i = 1;

	jlong acceptLong(NVisitorLong* visitor);
};

class NGamma : public NElement
{
public:
    static const int i = 2;

	jlong acceptLong(NVisitorLong* visitor);
};

} // END namespace

#endif
