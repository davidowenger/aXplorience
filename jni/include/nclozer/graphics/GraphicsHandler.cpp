#include "GraphicsCommon.h"

namespace NSNATIVE
{

GraphicsHandler::GraphicsHandler(NWrapper* vNWrapper)
    : mNWrapper(vNWrapper)
{
}

GraphicsHandler::~GraphicsHandler()
{
}

nint GraphicsHandler::initFontRendering()
{
    FT_Error vError = 0;

    vError = FT_Init_FreeType(&mNWrapper->mGraphicsWrapper->mFontLib);

    if (vError) {
        LOGE(("Could not init freetype library : #" + to_string(vError)).c_str());
    }
    if (!vError) {
        vError = FT_New_Face(mNWrapper->mGraphicsWrapper->mFontLib, (mNWrapper->mFileDir + "FreeSans.ttf").c_str(), 0, &mNWrapper->mGraphicsWrapper->mFontFace);
    }
    if (vError) {
        vError = writeFile("FreeSans.ttf", loadAsset("FreeSans.ttf"));

        if (vError) {
            LOGE(("Could not extract font : #" + to_string(vError)).c_str());
        }
        if (!vError) {
            vError = FT_New_Face(mNWrapper->mGraphicsWrapper->mFontLib, (mNWrapper->mFileDir + "FreeSans.ttf").c_str(), 0, &mNWrapper->mGraphicsWrapper->mFontFace);
        }
        if (vError) {
            LOGE(("Could not load font : #" + to_string(vError)).c_str());
        }
    }
    if (!vError) {
        FT_Set_Pixel_Sizes(mNWrapper->mGraphicsWrapper->mFontFace, 0, 48);
        vError = FT_Load_Char(mNWrapper->mGraphicsWrapper->mFontFace, 'X', FT_LOAD_RENDER);
    }
    if (vError) {
        LOGE(("Could not load character : #" + to_string(vError)).c_str());
    }
    if (!vError) {
        mNWrapper->mGraphicsWrapper->mGlyphSlot = mNWrapper->mGraphicsWrapper->mFontFace->glyph;
    }
    return vError;
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

nint GraphicsHandler::renderFontLine(const char *text, float x, float y, float sx, float sy)
{
    const char *p;

    for (p = text; *p; p++) {
        if (FT_Load_Char(mNWrapper->mGraphicsWrapper->mFontFace, *p, FT_LOAD_RENDER))
            continue;

        glTexImage2D(
            GL_TEXTURE_2D,
            0,
            GL_ALPHA,
            mNWrapper->mGraphicsWrapper->mGlyphSlot->bitmap.width,
            mNWrapper->mGraphicsWrapper->mGlyphSlot->bitmap.rows,
            0,
            GL_ALPHA,
            GL_UNSIGNED_BYTE,
            mNWrapper->mGraphicsWrapper->mGlyphSlot->bitmap.buffer
        );

        float x2 = x + mNWrapper->mGraphicsWrapper->mGlyphSlot->bitmap_left * sx;
        float y2 = -y - mNWrapper->mGraphicsWrapper->mGlyphSlot->bitmap_top * sy;
        float w = mNWrapper->mGraphicsWrapper->mGlyphSlot->bitmap.width * sx;
        float h = mNWrapper->mGraphicsWrapper->mGlyphSlot->bitmap.rows * sy;

        GLfloat box[4][4] = {
            {x2,     -y2    , 0, 0},
            {x2 + w, -y2    , 1, 0},
            {x2,     -y2 - h, 0, 1},
            {x2 + w, -y2 - h, 1, 1},
        };

        glBufferData(GL_ARRAY_BUFFER, sizeof box, box, GL_DYNAMIC_DRAW);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

        x += (mNWrapper->mGraphicsWrapper->mGlyphSlot->advance.x >> 6) * sx;
        y += (mNWrapper->mGraphicsWrapper->mGlyphSlot->advance.y >> 6) * sy;
    }
    return 0;
}

} // End namespace
