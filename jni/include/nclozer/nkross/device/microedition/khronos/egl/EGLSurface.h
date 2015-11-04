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
        NSNKROSS::w->mNVisitorMicroedition->tRun(NSNKROSS::w->mNAlpha00, (NParam)this);
    }

private:
    EGLSurface(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
