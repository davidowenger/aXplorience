#include "NCommon.h"

namespace NNameSpace
{

NParamBox::NParamBox(NWrapper* nWrapper, CharSequence boxed)
	: n(0)
{
	w = nWrapper;
	tString = w->nFrame->tRunString(boxed);
	n = (NParam)&tString;
}

NParamBox::~NParamBox()
{
}

} // END namespace
