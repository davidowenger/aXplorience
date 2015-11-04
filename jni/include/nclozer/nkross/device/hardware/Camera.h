#ifndef __Camera_H__
#define __Camera_H__

namespace NSDEVICE
{

class Camera : public Object
{
friend NSNATIVE::NKrossFriend;

public:

    class CameraInfo
    {
    public:
        static const int CAMERA_FACING_BACK = 0x00000000;
        static const int CAMERA_FACING_FRONT = 0x00000001;

        CameraInfo() :
            facing(0), orientation(0)
        {
        }

        int facing;
        int orientation;
    };

    class Size
    {
    public:
        Size(int w, int h) :
            height(h), width(w)
        {
        }

        int  height;
        int  width;
    };

    class Parameters
    {
    friend NSNATIVE::NKrossFriend;

    public:
        static const String FLASH_MODE_AUTO;
        static const String FLASH_MODE_OFF;
        static const String FLASH_MODE_ON;
        static const String FLASH_MODE_RED_EYE;
        static const String FLASH_MODE_TORCH;
        static const String FOCUS_MODE_AUTO;
        static const String FOCUS_MODE_CONTINUOUS_PICTURE;
        static const String FOCUS_MODE_CONTINUOUS_VIDEO;
        static const String FOCUS_MODE_EDOF;
        static const String FOCUS_MODE_FIXED;
        static const String FOCUS_MODE_INFINITY;
        static const String FOCUS_MODE_MACRO;

        virtual ~Parameters()
        {
        }

        virtual String flatten()
        {
            NReturn index = NSNKROSS::w->mNVisitorHardware->tRun(NSNKROSS::w->mNAlpha00, (NParam)this);
            return NSNKROSS::w->mNKrossSystem->tGetString(NSNKROSS::w->mNKrossSystem->tRunObject((NParam)index));
        }

        virtual String get(const String& key)
        {
            NReturn index = NSNKROSS::w->mNVisitorHardware->tRun(NSNKROSS::w->mNBeta00, (NParam)this, NKrossParam(key).n);
            return NSNKROSS::w->mNKrossSystem->tGetString(NSNKROSS::w->mNKrossSystem->tRunObject((NParam)index));
        }

        virtual float getFocalLength()
        {
            nlong vcValue = NSNKROSS::w->mNVisitorHardware->tRun(NSNKROSS::w->mNGamma00, (NParam)this);
            return (nfloat)*reinterpret_cast<ndouble*>(&vcValue);
        }

        virtual float getHorizontalViewAngle()
        {
            nlong vcValue = NSNKROSS::w->mNVisitorHardware->tRun(NSNKROSS::w->mNDelta00, (NParam)this);
            return (nfloat)*reinterpret_cast<ndouble*>(&vcValue);
        }

        virtual int getInt(const String& key)
        {
            return (nint)NSNKROSS::w->mNVisitorHardware->tRun(NSNKROSS::w->mNEpsilon00, (NParam)this, NKrossParam(key).n);
        }

        virtual vector<nint> getPreviewSize()
        {
            NReturn index = NSNKROSS::w->mNVisitorHardware->tRun(NSNKROSS::w->mNDzeta00, (NParam)this);
            NReturn size = NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNAlpha01, index, -1);
            vector<nint> vVector =  vector<nint>();
            nuint i;

            for (i = 0 ; i < size ; ++i) {
                vVector.push_back((nint)NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNAlpha01, index, (NParam)i));
            }
            return vVector;
        }

        virtual vector<String> getSupportedFlashModes()
        {
            NReturn index = NSNKROSS::w->mNVisitorHardware->tRun(NSNKROSS::w->mNEta00, (NParam)this);
            NReturn size = NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNAlpha01, index, -1);
            vector<String> vVector = vector<String>();
            nuint i;

