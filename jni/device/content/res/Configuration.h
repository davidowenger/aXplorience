#ifndef __Configuration_H__
#define __Configuration_H__

namespace NSDEVICE
{

class Configuration : public Object
{
friend NSNATIVE::NNoObject;

public:
    virtual ~Configuration()
    {
    }

    virtual float getFontScale()
    {
        int vcInt = (int)NWrapper::w->mNVisitorContentRes->tRun(NWrapper::w->mNAlpha00, (NParam)this);
        return *reinterpret_cast<float*>(&vcInt);
    }

    virtual int getScreenWidthDp()
    {
        return (int)NWrapper::w->mNVisitorContentRes->tRun(NWrapper::w->mNBeta00, (NParam)this);
    }

    virtual int getSmallestScreenWidthDp()
    {
        return (int)NWrapper::w->mNVisitorContentRes->tRun(NWrapper::w->mNGamma00, (NParam)this);
    }

private:
    Configuration(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif
