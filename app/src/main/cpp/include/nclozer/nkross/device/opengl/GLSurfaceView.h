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
            NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNDelta00, (NParam)this);
        }

        virtual void* createWindowSurface(GL10* gll, void* display, void* config, Object* nativeWindow) = 0;
        virtual void destroySurface(GL10* gll, void* display, void* surface) = 0;

    protected:
        EGLWindowSurfaceFactory()
        {
            NSNKROSS::w->mNVisitorOpengl->tRun(NSNKROSS::w->mNMu00, (NParam)this);
        }
    };

    class Renderer
    {
    friend NSNATIVE::NKrossFriend;

    public:
        virtual ~Renderer()
        {
            NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNDelta00, (NParam)this);
        }

        virtual void onDrawFrame(GL10* gl) = 0;
        virtual void onSurfaceChanged(GL10* gl, int width, int height) = 0;
        virtual void onSurfaceCreated(GL10* gl, void* config) = 0;

    protected:
        Renderer()
        {
            NSNKROSS::w->mNVisitorOpengl->tRun(NSNKROSS::w->mNAlpha00, (NParam)this);
        }
    };

    GLSurfaceView(Context* context)
        : SurfaceView(NSNKROSS::w->mNKrossFriend->instance<SurfaceView>())
    {
        NSNKROSS::w->mNVisitorOpengl->tRun(NSNKROSS::w->mNBeta00, (NParam)this, (NParam)context);
    }

    virtual ~GLSurfaceView()
    {
    }

    virtual void onPause()
    {
        NSNKROSS::w->mNVisitorOpengl->tRun(NSNKROSS::w->mNGamma00, (NParam)this);
    }

    virtual void onResume()
    {
        NSNKROSS::w->mNVisitorOpengl->tRun(NSNKROSS::w->mNDelta00, (NParam)this);
    }

    virtual void requestRender()
    {
        NSNKROSS::w->mNVisitorOpengl->tRun(NSNKROSS::w->mNEpsilon00, (NParam)this);
    }

    virtual void setDebugFlags(int debugFlags)
    {
        NSNKROSS::w->mNVisitorOpengl->tRun(NSNKROSS::w->mNDzeta00, (NParam)this, (NParam)debugFlags);
    }

    virtual void setEGLConfigChooser(int redSize, int greenSize, int blueSize, int alphaSize, int depthSize, int stencilSize)
    {
        NSNKROSS::w->mNVisitorOpengl->tRun(NSNKROSS::w->mNEta00, (NParam)this, (NParam)((redSize<<24) + (greenSize<<16) + (blueSize<<8) + alphaSize), (NParam)depthSize, (NParam)stencilSize);
    }

    virtual void setEGLContextClientVersion(int version)
    {
        NSNKROSS::w->mNVisitorOpengl->tRun(NSNKROSS::w->mNTheta00, (NParam)this, (NParam)version);
    }

    virtual void setEGLWindowSurfaceFactory(GLSurfaceView::EGLWindowSurfaceFactory* factory)
    {
        NSNKROSS::w->mNVisitorOpengl->tRun(NSNKROSS::w->mNNu00, (NParam)this, (NParam)factory);
    }

    virtual void setPreserveEGLContextOnPause(bool preserveOnPause)
    {
        NSNKROSS::w->mNVisitorOpengl->tRun(NSNKROSS::w->mNIota00, (NParam)this, (NParam)preserveOnPause);
    }

    virtual void setRenderMode(int renderMode)
    {
        NSNKROSS::w->mNVisitorOpengl->tRun(NSNKROSS::w->mNKappa00, (NParam)this, (NParam)renderMode);
    }

    virtual void setRenderer(GLSurfaceView::Renderer* renderer)
    {
        NSNKROSS::w->mNVisitorOpengl->tRun(NSNKROSS::w->mNLambda00, (NParam)this, (NParam)renderer);
    }

private:
    GLSurfaceView(NKrossFriend* vNKrossFriend)
        : SurfaceView(NSNKROSS::w->mNKrossFriend->instance<SurfaceView>())
    {
    }
};

} // End namespace

#endif
