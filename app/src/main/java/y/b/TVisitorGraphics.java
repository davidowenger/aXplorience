package y.b;

import android.graphics.SurfaceTexture;
import android.graphics.Typeface;
import android.graphics.drawable.ColorDrawable;
import android.graphics.drawable.Drawable;
import android.graphics.drawable.StateListDrawable;

public class TVisitorGraphics extends TKrossVisitor
{
    public TVisitorGraphics(TWrapper w) {
        super(w);
    }

    //*******************************************************************************
    //******************************** Drawable *************************************
    //*******************************************************************************
    // int getIntrinsicHeight()
    public long visit(TDzeta00 element, long a, long b, long c, long d, long e)
    {
        return ((Drawable)w.sObject.get(a)).getIntrinsicHeight();
    }

    // int getIntrinsicWidth()
    public long visit(TEta00 element, long a, long b, long c, long d, long e)
    {
        return ((Drawable)w.sObject.get(a)).getIntrinsicHeight();
    }

    // void invalidateSelf()
    public long visit(TTheta00 element, long a, long b, long c, long d, long e)
    {
        ((Drawable)w.sObject.get(a)).invalidateSelf();
        return 0;
    }

    //*******************************************************************************
    //**************************** StateListDrawable ********************************
    //*******************************************************************************
    // StateListDrawable()
    public long visit(TAlpha00 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put(a, new StateListDrawable());
        return 0;
    }

    // void addState(vector<int> stateSet, Drawable* drawable)
    public long visit(TBeta00 element, long a, long b, long c, long d, long e)
    {
        ((StateListDrawable)w.sObject.get(a)).addState((int[])w.aObject.remove((int)b), w.mTKrossSystem.getValue(c, Drawable.class));
        return 0;
    }

    //*******************************************************************************
    //******************* SurfaceTexture.OnFrameAvailableListener *******************
    //*******************************************************************************
    // OnFrameAvailableListener()
    public long visit(TIota00 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put(a, new TOnFrameAvailableListener(w, a));
        return 0;
    }

    //*******************************************************************************
    //******************************** SurfaceTexture *******************************
    //*******************************************************************************
    // SurfaceTexture(int texName)
    public long visit(TKappa00 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put(a, new SurfaceTexture((int)b));
        return 0;
    }

    // SurfaceTexture(int texName, bool singleBufferMode)
    public long visit(TLambda00 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put(a, new SurfaceTexture((int)b, c != 0));
        return 0;
    }

    // void getTransformMatrix(NArray<float> mtx)
    public long visit(TMu00 element, long a, long b, long c, long d, long e)
    {
        float[] vOut = new float[16];
        ((SurfaceTexture)w.sObject.get(a)).getTransformMatrix(vOut);
        return w.mTKrossSystem.putNext(vOut);
    }

    // void release()
    public long visit(TNu00 element, long a, long b, long c, long d, long e)
    {
        ((SurfaceTexture)w.sObject.get(a)).release();
        return 0;
    }

    // void releaseTexImage()
    public long visit(TXi00 element, long a, long b, long c, long d, long e)
    {
        ((SurfaceTexture)w.sObject.get(a)).releaseTexImage();
        return 0;
    }

    // void setDefaultBufferSize(int width, int height)
    public long visit(TOmicron00 element, long a, long b, long c, long d, long e)
    {
        ((SurfaceTexture)w.sObject.get(a)).setDefaultBufferSize((int)b, (int)c);
        return 0;
    }

    // void setOnFrameAvailableListener(SurfaceTexture::OnFrameAvailableListener* listener)
    public long visit(TPi00 element, long a, long b, long c, long d, long e)
    {
        ((SurfaceTexture)w.sObject.get(a)).setOnFrameAvailableListener(w.mTKrossSystem.getValue(b, SurfaceTexture.OnFrameAvailableListener.class));
        return 0;
    }

    // void updateTexImage()
    public long visit(TRho00 element, long a, long b, long c, long d, long e)
    {
        ((SurfaceTexture)w.sObject.get(a)).updateTexImage();
        return 0;
    }

    //*******************************************************************************
    //******************************** Typeface *************************************
    //*******************************************************************************
    // static Typeface* create(const String& familyName, int style)
    public long visit(TGamma00 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.putKey(a, Typeface.create((String)w.mTKrossSystem.nRunObject(b), (int)c));
    }

    // static Typeface* defaultFromStyle(int style)
    public long visit(TDelta00 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.putKey(a, Typeface.defaultFromStyle((int)b));
    }

    //*******************************************************************************
    //******************************** ColorDrawable ********************************
    //*******************************************************************************
    // ColorDrawable(int color)
    public long visit(TEpsilon00 element, long a, long b, long c, long d, long e)
    {
        w.sObject.put(a, new ColorDrawable((int)b));
        return 0;
    }
}
