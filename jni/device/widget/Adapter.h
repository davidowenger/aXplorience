#ifndef __Adapter_H__
#define __Adapter_H__

namespace NSDEVICE
{

class Adapter
{
friend NSNATIVE::NNoObject;

protected:
    Adapter()
    {
    }

public:
    virtual ~Adapter()
    {
        NWrapper::w->nFrame->tRun(NWrapper::w->mNDelta00, (NParam)this);
    }

    virtual int getCount() = 0;
    virtual Object* getItem(int position) = 0;
    virtual long getItemId(int position) = 0;
    virtual View* getView(int position, View* convertView, ViewGroup* parent) = 0;
};

} // End namespace

#endif
