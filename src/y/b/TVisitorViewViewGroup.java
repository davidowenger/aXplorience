package y.b;

import android.view.View;
import android.view.ViewGroup;

public class TVisitorViewViewGroup extends TVisitor
{
    public TVisitorViewViewGroup(TWrapper w) {
        super(w);
    }

    //******************************************************************************************
    //***************************************** ViewGroup **************************************
    //******************************************************************************************
    // void addView(View* view)
    public long visit(TAlpha00 element, long a, long b, long c, long d, long e)
    {
        ((ViewGroup)w.sObject.get(a)).addView((View)w.sObject.get(b));
        return 0;
    }

    // void addView(View* view, int index)
    public long visit(TEta00 element, long a, long b, long c, long d, long e)
    {
        ((ViewGroup)w.sObject.get(a)).addView((View)w.sObject.get(b), (int)c);
        return 0;
    }

    // View* getChildAt(int index)
    public long visit(TBeta00 element, long a, long b, long c, long d, long e)
    {
        return w.tFrame.emplaceKey(b, ((ViewGroup)w.sObject.get(a)).getChildAt((int)c));
    }

    // int getChildCount()
    public long visit(TGamma00 element, long a, long b, long c, long d, long e)
    {
        return ((ViewGroup)w.sObject.get(a)).getChildCount();
    }

    // void removeAllViews()
    public long visit(TDelta00 element, long a, long b, long c, long d, long e)
    {
        ((ViewGroup)w.sObject.get(a)).removeAllViews();
        return 0;
    }

    // void removeViewAt(int index)
    public long visit(TEpsilon00 element, long a, long b, long c, long d, long e)
    {
        ((ViewGroup)w.sObject.get(a)).removeViewAt((int)b);
        return 0;
    }

    // void requestLayout()
    public long visit(TDzeta00 element, long a, long b, long c, long d, long e)
    {
        ((ViewGroup)w.sObject.get(a)).requestLayout();
        return 0;
    }

    //******************************************************************************************
    //************************************** LayoutParams **************************************
    //******************************************************************************************
    // LayoutParams(int width, int height)
    public long visit(TAlpha03 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put(a, new ViewGroup.LayoutParams((int)b, (int)c));
        return 0;
    }

    //******************************************************************************************
    //******************************** MarginLayoutParams **************************************
    //******************************************************************************************
    // MarginLayoutParams(int width, int height)
    public long visit(TBeta03 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put(a, new ViewGroup.MarginLayoutParams((int)b, (int)c));
        return 0;
    }

    // void setMargins(int left, int top, int right, int bottom)
    public long visit(TGamma03 element, long a, long b, long c, long d, long e)
    {
        ((ViewGroup.MarginLayoutParams)w.sObject.get(a)).setMargins((int)b, (int)c, (int)d, (int)e);
        return 0;
    }
}
