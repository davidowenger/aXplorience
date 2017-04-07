#ifndef __ContextThemeWrapper_H__
#define __ContextThemeWrapper_H__

namespace NSDEVICE
{

class ContextThemeWrapper : public ContextWrapper
{
friend NSNATIVE::NKrossFriend;

public:
    virtual ~ContextThemeWrapper()
    {
    }

    virtual Resources* getResources()
    {
        Resources* b = NKrossWrapper::w->mNKrossFriend->pointer<Resources>();
        return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorView->tRun(NKrossWrapper::w->mNKappa00, (NParam)this, (NParam)b));
    }

private:
    ContextThemeWrapper(NKrossFriend* vNKrossFriend)
        : ContextWrapper(NKrossWrapper::w->mNKrossFriend->instance<ContextWrapper>())
    {
    }
};

} // End namespace

#endif
