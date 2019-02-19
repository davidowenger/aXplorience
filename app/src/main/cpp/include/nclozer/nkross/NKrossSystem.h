#ifndef __NKrossSystem_H__
#define __NKrossSystem_H__

namespace NSNATIVE
{

class NKrossSystem : public NKrossVisitor
{
public:
    static const nint GET_W = 0;
    static const nint GET_ELEMENT = GET_W + 1;
    static const nint GET_VISITOR = GET_ELEMENT + 1;

    NKrossSystem(NWrapper* vWrapper);
    virtual ~NKrossSystem();

    virtual NReturn nInit(nint cState);
    virtual NReturn tAttachCurrentThread();
    virtual NReturn tDetachCurrentThread();
    virtual NReturnObject tRunString(const String& boxed);
    virtual String tGetString(NReturnObject tString);
    virtual NReturn tDeleteGlobalRef(NParamObject vGlobalRef);

    NReturn visit(NAlpha00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
};

} // END namespace

#endif
