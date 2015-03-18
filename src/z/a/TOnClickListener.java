package z.a;

import android.view.ContextMenu;
import android.view.MotionEvent;
import android.view.View;

//*******************************************************************************************
//************************************ OnClickListener **************************************
//*******************************************************************************************
public class TOnClickListener implements View.OnClickListener
{
    public TWrapper w;
    public long n;

    public TOnClickListener(TWrapper w, long n)
    {
        this.w = w;
        this.n = n;
    }

    @Override
    public void onClick(View v)
    {
      w.mTVisitorView.nRun(w.mTAlpha03, n,
          w.tFrame.putKey(w.mTVisitorView.nRun(w.mTAlpha03, n, -1, 1), v)
      );
    }
}

//*******************************************************************************************
//****************************** OnCreateContextMenuListener ********************************
//*******************************************************************************************
class TOnCreateContextMenuListener implements View.OnCreateContextMenuListener
{
    public TWrapper w;
    public long n;

    public TOnCreateContextMenuListener()
    {
    }

    @Override
    public void onCreateContextMenu(ContextMenu menu, View v, ContextMenu.ContextMenuInfo menuInfo)
    {
      w.mTVisitorView.nRun(w.mTBeta03, n,
          w.tFrame.putKey(w.mTVisitorView.nRun(w.mTBeta03, n, -1, 3), menu),
          w.tFrame.putKey(w.mTVisitorView.nRun(w.mTBeta03, n, -1, 2), v),
          w.tFrame.putKey(w.mTVisitorView.nRun(w.mTBeta03, n, -1, 1), menuInfo)
      );
    }
}

//******************************************************************************************
//************************************* OnTouchListener ************************************
//******************************************************************************************
class TOnTouchListener implements View.OnTouchListener
{
    public TWrapper w;
    public long n;

    public TOnTouchListener()
    {
    }

    @Override
    public boolean onTouch(View v, MotionEvent event)
    {
        return w.mTVisitorView.nRun(w.mTGamma03, n,
            w.tFrame.putKey(w.mTVisitorView.nRun(w.mTGamma03, n, -1, 2), v),
            w.tFrame.putKey(w.mTVisitorView.nRun(w.mTGamma03, n, -1, 1), event)
        ) != 0;
    }
}
