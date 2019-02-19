#include "nkross/NKrossCommon.h"

namespace NSNATIVE
{

NVisitorView::NVisitorView(NWrapper* w)
    : NKrossVisitor(w)
{
}

NVisitorView::~NVisitorView()
{
}

//*******************************************************************************************
//*********************************** OnGestureListener *************************************
//*******************************************************************************************
// bool onDown(MotionEvent* e)
NReturn NVisitorView::visit(NAlpha03* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    NReturn vcRet = 0;
    if (b == -1 && c == 1) vcRet = (NReturn)mNWrapper->mNKrossWrapper->mNKrossFriend->pointer<MotionEvent>();
    if (b != -1) {
        vcRet = ((GestureDetector::OnGestureListener*)a)->onDown((MotionEvent*)b);
        delete (MotionEvent*)b;
    }
    return vcRet;
}

// bool onFling(MotionEvent* e1, MotionEvent* e2, nfloat velocityX, nfloat velocityY)
NReturn NVisitorView::visit(NBeta03* element, NParam a, NParam b, NParam c, NParam d, NParam e)
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
NReturn NVisitorView::visit(NGamma03* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    NReturn vcRet = 0;
    if (b == -1 && c == 1) vcRet = (NReturn)mNWrapper->mNKrossWrapper->mNKrossFriend->pointer<MotionEvent>();
    if (b != -1) {
        ((GestureDetector::OnGestureListener*)a)->onLongPress((MotionEvent*)b);
        delete (MotionEvent*)b;
    }
    return vcRet;
}

// bool onScroll(MotionEvent* e1, MotionEvent* e2, nfloat distanceX, nfloat distanceY)
NReturn NVisitorView::visit(NDelta03* element, NParam a, NParam b, NParam c, NParam d, NParam e)
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
NReturn NVisitorView::visit(NEpsilon03* element, NParam a, NParam b, NParam c, NParam d, NParam e)
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
NReturn NVisitorView::visit(NDzeta03* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    NReturn vcRet = 0;
    if (b == -1 && c == 1) vcRet = (NReturn)mNWrapper->mNKrossWrapper->mNKrossFriend->pointer<MotionEvent>();
    if (b != -1) {
        vcRet = ((GestureDetector::OnGestureListener*)a)->onSingleTapUp((MotionEvent*)b);
        delete (MotionEvent*)b;
    }
    return vcRet;
}

} // END namespace
