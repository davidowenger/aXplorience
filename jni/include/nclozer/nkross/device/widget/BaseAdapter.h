#ifndef __BaseAdapter_H__
#define __BaseAdapter_H__

namespace NSDEVICE
{

class BaseAdapter : public SpinnerAdapter
{
friend NSNATIVE::NKrossFriend;

public:
    virtual ~BaseAdapter()
    {
    }

    //******************************************************************************************
    //********************************** BaseAdapter events ************************************
    //* This passes the call back to the default implementation if the method is not overriden *
    //******************************************************************************************
    virtual View* getDropDownView(int position, View* convertView, ViewGroup* parent)
    {
        View* b = NKrossWrapper::w->mNKrossFriend->pointer<View>();
        return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorWidget->tRun(NKrossWrapper::w->mNGamma00, (NParam)this, (NParam)b, (NParam)position, (NParam)convertView, (NParam)parent));
    }

protected:
    BaseAdapter()
    {
        NKrossWrapper::w->mNVisitorWidget->tRun(NKrossWrapper::w->mNBeta00, (NParam)this);
    }

private:
    BaseAdapter(NKrossFriend* vNKrossFriend) :
        SpinnerAdapter(vNKrossFriend)
    {
    }
};

} // End namespace

#endif
