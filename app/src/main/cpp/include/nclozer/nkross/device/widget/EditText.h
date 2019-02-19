#ifndef __EditText_H__
#define __EditText_H__

namespace NSDEVICE
{

class EditText : public TextView
{
friend NSNATIVE::NKrossFriend;

public:
    EditText(Context* context)
        : TextView(NSNKROSS::w->mNKrossFriend->instance<TextView>())
    {
        NSNKROSS::w->mNVisitorWidget->tRun(NSNKROSS::w->mNMu00, (NParam)this, (NParam)context);
    }

    virtual ~EditText()
    {
    }

    virtual String getText()
    {
        NReturn index = NSNKROSS::w->mNVisitorWidget->tRun(NSNKROSS::w->mNNu00, (NParam)this);
        return NSNKROSS::w->mNKrossSystem->tGetString(NSNKROSS::w->mNKrossSystem->tRunObject((NParam)index));
    }

    virtual void setText(const String& text, TextView::BufferType type)
    {
        NSNKROSS::w->mNVisitorWidget->tRun(NSNKROSS::w->mNXi00, (NParam)this, NKrossParam(text).n, (NParam)type);
    }

private:
    EditText(NKrossFriend* vNKrossFriend)
        : TextView(NSNKROSS::w->mNKrossFriend->instance<TextView>())
    {
    }
};

} // End namespace

#endif
