#ifndef __AbsSpinner_H__
#define __AbsSpinner_H__

namespace NSDEVICE
{

class AbsSpinner : public AdapterView
{
friend NSNATIVE::NNoObject;

public:
    virtual ~AbsSpinner()
    {
    }

    virtual void setSelection(int position)
    {
        NWrapper::w->mNVisitorWidget->tRun(NWrapper::w->mNAlpha00, (NParam)this, (NParam)position);
    }

private:
    AbsSpinner(NNoObject* vNNoObject)
        : AdapterView(NWrapper::w->mNNoObject->instance<AdapterView>())
    {
    }
};

} // End namespace

#endif
