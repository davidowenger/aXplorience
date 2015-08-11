#ifndef __Spinner_H__
#define __Spinner_H__

namespace NSDEVICE
{

class Spinner : public AbsSpinner
{
friend NSNATIVE::NNoObject;

public:
    Spinner(Context* context)
        : AbsSpinner(NWrapper::w->mNNoObject->instance<AbsSpinner>())
    {
        NWrapper::w->mNVisitorWidget->tRun(NWrapper::w->mNPi00, (NParam)this, (NParam)context);
    }

    virtual ~Spinner()
    {
    }

    virtual void setGravity(int gravity)
    {
        NWrapper::w->mNVisitorWidget->tRun(NWrapper::w->mNRho00, (NParam)this, (NParam)gravity);
    }

    virtual void setOnItemClickListener(AdapterView::OnItemClickListener* l)
    {
        NWrapper::w->mNVisitorWidget->tRun(NWrapper::w->mNSigma00, (NParam)this, (NParam)l);
    }

    virtual void setAdapter(SpinnerAdapter* adapter)
    {
        NWrapper::w->mNVisitorWidget->tRun(NWrapper::w->mNTau00, (NParam)this, (NParam)adapter);
    }

private:
    Spinner(NNoObject* vNNoObject)
        : AbsSpinner(NWrapper::w->mNNoObject->instance<AbsSpinner>())
    {
    }
};

} // End namespace

#endif
