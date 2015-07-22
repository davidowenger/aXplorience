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
        return w.mTVisitorView.nRun(w.mTAlpha03, n,
            w.tFrame.putKey(w.mTVisitorView.nRun(w.mTAlpha03, n, -1, 1), e)
        ) != 0;
    }

    public boolean onFling(MotionEvent e1, MotionEvent e2, float velocityX, float velocityY)
    {
        return w.mTVisitorView.nRun(w.mTBeta03, n,
            w.tFrame.putKey(w.mTVisitorView.nRun(w.mTBeta03, n, -1, 2), e1),
            w.tFrame.putKey(w.mTVisitorView.nRun(w.mTBeta03, n, -1, 1), e2),
            Double.doubleToRawLongBits(velocityX),
            Double.doubleToRawLongBits(velocityY)
        ) != 0;
    }

    public void onLongPress(MotionEvent e)
    {
        w.mTVisitorView.nRun(w.mTGamma03, n,
            w.tFrame.putKey(w.mTVisitorView.nRun(w.mTGamma03, n, -1, 1), e)
        );
    }

    public boolean onScroll(MotionEvent e1, MotionEvent e2, float distanceX, float distanceY)
    {
        return w.mTVisitorView.nRun(w.mTDelta03, n,
            w.tFrame.putKey(w.mTVisitorView.nRun(w.mTDelta03, n, -1, 2), e1),
            w.tFrame.putKey(w.mTVisitorView.nRun(w.mTDelta03, n, -1, 1), e2),
            Double.doubleToRawLongBits(distanceX),
            Double.doubleToRawLongBits(distanceY)
        ) != 0;
    }

    public void onShowPress(MotionEvent e)
    {
        w.mTVisitorView.nRun(w.mTEpsilon03, n,
            w.tFrame.putKey(w.mTVisitorView.nRun(w.mTEpsilon03, n, -1, 1), e)
        );
    }

    public boolean onSingleTapUp(MotionEvent e)
    {
        return w.mTVisitorView.nRun(w.mTDzeta03, n,
            w.tFrame.putKey(w.mTVisitorView.nRun(w.mTDzeta03, n, -1, 1), e)
        ) != 0;
    }
}
