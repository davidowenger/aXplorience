#ifndef __MenuItem_H__
#define __MenuItem_H__

namespace NSDEVICE
{

class MenuItem
{
friend NSNATIVE::NNoObject;

public:
    static const int SHOW_AS_ACTION_NEVER = 0;
    static const int SHOW_AS_ACTION_IF_ROOM = 1;
    static const int SHOW_AS_ACTION_ALWAYS = 2;
    static const int SHOW_AS_ACTION_WITH_TEXT = 4;
    static const int SHOW_AS_ACTION_COLLAPSE_ACTION_VIEW = 8;

	virtual ~MenuItem()
	{
        NWrapper::w->nFrame->tRun(NWrapper::w->mNDelta00, (NParam)this);
	}

    virtual int getItemId()
    {
        return NWrapper::w->mNVisitorView->tRun(NWrapper::w->mNEpsilon00, (NParam)this);
    }

    virtual MenuItem* setIcon(Drawable* icon)
    {
        NWrapper::w->mNVisitorView->tRun(NWrapper::w->mNDzeta00, (NParam)this, (NParam)icon);
        return this;
    }

    virtual MenuItem* setShowAsAction(int actionEnum)
    {
        NWrapper::w->mNVisitorView->tRun(NWrapper::w->mNEta00, (NParam)this, (NParam)actionEnum);
        return this;
    }

private:
    MenuItem(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif
