#ifndef __R_H__
#define __R_H__

namespace NSDEVICE
{

class R : public Object
{
public:
    class attr : public Object
    {
    public:
        static const int state_checked = 0x010100a0;
        static const int state_enabled = 0x0101009e;
    };

    class id : public Object
    {
    public:
        static const int home = 0x0102002c;
    };
};

} // End namespace

#endif
