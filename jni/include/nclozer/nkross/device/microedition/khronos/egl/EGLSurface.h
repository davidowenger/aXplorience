#ifndef __EGLSurface_H__
#define __EGLSurface_H__

namespace NSDEVICE
{

class EGLSurface : public Object
{
friend NSNATIVE::NKrossFriend;

public:
    virtual ~EGLSurface()
    {
    }

protected:
    EGLSurface()
    {
        NKrossWrapper::w->mNVisitorMicroedition->tRun(NKrossWrapper::w->mNAlpha00, (NParam)this);
    }

private:
    EGLSurface(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
