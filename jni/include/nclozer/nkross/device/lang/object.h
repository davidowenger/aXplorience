#ifndef __Object_H__
#define __Object_H__

namespace NSDEVICE
{

class Object
{
public:
    Object()
    {
    }

    virtual ~Object()
    {
        NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNDelta00, (NParam)this);
    }
};

} // End namespace

#endif
