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

private:
    ContextThemeWrapper(NNoObject* vNNoObject)
        : ContextWrapper(NWrapper::w->mNNoObject->instance<ContextWrapper>())
    {
    }
};

} // End namespace

#endif
