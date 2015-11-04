#include "Common.h"

namespace NSDEVICE
{

OpUnitListener::OpUnitListener(Wrapper* const vWrapper, OpUnitPeer* vOpUnitPeer)
    : OpUnit(vWrapper->mNWrapper), w(vWrapper), mBuffer()
{
    mOpUnitPeer = vOpUnitPeer;
    mInputStream = vOpUnitPeer->mInputStream;
    mcUnitType = OpUnit::OPUNIT_TYPE_LISTENER;
}

OpUnitListener::~OpUnitListener()
{
}

void OpUnitListener::run()
{
    String vBuffer;
    nint error;

    while (mAlive) {
        this_thread::sleep_for(200*w->mMili);
        vBuffer.assign("");
        error = mInputStream->read(vBuffer, 0, 2048);

        if (error < 0) {
            LOGE(("Listener error while reading : " + to_string(error)).c_str());
            mAlive = false;
        }
        if (mAlive && vBuffer.length()) {
            String vPacked;
            nint vcStart;
            nint vcEnd;
            mBuffer += regex_replace(vBuffer, regex("2#3#"), String(""));
            LOGI("Data received");

            if (mAlive && (vcStart = mBuffer.find("2#")) >= 0 && (vcEnd = mBuffer.rfind("3#")) >= 0 && vcStart < vcEnd) {
                sendOp(w->mOpUnitUIId, w->mNWrapper->mNKrossWrapper->mNGamma00, new OpMessage(mBuffer.substr(vcStart, vcEnd + 2 - vcStart)));
                mBuffer = mBuffer.substr(vcEnd + 2);
            }
        }
    }
    LOGD("Listener stopping");
    mOpUnitPeer->mOutputStream->close();

    // Allow Peer thread to stop
    mOpUnitPeer->mAliveListener = false;
}

} // End namespace
