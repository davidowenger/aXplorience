#ifndef __SurfaceView_H__
#define __SurfaceView_H__

namespace NSDEVICE
{

class SurfaceView : public View
{
friend NSNATIVE::NKrossFriend;

public:
    SurfaceView(Context* context)
        : View(NKrossWrapper::w->mNKrossFriend->instance<View>())
    {
        NKrossWrapper::w->mNVisitorView->tRun(NKrossWrapper::w->mNMu00, (NParam)this, (NParam)context);
    }

    virtual ~SurfaceView()
    {
    }

    SurfaceHolder* getHolder()
    {
        SurfaceHolder* b = NKrossWrapper::w->mNKrossFriend->pointer<SurfaceHolder>();
        return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorView->tRun(NKrossWrapper::w->mNPhi00, (NParam)this, (NParam)b));
    }

private:
    SurfaceView(NKrossFriend* vNKrossFriend)
        : View(NKrossWrapper::w->mNKrossFriend->instance<View>())
    {
    }
};

} // End namespace

#endif
