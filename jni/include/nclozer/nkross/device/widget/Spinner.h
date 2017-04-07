#ifndef __Spinner_H__
#define __Spinner_H__

namespace NSDEVICE
{

class Spinner : public AbsSpinner
{
friend NSNATIVE::NKrossFriend;

public:
    Spinner(Context* context)
        : AbsSpinner(NKrossWrapper::w->mNKrossFriend->instance<AbsSpinner>())
    {
        NKrossWrapper::w->mNVisitorWidget->tRun(NKrossWrapper::w->mNPi00, (NParam)this, (NParam)context);
    }

    virtual ~Spinner()
    {
    }

    virtual void setGravity(int gravity)
    {
        NKrossWrapper::w->mNVisitorWidget->tRun(NKrossWrapper::w->mNRho00, (NParam)this, (NParam)gravity);
    }

    virtual void setOnItemClickListener(AdapterView::OnItemClickListener* l)
    {
        NKrossWrapper::w->mNVisitorWidget->tRun(NKrossWrapper::w->mNSigma00, (NParam)this, (NParam)l);
    }

    virtual void setAdapter(SpinnerAdapter* adapter)
    {
        NKrossWrapper::w->mNVisitorWidget->tRun(NKrossWrapper::w->mNTau00, (NParam)this, (NParam)adapter);
    }

private:
    Spinner(NKrossFriend* vNKrossFriend)
        : AbsSpinner(NKrossWrapper::w->mNKrossFriend->instance<AbsSpinner>())
    {
    }
};

} // End namespace

#endif
