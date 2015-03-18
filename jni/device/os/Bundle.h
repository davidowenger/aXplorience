#ifndef __Bundle_H__
#define __Bundle_H__

namespace NSDEVICE
{

class Bundle : public BaseBundle
{
friend NSNATIVE::NNoObject;

public:
	Bundle()
        : BaseBundle(NWrapper::w->mNNoObject->instance<BaseBundle>())
	{
	}

	virtual ~Bundle()
	{
	}

protected:
    Bundle(NNoObject* vNNoObject)
        : BaseBundle(NWrapper::w->mNNoObject->instance<BaseBundle>())
    {
    }
};

} // End namespace

#endif
