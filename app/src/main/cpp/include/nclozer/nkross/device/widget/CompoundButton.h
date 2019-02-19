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
        NSNKROSS::w->mNVisitorWidget->tRun(NSNKROSS::w->mNLambda00, (NParam)this, (NParam)d);
    }

    virtual bool isChecked()
    {
        return (bool)NSNKROSS::w->mNVisitorWidget->tRun(NSNKROSS::w->mNOmega00, (NParam)this);
    }

private:
    CompoundButton(NKrossFriend* vNKrossFriend)
        : Button(NSNKROSS::w->mNKrossFriend->instance<Button>())
    {
    }
};

} // End namespace

#endif
