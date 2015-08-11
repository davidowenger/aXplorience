#ifndef __CompoundButton_H__
#define __CompoundButton_H__

namespace NSDEVICE
{

class CompoundButton : public Button
{
friend NSNATIVE::NNoObject;

public:
    virtual ~CompoundButton()
    {
    }

    virtual void setButtonDrawable(Drawable* d)
    {
        NWrapper::w->mNVisitorWidget->tRun(NWrapper::w->mNLambda00, (NParam)this, (NParam)d);
    }

    virtual bool isChecked()
    {
        return (bool)NWrapper::w->mNVisitorWidget->tRun(NWrapper::w->mNOmega00, (NParam)this);
    }

private:
    CompoundButton(NNoObject* vNNoObject)
        : Button(NWrapper::w->mNNoObject->instance<Button>())
    {
    }
};

} // End namespace

#endif
