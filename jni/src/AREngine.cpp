#include "Common.h"

namespace NSDEVICE
{

AREngine::AREngine(Wrapper* vWrapper) :
    SurfaceTexture::OnFrameAvailableListener(),
    mUpdate(false), mHasEvent(false), mIsEventDone(true), mGrey(0), mARState(1), mEventState(1),
    mWidth(0), mHeight(0), mSpacingWidth(0), mSpacingHeight(0),
    mMaxDistance(0.0), mMaxStatic(nullptr), mMaxSorted(nullptr),
    maColumnOffset(new nfloat[k::LineCount]()), maItemCount(new nint[k::LineCount]()), maHasGap(new bool[k::LineCount]()), mItemTotal(0), mItemLast(nullptr),
    w(vWrapper), mEnv(nullptr), mGraphicsBuffer(nullptr), mPerspectiveProjection(4),
    mNorthAxis({0, 1, 0}), mUpAxis({0, 0, 1}), mChangeMatrix(9),
    mDeviceEarthCoord(3), mDeviceRotation(4), mNorthEarthCoord(3), mNorthGroundCoord(3), mNorthRotation(4),
    mPOIGroundCoord(3), mPOIScreenCoord(3), mPOIAzimuthRotation(4), mClassCoord(16), mClassRotation(4),
    mEventCoord(3), mEventRotation(4), mFrontOrientation(3), mFrontCoord(3), mFrontRotation(4),
    mcPreviewIndice(6),
    mPreviewTexture(nullptr), mPreviewProgram(nullptr),
    mPreviewVertex(nullptr), mPreviewFragment(nullptr), mPreviewRotation(nullptr), mPreviewTextureUnit(nullptr),
    mcPOIIndice(12),
    mPOIProgram(nullptr),
    mPOIVertex(nullptr), mPOIFragment(nullptr), mPOIRotation(nullptr), mPOITranslation(nullptr), mPOIProjection(nullptr),
    mcLabelIndice(6),
    mLabelTexture(nullptr), mLabelProgram(nullptr),
    mLabelVertex(nullptr), mLabelFragment(nullptr), mLabelRotation(nullptr), mLabelTranslation(nullptr), mLabelProjection(nullptr),
    mLabelTextureUnit(nullptr), mLabelBox(nullptr), mLabelColor(nullptr),
    mcDebugIndice(6),
    mDebugTexture(nullptr), mDebugProgram(nullptr),
    mDebugVertex(nullptr), mDebugFragment(nullptr), mDebugPosition(nullptr), mDebugBox(nullptr), mDebugTextureUnit(nullptr),
    mDebugParamNameArray({
        "vaFPS"
    }),
    mDebugParamArray(mDebugParamNameArray.mcData),
    mFrameFirst(0), mFrameCount(0)
{
    // Geomagnetic North Pole based on the WMM2015 coefficients for 2015.0
    nfloat vLat = 80.31*k::PiOn180;
    nfloat vLong = -72.62*k::PiOn180;

    mNorthEarthCoord.is(
        cos(vLat)*cos(vLong),
        cos(vLat)*sin(vLong),
        sin(vLat)
    );
}

AREngine::~AREngine()
{
    mNorthAxis.discard();
    mUpAxis.discard();
    mChangeMatrix.discard();
    mDeviceEarthCoord.discard();
    mDeviceRotation.discard();
    mNorthEarthCoord.discard();
    mNorthGroundCoord.discard();
    mPOIAzimuthRotation.discard();
    mClassCoord.discard();
    mClassRotation.discard();
}

void AREngine::engineCreate()
{
    LOGI("AREngine engineCreate");
    mEnv = (JNIEnv*)w->mNWrapper->mNKrossWrapper->mNKrossSystem->tAttachCurrentThread();
    w->mGraphicsHandler->createDisplayConfig();
}

void AREngine::engineEnable(Surface* vSurface, nint vWidth, nint vHeight)
{
    SLOGI("AREngine engineReset w: #" + to_string(vWidth) + " h: #" + to_string(vHeight));

    //*******************************************************************************
    //*************************** Display Surface ***********************************
    //*******************************************************************************
    NReturnObject vSurfaceObject = w->mNWrapper->mNKrossWrapper->mNKrossSystem->tRunObject((NParam)vSurface, -2);
    EGLNativeWindowType vEGLNativeWindow = ANativeWindow_fromSurface(mEnv, vSurfaceObject);

    w->mGraphicsHandler->createDisplaySurface(vEGLNativeWindow);
    w->mGraphicsHandler->enableRendering3D(vWidth, vHeight, true, false);
    w->mGraphicsHandler->enableRenderingFont(36);

    mWidth = vWidth;
    mHeight = vHeight;
    mSpacingWidth = 1.5*w->mNWrapper->mGraphicsWrapper->mGlyphWidth/mWidth;
    mSpacingHeight = 1.5*w->mNWrapper->mGraphicsWrapper->mGlyphHeight/mHeight;
    mClassCoord.is(
        0.9*mSpacingWidth,   0.6*mSpacingWidth,  0.3*mSpacingWidth,  0*mSpacingWidth,
       -5.3*mSpacingHeight, -2.8*mSpacingHeight, 2.2*mSpacingHeight, 4.7*mSpacingHeight,
       -4.3*mSpacingHeight, -1.8*mSpacingHeight, 1.2*mSpacingHeight, 3.7*mSpacingHeight,
        5,                   4,                  1,                  0
    );
    mGraphicsBuffer = w->mGraphicsHandler->factoryBuffer(
        NArray<nfloat>({
            // Preview Data
            +1.00f, -1.00f, +1.00f, 1.00f, 1.00f,
            -1.00f, +1.00f, +1.00f, 0.00f, 0.00f,
            -1.00f, -1.00f, +1.00f, 0.00f, 1.00f,
            +1.00f, +1.00f, +1.00f, 1.00f, 0.00f,
            // POI Data
            +0.00f, +0.00f, +0.01f, 1.00f, 0.00f,
            -0.05f, -0.05f, -0.01f, 0.00f, 0.00f,
            +0.05f, -0.05f, -0.01f, 0.00f, 0.00f,
            +0.00f, +0.05f, -0.01f, 0.00f, 1.00f,
            // Label Data
            +1.00f, +1.00f, +0.01f, 1.00f, 1.00f,
            +0.00f, +0.00f, +0.01f, 0.00f, 0.00f,
            +0.00f, +1.00f, +0.01f, 0.00f, 1.00f,
            +1.00f, +0.00f, +0.01f, 1.00f, 0.00f,
            // Debug Data
            +1.00f, +0.00f, +1.00f, 1.00f, 0.00f,
            +0.00f, +1.00f, +1.00f, 0.00f, 1.00f,
            +0.00f, +0.00f, +1.00f, 0.00f, 0.00f,
            +1.00f, +1.00f, +1.00f, 1.00f, 1.00f
        }),
        5,
        NArray<nushort>({
            // Preview Indices
            0, 1, 2,
            3, 1, 0,
            // POI Indices
            4, 5, 6,
            4, 7, 5,
            4, 6, 7,
            7, 6, 5,
            // Label Indices
            8, 9, 10,
            11, 9, 8,
            // Debug Indices
            12, 13, 14,
            15, 13, 12
        })
    );
    mGrey = 1.0f;
    mPreviewTexture = w->mGraphicsHandler->factoryTexture(GL_TEXTURE_EXTERNAL_OES, 0, 0, GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE, GL_NEAREST, GL_NEAREST);
    mLabelTexture = w->mGraphicsHandler->factoryTexture(GL_TEXTURE_2D, GL_ALPHA, GL_UNSIGNED_BYTE, GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE, GL_NEAREST, GL_NEAREST);
    mDebugTexture = w->mGraphicsHandler->factoryTexture(GL_TEXTURE_2D, GL_RGB, GL_UNSIGNED_BYTE, GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE, GL_NEAREST, GL_NEAREST);

    w->mcCameraMountOrientation = 0;
    w->mcDisplayRotation = (4 - w->mDisplay->getRotation())%4;
    w->mTexturePreview = new SurfaceTexture(mPreviewTexture->mID);
    w->mTexturePreview->setOnFrameAvailableListener(this);

    //*******************************************************************************
    //*************************** Perspective Projection ****************************
    //*******************************************************************************
    nfloat vTanAlphaH = 1;

    if (w->maCameraId.mcData) {
        nint vCameraId = w->maCameraId.maData[Camera::CameraInfo::CAMERA_FACING_BACK];
        w->mcCameraMountOrientation = (4 - w->maCameraInfo.maData[vCameraId].orientation/90)%4;
        w->mCamera = Camera::open(vCameraId);
    }
    if (w->mCamera) {
        nuint i = 0;
        Camera::Parameters* vParameters = w->mCamera->getParameters();
        vector<Camera::Size> vSupportedPreviewSizes = vParameters->getSupportedPreviewSizes();
        w->mcCameraFocalLength = vParameters->getFocalLength()/1000;
        w->mcCameraHorizontalAngle = vParameters->getHorizontalViewAngle()*k::PiOn180;
        w->mcCameraVerticalAngle = vParameters->getVerticalViewAngle()*k::PiOn180;
        vTanAlphaH = 1/tan(w->mcCameraHorizontalAngle/2);

        while (
            i + 1 < vSupportedPreviewSizes.size() &&
            isSuitedPreviewOrientation(mWidth, mHeight, vSupportedPreviewSizes[i + 1].width, vSupportedPreviewSizes[i + 1].height)
        ) {
            ++i;
        }
        vParameters->setPreviewSize(vSupportedPreviewSizes[i].width, vSupportedPreviewSizes[i].height);
        w->mCamera->setParameters(vParameters);
        w->mCamera->setPreviewTexture(w->mTexturePreview);
    } else {
        LOGE("Camera cannot be opened");
    }
    mPerspectiveProjection.is({
        ( mWidth > mHeight ? vTanAlphaH : vTanAlphaH ),
        ( mWidth > mHeight ? vTanAlphaH*mWidth/mHeight : vTanAlphaH*mWidth/mHeight ),
        3,
        110000
    });

    //*******************************************************************************
    //*************************** PREVIEW *******************************************
    //*******************************************************************************
    mPreviewProgram = w->mGraphicsHandler->factoryProgram(NArray<String>({"Preview.vert", "Preview.frag"}), mcPreviewIndice);
    mPreviewVertex = mPreviewProgram->createParam("vaVertex", mGraphicsBuffer, 3);
    mPreviewFragment = mPreviewProgram->createParam("vaFragment", mGraphicsBuffer, 2);
    mPreviewRotation = mPreviewProgram->createParam("vcRotation", NArray<nfloat>({
        getPreviewRotation(w->mcCameraMountOrientation, w->mcDisplayRotation)
    }));
    mPreviewTextureUnit = mPreviewProgram->createParam("vTextureUnit", mPreviewTexture);

    //*******************************************************************************
    //********************* POINT OF INTEREST ***************************************
    //*******************************************************************************
    mPOIProgram = w->mGraphicsHandler->factoryProgram(NArray<String>({"POI.vert", "POI.frag"}), mcPOIIndice);
    mPOIVertex = mPOIProgram->createParam("vaVertex", mGraphicsBuffer, 3);
    mPOIFragment = mPOIProgram->createParam("vaFragment", mGraphicsBuffer, 2);
    mPOIRotation = mPOIProgram->createParam("vaRotation", NArray<nfloat>(4));
    mPOITranslation = mPOIProgram->createParam("vaTranslation", NArray<nfloat>(3));
    mPOIProjection = mPOIProgram->createParam("vaProjection", mPerspectiveProjection);

    //*******************************************************************************
    //*************************** LABEL *********************************************
    //*******************************************************************************
    mLabelProgram = w->mGraphicsHandler->factoryProgram(NArray<String>({"Label.vert", "Label.frag"}), mcLabelIndice);
    mLabelVertex = mLabelProgram->createParam("vaVertex", mGraphicsBuffer, 3);
    mLabelFragment = mLabelProgram->createParam("vaFragment", mGraphicsBuffer, 2);
    mLabelRotation = mLabelProgram->createParam("vaRotation", NArray<nfloat>(4));
    mLabelTranslation = mLabelProgram->createParam("vaTranslation", NArray<nfloat>(3));
    mLabelProjection = mLabelProgram->createParam("vaProjection", mPerspectiveProjection);
    mLabelTextureUnit = mLabelProgram->createParam("vTextureUnit", mLabelTexture);
    mLabelBox = mLabelProgram->createParam("vaLabelBox", NArray<nfloat>(4));
    mLabelColor = mLabelProgram->createParam("vaLabelColor", NArray<nfloat>({0.5, 0.14, 0.5, 1.0}));

#ifdef DEBUG
    //*******************************************************************************
    //*************************** DEBUG *********************************************
    //*******************************************************************************
    NArray<nbyte> vAtlasMonoNum = w->mGraphicsHandler->loadAsset("AtlasMonoNum.rtx");

    mDebugProgram = w->mGraphicsHandler->factoryProgram(NArray<String>({"Debug.vert", "Debug.frag"}), mcDebugIndice);
    mDebugVertex = mDebugProgram->createParam("vaDebugVertex", mGraphicsBuffer, 3);
    mDebugFragment = mDebugProgram->createParam("vaDebugFragment", mGraphicsBuffer, 2);
    mDebugPosition = mDebugProgram->createParam("vaDebugPosition", NArray<nfloat>(3));
    mDebugBox = mDebugProgram->createParam("vaDebugBox", NArray<nfloat>({(nfloat)mWidth, (nfloat)mHeight}));
    mDebugTextureUnit = mDebugProgram->createParam("vDebugTextureUnit", mDebugTexture);
    mDebugParamArray.maData[0] = mDebugProgram->createParam(mDebugParamNameArray.maData[0].c_str(), NArray<nfloat>({0.0f, 0.0f, 0.0f}));
    mDebugTexture->setBitmap((nubyte*)vAtlasMonoNum.maData, 104, 10);
#endif //DEBUG
}

void AREngine::engineEnd()
{
    SLOGI(String("AREngine engineEnd"));
    w->mGraphicsHandler->endRendering3D();

    if (w->mTexturePreview) {
        w->mTexturePreview->release();
        delete w->mTexturePreview;
        w->mTexturePreview = nullptr;
    }
    if (w->mCamera) {
        w->mCamera->release();
        delete w->mCamera;
        w->mCamera = nullptr;
    }
}

void AREngine::engineResume()
{
    w->mAREngine->mPOIIt = w->maPOIStatic.begin();
    w->mOpUnitEvents->startEventsProduction();

    if (w->mCamera) {
        mUpdate = true;
        w->mCamera->startPreview();
    }
    glClearColor(mGrey, mGrey, mGrey, 1.0f);
}

void AREngine::engineRunEvent(nlong vT, nuint vX, nuint vY, nuint vState)
{
    if (vState > mEventState) {
        mEventState = vState;

        if (vState&1) {
            mIsEventDone = true;
        } else {
            mEventT0 = vT;
            mEventX0 = vX;
            mEventY0 = vY;
        }
    }
    if (!(vState&1)) {
        mHasEvent = true;
        mIsEventDone = false;

        // Screen coordinate system
        mEventCoord.is(
            (2.0f*vX/mWidth - 1.0f)/mPerspectiveProjection[0],
            (1.0f - 2.0f*vY/mHeight)/mPerspectiveProjection[1],
            -1
        );

        // Geomagnetic north aligned coordinate system
        mEventRotation.is4(mDeviceRotation).conj4();
        mFrontOrientation.is(0, 0, -1).rot3(mEventRotation);
        mFrontRotation.is4FromAxisAngle(mUpAxis, mFrontOrientation.angle2(mNorthAxis));
        mEventRotation.mul4AtLeft(mFrontRotation);
        mEventCoord.rot3(mEventRotation);
        mEventCoord.is(
            mPerspectiveProjection[0]*mEventCoord[0]/mEventCoord[1],
            mPerspectiveProjection[1]*mEventCoord[2]/mEventCoord[1]
        );
    }
}

void AREngine::engineRun()
{
    // Earth centered coordinate system
    //  X-axis intersects the sphere of the Earth at 0° latitude (Equator) and 0° longitude (Greenwich)
    //  Y is the cross-product X x Z
    //  Z-axis points toward the North Pole
    // North aligned coordinate system (device centered)
    //  X is the cross-product Y x Z, it is tangential to the ground and points east
    //  Y-axis is tangential to the ground, and points toward the North Pole
    //  Z-axis points toward the sky and is perpendicular to the ground plane
    // Geomagnetic north aligned coordinate system (device centered)
    //  X is the cross-product Y x Z, it is tangential to the ground and points approximately east
    //  Y-axis is tangential to the ground, and points toward the North Geomagnetic Pole
    //  Z-axis points toward the sky and is perpendicular to the ground plane
    nfloat vLastX;
    nfloat vSinAlpha;
    nint vLine;
    nint vMinLine;
    nint vMinCount;
    bool vIsNewGroup;
    BOPOI* vPOI = mPOIIt->second;
    nint vClass = 0;

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    //*******************************************************************************
    //*************************** CAMERA PREVIEW ************************************
    //*******************************************************************************
    mPreviewProgram->use();
    updatePreview();
    mPreviewProgram->draw();

    //*******************************************************************************
    //************************** POINT OF INTEREST **********************************
    //*******************************************************************************
    if (mIsEventDone) {
        // Earth centered coordinate system
        mDeviceEarthCoord.is3(w->mCoordBuffer->getHead());
        mDeviceRotation.is4(w->mRotationBuffer->getHead());

        // North aligned coordinate system
        vSinAlpha = sqrt(mDeviceEarthCoord[0]*mDeviceEarthCoord[0] + mDeviceEarthCoord[1]*mDeviceEarthCoord[1]);
        mChangeMatrix.is(
           -mDeviceEarthCoord[1]/vSinAlpha, -mDeviceEarthCoord[2]*mDeviceEarthCoord[0]/vSinAlpha, mDeviceEarthCoord[0],
            mDeviceEarthCoord[0]/vSinAlpha, -mDeviceEarthCoord[2]*mDeviceEarthCoord[1]/vSinAlpha, mDeviceEarthCoord[1],
            0.0f,                            vSinAlpha,                                           mDeviceEarthCoord[2]
        ).inv9();

        // Geomagnetic north aligned coordinate system
        mNorthGroundCoord.is3(mNorthEarthCoord).sub3(mDeviceEarthCoord).mul3AtLeft(mChangeMatrix);
        mNorthRotation.is4FromAxisAngle(mUpAxis, -mNorthAxis.angle2(mNorthGroundCoord));
    }
    if (!vPOI->mIsActive) {
        mPOIGroundCoord.is3(vPOI->maEarthCoord).sub3(mDeviceEarthCoord).scale3(6371000);
        vPOI->setDistance(mPOIGroundCoord.magnitude3());

        if (vPOI->mDistance < mMaxDistance) {
            vPOI->mIsActive = true;
            mMaxStatic->mIsActive = false;
            mMaxSorted->update(vPOI);
        }
    }
    if (++mPOIIt == w->maPOIStatic.end()) {
        mPOIIt = w->maPOIStatic.begin();
    }
    for (vLine = 0 ; vLine < k::LineCount ; ++vLine) {
        maHasGap[vLine] = true;
    }
    mMaxDistance = 0;
    vPOI = w->maPOISorted.getObject();

    while (vPOI) {
        // Earth centered coordinate system
        mPOIGroundCoord.is3(vPOI->maEarthCoord).sub3(mDeviceEarthCoord).scale3(6371000);
        vPOI->setDistance(mPOIGroundCoord.magnitude3());

        if (vPOI->mDistance > mMaxDistance && vPOI->mType == 2) {
            mMaxDistance = vPOI->mDistance;
            mMaxSorted = vPOI;
            mMaxStatic = w->maPOIStatic[vPOI->mId];
        }
        if (vPOI->mIsVisible) {
            // North aligned coordinate system
            mPOIGroundCoord.mul3AtLeft(mChangeMatrix);
            vPOI->setAzimuth(w->maPOISorted.getValue(), mNorthGroundCoord.angle2(mPOIGroundCoord));
        }
        if (vPOI->mIsVisible) {
            vIsNewGroup = true;

            for (vLine = 0 ; vLine < k::LineCount ; ++vLine) {
                vIsNewGroup &= maHasGap[vLine];
            }
            if (vIsNewGroup) {
                for (vLine = 0 ; vLine < k::LineCount ; ++vLine) {
                    maHasGap[vLine] = false;
                    maItemCount[vLine] = 0;
                    maColumnOffset[vLine] = -vPOI->mAzimuth - 0.5*k::MinGroupSpace;
                }
                mItemTotal = 0;
            }
            if (maItemCount[vPOI->mLine]++ > ++mItemTotal/k::LineCount) {
                vMinLine = 0;
                vMinCount = k::POICount;

                for (vLine = 0 ; vLine < k::LineCount ; ++vLine) {
                    if (maItemCount[vLine] < vMinCount) {
                        vMinCount = maItemCount[vLine];
                        vMinLine = vLine;
                    }
                }
                vPOI->mLine = vMinLine;
            }
            maHasGap[vPOI->mLine] = (-vPOI->mAzimuth - maColumnOffset[vPOI->mLine] > k::MinGroupSpace);

            if (maHasGap[vPOI->mLine]) {
                maColumnOffset[vPOI->mLine] = -vPOI->mAzimuth - 0.5*k::MinGroupSpace;
            }
            // Geomagnetic north aligned coordinate system
            mPOIGroundCoord.rot3(mNorthRotation);

            // Screen coordinate system
            mPOIAzimuthRotation.is4(mDeviceRotation).mul4ByAxisAngle(mUpAxis, vPOI->mAzimuth);
            mClassRotation.is4(mPOIAzimuthRotation).mul4ByAxisAngle(mNorthAxis, mClassCoord[vClass + 3]*k::PiOn6);
            mPOIScreenCoord.is3(mPOIGroundCoord).rot3(mDeviceRotation);

            // Draw
            mPOIProgram->use();
            mPOITranslation->is3(mPOIScreenCoord);
            mPOIRotation->is4(mClassRotation);
            mPOIProgram->draw();

            //*******************************************************************************
            //*************************** LABEL *********************************************
            //*******************************************************************************
            mLabelProgram->use();
            mLabelTranslation->is3(mPOIScreenCoord);
            mLabelRotation->is4(mPOIAzimuthRotation);
            mLabelColor->is4(vPOI->maColor);
            vLastX = w->mGraphicsHandler->renderFontLine(vPOI->mTitle, maColumnOffset[vPOI->mLine] + vPOI->mAzimuth, mClassCoord[vPOI->mLine*4 + 1], mLabelProgram, mLabelBox, mLabelTextureUnit);
          //vLastX = max(
          //    w->mGraphicsHandler->renderFontLine(vPOI->mTitle, mClassCoord[vClass], mClassCoord[vClass + 1], mLabelProgram, mLabelBox, mLabelTextureUnit),
          //    w->mGraphicsHandler->renderFontLine(vPOI->mText, mClassCoord[vClass], mClassCoord[vClass + 2], mLabelProgram, mLabelBox, mLabelTextureUnit)
          //);
            maColumnOffset[vPOI->mLine] += vLastX;

            //*******************************************************************************
            //*************************** Events ********************************************
            //*******************************************************************************
            if (mHasEvent) {
                // Geomagnetic north aligned coordinate system
                mFrontCoord.is3(mPOIGroundCoord).rot3(mFrontRotation);
                mFrontCoord.is(mFrontCoord[0], mFrontCoord[1] - 0.01f, mFrontCoord[2]);

                if (mFrontCoord[1] - mPerspectiveProjection[2] >= 0) {
                    nfloat vItemBoxGroundCoord[4] {
                        mPerspectiveProjection[0]*(mFrontCoord[0]/mFrontCoord[1] + mClassCoord[vClass]),
                        mPerspectiveProjection[1]*(mFrontCoord[2]/mFrontCoord[1] + mClassCoord[vClass + 2 - (vClass < 8)]),
                        mPerspectiveProjection[0]*(mFrontCoord[0]/mFrontCoord[1] + mClassCoord[vClass] + vLastX),
                        mPerspectiveProjection[1]*(mFrontCoord[2]/mFrontCoord[1] + mClassCoord[vClass + 1 + (vClass < 8)] + (nfloat)w->mNWrapper->mGraphicsWrapper->mGlyphHeight/mHeight)
                    };
                    nfloat vItemBoxMarginWidth = 0.1f*(vItemBoxGroundCoord[2] - vItemBoxGroundCoord[0]);
                    nfloat vItemBoxMarginHeight = 0.1f*(vItemBoxGroundCoord[3] - vItemBoxGroundCoord[1]);

                    if (
                        mEventCoord[0] >= vItemBoxGroundCoord[0] - vItemBoxMarginWidth && mEventCoord[1] >= vItemBoxGroundCoord[1] - vItemBoxMarginHeight &&
                        mEventCoord[0] <= vItemBoxGroundCoord[2] + vItemBoxMarginWidth && mEventCoord[1] <= vItemBoxGroundCoord[3] + vItemBoxMarginHeight
                    ) {
                        vPOI->maColor[0] = 0.14;
                        vPOI->maColor[1] = 0.5;
                        vPOI->maColor[2] = 0.14;
                        vPOI->maColor[3] = 1.0;
                    }
                }
            }
            vClass = (vClass + 4)%16;
        }
        vPOI = w->maPOISorted.updateValue(-vPOI->mAzimuth);
    }
    showDebug();
    w->mGraphicsHandler->flush();
    mHasEvent = false;
}

void AREngine::engineSleep()
{
    if (w->mCamera) {
        w->mCamera->stopPreview();
    }
    w->mOpUnitEvents->stopEventsProduction();
}

nfloat AREngine::getPreviewRotation(nint vcCameraMountOrientation, nint vcDisplayRotation)
{
    return (nfloat)((4 + vcCameraMountOrientation - vcDisplayRotation)%4)*M_PI_2;
}

bool AREngine::isSuitedPreviewOrientation(nint vTargetWidth, nint vTargetHeight, nint vSupportedWidth, nint vSupportedHeight)
{
    nint vIsSuited = (vTargetWidth > vTargetHeight);

    if (vSupportedHeight > vSupportedWidth) {
        vIsSuited = !vIsSuited;
    }
    if (vIsSuited) {
        vIsSuited = (vSupportedWidth > vTargetWidth && vSupportedHeight > vTargetHeight);
    } else {
        vIsSuited = (vSupportedWidth > vTargetHeight && vSupportedHeight > vTargetWidth);
    }
    return vIsSuited;
}

void AREngine::showDebug()
{
#ifdef DEBUG
    //*******************************************************************************
    //*************************** DEBUG *********************************************
    //*******************************************************************************
    nuint vcShowDebugLine = 3;
    nuint j;
    nuint k;
    nuint l;

    mDebugProgram->use();
    mDebugTexture->use();

    if (++mFrameCount > 200) {
        mDebugParamArray[0]->is((nfloat)mFrameCount/(nfloat)(system_clock::now().time_since_epoch().count() - mFrameFirst)*w->mc1Seconde, 0, 0);
        mFrameFirst = system_clock::now().time_since_epoch().count();
        mFrameCount = 0;
    }
    for (l = 0; l < vcShowDebugLine; ++l) {
        for (k = 0; k < 4; ++k) {
            for (j = 0; j < 8; ++j) {
                mDebugPosition->is(j, k, l);
                mDebugProgram->draw();
            }
        }
    }
#endif //DEBUG
}

void AREngine::updatePreview()
{
    if (mUpdate) {
        mUpdate = false;
        w->mTexturePreview->updateTexImage();
    }
}

void AREngine::onFrameAvailable(SurfaceTexture* surfaceTexture)
{
    // This callback is called on an arbitrary thread
    mUpdate = true;
}

} // End namespace
