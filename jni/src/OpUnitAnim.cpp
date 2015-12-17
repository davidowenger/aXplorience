#include "Common.h"
#include "Theme.h"

namespace NSDEVICE
{

OpUnitAnim::OpUnitAnim(Wrapper* const vWrapper)
    : OpUnit(vWrapper->mNWrapper), w(vWrapper), mIsARInitialized(false)
{
    w->mAREngine = new AREngine(w);
}

OpUnitAnim::~OpUnitAnim()
{
    delete w->mAREngine;

    if (mIsARInitialized) {
        w->maPOI.discard();

        delete w->mLocationManager;
        delete w->mGraphicsHandler;
        delete w->mCoordBuffer;
        delete w->mRotationBuffer;
    }
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
                sendOp(w->mOpUnitUIId, w->mNWrapper->mNKrossWrapper->mNDzeta00, vOp);
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

// AR Rendering
NReturn OpUnitAnim::visit(NBeta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    Op* vOp = nextOp();

    if (!mIsARInitialized) {
        nuint vPOIIndex;

        mIsARInitialized = true;
        w->mLocationManager = (LocationManager*)w->mNActivity->getSystemService(Context::LOCATION_SERVICE);
        w->mGraphicsHandler = new GraphicsHandler(w->mNWrapper);
        w->mCoordBuffer = new NConcurrentCircularBuffer<nfloat>(24);
        w->mRotationBuffer = new NConcurrentCircularBuffer<nfloat>(32);
        //TODO: link to a data source
        w->maPOI = NArray<BOPOI*>({
            new BOPOI(w, 46.521390, 6.628466, "Taco's Bar", ""),
            new BOPOI(w, 46.519865, 6.639356, "Chorus", ""),
            new BOPOI(w, 46.522417, 6.619248, "Les Docks", ""),
            new BOPOI(w, 46.521222, 6.627045, "Xoxo Club", ""),
            new BOPOI(w, 46.520137, 6.637671, "Bleu Lezard", ""),
            new BOPOI(w, 46.519973, 6.636507, "Le Bourg", ""),
            new BOPOI(w, 46.521796, 6.627189, "Mad Club", ""),
            new BOPOI(w, 46.520579, 6.567823, "Satellite", ""),
            new BOPOI(w, 46.526035, 6.580006, "Zelig", ""),
            new BOPOI(w, 46.520995, 6.631114, "D! Club", ""),
            new BOPOI(w, 46.522408, 6.634345, "La Giraf", ""),
            new BOPOI(w, 46.520204, 6.637295, "Buzz Club", ""),
            new BOPOI(w, 46.529604, 6.622984, "Beaulieu", ""),
            new BOPOI(w, 46.519403, 6.578746, "Centre sportif de Dorigny", ""),
            new BOPOI(w, 46.533306, 6.624165, "La Pontaise", "")
        });
        vPOIIndex = w->maPOI.mcData;
        w->mPOISortList = new NSortList<BOPOI,nfloat>();
        w->mPOISortList->resize(vPOIIndex);
        w->mcDisplayRotation = (4 - w->mDisplay->getRotation())%4;

        while (vPOIIndex--) {
            w->mPOISortList->setValue(w->maPOI[vPOIIndex], 0);
        }
        w->mOpUnitEvents->start();
        w->mAREngine->engineCreate();
    }
    sendOp(w->mOpUnitEventsId, w->mNWrapper->mNKrossWrapper->mNAlpha00, new Op());
    w->mAREngine->enginePlay();

    while (mAlive && vOp) {
        if (vOp->mNElement == w->mNWrapper->mNKrossWrapper->mNAlpha00) {
            if (vOp->a) {
                sendOp(w->mOpUnitUIId, w->mNWrapper->mNKrossWrapper->mNDzeta00, vOp);
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
