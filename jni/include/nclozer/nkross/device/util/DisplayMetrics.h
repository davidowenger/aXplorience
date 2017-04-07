#ifndef __DisplayMetrics_H__
#define __DisplayMetrics_H__

namespace NSDEVICE
{

class DisplayMetrics : public Object
{
friend NSNATIVE::NKrossFriend;

public:
    DisplayMetrics()
    {
    }

    virtual ~DisplayMetrics()
    {
    }

    virtual float getDensity()
    {
        nlong vcValue = NKrossWrapper::w->mNVisitorUtil->tRun(NKrossWrapper::w->mNAlpha00, (NParam)this);
        return (nfloat)*reinterpret_cast<ndouble*>(&vcValue);
    }

private:
    DisplayMetrics(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
