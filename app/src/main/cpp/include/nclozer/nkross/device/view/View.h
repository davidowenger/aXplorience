#ifndef __VIEW_H__
#define __VIEW_H__

namespace NSDEVICE
{

class View : public Object
{
friend NSNATIVE::NKrossFriend;

public:
    static const int VISIBLE = 0;
    static const int INVISIBLE = 4;
    static const int GONE = 8;

    class LayoutParams : public Object
    {
    public:
        virtual ~LayoutParams();
    protected:
        LayoutParams();
    };

    class OnClickListener
    {
    public:
        virtual ~OnClickListener();
        virtual void onClick(View* v) = 0;
    protected:
        OnClickListener();
    };

    class OnCreateContextMenuListener
    {
    public:
        virtual ~OnCreateContextMenuListener();
        virtual void onCreateContextMenu(ContextMenu* menu, View* v, ContextMenu::ContextMenuInfo* menuInfo) = 0;
    protected:
        OnCreateContextMenuListener();
    };

    class OnTouchListener
    {
    public:
        virtual ~OnTouchListener();
        virtual bool onTouch(View* v, MotionEvent* event) = 0;
    protected:
        OnTouchListener();
    };

    View(Context* context);
    virtual ~View();
    virtual Drawable* getBackground();
    virtual int getId();
    virtual void invalidate();
    virtual bool performClick();
    virtual void requestLayout();
    virtual void setBackgroundColor(int color);
    virtual void setBackgroundDrawable(Drawable* background);
    virtual void setBackgroundResource(int resid);
    virtual void setId(int id);
    virtual void setLayoutParams(View::LayoutParams* params);
    virtual void setMinimumHeight(int minHeight);
    virtual void setMinimumWidth(int minWidth);
    virtual void setOnClickListener(View::OnClickListener* l);
    virtual void setOnTouchListener(View::OnTouchListener* l);
    virtual void setPadding(int left, int top, int right, int bottom);
    virtual void setVisibility(int visibility);
private:
    View(NKrossFriend* vNKrossFriend);
};

} // End namespace

#endif
