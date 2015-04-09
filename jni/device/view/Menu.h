#ifndef __Menu_H__
#define __Menu_H__

namespace NSDEVICE
{

class Menu
{
friend NSNATIVE::NNoObject;

public:
    static const int CATEGORY_ALTERNATIVE = 0x00040000;
    static const int CATEGORY_CONTAINER = 0x00010000;
    static const int CATEGORY_SECONDARY = 0x00030000;
    static const int CATEGORY_SYSTEM = 0x00020000;
    static const int FIRST = 0x00000001;
    static const int NONE = 0x00000000;

    virtual ~Menu()
    {
        NWrapper::w->nFrame->tRun(NWrapper::w->mNDelta00, (NParam)this);
    }

    virtual MenuItem* add(int groupId, int itemId, int order, const String& title)
    {
        MenuItem* b = NWrapper::w->mNNoObject->pointer<MenuItem>();
        return NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->mNVisitorView->tRun(NWrapper::w->mNGamma00, (NParam)this, (NParam)b, (NParam)groupId<<32|itemId, (NParam)order, NParamBox(NWrapper::w, title).n));
    }

    virtual void removeItem(int id)
    {
        NWrapper::w->mNVisitorView->tRun(NWrapper::w->mNDelta00, (NParam)this, (NParam)id);
    }

private:
    Menu(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif
