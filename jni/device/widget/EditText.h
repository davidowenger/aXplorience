#ifndef __EditText_H__
#define __EditText_H__

namespace NSDEVICE
{

class EditText : public TextView
{
friend NSNATIVE::NNoObject;

public:
    EditText(Context* context)
        : TextView(NWrapper::w->mNNoObject->instance<TextView>())
    {
        NWrapper::w->mNVisitorWidget->tRun(NWrapper::w->mNMu00, (NParam)this, (NParam)context);
    }

    virtual ~EditText()
    {
    }

    virtual String getText()
    {
        NReturn index = NWrapper::w->mNVisitorWidget->tRun(NWrapper::w->mNNu00, (NParam)this);
        return NWrapper::w->nFrame->tGetString(NWrapper::w->nFrame->tRunObject((NParam)index));
    }

    virtual void setText(const String& text, TextView::BufferType type)
    {
        NWrapper::w->mNVisitorWidget->tRun(NWrapper::w->mNXi00, (NParam)this, NParamBox(NWrapper::w, text).n, (NParam)type);
    }

private:
    EditText(NNoObject* vNNoObject)
        : TextView(NWrapper::w->mNNoObject->instance<TextView>())
    {
    }
};

} // End namespace

#endif
