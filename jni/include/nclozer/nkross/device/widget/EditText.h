#ifndef __EditText_H__
#define __EditText_H__

namespace NSDEVICE
{

class EditText : public TextView
{
friend NSNATIVE::NKrossFriend;

public:
    EditText(Context* context)
        : TextView(NKrossWrapper::w->mNKrossFriend->instance<TextView>())
    {
        NKrossWrapper::w->mNVisitorWidget->tRun(NKrossWrapper::w->mNMu00, (NParam)this, (NParam)context);
    }

    virtual ~EditText()
    {
    }

    virtual String getText()
    {
        NReturn index = NKrossWrapper::w->mNVisitorWidget->tRun(NKrossWrapper::w->mNNu00, (NParam)this);
        return NKrossWrapper::w->mNKrossSystem->tGetString(NKrossWrapper::w->mNKrossSystem->tRunObject((NParam)index));
    }

    virtual void setText(const String& text, TextView::BufferType type)
    {
        NKrossWrapper::w->mNVisitorWidget->tRun(NKrossWrapper::w->mNXi00, (NParam)this, NKrossParam(text).n, (NParam)type);
    }

private:
    EditText(NKrossFriend* vNKrossFriend)
        : TextView(NKrossWrapper::w->mNKrossFriend->instance<TextView>())
    {
    }
};

} // End namespace

#endif
