package y.b;

import javax.microedition.khronos.opengles.GL10;
import javax.microedition.khronos.egl.EGLConfig;

import android.opengl.GLSurfaceView;

//*******************************************************************************************
//************************************ OnFrameAvailableListener *****************************
//*******************************************************************************************
public class TRenderer implements GLSurfaceView.Renderer
{
    public TWrapper w;
    public long n;

    public TRenderer(TWrapper w, long n)
    {
        this.w = w;
        this.n = n;
    }

    @Override
    public void onDrawFrame(GL10 gl)
    {
        w.mTVisitorOpengl.nRun(w.mTAlpha00, n,
            0
        );
    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height)
    {
        w.mTVisitorOpengl.nRun(w.mTBeta00, n,
            0,
            width,
            height
        );
    }

    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config)
    {
        w.mTVisitorOpengl.nRun(w.mTGamma00, n,
            0,
            0
        );
    }
}
