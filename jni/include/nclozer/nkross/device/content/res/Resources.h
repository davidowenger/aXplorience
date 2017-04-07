#ifndef __Resources_H__
#define __Resources_H__

namespace NSDEVICE
{

class Resources : public Object
{
friend NSNATIVE::NKrossFriend;

public:
    virtual ~Resources()
    {
    }

    virtual DisplayMetrics* getDisplayMetrics()
    {
        DisplayMetrics* b = NKrossWrapper::w->mNKrossFriend->pointer<DisplayMetrics>();
        return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorContentRes->tRun(NKrossWrapper::w->mNAlpha01, (NParam)this, (NParam)b));
    }

    virtual Configuration* getConfiguration()
    {
        Configuration* b = NKrossWrapper::w->mNKrossFriend->pointer<Configuration>();
        return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorContentRes->tRun(NKrossWrapper::w->mNBeta01, (NParam)this, (NParam)b));
    }

    virtual Drawable* getDrawable(const String& vString)
    {
        Drawable* b = NKrossWrapper::w->mNKrossFriend->pointer<Drawable>();
        return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorContentRes->tRun(NKrossWrapper::w->mNGamma01, (NParam)this, (NParam)b, NKrossParam(vString).n));
    }

private:
    Resources(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
