#ifndef __Context_H__
#define __Context_H__

namespace NSDEVICE
{

class Context : public Object
{
friend NSNATIVE::NNoObject;

public:
	virtual ~Context()
	{
	}

private:
    Context(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif
