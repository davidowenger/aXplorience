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
    void engineResume();
    void engineRunEvent(nlong vT, nuint vX, nuint vY, nuint vState);
    void engineRun();
    void engineSleep();
    nfloat getPreviewRotation(nint vcCameraMountOrientation, nint vcDisplayRotation);
    bool isSuitedPreviewOrientation(nint vTargetWidth, nint vTargetHeight, nint vSupportedWidth, nint vSupportedHeight);
    void showDebug();
    void updatePreview();

    // SurfaceTexture::OnFrameAvailableListener
    virtual void onFrameAvailable(SurfaceTexture* surfaceTexture);

    bool mUpdate;
    bool mHasEvent;
    bool mIsEventDone;
    nfloat mGrey;
    nuint mARState;
    nlong mEventT0;
    nuint mEventX0;
    nuint mEventY0;
    nuint mEventState;
    nint mWidth;
    nint mHeight;
    nfloat mSpacingWidth;
    nfloat mSpacingHeight;

    map<nuint,BOPOI*>::iterator mPOIIt;
    nfloat mMaxDistance;
    BOPOI* mMaxStatic;
    BOPOI* mMaxSorted;
    nfloat* maColumnOffset;
    nint* maItemCount;
    bool* maHasGap;
    nint mItemTotal;
    BOPOI* mItemLast;

    Wrapper* w;
    JNIEnv* mEnv;
    GraphicsBuffer* mGraphicsBuffer;
    NArray<nfloat> mPerspectiveProjection;

    NVec<nfloat> mNorthAxis;
    NVec<nfloat> mUpAxis;
    NVec<nfloat> mChangeMatrix;
    NVec<nfloat> mDeviceEarthCoord;
    NVec<nfloat> mDeviceRotation;
    NVec<nfloat> mNorthEarthCoord;
    NVec<nfloat> mNorthGroundCoord;
    NVec<nfloat> mNorthRotation;
    NVec<nfloat> mPOIGroundCoord;
    NVec<nfloat> mPOIScreenCoord;
    NVec<nfloat> mPOIAzimuthRotation;
    NVec<nfloat> mClassCoord;
    NVec<nfloat> mClassRotation;
    NVec<nfloat> mEventCoord;
    NVec<nfloat> mEventRotation;
    NVec<nfloat> mFrontOrientation;
    NVec<nfloat> mFrontCoord;
    NVec<nfloat> mFrontRotation;

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

    TimeStamp mFrameFirst;
    nfloat mFrameCount;
};

} // End namespace

#endif
