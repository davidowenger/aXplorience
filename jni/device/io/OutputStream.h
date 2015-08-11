#ifndef __OutputStream_H__
#define __OutputStream_H__

namespace NSDEVICE
{

class OutputStream : public Object
{
friend NSNATIVE::NNoObject;

public:
    virtual ~OutputStream()
    {
    }

    int close()
    {
        return (nint)NWrapper::w->mNVisitorIO->tRun(NWrapper::w->mNAlpha01, (NParam)this);
    }

    int write(const string& packet)
    {
        return (nint)NWrapper::w->mNVisitorIO->tRun(NWrapper::w->mNBeta01, (NParam)this, NParamBox(NWrapper::w, packet).n);
    }

private:
    OutputStream(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif
