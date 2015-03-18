#ifndef __DisplayMetrics_H__
#define __DisplayMetrics_H__

namespace NSDEVICE
{

class DisplayMetrics : public Object
{
friend NSNATIVE::NNoObject;

public:
    DisplayMetrics()
    {
    }

    virtual ~DisplayMetrics()
    {
    }

    virtual float getDensity()
    {
        long vcX = NWrapper::w->mNVisitorUtil->tRun(NWrapper::w->mNAlpha00, (NParam)this);
        return (float)(*reinterpret_cast<double*>(&vcX));
    }

private:
    DisplayMetrics(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif