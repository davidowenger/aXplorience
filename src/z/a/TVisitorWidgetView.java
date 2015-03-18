package z.a;

import android.content.Context;
import android.graphics.Typeface;
import android.graphics.drawable.Drawable;
import android.view.View;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemSelectedListener;
import android.widget.ImageView;
import android.widget.ImageView.ScaleType;
import android.widget.ScrollView;
import android.widget.TextView;

public class TVisitorWidgetView extends TVisitor
{
    public final ScaleType[] maScaleType = ScaleType.values();

	public TVisitorWidgetView(TWrapper w) {
		super(w);
	}

    //******************************************************************************************
    //************************************ AdapterView *****************************************
    //******************************************************************************************
    // void setOnItemSelectedListener(OnItemSelectedListener* listener)
    public long visit(TBeta00 element, long a, long b, long c, long d, long e)
    {
        ((AdapterView<?>)w.sObject.get("" + a)).setOnItemSelectedListener((OnItemSelectedListener)w.sObject.get("" + b));
        return 0;
    }

    //******************************************************************************************
    //************************************** ImageView *****************************************
    //******************************************************************************************
    // ImageView(Context* context)
    public long visit(TGamma00 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put("" + a, new ImageView((Context)w.sObject.get("" + b)));
        return 0;
    }

    // void setImageDrawable(Drawable* drawable)
    public long visit(TDelta00 element, long a, long b, long c, long d, long e)
    {
        ((ImageView)w.sObject.get("" + a)).setImageDrawable((Drawable)w.sObject.get("" + b));
        return 0;
    }

    // setScaleType(ScaleType scaleType)
    public long visit(TEpsilon00 element, long a, long b, long c, long d, long e)
    {
        ((ImageView)w.sObject.get("" + a)).setScaleType(maScaleType[(int)b]);
        return 0;
    }

    //******************************************************************************************
    //************************************** ScrollView ****************************************
    //******************************************************************************************
    // ScrollView(Context* context)
    public long visit(TDzeta00 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put("" + a, new ScrollView((Context)w.sObject.get("" + b)));
        return 0;
    }

    // void addView(View* view)
    public long visit(TEta00 element, long a, long b, long c, long d, long e)
    {
        ((ScrollView)w.sObject.get("" + a)).addView((View)w.sObject.get("" + b));
        return 0;
    }

    // void requestLayout()
    public long visit(TTheta00 element, long a, long b, long c, long d, long e)
    {
        ((ScrollView)w.sObject.get("" + a)).requestLayout();
        return 0;
    }

    //******************************************************************************************
    //************************************** TextView ****************************************
    //******************************************************************************************
    // TextView(Context* context)
    public long visit(TIota00 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put("" + a, new TextView((Context)w.sObject.get("" + b)));
        return 0;
    }

    // void onSaveInstanceState()
    public long visit(TKappa00 element, long a, long b, long c, long d, long e)
    {
        ((TextView)w.sObject.get("" + a)).onSaveInstanceState();
        return 0;
    }

    // void setEnabled(bool enabled)
    public long visit(TLambda00 element, long a, long b, long c, long d, long e)
    {
        ((TextView)w.sObject.get("" + a)).setEnabled( b != 0 ? true : false );
        return 0;
    }

    // void setGravity(int gravity)
    public long visit(TMu00 element, long a, long b, long c, long d, long e)
    {
        ((TextView)w.sObject.get("" + a)).setGravity((int)b);
        return 0;
    }

    // void setLines(int lines)
    public long visit(TNu00 element, long a, long b, long c, long d, long e)
    {
        ((TextView)w.sObject.get("" + a)).setLines((int)b);
        return 0;
    }

    // void setPadding(int left, int top, int right, int bottom)
    public long visit(TXi00 element, long a, long b, long c, long d, long e)
    {
        ((TextView)w.sObject.get("" + a)).setPadding((int)b, (int)c, (int)d, (int)e);
        return 0;
    }

    // void setSelected(bool selected)
    public long visit(TOmicron00 element, long a, long b, long c, long d, long e)
    {
        ((TextView)w.sObject.get("" + a)).setSelected( b != 0 ? true : false );
        return 0;
    }

    // void setText(const String& text)
    public long visit(TPi00 element, long a, long b, long c, long d, long e)
    {
        ((TextView)w.sObject.get("" + a)).setText(((String)w.tFrame.nRunObject(b)));
        return 0;
    }

    // void setTextSize(float size)
    public long visit(TRho00 element, long a, long b, long c, long d, long e)
    {
        ((TextView)w.sObject.get("" + a)).setTextSize((float)Double.longBitsToDouble(b));
        return 0;
    }

    // void setTypeface(Typeface tf)
    public long visit(TSigma00 element, long a, long b, long c, long d, long e)
    {
        ((TextView)w.sObject.get("" + a)).setTypeface((Typeface)w.sObject.get("" + b));
        return 0;
    }
}
