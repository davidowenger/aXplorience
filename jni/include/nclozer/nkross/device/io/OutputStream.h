#ifndef __OutputStream_H__
#define __OutputStream_H__

namespace NSDEVICE
{

class OutputStream : public Object
{
friend NSNATIVE::NKrossFriend;

public:
    virtual ~OutputStream()
    {
    }

    int close()
    {
        return (nint)NKrossWrapper::w->mNVisitorIO->tRun(NKrossWrapper::w->mNAlpha01, (NParam)this);
    }

    int write(const string& packet)
    {
        return (nint)NKrossWrapper::w->mNVisitorIO->tRun(NKrossWrapper::w->mNBeta01, (NParam)this, NKrossParam(packet).n);
    }

private:
    OutputStream(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
