#include "Common.h"

namespace NSDEVICE
{

OpUnitPeer::OpUnitPeer(Wrapper* const vWrapper, BluetoothServerSocket* vBluetoothServerSocket, BluetoothSocket* vBluetoothSocket, BluetoothDevice* vBluetoothDevice, const String& vsMac)
    : OpUnit(vWrapper->mNWrapper),mConnected(false), mAliveListener(true), mcOrigin(1), mBuzzIndex(0), mUpdateIndex(0), mcInterruptDone(0), mcTimeStampBroadcast(0),
      w(vWrapper), maMessageAlive(nullptr), maMessageBuzz(nullptr), maMessageUpdate(nullptr),
      mBluetoothServerSocket(vBluetoothServerSocket), mBluetoothSocket(vBluetoothSocket), mInputStream(nullptr), mOutputStream(nullptr), mBluetoothDevice(vBluetoothDevice),
      msMac(vsMac)
{
    mcUnitType = OpUnit::OPUNIT_TYPE_PEER;
}

OpUnitPeer::OpUnitPeer(Wrapper* const vWrapper, BluetoothDevice* vBluetoothDevice, const String& vsMac)
    : OpUnit(vWrapper->mNWrapper), mConnected(false), mAliveListener(true), mcOrigin(2), mBuzzIndex(0), mUpdateIndex(0), mcInterruptDone(0), mcTimeStampBroadcast(0),
      w(vWrapper), maMessageAlive(nullptr), maMessageBuzz(nullptr), maMessageUpdate(nullptr),
      mBluetoothServerSocket(nullptr), mBluetoothSocket(nullptr), mInputStream(nullptr), mOutputStream(nullptr), mBluetoothDevice(vBluetoothDevice),
      msMac(vsMac)
{
    mcUnitType = OpUnit::OPUNIT_TYPE_PEER;
}

OpUnitPeer::~OpUnitPeer()
{
    if (mBluetoothDevice) {
        delete mBluetoothDevice;
    }
    if (mInputStream) {
        delete mInputStream;
    }
    if (mOutputStream) {
        delete mOutputStream;
    }
    if (mBluetoothSocket) {
        delete mBluetoothSocket;
    }
}

void OpUnitPeer::run()
{
    nint vChannel = -1;

    if (mcOrigin == 1) {
        LOGD(("Server accepted client with mac : #" + msMac).c_str());
        vChannel = mBluetoothServerSocket->getChannel();
        mBluetoothServerSocket->close();
        delete mBluetoothServerSocket;

        if (vChannel == -1) {
            vChannel = mBluetoothSocket->getPort();
        }
        mBluetoothSocket->close();

        mConnected = (vChannel != -1);

        if (mConnected) {
            mBluetoothServerSocket = w->dBluetoothAdapter->listenUsingInsecureRfcommOn(vChannel);
        }
        if (mConnected && mBluetoothServerSocket) {
            delete mBluetoothSocket;
            mBluetoothSocket = mBluetoothServerSocket->accept(7500);
            mConnected &= (mBluetoothSocket != nullptr);
            mBluetoothServerSocket->close();
            delete mBluetoothServerSocket;
        }
        // Unblock server
        sendOp(w->mOpUnitServerId, w->mNWrapper->mNKrossWrapper->mNAlpha00, new Op());

        if (mConnected) {
            LOGD(("Server connected to client on channel : #" + to_string(vChannel)).c_str());
        }
    }
    if (mcOrigin == 2) {
        LOGD(("Client trying server at address : #" + msMac).c_str());

        mConnected = ((mBluetoothSocket = mBluetoothDevice->createInsecureRfcommSocketToServiceRecord(w->sUuidService)) != nullptr);

        if (mConnected) {
            mConnected &= (mBluetoothSocket->connect() == 0);
            mConnected &= ((vChannel = mBluetoothSocket->getPort()) != -1);
            mBluetoothSocket->close();
        }
        if (mConnected) {
            delete mBluetoothSocket;
            mConnected &= ((mBluetoothSocket = mBluetoothDevice->createInsecureRfcommSocket(vChannel)) != nullptr);
            this_thread::sleep_for(1500*w->mMili);
            mConnected &= (mBluetoothSocket->connect() == 0);
        }
        if (mConnected) {
            LOGD(("Client connected to server on channel : #" + to_string(vChannel)).c_str());
        }
    }
    if (mConnected) {
        mConnected &= ((mOutputStream = mBluetoothSocket->getOutputStream()) != nullptr);
        mConnected &= ((mInputStream = mBluetoothSocket->getInputStream()) != nullptr);
    }
    // Initialization ended, now try to register the connection
    sendOp(w->mOpUnitCoreId, w->mNWrapper->mNKrossWrapper->mNGamma00, new OpMessage(msMac, "", "", "", "", (NParam)this, mcOrigin, mConnected));

    if (mConnected) {
        mConnected = false;
        handleOp();

        if (mConnected) {
            mAlive = true;
            sendOp(w->mOpUnitCoreId, w->mNWrapper->mNKrossWrapper->mNEta00, new OpMessage(msMac));
        }
    }
    if (mInputStream) {
        mInputStream->close();
    }
    if (mOutputStream) {
        mOutputStream->close();
    }
    if (mBluetoothSocket) {
        mBluetoothSocket->close();
    }
    if (mConnected) {
        LOGW(("Lost Client/Server connection with peer : #" + msMac).c_str());
        while (mAliveListener) {
            this_thread::sleep_for(200*w->mMili);
        };
    }
    LOGD("Peer canceled");
}

void OpUnitPeer::handleOp()
{
    Op* op;
    TimeStamp vcTimeStampNow;

    maMessageAlive = w->maMessageAlive;
    maMessageBuzz = w->maMessageBuzz;
    maMessageUpdate = w->maMessageUpdate;
    mBuzzIndex = maMessageBuzz->mSize;
    mUpdateIndex = maMessageUpdate->mSize;

    while (mAlive && mUpdateIndex == maMessageUpdate->mSize && mBuzzIndex == maMessageBuzz->mSize) {
        this_thread::sleep_for(200*w->mMili);
        op = nextOp();

        if (op) {
            execOp(op);
        }
    }
    while (mAlive) {
        vcTimeStampNow = system_clock::now().time_since_epoch().count();

        while (mBuzzIndex != maMessageBuzz->mHeadIndex) {
            mBuzzIndex = (mBuzzIndex + 1)%maMessageBuzz->mSize;
            write(*(maMessageBuzz->read(mBuzzIndex)));
            ++mcInterruptDone;
        }
        if (!w->mIsInterrupted && mcInterruptDone == w->mcInterrupt && mUpdateIndex != maMessageUpdate->mHeadIndex) {
            mUpdateIndex = (mUpdateIndex + 1)%maMessageUpdate->mSize;
            write(*(maMessageUpdate->read(mUpdateIndex)));
        }
        if (!w->mIsInterrupted && mcInterruptDone == w->mcInterrupt && vcTimeStampNow - mcTimeStampBroadcast > 15*w->mc1Seconde) {
            mcTimeStampBroadcast = vcTimeStampNow;
            write(*(maMessageAlive->readHead()));
        }
        this_thread::sleep_for(200*w->mMili);
    }
}

void OpUnitPeer::write(const String& packet)
{
    LOGI(("Sending packed message: #" + packet + " to #" + msMac).c_str());
    nint error = mOutputStream->write(packet);

    if (error) {
        LOGE(("Peer error on writing to : #" + msMac).c_str());
        mAlive = false;
    }
}

// Register connection
NReturn OpUnitPeer::visit(NAlpha00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    mConnected = (bool)a;

    if (!mConnected) {
        mAlive = false;
    }
    if (mConnected) {
        LOGW(("Client/Server connection established with peer : #" + msMac).c_str());
    }
    return 0;
}

// Begin communication
NReturn OpUnitPeer::visit(NBeta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    write(*(String*)a);
    mUpdateIndex = b;
    mBuzzIndex = c;
    mcInterruptDone = d;
    delete (String*)a;
    return 0;
}

} // End namespace
