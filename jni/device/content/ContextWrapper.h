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

private:
    ContextWrapper(NNoObject* vNNoObject)
        : Context(NWrapper::w->mNNoObject->instance<Context>())
    {
    }
};

} // End namespace

#endif
