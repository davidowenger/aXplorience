#ifndef __NVisitorHardware_H__
#define __NVisitorHardware_H__

namespace NSNATIVE
{

class NVisitorHardware : public NKrossVisitor
{
public:
    NVisitorHardware(NWrapper* w)
        : NKrossVisitor(w)
    {
    }

    virtual ~NVisitorHardware()
    {
    }
};

} // END namespace

#endif
