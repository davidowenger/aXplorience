#ifndef __NFRAME_H__
#define __NFRAME_H__

namespace NSNATIVE
{

class NFrame : public NVisitor
{
public:
    static const nint GET_W = 0;
    static const nint GET_ELEMENT = GET_W + 1;
    static const nint GET_VISITOR = GET_ELEMENT + 1;

    NFrame(NWrapper* w);
    virtual ~NFrame();

    virtual NReturn nInit(nint cState) = 0;
    virtual NReturn tAttachCurrentThread() = 0;
    virtual NReturn tDetachCurrentThread() = 0;
    virtual NReturnObject tRunString(const String& boxed) = 0;
    virtual String tGetString(NReturnObject tString) = 0;
    virtual NReturn tDeleteGlobalRef(NParamObject vGlobalRef) = 0;
};

} // END namespace

#endif
