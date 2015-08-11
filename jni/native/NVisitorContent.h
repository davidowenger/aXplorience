#ifndef __NVisitorContent_H__
#define __NVisitorContent_H__

namespace NSNATIVE
{

class NVisitorContent : public NVisitor
{
public:
    NVisitorContent(NWrapper* w)
        : NVisitor(w)
    {
    }

    virtual ~NVisitorContent()
    {
    }
};

} // END namespace

#endif
