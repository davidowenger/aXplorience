#ifndef __NCLOZER_H__
#define __NCLOZER_H__

namespace NSNATIVE
{

class NClozer : public NFrame
{
public:
	NClozer(NWrapper* w);
	virtual ~NClozer();

	NReturn nInit(NINIT cState);
	NReturn tAttachCurrentThread();
	NReturn tDetachCurrentThread();
	NReturnObject tRunString(const String& boxed);
	String tGetString(NReturnObject tString);

	NReturn visit(NAlpha00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0);
};

} // END namespace

#endif
