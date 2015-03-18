package z.a;

import android.view.View;
import android.widget.AdapterView;

//*******************************************************************************************
//*********************************** OnItemSelectedListener ********************************
//*******************************************************************************************
public class TOnItemSelectedListener implements AdapterView.OnItemSelectedListener
{
    public TWrapper w;
    public long n;

    public TOnItemSelectedListener(TWrapper w, long n)
    {
        this.w = w;
        this.n = n;
    }

    public void onItemSelected(AdapterView<?> parent, View view, int position, long id)
    {
        w.mTVisitorWidgetView.nRun(w.mTAlpha03, n,
            w.tFrame.putKey(w.mTVisitorView.nRun(w.mTAlpha03, n, -1, 2), parent),
            w.tFrame.putKey(w.mTVisitorView.nRun(w.mTAlpha03, n, -1, 1), view),
            position,
            id
        );
    }

    public void onNothingSelected(AdapterView<?> parent)
    {
        w.mTVisitorWidgetView.nRun(w.mTBeta03, n,
            w.tFrame.putKey(w.mTVisitorView.nRun(w.mTBeta03, n, -1, 1), parent)
        );
    }
}