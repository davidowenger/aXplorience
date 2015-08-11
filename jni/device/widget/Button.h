#ifndef __Button_H__
#define __Button_H__

namespace NSDEVICE
{

class Button : public TextView
{
friend NSNATIVE::NNoObject;

public:
    Button(Context* context)
        : TextView(NWrapper::w->mNNoObject->instance<TextView>())
    {
        NWrapper::w->mNVisitorWidget->tRun(NWrapper::w->mNIota00, (NParam)this, (NParam)context);
    }

    virtual ~Button()
    {
    }

private:
    Button(NNoObject* vNNoObject)
        : TextView(NWrapper::w->mNNoObject->instance<TextView>())
    {
    }
};

} // End namespace

#endif
