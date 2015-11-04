package y.b;

import android.content.Context;
import android.graphics.drawable.Drawable;
import android.view.ContextThemeWrapper;
import android.view.Display;
import android.view.GestureDetector;
import android.view.Menu;
import android.view.MenuItem;
import android.view.MotionEvent;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.view.WindowManager;

public class TVisitorView extends TKrossVisitor
{
    public TVisitorView(TWrapper w) {
        super(w);
    }

    //******************************************************************************************
    //********************************** ContextThemeWrapper ***********************************
    //******************************************************************************************
    // Resources* getResources()
    public long visit(TKappa00 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.emplaceKey(b, ((ContextThemeWrapper)w.sObject.get(a)).getResources());
    }

    //******************************************************************************************
    //*************************************** Display ******************************************
    //******************************************************************************************
    // int getRotation()
    public long visit(TXi00 element, long a, long b, long c, long d, long e)
    {
        return ((Display)w.sObject.get(a)).getRotation();
    }

    //******************************************************************************************
    //********************************** GestureDetector ***************************************
    //******************************************************************************************
    // GestureDetector(Context* context, GestureDetector::OnGestureListener* listener)
    public long visit(TAlpha00 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put(a, new GestureDetector(w.mTKrossSystem.getValue(b, Context.class), w.mTKrossSystem.getValue(c, GestureDetector.OnGestureListener.class)));
        return 0;
    }

    // bool onTouchEvent(MotionEvent* ev)
    public long visit(TBeta00 element, long a, long b, long c, long d, long e)
    {
        return ( ((GestureDetector)w.sObject.get(a)).onTouchEvent(w.mTKrossSystem.getValue(b, MotionEvent.class)) ? 1 : 0 );
    }

    //*******************************************************************************************
    //****************************************** Menu *******************************************
    //*******************************************************************************************
    // MenuItem* add(int groupId, int itemId, int order, const String& title)
    public long visit(TGamma00 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.emplaceKey(b, ((Menu)w.sObject.get(a)).add(w.mTKrossSystem.getSubInt(c, 0), w.mTKrossSystem.getSubInt(c, 1), (int)d, (String)w.mTKrossSystem.nRunObject(e)));
    }

    // void removeItem(int id)
    public long visit(TDelta00 element, long a, long b, long c, long d, long e)
    {
        ((Menu)w.sObject.get(a)).removeItem((int)b);
        return 0;
    }

    //*******************************************************************************************
    //*************************************** MenuItem ******************************************
    //*******************************************************************************************
    // int getItemId()
    public long visit(TEpsilon00 element, long a, long b, long c, long d, long e)
    {
        return ((MenuItem)w.sObject.get(a)).getItemId();
    }

    // MenuItem* setIcon(Drawable* icon)
    public long visit(TDzeta00 element, long a, long b, long c, long d, long e)
    {
        ((MenuItem)w.sObject.get(a)).setIcon(w.mTKrossSystem.getValue(b, Drawable.class));
        return 0;
    }

    // void setShowAsAction(int actionEnum)
    public long visit(TEta00 element, long a, long b, long c, long d, long e)
    {
        ((MenuItem)w.sObject.get(a)).setShowAsAction((int)b);
        return 0;
    }

    //*******************************************************************************************
    //*************************************** MotionEvent ***************************************
    //*******************************************************************************************
    // float getX()
    public long visit(TTheta00 element, long a, long b, long c, long d, long e)
    {
        return Double.doubleToRawLongBits(((MotionEvent)w.sObject.get(a)).getX());
    }

    // float getY()
    public long visit(TIota00 element, long a, long b, long c, long d, long e)
    {
        return Double.doubleToRawLongBits(((MotionEvent)w.sObject.get(a)).getY());
    }

    // nlong getEventTime()
    public long visit(TLambda00 element, long a, long b, long c, long d, long e)
    {
        return ((MotionEvent)w.sObject.get(a)).getEventTime();
    }

    //*******************************************************************************************
    //*********************************** OnGestureListener *************************************
    //*******************************************************************************************
    // OnGestureListener()
    public long visit(TAlpha02 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put(a, new TOnGestureListener(w, a));
        return 0;
    }

    //*******************************************************************************************
    //*********************************** SurfaceHolder::Callback *******************************
    //*******************************************************************************************
    // SurfaceHolder::Callback()
    public long visit(TOmicron00 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put(a, new TSurfaceHolderCallback(w, a));
        return 0;
    }

    //*******************************************************************************************
    //*********************************** SurfaceHolder::Callback2 *******************************
    //*******************************************************************************************
    // SurfaceHolder::Callback2()
    public long visit(TPi00 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put(a, new TSurfaceHolderCallback2(w, a));
        return 0;
    }

    //*******************************************************************************************
    //*********************************** SurfaceHolder *****************************************
    //*******************************************************************************************
    // void addCallback(SurfaceHolder::Callback* callback)
    public long visit(TRho00 element, long a, long b, long c, long d, long e)
    {
        ((SurfaceHolder)w.sObject.get(a)).addCallback(w.mTKrossSystem.getValue(b, SurfaceHolder.Callback.class));
        return 0;
    }

    // Surface* getSurface()
    public long visit(TSigma00 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.emplaceKey(b, ((SurfaceHolder)w.sObject.get(a)).getSurface());
    }

    // void removeCallback(SurfaceHolder::Callback* callback)
    public long visit(TTau00 element, long a, long b, long c, long d, long e)
    {
       ((SurfaceHolder)w.sObject.get(a)).removeCallback(w.mTKrossSystem.getValue(b, SurfaceHolder.Callback.class));
        return 0;
    }

    // void setKeepScreenOn(bool screenOn)
    public long visit(TUpsilon00 element, long a, long b, long c, long d, long e)
    {
       ((SurfaceHolder)w.sObject.get(a)).setKeepScreenOn( b != 0 ? true : false );
        return 0;
    }

    //*******************************************************************************************
    //*********************************** SurfaceView *******************************************
    //*******************************************************************************************
    // SurfaceView(Context* context)
    public long visit(TMu00 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put(a, new SurfaceView(w.mTKrossSystem.getValue(b, Context.class)));
        return 0;
    }

    // SurfaceHolder* getHolder()
    public long visit(TPhi00 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.emplaceKey(b, ((SurfaceView)w.sObject.get(a)).getHolder());
    }

    //******************************************************************************************
    //********************************** WindowManager *****************************************
    //******************************************************************************************
    // Display* getDefaultDisplay()
    public long visit(TNu00 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.emplaceKey(b, ((WindowManager)w.sObject.get(a)).getDefaultDisplay());
    }
}
