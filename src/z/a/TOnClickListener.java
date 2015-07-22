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
		long vcKey;
		w.mTVisitorViewView.nRun(w.mTAlpha03, n,
			(vcKey = w.tFrame.getKey(v)) != -1 ? vcKey : w.tFrame.putKey(w.mTVisitorViewView.nRun(w.mTAlpha03, n, -1, 1), v)
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

	public TOnCreateContextMenuListener(TWrapper w, long n)
    {
        this.w = w;
        this.n = n;
    }

	@Override
	public void onCreateContextMenu(ContextMenu menu, View v, ContextMenu.ContextMenuInfo menuInfo)
	{
		long vcKey;
		w.mTVisitorViewView.nRun(w.mTBeta03, n,
			(vcKey = w.tFrame.getKey(menu)) != -1 ? vcKey : w.tFrame.putKey(w.mTVisitorViewView.nRun(w.mTBeta03, n, -1, 3), menu),
			(vcKey = w.tFrame.getKey(v)) != -1 ? vcKey : w.tFrame.putKey(w.mTVisitorViewView.nRun(w.mTBeta03, n, -1, 2), v),
			(vcKey = w.tFrame.getKey(menuInfo)) != -1 ? vcKey : w.tFrame.putKey(w.mTVisitorViewView.nRun(w.mTBeta03, n, -1, 1), menuInfo)
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

	public TOnTouchListener(TWrapper w, long n)
    {
        this.w = w;
        this.n = n;
    }

	@Override
	public boolean onTouch(View v, MotionEvent event)
	{
        long vcKey;
		return w.mTVisitorViewView.nRun(w.mTGamma03, n,
			(vcKey = w.tFrame.getKey(v)) != -1 ? vcKey : w.tFrame.putKey(w.mTVisitorViewView.nRun(w.mTGamma03, n, -1, 2), v),
			w.tFrame.putKey(w.mTVisitorViewView.nRun(w.mTGamma03, n, -1, 1), event)
		) != 0;
	}
}
