#ifndef __GLSurfaceView_H__
#define __GLSurfaceView_H__

namespace NSDEVICE
{

class GLSurfaceView : public SurfaceView
{
friend NSNATIVE::NKrossFriend;

public:
    static const int DEBUG_CHECK_GL_ERROR = 0x00000001;
    static const int DEBUG_LOG_GL_CALLS = 0x00000002;
    static const int RENDERMODE_CONTINUOUSLY = 0x00000001;
    static const int RENDERMODE_WHEN_DIRTY = 0x00000000;

    class EGLWindowSurfaceFactory
    {
    friend NSNATIVE::NKrossFriend;

    public:
        virtual ~EGLWindowSurfaceFactory()
        {
            NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNDelta00, (NParam)this);
        }

        virtual void* createWindowSurface(GL10* gll, void* display, void* config, Object* nativeWindow) = 0;
        virtual void destroySurface(GL10* gll, void* display, void* surface) = 0;

    protected:
        EGLWindowSurfaceFactory()
        {
            NKrossWrapper::w->mNVisitorOpengl->tRun(NKrossWrapper::w->mNMu00, (NParam)this);
        }
    };

    class Renderer
    {
    friend NSNATIVE::NKrossFriend;

    public:
        virtual ~Renderer()
        {
            NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNDelta00, (NParam)this);
        }

        virtual void onDrawFrame(GL10* gl) = 0;
        virtual void onSurfaceChanged(GL10* gl, int width, int height) = 0;
        virtual void onSurfaceCreated(GL10* gl, void* config) = 0;

    protected:
        Renderer()
        {
            NKrossWrapper::w->mNVisitorOpengl->tRun(NKrossWrapper::w->mNAlpha00, (NParam)this);
        }
    };

    GLSurfaceView(Context* context)
        : SurfaceView(NKrossWrapper::w->mNKrossFriend->instance<SurfaceView>())
    {
        NKrossWrapper::w->mNVisitorOpengl->tRun(NKrossWrapper::w->mNBeta00, (NParam)this, (NParam)context);
    }

    virtual ~GLSurfaceView()
    {
    }

    virtual void onPause()
    {
        NKrossWrapper::w->mNVisitorOpengl->tRun(NKrossWrapper::w->mNGamma00, (NParam)this);
    }

    virtual void onResume()
    {
        NKrossWrapper::w->mNVisitorOpengl->tRun(NKrossWrapper::w->mNDelta00, (NParam)this);
    }

    virtual void requestRender()
    {
        NKrossWrapper::w->mNVisitorOpengl->tRun(NKrossWrapper::w->mNEpsilon00, (NParam)this);
    }

    virtual void setDebugFlags(int debugFlags)
    {
        NKrossWrapper::w->mNVisitorOpengl->tRun(NKrossWrapper::w->mNDzeta00, (NParam)this, (NParam)debugFlags);
    }

    virtual void setEGLConfigChooser(int redSize, int greenSize, int blueSize, int alphaSize, int depthSize, int stencilSize)
    {
        NKrossWrapper::w->mNVisitorOpengl->tRun(NKrossWrapper::w->mNEta00, (NParam)this, (NParam)((redSize<<24) + (greenSize<<16) + (blueSize<<8) + alphaSize), (NParam)depthSize, (NParam)stencilSize);
    }

    virtual void setEGLContextClientVersion(int version)
    {
        NKrossWrapper::w->mNVisitorOpengl->tRun(NKrossWrapper::w->mNTheta00, (NParam)this, (NParam)version);
    }

    virtual void setEGLWindowSurfaceFactory(GLSurfaceView::EGLWindowSurfaceFactory* factory)
    {
        NKrossWrapper::w->mNVisitorOpengl->tRun(NKrossWrapper::w->mNNu00, (NParam)this, (NParam)factory);
    }

    virtual void setPreserveEGLContextOnPause(bool preserveOnPause)
    {
        NKrossWrapper::w->mNVisitorOpengl->tRun(NKrossWrapper::w->mNIota00, (NParam)this, (NParam)preserveOnPause);
    }

    virtual void setRenderMode(int renderMode)
    {
        NKrossWrapper::w->mNVisitorOpengl->tRun(NKrossWrapper::w->mNKappa00, (NParam)this, (NParam)renderMode);
    }

    virtual void setRenderer(GLSurfaceView::Renderer* renderer)
    {
        NKrossWrapper::w->mNVisitorOpengl->tRun(NKrossWrapper::w->mNLambda00, (NParam)this, (NParam)renderer);
    }

private:
    GLSurfaceView(NKrossFriend* vNKrossFriend)
        : SurfaceView(NKrossWrapper::w->mNKrossFriend->instance<SurfaceView>())
    {
    }
};

} // End namespace

#endif
