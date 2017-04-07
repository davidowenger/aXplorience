#ifndef __Button_H__
#define __Button_H__

namespace NSDEVICE
{

class Button : public TextView
{
friend NSNATIVE::NKrossFriend;

public:
    Button(Context* context)
        : TextView(NKrossWrapper::w->mNKrossFriend->instance<TextView>())
    {
        NKrossWrapper::w->mNVisitorWidget->tRun(NKrossWrapper::w->mNIota00, (NParam)this, (NParam)context);
    }

    virtual ~Button()
    {
    }

private:
    Button(NKrossFriend* vNKrossFriend)
        : TextView(NKrossWrapper::w->mNKrossFriend->instance<TextView>())
    {
    }
};

} // End namespace

#endif
