#ifndef __MenuInflater_H__
#define __MenuInflater_H__

namespace NSDEVICE
{

class MenuInflater : public Object
{
friend NSNATIVE::NNoObject;

public:
    virtual ~MenuInflater()
    {
    }

private:
    MenuInflater(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif
