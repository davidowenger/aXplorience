#ifndef __NVisitorWidgetLayout_H__
#define __NVisitorWidgetLayout_H__

namespace NSNATIVE
{

class NVisitorWidgetLayout : public NVisitor
{
public:
    NVisitorWidgetLayout(NWrapper* w)
        : NVisitor(w)
    {
    }

   ~NVisitorWidgetLayout()
    {
    }
};

} // END namespace

#endif
