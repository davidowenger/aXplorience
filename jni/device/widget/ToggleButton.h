#ifndef __ToggleButton_H__
#define __ToggleButton_H__

namespace NSDEVICE
{

class ToggleButton : public CompoundButton
{
friend NSNATIVE::NNoObject;

public:
    ToggleButton(Context* context)
        : CompoundButton(NWrapper::w->mNNoObject->instance<CompoundButton>())
	{
        NWrapper::w->mNVisitorWidget->tRun(NWrapper::w->mNUpsilon00, (NParam)this);
	}

    virtual ~ToggleButton()
	{
	}

    void setChecked(bool checked)
    {
        NWrapper::w->mNVisitorWidget->tRun(NWrapper::w->mNPhi00, (NParam)this);
    }

    void setTextOn(const String& textOn)
    {
        NWrapper::w->mNVisitorWidget->tRun(NWrapper::w->mNKhi00, (NParam)this);
    }

    void setTextOff(const String& textOff)
    {
        NWrapper::w->mNVisitorWidget->tRun(NWrapper::w->mNPsi00, (NParam)this);
    }

private:
    ToggleButton(NNoObject* vNNoObject)
        : CompoundButton(NWrapper::w->mNNoObject->instance<CompoundButton>())
    {
    }
};

} // End namespace

#endif
