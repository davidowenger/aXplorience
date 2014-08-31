#include "NCommon.h"

namespace NSNATIVE
{

NParamBox::NParamBox(NWrapper* w, CharSequence boxed)
	: n(0), w(w)
{
	set(boxed);
}

NParamBox::NParamBox(NWrapper* w, const String& boxed)
	: n(0), w(w)
{
	set(boxed.c_str());
}

NParamBox::~NParamBox()
{
}

void NParamBox::set(CharSequence boxed)
{
	mTString = w->nFrame->tRunString(boxed);
	n = (NParam)&mTString;
}

} // END namespace
