package y.b;

import android.graphics.SurfaceTexture;

//*******************************************************************************************
//************************************ OnFrameAvailableListener *****************************
//*******************************************************************************************
public class TOnFrameAvailableListener implements SurfaceTexture.OnFrameAvailableListener
{
    public TWrapper w;
    public long n;

    public TOnFrameAvailableListener(TWrapper w, long n)
    {
        this.w = w;
        this.n = n;
    }

    @Override
    public void onFrameAvailable(SurfaceTexture surfaceTexture)
    {
        long vcKey;

        if (w != null && w.isAlive) {
            w.mTVisitorGraphics.nRun(w.mTAlpha00, n,
                (vcKey = w.mTKrossSystem.getKey(surfaceTexture)) != -1 ? vcKey : w.mTKrossSystem.putKey(w.mTVisitorGraphics.nRun(w.mTAlpha00, n, -1, 1), surfaceTexture)
            );
        }
    }
}
