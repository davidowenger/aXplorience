#ifndef __MenuInflater_H__
#define __MenuInflater_H__

namespace NSDEVICE
{

class MenuInflater : public Object
{
friend NSNATIVE::NKrossFriend;

public:
    virtual ~MenuInflater()
    {
    }

private:
    MenuInflater(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
