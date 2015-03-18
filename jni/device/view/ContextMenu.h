#ifndef __ContextMenu_H__
#define __ContextMenu_H__

namespace NSDEVICE
{

class ContextMenu : public Menu
{
friend NSNATIVE::NNoObject;

public:
    class ContextMenuInfo
    {
    friend NSNATIVE::NNoObject;

    public:
        virtual ~ContextMenuInfo()
        {
            NWrapper::w->nFrame->tRun(NWrapper::w->mNDelta00, (NParam)this);
        }

    protected:
        ContextMenuInfo(NNoObject* vNNoObject)
        {
        }
    };

	virtual ~ContextMenu()
	{
        NWrapper::w->nFrame->tRun(NWrapper::w->mNDelta00, (NParam)this);
	}

private:
    ContextMenu(NNoObject* vNNoObject)
        : Menu(NWrapper::w->mNNoObject->instance<Menu>())
    {
    }
};

} // End namespace

#endif
