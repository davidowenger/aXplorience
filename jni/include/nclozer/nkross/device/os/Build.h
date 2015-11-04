#ifndef __Build_H__
#define __Build_H__

namespace NSDEVICE
{

class Build : public Object
{
friend NSNATIVE::NKrossFriend;

public:
    class VERSION : public Object
    {
    public:
        static int SDK_INT;
    };

private:
    Build(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
