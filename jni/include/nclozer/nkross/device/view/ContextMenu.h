#ifndef __ContextMenu_H__
#define __ContextMenu_H__

namespace NSDEVICE
{

class ContextMenu : public Menu
{
friend NSNATIVE::NKrossFriend;

public:
    class ContextMenuInfo
    {
    friend NSNATIVE::NKrossFriend;

    public:
        virtual ~ContextMenuInfo()
        {
            NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNDelta00, (NParam)this);
        }

    protected:
        ContextMenuInfo(NKrossFriend* vNKrossFriend)
        {
        }
    };

    virtual ~ContextMenu()
    {
        NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNDelta00, (NParam)this);
    }

private:
    ContextMenu(NKrossFriend* vNKrossFriend)
        : Menu(NSNKROSS::w->mNKrossFriend->instance<Menu>())
    {
    }
};

} // End namespace

#endif
