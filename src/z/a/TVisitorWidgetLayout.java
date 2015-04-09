package z.a;

import android.content.Context;
import android.widget.FrameLayout;
import android.widget.LinearLayout;

public class TVisitorWidgetLayout extends TVisitor
{
	public TVisitorWidgetLayout(TWrapper w) {
		super(w);
	}

    //******************************************************************************************
    //************************************ FrameLayout *****************************************
    //******************************************************************************************
    // FrameLayout(Context* context)
    public long visit(TAlpha00 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put(a, new FrameLayout((Context)w.sObject.get(b)));
        return 0;
    }

    // void setVisibility(int visibility)
    public long visit(TBeta00 element, long a, long b, long c, long d, long e)
    {
        ((FrameLayout)w.sObject.get(a)).setVisibility((int)b);
        return 0;
    }

    //******************************************************************************************
    //*********************************** LinearLayout *****************************************
    //******************************************************************************************
    // LinearLayout(Context* context)
	public long visit(TGamma00 element, long a, long b, long c, long d, long e)
	{
        w.sObject.put(a, new TLinearLayout(w, a, (Context)w.sObject.get(b)));
        return 0;
	}

    // void invalidate()
	public long visit(TDelta00 element, long a, long b, long c, long d, long e)
	{
        ((LinearLayout)w.sObject.get(a)).invalidate();
		return 0;
	}

    // void requestLayout()
	public long visit(TEpsilon00 element, long a, long b, long c, long d, long e)
	{
        ((LinearLayout)w.sObject.get(a)).requestLayout();
		return 0;
	}

    // void setGravity(int gravity)
    public long visit(TDzeta00 element, long a, long b, long c, long d, long e)
    {
        ((LinearLayout)w.sObject.get(a)).setGravity((int)b);
        return 0;
    }

    // void setOrientation(int orientation)
    public long visit(TEta00 element, long a, long b, long c, long d, long e)
    {
        ((LinearLayout)w.sObject.get(a)).setOrientation((int)b);
        return 0;
    }

    //******************************************************************************************
    //*************************** LinearLayout::LayoutParams ***********************************
    //******************************************************************************************
    // LinearLayout::LayoutParams(int width, int height)
    public long visit(TAlpha01 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put(a, new LinearLayout.LayoutParams((int)b, (int)c));
        return 0;
    }

    // LinearLayout::LayoutParams(int width, int height, float weight)
    public long visit(TBeta01 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put(a, new LinearLayout.LayoutParams((int)b, (int)c, (float)Double.longBitsToDouble(d)));
        return 0;
    }
}
