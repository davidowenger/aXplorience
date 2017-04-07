#ifndef __AbsListView_H__
#define __AbsListView_H__

namespace NSDEVICE
{

class AbsListView : public AdapterView
{
friend NSNATIVE::NKrossFriend;

public:
    class LayoutParams : public ViewGroup::LayoutParams
    {
    friend  NSNATIVE::NKrossFriend;

    public:
        LayoutParams(int w, int h)
            : ViewGroup::LayoutParams(NKrossWrapper::w->mNKrossFriend->instance<ViewGroup::LayoutParams>())
        {
            NKrossWrapper::w->mNVisitorWidgetView->tRun(NKrossWrapper::w->mNTau00, (NParam)this, (NParam)w, (NParam)h);
        }

        virtual ~LayoutParams()
        {
        }

    private:
        LayoutParams(NKrossFriend* vNKrossFriend)
            : ViewGroup::LayoutParams(NKrossWrapper::w->mNKrossFriend->instance<ViewGroup::LayoutParams>())
        {
        }
    };

    virtual ~AbsListView()
    {
    }

private:
    AbsListView(NKrossFriend* vNKrossFriend)
        : AdapterView(NKrossWrapper::w->mNKrossFriend->instance<AdapterView>())
    {
    }
};

} // End namespace

#endif
