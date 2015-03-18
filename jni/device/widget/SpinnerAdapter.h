#ifndef __SpinnerAdapter_H__
#define __SpinnerAdapter_H__

namespace NSDEVICE
{

class SpinnerAdapter : public Adapter
{
friend NSNATIVE::NNoObject;

protected:
    SpinnerAdapter()
    {
    }

public:
	virtual ~SpinnerAdapter()
    {
    }

    virtual View* getDropDownView(int position, View convertView, ViewGroup parent) = 0;
};

} // End namespace

#endif
