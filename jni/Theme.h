#ifndef __Theme_H__
#define __Theme_H__

namespace NSDEVICE
{

class Theme
{
public:
    static const int OPUNIT_TYPE_NONE = 0;

    //TODO: include theme.h where needed only
    static const int kColorApplicationBackground = 3;
    static const int kColorMessageBackground = 2;
    static const int kColorMessageText = 1;
    static const int kColorCategoryBackground = 8;
    static const int kColorTilt0 = 1;
    static const int kColorTilt1 = 8;
    static const int kColorTilt2 = 11;
    static const int kColorTilt3 = 14;
    static const int kColorTilt4 = 17;
    static const int kColorTilt5 = 20;

    //TODO: fix icons for a dark theme
  //static const int kColorApplicationBackground = 1;
  //static const int kColorMessageBackground = 5;
  //static const int kColorMessageText = 2;
  //static const int kColorCategoryBackground = 8;

};

} // End namespace

#endif
