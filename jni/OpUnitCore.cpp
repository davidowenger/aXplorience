#include "Common.h"

namespace NSDEVICE
{

OpUnitCore::OpUnitCore(Wrapper* const w)
	: OpUnit(w), mWrapper(w), mcProcessedDevice(0), mcTimeStampBroadcast(0), maMac()
{
}

OpUnitCore::~OpUnitCore()
{
    delete mWrapper->dbh;
    delete mWrapper->mBOHandlerMessage;
    delete[] mWrapper->aPeer;
}

void OpUnitCore::run()
{
	//00000000-0000-07da-0000-0000000007d0
    //00001101-0000-1000-8000-00805F9B34FB
	//UUID(2010L,2000L);

    int i;

    mWrapper->aDiscoveredDevice = Col<BluetoothDevice*>();
    mWrapper->aBODrop = vector<DBObject*>();

    mWrapper->mcTimeStampStart = 0;
    mWrapper->mcTimeStampStop = steady_clock::now().time_since_epoch().count();

    mWrapper->dbh = new DBHandler(mWrapper);
	mWrapper->dbh->add<Table_Drop>("Drop");

	mWrapper->mBOHandlerMessage = new BOHandlerMessage(mWrapper);
	mWrapper->opUnitServer = new OpUnitServer(mWrapper);
	mWrapper->aPeer = new OpUnitPeer*[mWrapper->cMaxOpUnit];

    mWrapper->mBOHandlerMessage->h->drop();
    mWrapper->aBOSeed  = mWrapper->mBOHandlerMessage->getSeeds();
    mWrapper->mac = mWrapper->dBluetoothAdapter->getAddress();
	mWrapper->sServiceName = "Proximity service";
	mWrapper->sUuidService = "0000F9B3-";
	mWrapper->sUuidPeer = "0000F9B4-";
	mWrapper->sUuidSuffix = "0000-0000-0000-000000000000";
    mWrapper->sUuidMacSuffix = parseMac(mWrapper->mac);

    if (mWrapper->aBOSeed->count() == 0) {
        DBObject* vDBObject;
        vDBObject = mWrapper->mBOHandlerMessage->addSeed("1", "Outbound Title 1", "Outbound Text 1");
        LOGE(vDBObject->get("title").c_str());
        delete vDBObject;
        vDBObject = mWrapper->mBOHandlerMessage->addSeed("2", "Outbound Title 2", "Outbound Text 2");
        LOGE(vDBObject->get("text").c_str());
        delete vDBObject;
        mWrapper->aBOSeed  = mWrapper->mBOHandlerMessage->getSeeds();
    }
	for ( i = 0 ; i < mWrapper->cMaxOpUnit ; ++i ) {
		mWrapper->aPeer[i] = nullptr;
	}
	mWrapper->dBluetoothAdapter->enable();
    mWrapper->dBluetoothAdapter->discoverable();
    mWrapper->opSquad->add(mWrapper->opUnitServer)->start();

    //********************************************************************//
    //**************** Critical Section Start : Discovery ****************//
    //********************************************************************//
    mWrapper->mMutexDiscovery.lock();
    mWrapper->dBluetoothAdapter->startDiscovery();
    mWrapper->mMutexDiscovery.unlock();
    //********************************************************************//
    //**************** Critical Section Stop : Discovery *****************//
    //********************************************************************//

	handleOp();

    //********************************************************************//
    //**************** Critical Section Start : Discovery ****************//
    //********************************************************************//
    mWrapper->mMutexDiscovery.lock();
    mWrapper->dBluetoothAdapter->cancelDiscovery();
    mWrapper->mMutexDiscovery.unlock();
    //********************************************************************//
    //**************** Critical Section Stop : Discovery *****************//
    //********************************************************************//

    cancel();
}

void OpUnitCore::handleOp()
{
    Op* op;
    int i = 0;
    int j = 0;
    TimeStamp vc10Secondes = chrono::duration_cast<steady_clock::duration>(chrono::seconds(10)).count();
    TimeStamp vcTimeStampNow;

    while (mAlive) {
        vcTimeStampNow = steady_clock::now().time_since_epoch().count();

        if (vcTimeStampNow - mcTimeStampBroadcast > vc10Secondes) {
            mcTimeStampBroadcast = vcTimeStampNow;

            for (i = 0 ; i < mWrapper->aBOSeed->count() ; ++i) {
                String vString = mWrapper->mBOHandlerMessage->pack(mWrapper->aBOSeed->get(i));

                for (j = 0 ; j < mWrapper->opSquad->mcMaxOpUnit ; ++j) {
                    if (mWrapper->opSquad->maOpUnitType[j] == Wrapper::OPUNIT_TYPE_PEER) {
                        OpCallback* cb = sendOp(j, w->mNBeta01, new OpMessageForResult(vString));
                    }
                }
            }
        }
        op = nextOp();

        if (op) {
            execOp(op);
            //HINT: use op->result here, before calling nextOp again
        } else {
            //TODO: check if condition needed
            //if (mWrapper->dBluetoothAdapter->isEnabled()) {
            //********************************************************************//
            //**************** Critical Section Start : Discovery ****************//
            //********************************************************************//
            mWrapper->mMutexDiscovery.lock();
            if (vcTimeStampNow - mWrapper->mcTimeStampStop > 1*vc10Secondes && vcTimeStampNow - mWrapper->mcTimeStampStart > 6*vc10Secondes) {
                mWrapper->mcTimeStampStart = vcTimeStampNow;
                mWrapper->dBluetoothAdapter->startDiscovery();
            }
            if (vcTimeStampNow - mWrapper->mcTimeStampStart > 5*vc10Secondes && vcTimeStampNow - mWrapper->mcTimeStampStop > 6*vc10Secondes) {
                mWrapper->mcTimeStampStop = vcTimeStampNow;
                mWrapper->dBluetoothAdapter->cancelDiscovery();
            }
            mWrapper->mMutexDiscovery.unlock();
            //********************************************************************//
            //**************** Critical Section Stop : Discovery *****************//
            //********************************************************************//
            this_thread::sleep_for(chrono::milliseconds(300));
        }
    }
}

// Add a new peer received from server
NReturn OpUnitCore::visit(NAlpha00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    BluetoothDevice* vBluetoothDevice = (BluetoothDevice*)a;
    bool vIsAlive = (vBluetoothDevice != nullptr);

    if (vIsAlive) {
        vIsAlive &= maMac.emplace(parseMac(vBluetoothDevice->getAddress())).second;
    }
    if (vIsAlive) {
        mWrapper->opSquad->add(new OpUnitPeer(mWrapper, vBluetoothDevice))->start();
    }
    return 0;
}

// Add a new peer received from server
NReturn OpUnitCore::visit(NBeta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    BluetoothSocket* vBluetoothSocket = (BluetoothSocket*)a;
    bool vIsAlive = (vBluetoothSocket != nullptr);

    if (vIsAlive) {
        vIsAlive &= maMac.emplace(parseMac(vBluetoothSocket->getRemoteDevice()->getAddress())).second;
    }
    if (vIsAlive) {
        mWrapper->opSquad->add(new OpUnitPeer(mWrapper, vBluetoothSocket))->start();
    }
    return 0;
}

String OpUnitCore::parseMac(const String& vMac)
{
    String vMacParsed;
//    try {
//      vMacParsed = regex_replace(vMac,regex("[^0123456789abcdefABCDEF]+"),String(""));
//    }
//    catch (regex_error& vError) {
//        std::cerr << "Regex error with code: #" << (int)vError.code() << "\n";
//    }
    vMacParsed = vMac;
    return vMacParsed;
}

void OpUnitCore::cancel()
{
	mAlive = false;
}

} // End namespace
