#ifndef __UUID_H__
#define __UUID_H__

namespace NSDEVICE
{

class UUID : public Object
{
friend NSNATIVE::NKrossFriend;

public:

    static UUID* randomUUID()
    {
        UUID* b = NSNKROSS::w->mNKrossFriend->pointer<UUID>();
        return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorUtil->tRun(NSNKROSS::w->mNBeta00, (NParam)b));
    }

    UUID()
    {
    }

    virtual ~UUID()
    {
    }

    virtual String toString()
    {
        NReturn index = NSNKROSS::w->mNVisitorUtil->tRun(NSNKROSS::w->mNGamma00, (NParam)this);
        return NSNKROSS::w->mNKrossSystem->tGetString(NSNKROSS::w->mNKrossSystem->tRunObject((NParam)index));
    }

private:
    UUID(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
