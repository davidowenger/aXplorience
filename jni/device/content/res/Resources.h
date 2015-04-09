#ifndef __Resources_H__
#define __Resources_H__

namespace NSDEVICE
{

class Resources : public Object
{
friend NSNATIVE::NNoObject;

public:
    virtual ~Resources()
    {
    }

    virtual DisplayMetrics* getDisplayMetrics()
    {
        DisplayMetrics* b = NWrapper::w->mNNoObject->pointer<DisplayMetrics>();
        return NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->mNVisitorContentRes->tRun(NWrapper::w->mNAlpha01, (NParam)this, (NParam)b));
    }

    virtual Configuration* getConfiguration()
    {
        Configuration* b = NWrapper::w->mNNoObject->pointer<Configuration>();
        return NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->mNVisitorContentRes->tRun(NWrapper::w->mNBeta01, (NParam)this, (NParam)b));
    }

    virtual Drawable* getDrawable(const String& vString)
    {
        Drawable* b = NWrapper::w->mNNoObject->pointer<Drawable>();
        return NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->mNVisitorContentRes->tRun(NWrapper::w->mNGamma01, (NParam)this, (NParam)b, NParamBox(NWrapper::w, vString).n));
    }

private:
    Resources(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif
