#ifndef __AbsListView_H__
#define __AbsListView_H__

namespace NSDEVICE
{

class AbsListView : public AdapterView
{
friend NSNATIVE::NNoObject;

public:
    class LayoutParams : public ViewGroup::LayoutParams
    {
    friend  NSNATIVE::NNoObject;

    public:
        LayoutParams(int w, int h)
            : ViewGroup::LayoutParams(NWrapper::w->mNNoObject->instance<ViewGroup::LayoutParams>())
        {
            NWrapper::w->mNVisitorWidgetView->tRun(NWrapper::w->mNTau00, (NParam)this, (NParam)w, (NParam)h);
        }

        virtual ~LayoutParams()
        {
        }

    private:
        LayoutParams(NNoObject* vNNoObject)
            : ViewGroup::LayoutParams(NWrapper::w->mNNoObject->instance<ViewGroup::LayoutParams>())
        {
        }
    };

	virtual ~AbsListView()
	{
	}

private:
    AbsListView(NNoObject* vNNoObject)
        : AdapterView(NWrapper::w->mNNoObject->instance<AdapterView>())
    {
    }
};

} // End namespace

#endif
