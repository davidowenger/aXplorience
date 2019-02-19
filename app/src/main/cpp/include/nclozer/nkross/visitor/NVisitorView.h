#ifndef __NVisitorView_H__
#define __NVisitorView_H__

namespace NSNATIVE
{

class NVisitorView : public NKrossVisitor
{
public:
    NVisitorView(NWrapper* w)
        : NKrossVisitor(w)
    {
    }

    virtual ~NVisitorView()
    {
    }

    //*******************************************************************************************
    //*********************************** OnGestureListener *************************************
    //*******************************************************************************************
    // bool onDown(MotionEvent* e)
    NReturn visit(NAlpha03* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (b == -1 && c == 1) vcRet = (NReturn)mNWrapper->mNKrossWrapper->mNKrossFriend->pointer<MotionEvent>();
        if (b != -1) {
            vcRet = ((GestureDetector::OnGestureListener*)a)->onDown((MotionEvent*)b);
            delete (MotionEvent*)b;
        }
        return vcRet;
    }

    // bool onFling(MotionEvent* e1, MotionEvent* e2, float velocityX, float velocityY)
    NReturn visit(NBeta03* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (b == -1 && c == 2) vcRet = (NReturn)mNWrapper->mNKrossWrapper->mNKrossFriend->pointer<MotionEvent>();
        if (b == -1 && c == 1) vcRet = (NReturn)mNWrapper->mNKrossWrapper->mNKrossFriend->pointer<MotionEvent>();
        if (b != -1) {
            vcRet = ((GestureDetector::OnGestureListener*)a)->onFling((MotionEvent*)b, (MotionEvent*)c, (nfloat)*reinterpret_cast<ndouble*>(&d), (nfloat)*reinterpret_cast<ndouble*>(&e));
            delete (MotionEvent*)b;
            delete (MotionEvent*)c;
        }
        return vcRet;
    }

    // void onLongPress(MotionEvent* e)
    NReturn visit(NGamma03* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (b == -1 && c == 1) vcRet = (NReturn)mNWrapper->mNKrossWrapper->mNKrossFriend->pointer<MotionEvent>();
        if (b != -1) {
            ((GestureDetector::OnGestureListener*)a)->onLongPress((MotionEvent*)b);
            delete (MotionEvent*)b;
        }
        return vcRet;
    }


    // bool onScroll(MotionEvent* e1, MotionEvent* e2, float distanceX, float distanceY)
    NReturn visit(NDelta03* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (b == -1 && c == 2) vcRet = (NReturn)mNWrapper->mNKrossWrapper->mNKrossFriend->pointer<MotionEvent>();
        if (b == -1 && c == 1) vcRet = (NReturn)mNWrapper->mNKrossWrapper->mNKrossFriend->pointer<MotionEvent>();
        if (b != -1) {
            vcRet = ((GestureDetector::OnGestureListener*)a)->onScroll((MotionEvent*)b, (MotionEvent*)c, (nfloat)*reinterpret_cast<ndouble*>(&d), (nfloat)*reinterpret_cast<ndouble*>(&e));
            delete (MotionEvent*)b;
            delete (MotionEvent*)c;
        }
        return vcRet;
    }

    // void onShowPress(MotionEvent* e)
    NReturn visit(NEpsilon03* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (b == -1 && c == 1) vcRet = (NReturn)mNWrapper->mNKrossWrapper->mNKrossFriend->pointer<MotionEvent>();
        if (b != -1) {
            ((GestureDetector::OnGestureListener*)a)->onShowPress((MotionEvent*)b);
            delete (MotionEvent*)b;
        }
        return vcRet;
    }

    // bool onSingleTapUp(MotionEvent* e)
    NReturn visit(NDzeta03* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (b == -1 && c == 1) vcRet = (NReturn)mNWrapper->mNKrossWrapper->mNKrossFriend->pointer<MotionEvent>();
        if (b != -1) {
            vcRet = ((GestureDetector::OnGestureListener*)a)->onSingleTapUp((MotionEvent*)b);
            delete (MotionEvent*)b;
        }
        return vcRet;
    }

    //*******************************************************************************************
    //********************************** SurfaceHolder::Callback ********************************
    //*******************************************************************************************
    // void surfaceCreated(SurfaceHolder holder)
    NReturn visit(NAlpha00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (a == 0 && b == 1) vcRet = (NReturn)mNWrapper->mNKrossWrapper->mNKrossFriend->pointer<SurfaceHolder>();
        if (a != 0) ((SurfaceHolder::Callback*)a)->surfaceCreated((SurfaceHolder*)b);
        return vcRet;
    }

    // void surfaceChanged(SurfaceHolder holder, int format, int width, int height)
    NReturn visit(NBeta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (a == 0 && b == 1) vcRet = (NReturn)mNWrapper->mNKrossWrapper->mNKrossFriend->pointer<SurfaceHolder>();
        if (a != 0) ((SurfaceHolder::Callback*)a)->surfaceChanged((SurfaceHolder*)b, (nint)c, (nint)d, (nint)e);
        return vcRet;
    }

    // void surfaceDestroyed(SurfaceHolder holder)
    NReturn visit(NGamma00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (a == 0 && b == 1) vcRet = (NReturn)mNWrapper->mNKrossWrapper->mNKrossFriend->pointer<SurfaceHolder>();
        if (a != 0) ((SurfaceHolder::Callback*)a)->surfaceDestroyed((SurfaceHolder*)b);
        return vcRet;
    }

    //*******************************************************************************************
    //********************************** SurfaceHolder::Callback2 *******************************
    //*******************************************************************************************
    // void surfaceRedrawNeeded(SurfaceHolder holder)
    NReturn visit(NDelta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (a == 0 && b == 1) vcRet = (NReturn)mNWrapper->mNKrossWrapper->mNKrossFriend->pointer<SurfaceHolder>();
        if (a != 0) ((SurfaceHolder::Callback2*)a)->surfaceRedrawNeeded((SurfaceHolder*)b);
        return vcRet;
    }
};

} // END namespace

#endif
