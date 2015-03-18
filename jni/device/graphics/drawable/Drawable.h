#ifndef __Drawable_H__
#define __Drawable_H__

namespace NSDEVICE
{

class Drawable : public Object
{
friend NSNATIVE::NNoObject;

public:
	virtual ~Drawable()
	{
	}

private:
    Drawable(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif
