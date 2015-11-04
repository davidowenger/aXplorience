package y.b;

import android.content.Context;
import android.view.MotionEvent;
import android.widget.LinearLayout;

public class TLinearLayout extends LinearLayout
{
    public TWrapper w;
    public long n;


    //******************************************************************************************
    //************************************* LinearLayout ***************************************
    //******************************************************************************************
    public TLinearLayout(TWrapper w, long n, Context context)
    {
        super(context);
        this.w = w;
        this.n = n;
    }

    //******************************************************************************************
    //******************************* LinearLayout events **************************************
    //* This passes the call back to the default implementation if the method is not overriden *
    //******************************************************************************************
    @Override
    public boolean onInterceptTouchEvent(MotionEvent ev)
    {
        long vcKey;
        return w.mTVisitorViewViewGroup.nRun(w.mTEta00, n,
            (vcKey = w.mTKrossSystem.getKey(ev)) != -1 ? vcKey : w.mTKrossSystem.putKey(w.mTVisitorViewViewGroup.nRun(w.mTEta00, n, -1, 1), ev)
        ) != 0;
    }
}
