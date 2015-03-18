#include "Common.h"

namespace NSDEVICE
{

OpUnitPeer::OpUnitPeer(Wrapper* const w, BluetoothSocket* dPeerSocket)
    : OpUnit(w), mWrapper(w), mUuid(), mServerSocket(nullptr), mInputStream(nullptr), mOutputStream(nullptr), mDropHandler(nullptr), mOpUnitListener(nullptr), msMac()
{
    mcOrigin = 1;
    mPeerSocket = dPeerSocket;
    mPeerDevice = nullptr;
    mcUnitType = Wrapper::OPUNIT_TYPE_PEER;
}

OpUnitPeer::OpUnitPeer(Wrapper* const w, BluetoothDevice* dPeerDevice)
    : OpUnit(w), mWrapper(w), mUuid(), mServerSocket(nullptr), mInputStream(nullptr), mOutputStream(nullptr), mDropHandler(nullptr), mOpUnitListener(nullptr), msMac()
{
    mcOrigin = 2;
    mPeerSocket = nullptr;
    mPeerDevice = dPeerDevice;
    mcUnitType = Wrapper::OPUNIT_TYPE_PEER;
}

OpUnitPeer::~OpUnitPeer()
{
    if (mInputStream) {
        delete mInputStream;
    }
    if (mOutputStream) {
        delete mOutputStream;
    }
	if (mPeerDevice) {
		delete mPeerDevice;
	}
	if (mPeerSocket) {
		delete mPeerSocket;
	}
    if (mServerSocket) {
        delete mServerSocket;
    }
}

void OpUnitPeer::run()
{
    String vKey1 = String("");
    String vKey2 = String("");

    //********************************************************************//
    //**************** Critical Section Start : Discovery ****************//
    //********************************************************************//
    mWrapper->mMutexDiscovery.lock();
    mWrapper->dBluetoothAdapter->cancelDiscovery();

    if (mcOrigin == 1) {
        mAlive &= (mPeerSocket != nullptr);

        if (mAlive) {
            mPeerDevice = mPeerSocket->getRemoteDevice();
            msMac = mWrapper->opUnitCore->parseMac(mPeerDevice->getAddress());
            mPeerSocket->close();
            mUuid = mWrapper->sUuidMacSuffix;
            mUuid.insert(8, 1, '-').insert(4, 1, '-');
            mUuid = mWrapper->sUuidPeer + mUuid + "-" + msMac;
            mAlive &= ((mServerSocket = mWrapper->dBluetoothAdapter->listenUsingInsecureRfcommWithServiceRecord(mWrapper->sServiceName + " Second", mUuid)) != nullptr);
        }
        if (mAlive) {
            mAlive &= ((mPeerSocket = mServerSocket->accept(5000)) != nullptr);
            mServerSocket->close();
        }
    }
    if (mcOrigin == 2) {
        mAlive &= (mPeerDevice != nullptr);

        if (mAlive) {
            msMac = mWrapper->opUnitCore->parseMac(mPeerDevice->getAddress());
            mAlive &= ((mPeerSocket = mPeerDevice->createInsecureRfcommSocketToServiceRecord(mWrapper->sUuidService + mWrapper->sUuidSuffix)) != nullptr);
        }
        if (mAlive) {
            mAlive &= (mPeerSocket->connect() == 0);
            mUuid = msMac;
            mUuid.insert(8, 1, '-').insert(4, 1, '-');
            mUuid = mWrapper->sUuidPeer + mUuid + "-" + mWrapper->sUuidMacSuffix;
            mPeerSocket->close();
        }
        if (mAlive) {
            mAlive &= ((mPeerSocket = mPeerDevice->createInsecureRfcommSocketToServiceRecord(mUuid)) != nullptr);
        }
        if (mAlive) {
            mAlive &= (mPeerSocket->connect() == 0);
        }
    }
    if (mWrapper->mcTimeStampStop <= mWrapper->mcTimeStampStart) {
        mWrapper->dBluetoothAdapter->startDiscovery();
    }
    mWrapper->mMutexDiscovery.unlock();
    //********************************************************************//
    //**************** Critical Section Stop : Discovery *****************//
    //********************************************************************//

    if (mAlive) {
        mAlive &= ((mOutputStream = mPeerSocket->getOutputStream()) != nullptr);
    }
    if (mAlive) {
        string buffer = "";
        this_thread::sleep_for(chrono::milliseconds(1000)); // wait before read ?

        mInputStream = mPeerSocket->getInputStream();
        mWrapper->opSquad->add(new OpUnitListener(mWrapper, this, mInputStream))->start();
        mDropHandler = mWrapper->dbh->get("Drop");
        handleOp();
    }
    mWrapper->opUnitCore->maMac.erase(msMac);
    cancel();
}

// Receive from peer
NReturn OpUnitPeer::visit(NAlpha01* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    DBObject* vDBObject = mWrapper->mBOHandlerMessage->addDrop(((OpMessage*)a)->mString);
    mWrapper->aBODrop.push_back(vDBObject);
    w->dActivity->sendMessage((NParam)w->mNAlpha01, (NParam)vDBObject);
    return 0;
}

// Send data to this peer
NReturn OpUnitPeer::visit(NBeta01* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    write(((OpMessage*)a)->mString);
    return 0;
}

// Listener is dead
NReturn OpUnitPeer::visit(NAlpha03* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
   if (a == mIdUnique) {
       mAlive = false;
   }
   return 0;
}

// i want to terminate
//NReturn OpUnitPeer::visit(NBeta03* element, NParam a, NParam b, NParam c, NParam d, NParam e)
//{
//   mInputStream->close();
//   return 0;
//}

int OpUnitPeer::write(String packet)
{
    int error = mOutputStream->write(packet + "2#");

	if (error) {
        mInputStream->close();
	}
    return error;
}

void OpUnitPeer::cancel()
{
    if (mInputStream) {
        mInputStream->close();
    }
    if (mOutputStream) {
        mOutputStream->close();
    }
    if (mPeerSocket) {
        mPeerSocket->close();
    }
    if (mServerSocket) {
        mServerSocket->close();
    }
}

} // End namespace
