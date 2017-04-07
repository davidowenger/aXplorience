#ifndef __Configuration_H__
#define __Configuration_H__

namespace NSDEVICE
{

class Configuration : public Object
{
friend NSNATIVE::NKrossFriend;

public:
    static const int ORIENTATION_LANDSCAPE = 0x00000002;
    static const int ORIENTATION_PORTRAIT = 0x00000001;

    virtual ~Configuration()
    {
    }

    virtual float getFontScale()
    {
        nlong vcValue = NKrossWrapper::w->mNVisitorContentRes->tRun(NKrossWrapper::w->mNAlpha00, (NParam)this);
        return (nfloat)*reinterpret_cast<ndouble*>(&vcValue);
    }

    virtual int getOrientation()
    {
        return (int)NKrossWrapper::w->mNVisitorContentRes->tRun(NKrossWrapper::w->mNDelta00, (NParam)this);
    }

    virtual int getScreenWidthDp()
    {
        return (int)NKrossWrapper::w->mNVisitorContentRes->tRun(NKrossWrapper::w->mNBeta00, (NParam)this);
    }

    virtual int getSmallestScreenWidthDp()
    {
        return (int)NKrossWrapper::w->mNVisitorContentRes->tRun(NKrossWrapper::w->mNGamma00, (NParam)this);
    }

private:
    Configuration(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
