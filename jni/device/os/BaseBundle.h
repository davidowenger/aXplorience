#ifndef __BaseBundle_H__
#define __BaseBundle_H__

namespace NSDEVICE
{

class BaseBundle : public Object
{
friend NSNATIVE::NNoObject;

public:
	virtual ~BaseBundle()
	{
	}

private:
    BaseBundle(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif
