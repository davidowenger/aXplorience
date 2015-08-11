#include "Common.h"

namespace NSDEVICE
{

OpUnitServer::OpUnitServer(Wrapper* w)
    : OpUnit(w), mIsFirst(true), mWrapper(w), mBluetoothSocket(nullptr), mBluetoothServerSocket(nullptr)
{
}

OpUnitServer::~OpUnitServer()
{
}

void OpUnitServer::run()
{
    sendOp(mWrapper->mOpUnitServerId, w->mNAlpha00, new Op());
    handleOp();
    cancel();
}

void OpUnitServer::cancel()
{
    mAlive = false;

    if (mBluetoothServerSocket) {
        mBluetoothServerSocket->close();
    }
}

NReturn OpUnitServer::visit(NAlpha00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
{
    if (mWrapper->mcBTState == 2) {
        mBluetoothSocket = nullptr;
        mBluetoothServerSocket = mWrapper->dBluetoothAdapter->listenUsingInsecureRfcommWithServiceRecord(mWrapper->sServiceName, mWrapper->sUuidService + mWrapper->mac);

        if (mBluetoothServerSocket && mAlive) {
            LOGD("Server is listening");
            mBluetoothSocket = mBluetoothServerSocket->accept();
            LOGD("Server stopped");
        }
        if (mBluetoothSocket) {
            sendOp(mWrapper->mOpUnitCoreId, w->mNDelta00, new OpParam((NParam)mBluetoothServerSocket, (NParam)mBluetoothSocket));
            mBluetoothServerSocket = nullptr;
        } else {
            sendOp(mWrapper->mOpUnitServerId, w->mNAlpha00, new Op());
        }
        if (mBluetoothServerSocket) {
            mBluetoothServerSocket->close();
            delete mBluetoothServerSocket;
        }
    } else {
        sendOp(mWrapper->mOpUnitServerId, w->mNAlpha00, new Op());
    }
    return 0;
}

} // End namespace
