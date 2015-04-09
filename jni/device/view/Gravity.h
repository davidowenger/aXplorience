#ifndef __Gravity_H__
#define __Gravity_H__

namespace NSDEVICE
{

class Gravity : public Object
{
friend NSNATIVE::NNoObject;

public:
    static const int BOTTOM = 0x00000050;
    static const int CENTER = 0x00000011;
    static const int CENTER_HORIZONTAL = 0x00000001;
    static const int CENTER_VERTICAL = 0x00000010;
    static const int CLIP_HORIZONTAL = 0x00000008;
    static const int CLIP_VERTICAL = 0x00000080;
    static const int DISPLAY_CLIP_HORIZONTAL = 0x01000000;
    static const int DISPLAY_CLIP_VERTICAL = 0x10000000;
    static const int END = 0x00800005;
    static const int FILL = 0x00000077;
    static const int FILL_HORIZONTAL = 0x00000007;
    static const int FILL_VERTICAL = 0x00000070;
    static const int HORIZONTAL_GRAVITY_MASK = 0x00000007;
    static const int LEFT = 0x00000003;
    static const int NO_GRAVITY = 0x00000000;
    static const int RELATIVE_HORIZONTAL_GRAVITY_MASK = 0x00800007;
    static const int RELATIVE_LAYOUT_DIRECTION = 0x00800000;
    static const int RIGHT = 0x00000005;
    static const int START = 0x00800003;
    static const int TOP = 0x00000030;
    static const int VERTICAL_GRAVITY_MASK = 0x00000070;

private:
    Gravity(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif
