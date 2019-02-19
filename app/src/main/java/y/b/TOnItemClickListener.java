package y.b;

import android.view.View;
import android.widget.AdapterView;

//*******************************************************************************************
//*********************************** OnItemClickListener ***********************************
//*******************************************************************************************
public class TOnItemClickListener implements AdapterView.OnItemClickListener
{
    public TWrapper w;
    public long n;

    public TOnItemClickListener(TWrapper w, long n)
    {
        this.w = w;
        this.n = n;
    }

    public void onItemClick(AdapterView<?> parent, View view, int position, long id)
    {
        long vcKey;
        w.mTVisitorWidgetView.nRun(w.mTGamma03, n,
            (vcKey = w.mTKrossSystem.getKey(parent)) != -1 ? vcKey : w.mTKrossSystem.putKey(w.mTVisitorWidgetView.nRun(w.mTGamma03, n, -1, 2), parent),
            (vcKey = w.mTKrossSystem.getKey(view)) != -1 ? vcKey : w.mTKrossSystem.putKey(w.mTVisitorWidgetView.nRun(w.mTGamma03, n, -1, 1), view),
            position,
            id
        );
    }
}
