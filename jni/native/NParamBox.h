#ifndef __NParamBox_H__
#define __NParamBox_H__

namespace NSNATIVE
{

class NParamBox
{
public:
	NParamBox(NWrapper* const w, const String& boxed);
	virtual ~NParamBox();

	NWrapper* const w;
	NParam n;
	NReturnObject mTString;
};

} // END namespace

#endif
