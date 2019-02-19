#ifndef __BaseBundle_H__
#define __BaseBundle_H__

namespace NSDEVICE
{

class BaseBundle : public Object
{
friend NSNATIVE::NKrossFriend;

public:
    virtual ~BaseBundle()
    {
    }

private:
    BaseBundle(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
