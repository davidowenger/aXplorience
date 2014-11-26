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
		return NSDEVICE::Activity::kActivity->w->nVisitorBluetooth->tRun(NSDEVICE::Activity::kActivity->w->alpha01, (NParam)this);
	}

    int write(const string& packet)
    {
		return NSDEVICE::Activity::kActivity->w->nVisitorBluetooth->tRun(NSDEVICE::Activity::kActivity->w->beta01, (NParam)this, NParamBox(NSDEVICE::Activity::kActivity->w, packet).n);
    }
};

} // End namespace

#endif
