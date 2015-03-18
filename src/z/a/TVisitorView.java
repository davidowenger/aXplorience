package z.a;

import android.content.Context;
import android.graphics.drawable.Drawable;
import android.view.GestureDetector;
import android.view.Menu;
import android.view.MenuItem;
import android.view.MotionEvent;
import android.view.View;

public class TVisitorView extends TVisitor
{
	public TVisitorView(TWrapper w) {
		super(w);
	}

    //******************************************************************************************
    //********************************** GestureDetector ***************************************
    //******************************************************************************************
    // GestureDetector(Context* context, GestureDetector::OnGestureListener* listener)
    public long visit(TAlpha00 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put("" + a, new GestureDetector((Context)w.sObject.get("" + b), (GestureDetector.OnGestureListener)w.sObject.get("" + c)));
        return 0;
    }

    // bool onTouchEvent(MotionEvent* ev)
    public long visit(TBeta00 element, long a, long b, long c, long d, long e)
    {
        return ( ((View)w.sObject.get("" + a)).onTouchEvent((MotionEvent)w.sObject.get("" + b)) ? 1 : 0 );
    }

    //*******************************************************************************************
    //****************************************** Menu *******************************************
    //*******************************************************************************************
    // MenuItem* add(int groupId, int itemId, int order, const String& title)
    public long visit(TGamma00 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put("" + b, ((Menu)w.sObject.get("" + a)).add(w.tFrame.getInt(c, 0), w.tFrame.getInt(c, 1), (int)d, (String)w.tFrame.nRunObject(e)));
        return 0;
    }

    // void removeItem(int id)
    public long visit(TDelta00 element, long a, long b, long c, long d, long e)
    {
        ((Menu)w.sObject.get("" + a)).removeItem((int)b);
        return 0;
    }

    //*******************************************************************************************
    //*************************************** MenuItem ******************************************
    //*******************************************************************************************
    // int getItemId()
    public long visit(TEpsilon00 element, long a, long b, long c, long d, long e)
    {
        return ((MenuItem)w.sObject.get("" + a)).getItemId();
    }

    // MenuItem* setIcon(Drawable* icon)
    public long visit(TDzeta00 element, long a, long b, long c, long d, long e)
    {
        ((MenuItem)w.sObject.get("" + a)).setIcon((Drawable)w.sObject.get("" + b));
        return 0;
    }

    // MenuItem* setShowAsAction(int actionEnum)
    public long visit(TEta00 element, long a, long b, long c, long d, long e)
    {
        ((MenuItem)w.sObject.get("" + a)).setShowAsAction((int)b);
        return 0;
    }

    //*******************************************************************************************
    //*************************************** MotionEvent ***************************************
    //*******************************************************************************************
    // float getX()
    public long visit(TTheta00 element, long a, long b, long c, long d, long e)
    {
        return Double.doubleToRawLongBits((double)((MotionEvent)w.sObject.get("" + a)).getX());
    }

    // float getY()
    public long visit(TIota00 element, long a, long b, long c, long d, long e)
    {
        return Double.doubleToRawLongBits((double)((MotionEvent)w.sObject.get("" + a)).getY());
    }

    //*******************************************************************************************
    //*********************************** OnGestureListener *************************************
    //*******************************************************************************************
    // OnGestureListener()
    public long visit(TAlpha02 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put("" + a, new TOnGestureListener(w, a));
        return 0;
    }
}
