#ifndef __LayoutInflater_H__
#define __LayoutInflater_H__

namespace NSDEVICE
{

class LayoutInflater : public Object
{
friend NSNATIVE::NKrossFriend;

public:
    virtual ~LayoutInflater()
    {
    }

private:
    LayoutInflater(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
