#ifndef __ToggleButton_H__
#define __ToggleButton_H__

namespace NSDEVICE
{

class ToggleButton : public CompoundButton
{
friend NSNATIVE::NKrossFriend;

public:
    ToggleButton(Context* context)
        : CompoundButton(NKrossWrapper::w->mNKrossFriend->instance<CompoundButton>())
    {
        NKrossWrapper::w->mNVisitorWidget->tRun(NKrossWrapper::w->mNUpsilon00, (NParam)this, (NParam)context);
    }

    virtual ~ToggleButton()
    {
    }

    void setChecked(bool checked)
    {
        NKrossWrapper::w->mNVisitorWidget->tRun(NKrossWrapper::w->mNPhi00, (NParam)this, (NParam)checked);
    }

    void setTextOn(const String& textOn)
    {
        NKrossWrapper::w->mNVisitorWidget->tRun(NKrossWrapper::w->mNKhi00, (NParam)this, NKrossParam(textOn).n);
    }

    void setTextOff(const String& textOff)
    {
        NKrossWrapper::w->mNVisitorWidget->tRun(NKrossWrapper::w->mNPsi00, (NParam)this, NKrossParam(textOff).n);
    }

private:
    ToggleButton(NKrossFriend* vNKrossFriend)
        : CompoundButton(NKrossWrapper::w->mNKrossFriend->instance<CompoundButton>())
    {
    }
};

} // End namespace

#endif
