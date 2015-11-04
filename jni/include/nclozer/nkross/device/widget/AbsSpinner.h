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
        NSNKROSS::w->mNVisitorWidget->tRun(NSNKROSS::w->mNAlpha00, (NParam)this, (NParam)position);
    }

private:
    AbsSpinner(NKrossFriend* vNKrossFriend)
        : AdapterView(NSNKROSS::w->mNKrossFriend->instance<AdapterView>())
    {
    }
};

} // End namespace

#endif
