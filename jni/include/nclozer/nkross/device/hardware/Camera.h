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
            NReturn index = NKrossWrapper::w->mNVisitorHardware->tRun(NKrossWrapper::w->mNAlpha00, (NParam)this);
            return NKrossWrapper::w->mNKrossSystem->tGetString(NKrossWrapper::w->mNKrossSystem->tRunObject((NParam)index));
        }

        virtual String get(const String& key)
        {
            NReturn index = NKrossWrapper::w->mNVisitorHardware->tRun(NKrossWrapper::w->mNBeta00, (NParam)this, NKrossParam(key).n);
            return NKrossWrapper::w->mNKrossSystem->tGetString(NKrossWrapper::w->mNKrossSystem->tRunObject((NParam)index));
        }

        virtual float getFocalLength()
        {
            nlong vcValue = NKrossWrapper::w->mNVisitorHardware->tRun(NKrossWrapper::w->mNGamma00, (NParam)this);
            return (nfloat)*reinterpret_cast<ndouble*>(&vcValue);
        }

        virtual float getHorizontalViewAngle()
        {
            nlong vcValue = NKrossWrapper::w->mNVisitorHardware->tRun(NKrossWrapper::w->mNDelta00, (NParam)this);
            return (nfloat)*reinterpret_cast<ndouble*>(&vcValue);
        }

        virtual int getInt(const String& key)
        {
            return (nint)NKrossWrapper::w->mNVisitorHardware->tRun(NKrossWrapper::w->mNEpsilon00, (NParam)this, NKrossParam(key).n);
        }

        virtual vector<nint> getPreviewSize()
        {
            NReturn index = NKrossWrapper::w->mNVisitorHardware->tRun(NKrossWrapper::w->mNDzeta00, (NParam)this);
            NReturn size = NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNAlpha01, index, -1);
            vector<nint> vVector =  vector<nint>();
            nuint i;

            for (i = 0 ; i < size ; ++i) {
                vVector.push_back((nint)NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNAlpha01, index, (NParam)i));
            }
            return vVector;
        }

        virtual vector<String> getSupportedFlashModes()
        {
            NReturn index = NKrossWrapper::w->mNVisitorHardware->tRun(NKrossWrapper::w->mNEta00, (NParam)this);
            NReturn size = NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNAlpha01, index, -1);
            vector<String> vVector = vector<String>();
            nuint i;

            for (i = 0 ; i < size ; ++i) {
                vVector.push_back(NKrossWrapper::w->mNKrossSystem->tGetString(NKrossWrapper::w->mNKrossSystem->tRunObject(index, (NParam)i)));
            }
            return vVector;
        }

        virtual vector<String> getSupportedFocusModes()
        {
            NReturn index = NKrossWrapper::w->mNVisitorHardware->tRun(NKrossWrapper::w->mNTheta00, (NParam)this);
            NReturn size = NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNAlpha01, index, -1);
            vector<String> vVector = vector<String>();
            nuint i;

            for (i = 0 ; i < size ; ++i) {
                vVector.push_back(NKrossWrapper::w->mNKrossSystem->tGetString(NKrossWrapper::w->mNKrossSystem->tRunObject(index, (NParam)i)));
            }
            return vVector;
        }

        virtual vector<Camera::Size> getSupportedPreviewSizes()
        {
            NReturn index = NKrossWrapper::w->mNVisitorHardware->tRun(NKrossWrapper::w->mNIota00, (NParam)this);
            NReturn size = NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNAlpha01, index, -1)>>1;
            vector<Camera::Size> vVector =  vector<Camera::Size>();
            nuint i;

            for (i = 0 ; i < size ; ++i) {
                vVector.push_back(Camera::Size(
                    (nint)NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNAlpha01, index, (NParam)2*i),
                    (nint)NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNAlpha01, index, (NParam)2*i + 1)
                ));
            }
            return vVector;
        }

        virtual float getVerticalViewAngle()
        {
            nlong vcValue = NKrossWrapper::w->mNVisitorHardware->tRun(NKrossWrapper::w->mNKappa00, (NParam)this);
            return (nfloat)*reinterpret_cast<ndouble*>(&vcValue);
        }

        virtual bool getVideoStabilization()
        {
            return (bool)NKrossWrapper::w->mNVisitorHardware->tRun(NKrossWrapper::w->mNLambda00, (NParam)this);
        }

        virtual bool isVideoStabilizationSupported()
        {
            return (bool)NKrossWrapper::w->mNVisitorHardware->tRun(NKrossWrapper::w->mNMu00, (NParam)this);
        }

        virtual bool isZoomSupported()
        {
            return (bool)NKrossWrapper::w->mNVisitorHardware->tRun(NKrossWrapper::w->mNNu00, (NParam)this);
        }

        virtual void remove(const String& key)
        {
            NKrossWrapper::w->mNVisitorHardware->tRun(NKrossWrapper::w->mNXi00, (NParam)this, NKrossParam(key).n);
        }

        virtual void set(const String& key, const String& value)
        {
            NKrossWrapper::w->mNVisitorHardware->tRun(NKrossWrapper::w->mNOmicron00, (NParam)this, NKrossParam(key).n, NKrossParam(value).n);
        }

        virtual void set(const String& key, int value)
        {
            NKrossWrapper::w->mNVisitorHardware->tRun(NKrossWrapper::w->mNPi00, (NParam)this, NKrossParam(key).n, (NParam)value);
        }

        virtual void setPreviewSize(int width, int height)
        {
            NKrossWrapper::w->mNVisitorHardware->tRun(NKrossWrapper::w->mNRho00, (NParam)this, (NParam)width, (NParam)height);
        }

        virtual void setRotation(int rotation)
        {
            NKrossWrapper::w->mNVisitorHardware->tRun(NKrossWrapper::w->mNEta01, (NParam)this, (NParam)rotation);
        }

        virtual void setVideoStabilization(bool toggle)
        {
            NKrossWrapper::w->mNVisitorHardware->tRun(NKrossWrapper::w->mNSigma00, (NParam)this, (NParam)toggle);
        }

        virtual void unflatten(const String& flattened)
        {
            NKrossWrapper::w->mNVisitorHardware->tRun(NKrossWrapper::w->mNTau00, (NParam)this, NKrossParam(flattened).n);
        }

    private:
        Parameters(NKrossFriend* vNKrossFriend)
        {
        }
    };

    static void getCameraInfo(int cameraId, Camera::CameraInfo& cameraInfo)
    {
        NReturn index = NKrossWrapper::w->mNVisitorHardware->tRun(NKrossWrapper::w->mNGamma01, (NParam)cameraId);
        NReturn size = NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNAlpha01, index, -1);

        if (size > 1) {
            cameraInfo.facing = (nint)NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNAlpha01, index, (NParam)0);
            cameraInfo.orientation = (nint)NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNAlpha01, index, (NParam)1);
        }
    }

    static int getNumberOfCameras()
    {
        return (nint)NKrossWrapper::w->mNVisitorHardware->tRun(NKrossWrapper::w->mNDelta01);
    }

    static Camera* open()
    {
        Camera* b = NKrossWrapper::w->mNKrossFriend->pointer<Camera>();
        return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorHardware->tRun(NKrossWrapper::w->mNUpsilon00, (NParam)b));
    }

    static Camera* open(int cameraId)
    {
        Camera* b = NKrossWrapper::w->mNKrossFriend->pointer<Camera>();
        return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorHardware->tRun(NKrossWrapper::w->mNEpsilon01, (NParam)b, (NParam)cameraId));
    }

    virtual ~Camera()
    {
    }

    virtual Camera::Parameters* getParameters()
    {
        Camera::Parameters* b = NKrossWrapper::w->mNKrossFriend->pointer<Camera::Parameters>();
        return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorHardware->tRun(NKrossWrapper::w->mNPhi00, (NParam)this, (NParam)b));
    }

    void release()
    {
        NKrossWrapper::w->mNVisitorHardware->tRun(NKrossWrapper::w->mNKhi00, (NParam)this);
    }

    void setDisplayOrientation(int degrees)
    {
        NKrossWrapper::w->mNVisitorHardware->tRun(NKrossWrapper::w->mNDzeta01, (NParam)this, (NParam)degrees);
    }

    virtual void setParameters(Camera::Parameters* params)
    {
        NKrossWrapper::w->mNVisitorHardware->tRun(NKrossWrapper::w->mNPsi00, (NParam)this, (NParam)params);
    }

    void setPreviewTexture(SurfaceTexture* surfaceTexture)
    {
        NKrossWrapper::w->mNVisitorHardware->tRun(NKrossWrapper::w->mNOmega00, (NParam)this, (NParam)surfaceTexture);
    }

    void startPreview()
    {
        NKrossWrapper::w->mNVisitorHardware->tRun(NKrossWrapper::w->mNAlpha01, (NParam)this);
    }

    void stopPreview()
    {
        NKrossWrapper::w->mNVisitorHardware->tRun(NKrossWrapper::w->mNBeta01, (NParam)this);
    }

private:
    Camera(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
