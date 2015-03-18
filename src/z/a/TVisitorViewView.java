package z.a;

import android.content.Context;
import android.view.View;

public class TVisitorViewView extends TVisitor
{
	public TVisitorViewView(TWrapper w) {
		super(w);
	}

    //******************************************************************************************
    //********************************************* View ***************************************
    //******************************************************************************************
    // View(Context* context)
    public long visit(TAlpha00 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put("" + a, new View((Context)w.sObject.get("" + b)));
        return 0;
    }

    // int getId()
    public long visit(TBeta00 element, long a, long b, long c, long d, long e)
    {
        return ((View)w.sObject.get("" + a)).getId();
    }

    // void invalidate()
    public long visit(TGamma00 element, long a, long b, long c, long d, long e)
    {
        ((View)w.sObject.get("" + a)).invalidate();
        return 0;
    }

    // void requestLayout()
    public long visit(TDelta00 element, long a, long b, long c, long d, long e)
    {
        ((View)w.sObject.get("" + a)).requestLayout();
        return 0;
    }

    // void setBackgroundColor(int color)
    public long visit(TEpsilon00 element, long a, long b, long c, long d, long e)
    {
        ((View)w.sObject.get("" + a)).requestLayout();
        return 0;
    }

    // void setId(int id)
    public long visit(TDzeta00 element, long a, long b, long c, long d, long e)
    {
        ((View)w.sObject.get("" + a)).requestLayout();
        return 0;
    }

    // void setLayoutParams(LayoutParams* params)
    public long visit(TEta00 element, long a, long b, long c, long d, long e)
    {
        ((View)w.sObject.get("" + a)).requestLayout();
        return 0;
    }

    // void setOnClickListener(OnClickListener* l)
    public long visit(TTheta00 element, long a, long b, long c, long d, long e)
    {
        ((View)w.sObject.get("" + a)).requestLayout();
        return 0;
    }

    // void setPadding(int left, int top, int right, int bottom)
    public long visit(TIota00 element, long a, long b, long c, long d, long e)
    {
        ((View)w.sObject.get("" + a)).requestLayout();
        return 0;
    }

    // void setVisibility(int visibility)
    public long visit(TKappa00 element, long a, long b, long c, long d, long e)
    {
        ((View)w.sObject.get("" + a)).requestLayout();
        return 0;
    }

    //******************************************************************************************
    //************************************* OnClickListener ************************************
    //******************************************************************************************
    // OnClickListener()
    public long visit(TAlpha03 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put("" + a, new TOnClickListener(w, a));
        return 0;
    }

    //******************************************************************************************
    //***************************** OnCreateContextMenuListener ********************************
    //******************************************************************************************
    // OnCreateContextMenuListener()
    public long visit(TBeta03 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put("" + a, new TOnCreateContextMenuListener());
        return 0;
    }

    //******************************************************************************************
    //************************************* OnTouchListener ************************************
    //******************************************************************************************
    // OnTouchListener()
    public long visit(TGamma03 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put("" + a, new TOnTouchListener());
        return 0;
    }
}
