#include "Common.h"

namespace NSDEVICE
{

AREngine::AREngine(Wrapper* vWrapper) :
    SurfaceTexture::OnFrameAvailableListener(),
    mUpdate(false), mGrey(0), mARState(1), mARSurface(1), mWidth(0), mHeight(0), mSpacingWidth(0), mSpacingHeight(0),
    w(vWrapper), mEnv(nullptr), mGraphicsBuffer(nullptr),
    mNorthAxis({0, 1, 0}), mUpAxis({0, 0, 1}), mChangeMatrix(9), mDeviceEarthCoord(3), mDeviceRotation(4),
    mNorthEarthCoord(3), mNorthCoord(3), mPOICoord(3), mPOIAzimuthRotation(4), mClassCoord(16), mClassRotation(4),
    mcPreviewIndice(6),
    mPreviewTexture(nullptr), mPreviewProgram(nullptr),
    mPreviewVertex(nullptr), mPreviewFragment(nullptr), mPreviewRotation(nullptr), mPreviewTextureUnit(nullptr),
    mcPOIIndice(12),
    mPOIProgram(nullptr),
    mPOIVertex(nullptr), mPOIFragment(nullptr), mPOIRotation(nullptr), mPOITranslation(nullptr), mPOIProjection(nullptr),
    mcLabelIndice(6),
    mLabelTexture(nullptr), mLabelProgram(nullptr),
    mLabelVertex(nullptr), mLabelFragment(nullptr), mLabelRotation(nullptr), mLabelTranslation(nullptr), mLabelProjection(nullptr),
    mLabelTextureUnit(nullptr), mLabelPosition(nullptr), mLabelBox(nullptr), mLabelColor(nullptr),
    mcDebugIndice(6),
    mDebugTexture(nullptr), mDebugProgram(nullptr),
    mDebugVertex(nullptr), mDebugFragment(nullptr), mDebugPosition(nullptr), mDebugBox(nullptr), mDebugTextureUnit(nullptr),
    mDebugParamNameArray({
        "vaVertex",
        "vaFragment",
        "vcRotation"
    }),
    mDebugParamArray(mDebugParamNameArray.mcData)
{
    // Geomagnetic North Pole based on the WMM2015 coefficients for 2015.0
    nfloat vLat = 80.31*M_PI_180;
    nfloat vLong = -72.62*M_PI_180;

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
    mNorthCoord.discard();
    mPOICoord.discard();
    mPOIAzimuthRotation.discard();
    mClassCoord.discard();
    mClassRotation.discard();
}

void AREngine::engineCreate()
{
    LOGI("AREngine engineCreate");
    w->mGraphicsHandler->createDisplayConfig();
    mEnv = (JNIEnv*)w->mNWrapper->mNKrossWrapper->mNKrossSystem->tAttachCurrentThread();
}

void AREngine::engineEnable(Surface* vSurface, nint vWidth, nint vHeight)
{
    SLOGI("AREngine engineReset w: #" + to_string(vWidth) + " h: #" + to_string(vHeight));

    NReturnObject vSurfaceObject = w->mNWrapper->mNKrossWrapper->mNKrossSystem->tRunObject((NParam)vSurface, -2);
    EGLNativeWindowType vEGLNativeWindow = ANativeWindow_fromSurface(mEnv, vSurfaceObject);

    w->mGraphicsHandler->createDisplaySurface(vEGLNativeWindow);
    w->mGraphicsHandler->enableRendering3D(vWidth, vHeight, true, true);
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

    //*******************************************************************************
    //*************************** PREVIEW *******************************************
    //*******************************************************************************
    nfloat vTanAlphaH = 1;

    w->mTexturePreview = new SurfaceTexture(mPreviewTexture->mID);
    w->mTexturePreview->setOnFrameAvailableListener(this);

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
        w->mcCameraHorizontalAngle = vParameters->getHorizontalViewAngle()*M_PI_180;
        w->mcCameraVerticalAngle = vParameters->getVerticalViewAngle()*M_PI_180;
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
    mPOIProjection = mPOIProgram->createParam("vaProjection", NArray<nfloat>({
        ( mWidth > mHeight ? vTanAlphaH : vTanAlphaH ),
        ( mWidth > mHeight ? vTanAlphaH*mWidth/mHeight : vTanAlphaH*mWidth/mHeight ),
        3,
        110000
    }));

    //*******************************************************************************
    //*************************** LABEL *********************************************
    //*******************************************************************************
    mLabelProgram = w->mGraphicsHandler->factoryProgram(NArray<String>({"Label.vert", "Label.frag"}), mcLabelIndice);
    mLabelVertex = mLabelProgram->createParam("vaVertex", mGraphicsBuffer, 3);
    mLabelFragment = mLabelProgram->createParam("vaFragment", mGraphicsBuffer, 2);
    mLabelRotation = mLabelProgram->createParam("vaRotation", NArray<nfloat>(4));
    mLabelTranslation = mLabelProgram->createParam("vaTranslation", NArray<nfloat>(3));
    mLabelProjection = mLabelProgram->createParam("vaProjection", NArray<nfloat>(4));
    mLabelTextureUnit = mLabelProgram->createParam("vTextureUnit", mLabelTexture);
    mLabelPosition = mLabelProgram->createParam("vaLabelPosition", NArray<nfloat>(2));
    mLabelBox = mLabelProgram->createParam("vaLabelBox", NArray<nfloat>(4));
    mLabelColor = mLabelProgram->createParam("vaLabelColor", NArray<nfloat>({0.5, 0.14, 0.5, 1.0}));
    mLabelProjection->is(mPOIProjection);

#ifdef DEBUG
    //*******************************************************************************
    //*************************** DEBUG *********************************************
    //*******************************************************************************
    nuint i;
    NArray<nbyte> vAtlasMonoNum = w->mGraphicsHandler->loadAsset("AtlasMonoNum.rtx");

    mDebugProgram = w->mGraphicsHandler->factoryProgram(NArray<String>({"Debug.vert", "Debug.frag"}), mcDebugIndice);
    mDebugVertex = mDebugProgram->createParam("vaDebugVertex", mGraphicsBuffer, 3);
    mDebugFragment = mDebugProgram->createParam("vaDebugFragment", mGraphicsBuffer, 2);
    mDebugPosition = mDebugProgram->createParam("vaDebugPosition", NArray<nfloat>(3));
    mDebugBox = mDebugProgram->createParam("vaDebugBox", NArray<nfloat>({(nfloat)mWidth, (nfloat)mHeight}));
    mDebugTextureUnit = mDebugProgram->createParam("vDebugTextureUnit", mDebugTexture);
    mDebugParamArray.maData[0] = mDebugProgram->createParam(mDebugParamNameArray.maData[0].c_str(), NArray<nfloat>(3));
    mDebugParamArray.maData[1] = mDebugProgram->createParam(mDebugParamNameArray.maData[1].c_str(), NArray<nfloat>(2));

    for (i = 2 ; i < mDebugParamArray.mcData ; ++i) {
        mDebugParamArray.maData[i] = mDebugProgram->createParam(mDebugParamNameArray.maData[i].c_str(), NArray<nfloat>(1));
    }
    mDebugTexture->setBitmap((nubyte*)vAtlasMonoNum.maData, 104, 10);
#endif //DEBUG
}

void AREngine::engineEnd()
{
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

void AREngine::enginePlay()
{
    bool vStarted = true;
    mARState = 2;

    while (vStarted) {
        switch (mARState) {
        case 0: // destroy
            LOGI("AR Engine state 0 -> 1");
            engineEnd();
            mARState = 1;
            this_thread::sleep_for(chrono::milliseconds(40));
            break;
        case 1: // off
            vStarted = false;
            this_thread::sleep_for(chrono::milliseconds(40));
            break;
        case 2: // create
            if (w->mARState != 2 && w->mARSurface == 2) {
                LOGI("AR Engine state 2 -> 3");
                engineEnable(w->mSurface, w->mSurfaceWidth, w->mSurfaceHeight);
                mARSurface = w->mARSurface;
                mARState = 3;
            }
            if (w->mARState == 0) {
                LOGI("AR Engine state 2 -> 0");
                mARState = 0;
            }
            this_thread::sleep_for(chrono::milliseconds(40));
            break;
        case 3: // resume
            LOGI("AR Engine state 3 -> 4");
            engineResume();
            mARState = 4;

            if (w->mARState != 3) {
                LOGI("AR Engine state 3 -> 5");
                mARState = 5;
            }
            this_thread::sleep_for(chrono::milliseconds(40));
            break;
        case 4: // run
            engineRun();

            if (w->mARState != 3) {
                LOGI("AR Engine state 4 -> 5");
                mARState = 5;
            }
            break;
        case 5: // pause
            engineSleep();

            if (w->mARState < 3) {
                LOGI("AR Engine state 5 -> 0");
                mARState = 0;
            }
            if (w->mARState == 3) {
                LOGI("AR Engine state 5 -> 3");
                mARState = 3;
            }
            this_thread::sleep_for(chrono::milliseconds(40));
            break;
        default: // bad state
            LOGE("AR Engine BAD state");
            mARState = 0;
            this_thread::sleep_for(chrono::milliseconds(40));
            break;
        }
        this_thread::sleep_for(chrono::milliseconds(10));
    }
}

void AREngine::engineResume()
{
    w->mOpUnitEvents->startEventsProduction();

    if (w->mCamera) {
        mUpdate = false;
        w->mCamera->startPreview();
    }
    glClearColor(mGrey, mGrey, mGrey, 1.0f);
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
    nfloat vSinAlpha;
    nfloat vNorthDeclination;
    BOPOI* vPOI;
    nfloat vPOIAzimuth;
    nint vPOIDistance;
    nfloat vPreviousValue;
    nint vClass = 0;

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    //*******************************************************************************
    //*************************** CAMERA PREVIEW ************************************
    //*******************************************************************************
    mPreviewProgram->use();
    updatePreview();
    mPreviewProgram->draw();

    while ((vPOI = w->mPOISortList->updateHead())) {
        //*******************************************************************************
        //************************** POINT OF INTEREST **********************************
        //*******************************************************************************
        // Earth centered coordinate system
        mDeviceEarthCoord.is3(w->mCoordBuffer->getHead());
        mPOICoord.is3(vPOI->maEarthCoord).sub3(mDeviceEarthCoord).scale3(6371000);
        vPOIDistance = mPOICoord.magnitude3();
        vPOIAzimuth = 100000;
        vPreviousValue = 100000;

        if (vPOIDistance >= 100000) {
            vPreviousValue = w->mPOISortList->updateValue(vPOIDistance);
        }
        if (vPOIDistance < 100000 || vPreviousValue < 100000) {
            // North aligned coordinate system
            vSinAlpha = sqrt(mDeviceEarthCoord[0]*mDeviceEarthCoord[0] + mDeviceEarthCoord[1]*mDeviceEarthCoord[1]);
            mChangeMatrix.is(
               -mDeviceEarthCoord[1]/vSinAlpha, -mDeviceEarthCoord[2]*mDeviceEarthCoord[0]/vSinAlpha, mDeviceEarthCoord[0],
                mDeviceEarthCoord[0]/vSinAlpha, -mDeviceEarthCoord[2]*mDeviceEarthCoord[1]/vSinAlpha, mDeviceEarthCoord[1],
                0.0f,                            vSinAlpha,                                           mDeviceEarthCoord[2]
            ).inv9();
            mPOICoord.mul3AtLeft(mChangeMatrix);

            // Geomagnetic north aligned coordinate system
            mNorthCoord.is3(mNorthEarthCoord).sub3(mDeviceEarthCoord).mul3AtLeft(mChangeMatrix);
            vPOIAzimuth = mNorthCoord.angle2(mPOICoord);
        }
        if (vPOIDistance < 100000) {
            vPreviousValue = w->mPOISortList->updateValue(vPOIAzimuth);
        }
        if (vPreviousValue < 100000) {
            vNorthDeclination = mNorthAxis.angle2(mNorthCoord);
            mPOICoord.rot3ByAxisAngle(mUpAxis, -vNorthDeclination);

            // Device coordinate system
            mDeviceRotation.is4(w->mRotationBuffer->getHead());
            mPOIAzimuthRotation.is4(mDeviceRotation).mul4ByAxisAngle(mUpAxis, vPOIAzimuth);
            mClassRotation.is4(mPOIAzimuthRotation).mul4ByAxisAngle(mNorthAxis, mClassCoord[vClass + 3]*M_PI/6.0f);
            mPOICoord.rot3(mDeviceRotation);

            // Draw
            mPOIProgram->use();
            mPOITranslation->is3(mPOICoord);
            mPOIRotation->is4(mClassRotation);
            mPOIProgram->draw();

            //*******************************************************************************
            //*************************** LABEL *********************************************
            //*******************************************************************************
            mLabelProgram->use();
            mLabelTranslation->is3(mPOICoord);
            mLabelRotation->is4(mPOIAzimuthRotation);

            mLabelPosition->is(mClassCoord[vClass], mClassCoord[vClass + 1]);
            w->mGraphicsHandler->renderFontLine(vPOI->mLabel, mLabelProgram, mLabelPosition, mLabelBox, mLabelTextureUnit);
            mLabelPosition->is(mClassCoord[vClass], mClassCoord[vClass + 2]);
            w->mGraphicsHandler->renderFontLine(to_string(vPOIDistance) + "m", mLabelProgram, mLabelPosition, mLabelBox, mLabelTextureUnit);

#ifdef DEBUG
            //*******************************************************************************
            //*************************** DEBUG *********************************************
            //*******************************************************************************
            nuint vcShowDebugLine = 4;
            nuint i = 0;
            nuint j;
            nuint k;
            nuint l;

            mDebugProgram->use();
            mDebugTexture->use();
            mDebugParamArray[2]->is(getPreviewRotation(w->mcCameraMountOrientation, w->mcDisplayRotation));

            for (l = 0; l < vcShowDebugLine; ++l) {
                for (k = 0; k < 4; ++k) {
                    for (j = 0; j < 8; ++j) {
                        mDebugPosition->is(j, k, l);
                        mDebugParamArray[0]->is3(mGraphicsBuffer->mDataArray.maData + i + k*5);
                        mDebugParamArray[1]->is2(mGraphicsBuffer->mDataArray.maData + i + k*5 + 3);
                        mDebugProgram->draw();
                    }
                }
            }
#endif //DEBUG

            vClass = (vClass + 4)%16;
        }
    }
    w->mGraphicsHandler->flush();
    w->mPOISortList->swap();
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
