#ifndef __Typeface_H__
#define __Typeface_H__

namespace NSDEVICE
{

class Typeface : public Object
{
friend NSNATIVE::NNoObject;

public:
    static const int NORMAL = 0;
    static const int BOLD = NORMAL + 1;
    static const int ITALIC = BOLD + 1;
    static const int BOLD_ITALIC = ITALIC + 1;

    static Typeface* DEFAULT;
    static Typeface* DEFAULT_BOLD;
    static Typeface* SANS_SERIF;
    static Typeface* SERIF;
    static Typeface* MONOSPACE;

    static Typeface* create(const String& familyName, int style)
    {
        Typeface* b = NWrapper::w->mNNoObject->pointer<Typeface>();
        return NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->mNVisitorGraphics->tRun(NWrapper::w->mNGamma00, (NParam)b, NParamBox(NWrapper::w, familyName).n, (NParam)style));
    }

    static Typeface* defaultFromStyle(int style)
    {
        Typeface* b = NWrapper::w->mNNoObject->pointer<Typeface>();
        return NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->mNVisitorGraphics->tRun(NWrapper::w->mNDelta00, (NParam)b, (NParam)style));
    }

    virtual ~Typeface()
    {
    }

protected:
    Typeface(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif
