#include "Common.h"
#include "Theme.h"

namespace NSDEVICE
{

OpUnitAnim::OpUnitAnim(Wrapper* const vWrapper)
    : OpUnit(vWrapper->mNWrapper), w(vWrapper)
{
}

OpUnitAnim::~OpUnitAnim()
{
}

void OpUnitAnim::run()
{
    Op* vOp;

    while (mAlive) {
        vOp = nextOp();

        if (vOp) {
            execOp(vOp);
        }
        this_thread::sleep_for(chrono::milliseconds(200));
    }
}

// TILTING
NReturn OpUnitAnim::visit(NAlpha00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    LOGD("******* TILTING *******");
    nuint i;
    nuint j;
    nuint vcSleep;
    Op* vOp = nextOp();
    nuint vaAnim[3] = {3,5,0};

    w->mNActivity->sendMessage((NParam)(new Op(w->mNWrapper->mNKrossWrapper->mNEpsilon01, w->maColor[1])));
    vcSleep = 0;

    while (mAlive && vcSleep < 3 && w->mNActivity->mState != w->maColor[1]) {
        this_thread::sleep_for(chrono::milliseconds(120));
        ++vcSleep;
    }
    this_thread::sleep_for(chrono::milliseconds(360 - 120*vcSleep));

    for (j = 0 ; j < 3 ; ++j) {
        nuint index = vaAnim[j]*3 + 6;
        w->mNActivity->sendMessage((NParam)(new Op(w->mNWrapper->mNKrossWrapper->mNEpsilon01, w->maColor[1])));
        vcSleep = 0;

        while (mAlive && vcSleep < 2 && w->mNActivity->mState != w->maColor[1]) {
            this_thread::sleep_for(chrono::milliseconds(10));
            ++vcSleep;
        }
        this_thread::sleep_for(chrono::milliseconds(20 - 10*vcSleep));

        for (i = index ; i < index + 3 ; ++i) {
            w->mNActivity->sendMessage((NParam)(new Op(w->mNWrapper->mNKrossWrapper->mNEpsilon01, w->maColor[i])));
            vcSleep = 0;

            while (mAlive && vcSleep < 2 && w->mNActivity->mState != w->maColor[i]) {
                this_thread::sleep_for(chrono::milliseconds(10));
                ++vcSleep;
            }
            this_thread::sleep_for(chrono::milliseconds(20 - 10*vcSleep));
        }
        this_thread::sleep_for(chrono::milliseconds(260));
    }
    this_thread::sleep_for(chrono::milliseconds(420));

    w->mNActivity->sendMessage((NParam)(new Op(w->mNWrapper->mNKrossWrapper->mNEpsilon01, w->maColor[1])));
    vcSleep = 0;

    while (mAlive && vcSleep < 3 && w->mNActivity->mState != w->maColor[1]) {
        this_thread::sleep_for(chrono::milliseconds(120));
        ++vcSleep;
    }
    this_thread::sleep_for(chrono::milliseconds(360 - 120*vcSleep));
    w->mNActivity->sendMessage((NParam)(new Op(w->mNWrapper->mNKrossWrapper->mNEpsilon01, w->maColor[Theme::kColorApplicationBackground])));

    while (mAlive && vOp) {
        if (vOp->mNElement == w->mNWrapper->mNKrossWrapper->mNAlpha00) {
            if (vOp->a) {
                sendOp(w->mOpUnitDBId, w->mNWrapper->mNKrossWrapper->mNDzeta00, vOp);
            } else {
                delete vOp;
            }
            vOp = nextOp();
        } else {
            this_thread::sleep_for(chrono::milliseconds(200));
            execOp(vOp);
            vOp = nullptr;
        }
    }
    return 0;
}

} // End namespace
