#include "Common.h"
#include "Theme.h"

namespace NSDEVICE
{

OpUnitAnim::OpUnitAnim(Wrapper* const w)
    : OpUnit(w)
{
}

OpUnitAnim::~OpUnitAnim()
{
}

void OpUnitAnim::run()
{
    Op* vOp;

    while (mAlive) {
        vOp = mOpSquad->maConcurrentQueue[mId][mWrapper->mOpUnitUIId]->next();

        if (vOp) {
            LOGD("******* TILTING *******");
            nuint i;
            nuint j;
            nuint vcSleep;
            nuint vaAnim[3] = {3,5,0};

            mWrapper->mNActivity->sendMessage((NParam)(new Op(w->mNEpsilon01, mWrapper->maColor[1])));
            vcSleep = 0;

            while (mAlive && vcSleep < 3 && mWrapper->mNActivity->mState != mWrapper->maColor[1]) {
                this_thread::sleep_for(chrono::milliseconds(120));
                ++vcSleep;
            }
            this_thread::sleep_for(chrono::milliseconds(360 - 120*vcSleep));

            for (j = 0 ; j < 3 ; ++j) {
                nuint index = vaAnim[j]*3 + 6;
                mWrapper->mNActivity->sendMessage((NParam)(new Op(w->mNEpsilon01, mWrapper->maColor[1])));
                vcSleep = 0;

                while (mAlive && vcSleep < 2 && mWrapper->mNActivity->mState != mWrapper->maColor[1]) {
                    this_thread::sleep_for(chrono::milliseconds(10));
                    ++vcSleep;
                }
                this_thread::sleep_for(chrono::milliseconds(20 - 10*vcSleep));

                for (i = index ; i < index + 3 ; ++i) {
                    mWrapper->mNActivity->sendMessage((NParam)(new Op(w->mNEpsilon01, mWrapper->maColor[i])));
                    vcSleep = 0;

                    while (mAlive && vcSleep < 2 && mWrapper->mNActivity->mState != mWrapper->maColor[i]) {
                        this_thread::sleep_for(chrono::milliseconds(10));
                        ++vcSleep;
                    }
                    this_thread::sleep_for(chrono::milliseconds(20 - 10*vcSleep));
                }
                this_thread::sleep_for(chrono::milliseconds(260));
            }
            this_thread::sleep_for(chrono::milliseconds(420));

            mWrapper->mNActivity->sendMessage((NParam)(new Op(w->mNEpsilon01, mWrapper->maColor[1])));
            vcSleep = 0;

            while (mAlive && vcSleep < 3 && mWrapper->mNActivity->mState != mWrapper->maColor[1]) {
                this_thread::sleep_for(chrono::milliseconds(120));
                ++vcSleep;
            }
            this_thread::sleep_for(chrono::milliseconds(360 - 120*vcSleep));
            mWrapper->mNActivity->sendMessage((NParam)(new Op(w->mNEpsilon01, mWrapper->maColor[Theme::kColorApplicationBackground])));

            while (mAlive && vOp) {
                if (vOp->a) {
                    sendOp(mWrapper->mOpUnitUIId, w->mNDzeta00, vOp);
                } else {
                    delete vOp;
                }
                vOp = mOpSquad->maConcurrentQueue[mId][mWrapper->mOpUnitUIId]->next();
            }
        }
        this_thread::sleep_for(chrono::milliseconds(200));
    }
}

} // End namespace
