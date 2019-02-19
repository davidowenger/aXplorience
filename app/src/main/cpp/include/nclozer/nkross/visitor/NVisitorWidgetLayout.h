#ifndef __NVisitorWidgetLayout_H__
#define __NVisitorWidgetLayout_H__

namespace NSNATIVE
{

class NVisitorWidgetLayout : public NKrossVisitor
{
public:
    NVisitorWidgetLayout(NWrapper* w)
        : NKrossVisitor(w)
    {
    }

   ~NVisitorWidgetLayout()
    {
    }
};

} // END namespace

#endif
