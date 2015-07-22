#include "Common.h"

namespace NSDEVICE
{

OpUnitPeer::OpUnitPeer(Wrapper* const w, BluetoothSocket* dPeerSocket)
    : OpUnit(w), mUuid(), mBuffer(), mcTimeStampBroadcast(0), mcForce(0), mServerSocket(nullptr), mInputStream(nullptr), mOutputStream(nullptr), mDropHandler(nullptr),
      mOpUnitListener(nullptr), msMac(), mPeerSocket(dPeerSocket), mPeerDevice(nullptr)
{
    mcOrigin = 1;
    mcUnitType = Wrapper::OPUNIT_TYPE_PEER;
}

OpUnitPeer::OpUnitPeer(Wrapper* const w, BluetoothDevice* dPeerDevice)
    : OpUnit(w), mUuid(), mBuffer(), mcTimeStampBroadcast(0), mcForce(0), mServerSocket(nullptr), mInputStream(nullptr), mOutputStream(nullptr), mDropHandler(nullptr),
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
    if (mcOrigin == 1) {
        mPeerDevice = mPeerSocket->getRemoteDevice();
        msMac = mWrapper->opUnitCore->parseMac(mPeerDevice->getAddress());

//        mAlive &= (mPeerSocket != nullptr);
//
//        if (mAlive) {
//            // channel = mPeerSocket.getPort();
//            mPeerDevice = mPeerSocket->getRemoteDevice();
//            msMac = mWrapper->opUnitCore->parseMac(mPeerDevice->getAddress());
//            LOGD(("Server accepted client at : #" + msMac).c_str());
//            mPeerSocket->close();
//            mUuid = mWrapper->sUuidMacSuffix;
//            mUuid.insert(8, 1, '-').insert(4, 1, '-');
//            mUuid = mWrapper->sUuidPeer + mUuid + "-" + msMac;
//            // BluetoothServerSocket listenUsingRfcommOn(int channel)
//            mAlive &= ((mServerSocket = mWrapper->dBluetoothAdapter->listenUsingInsecureRfcommWithServiceRecord(mWrapper->sServiceName + " Second", mUuid)) != nullptr);
//        }
//        if (mAlive) {
//            LOGD(("Server accepting the client for 7.5 seconds on second UUID : #" + mUuid).c_str());
//            mAlive &= ((mPeerSocket = mServerSocket->accept(7500)) != nullptr);
//            mServerSocket->close();
//        }
    }
    if (mcOrigin == 2) {
        mAlive &= (mPeerDevice != nullptr);
        nint vChannel = -1;

        if (mAlive) {
            msMac = mWrapper->opUnitCore->parseMac(mPeerDevice->getAddress());

            if (msMac == "E02A82CF0845" || msMac == "680571EDCCBE" || msMac == "E4B021A5443F") {
                mAlive &= ((mPeerSocket = mPeerDevice->createInsecureRfcommSocketToServiceRecord(mWrapper->sUuidService + mWrapper->sUuidSuffix)) != nullptr);
            } else {
                mAlive &= false; //((mPeerSocket = mPeerDevice->createInsecureRfcommSocketToServiceRecord(mWrapper->sUuidService + "2222-0000-0000-000000000000")) != nullptr);
            }
        }
        if (mAlive) {
            LOGD(("Client trying server at address : #" + msMac).c_str());
            mAlive &= (mPeerSocket->connect() == 0);
            mAlive &= ((vChannel = mPeerSocket->getPort()) != -1);
            mPeerSocket->close();
        }
        if (mAlive) {
            LOGD(("Client trying server on channel : #" + to_string(vChannel)).c_str());
            mAlive &= ((mPeerSocket = mPeerDevice->createInsecureRfcommSocket(vChannel)) != nullptr);
        }
        if (mAlive) {
            this_thread::sleep_for(chrono::milliseconds(1500));
            mAlive &= (mPeerSocket->connect() == 0);
        }
        if (mAlive) {
            LOGD(("Client connected to server on channel : #" + to_string(vChannel)).c_str());
            mAlive &= (bool)sendOpForResult(0, mWrapper->mOpUnitCoreId, w->mNUpsilon00, new OpParamForResult((NParam)mPeerSocket->getRemoteDevice()));
        }
//        if (mAlive) {
//            LOGD(("Client trying server at : #" + msMac).c_str());
//            mAlive &= (mPeerSocket->connect() == 0);
//            mUuid = msMac;
//            mUuid.insert(8, 1, '-').insert(4, 1, '-');
//            mUuid = mWrapper->sUuidPeer + mUuid + "-" + mWrapper->sUuidMacSuffix;
//            mPeerSocket->close();
//        }
//        if (mAlive) {
//            mAlive &= ((mPeerSocket = mPeerDevice->createInsecureRfcommSocketToServiceRecord(mUuid)) != nullptr);
//        }
//        if (mAlive) {
//            this_thread::sleep_for(chrono::milliseconds(3500));
//            LOGD(("Client now trying second UUID on server : #" + mUuid).c_str());
//            mAlive &= (mPeerSocket->connect() == 0);
//        }
    }
    if (mAlive) {
        mAlive &= ((mOutputStream = mPeerSocket->getOutputStream()) != nullptr);
    }
    // Tell the Core Unit to restart discorvery ?
    sendOp(0, mWrapper->mOpUnitCoreId, w->mNKappa00, new OpMessage());
    if (mAlive) {
        LOGW(("Client/Server connection established with peer : #" + msMac).c_str());
        //this_thread::sleep_for(chrono::milliseconds(720)); // wait before read ?
        mInputStream = mPeerSocket->getInputStream();
        sendOp(0, mWrapper->mOpUnitCoreId, w->mNPi00, new OpParam((nlong)this, (nlong)mInputStream));
        handleOp();
        LOGW(("Lost Client/Server connection with peer : #" + msMac).c_str());
    }
    LOGD(("Connection canceled with Client or Server : #" + msMac).c_str());
    // Tell the Core Unit that the initialization ended
    sendOp(0, mWrapper->mOpUnitCoreId, w->mNRho00, new OpMessage(msMac));
    cancel();
}

