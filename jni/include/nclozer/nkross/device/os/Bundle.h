#ifndef __Bundle_H__
#define __Bundle_H__

namespace NSDEVICE
{

class Bundle : public BaseBundle
{
friend NSNATIVE::NKrossFriend;

public:
    Bundle()
        : BaseBundle(NKrossWrapper::w->mNKrossFriend->instance<BaseBundle>())
    {
    }

    virtual ~Bundle()
    {
    }

protected:
    Bundle(NKrossFriend* vNKrossFriend)
        : BaseBundle(NKrossWrapper::w->mNKrossFriend->instance<BaseBundle>())
    {
    }
};

} // End namespace

#endif
