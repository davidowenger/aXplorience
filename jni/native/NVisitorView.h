#ifndef __NVisitorView_H__
#define __NVisitorView_H__

namespace NSNATIVE
{

class NVisitorView : public NVisitor
{
public:
	NVisitorView(NWrapper* w);
   ~NVisitorView();

    //*******************************************************************************************
    //*********************************** OnGestureListener *************************************
    //*******************************************************************************************
    // bool onDown(MotionEvent* e)
    NReturn visit(NAlpha03* element, NParam a, NParam b, NParam c, NParam d, NParam e) override;

    // bool onFling(MotionEvent* e1, MotionEvent* e2, float velocityX, float velocityY)
    NReturn visit(NBeta03* element, NParam a, NParam b, NParam c, NParam d, NParam e) override;

    // void onLongPress(MotionEvent* e)
    NReturn visit(NGamma03* element, NParam a, NParam b, NParam c, NParam d, NParam e) override;

    // bool onScroll(MotionEvent* e1, MotionEvent* e2, float distanceX, float distanceY)
    NReturn visit(NDelta03* element, NParam a, NParam b, NParam c, NParam d, NParam e) override;

    // void onShowPress(MotionEvent* e)
    NReturn visit(NEpsilon03* element, NParam a, NParam b, NParam c, NParam d, NParam e) override;

    // bool onSingleTapUp(MotionEvent* e)
    NReturn visit(NDzeta03* element, NParam a, NParam b, NParam c, NParam d, NParam e) override;
};

} // END namespace

#endif
