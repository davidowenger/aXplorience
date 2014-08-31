#ifndef __OutputStream_H__
#define __OutputStream_H__

namespace NSDEVICE
{

class OutputStream
{
friend class NSNATIVE::NVisitorIO;

public:
	int close()
	{
		return NWrapper::w->nVisitorBluetooth->tRun(NWrapper::w->alpha01, (NParam)this);
	}

    int write(const string& packet)
    {
		return NWrapper::w->nVisitorBluetooth->tRun(NWrapper::w->beta01, (NParam)this, NParamBox(NWrapper::w, packet).n);
    }
};

} // End namespace

#endif
