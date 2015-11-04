#ifndef __ToggleButton_H__
#define __ToggleButton_H__

namespace NSDEVICE
{

class ToggleButton : public CompoundButton
{
friend NSNATIVE::NKrossFriend;

public:
    ToggleButton(Context* context)
        : CompoundButton(NSNKROSS::w->mNKrossFriend->instance<CompoundButton>())
    {
        NSNKROSS::w->mNVisitorWidget->tRun(NSNKROSS::w->mNUpsilon00, (NParam)this, (NParam)context);
    }

    virtual ~ToggleButton()
    {
    }

    void setChecked(bool checked)
    {
        NSNKROSS::w->mNVisitorWidget->tRun(NSNKROSS::w->mNPhi00, (NParam)this, (NParam)checked);
    }

    void setTextOn(const String& textOn)
    {
        NSNKROSS::w->mNVisitorWidget->tRun(NSNKROSS::w->mNKhi00, (NParam)this, NKrossParam(textOn).n);
    }

    void setTextOff(const String& textOff)
    {
        NSNKROSS::w->mNVisitorWidget->tRun(NSNKROSS::w->mNPsi00, (NParam)this, NKrossParam(textOff).n);
    }

private:
    ToggleButton(NKrossFriend* vNKrossFriend)
        : CompoundButton(NSNKROSS::w->mNKrossFriend->instance<CompoundButton>())
    {
    }
};

} // End namespace

#endif
