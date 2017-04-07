#ifndef __CompoundButton_H__
#define __CompoundButton_H__

namespace NSDEVICE
{

class CompoundButton : public Button
{
friend NSNATIVE::NKrossFriend;

public:
    virtual ~CompoundButton()
    {
    }

    virtual void setButtonDrawable(Drawable* d)
    {
        NKrossWrapper::w->mNVisitorWidget->tRun(NKrossWrapper::w->mNLambda00, (NParam)this, (NParam)d);
    }

    virtual bool isChecked()
    {
        return (bool)NKrossWrapper::w->mNVisitorWidget->tRun(NKrossWrapper::w->mNOmega00, (NParam)this);
    }

private:
    CompoundButton(NKrossFriend* vNKrossFriend)
        : Button(NKrossWrapper::w->mNKrossFriend->instance<Button>())
    {
    }
};

} // End namespace

#endif
