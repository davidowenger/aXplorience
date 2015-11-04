#include "Common.h"

namespace NSDEVICE
{

AREngine::AREngine(Wrapper* vWrapper) :
    SurfaceTexture::OnFrameAvailableListener(), w(vWrapper), mEnv(nullptr), mEGLDisplay(nullptr), mEGLConfig(nullptr), mEGLContext(nullptr), mEGLSurface(nullptr),
    maVertexPreview(new GLfloat[24] {
        +1.0f, -1.0f, +1.0f, +1.0f,
        -1.0f, +1.0f, +1.0f, +1.0f,
        -1.0f, -1.0f, +1.0f, +1.0f,
        +1.0f, +1.0f, +1.0f, +1.0f,
        -1.0f, +1.0f, +1.0f, +1.0f,
        +1.0f, -1.0f, +1.0f, +1.0f,
    }),
    maCoordPreview(new GLfloat[12] {
        1.0f, 1.0f,
        0.0f, 0.0f,
        0.0f, 1.0f,
        1.0f, 0.0f,
        0.0f, 0.0f,
        1.0f, 1.0f
    }),
    mProjection(new GLfloat[4] {0, 0, 0, 1}),
    mModel(new GLfloat[4] {0, 0, 0, 1}),
    mcARState(1), mcARSurface(1),  mWidth(0), mHeight(0), mModelIndex(0.0), mGrey(1.0),
    mhProgramCameraPreview(0), mhProgramOverlayText(0), mhVertexPreview(0), mhCoordPreview(0), mhSamplerPreview(0),
    mhTransformation(0), mhVertexPOI(0), mhProgramPOI(0), mhModel(0), mhProjection(0), mhVertexBuffer(0),
    mhIndiceBuffer(0), mhTexturePreview(0), mUpdate(false),
    maVertexPOI({
        +0.0f, +0.0f, +1.0f, +0.85f,
        -1.0f, -1.0f, +2.0f, +0.65f,
        +1.0f, -1.0f, +2.0f, +0.00f,
        +0.0f, +1.0f, +2.0f, +0.45f
    }),
    maIndicesPOI({
        0, 1, 2,
        0, 2, 3,
        0, 3, 1
    })
{
}

AREngine::~AREngine()
{
    maVertexPOI.discard();
    maIndicesPOI.discard();

    delete maVertexPreview;
    delete maCoordPreview;
    delete mProjection;
    delete mModel;
}

void AREngine::engineCreate()
{
    LOGI("AREngine engineCreate");

    //*******************************************************************************
    //********************************* EGL *****************************************
    //*******************************************************************************
#ifdef EGL_VERSION_1_3
    LOGI("EGL Version 1.3");
    nuint vState = 0;
    EGLint vSize = 0;
    NArray<EGLint> vaConfigAttrib({
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
        EGL_NONE
    });
    NArray<EGLint> vaContextAttrib({
         EGL_CONTEXT_CLIENT_VERSION, 2,
         EGL_NONE
    });
    mEnv = (JNIEnv*)w->mNWrapper->mNKrossWrapper->mNKrossSystem->tAttachCurrentThread();
    mEGLDisplay = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    vState = (mEGLDisplay != nullptr);

    if (vState) {
        vState &= eglInitialize(mEGLDisplay, NULL, NULL);
    } else {
        LOGE("Could not get default display");
    }
    if (vState) {
        vState = eglChooseConfig(mEGLDisplay, vaConfigAttrib.maData, &mEGLConfig, 1, &vSize);
        vState &= (vSize > 0);
    } else {
        LOGE("Could not initialize display");
    }
    if (vState) {
        mEGLContext = eglCreateContext(mEGLDisplay, mEGLConfig, nullptr, vaContextAttrib.maData);
        vState &= (mEGLContext != nullptr);
    } else {
        LOGE("Could not find configuration");
    }
    if (vState) {
        LOGI("EGL context created");
    } else {
        LOGE("Could not create context");
    }
    vaConfigAttrib.discard();
    vaContextAttrib.discard();
#else
    LOGE("EGL version 1.3 not found");
#endif //EGL_VERSION_1_3
}

void AREngine::engineDestroy()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glUseProgram(0);

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

void AREngine::engineInit(Surface* vSurface, int width, int height)
{
    LOGI(("AREngine engineReset w: #" + to_string(width) + " h: #" + to_string(height)).c_str());
    mWidth = width;
    mHeight = height;

    //*******************************************************************************
    //********************************* EGL *****************************************
    //*******************************************************************************
    NReturnObject vSurfaceObject = w->mNWrapper->mNKrossWrapper->mNKrossSystem->tRunObject((NParam)vSurface, -2);
    EGLNativeWindowType vEGLNativeWindow = ANativeWindow_fromSurface(mEnv, vSurfaceObject);
    nuint vState = (vEGLNativeWindow != nullptr);

    if (vState) {
        mEGLSurface = eglCreateWindowSurface(mEGLDisplay, mEGLConfig, vEGLNativeWindow, nullptr);
        vState &= (mEGLSurface != nullptr);
    } else {
        LOGE("Could not get Native Window");
    }
    if (vState) {
        vState = eglMakeCurrent(mEGLDisplay, mEGLSurface, mEGLSurface, mEGLContext);
    } else {
        LOGE("Could not create surface");
    }
    if (vState) {
        LOGI("Current EGL context set");
    } else {
        LOGE("Could not set current context");
    }

    //*******************************************************************************
    //*************************** CAMERA ********************************************
    //*******************************************************************************
    LOGI(("GL Vendor " + to_string(GL_VENDOR)).c_str());
    LOGI(("GL Renderer " + to_string(GL_RENDERER)).c_str());
    LOGI(("GL Extensions " + to_string(GL_EXTENSIONS)).c_str());

    glViewport(0, 0, mWidth, mHeight);

    mhProgramCameraPreview = w->mGraphicsHandler->loadProgramAsset("CameraPreview.vert", "CameraPreview.frag");
    mhVertexPreview = glGetAttribLocation(mhProgramCameraPreview, "mVertexPreview");
    mhCoordPreview = glGetAttribLocation(mhProgramCameraPreview, "mCoordPreview");
    mhSamplerPreview = glGetUniformLocation(mhProgramCameraPreview, "mcSamplerPreview");
    mhTransformation = glGetUniformLocation(mhProgramCameraPreview, "mcTransformation");

    glGenTextures(1, &mhTexturePreview);
    glBindTexture(GL_TEXTURE_EXTERNAL_OES, mhTexturePreview);
    glTexParameteri(GL_TEXTURE_EXTERNAL_OES, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_EXTERNAL_OES, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_EXTERNAL_OES, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_EXTERNAL_OES, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    w->mTexturePreview = new SurfaceTexture(mhTexturePreview);
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
        w->mcCameraHorizontalAngle = vParameters->getHorizontalViewAngle()*w->mcPi/180.0;
        w->mcCameraVerticalAngle = vParameters->getVerticalViewAngle()*w->mcPi/180.0;

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
    nfloat vTanAlphaH = 1/tan(w->mcCameraHorizontalAngle/2);
    mProjection[0] = ( mWidth > mHeight ? vTanAlphaH : vTanAlphaH );
    mProjection[1] = ( mWidth > mHeight ? vTanAlphaH*mWidth/mHeight : vTanAlphaH*mWidth/mHeight );
    mProjection[2] = 1;
    mProjection[3] = 110000;
    mModelIndex = getPreviewRotation(w->mcCameraMountOrientation, w->mcDisplayRotation);

    //*******************************************************************************
    //*************************** POI ***********************************************
    //*******************************************************************************
    glGenBuffers(1, &mhVertexBuffer);
    glGenBuffers(1, &mhIndiceBuffer);

    mhProgramPOI = w->mGraphicsHandler->loadProgramAsset("POI.vert", "POI.frag");
    mhModel = glGetUniformLocation(mhProgramPOI, "mModel");
    mhProjection = glGetUniformLocation(mhProgramPOI, "mProjection");
    mhVertexPOI = glGetAttribLocation(mhProgramPOI, "maVertexPOI");
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
    //*******************************************************************************
    //*************************** CAMERA ********************************************
    //*******************************************************************************
    glClear(GL_COLOR_BUFFER_BIT);

    if (mUpdate) {
        mUpdate = false;
        w->mTexturePreview->updateTexImage();
    }
    glActiveTexture(GL_TEXTURE0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindTexture(GL_TEXTURE_EXTERNAL_OES, mhTexturePreview);
    glEnableVertexAttribArray(mhVertexPreview);
    glEnableVertexAttribArray(mhCoordPreview);
    glUseProgram(mhProgramCameraPreview);

    glUniform1i(mhSamplerPreview, 0);
    glUniform1f(mhTransformation, mModelIndex);
    glVertexAttribPointer(mhVertexPreview, 4, GL_FLOAT, GL_FALSE, 0, maVertexPreview);
    glVertexAttribPointer(mhCoordPreview, 2, GL_FLOAT, GL_FALSE, 0, maCoordPreview);

    glDrawArrays(GL_TRIANGLES, 0, 6);

    //*******************************************************************************
    //*************************** POI ***********************************************
    //*******************************************************************************
    //   Rotation Vector coordinate system
    // X is defined as the vector product Y x Z. It is tangential to the ground at the device's current location and points approximately East.
    // Y is tangential to the ground at the device's current location and points toward the geomagnetic North Pole.
    // Z points toward the sky and is perpendicular to the ground plane.
    // The magnitude of the rotation vector is equal to sin(θ/2)
    //   N-Vector coordinate system
    // x-axis intersects the sphere of the Earth at 0° latitude (Equator) and 0° longitude (Greenwich).
    // Y is the cross-product of x/z
    // z-axis is pointing towards the north
    nuint i = 0;
    nfloat m[3][3];
    nfloat n[3][3];
    GLfloat p[4] = {0, 0, 0, 1};
    GLfloat v[4] = {0, 0, 0, 1};

    glUseProgram(mhProgramPOI);
    glBindBuffer(GL_ARRAY_BUFFER, mhVertexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mhIndiceBuffer);

    glUniform4fv(mhProjection, 1, mProjection);
    glBufferData(GL_ARRAY_BUFFER, maVertexPOI.mcData*sizeof(GLfloat), maVertexPOI.maData, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, maIndicesPOI.mcData*sizeof(GLushort), maIndicesPOI.maData, GL_STATIC_DRAW);

    for (i = 0 ; i < w->maPOICoord.mcData/4; ++i) {
        nfloat* vDeviceCoord = w->maDeviceCoord->maBuffer + w->maDeviceCoord->mWriteIndex;
        v[0] = (w->maPOICoordData[4*i + 0] - vDeviceCoord[0])*6371000;
        v[1] = (w->maPOICoordData[4*i + 1] - vDeviceCoord[1])*6371000;
        v[2] = (w->maPOICoordData[4*i + 2] - vDeviceCoord[2])*6371000;

        if (v[0]*v[0] + v[1]*v[1] + v[2]*v[2] < 100000.0*100000.0) {
            // Matrix for change from n-Vector basis to sensor basis
            nfloat vcLength = sqrt(vDeviceCoord[0]*vDeviceCoord[0] + vDeviceCoord[1]*vDeviceCoord[1]);
            m[0][0] = -vDeviceCoord[1]/vcLength;
            m[0][1] = vDeviceCoord[0]/vcLength;
            m[0][2] = 0;
            m[1][0] = -vDeviceCoord[2]*vDeviceCoord[0]/vcLength;
            m[1][1] = -vDeviceCoord[2]*vDeviceCoord[1]/vcLength;
            m[1][2] = sqrt(1 - vDeviceCoord[2]*vDeviceCoord[2]);
            m[2][0] = sqrt(1 - vDeviceCoord[2]*vDeviceCoord[2])*vDeviceCoord[0]/vcLength;
            m[2][1] = sqrt(1 - vDeviceCoord[2]*vDeviceCoord[2])*vDeviceCoord[1]/vcLength;
            m[2][2] = vDeviceCoord[2];
            matInv(n, m);
            matMult(p, n, v); // POI coordinates in the sensor basis
            quatRot(mModel, p, w->maRotation->maBuffer + w->maRotation->mWriteIndex); // POI coordinates in the device basis

            glUniform4fv(mhModel, 1, mModel);
            glVertexAttribPointer(mhVertexPOI, 4, GL_FLOAT, GL_FALSE, 4*sizeof(GLfloat), (GLvoid*)nullptr);

            glEnableVertexAttribArray(mhVertexPOI);
            glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_SHORT, (GLvoid*)nullptr);
        }
    }
    glFlush();
    eglSwapBuffers(mEGLDisplay, mEGLSurface);
}

void AREngine::engineSleep()
{
    if (w->mCamera) {
        w->mCamera->stopPreview();
    }
    w->mOpUnitEvents->stopEventsProduction();
}

void AREngine::engineStart()
{
    bool vStarted = true;
    mcARState = 2;

    while (vStarted) {
        switch (mcARState) {
        case 0: // destroy
            LOGI("AR Engine state 0 -> 1");
            engineDestroy();
            mcARState = 1;
            this_thread::sleep_for(chrono::milliseconds(40));
            break;
        case 1: // off
            vStarted = false;
            this_thread::sleep_for(chrono::milliseconds(40));
            break;
        case 2: // create
            if (w->mcARState != 2 && w->mcARSurface == 2) {
                LOGI("AR Engine state 2 -> 3");
                engineInit(w->mSurface, w->mSurfaceWidth, w->mSurfaceHeight);
                mcARSurface = w->mcARSurface;
                mcARState = 3;
            }
            if (w->mcARState == 0) {
                LOGI("AR Engine state 2 -> 0");
                mcARState = 0;
            }
            this_thread::sleep_for(chrono::milliseconds(40));
            break;
        case 3: // resume
            LOGI("AR Engine state 3 -> 4");
            engineResume();
            mcARState = 4;

            if (w->mcARState != 3) {
                LOGI("AR Engine state 3 -> 5");
                mcARState = 5;
            }
            this_thread::sleep_for(chrono::milliseconds(40));
            break;
        case 4: // run
            engineRun();

            if (w->mcARState != 3) {
                LOGI("AR Engine state 4 -> 5");
                mcARState = 5;
            }
            break;
        case 5: // pause
            engineSleep();

            if (w->mcARState < 3) {
                LOGI("AR Engine state 5 -> 0");
                mcARState = 0;
            }
            if (w->mcARState == 3) {
                LOGI("AR Engine state 5 -> 3");
                mcARState = 3;
            }
            this_thread::sleep_for(chrono::milliseconds(40));
            break;
        default: // bad state
            LOGE("AR Engine BAD state");
            mcARState = 0;
            this_thread::sleep_for(chrono::milliseconds(40));
            break;
        }
        this_thread::sleep_for(chrono::milliseconds(10));
    }
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

nint AREngine::getPreviewRotation(nint vcCameraMountOrientation, nint vcDisplayRotation)
{
    return (4 + vcCameraMountOrientation - vcDisplayRotation)%4;
}

void AREngine::matMult(nfloat* v, nfloat(*m)[3], nfloat* u)
{
    v[0] = m[0][0]*u[0] + m[1][0]*u[1] + m[2][0]*u[2];
    v[1] = m[0][1]*u[0] + m[1][1]*u[1] + m[2][1]*u[2];
    v[2] = m[0][2]*u[0] + m[1][2]*u[1] + m[2][2]*u[2];
}

nfloat AREngine::matDet(nfloat(*m)[3])
{
    return m[0][0]*matMinor(0, 0, m) - m[1][0]*matMinor(0, 1, m) + m[2][0]*matMinor(0, 2, m);
}

void AREngine::matInv(nfloat(*n)[3], nfloat(*m)[3])
{
    nfloat det = matDet(m);

    n[0][0] =  matMinor(0, 0, m)/det;
    n[0][1] = -matMinor(0, 1, m)/det;
    n[0][2] =  matMinor(0, 2, m)/det;
    n[1][0] = -matMinor(1, 0, m)/det;
    n[1][1] =  matMinor(1, 1, m)/det;
    n[1][2] = -matMinor(1, 2, m)/det;
    n[2][0] =  matMinor(2, 0, m)/det;
    n[2][1] = -matMinor(2, 1, m)/det;
    n[2][2] =  matMinor(2, 2, m)/det;
}

nfloat AREngine::matMinor(nint row, nint column, nfloat(*m)[3])
{
    nint r0 = 0;
    nint r1 = 2;
    nint c0 = 0;
    nint c1 = 2;

    if (row == 0) {
        r0 = 1;
    }
    if (row == 2) {
        r1 = 1;
    }
    if (column == 0) {
        c0 = 1;
    }
    if (column == 2) {
        c1 = 1;
    }
    return m[c0][r0]*m[c1][r1] - m[c1][r0]*m[c0][r1];
}

void AREngine::quatMult(nfloat* q, nfloat* q1, nfloat* q2)
{
    q[0] = q1[3]*q2[0] + q1[0]*q2[3] + q1[1]*q2[2] - q1[2]*q2[1];
    q[1] = q1[3]*q2[1] + q1[1]*q2[3] + q1[2]*q2[0] - q1[0]*q2[2];
    q[2] = q1[3]*q2[2] + q1[2]*q2[3] + q1[0]*q2[1] - q1[1]*q2[0];
    q[3] = q1[3]*q2[3] - q1[0]*q2[0] - q1[1]*q2[1] - q1[2]*q2[2];
}

void AREngine::quatNormalize(nfloat* q)
{
    q[0] /= q[3];
    q[1] /= q[3];
    q[2] /= q[3];
    q[3] = 1.0;
}

void AREngine::quatRot(nfloat* q, nfloat* q1, nfloat* r1)
{
    nfloat t1[4];
    q[0] = -r1[0];
    q[1] = -r1[1];
    q[2] = -r1[2];
    q[3] = r1[3];
    quatMult(t1, q1, q);
    quatMult(q, r1, t1);
}

void AREngine::onFrameAvailable(SurfaceTexture* surfaceTexture)
{
    // This callback is called on an arbitrary thread
    mUpdate = true;
}

} // End namespace
