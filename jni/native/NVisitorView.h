#ifndef __NVisitorView_H__
#define __NVisitorView_H__

namespace NSNATIVE
{

class NVisitorView : public NVisitor
{
public:
	NVisitorView(NWrapper* w)
		: NVisitor(w)
	{
	}

   ~NVisitorView()
	{
	}

    //*******************************************************************************************
    //*********************************** OnGestureListener *************************************
    //*******************************************************************************************
    // bool onDown(MotionEvent* e)
    NReturn visit(NAlpha03* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (b == -1 && c == 1) vcRet = (NReturn)NWrapper::w->mNNoObject->pointer<MotionEvent>();
        if (b != -1) vcRet = ((GestureDetector::OnGestureListener*)a)->onDown((MotionEvent*)b);
        return vcRet;
    }

    // bool onFling(MotionEvent* e1, MotionEvent* e2, float velocityX, float velocityY)
    NReturn visit(NBeta03* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (b == -1 && c == 2) vcRet = (NReturn)NWrapper::w->mNNoObject->pointer<MotionEvent>();
        if (b == -1 && c == 1) vcRet = (NReturn)NWrapper::w->mNNoObject->pointer<MotionEvent>();
        if (b != -1) vcRet = ((GestureDetector::OnGestureListener*)a)->onFling((MotionEvent*)b, (MotionEvent*)c, *reinterpret_cast<float*>(&d), *reinterpret_cast<float*>(&e));
        return vcRet;
    }

    // void onLongPress(MotionEvent* e)
    NReturn visit(NGamma03* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (b == -1 && c == 1) vcRet = (NReturn)NWrapper::w->mNNoObject->pointer<MotionEvent>();
        if (b != -1) ((GestureDetector::OnGestureListener*)a)->onLongPress((MotionEvent*)b);
        return vcRet;
    }

    // bool onScroll(MotionEvent* e1, MotionEvent* e2, float distanceX, float distanceY)
    NReturn visit(NDelta03* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;

        if (b == -1 && c == 2) vcRet = (NReturn)NWrapper::w->mNNoObject->pointer<MotionEvent>();
        if (b == -1 && c == 1) vcRet = (NReturn)NWrapper::w->mNNoObject->pointer<MotionEvent>();
        if (b != -1) vcRet = ((GestureDetector::OnGestureListener*)a)->onScroll((MotionEvent*)b, (MotionEvent*)c, *reinterpret_cast<float*>(&d), *reinterpret_cast<float*>(&e));
        return vcRet;
    }

    // void onShowPress(MotionEvent* e)
    NReturn visit(NEpsilon03* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;

        if (b == -1 && c == 1) vcRet = (NReturn)NWrapper::w->mNNoObject->pointer<MotionEvent>();
        if (b != -1) ((GestureDetector::OnGestureListener*)a)->onShowPress((MotionEvent*)b);
        return vcRet;
    }

    // bool onSingleTapUp(MotionEvent* e)
    NReturn visit(NDzeta03* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (b == -1 && c == 1) vcRet = (NReturn)NWrapper::w->mNNoObject->pointer<MotionEvent>();
        if (b != -1) vcRet = ((GestureDetector::OnGestureListener*)a)->onSingleTapUp((MotionEvent*)b);
        return vcRet;
    }


};

} // END namespace

#endif
