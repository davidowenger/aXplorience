#ifndef __ParcelUuid_H__
#define __ParcelUuid_H__

namespace NSDEVICE
{

class ParcelUuid : public Object
{
friend NSNATIVE::NKrossFriend;

public:
    String toString()
    {
        NReturn index = NKrossWrapper::w->mNVisitorOS->tRun(NKrossWrapper::w->mNAlpha00, (NParam)this);
        return NKrossWrapper::w->mNKrossSystem->tGetString(NKrossWrapper::w->mNKrossSystem->tRunObject((NParam)index));
    }

private:
    ParcelUuid(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
