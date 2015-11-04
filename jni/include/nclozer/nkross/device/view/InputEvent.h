#ifndef __InputEvent_H__
#define __InputEvent_H__

namespace NSDEVICE
{

class InputEvent : public Object
{
friend NSNATIVE::NKrossFriend;

public:
    virtual ~InputEvent()
    {
    }

private:
    InputEvent(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