            for (i = 0 ; i < size ; ++i) {
                vVector.push_back(NSNKROSS::w->mNKrossSystem->tGetString(NSNKROSS::w->mNKrossSystem->tRunObject(index, (NParam)i)));
            }
            return vVector;
        }

        virtual vector<String> getSupportedFocusModes()
        {
            NReturn index = NSNKROSS::w->mNVisitorHardware->tRun(NSNKROSS::w->mNTheta00, (NParam)this);
            NReturn size = NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNAlpha01, index, -1);
            vector<String> vVector = vector<String>();
            nuint i;

            for (i = 0 ; i < size ; ++i) {
                vVector.push_back(NSNKROSS::w->mNKrossSystem->tGetString(NSNKROSS::w->mNKrossSystem->tRunObject(index, (NParam)i)));
            }
            return vVector;
        }

        virtual vector<Camera::Size> getSupportedPreviewSizes()
        {
            NReturn index = NSNKROSS::w->mNVisitorHardware->tRun(NSNKROSS::w->mNIota00, (NParam)this);
            NReturn size = NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNAlpha01, index, -1)>>1;
            vector<Camera::Size> vVector =  vector<Camera::Size>();
            nuint i;

            for (i = 0 ; i < size ; ++i) {
                vVector.push_back(Camera::Size(
                    (nint)NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNAlpha01, index, (NParam)2*i),
                    (nint)NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNAlpha01, index, (NParam)2*i + 1)
                ));
            }
            return vVector;
        }

        virtual float getVerticalViewAngle()
        {
            nlong vcValue = NSNKROSS::w->mNVisitorHardware->tRun(NSNKROSS::w->mNKappa00, (NParam)this);
            return (nfloat)*reinterpret_cast<ndouble*>(&vcValue);
        }

        virtual bool getVideoStabilization()
        {
            return (bool)NSNKROSS::w->mNVisitorHardware->tRun(NSNKROSS::w->mNLambda00, (NParam)this);
        }

        virtual bool isVideoStabilizationSupported()
        {
            return (bool)NSNKROSS::w->mNVisitorHardware->tRun(NSNKROSS::w->mNMu00, (NParam)this);
        }

        virtual bool isZoomSupported()
        {
            return (bool)NSNKROSS::w->mNVisitorHardware->tRun(NSNKROSS::w->mNNu00, (NParam)this);
        }

        virtual void remove(const String& key)
        {
            NSNKROSS::w->mNVisitorHardware->tRun(NSNKROSS::w->mNXi00, (NParam)this, NKrossParam(key).n);
        }

        virtual void set(const String& key, const String& value)
        {
            NSNKROSS::w->mNVisitorHardware->tRun(NSNKROSS::w->mNOmicron00, (NParam)this, NKrossParam(key).n, NKrossParam(value).n);
        }

        virtual void set(const String& key, int value)
        {
            NSNKROSS::w->mNVisitorHardware->tRun(NSNKROSS::w->mNPi00, (NParam)this, NKrossParam(key).n, (NParam)value);
        }

        virtual void setPreviewSize(int width, int height)
        {
            NSNKROSS::w->mNVisitorHardware->tRun(NSNKROSS::w->mNRho00, (NParam)this, (NParam)width, (NParam)height);
        }

        virtual void setRotation(int rotation)
        {
            NSNKROSS::w->mNVisitorHardware->tRun(NSNKROSS::w->mNEta01, (NParam)this, (NParam)rotation);
        }

        virtual void setVideoStabilization(bool toggle)
        {
            NSNKROSS::w->mNVisitorHardware->tRun(NSNKROSS::w->mNSigma00, (NParam)this, (NParam)toggle);
        }

        virtual void unflatten(const String& flattened)
        {
            NSNKROSS::w->mNVisitorHardware->tRun(NSNKROSS::w->mNTau00, (NParam)this, NKrossParam(flattened).n);
        }

    private:
        Parameters(NKrossFriend* vNKrossFriend)
        {
        }
    };

    static void getCameraInfo(int cameraId, Camera::CameraInfo& cameraInfo)
    {
        NReturn index = NSNKROSS::w->mNVisitorHardware->tRun(NSNKROSS::w->mNGamma01, (NParam)cameraId);
        NReturn size = NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNAlpha01, index, -1);

        if (size > 1) {
            cameraInfo.facing = (nint)NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNAlpha01, index, (NParam)0);
            cameraInfo.orientation = (nint)NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNAlpha01, index, (NParam)1);
        }
    }

    static int getNumberOfCameras()
    {
        return (nint)NSNKROSS::w->mNVisitorHardware->tRun(NSNKROSS::w->mNDelta01);
    }

    static Camera* open()
    {
        Camera* b = NSNKROSS::w->mNKrossFriend->pointer<Camera>();
        return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorHardware->tRun(NSNKROSS::w->mNUpsilon00, (NParam)b));
    }

    static Camera* open(int cameraId)
    {
        Camera* b = NSNKROSS::w->mNKrossFriend->pointer<Camera>();
        return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorHardware->tRun(NSNKROSS::w->mNEpsilon01, (NParam)b, (NParam)cameraId));
    }

    virtual ~Camera()
    {
    }

    virtual Camera::Parameters* getParameters()
    {
        Camera::Parameters* b = NSNKROSS::w->mNKrossFriend->pointer<Camera::Parameters>();
        return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorHardware->tRun(NSNKROSS::w->mNPhi00, (NParam)this, (NParam)b));
    }

    void release()
    {
        NSNKROSS::w->mNVisitorHardware->tRun(NSNKROSS::w->mNKhi00, (NParam)this);
    }

    void setDisplayOrientation(int degrees)
    {
        NSNKROSS::w->mNVisitorHardware->tRun(NSNKROSS::w->mNDzeta01, (NParam)this, (NParam)degrees);
    }

    virtual void setParameters(Camera::Parameters* params)
    {
        NSNKROSS::w->mNVisitorHardware->tRun(NSNKROSS::w->mNPsi00, (NParam)this, (NParam)params);
    }

    void setPreviewTexture(SurfaceTexture* surfaceTexture)
    {
        NSNKROSS::w->mNVisitorHardware->tRun(NSNKROSS::w->mNOmega00, (NParam)this, (NParam)surfaceTexture);
    }

    void startPreview()
    {
        NSNKROSS::w->mNVisitorHardware->tRun(NSNKROSS::w->mNAlpha01, (NParam)this);
    }

    void stopPreview()
    {
        NSNKROSS::w->mNVisitorHardware->tRun(NSNKROSS::w->mNBeta01, (NParam)this);
    }

private:
    Camera(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
