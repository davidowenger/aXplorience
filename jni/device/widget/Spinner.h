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
        NWrapper::w->mNVisitorWidget->tRun(NWrapper::w->mNPi00, (NParam)this);
	}

	virtual ~Spinner()
	{
	}

    virtual void setGravity(int gravity)
    {
        NWrapper::w->mNVisitorWidget->tRun(NWrapper::w->mNRho00, (NParam)this);
    }

    virtual void setOnItemClickListener(AdapterView::OnItemClickListener* l)
    {
        NWrapper::w->mNVisitorWidget->tRun(NWrapper::w->mNSigma00, (NParam)this);
    }

    virtual void setAdapter(SpinnerAdapter* adapter)
    {
        NWrapper::w->mNVisitorWidget->tRun(NWrapper::w->mNTau00, (NParam)this);
    }

private:
    Spinner(NNoObject* vNNoObject)
        : AbsSpinner(NWrapper::w->mNNoObject->instance<AbsSpinner>())
    {
    }
};

} // End namespace

#endif
