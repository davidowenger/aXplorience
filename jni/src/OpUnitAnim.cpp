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
        w->maPOICoord.discard();
        w->maPOILabel.discard();

        delete w->mLocationManager;
        delete w->mGraphicsHandler;
        delete w->maDeviceCoord;
        delete w->maRotation;
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
        nuint i = 0;
        NArray<nfloat> vaPOILocation = NArray<nfloat>({
            46.5183910, 6.6305800,
            46.5271310, 6.6517860,
            46.5223740, 6.6343880,
            46.5071060, 6.6265730,
            46.5252710, 6.6340880,
            46.5228050, 6.5794420,
            46.5082340, 6.6241910,
            46.5165130, 6.6258520,
            46.5481160, 6.5537010,
            46.5195300, 6.6313710,
            46.5195300, 6.6313710
        });
        nfloat* vaPOILocationData = vaPOILocation.maData;

        mIsARInitialized = true;
        w->mLocationManager = (LocationManager*)w->mNActivity->getSystemService(Context::LOCATION_SERVICE);
        w->maDeviceCoord = new NConcurrentCircularScalarBuffer<nfloat>(24);
        w->maRotation = new NConcurrentCircularScalarBuffer<nfloat>(32);
        w->mGraphicsHandler = new GraphicsHandler(w->mNWrapper);
        w->mcDisplayRotation = (4 - w->mDisplay->getRotation())%4;
        w->maPOICoord = NArray<nfloat>(vaPOILocation.mcData*2);
        w->maPOICoordData = w->maPOICoord.maData;
        w->maPOILabel = NArray<String>({
            "Yatus - Lausanne", "",
            "Brasserie de Chailly Lausanne", "",
            "Giraf restaurant Vieux-Lausanne", "",
            "La Riviera Lausanne-Ouchy", "",
            "Lausanne-Moudon", "",
            "Restaurant de Dorigny", "",
            "Mövenpick-Ouchy", "",
            "Restaurant Le Milan", "",
            "Restaurant les Arcades", "",
            "Brasserie du Grand-Chêne", "",
            "La Table d'Edgard", ""
        });
        for (i = 0 ; i < w->maPOICoord.mcData/4 ; ++i) {
            w->maPOICoordData[4*i + 0] = cos((ndouble)vaPOILocationData[2*i + 0]/180*w->mcPi)*cos((ndouble)vaPOILocationData[2*i + 1]/180*w->mcPi);
            w->maPOICoordData[4*i + 1] = cos((ndouble)vaPOILocationData[2*i + 0]/180*w->mcPi)*sin((ndouble)vaPOILocationData[2*i + 1]/180*w->mcPi);
            w->maPOICoordData[4*i + 2] = sin((ndouble)vaPOILocationData[2*i + 0]/180*w->mcPi);
            w->maPOICoordData[4*i + 3] = 1.0;
        }
        vaPOILocation.discard();
        w->mOpUnitEvents->start();
        w->mAREngine->engineCreate();
    }
    sendOp(w->mOpUnitEventsId, w->mNWrapper->mNKrossWrapper->mNAlpha00, new Op());
    w->mAREngine->engineStart();

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
