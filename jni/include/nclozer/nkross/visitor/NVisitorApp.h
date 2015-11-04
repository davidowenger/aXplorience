#ifndef __NVisitorApp_H__
#define __NVisitorApp_H__

namespace NSNATIVE
{

class NVisitorApp : public NKrossVisitor
{
public:
    NVisitorApp(NWrapper* w)
        : NKrossVisitor(w)
    {
    }

    virtual ~NVisitorApp()
    {
    }
};

} // END namespace

#endif
