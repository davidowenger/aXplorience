#ifndef __AREngine_H__
#define __AREngine_H__

namespace NSDEVICE
{

class AREngine : public SurfaceTexture::OnFrameAvailableListener
{
public:
    static const nuint kTextureUnitBase = GL_TEXTURE0;

    AREngine(Wrapper* vWrapper);
    virtual ~AREngine();

    void engineCreate();
    void engineEnable(Surface* vSurface, int width, int height);
    void engineEnd();
    void enginePlay();
    void engineResume();
    void engineRun();
    void engineSleep();
    nfloat getPreviewRotation(nint vcCameraMountOrientation, nint vcDisplayRotation);
    bool isSuitedPreviewOrientation(nint vTargetWidth, nint vTargetHeight, nint vSupportedWidth, nint vSupportedHeight);
    void updatePreview();

    // SurfaceTexture::OnFrameAvailableListener
    virtual void onFrameAvailable(SurfaceTexture* surfaceTexture);

    bool mUpdate;
    nfloat mGrey;
    nuint mARState;
    nuint mARSurface;
    nint mWidth;
    nint mHeight;
    nfloat mSpacingWidth;
    nfloat mSpacingHeight;

    Wrapper* w;
    JNIEnv* mEnv;
    GraphicsBuffer* mGraphicsBuffer;

    NVec<nfloat> mNorthAxis;
    NVec<nfloat> mUpAxis;
    NVec<nfloat> mChangeMatrix;
    NVec<nfloat> mDeviceEarthCoord;
    NVec<nfloat> mDeviceRotation;
    NVec<nfloat> mNorthEarthCoord;
    NVec<nfloat> mNorthCoord;
    NVec<nfloat> mPOICoord;
    NVec<nfloat> mPOIAzimuthRotation;
    NVec<nfloat> mClassCoord;
    NVec<nfloat> mClassRotation;

    nuint mcPreviewIndice;
    GraphicsTexture* mPreviewTexture;
    GraphicsProgram* mPreviewProgram;
    GraphicsParam* mPreviewVertex;
    GraphicsParam* mPreviewFragment;
    GraphicsParam* mPreviewRotation;
    GraphicsParam* mPreviewTextureUnit;

    nuint mcPOIIndice;
    GraphicsProgram* mPOIProgram;
    GraphicsParam* mPOIVertex;
    GraphicsParam* mPOIFragment;
    GraphicsParam* mPOIRotation;
    GraphicsParam* mPOITranslation;
    GraphicsParam* mPOIProjection;

    nuint mcLabelIndice;
    GraphicsTexture* mLabelTexture;
    GraphicsProgram* mLabelProgram;
    GraphicsParam* mLabelVertex;
    GraphicsParam* mLabelFragment;
    GraphicsParam* mLabelRotation;
    GraphicsParam* mLabelTranslation;
    GraphicsParam* mLabelProjection;
    GraphicsParam* mLabelTextureUnit;
    GraphicsParam* mLabelPosition;
    GraphicsParam* mLabelBox;
    GraphicsParam* mLabelColor;

    nuint mcDebugIndice;
    GraphicsTexture* mDebugTexture;
    GraphicsProgram* mDebugProgram;
    GraphicsParam* mDebugVertex;
    GraphicsParam* mDebugFragment;
    GraphicsParam* mDebugPosition;
    GraphicsParam* mDebugBox;
    GraphicsParam* mDebugTextureUnit;
    NArray<String> mDebugParamNameArray;
    NArray<GraphicsParam*> mDebugParamArray;
};

} // End namespace

#endif
