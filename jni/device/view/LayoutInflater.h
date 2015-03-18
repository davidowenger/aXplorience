#ifndef __LayoutInflater_H__
#define __LayoutInflater_H__

namespace NSDEVICE
{

class LayoutInflater : public Object
{
friend NSNATIVE::NNoObject;

public:
	virtual ~LayoutInflater()
	{
	}

private:
    LayoutInflater(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif
