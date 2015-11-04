#include "Common.h"

namespace NSDEVICE
{

OpUnitServer::OpUnitServer(Wrapper* vWrapper)
    : OpUnit(vWrapper->mNWrapper), mIsFirst(true), w(vWrapper), mBluetoothSocket(nullptr), mBluetoothServerSocket(nullptr)
{
}

OpUnitServer::~OpUnitServer()
{
}

void OpUnitServer::run()
{
    sendOp(w->mOpUnitServerId, w->mNWrapper->mNKrossWrapper->mNAlpha00, new Op());
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
    if (w->mcBTState == 2) {
        mBluetoothSocket = nullptr;
        mBluetoothServerSocket = w->dBluetoothAdapter->listenUsingInsecureRfcommWithServiceRecord(w->sServiceName, w->sUuidService + w->mac);

        if (mBluetoothServerSocket && mAlive) {
            LOGD("Server is listening");
            mBluetoothSocket = mBluetoothServerSocket->accept();
            LOGD("Server stopped");
        }
        if (mBluetoothSocket) {
            sendOp(w->mOpUnitCoreId, w->mNWrapper->mNKrossWrapper->mNDelta00, new OpParam((NParam)mBluetoothServerSocket, (NParam)mBluetoothSocket));
            mBluetoothServerSocket = nullptr;
        } else {
            sendOp(w->mOpUnitServerId, w->mNWrapper->mNKrossWrapper->mNAlpha00, new Op());
        }
        if (mBluetoothServerSocket) {
            mBluetoothServerSocket->close();
            delete mBluetoothServerSocket;
        }
    } else {
        sendOp(w->mOpUnitServerId, w->mNWrapper->mNKrossWrapper->mNAlpha00, new Op());
    }
    return 0;
}

} // End namespace
