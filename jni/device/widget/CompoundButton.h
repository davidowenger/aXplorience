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

    void setButtonDrawable(Drawable* d)
    {
        NWrapper::w->mNVisitorWidget->tRun(NWrapper::w->mNLambda00, (NParam)this);
    }

private:
    CompoundButton(NNoObject* vNNoObject)
        : Button(NWrapper::w->mNNoObject->instance<Button>())
    {
    }
};

} // End namespace

#endif
