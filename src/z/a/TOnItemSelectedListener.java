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
        long vcKey;
        w.mTVisitorWidgetView.nRun(w.mTAlpha03, n,
            (vcKey = w.tFrame.getKey(parent)) != -1 ? vcKey : w.tFrame.putKey(w.mTVisitorView.nRun(w.mTAlpha03, n, -1, 2), parent),
            (vcKey = w.tFrame.getKey(view)) != -1 ? vcKey : w.tFrame.putKey(w.mTVisitorView.nRun(w.mTAlpha03, n, -1, 1), view),
            position,
            id
        );
    }

    public void onNothingSelected(AdapterView<?> parent)
    {
        long vcKey;
        w.mTVisitorWidgetView.nRun(w.mTBeta03, n,
            (vcKey = w.tFrame.getKey(parent)) != -1 ? vcKey : w.tFrame.putKey(w.mTVisitorView.nRun(w.mTBeta03, n, -1, 1), parent)
        );
    }
}