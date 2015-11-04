#ifndef __Widget_H__
#define __Widget_H__

namespace NSDEVICE
{

class Widget : public LinearLayout
{
public:
    Widget(Wrapper* w)
        : LinearLayout(w->mApplication), w(w), mcDBObjectId(1)
    {
        setLayoutParams(new LinearLayout::LayoutParams(0, LinearLayout::LayoutParams::MATCH_PARENT, 1));
    }

    virtual ~Widget()
    {
    }

    Wrapper* w;
    nuint mcDBObjectId;
};

} // End namespace

#endif
