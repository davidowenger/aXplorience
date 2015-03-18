#ifndef __VIEW_H__
#define __VIEW_H__

namespace NSDEVICE
{

class View : public Object
{
friend NSNATIVE::NNoObject;

public:
    static const int VISIBLE = 0;
    static const int INVISIBLE = 4;
    static const int GONE = 8;

    class OnClickListener
    {
    public:
        virtual ~OnClickListener()
        {
            NWrapper::w->nFrame->tRun(NWrapper::w->mNDelta00, (NParam)this);
        }

        virtual void onClick(View* v) = 0;

    protected:
        OnClickListener()
        {
            NWrapper::w->mNVisitorView->tRun(NWrapper::w->mNAlpha03, (NParam)this);
        }
    };

    class OnCreateContextMenuListener
    {
    public:
        virtual ~OnCreateContextMenuListener()
        {
            NWrapper::w->nFrame->tRun(NWrapper::w->mNDelta00, (NParam)this);
        }

        virtual void onCreateContextMenu(ContextMenu* menu, View* v, ContextMenu::ContextMenuInfo* menuInfo) = 0;

    protected:
        OnCreateContextMenuListener()
        {
            NWrapper::w->mNVisitorView->tRun(NWrapper::w->mNBeta03, (NParam)this);
        }
    };

    class OnTouchListener
    {
    public:
        virtual ~OnTouchListener()
        {
            NWrapper::w->nFrame->tRun(NWrapper::w->mNDelta00, (NParam)this);
        }

        virtual bool onTouch(View* v, MotionEvent* event) = 0;

    protected:
        OnTouchListener()
        {
            NWrapper::w->mNVisitorView->tRun(NWrapper::w->mNGamma03, (NParam)this);
        }
    };

	View(Context* context)
	{
        NWrapper::w->mNVisitorView->tRun(NWrapper::w->mNAlpha00, (NParam)this);
	}

	virtual ~View()
	{
	}

    virtual int getId()
    {
        return (int)NWrapper::w->mNVisitorView->tRun(NWrapper::w->mNBeta00, (NParam)this);
    }

	virtual void invalidate()
    {
        NWrapper::w->mNVisitorView->tRun(NWrapper::w->mNGamma00, (NParam)this);
    }

	virtual void requestLayout()
    {
        NWrapper::w->mNVisitorView->tRun(NWrapper::w->mNDelta00, (NParam)this);
    }

	virtual void setBackgroundColor(int color)
    {
        NWrapper::w->mNVisitorView->tRun(NWrapper::w->mNEpsilon00, (NParam)this, (NParam)color);
    }

	virtual void setBackgroundDrawable(Drawable* background)
    {
        NWrapper::w->mNVisitorView->tRun(NWrapper::w->mNDzeta00, (NParam)this, (NParam)background);
    }

    virtual void setId(int id)
    {
        NWrapper::w->mNVisitorView->tRun(NWrapper::w->mNEta00, (NParam)this, (NParam)id);
    }

	virtual void setLayoutParams(LayoutParams* params)
    {
        NWrapper::w->mNVisitorView->tRun(NWrapper::w->mNTheta00, (NParam)this, (NParam)params);
    }

	virtual void setOnClickListener(OnClickListener* l)
    {
        NWrapper::w->mNVisitorView->tRun(NWrapper::w->mNIota00, (NParam)this, (NParam)l);
    }

	virtual void setPadding(int left, int top, int right, int bottom)
    {
        NWrapper::w->mNVisitorView->tRun(NWrapper::w->mNKappa00, (NParam)this, (NParam)left, (NParam)top, (NParam)right, (NParam)bottom);
    }

	virtual void setVisibility(int visibility)
    {
        NWrapper::w->mNVisitorView->tRun(NWrapper::w->mNLambda00, (NParam)this, (NParam)visibility);
    }

private:
    View(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif
