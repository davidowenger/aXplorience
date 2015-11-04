#ifndef __AREngine_H__
#define __AREngine_H__

namespace NSDEVICE
{

class AREngine : public SurfaceTexture::OnFrameAvailableListener
{
public:
    AREngine(Wrapper* vWrapper);
    virtual ~AREngine();

    void engineCreate();
    void engineDestroy();
    void engineInit(Surface* vSurface, int width, int height);
    void engineResume();
    void engineRun();
    void engineSleep();
    void engineStart();
    bool isSuitedPreviewOrientation(nint vTargetWidth, nint vTargetHeight, nint vSupportedWidth, nint vSupportedHeight);
    nint getPreviewRotation(nint vcCameraMountOrientation, nint vcDisplayRotation);
    nfloat matDet(nfloat(*m)[3]);
    void matInv(nfloat(*n)[3], nfloat(*m)[3]);
    nfloat matMinor(nint row, nint column, nfloat(*m)[3]);
    void matMult(nfloat* v, nfloat(*m)[3], nfloat* u);
    void quatMult(nfloat* q, nfloat* q1, nfloat* q2);
    void quatNormalize(nfloat* q);
    void quatRot(nfloat* t, nfloat* p, nfloat* r);

    // SurfaceTexture::OnFrameAvailableListener
    virtual void onFrameAvailable(SurfaceTexture* surfaceTexture);

    Wrapper* w;
    JNIEnv* mEnv;
    EGLDisplay mEGLDisplay;
    EGLConfig mEGLConfig;
    EGLContext mEGLContext;
    EGLSurface mEGLSurface;
    const GLfloat* maVertexPreview;
    const GLfloat* maCoordPreview;
    GLfloat* mProjection;
    GLfloat* mModel;

    nuint mcARState;
    nuint mcARSurface;
    nint mWidth;
    nint mHeight;
    nfloat mModelIndex;
    float mGrey;
    GLint mhProgramCameraPreview;
    GLint mhProgramOverlayText;
    GLint mhVertexPreview;
    GLint mhCoordPreview;
    GLint mhSamplerPreview;
    GLint mhTransformation;
    GLint mhVertexPOI;
    GLint mhProgramPOI;
    GLint mhModel;
    GLint mhProjection;
    GLuint mhVertexBuffer;
    GLuint mhIndiceBuffer;
    GLuint mhTexturePreview;
    bool mUpdate;

    NArray<GLfloat> maVertexPOI;
    NArray<GLushort> maIndicesPOI;
};

} // End namespace

#endif
