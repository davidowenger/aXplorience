package y.b;

import java.util.ArrayList;
import java.util.List;

import android.graphics.SurfaceTexture;
import android.hardware.Camera;

public class TVisitorHardware extends TKrossVisitor
{
    public TVisitorHardware(TWrapper w) {
        super(w);
    }

    //*******************************************************************************
    //******************************** Camera.Parameters ****************************
    //*******************************************************************************
    // String flatten()
    public long visit(TAlpha00 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.putNext(((Camera.Parameters)w.sObject.get(a)).flatten());
    }

    // String get(const String& key)
    public long visit(TBeta00 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.putNext(((Camera.Parameters)w.sObject.get(a)).get((String)w.mTKrossSystem.nRunObject(b)));
    }

    // float getFocalLength()
    public long visit(TGamma00 element, long a, long b, long c, long d, long e)
    {
        return Double.doubleToRawLongBits((double)((Camera.Parameters)w.sObject.get(a)).getFocalLength());
    }

    // float getHorizontalViewAngle()
    public long visit(TDelta00 element, long a, long b, long c, long d, long e)
    {
        return Double.doubleToRawLongBits((double)((Camera.Parameters)w.sObject.get(a)).getHorizontalViewAngle());
    }

    // int getInt(const String& key)
    public long visit(TEpsilon00 element, long a, long b, long c, long d, long e)
    {
        return ((Camera.Parameters)w.sObject.get(a)).getInt((String)w.mTKrossSystem.nRunObject(b));
    }

    // NArray<nint> getPreviewSize()
    public long visit(TDzeta00 element, long a, long b, long c, long d, long e)
    {
        List<Integer> vaInt = new ArrayList<Integer>();
        Camera.Size vSize = ((Camera.Parameters)w.sObject.get(a)).getPreviewSize();
        vaInt.add(vSize.width);
        vaInt.add(vSize.height);
        return w.mTKrossSystem.putNext(vaInt);
    }

    // NArray<String> getSupportedFlashModes()
    public long visit(TEta00 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.putNext(((Camera.Parameters)w.sObject.get(a)).getSupportedFlashModes());
    }

    // NArray<String> getSupportedFocusModes()
    public long visit(TTheta00 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.putNext(((Camera.Parameters)w.sObject.get(a)).getSupportedFocusModes());
    }

    // NArray<nint> getSupportedPreviewSizes()
    public long visit(TIota00 element, long a, long b, long c, long d, long e)
    {
        List<Integer> vaInt = new ArrayList<Integer>();
        List<Camera.Size> vaSize = ((Camera.Parameters)w.sObject.get(a)).getSupportedPreviewSizes();

        for (Camera.Size vSize : vaSize) {
            vaInt.add(vSize.width);
            vaInt.add(vSize.height);
        }
        return w.mTKrossSystem.putNext(vaInt);
    }

    // float getVerticalViewAngle()
    public long visit(TKappa00 element, long a, long b, long c, long d, long e)
    {
        return Double.doubleToRawLongBits((double)((Camera.Parameters)w.sObject.get(a)).getVerticalViewAngle());
    }

    // bool getVideoStabilization()
    public long visit(TLambda00 element, long a, long b, long c, long d, long e)
    {
        return ( ((Camera.Parameters)w.sObject.get(a)).getVideoStabilization() ? 1 : 0 );
    }

    // bool isVideoStabilizationSupported()
    public long visit(TMu00 element, long a, long b, long c, long d, long e)
    {
        return ( ((Camera.Parameters)w.sObject.get(a)).isVideoStabilizationSupported() ? 1 : 0 );
    }

    // bool isZoomSupported()
    public long visit(TNu00 element, long a, long b, long c, long d, long e)
    {
        return ( ((Camera.Parameters)w.sObject.get(a)).isZoomSupported() ? 1 : 0 );
    }

    // void remove(const String& key)
    public long visit(TXi00 element, long a, long b, long c, long d, long e)
    {
        ((Camera.Parameters)w.sObject.get(a)).remove((String)w.mTKrossSystem.nRunObject(b));
        return 0;
    }

    // void set(const String& key, const String& value)
    public long visit(TOmicron00 element, long a, long b, long c, long d, long e)
    {
        ((Camera.Parameters)w.sObject.get(a)).set((String)w.mTKrossSystem.nRunObject(b), (String)w.mTKrossSystem.nRunObject(c));
        return 0;
    }

