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
        delete mDisplayMetrics;
        delete mConfiguration;
    }

    virtual DisplayMetrics* getDisplayMetrics()
    {
        NWrapper::w->mNVisitorContentRes->tRun(NWrapper::w->mNAlpha01, (NParam)this, (NParam)mDisplayMetrics);
        return mDisplayMetrics;
    }

    virtual Configuration* getConfiguration()
    {
        NWrapper::w->mNVisitorContentRes->tRun(NWrapper::w->mNBeta01, (NParam)this, (NParam)mConfiguration);
        return mConfiguration;
    }

    virtual Drawable* getDrawable(int id)
    {
        Drawable* vDrawable = NWrapper::w->mNNoObject->pointer<Drawable>();
        bool error = NWrapper::w->mNVisitorContentRes->tRun(NWrapper::w->mNGamma01, (NParam)this, (NParam)vDrawable, (NParam)id);

        if (error) {
            delete vDrawable;
            vDrawable = nullptr;
        }
        return vDrawable;
    }

private:
    DisplayMetrics* mDisplayMetrics;
    Configuration* mConfiguration;

    Resources(NNoObject* vNNoObject)
    {
        init();
    }

    void init()
    {
        mDisplayMetrics = NWrapper::w->mNNoObject->pointer<DisplayMetrics>();
        mConfiguration = NWrapper::w->mNNoObject->pointer<Configuration>();
    }
};

} // End namespace

#endif
