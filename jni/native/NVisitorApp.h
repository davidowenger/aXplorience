#ifndef __NVisitorApp_H__
#define __NVisitorApp_H__

namespace NSNATIVE
{

class NVisitorApp : public NVisitor
{
public:
    NVisitorApp(NWrapper* w)
        : NVisitor(w)
    {
    }

    virtual ~NVisitorApp()
    {
    }
};

} // END namespace

#endif
