#include "GraphicsCommon.h"

namespace NSNATIVE
{

GraphicsBuffer::GraphicsBuffer(NArray<nfloat> vDataArray, nuint vRowSize, NArray<nushort> vIndiceArray)
    : mRowSize(vRowSize), mDataArray(vDataArray), mIndiceArray(vIndiceArray)
{
    // TODO: enable multiple buffers
    glGenBuffers(1, &mDataID);
    glGenBuffers(1, &mIndiceID);
    use();
    glBufferData(GL_ARRAY_BUFFER, mDataArray.mcData*sizeof(GLfloat), mDataArray.maData, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, mIndiceArray.mcData*sizeof(GLushort), mIndiceArray.maData, GL_STATIC_DRAW);
}

GraphicsBuffer::~GraphicsBuffer()
{
}

void GraphicsBuffer::use()
{
    glBindBuffer(GL_ARRAY_BUFFER, mDataID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIndiceID);
}

GraphicsTexture::GraphicsTexture(nuint vTextureUnit, nuint vTarget, nint vFormat, nint vType, nint vWrapX, nint vWrapY, nint vMinFilter, nint vMagFilter)
    : mID(0), mTextureUnit(vTextureUnit), mTarget(vTarget), mFormat(vFormat), mType(vType), mWrapX(vWrapX), mWrapY(vWrapY), mMinFilter(vMinFilter), mMagFilter(vMagFilter)
{
    glGenTextures(1, &mID);
    use();
    glTexParameteri(mTarget, GL_TEXTURE_WRAP_S, mWrapX);
    glTexParameteri(mTarget, GL_TEXTURE_WRAP_T, mWrapY);
    glTexParameteri(mTarget, GL_TEXTURE_MIN_FILTER, mMinFilter);
    glTexParameteri(mTarget, GL_TEXTURE_MAG_FILTER, mMagFilter);
}

GraphicsTexture::~GraphicsTexture()
{
}

void GraphicsTexture::setBitmap(nubyte* vaPixel, nuint vWidth, nuint vHeight)
{
    glActiveTexture(kTextureUnitBase + mTextureUnit);
    glBindTexture(mTarget, mID);
    glTexImage2D(mTarget, 0, mFormat, vWidth, vHeight, 0, mFormat, mType, vaPixel);
}

void GraphicsTexture::use()
{
    glActiveTexture(kTextureUnitBase + mTextureUnit);
    glBindTexture(mTarget, mID);
}

GraphicsHandler::GraphicsHandler(NWrapper* vNWrapper) :
    mTextureUnitCount(0), mFirstIndice(0), mWidth(0), mHeight(0),
    mNWrapper(vNWrapper), mEGLDisplay(nullptr), mEGLConfig(nullptr), mEGLContext(nullptr), mEGLSurface(nullptr)
{
    mNWrapper->mGraphicsWrapper->mGraphicsHandler = this;
}

GraphicsHandler::~GraphicsHandler()
{
}

nint GraphicsHandler::createDisplayConfig()
{
    //*******************************************************************************
    //********************************* EGL CONFIG **********************************
    //*******************************************************************************
#ifdef EGL_VERSION_1_3
    LOGI("EGL Version 1.3");

    nuint vState = 0;
    EGLint vSize = 0;
    NArray<EGLint> vaConfigAttrib({
        EGL_DEPTH_SIZE, 24,
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
        EGL_NONE
    });
    NArray<EGLint> vaContextAttrib({
         EGL_CONTEXT_CLIENT_VERSION, 2,
         EGL_NONE
    });
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
    return 0;
}

nint GraphicsHandler::createDisplaySurface(EGLNativeWindowType vEGLNativeWindow)
{
    //*******************************************************************************
    //******************************* EGL Surface ***********************************
    //*******************************************************************************
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
    return !vState;
}

nint GraphicsHandler::enableRendering3D(nint vWidth, nint vHeight, bool vDepthTest, bool vCullFace)
{
    //*******************************************************************************
    //********************************* OPEN GL *************************************
    //*******************************************************************************
    LOGI(("GL Vendor " + to_string(GL_VENDOR)).c_str());
    LOGI(("GL Renderer " + to_string(GL_RENDERER)).c_str());
    LOGI(("GL Extensions " + to_string(GL_EXTENSIONS)).c_str());
    mWidth = vWidth;
    mHeight = vHeight;
    mTextureUnitCount = 0;
    mFirstIndice = 0;

    if (vDepthTest) {
        glEnable(GL_DEPTH_TEST);
    }
    if (vCullFace) {
        glEnable(GL_CULL_FACE);
    }
    glViewport(0, 0, vWidth, vHeight);

    return 0;
}

nint GraphicsHandler::enableRenderingFont(nuint vFontSize)
{
    //*******************************************************************************
    //********************************* FreeType ************************************
    //*******************************************************************************
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    nint vError = FT_Init_FreeType(&mNWrapper->mGraphicsWrapper->mFontLib);

    if (vError) {
        SLOGE("Could not init freetype library : #" + to_string(vError));
    }
    if (!vError) {
        vError = FT_New_Face(mNWrapper->mGraphicsWrapper->mFontLib, (mNWrapper->mFileDir + "FreeSans.ttf").c_str(), 0, &mNWrapper->mGraphicsWrapper->mFontFace);
    }
    if (vError) {
        vError = writeFile("FreeSans.ttf", loadAsset("FreeSans.ttf"));

        if (vError) {
            SLOGE("Could not extract font : #" + to_string(vError));
        }
        if (!vError) {
            vError = FT_New_Face(mNWrapper->mGraphicsWrapper->mFontLib, (mNWrapper->mFileDir + "FreeSans.ttf").c_str(), 0, &mNWrapper->mGraphicsWrapper->mFontFace);
        }
        if (vError) {
            SLOGE("Could not load font : #" + to_string(vError));
        }
    }
    if (!vError) {
        vError = FT_Set_Pixel_Sizes(mNWrapper->mGraphicsWrapper->mFontFace, 0, vFontSize);
    }
    if (vError) {
        SLOGE("Could not set font size : #" + to_string(vError));
    }
    if (!vError) {
        vError = FT_Load_Char(mNWrapper->mGraphicsWrapper->mFontFace, 'X', FT_LOAD_RENDER);
    }
    if (vError) {
        SLOGE("Could not load character : #" + to_string(vError));
    }
    if (!vError) {
        mNWrapper->mGraphicsWrapper->mGlyphSlot = mNWrapper->mGraphicsWrapper->mFontFace->glyph;
        mNWrapper->mGraphicsWrapper->mGlyphWidth = mNWrapper->mGraphicsWrapper->mGlyphSlot->bitmap.width;
        mNWrapper->mGraphicsWrapper->mGlyphHeight = mNWrapper->mGraphicsWrapper->mGlyphSlot->bitmap.rows;
    }
    return vError;
}

void GraphicsHandler::endRendering3D()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glUseProgram(0);
}

