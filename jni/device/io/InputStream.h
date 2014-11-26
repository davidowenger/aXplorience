#ifndef __InputStream_H__
#define __InputStream_H__

namespace NSDEVICE
{

class InputStream
{
friend class NSNATIVE::NVisitorIO;

public:
	int close()
	{
		return NSDEVICE::Activity::kActivity->w->nVisitorBluetooth->tRun(NSDEVICE::Activity::kActivity->w->alpha00, (NParam)this);
	}

    int read(string& buffer, int cMaxByte)
    {
		int err = (int)NSDEVICE::Activity::kActivity->w->nVisitorIO->tRun(NSDEVICE::Activity::kActivity->w->beta00, (NParam)this, (NParam)cMaxByte);

		if (err >= 0) {
			int cByte = NSDEVICE::Activity::kActivity->w->nFrame->tRun(NSDEVICE::Activity::kActivity->w->gamma00, (NParam)err, (NParam)-1, (NParam)-1);

			while (--cByte >= 0) {
				buffer += (char)NSDEVICE::Activity::kActivity->w->nFrame->tRun(NSDEVICE::Activity::kActivity->w->gamma00, (NParam)err, (NParam)cByte, (NParam)-1);
			}
			err = 0;
		}
		return err;
	}
};

} // End namespace

#endif
