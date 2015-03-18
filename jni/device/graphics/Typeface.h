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

    static const Typeface* DEFAULT;
    static const Typeface* DEFAULT_BOLD;
    static const Typeface* SANS_SERIF;
    static const Typeface* SERIF;
    static const Typeface* MONOSPACE;

    static Typeface* create(const String& familyName, int style)
    {
//        Typeface* vTypeface = NWrapper::w->mNNoObject->pointer<Typeface>();
//        NWrapper::w->mNVisitorGraphics->tRun(NWrapper::w->mNAlpha03, (NParam)vTypeface, NParamBox(NWrapper::w, familyName).n, (NParam)style);
//        return vTypeface;
    	return nullptr;
    }

    static Typeface* defaultFromStyle(int style)
    {
//        Typeface* vTypeface = NWrapper::w->mNNoObject->pointer<Typeface>();
//        NWrapper::w->mNVisitorGraphics->tRun(NWrapper::w->mNBeta03, (NParam)vTypeface, (NParam)style);
//        return vTypeface;
    	return nullptr;
    }

    virtual ~Typeface()
    {
        //FIXME
    }

protected:
    Typeface(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif
