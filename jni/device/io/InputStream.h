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
		return NWrapper::w->nVisitorBluetooth->tRun(NWrapper::w->alpha00, (NParam)this);
	}

    int read(string& buffer, int cMaxByte)
    {
		int err = (int)NWrapper::w->nVisitorIO->tRun(NWrapper::w->beta00, (NParam)this, (NParam)cMaxByte);

		if (err >= 0) {
			int cByte = NWrapper::w->nFrame->tRun(NWrapper::w->gamma00, (NParam)err, (NParam)-1, (NParam)-1);

			while (--cByte >= 0) {
				buffer += (char)NWrapper::w->nFrame->tRun(NWrapper::w->gamma00, (NParam)err, (NParam)cByte, (NParam)-1);
			}
			err = 0;
		}
		return err;
	}
};

} // End namespace

#endif
