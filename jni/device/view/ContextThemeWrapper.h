#ifndef __ContextThemeWrapper_H__
#define __ContextThemeWrapper_H__

namespace NSDEVICE
{

class ContextThemeWrapper : public ContextWrapper
{
friend NSNATIVE::NNoObject;

public:
	virtual ~ContextThemeWrapper()
	{
	}

    virtual Resources* getResources()
    {
        Resources* b = NWrapper::w->mNNoObject->pointer<Resources>();
        return NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->mNVisitorView->tRun(NWrapper::w->mNKappa00, (NParam)this, (NParam)b));
    }

private:
    ContextThemeWrapper(NNoObject* vNNoObject)
        : ContextWrapper(NWrapper::w->mNNoObject->instance<ContextWrapper>())
    {
    }
};

} // End namespace

#endif
