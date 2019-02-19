#ifndef __NVisitorGraphics_H__
#define __NVisitorGraphics_H__

namespace NSNATIVE
{

class NVisitorGraphics : public NKrossVisitor
{
public:
    NVisitorGraphics(NWrapper* w)
        : NKrossVisitor(w)
    {
    }

    virtual ~NVisitorGraphics()
    {
    }

    //*******************************************************************************************
    //******************************** TOnFrameAvailableListener ********************************
    //*******************************************************************************************
    //void onFrameAvailable(SurfaceTexture surfaceTexture)
    NReturn visit(NAlpha00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (b == -1 && c == 1) vcRet = (NReturn)mNWrapper->mNKrossWrapper->mNKrossFriend->pointer<SurfaceTexture>();
        if (b != -1) ((SurfaceTexture::OnFrameAvailableListener*)a)->onFrameAvailable((SurfaceTexture*)b);
        return vcRet;
    }
};

} // END namespace

#endif
