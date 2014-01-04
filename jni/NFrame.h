#ifndef __NFRAME_H__
#define __NFRAME_H__

namespace NNameSpace
{

class NFrame : public NVisitorLong
{
public:
	NFrame();
	virtual ~NFrame();

	virtual jobject nInit(jobjectArray aTElement) = 0;
};

} // END namespace

#endif
