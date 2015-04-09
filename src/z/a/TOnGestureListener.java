package z.a;

import android.view.GestureDetector;
import android.view.MotionEvent;

//*******************************************************************************************
//*********************************** OnGestureListener *************************************
//*******************************************************************************************
public class TOnGestureListener implements GestureDetector.OnGestureListener
{
    public TWrapper w;
    public long n;

    public TOnGestureListener(TWrapper w, long n)
    {
        this.w = w;
        this.n = n;
    }

    public boolean onDown(MotionEvent e)
    {
        long vcKey;
        return w.mTVisitorView.nRun(w.mTAlpha03, n,
            (vcKey = w.tFrame.getKey(e)) != -1 ? vcKey : w.tFrame.putKey(w.mTVisitorView.nRun(w.mTAlpha03, n, -1, 1), e)
        ) != 0;
    }

    public boolean onFling(MotionEvent e1, MotionEvent e2, float velocityX, float velocityY)
    {
        long vcKey;
        return w.mTVisitorView.nRun(w.mTBeta03, n,
            (vcKey = w.tFrame.getKey(e1)) != -1 ? vcKey : w.tFrame.putKey(w.mTVisitorView.nRun(w.mTBeta03, n, -1, 2), e1),
            (vcKey = w.tFrame.getKey(e2)) != -1 ? vcKey : w.tFrame.putKey(w.mTVisitorView.nRun(w.mTBeta03, n, -1, 1), e2),
            Double.doubleToRawLongBits(velocityX),
            Double.doubleToRawLongBits(velocityY)
        ) != 0;
    }

    public void onLongPress(MotionEvent e)
    {
        long vcKey;
        w.mTVisitorView.nRun(w.mTGamma03, n,
            (vcKey = w.tFrame.getKey(e)) != -1 ? vcKey : w.tFrame.putKey(w.mTVisitorView.nRun(w.mTGamma03, n, -1, 1), e)
        );
    }

    public boolean onScroll(MotionEvent e1, MotionEvent e2, float distanceX, float distanceY)
    {
        long vcKey;
        return w.mTVisitorView.nRun(w.mTDelta03, n,
            (vcKey = w.tFrame.getKey(e1)) != -1 ? vcKey : w.tFrame.putKey(w.mTVisitorView.nRun(w.mTDelta03, n, -1, 2), e1),
            (vcKey = w.tFrame.getKey(e2)) != -1 ? vcKey : w.tFrame.putKey(w.mTVisitorView.nRun(w.mTDelta03, n, -1, 1), e2),
            Double.doubleToRawLongBits(distanceX),
            Double.doubleToRawLongBits(distanceY)
        ) != 0;
    }

    public void onShowPress(MotionEvent e)
    {
        long vcKey;
        w.mTVisitorView.nRun(w.mTEpsilon03, n,
            (vcKey = w.tFrame.getKey(e)) != -1 ? vcKey : w.tFrame.putKey(w.mTVisitorView.nRun(w.mTEpsilon03, n, -1, 1), e)
        );
    }

    public boolean onSingleTapUp(MotionEvent e)
    {
        long vcKey;
        return w.mTVisitorView.nRun(w.mTDzeta03, n,
            (vcKey = w.tFrame.getKey(e)) != -1 ? vcKey : w.tFrame.putKey(w.mTVisitorView.nRun(w.mTDzeta03, n, -1, 1), e)
        ) != 0;
    }
}
