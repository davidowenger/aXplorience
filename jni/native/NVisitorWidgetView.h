#ifndef __NVisitorWidgetView_H__
#define __NVisitorWidgetView_H__

namespace NSNATIVE
{

class NVisitorWidgetView : public NVisitor
{
public:
	NVisitorWidgetView(NWrapper* w)
		: NVisitor(w)
	{
	}

    virtual ~NVisitorWidgetView()
	{
	}

    //******************************************************************************************
    //******************************** OnItemSelectedListener **********************************
    //******************************************************************************************
    // void onItemSelected(AdapterView<?> parent, View view, int position, long id)
    NReturn visit(NAlpha03* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (b == -1 && c == 2) vcRet = (NReturn)NWrapper::w->mNNoObject->pointer<AdapterView>();
        if (b == -1 && c == 1) vcRet = (NReturn)NWrapper::w->mNNoObject->pointer<View>();
        if (b != -1) ((AdapterView::OnItemSelectedListener*)a)->onItemSelected((AdapterView*)b, (View*)c, (nint)d, (nlong)e);
        return vcRet;
    }

    // void onNothingSelected(AdapterView<?> parent)
    NReturn visit(NBeta03* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (b == -1 && c == 1) vcRet = (NReturn)NWrapper::w->mNNoObject->pointer<AdapterView>();
        if (b != -1) ((AdapterView::OnItemSelectedListener*)a)->onNothingSelected((AdapterView*)b);
        return vcRet;
    }

    //******************************************************************************************
    //*********************************** OnItemClickListener **********************************
    //******************************************************************************************
    // void onItemClick(AdapterView<?> parent, View view, int position, long id)
    NReturn visit(NGamma03* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (b == -1 && c == 2) vcRet = (NReturn)NWrapper::w->mNNoObject->pointer<AdapterView>();
        if (b == -1 && c == 1) vcRet = (NReturn)NWrapper::w->mNNoObject->pointer<View>();
        if (b != -1) ((AdapterView::OnItemSelectedListener*)a)->onItemSelected((AdapterView*)b, (View*)c, (nint)d, (nlong)e);
        return vcRet;
    }
};

} // END namespace

#endif
