#ifndef __SpinnerAdapter_H__
#define __SpinnerAdapter_H__

namespace NSDEVICE
{

class BaseAdapter;

class SpinnerAdapter : public Adapter
{
friend BaseAdapter;

public:
    virtual ~SpinnerAdapter()
    {
    }

    virtual View* getDropDownView(int position, View* convertView, ViewGroup* parent) = 0;

protected:
    SpinnerAdapter()
    {
    }

private:
    SpinnerAdapter(NKrossFriend* vNKrossFriend) :
        Adapter(vNKrossFriend)
    {
    }
};

} // End namespace

#endif
