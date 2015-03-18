#ifndef __NVisitorWidget_H__
#define __NVisitorWidget_H__

namespace NSNATIVE
{

class NVisitorWidget : public NVisitor
{
public:
	NVisitorWidget(NWrapper* w)
		: NVisitor(w)
	{
	}

   ~NVisitorWidget()
	{
	}

    //*******************************************************************************************
    //********************************** BaseAdapter events *************************************
    //*******************************************************************************************
    // int getCount()
    virtual long visit(NAlpha01* element, long a, long b, long c, long d, long e)
    {
        return ((BaseAdapter*)a)->getCount();
    }

    // View getDropDownView(int position, View convertView, ViewGroup parent)
    virtual long visit(NBeta01* element, long a, long b, long c, long d, long e)
    {
        NReturn vcRet = 0;
        if (b == -1 && c == 2) vcRet = (NReturn)NWrapper::w->mNNoObject->pointer<View>();
        if (b == -1 && c == 1) vcRet = (NReturn)NWrapper::w->mNNoObject->pointer<ViewGroup>();
        if (b != -1) vcRet = (NReturn)((BaseAdapter*)a)->getDropDownView((int)b, (View*)c, (ViewGroup*)d);
        return vcRet;
    }

    // Object getItem(int position)
    virtual long visit(NGamma01* element, long a, long b, long c, long d, long e)
    {
        return (NReturn)((BaseAdapter*)a)->getItem((int)b);
    }

    // long getItemId(int position)
    virtual long visit(NDelta01* element, long a, long b, long c, long d, long e)
    {
        return (NReturn)((BaseAdapter*)a)->getItemId((int)b);
    }

    // View getView(int position, View convertView, ViewGroup parent)
    virtual long visit(NEpsilon01* element, long a, long b, long c, long d, long e)
    {
        NReturn vcRet = 0;
        if (b == -1 && c == 2) vcRet = (NReturn)NWrapper::w->mNNoObject->pointer<View>();
        if (b == -1 && c == 1) vcRet = (NReturn)NWrapper::w->mNNoObject->pointer<ViewGroup>();
        if (b != -1) vcRet = (NReturn)((BaseAdapter*)a)->getView((int)b, (View*)c, (ViewGroup*)d);
        return vcRet;
    }
};

} // END namespace

#endif
