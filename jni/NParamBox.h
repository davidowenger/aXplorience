#ifndef __NParamBox_H__
#define __NParamBox_H__

namespace NNameSpace
{

class NParamBox
{
public:
	NParamBox(NWrapper* nWrapper, CharSequence boxed);
	virtual ~NParamBox();

	NWrapper* w;
	NReturnObject tString;
	NParam n;
};

} // END namespace

#endif
