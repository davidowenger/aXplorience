#include "Common.h"

namespace NSDEVICE
{

OpUnitListener::OpUnitListener(Wrapper* const w, OpUnit* vOpUnit, InputStream* vInputStream)
	: OpUnit(w), mWrapper(w)
{
    mOpUnitId = vOpUnit->mId;
    mOpUnitIdUnique = vOpUnit->mIdUnique;
	mInputStream = vInputStream;
	mcUnitType = Wrapper::OPUNIT_TYPE_LISTENER;
}

OpUnitListener::~OpUnitListener()
{
}

void OpUnitListener::run()
{
    int vcStart;
    mAlive &= (mInputStream != nullptr);
    String vBuffer = String("");
    String vPacket = String("");

    while (mAlive) {
        vcStart = 0;

    	if (!mAlive || mInputStream->read(vBuffer, 1024)) {
    	    mAlive = false;
    	}
        if (mAlive && vBuffer.length()) {
            while ((vcStart = vBuffer.find("2#")) >= 0) {
                vPacket = vBuffer.substr(0, vcStart);
                vBuffer = vBuffer.substr(vcStart + 2);

                if (vcStart > 0) {
                    sendOp(mOpUnitId, mWrapper->w->mNAlpha01, new OpMessage(vPacket));
                }
            }
        }
        this_thread::sleep_for(chrono::milliseconds(300));
    }
	cancel();
    sendOp(mOpUnitId, mWrapper->w->mNAlpha03, new OpParam(mOpUnitIdUnique));
}

void OpUnitListener::cancel()
{
	mAlive = false;
	mInputStream->close();
}

} // End namespace
