#ifndef __MenuItem_H__
#define __MenuItem_H__

namespace NSDEVICE
{

class MenuItem
{
friend NSNATIVE::NKrossFriend;

public:
    static const int SHOW_AS_ACTION_NEVER = 0;
    static const int SHOW_AS_ACTION_IF_ROOM = 1;
    static const int SHOW_AS_ACTION_ALWAYS = 2;
    static const int SHOW_AS_ACTION_WITH_TEXT = 4;
    static const int SHOW_AS_ACTION_COLLAPSE_ACTION_VIEW = 8;

    virtual ~MenuItem()
    {
        NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNDelta00, (NParam)this);
    }

    virtual int getItemId()
    {
        return (nint)NSNKROSS::w->mNVisitorView->tRun(NSNKROSS::w->mNEpsilon00, (NParam)this);
    }

    virtual MenuItem* setIcon(Drawable* icon)
    {
        NSNKROSS::w->mNVisitorView->tRun(NSNKROSS::w->mNDzeta00, (NParam)this, (NParam)icon);
        return this;
    }

    virtual MenuItem* setShowAsAction(int actionEnum)
    {
        NSNKROSS::w->mNVisitorView->tRun(NSNKROSS::w->mNEta00, (NParam)this, (NParam)actionEnum);
        return this;
    }

private:
    MenuItem(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
