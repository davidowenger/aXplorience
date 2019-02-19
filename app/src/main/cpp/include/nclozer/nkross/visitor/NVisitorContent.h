#ifndef __NVisitorContent_H__
#define __NVisitorContent_H__

namespace NSNATIVE
{

class NVisitorContent : public NKrossVisitor
{
public:
    NVisitorContent(NWrapper* w)
        : NKrossVisitor(w)
    {
    }

    virtual ~NVisitorContent()
    {
    }
};

} // END namespace

#endif