    // void set(const String& key, int value)
    public long visit(TPi00 element, long a, long b, long c, long d, long e)
    {
        ((Camera.Parameters)w.sObject.get(a)).set((String)w.mTKrossSystem.nRunObject(b), (int)c);
        return 0;
    }

    // void setPreviewSize(int width, int height)
    public long visit(TRho00 element, long a, long b, long c, long d, long e)
    {
        ((Camera.Parameters)w.sObject.get(a)).setPreviewSize((int)b, (int)c);
        return 0;
    }

    // void setRotation(int rotation)
    public long visit(TEta01 element, long a, long b, long c, long d, long e)
    {
        ((Camera.Parameters)w.sObject.get(a)).setRotation((int)b);
        return 0;
    }

    // void setVideoStabilization(bool toggle)
    public long visit(TSigma00 element, long a, long b, long c, long d, long e)
    {
        ((Camera.Parameters)w.sObject.get(a)).setVideoStabilization(b != 0);
        return 0;
    }

    // void unflatten(const String& flattened)
    public long visit(TTau00 element, long a, long b, long c, long d, long e)
    {
        ((Camera.Parameters)w.sObject.get(a)).unflatten((String)w.mTKrossSystem.nRunObject(b));
        return 0;
    }

    //*******************************************************************************
    //******************************** Camera ***************************************
    //*******************************************************************************
    // static void getCameraInfo(int cameraId, Camera::CameraInfo& cameraInfo)
    public long visit(TGamma01 element, long a, long b, long c, long d, long e)
    {
        List<Integer> vList = new ArrayList<Integer>();
        Camera.CameraInfo vCameraInfo = new Camera.CameraInfo();
        Camera.getCameraInfo((int)a, vCameraInfo);
        vList.add(vCameraInfo.facing);
        vList.add(vCameraInfo.orientation);
        return w.mTKrossSystem.putNext(vList);
    }

    // static int getNumberOfCameras()
    public long visit(TDelta01 element, long a, long b, long c, long d, long e)
    {
        return Camera.getNumberOfCameras();
    }

    // static Camera* open()
    public long visit(TUpsilon00 element, long a, long b, long c, long d, long e)
    {
        long ret = 0;
        try {
            ret = w.mTKrossSystem.emplaceKey(a, Camera.open());
        }
        catch (Exception vException) {
            if (w.doDebug) vException.printStackTrace();
            ret = 0;
        }
        return ret;
    }

    // static Camera* open(int cameraId)
    public long visit(TEpsilon01 element, long a, long b, long c, long d, long e)
    {
        long ret = 0;
        try {
            ret = w.mTKrossSystem.emplaceKey(a, Camera.open((int)b));
        }
        catch (Exception vException) {
            if (w.doDebug) vException.printStackTrace();
            ret = 0;
        }
        return ret;
    }

    // Camera::Parameters* getParameters()
    public long visit(TPhi00 element, long a, long b, long c, long d, long e)
    {
        return w.mTKrossSystem.emplaceKey(b, ((Camera)w.sObject.get(a)).getParameters());
    }

    // void release()
    public long visit(TKhi00 element, long a, long b, long c, long d, long e)
    {
        ((Camera)w.sObject.get(a)).release();
        return 0;
    }

    // void setDisplayOrientation(int degrees)
    public long visit(TDzeta01 element, long a, long b, long c, long d, long e)
    {
        ((Camera)w.sObject.get(a)).setDisplayOrientation((int)b);
        return 0;
    }

    // void setParameters(Camera::Parameters* params)
    public long visit(TPsi00 element, long a, long b, long c, long d, long e)
    {
        ((Camera)w.sObject.get(a)).setParameters(w.mTKrossSystem.getValue(b, Camera.Parameters.class));
        return 0;
    }

    // void setPreviewTexture(SurfaceTexture* surfaceTexture)
    public long visit(TOmega00 element, long a, long b, long c, long d, long e)
    {
        try {
            ((Camera)w.sObject.get(a)).setPreviewTexture(w.mTKrossSystem.getValue(b, SurfaceTexture.class));
        }
        catch (Exception vException) {
            if (w.doDebug) vException.printStackTrace();
        }
        return 0;
    }

    // void startPreview()
    public long visit(TAlpha01 element, long a, long b, long c, long d, long e)
    {
        ((Camera)w.sObject.get(a)).startPreview();
        return 0;
    }

    // void stopPreview()
    public long visit(TBeta01 element, long a, long b, long c, long d, long e)
    {
        ((Camera)w.sObject.get(a)).stopPreview();
        return 0;
    }
}
