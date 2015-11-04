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
        Resources* b = NSNKROSS::w->mNKrossFriend->pointer<Resources>();
        return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorView->tRun(NSNKROSS::w->mNKappa00, (NParam)this, (NParam)b));
    }

private:
    ContextThemeWrapper(NKrossFriend* vNKrossFriend)
        : ContextWrapper(NSNKROSS::w->mNKrossFriend->instance<ContextWrapper>())
    {
    }
};

} // End namespace

#endif
