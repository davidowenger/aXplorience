#ifndef __NFRAME_H__
#define __NFRAME_H__

namespace NNameSpace
{

class NFrame : public NVisitor
{
public:
	NFrame();
	virtual ~NFrame();

	virtual jobject nInit(jobjectArray aTElement) = 0;
	virtual jlong nRunLong(NElement* nElement) = 0;
	virtual jobject nRunObject(NElement* nElement) = 0;
};

} // END namespace

#endif
