#ifndef __AdapterView_H__
#define __AdapterView_H__

namespace NSDEVICE
{

class AdapterView : public ViewGroup
{
friend NSNATIVE::NKrossFriend;

public:
    class OnItemSelectedListener
    {
    friend  NSNATIVE::NKrossFriend;

    protected:
        OnItemSelectedListener()
        {
            NSNKROSS::w->mNVisitorWidgetView->tRun(NSNKROSS::w->mNAlpha03, (NParam)this);
        }

    public:
        virtual ~OnItemSelectedListener()
        {
            NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNDelta00, (NParam)this);
        }

        virtual void onItemSelected(AdapterView* parent, View* view, int position, long id) = 0;
        virtual void onNothingSelected(AdapterView* parent) = 0;
    };

    class OnItemClickListener
    {
    friend  NSNATIVE::NKrossFriend;

    protected:
        OnItemClickListener()
        {
            NSNKROSS::w->mNVisitorWidgetView->tRun(NSNKROSS::w->mNBeta03, (NParam)this);
        }

    public:
        virtual ~OnItemClickListener()
        {
            NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNDelta00, (NParam)this);
        }

        virtual void onItemClick(AdapterView* parent, View* view, int position, long id) = 0;
    };

    virtual ~AdapterView()
    {
    }

    virtual int getSelectedItemPosition()
    {
        return (nint)NSNKROSS::w->mNVisitorWidgetView->tRun(NSNKROSS::w->mNOmega00, (NParam)this);
    }

    virtual void setOnItemSelectedListener(OnItemSelectedListener* listener)
    {
        NSNKROSS::w->mNVisitorWidgetView->tRun(NSNKROSS::w->mNBeta00, (NParam)this, (NParam)listener);
    }

private:
    AdapterView(NKrossFriend* vNKrossFriend)
        : ViewGroup(NSNKROSS::w->mNKrossFriend->instance<ViewGroup>())
    {
    }
};

} // End namespace

#endif