GraphicsBuffer* GraphicsHandler::factoryBuffer(NArray<nfloat> vDataArray, nuint vRowSize, NArray<nushort> vIndiceArray)
{
    return new GraphicsBuffer(vDataArray, vRowSize, vIndiceArray);
}

GraphicsProgram* GraphicsHandler::factoryProgram(NArray<String> vaShader, nuint vIndiceCount)
{
    GraphicsProgram* vGraphicsProgram = new GraphicsProgram(mNWrapper, vaShader, vIndiceCount, mFirstIndice);
    mFirstIndice += vIndiceCount;
    return vGraphicsProgram;
}

GraphicsTexture* GraphicsHandler::factoryTexture(nuint vTarget, nint vFormat, nint vType, nint vWrapX, nint vWrapY, nint vMinFilter, nint vMagFilter)
{
    return new GraphicsTexture(mTextureUnitCount++, vTarget, vFormat, vType, vWrapX, vWrapY, vMinFilter, vMagFilter);
}

void GraphicsHandler::flush()
{
    glFlush();
    eglSwapBuffers(mEGLDisplay, mEGLSurface);
}

NArray<nbyte> GraphicsHandler::loadAsset(const String& vFilePath)
{
    nint vState = -1;
    const void* vBuffer = nullptr;
    AAsset* vAAsset = AAssetManager_open(mNWrapper->mAAssetManager, (mNWrapper->mAssetDir + vFilePath).c_str(), AASSET_MODE_BUFFER);
    NArray<nbyte> vFile;

    if (!vAAsset) {
        LOGE(("Error accessing asset : #" + mNWrapper->mAssetDir + vFilePath).c_str());
    }
    if (vAAsset) {
        vState = AAsset_getLength(vAAsset);
    }
    if (vAAsset && vState == 0) {
        LOGE(("Asset not found or empty : #" + mNWrapper->mAssetDir + vFilePath).c_str());
    }
    if (vState > 0) {
        vBuffer = AAsset_getBuffer(vAAsset);
    }
    if (!vBuffer && vState > 0) {
        LOGE(("Error reading asset : #" + mNWrapper->mAssetDir + vFilePath).c_str());
    }
    if (vBuffer) {
        vFile.mcData = vState;
        vFile.maData = new nbyte[vFile.mcData + 1];
        vFile.maData[vFile.mcData] = 0;
        memcpy(vFile.maData, vBuffer, vFile.mcData);
    }
    if (vAAsset) {
        AAsset_close(vAAsset);
    }
    return vFile;
}


NArray<nbyte> GraphicsHandler::loadFile(const String& vFilePath)
{
    nint vState = -3;
    NArray<nbyte> vFile;
    fstream vFileStream;

    vFileStream.open(mNWrapper->mFileDir + vFilePath, ios_base::binary | ios_base::out | ios_base::app );

    if (!vFileStream.good()) {
        LOGE(("Error accessing file : #" + mNWrapper->mFileDir + vFilePath).c_str());
    }
    if (vFileStream.good()) {
        vFileStream.close();
        vFileStream.open(mNWrapper->mFileDir + vFilePath, ios_base::binary| ios_base::in );
        vState = -2;
    }
    if (!vFileStream.good() && vState == -2) {
        LOGE(("Error reading file data : #" + mNWrapper->mFileDir + vFilePath).c_str());
    }
    if (vFileStream.good()) {
        vFileStream.seekg(0, ios::end);
        vState = vFileStream.tellg();
        vFileStream.seekg(0, ios::beg);
    }
    if (vFileStream.good() && vState == -1) {
        LOGE(("Error reading file size : #" + mNWrapper->mFileDir + vFilePath).c_str());
    }
    if (vFileStream.good() && vState == 0) {
        LOGE(("File not found or empty : #" + mNWrapper->mFileDir + vFilePath).c_str());
    }
    if (vState > 0) {
        vFile.mcData = vState;
        vFile.maData = new nbyte[vFile.mcData + 1];
        vFileStream.read(vFile.maData, vFile.mcData);
    }
    vFileStream.clear();
    vFileStream.close();
    return vFile;
}

GLuint GraphicsHandler::loadProgramAsset(const String& vVertexFile, const String& vFragmentFile)
{
    GLuint vhProgram = 0;
    NArray<nbyte> vVertexText = loadAsset(vVertexFile);
    NArray<nbyte> vFragmentText = loadAsset(vFragmentFile);

    if (vVertexText.maData && vFragmentText.maData) {
        vhProgram = loadProgramText(vVertexText.maData, vFragmentText.maData);
    }
    return vhProgram;
}

GLuint GraphicsHandler::loadProgramText(const char* vVertexText, const char* vFragmentText)
{
    char* vsMessage = nullptr;
    GLint vcMessage = 0;
    GLint vcStatus = 0;
    GLuint vhProgram = 0;
    GLuint vhVertex = loadShaderText(GL_VERTEX_SHADER, vVertexText);
    GLuint vhFragement = loadShaderText(GL_FRAGMENT_SHADER, vFragmentText);

    if (vhVertex && vhFragement) {
        vhProgram = glCreateProgram();
    }
    if (vhProgram) {
        glAttachShader(vhProgram, vhVertex);
        glAttachShader(vhProgram, vhFragement);
        glLinkProgram(vhProgram);
        glGetProgramiv(vhProgram, GL_LINK_STATUS, &vcStatus);
    }
    if (!vcStatus) {
        LOGE(("Program not created - program: #" + to_string(vhProgram) + " vertex: #" + to_string(vhVertex) + " fragment: #" + to_string(vhFragement)).c_str());
        glGetProgramiv(vhProgram, GL_INFO_LOG_LENGTH, &vcMessage);
    }
    if (vcMessage) {
        vsMessage = (char*)malloc(vcMessage);
        glGetProgramInfoLog(vhProgram, vcMessage, NULL, vsMessage);
        LOGE(vsMessage);
        free(vsMessage);
    }
    if (!vcStatus && vhProgram) {
        glDeleteProgram(vhProgram);
        vhProgram = 0;
    }
    return vhProgram;
}

