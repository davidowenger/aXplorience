#ifndef __BaseAdapter_H__
#define __BaseAdapter_H__

namespace NSDEVICE
{

class BaseAdapter : public SpinnerAdapter
{
friend NSNATIVE::NNoObject;

protected:
    BaseAdapter()
    {
        NWrapper::w->mNVisitorWidget->tRun(NWrapper::w->mNBeta00, (NParam)this);
    }

public:
	virtual ~BaseAdapter()
    {
    }

    //******************************************************************************************
    //********************************** BaseAdapter events ************************************
    //* This passes the call back to the default implementation if the method is not overriden *
    //******************************************************************************************
    View* getDropDownView(int position, View* convertView, ViewGroup* parent)
    {
        View* vView = NWrapper::w->mNNoObject->pointer<View>();
        View* vRet = (View*)NWrapper::w->mNVisitorWidget->tRun(NWrapper::w->mNGamma00, (NParam)this, (NParam)vView, (NParam)position, (NParam)convertView, (NParam)parent);
        if (!vRet) delete vView;
        return vRet;
    }
};

} // End namespace

#endif