void OpUnitPeer::handleOp()
{
    Op* op;
    String vPacket;
    TimeStamp vcTimeStampNow;
    DBCollection* vaMessage = nullptr;
    nint i = 0;

    while (mAlive) {
        vcTimeStampNow = system_clock::now().time_since_epoch().count();

        if (vcTimeStampNow - mcTimeStampBroadcast > mWrapper->mc10Secondes/11 && (!vaMessage || i == vaMessage->count())) {
            if (vaMessage) {
                delete vaMessage;
            }
            mcTimeStampBroadcast = vcTimeStampNow;
            vaMessage = (DBCollection*)sendOpForResult(0, mWrapper->mOpUnitUIId, w->mNOmicron00, new OpMessageForResult());
            i = 0;
        }
        if (vaMessage && i < vaMessage->count()) {
            vPacket = mWrapper->mBOHandlerMessage->pack(vaMessage->get(i++));
        } else {
            vPacket = "keep-alive=1";
        }
        write(vPacket);
        op = nextOp();

        if (op) {
            execOp(op);
            //Hint: use op->result here, before calling nextOp again
        }
        this_thread::sleep_for(mWrapper->mcSleep*16);
    }
}

// Receive from peer
NReturn OpUnitPeer::visit(NAlpha01* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    String vPacked;
    nint vcStart;
    nint vcEnd;
    mBuffer += ((OpMessage*)a)->mStringA;
    LOGD(("Data received from : #" + msMac).c_str());

    while (mAlive && (vcStart = mBuffer.find("2#")) >= 0) {
        mBuffer = mBuffer.substr(vcStart + 2);

        if ((vcEnd = mBuffer.find("3#")) >= 0) {
            LOGI(("Packed message received from : #" + msMac).c_str());
            vPacked = mBuffer.substr(0, vcEnd);
            mBuffer = mBuffer.substr(vcEnd + 2);
            sendOp(0, mWrapper->mOpUnitUIId, w->mNGamma00, new OpMessage(vPacked));
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
       LOGD("Peer stopping because listener stopped");
       mAlive = false;
   }
   return 0;
}

nint OpUnitPeer::write(String packet)
{
    //this_thread::sleep_for(chrono::milliseconds(1500));
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
    LOGD("Peer canceled");
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
