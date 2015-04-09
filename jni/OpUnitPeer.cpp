#include "Common.h"

namespace NSDEVICE
{

OpUnitPeer::OpUnitPeer(Wrapper* const w, BluetoothSocket* dPeerSocket)
    : OpUnit(w), mWrapper(w), mUuid(), mBuffer(), mcTimeStampBroadcast(0), mcForce(0), mServerSocket(nullptr), mInputStream(nullptr), mOutputStream(nullptr), mDropHandler(nullptr),
      mOpUnitListener(nullptr), msMac(), mPeerSocket(dPeerSocket), mPeerDevice(nullptr)
{
    mcOrigin = 1;
    mcUnitType = Wrapper::OPUNIT_TYPE_PEER;
}

OpUnitPeer::OpUnitPeer(Wrapper* const w, BluetoothDevice* dPeerDevice)
    : OpUnit(w), mWrapper(w), mUuid(), mBuffer(), mcTimeStampBroadcast(0), mcForce(0), mServerSocket(nullptr), mInputStream(nullptr), mOutputStream(nullptr), mDropHandler(nullptr),
      mOpUnitListener(nullptr), msMac(), mPeerSocket(nullptr), mPeerDevice(dPeerDevice)
{
    mcOrigin = 2;
    mcUnitType = Wrapper::OPUNIT_TYPE_PEER;
}

OpUnitPeer::~OpUnitPeer()
{
//    if (mInputStream) {
//        delete mInputStream;
//    }
//    if (mOutputStream) {
//        delete mOutputStream;
//    }
//	if (mPeerDevice) {
//		delete mPeerDevice;
//	}
//	if (mPeerSocket) {
//		delete mPeerSocket;
//	}
//    if (mServerSocket) {
//        delete mServerSocket;
//    }
}

void OpUnitPeer::run()
{
    String vKey1 = String("");
    String vKey2 = String("");

    if (mcOrigin == 1) {
        mAlive &= (mPeerSocket != nullptr);

        if (mAlive) {
            mPeerDevice = mPeerSocket->getRemoteDevice();
            msMac = mWrapper->opUnitCore->parseMac(mPeerDevice->getAddress());
            LOGV(("Server accepted client at : #" + msMac).c_str());
            mPeerSocket->close();
            mUuid = mWrapper->sUuidMacSuffix;
            mUuid.insert(8, 1, '-').insert(4, 1, '-');
            mUuid = mWrapper->sUuidPeer + mUuid + "-" + msMac;
            mAlive &= ((mServerSocket = mWrapper->dBluetoothAdapter->listenUsingInsecureRfcommWithServiceRecord(mWrapper->sServiceName + " Second", mUuid)) != nullptr);
        }
        if (mAlive) {
            LOGV(("Server accepting the client for 7.5 seconds on second UUID : #" + mUuid).c_str());
            mAlive &= ((mPeerSocket = mServerSocket->accept(7500)) != nullptr);
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
            LOGV(("Client trying server at : #" + msMac).c_str());
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
            //LOGE("Client accepted on server - now waiting for remote peer to establish");
            //this_thread::sleep_for(chrono::milliseconds(30000));
            LOGV(("Client now trying second UUID on server : #" + mUuid).c_str());
            mAlive &= (mPeerSocket->connect() == 0);
        }
    }
    if (mAlive) {
        mAlive &= ((mOutputStream = mPeerSocket->getOutputStream()) != nullptr);
    }
    // Tell the Core Unit to restart discorvery ?
    if (mAlive) {
        LOGW(("Client/Server connection established with peer : #" + msMac).c_str());
        //this_thread::sleep_for(chrono::milliseconds(720)); // wait before read ?
        mInputStream = mPeerSocket->getInputStream();
        mWrapper->opSquad->add(new OpUnitListener(mWrapper, this, mInputStream))->start();
        mDropHandler = mWrapper->dbh->get("Drop");
        handleOp();
        LOGW(("Lost Client/Server connection with peer : #" + msMac).c_str());
    }
    LOGV(("Connection canceled with Client or Server : #" + msMac).c_str());
    // Tell the Core Unit that the initialization ended
    sendOp(0, mWrapper->mOpUnitCoreId, w->mNKappa00, new OpMessage(msMac));
    cancel();
}

void OpUnitPeer::handleOp()
{
    Op* op;
    nint i = 0;
    TimeStamp vcTimeStampNow;
    DBObject* vMessage;

    while (mAlive) {
        vcTimeStampNow = steady_clock::now().time_since_epoch().count();

        if (vcTimeStampNow - mcTimeStampBroadcast > mWrapper->mc10Secondes || mWrapper->opUnitCore->mcForce != mcForce) {
            mcTimeStampBroadcast = vcTimeStampNow;
            mcForce = mWrapper->opUnitCore->mcForce;
            DBCollection* vaMessage = (DBCollection*)sendOpForResult(0, mWrapper->mOpUnitCoreId, w->mNLambda00, new OpMessageForResult());

            for (i = 0 ; i < vaMessage->count() ; ++i) {
                vMessage = vaMessage->get(i);

                if (vMessage->is("in") && vcTimeStampNow - vMessage->count("date") > 12*mWrapper->mc10Secondes) {
                    sendOp(0, mWrapper->mOpUnitCoreId, w->mNNu00, new OpParam(vMessage->count("id"), true));
                } else {
                    write(mWrapper->mBOHandlerMessage->pack(vMessage));
                }
            }
            delete vaMessage;
        }
        op = nextOp();

        if (op) {
            execOp(op);
            //Hnint: use op->result here, before calling nextOp again
        } else {
            this_thread::sleep_for(chrono::milliseconds(300));
        }
    }
}

// Receive from peer
NReturn OpUnitPeer::visit(NAlpha01* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    String vPacked;
    nint vcStart;
    nint vcEnd;
    mBuffer += ((OpMessage*)a)->mStringA;

    while (mAlive && (vcStart = mBuffer.find("2#")) >= 0) {
        mBuffer = mBuffer.substr(vcStart + 2);

        if ((vcEnd = mBuffer.find("3#")) >= 0) {
            LOGI(("Packed message received from : #" + msMac).c_str());
            vPacked = mBuffer.substr(0, vcEnd);
            mBuffer = mBuffer.substr(vcEnd + 2);
            sendOp(0, mWrapper->mOpUnitCoreId, w->mNGamma00, new OpMessage(vPacked));
        }
    }
    return 0;
}

// Send data to this peer
NReturn OpUnitPeer::visit(NBeta01* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    write(((OpMessage*)a)->mStringA);
    return 0;
}

// Listener is dead
NReturn OpUnitPeer::visit(NAlpha03* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
   if (a == mIdUnique) {
       LOGV("Peer stopping because listener stopped");
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

nint OpUnitPeer::write(String packet)
{
    LOGI(("Sending packed message to : #" + msMac).c_str());
    nint error = mOutputStream->write("2#" + packet + "3#");

	if (error) {
        LOGE(("Peer error on writing to : #" + msMac).c_str());
        mInputStream->close();
	}
    return error;
}

void OpUnitPeer::cancel()
{
    LOGV("Peer canceled");
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
