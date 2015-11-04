#ifndef __NVisitorLocation_H__
#define __NVisitorLocation_H__

namespace NSNATIVE
{

class NVisitorLocation : public NKrossVisitor
{
public:
    NVisitorLocation(NWrapper* w)
        : NKrossVisitor(w)
    {
    }

    virtual ~NVisitorLocation()
    {
    }

    //*******************************************************************************************
    //**************************************** TLocationListener ********************************
    //*******************************************************************************************
    //void onLocationChanged(Location* location)
    NReturn visit(NAlpha00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (b == -1 && c == 1) vcRet = (NReturn)mNWrapper->mNKrossWrapper->mNKrossFriend->pointer<Location>();
        if (b != -1) ((LocationListener*)a)->onLocationChanged((Location*)b);
        return vcRet;
    }

    //void onProviderDisabled(const String& provider)
    NReturn visit(NBeta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        ((LocationListener*)a)->onProviderDisabled(mNWrapper->mNKrossWrapper->mNKrossSystem->tGetString(mNWrapper->mNKrossWrapper->mNKrossSystem->tRunObject(b)));
        return 0;
    }

    //void onProviderEnabled(const String& provider)
    NReturn visit(NGamma00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        ((LocationListener*)a)->onProviderEnabled(mNWrapper->mNKrossWrapper->mNKrossSystem->tGetString(mNWrapper->mNKrossWrapper->mNKrossSystem->tRunObject(b)));
        return 0;
    }

    //void onStatusChanged(const String& provider, int status, Bundle* extras)
    NReturn visit(NDelta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (b == -1 && c == 1) vcRet = (NReturn)mNWrapper->mNKrossWrapper->mNKrossFriend->pointer<Bundle>();
        if (b != -1) ((LocationListener*)a)->onStatusChanged(mNWrapper->mNKrossWrapper->mNKrossSystem->tGetString(mNWrapper->mNKrossWrapper->mNKrossSystem->tRunObject(b)), (int)c, (Bundle*)d);
        return vcRet;
    }

};

} // END namespace

#endif
