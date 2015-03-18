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
        NWrapper::w->nFrame->tRun(NWrapper::w->mNDelta00, (NParam)this);
    }
};

} // End namespace

#endif
