#ifndef __Surface_H__
#define __Surface_H__

namespace NSDEVICE
{

class Surface : public Object
{
friend NSNATIVE::NKrossFriend;

public:
    static const int ROTATION_0 = 0x00000000;
    static const int ROTATION_180 = 0x00000002;
    static const int ROTATION_270 = 0x00000003;
    static const int ROTATION_90 = 0x00000001;

    virtual ~Surface()
    {
    }

private:
    Surface(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
