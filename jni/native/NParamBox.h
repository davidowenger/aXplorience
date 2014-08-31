#ifndef __NParamBox_H__
#define __NParamBox_H__

namespace NSNATIVE
{

class NParamBox
{
public:
	NParamBox(NWrapper* w, CharSequence boxed);
	NParamBox(NWrapper* w, const String& boxed);
	virtual ~NParamBox();

	void set(CharSequence boxed);

	NWrapper* w;
	NParam n;
	NReturnObject mTString;
};

} // END namespace

#endif
