package z.a;

import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;

//*******************************************************************************************
//**************************************** BaseAdapter **************************************
//*******************************************************************************************
public class TBaseAdapter extends BaseAdapter
{
    public TWrapper w;
    public long n;

    public TBaseAdapter(TWrapper w, long n)
    {
        this.w = w;
        this.n = n;
    }

    @Override
    public int getCount()
    {
        return (int)w.mTVisitorWidget.nRun(w.mTAlpha01, n);
    }

    @Override
    public View getDropDownView(int position, View convertView, ViewGroup parent)
    {
        return (View)w.sObject.get("" + w.mTVisitorWidget.nRun(w.mTBeta01,n,
            position,
            w.tFrame.putKey(w.mTVisitorWidget.nRun(w.mTBeta01, n, -1, 2), convertView),
            w.tFrame.putKey(w.mTVisitorWidget.nRun(w.mTBeta01, n, -1, 1), parent)
        ));
    }

    @Override
    public Object getItem(int position)
    {
        return w.sObject.get("" + w.mTVisitorWidget.nRun(w.mTGamma01,n,
            position
        ));
    }

    @Override
    public long getItemId(int position)
    {
        return w.mTVisitorWidget.nRun(w.mTDelta01, n,
            position
        );
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent)
    {
        return (View)w.sObject.get("" + w.mTVisitorWidget.nRun(w.mTEpsilon01,n,
            position,
            w.tFrame.putKey(w.mTVisitorWidget.nRun(w.mTEpsilon01, n, -1, 2), convertView),
            w.tFrame.putKey(w.mTVisitorWidget.nRun(w.mTEpsilon01, n, -1, 1), parent)
        ));
    }

    //*******************************************************************************************
    //************************************ BaseAdapter : super **********************************
    //*******************************************************************************************
    public View getDropDownViewParent(int position, View convertView, ViewGroup parent)
    {
        return super.getDropDownView(position, convertView, parent);
    }

}
