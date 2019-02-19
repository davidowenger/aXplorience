#ifndef __NVisitorViewView_H__
#define __NVisitorViewView_H__

namespace NSNATIVE
{

class NVisitorViewView : public NKrossVisitor
{
public:
    NVisitorViewView(NWrapper* w)
        : NKrossVisitor(w)
    {
    }

    virtual ~NVisitorViewView()
    {
    }

    //******************************************************************************************
    //************************************* OnClickListener ************************************
    //******************************************************************************************
    // void onClick(View v)
    NReturn visit(NAlpha03* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (b == -1 && c == 1) vcRet = (NReturn)mNWrapper->mNKrossWrapper->mNKrossFriend->pointer<View>();
        if (b != -1) ((View::OnClickListener*)a)->onClick((View*)b);
        return vcRet;
    }

    //******************************************************************************************
    //***************************** OnCreateContextMenuListener ********************************
    //******************************************************************************************
    // void onCreateContextMenu(ContextMenu menu, View v, ContextMenu.ContextMenuInfo menuInfo)
    NReturn visit(NBeta03* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (b == -1 && c == 3) vcRet = (NReturn)mNWrapper->mNKrossWrapper->mNKrossFriend->pointer<ContextMenu>();
        if (b == -1 && c == 2) vcRet = (NReturn)mNWrapper->mNKrossWrapper->mNKrossFriend->pointer<View>();
        if (b == -1 && c == 1) vcRet = (NReturn)mNWrapper->mNKrossWrapper->mNKrossFriend->pointer<ContextMenu::ContextMenuInfo>();
        if (b != -1) ((View::OnCreateContextMenuListener*)a)->onCreateContextMenu((ContextMenu*)b, (View*)c, (ContextMenu::ContextMenuInfo*)d);
        return vcRet;
    }

    //******************************************************************************************
    //************************************* OnTouchListener ************************************
    //******************************************************************************************
    // boolean onTouch(View v, MotionEvent event)
    NReturn visit(NGamma03* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (b == -1 && c == 2) vcRet = (NReturn)mNWrapper->mNKrossWrapper->mNKrossFriend->pointer<View>();
        if (b == -1 && c == 1) vcRet = (NReturn)mNWrapper->mNKrossWrapper->mNKrossFriend->pointer<MotionEvent>();
        if (b != -1) {
            vcRet = ((View::OnTouchListener*)a)->onTouch((View*)b, (MotionEvent*)c);
            delete (MotionEvent*)c;
        }
        return vcRet;
    }
};

} // END namespace

#endif
