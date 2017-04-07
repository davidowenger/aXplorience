#ifndef __WindowManager_H__
#define __WindowManager_H__

namespace NSDEVICE
{

class WindowManager
{
friend NSNATIVE::NKrossFriend;

public:
    class LayoutParams : public ViewGroup::LayoutParams
    {
    friend NSNATIVE::NKrossFriend;

    public:
        LayoutParams(int _type, int _flags) :
            ViewGroup::LayoutParams(NKrossWrapper::w->mNKrossFriend->instance<ViewGroup::LayoutParams>())
        {
            NKrossWrapper::w->mNVisitorView->tRun(NKrossWrapper::w->mNAlpha00, (NParam)this, (NParam)_type, (NParam)_flags);
        }

        LayoutParams(int _type, int _flags, int _format) :
            ViewGroup::LayoutParams(NKrossWrapper::w->mNKrossFriend->instance<ViewGroup::LayoutParams>())
        {
            NKrossWrapper::w->mNVisitorView->tRun(NKrossWrapper::w->mNAlpha00, (NParam)this, (NParam)_type, (NParam)_flags, (NParam)_format);
        }

        virtual ~LayoutParams()
        {
        }
    };

    virtual ~WindowManager()
    {
        NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNDelta00, (NParam)this);
    }

    Display* getDefaultDisplay()
    {
        Display* b = NKrossWrapper::w->mNKrossFriend->pointer<Display>();
        return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorView->tRun(NKrossWrapper::w->mNNu00, (NParam)this, (NParam)b));
    }

private:
    WindowManager(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
