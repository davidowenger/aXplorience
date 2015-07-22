#ifndef __NVisitorViewGroup_H__
#define __NVisitorViewGroup_H__

namespace NSNATIVE
{

class NVisitorViewViewGroup : public NVisitor
{
public:
	NVisitorViewViewGroup(NWrapper* w)
		: NVisitor(w)
	{
	}

    virtual ~NVisitorViewViewGroup()
	{
	}

    //******************************************************************************************
    //******************************* ViewGroup events *****************************************
    //* This passes the call back to the default implementation if the method is not overriden *
    //******************************************************************************************
    // bool onInterceptTouchEvent(MotionEvent ev);
    NReturn visit(NEta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (b == -1 && c == 1) vcRet = (NReturn)NWrapper::w->mNNoObject->pointer<MotionEvent>();
        if (b != -1) {
            vcRet = ((ViewGroup*)a)->onInterceptTouchEvent((MotionEvent*)b);
            delete (MotionEvent*)b;
        }
        return vcRet;
    }
};

} // END namespace

#endif
