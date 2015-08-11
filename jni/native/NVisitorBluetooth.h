#ifndef __NVisitorBluetooth_H__
#define __NVisitorBluetooth_H__

namespace NSNATIVE
{

class NVisitorBluetooth : public NVisitor
{
public:
    NVisitorBluetooth(NWrapper* w)
        : NVisitor(w)
    {
    }

   ~NVisitorBluetooth()
    {
    }
};

} // END namespace

#endif
