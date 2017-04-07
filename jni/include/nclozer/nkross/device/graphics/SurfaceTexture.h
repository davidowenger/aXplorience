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
            NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNDelta00, (NParam)this);
        }

        virtual void onFrameAvailable(SurfaceTexture* surfaceTexture) = 0;

    protected:
        OnFrameAvailableListener()
        {
            NKrossWrapper::w->mNVisitorGraphics->tRun(NKrossWrapper::w->mNIota00, (NParam)this);
        }
    };

    SurfaceTexture(int texName)
    {
        NKrossWrapper::w->mNVisitorGraphics->tRun(NKrossWrapper::w->mNKappa00, (NParam)this, (NParam)texName);
    }

    SurfaceTexture(int texName, bool singleBufferMode)
    {
        NKrossWrapper::w->mNVisitorGraphics->tRun(NKrossWrapper::w->mNLambda00, (NParam)this, (NParam)texName, (NParam)singleBufferMode);
    }

    virtual ~SurfaceTexture()
    {
    }

    // The mtx array must have exactly 16 elements
    virtual void getTransformMatrix(NArray<float> mtx)
    {
        NReturn index = NKrossWrapper::w->mNVisitorGraphics->tRun(NKrossWrapper::w->mNMu00, (NParam)this);
        NReturn size = NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNAlpha01, index, -1);
        nuint i;

        for (i = 0 ; i < size && i < mtx.mcData ; ++i) {
            nlong vcValue = (nint)NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNAlpha01, index, (NParam)i);
            mtx.maData[i] = (nfloat)*reinterpret_cast<ndouble*>(&vcValue);
        }
    }

    virtual void release()
    {
        NKrossWrapper::w->mNVisitorGraphics->tRun(NKrossWrapper::w->mNNu00, (NParam)this);
    }

    virtual void releaseTexImage()
    {
        NKrossWrapper::w->mNVisitorGraphics->tRun(NKrossWrapper::w->mNXi00, (NParam)this);
    }

    virtual void setDefaultBufferSize(int width, int height)
    {
        NKrossWrapper::w->mNVisitorGraphics->tRun(NKrossWrapper::w->mNOmicron00, (NParam)this, (NParam)width, (NParam)height);
    }

    virtual void setOnFrameAvailableListener(SurfaceTexture::OnFrameAvailableListener* listener)
    {
        NKrossWrapper::w->mNVisitorGraphics->tRun(NKrossWrapper::w->mNPi00, (NParam)this, (NParam)listener);
    }

    virtual void updateTexImage()
    {
        NKrossWrapper::w->mNVisitorGraphics->tRun(NKrossWrapper::w->mNRho00, (NParam)this);
    }

private:
    SurfaceTexture(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
