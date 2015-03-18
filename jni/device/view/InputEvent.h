#ifndef __InputEvent_H__
#define __InputEvent_H__

namespace NSDEVICE
{

class InputEvent : public Object
{
friend NSNATIVE::NNoObject;

public:
	virtual ~InputEvent()
	{
	}

private:
    InputEvent(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif
