#ifndef __GraphicsHandler_H__
#define __GraphicsHandler_H__

namespace NSNATIVE
{

class GraphicsProgram;
class GraphicsParam;

class GraphicsBuffer
{
public:
    GraphicsBuffer(NArray<nfloat> vDataArray, nuint vDataSize, NArray<nushort> vIndiceArray);
   ~GraphicsBuffer();

    void use();

    nuint mDataID;
    nuint mIndiceID;
    nuint mRowSize;
    NArray<nfloat> mDataArray;
    NArray<nushort> mIndiceArray;
};

class GraphicsTexture
{
public:
    static const nuint kTextureUnitBase = GL_TEXTURE0;

    GraphicsTexture(nuint vTextureUnit, nuint vTarget, nint vFormat, nint vType, nint vWrapX, nint vWrapY, nint vMinFilter, nint vMagFilter);
   ~GraphicsTexture();

    void setBitmap(nubyte* vaPixel, nuint vWidth, nuint vHeight);
    void use();

    nuint mID;
    nuint mTextureUnit;
    nuint mTarget;
    nint mFormat;
    nint mType;
    nint mWrapX;
    nint mWrapY;
    nint mMinFilter;
    nint mMagFilter;
    NArray<nbyte> mPixArray;
};

class GraphicsHandler
{
public:
    GraphicsHandler(NWrapper* vWrapper);
   ~GraphicsHandler();

    nint createDisplayConfig();
    nint createDisplaySurface(EGLNativeWindowType vEGLNativeWindow);
    nint enableRendering3D(nint vWidth, nint vHeight, bool vDepthTest, bool vCullFace);
    nint enableRenderingFont(nuint vFontSize);
    void endRendering3D();
    GraphicsBuffer* factoryBuffer(NArray<nfloat> vDataArray, nuint vDataSize, NArray<nushort> vIndiceArray);
    GraphicsProgram* factoryProgram(NArray<String> vaShader, nuint vIndiceCount);
    GraphicsTexture* factoryTexture(nuint vTarget, nint vFormat, nint vType, nint vWrapX, nint vWrapY, nint vMinFilter, nint vMagFilter);
    void flush();
    NArray<nbyte> loadAsset(const String& vFilePath);
    NArray<nbyte> loadFile(const String& vFilePath);
    GLuint loadProgramAsset(const String& vVertexFile, const String& vFragmentFile);
    GLuint loadProgramText(const char* vVertexText, const char* vFragmentText);
    GLuint loadShaderText(GLenum vcType, const char* vShaderText);
    nint renderFontLine(const String& vLabel, GraphicsProgram* vProgram, GraphicsParam* vPosition, GraphicsParam* vBox, GraphicsParam* vTextureUnit);
    nint setFontSize(nuint vFontSize);
    nint writeFile(const String& vFilePath, NArray<nbyte> vFile);

    nuint mTextureUnitCount;
    nuint mFirstIndice;
    nint mWidth;
    nint mHeight;

    NWrapper* mNWrapper;
    EGLDisplay mEGLDisplay;
    EGLConfig mEGLConfig;
    EGLContext mEGLContext;
    EGLSurface mEGLSurface;
};

} // End namespace

#endif
