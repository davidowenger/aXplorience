#ifndef __AbsSpinner_H__
#define __AbsSpinner_H__

namespace NSDEVICE
{

class AbsSpinner : public AdapterView
{
friend NSNATIVE::NKrossFriend;

public:
    virtual ~AbsSpinner()
    {
    }

    virtual void setSelection(int position)
    {
        NKrossWrapper::w->mNVisitorWidget->tRun(NKrossWrapper::w->mNAlpha00, (NParam)this, (NParam)position);
    }

private:
    AbsSpinner(NKrossFriend* vNKrossFriend)
        : AdapterView(NKrossWrapper::w->mNKrossFriend->instance<AdapterView>())
    {
    }
};

} // End namespace

#endif
