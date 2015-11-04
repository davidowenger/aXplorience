#ifndef __GraphicsHandler_H__
#define __GraphicsHandler_H__

namespace NSNATIVE
{

class GraphicsHandler
{
public:
    GraphicsHandler(NWrapper* vWrapper);
   ~GraphicsHandler();

    nint initFontRendering();
    GLuint loadProgramAsset(const String& vVertexFile, const String& vFragmentFile);
    GLuint loadProgramText(const char* vVertexText, const char* vFragmentText);
    GLuint loadShaderText(GLenum vcType, const char* vShaderText);
    NArray<nbyte> loadAsset(const String& vFilePath);
    NArray<nbyte> loadFile(const String& vFilePath);
    nint renderFontLine(const char *text, float x, float y, float sx, float sy);
    nint writeFile(const String& vFilePath, NArray<nbyte> vFile);

    NWrapper* mNWrapper;
};

} // End namespace

#endif
