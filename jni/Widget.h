#ifndef __Widget_H__
#define __Widget_H__

namespace NSDEVICE
{

class Widget : public LinearLayout
{
public:
	Widget(Wrapper* w)
        : LinearLayout(w->mApplication), w(w), mcView(0), mcDBObjectId(1)
    {
	    setLayoutParams(new LinearLayout::LayoutParams(0, LinearLayout::LayoutParams::MATCH_PARENT, 1));
        setBackgroundColor(w->maColor[0]);
    }

	virtual ~Widget()
    {
    }

    virtual void init(nuint vcView, nuint vcDBObjectId)
    {
    }

    Wrapper* w;

    nuint mcView;
    nuint mcDBObjectId;
};

} // End namespace

#endif
