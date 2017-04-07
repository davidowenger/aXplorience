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
        Resources* b = NKrossWrapper::w->mNKrossFriend->pointer<Resources>();
        return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorContent->tRun(NKrossWrapper::w->mNBeta00, (NParam)this, (NParam)b));
    }

private:
    ContextWrapper(NKrossFriend* vNKrossFriend)
        : Context(NKrossWrapper::w->mNKrossFriend->instance<Context>())
    {
    }
};

} // End namespace

#endif
