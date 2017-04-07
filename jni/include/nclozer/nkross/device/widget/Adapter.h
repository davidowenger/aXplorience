#ifndef __Adapter_H__
#define __Adapter_H__

namespace NSDEVICE
{

class SpinnerAdapter;

class Adapter
{
friend SpinnerAdapter;

public:
    virtual ~Adapter()
    {
        NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNDelta00, (NParam)this);
    }

    virtual int getCount() = 0;
    virtual Object* getItem(int position) = 0;
    virtual long long int getItemId(int position) = 0;
    virtual View* getView(int position, View* convertView, ViewGroup* parent) = 0;

protected:
    Adapter()
    {
    }

private:
    Adapter(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