GLuint GraphicsHandler::loadShaderText(GLenum vcType, const char* vsSource)
{
    char* vsMessage = nullptr;
    GLint vcMessage = 0;
    GLint vcStatus = 0;
    GLuint vhShader = glCreateShader(vcType);

    if (vhShader) {
        glShaderSource(vhShader, 1, &vsSource, NULL);
        glCompileShader(vhShader);
        glGetShaderiv(vhShader, GL_COMPILE_STATUS, &vcStatus);
    }
    if (!vcStatus) {
        LOGE("Could not compile shader");
        glGetShaderiv(vhShader, GL_INFO_LOG_LENGTH, &vcMessage);
    }
    if (vcMessage) {
        vsMessage = (char*)malloc(vcMessage);
        glGetShaderInfoLog(vhShader, vcMessage, NULL, vsMessage);
        LOGE(vsMessage);
        free(vsMessage);
    }
    if (!vcStatus && vhShader) {
        glDeleteShader(vhShader);
        vhShader = 0;
    }
    return vhShader;
}

nint GraphicsHandler::renderFontLine(const String& vLabel, GraphicsProgram* vProgram, GraphicsParam* vPosition, GraphicsParam* vBox, GraphicsParam* vTextureUnit)
{
    const nbyte* vChar;
    nint vError = 0;
    GraphicsTexture* vTexture = ((GraphicsParamTex*)vTextureUnit)->mGraphicsTexture;
    nfloat vCoord[2] {vPosition->mNVec[0], vPosition->mNVec[1]};

    for (vChar = vLabel.c_str() ; *vChar ; ++vChar) {
        vError = FT_Load_Char(mNWrapper->mGraphicsWrapper->mFontFace, *vChar, FT_LOAD_RENDER);

        if (!vError) {
            vTexture->setBitmap(
                mNWrapper->mGraphicsWrapper->mGlyphSlot->bitmap.buffer,
                mNWrapper->mGraphicsWrapper->mGlyphSlot->bitmap.width,
                mNWrapper->mGraphicsWrapper->mGlyphSlot->bitmap.rows
            );
            vBox->is(
                (nfloat)mNWrapper->mGraphicsWrapper->mGlyphSlot->bitmap_left/mWidth,
                (nfloat)mNWrapper->mGraphicsWrapper->mGlyphSlot->bitmap_top/mHeight,
                (nfloat)mNWrapper->mGraphicsWrapper->mGlyphSlot->bitmap.width/mWidth,
                (nfloat)mNWrapper->mGraphicsWrapper->mGlyphSlot->bitmap.rows/mHeight
            );
            vProgram->draw();
            vPosition->is(
                vCoord[0] += (nfloat)(mNWrapper->mGraphicsWrapper->mGlyphSlot->advance.x >> 6)/mWidth,
                vCoord[1] += (nfloat)(mNWrapper->mGraphicsWrapper->mGlyphSlot->advance.y >> 6)/mHeight
            );
        } else {
            LOGE("Unknown char :" + *vChar);
        }
    }
    return vError;
}

nint GraphicsHandler::writeFile(const String& vFilePath, NArray<nbyte> vFile)
{
    fstream vFileStream;

    vFileStream.open(mNWrapper->mFileDir + vFilePath, ios_base::binary | ios_base::out );

    if (!vFileStream.good()) {
        LOGE(("Error accessing file : #" + mNWrapper->mFileDir + vFilePath).c_str());
    }
    if (vFileStream.good()) {
        vFileStream.write(vFile.maData, vFile.mcData);
    }
    return !vFileStream.good();
}

nint GraphicsHandler::setFontSize(nuint vFontSize)
{
    FT_Error vError = FT_Set_Pixel_Sizes(mNWrapper->mGraphicsWrapper->mFontFace, 0, vFontSize);

    if (vError) {
        LOGE(("Could not set font size : #" + to_string(vError)).c_str());
    }
    if (!vError) {
        vError = FT_Load_Char(mNWrapper->mGraphicsWrapper->mFontFace, 'X', FT_LOAD_RENDER);
    }
    if (vError) {
        LOGE(("Could not load character : #" + to_string(vError)).c_str());
    }
    if (!vError) {
        mNWrapper->mGraphicsWrapper->mGlyphWidth = mNWrapper->mGraphicsWrapper->mGlyphSlot->bitmap.width;
        mNWrapper->mGraphicsWrapper->mGlyphHeight = mNWrapper->mGraphicsWrapper->mGlyphSlot->bitmap.rows;
    }
    return vError;
}

} // End namespace
