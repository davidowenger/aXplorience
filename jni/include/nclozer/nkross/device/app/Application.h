#ifndef __Application_H__
#define __Application_H__

namespace NSDEVICE
{

class Application : public ContextWrapper
{
friend NSNATIVE::NKrossFriend;

public:
    virtual ~Application()
    {
    }

private:
    Application(NKrossFriend* vNKrossFriend)
        : ContextWrapper(NSNKROSS::w->mNKrossFriend->instance<ContextWrapper>())
    {
    }
};

} // End namespace

#endif
