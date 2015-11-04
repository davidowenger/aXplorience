#ifndef __Display_H__
#define __Display_H__

namespace NSDEVICE
{

class Display : public Object
{
friend NSNATIVE::NKrossFriend;

public:
    virtual ~Display()
    {
    }

    int getRotation()
    {
        return NSNKROSS::w->mNVisitorView->tRun(NSNKROSS::w->mNXi00, (NParam)this);
    }

private:
    Display(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
