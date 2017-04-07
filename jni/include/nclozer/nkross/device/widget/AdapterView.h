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
            NKrossWrapper::w->mNVisitorWidgetView->tRun(NKrossWrapper::w->mNAlpha03, (NParam)this);
        }

    public:
        virtual ~OnItemSelectedListener()
        {
            NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNDelta00, (NParam)this);
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
            NKrossWrapper::w->mNVisitorWidgetView->tRun(NKrossWrapper::w->mNBeta03, (NParam)this);
        }

    public:
        virtual ~OnItemClickListener()
        {
            NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNDelta00, (NParam)this);
        }

        virtual void onItemClick(AdapterView* parent, View* view, int position, long id) = 0;
    };

    virtual ~AdapterView()
    {
    }

    virtual int getSelectedItemPosition()
    {
        return (nint)NKrossWrapper::w->mNVisitorWidgetView->tRun(NKrossWrapper::w->mNOmega00, (NParam)this);
    }

    virtual void setOnItemSelectedListener(OnItemSelectedListener* listener)
    {
        NKrossWrapper::w->mNVisitorWidgetView->tRun(NKrossWrapper::w->mNBeta00, (NParam)this, (NParam)listener);
    }

private:
    AdapterView(NKrossFriend* vNKrossFriend)
        : ViewGroup(NKrossWrapper::w->mNKrossFriend->instance<ViewGroup>())
    {
    }
};

} // End namespace

#endif
