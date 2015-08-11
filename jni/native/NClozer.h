#ifndef __NCLOZER_H__
#define __NCLOZER_H__

namespace NSNATIVE
{

class NClozer : public NFrame
{
public:
    NClozer(NWrapper* w);
    virtual ~NClozer() override;

    virtual NReturn nInit(nint cState) override;
    virtual NReturn tAttachCurrentThread() override;
    virtual NReturn tDetachCurrentThread() override;
    virtual NReturnObject tRunString(const String& boxed) override;
    virtual String tGetString(NReturnObject tString) override;
    virtual NReturn tDeleteGlobalRef(NParamObject vGlobalRef) override;

    NReturn visit(NAlpha00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
};

} // END namespace

#endif
