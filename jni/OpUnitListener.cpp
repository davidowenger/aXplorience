#include "Common.h"

namespace NSDEVICE
{

OpUnitListener::OpUnitListener(Wrapper* const w, OpUnit* vOpUnit, InputStream* vInputStream)
	: OpUnit(w), mBuffer()
{
    mOpUnitId = vOpUnit->mId;
    mOpUnitIdUnique = vOpUnit->mIdUnique;
	mInputStream = vInputStream;
	mcUnitType = Wrapper::OPUNIT_TYPE_LISTENER;
	mOpUnitCoreId = mWrapper->opUnitCore->mId;
}

OpUnitListener::~OpUnitListener()
{
}

void OpUnitListener::run()
{
    mAlive &= (mInputStream != nullptr);
    String vBuffer;
    nint error;

    while (mAlive) {
        //LOGE("OpUnitListener::run");
        vBuffer.assign("");
        error = mInputStream->read(vBuffer, 0, 256);

    	if (error < 0) {
    	    LOGE(("Listener error while reading : " + to_string(error)).c_str());
    	    mAlive = false;
    	}
        if (mAlive && vBuffer.length()) {
            sendOp(0, mOpUnitId, mWrapper->w->mNAlpha01, new OpMessage(vBuffer));
        }
        this_thread::sleep_for(mWrapper->mcSleep*16);
    }
	cancel();
    LOGD("Listener stopping");
    sendOp(0, mOpUnitId, mWrapper->w->mNAlpha03, new OpParam(mOpUnitIdUnique));
}

void OpUnitListener::cancel()
{
    LOGD("Listener canceled");
	mAlive = false;
	mInputStream->close();
}

} // End namespace
