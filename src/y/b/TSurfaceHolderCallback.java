package y.b;

import android.view.SurfaceHolder;

//*******************************************************************************************
//************************************ TSurfaceHolderCallback *******************************
//*******************************************************************************************
public class TSurfaceHolderCallback implements SurfaceHolder.Callback
{
    public TWrapper w;
    public long n;

    public TSurfaceHolderCallback(TWrapper w, long n)
    {
        this.w = w;
        this.n = n;
    }

    public void surfaceCreated(SurfaceHolder holder)
    {
        long vcKey;
        w.mTVisitorView.nRun(w.mTAlpha00, n,
            (vcKey = w.mTKrossSystem.getKey(holder)) != -1 ? vcKey : w.mTKrossSystem.putKey(w.mTVisitorView.nRun(w.mTAlpha00, 0, 1), holder)
        );
    }

    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height)
    {
        long vcKey;
        w.mTVisitorView.nRun(w.mTBeta00, n,
            (vcKey = w.mTKrossSystem.getKey(holder)) != -1 ? vcKey : w.mTKrossSystem.putKey(w.mTVisitorView.nRun(w.mTBeta00, 0, 1), holder),
            format,
            width,
            height
        );
    }

    public void surfaceDestroyed(SurfaceHolder holder)
    {
        long vcKey;
        w.mTVisitorView.nRun(w.mTGamma00, n,
            (vcKey = w.mTKrossSystem.getKey(holder)) != -1 ? vcKey : w.mTKrossSystem.putKey(w.mTVisitorView.nRun(w.mTGamma00, 0, 1), holder)
        );
    }
}

//*******************************************************************************************
//****************************** TSurfaceHolderCallback2 ************************************
//*******************************************************************************************
class TSurfaceHolderCallback2 extends TSurfaceHolderCallback implements SurfaceHolder.Callback, SurfaceHolder.Callback2
{
    public TSurfaceHolderCallback2(TWrapper w, long n)
    {
        super(w, n);
    }

    public void surfaceRedrawNeeded(SurfaceHolder holder)
    {
        long vcKey;
        w.mTVisitorViewView.nRun(w.mTDelta00, n,
            (vcKey = w.mTKrossSystem.getKey(holder)) != -1 ? vcKey : w.mTKrossSystem.putKey(w.mTVisitorView.nRun(w.mTDelta00, 0, 1), holder)
        );
    }
}
