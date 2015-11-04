#ifndef __Spinner_H__
#define __Spinner_H__

namespace NSDEVICE
{

class Spinner : public AbsSpinner
{
friend NSNATIVE::NKrossFriend;

public:
    Spinner(Context* context)
        : AbsSpinner(NSNKROSS::w->mNKrossFriend->instance<AbsSpinner>())
    {
        NSNKROSS::w->mNVisitorWidget->tRun(NSNKROSS::w->mNPi00, (NParam)this, (NParam)context);
    }

    virtual ~Spinner()
    {
    }

    virtual void setGravity(int gravity)
    {
        NSNKROSS::w->mNVisitorWidget->tRun(NSNKROSS::w->mNRho00, (NParam)this, (NParam)gravity);
    }

    virtual void setOnItemClickListener(AdapterView::OnItemClickListener* l)
    {
        NSNKROSS::w->mNVisitorWidget->tRun(NSNKROSS::w->mNSigma00, (NParam)this, (NParam)l);
    }

    virtual void setAdapter(SpinnerAdapter* adapter)
    {
        NSNKROSS::w->mNVisitorWidget->tRun(NSNKROSS::w->mNTau00, (NParam)this, (NParam)adapter);
    }

private:
    Spinner(NKrossFriend* vNKrossFriend)
        : AbsSpinner(NSNKROSS::w->mNKrossFriend->instance<AbsSpinner>())
    {
    }
};

} // End namespace

#endif
