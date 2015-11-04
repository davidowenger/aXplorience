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
        NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNDelta00, (NParam)this);
    }
};

} // End namespace

#endif
