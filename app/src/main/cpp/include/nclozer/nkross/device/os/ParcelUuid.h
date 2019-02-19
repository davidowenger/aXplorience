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
        NReturn index = NSNKROSS::w->mNVisitorOS->tRun(NSNKROSS::w->mNAlpha00, (NParam)this);
        return NSNKROSS::w->mNKrossSystem->tGetString(NSNKROSS::w->mNKrossSystem->tRunObject((NParam)index));
    }

private:
    ParcelUuid(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
