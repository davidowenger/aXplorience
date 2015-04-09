#ifndef __ContextWrapper_H__
#define __ContextWrapper_H__

namespace NSDEVICE
{

class ContextWrapper : public Context
{
friend NSNATIVE::NNoObject;

public:
	virtual ~ContextWrapper()
	{
	}

    virtual Resources* getResources()
    {
        Resources* b = NWrapper::w->mNNoObject->pointer<Resources>();
        return NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->mNVisitorContent->tRun(NWrapper::w->mNBeta00, (NParam)this, (NParam)b));
    }

private:
    ContextWrapper(NNoObject* vNNoObject)
        : Context(NWrapper::w->mNNoObject->instance<Context>())
    {
    }
};

} // End namespace

#endif
