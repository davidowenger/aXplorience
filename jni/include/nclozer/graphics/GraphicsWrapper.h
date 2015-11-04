#ifndef __GraphicsWrapper_H__
#define __GraphicsWrapper_H__

namespace NSNATIVE
{

class GraphicsWrapper
{
public:
    FT_Library mFontLib;
    FT_Face mFontFace;
    FT_GlyphSlot mGlyphSlot;
};

} // END namespace

#endif
