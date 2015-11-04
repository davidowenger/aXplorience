package y.b;

import android.content.Context;
import android.opengl.GLSurfaceView;

public class TVisitorOpengl extends TKrossVisitor
{
    public TVisitorOpengl(TWrapper w) {
        super(w);
    }

    //*******************************************************************************
    //************************ GLSurfaceView.EGLWindowSurfaceFactory ****************
    //*******************************************************************************
    // EGLWindowSurfaceFactory()
    public long visit(TMu00 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put(a, new TEGLWindowSurfaceFactory(w, a));
        return 0;
    }

    //*******************************************************************************
    //************************ GLSurfaceView.Renderer *******************************
    //*******************************************************************************
    // Renderer()
    public long visit(TAlpha00 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put(a, new TRenderer(w, a));
        return 0;
    }

    //*******************************************************************************
    //************************** GLSurfaceView **************************************
    //*******************************************************************************
    // GLSurfaceView(Context* context)
    public long visit(TBeta00 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put(a, new GLSurfaceView(w.mTKrossSystem.getValue(b, Context.class)));
        return 0;
    }

    // void onPause()
    public long visit(TGamma00 element, long a, long b, long c, long d, long e)
    {
        ((GLSurfaceView)w.sObject.get(a)).onPause();
        return 0;
    }

    // void onResume()
    public long visit(TDelta00 element, long a, long b, long c, long d, long e)
    {
        ((GLSurfaceView)w.sObject.get(a)).onResume();
        return 0;
    }

    // void requestRender()
    public long visit(TEpsilon00 element, long a, long b, long c, long d, long e)
    {
        ((GLSurfaceView)w.sObject.get(a)).requestRender();
        return 0;
    }

    // void setDebugFlags(int debugFlags)
    public long visit(TDzeta00 element, long a, long b, long c, long d, long e)
    {
        ((GLSurfaceView)w.sObject.get(a)).setDebugFlags((int)b);
        return 0;
    }

    // void setEGLConfigChooser(int redSize, int greenSize, int blueSize, int alphaSize, int depthSize, int stencilSize)
    public long visit(TEta00 element, long a, long b, long c, long d, long e)
    {
        ((GLSurfaceView)w.sObject.get(a)).setEGLConfigChooser(0xFF&(int)b>>24, 0xFF&(int)b>>16, 0xFF&(int)b>>8, 0xFF&(int)b, (int)c, (int)d);
        return 0;
    }

    // void setEGLContextClientVersion(int version)
    public long visit(TTheta00 element, long a, long b, long c, long d, long e)
    {
        ((GLSurfaceView)w.sObject.get(a)).setEGLContextClientVersion((int)b);
        return 0;
    }

    // void setEGLWindowSurfaceFactory(GLSurfaceView::EGLWindowSurfaceFactory* factory)
    public long visit(TNu00 element, long a, long b, long c, long d, long e)
    {
        ((GLSurfaceView)w.sObject.get(a)).setEGLWindowSurfaceFactory(w.mTKrossSystem.getValue(b, GLSurfaceView.EGLWindowSurfaceFactory.class));
        return 0;
    }

    // void setPreserveEGLContextOnPause(bool preserveOnPause)
    public long visit(TIota00 element, long a, long b, long c, long d, long e)
    {
        ((GLSurfaceView)w.sObject.get(a)).setPreserveEGLContextOnPause(b != 0);
        return 0;
    }

    // void setRenderMode(int renderMode)
    public long visit(TKappa00 element, long a, long b, long c, long d, long e)
    {
        ((GLSurfaceView)w.sObject.get(a)).setRenderMode((int)b);
        return 0;
    }

    // void setRenderer(GLSurfaceView::Renderer* renderer)
    public long visit(TLambda00 element, long a, long b, long c, long d, long e)
    {
        ((GLSurfaceView)w.sObject.get(a)).setRenderer(w.mTKrossSystem.getValue(b, GLSurfaceView.Renderer.class));
        return 0;
    }
}
