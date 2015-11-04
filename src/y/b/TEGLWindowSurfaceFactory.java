package y.b;

import javax.microedition.khronos.egl.EGL10;
import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.egl.EGLDisplay;
import javax.microedition.khronos.egl.EGLSurface;
import android.opengl.GLSurfaceView;

//*******************************************************************************************
//************************************ OnFrameAvailableListener *****************************
//*******************************************************************************************
public class TEGLWindowSurfaceFactory implements GLSurfaceView.EGLWindowSurfaceFactory
{
    public TWrapper w;
    public long n;

    public TEGLWindowSurfaceFactory(TWrapper w, long n)
    {
        this.w = w;
        this.n = n;
    }

    public EGLSurface createWindowSurface(EGL10 egl, EGLDisplay display, EGLConfig config, Object nativeWindow)
    {
        return w.mTKrossSystem.getValue(w.mTVisitorOpengl.nRun(w.mTDelta00, n,
            0,
            0,
            0,
            0
        ), EGLSurface.class);
    }

    public void destroySurface(EGL10 egl, EGLDisplay display, EGLSurface surface)
    {
        long vcKey;
        w.mTVisitorOpengl.nRun(w.mTEpsilon00, n,
            0,
            0,
            (vcKey = w.mTKrossSystem.getKey(surface)) != -1 ? vcKey : w.mTKrossSystem.putKey(w.mTVisitorOpengl.nRun(w.mTEpsilon00, 0, 1), surface)
        );
    }
}
