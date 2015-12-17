#ifndef __GraphicsWrapper_H__
#define __GraphicsWrapper_H__

namespace NSNATIVE
{

class GraphicsWrapper
{
public:
    GraphicsHandler* mGraphicsHandler;
    FT_Library mFontLib;
    FT_Face mFontFace;
    FT_GlyphSlot mGlyphSlot;
    nuint mGlyphWidth;
    nuint mGlyphHeight;
};

} // END namespace

#endif
