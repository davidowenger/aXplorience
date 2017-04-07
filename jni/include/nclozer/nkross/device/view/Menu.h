#ifndef __Menu_H__
#define __Menu_H__

namespace NSDEVICE
{

class Menu
{
friend NSNATIVE::NKrossFriend;

public:
    static const int CATEGORY_ALTERNATIVE = 0x00040000;
    static const int CATEGORY_CONTAINER = 0x00010000;
    static const int CATEGORY_SECONDARY = 0x00030000;
    static const int CATEGORY_SYSTEM = 0x00020000;
    static const int FIRST = 0x00000001;
    static const int NONE = 0x00000000;

    virtual ~Menu()
    {
        NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNDelta00, (NParam)this);
    }

    virtual MenuItem* add(int groupId, int itemId, int order, const String& title)
    {
        MenuItem* b = NKrossWrapper::w->mNKrossFriend->pointer<MenuItem>();
        return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorView->tRun(NKrossWrapper::w->mNGamma00, (NParam)this, (NParam)b, (NParam)groupId<<32|itemId, (NParam)order, NKrossParam(title).n));
    }

    virtual void removeItem(int id)
    {
        NKrossWrapper::w->mNVisitorView->tRun(NKrossWrapper::w->mNDelta00, (NParam)this, (NParam)id);
    }

    virtual void setGroupEnabled(int group, bool enabled)
    {
        NKrossWrapper::w->mNVisitorView->tRun(NKrossWrapper::w->mNDelta01, (NParam)this, (NParam)group, (NParam)enabled);
    }

    virtual void setGroupVisible(int group, bool visible)
    {
        NKrossWrapper::w->mNVisitorView->tRun(NKrossWrapper::w->mNEpsilon01, (NParam)this, (NParam)group, (NParam)visible);
    }

private:
    Menu(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
