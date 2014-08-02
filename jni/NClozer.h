#ifndef __NCLOZER_H__
#define __NCLOZER_H__

namespace NNameSpace
{

class NClozer : public NFrame
{
public:
	NClozer(NWrapper* w);
	virtual ~NClozer();

	NReturn nInit(NINIT cState);
	NReturnObject tRunString(CharSequence boxed);

	NReturn visit(NAlpha* element, NParam a = 0, NParam b = 0, NParam c = 0);
	NReturn visit(NOmega* element, NParam a = 0, NParam b = 0, NParam c = 0);
};

} // END namespace

#endif
