#ifndef __SurfaceView_H__
#define __SurfaceView_H__

namespace NSDEVICE
{

class SurfaceView : public View
{
friend NSNATIVE::NKrossFriend;

public:
    SurfaceView(Context* context)
        : View(NSNKROSS::w->mNKrossFriend->instance<View>())
    {
        NSNKROSS::w->mNVisitorView->tRun(NSNKROSS::w->mNMu00, (NParam)this, (NParam)context);
    }

    virtual ~SurfaceView()
    {
    }

    SurfaceHolder* getHolder()
    {
        SurfaceHolder* b = NSNKROSS::w->mNKrossFriend->pointer<SurfaceHolder>();
        return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorView->tRun(NSNKROSS::w->mNPhi00, (NParam)this, (NParam)b));
    }

private:
    SurfaceView(NKrossFriend* vNKrossFriend)
        : View(NSNKROSS::w->mNKrossFriend->instance<View>())
    {
    }
};

} // End namespace

#endif
