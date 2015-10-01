#ifndef __Build_H__
#define __Build_H__

namespace NSDEVICE
{

class Build : public Object
{
friend NSNATIVE::NNoObject;

public:
    class VERSION : public Object
    {
    public:
        static int SDK_INT;
    };

private:
    Build(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif
