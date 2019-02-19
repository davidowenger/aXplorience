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
        NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNDelta00, (NParam)this);
    }

    virtual MenuItem* add(int groupId, int itemId, int order, const String& title)
    {
        MenuItem* b = NSNKROSS::w->mNKrossFriend->pointer<MenuItem>();
        return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorView->tRun(NSNKROSS::w->mNGamma00, (NParam)this, (NParam)b, (NParam)groupId<<32|itemId, (NParam)order, NKrossParam(title).n));
    }

    virtual void removeItem(int id)
    {
        NSNKROSS::w->mNVisitorView->tRun(NSNKROSS::w->mNDelta00, (NParam)this, (NParam)id);
    }

private:
    Menu(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
