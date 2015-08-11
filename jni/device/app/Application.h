#ifndef __Application_H__
#define __Application_H__

namespace NSDEVICE
{

class Application : public ContextWrapper
{
friend NSNATIVE::NNoObject;

public:
    virtual ~Application()
    {
    }

private:
    Application(NNoObject* vNNoObject)
        : ContextWrapper(NWrapper::w->mNNoObject->instance<ContextWrapper>())
    {
    }
};

} // End namespace

#endif
