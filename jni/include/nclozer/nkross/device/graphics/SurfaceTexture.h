#ifndef __SurfaceTexture_H__
#define __SurfaceTexture_H__

namespace NSDEVICE
{

class SurfaceTexture : public Object
{
friend NSNATIVE::NKrossFriend;

public:
    class OnFrameAvailableListener
    {
    public:
        virtual ~OnFrameAvailableListener()
        {
            NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNDelta00, (NParam)this);
        }

        virtual void onFrameAvailable(SurfaceTexture* surfaceTexture) = 0;

    protected:
        OnFrameAvailableListener()
        {
            NSNKROSS::w->mNVisitorGraphics->tRun(NSNKROSS::w->mNIota00, (NParam)this);
        }
    };

    SurfaceTexture(int texName)
    {
        NSNKROSS::w->mNVisitorGraphics->tRun(NSNKROSS::w->mNKappa00, (NParam)this, (NParam)texName);
    }

    SurfaceTexture(int texName, bool singleBufferMode)
    {
        NSNKROSS::w->mNVisitorGraphics->tRun(NSNKROSS::w->mNLambda00, (NParam)this, (NParam)texName, (NParam)singleBufferMode);
    }

    virtual ~SurfaceTexture()
    {
    }

    // The mtx array must have exactly 16 elements
    virtual void getTransformMatrix(NArray<float> mtx)
    {
        NReturn index = NSNKROSS::w->mNVisitorGraphics->tRun(NSNKROSS::w->mNMu00, (NParam)this);
        NReturn size = NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNAlpha01, index, -1);
        nuint i;

        for (i = 0 ; i < size && i < mtx.mcData ; ++i) {
            nlong vcValue = (nint)NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNAlpha01, index, (NParam)i);
            mtx.maData[i] = (nfloat)*reinterpret_cast<ndouble*>(&vcValue);
        }
    }

    virtual void release()
    {
        NSNKROSS::w->mNVisitorGraphics->tRun(NSNKROSS::w->mNNu00, (NParam)this);
    }

    virtual void releaseTexImage()
    {
        NSNKROSS::w->mNVisitorGraphics->tRun(NSNKROSS::w->mNXi00, (NParam)this);
    }

    virtual void setDefaultBufferSize(int width, int height)
    {
        NSNKROSS::w->mNVisitorGraphics->tRun(NSNKROSS::w->mNOmicron00, (NParam)this, (NParam)width, (NParam)height);
    }

    virtual void setOnFrameAvailableListener(SurfaceTexture::OnFrameAvailableListener* listener)
    {
        NSNKROSS::w->mNVisitorGraphics->tRun(NSNKROSS::w->mNPi00, (NParam)this, (NParam)listener);
    }

    virtual void updateTexImage()
    {
        NSNKROSS::w->mNVisitorGraphics->tRun(NSNKROSS::w->mNRho00, (NParam)this);
    }

private:
    SurfaceTexture(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
