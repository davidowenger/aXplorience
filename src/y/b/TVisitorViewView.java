package y.b;

import android.content.Context;
import android.graphics.drawable.Drawable;
import android.view.View;
import android.view.ViewGroup;

public class TVisitorViewView extends TKrossVisitor
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
        w.sObject.put(a, new View((Context)w.sObject.get(b)));
        return 0;
    }

    // Drawable* getBackground()
    public long visit(TOmicron00 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.emplaceKey(b, ((View)w.sObject.get(a)).getBackground());
    }

    // int getId()
    public long visit(TBeta00 element, long a, long b, long c, long d, long e)
    {
        return ((View)w.sObject.get(a)).getId();
    }

    // void invalidate()
    public long visit(TGamma00 element, long a, long b, long c, long d, long e)
    {
        ((View)w.sObject.get(a)).invalidate();
        return 0;
    }

    // bool performClick()
    public long visit(TPi00 element, long a, long b, long c, long d, long e)
    {
        return ( ((View)w.sObject.get(a)).performClick() ? 1 : 0 );
    }

    // void requestLayout()
    public long visit(TDelta00 element, long a, long b, long c, long d, long e)
    {
        ((View)w.sObject.get(a)).requestLayout();
        return 0;
    }

    // void setMinimumHeight(int minHeight);
    public long visit(TMu00 element, long a, long b, long c, long d, long e)
    {
        ((View)w.sObject.get(a)).setMinimumHeight((int)b);
        return 0;
    }

    // void setMinimumWidth(int minWidth);
    public long visit(TNu00 element, long a, long b, long c, long d, long e)
    {
        ((View)w.sObject.get(a)).setMinimumWidth((int)b);
        return 0;
    }

    // void setBackgroundColor(int color)
    public long visit(TEpsilon00 element, long a, long b, long c, long d, long e)
    {
        ((View)w.sObject.get(a)).setBackgroundColor((int)b);
        return 0;
    }

    // void setBackgroundDrawable(Drawable* background)
    public long visit(TDzeta00 element, long a, long b, long c, long d, long e)
    {
        ((View)w.sObject.get(a)).setBackgroundDrawable(w.mTKrossSystem.getValue(b, Drawable.class));
        return 0;
    }

    // void setBackgroundResource(int resid)
    public long visit(TRho00 element, long a, long b, long c, long d, long e)
    {
        ((View)w.sObject.get(a)).setBackgroundResource((int)b);
        return 0;
    }

    // void setId(int id)
    public long visit(TEta00 element, long a, long b, long c, long d, long e)
    {
        ((View)w.sObject.get(a)).setId((int)b);
        return 0;
    }

    // void setLayoutParams(LayoutParams* params)
    public long visit(TTheta00 element, long a, long b, long c, long d, long e)
    {
        ((View)w.sObject.get(a)).setLayoutParams((ViewGroup.LayoutParams)w.sObject.get(b));
        return 0;
    }

    // void setOnClickListener(OnClickListener* l)
    public long visit(TIota00 element, long a, long b, long c, long d, long e)
    {
        ((View)w.sObject.get(a)).setOnClickListener((View.OnClickListener)w.sObject.get(b));
        return 0;
    }

    // void setOnTouchListener(View::OnTouchListener* l)
    public long visit(TXi00 element, long a, long b, long c, long d, long e)
    {
        ((View)w.sObject.get(a)).setOnTouchListener((View.OnTouchListener)w.sObject.get(b));
        return 0;
    }

    // void setPadding(int left, int top, int right, int bottom)
    public long visit(TKappa00 element, long a, long b, long c, long d, long e)
    {
        ((View)w.sObject.get(a)).setPadding((int)b, (int)c, (int)d, (int)e);
        return 0;
    }

    // void setVisibility(int visibility)
    public long visit(TLambda00 element, long a, long b, long c, long d, long e)
    {
        ((View)w.sObject.get(a)).setVisibility((int)b);
        return 0;
    }

    //******************************************************************************************
    //************************************* OnClickListener ************************************
    //******************************************************************************************
    // OnClickListener()
    public long visit(TAlpha03 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put(a, new TOnClickListener(w, a));
        return 0;
    }

    //******************************************************************************************
    //***************************** OnCreateContextMenuListener ********************************
    //******************************************************************************************
    // OnCreateContextMenuListener()
    public long visit(TBeta03 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put(a, new TOnCreateContextMenuListener(w, a));
        return 0;
    }

    //******************************************************************************************
    //************************************* OnTouchListener ************************************
    //******************************************************************************************
    // OnTouchListener()
    public long visit(TGamma03 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put(a, new TOnTouchListener(w, a));
        return 0;
    }
}
