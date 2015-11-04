#ifndef __ContextWrapper_H__
#define __ContextWrapper_H__

namespace NSDEVICE
{

class ContextWrapper : public Context
{
friend NSNATIVE::NKrossFriend;

public:
    virtual ~ContextWrapper()
    {
    }

    virtual Resources* getResources()
    {
        Resources* b = NSNKROSS::w->mNKrossFriend->pointer<Resources>();
        return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorContent->tRun(NSNKROSS::w->mNBeta00, (NParam)this, (NParam)b));
    }

private:
    ContextWrapper(NKrossFriend* vNKrossFriend)
        : Context(NSNKROSS::w->mNKrossFriend->instance<Context>())
    {
    }
};

} // End namespace

#endif
