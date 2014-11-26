#ifndef __NFRAME_H__
#define __NFRAME_H__

namespace NSNATIVE
{

class NFrame : public NVisitor
{
public:
	static const NINIT GET_W = 0;
	static const NINIT GET_ELEMENT = GET_W + 1;
	static const NINIT GET_VISITOR = GET_ELEMENT + 1;

	NFrame(NWrapper* w);
	virtual ~NFrame();

	virtual NReturn nInit(NINIT cState) = 0;
	virtual NReturn tDetachCurrentThread() = 0;
	virtual NReturnObject tRunString(CharSequence boxed) = 0;
	virtual String tGetString(NReturnObject tString) = 0;
};

} // END namespace

#endif
