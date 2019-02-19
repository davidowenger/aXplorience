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
            ViewGroup::LayoutParams(NSNKROSS::w->mNKrossFriend->instance<ViewGroup::LayoutParams>())
        {
            NSNKROSS::w->mNVisitorView->tRun(NSNKROSS::w->mNAlpha00, (NParam)this, (NParam)_type, (NParam)_flags);
        }

        LayoutParams(int _type, int _flags, int _format) :
            ViewGroup::LayoutParams(NSNKROSS::w->mNKrossFriend->instance<ViewGroup::LayoutParams>())
        {
            NSNKROSS::w->mNVisitorView->tRun(NSNKROSS::w->mNAlpha00, (NParam)this, (NParam)_type, (NParam)_flags, (NParam)_format);
        }

        virtual ~LayoutParams()
        {
        }
    };

    virtual ~WindowManager()
    {
        NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNDelta00, (NParam)this);
    }

    Display* getDefaultDisplay()
    {
        Display* b = NSNKROSS::w->mNKrossFriend->pointer<Display>();
        return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorView->tRun(NSNKROSS::w->mNNu00, (NParam)this, (NParam)b));
    }

private:
    WindowManager(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
