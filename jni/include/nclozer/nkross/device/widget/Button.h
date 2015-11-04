#ifndef __Button_H__
#define __Button_H__

namespace NSDEVICE
{

class Button : public TextView
{
friend NSNATIVE::NKrossFriend;

public:
    Button(Context* context)
        : TextView(NSNKROSS::w->mNKrossFriend->instance<TextView>())
    {
        NSNKROSS::w->mNVisitorWidget->tRun(NSNKROSS::w->mNIota00, (NParam)this, (NParam)context);
    }

    virtual ~Button()
    {
    }

private:
    Button(NKrossFriend* vNKrossFriend)
        : TextView(NSNKROSS::w->mNKrossFriend->instance<TextView>())
    {
    }
};

} // End namespace

#endif
