#ifndef __ParcelUuid_H__
#define __ParcelUuid_H__

namespace NSDEVICE
{

class ParcelUuid : public Object
{
friend NSNATIVE::NNoObject;

public:
	String toString()
	{
        NReturn index = NWrapper::w->mNVisitorOS->tRun(NWrapper::w->mNAlpha00, (NParam)this);
        return NWrapper::w->nFrame->tGetString(NWrapper::w->nFrame->tRunObject((NParam)index));
	}

private:
    ParcelUuid(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif
