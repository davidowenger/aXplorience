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
        DisplayMetrics* b = NSNKROSS::w->mNKrossFriend->pointer<DisplayMetrics>();
        return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorContentRes->tRun(NSNKROSS::w->mNAlpha01, (NParam)this, (NParam)b));
    }

    virtual Configuration* getConfiguration()
    {
        Configuration* b = NSNKROSS::w->mNKrossFriend->pointer<Configuration>();
        return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorContentRes->tRun(NSNKROSS::w->mNBeta01, (NParam)this, (NParam)b));
    }

    virtual Drawable* getDrawable(const String& vString)
    {
        Drawable* b = NSNKROSS::w->mNKrossFriend->pointer<Drawable>();
        return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorContentRes->tRun(NSNKROSS::w->mNGamma01, (NParam)this, (NParam)b, NKrossParam(vString).n));
    }

private:
    Resources(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
