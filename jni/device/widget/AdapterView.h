#ifndef __AdapterView_H__
#define __AdapterView_H__

namespace NSDEVICE
{

class AdapterView : public ViewGroup
{
friend NSNATIVE::NNoObject;

public:
    class OnItemSelectedListener
    {
    friend  NSNATIVE::NNoObject;

    protected:
        OnItemSelectedListener()
        {
            NWrapper::w->mNVisitorWidgetView->tRun(NWrapper::w->mNAlpha03, (NParam)this);
        }

    public:
        virtual ~OnItemSelectedListener()
        {
            NWrapper::w->nFrame->tRun(NWrapper::w->mNDelta00, (NParam)this);
        }

        virtual void onItemSelected(AdapterView* parent, View* view, int position, long id) = 0;
        virtual void onNothingSelected(AdapterView* parent) = 0;
    };

    class OnItemClickListener
    {
    friend  NSNATIVE::NNoObject;

    protected:
        OnItemClickListener()
        {
            NWrapper::w->mNVisitorWidgetView->tRun(NWrapper::w->mNBeta03, (NParam)this);
        }

    public:
        virtual ~OnItemClickListener()
        {
            NWrapper::w->nFrame->tRun(NWrapper::w->mNDelta00, (NParam)this);
        }

        virtual void onItemClick(AdapterView* parent, View* view, int position, long id) = 0;
    };

	virtual ~AdapterView()
	{
	}

    virtual int getSelectedItemPosition()
    {
        return (nint)NWrapper::w->mNVisitorWidgetView->tRun(NWrapper::w->mNOmega00, (NParam)this);
    }

    virtual void setOnItemSelectedListener(OnItemSelectedListener* listener)
    {
        NWrapper::w->mNVisitorWidgetView->tRun(NWrapper::w->mNBeta00, (NParam)this, (NParam)listener);
    }

private:
    AdapterView(NNoObject* vNNoObject)
        : ViewGroup(NWrapper::w->mNNoObject->instance<ViewGroup>())
    {
    }
};

} // End namespace

#endif
