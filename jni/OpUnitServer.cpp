#include "Common.h"

namespace NSDEVICE
{

OpUnitServer::OpUnitServer(Wrapper* w)
	: OpUnit(w), mWrapper(w)
{
	mServerSocket = nullptr;
}

OpUnitServer::~OpUnitServer()
{
    if (mServerSocket) {
        delete mServerSocket;
    }
}

void OpUnitServer::run()
{
    BluetoothSocket* vBluetoothSocket;

    while (mAlive) {
        if (mWrapper->dBluetoothAdapter->getScanMode() == mWrapper->dBluetoothAdapter->SCAN_MODE_CONNECTABLE_DISCOVERABLE) {
            vBluetoothSocket = nullptr;

            if ((mServerSocket = mWrapper->dBluetoothAdapter->listenUsingInsecureRfcommWithServiceRecord(mWrapper->sServiceName, mWrapper->sUuidService + mWrapper->sUuidSuffix)) != nullptr) {
                while (mAlive && !vBluetoothSocket) {
                    vBluetoothSocket = mServerSocket->accept();
                }
                if (vBluetoothSocket) {
                    sendOp(0, mWrapper->opUnitCore->mId, mWrapper->w->mNBeta00, new OpParam((NParam)vBluetoothSocket));
                }
                mServerSocket->close();
            }
        } else {
            LOGW("SERVER NOT DISCOVERABLE : now waiting 15 seconds");
            this_thread::sleep_for(chrono::milliseconds(15000));
        }
    }
}

void OpUnitServer::cancel()
{
    mAlive = false;

    if (mServerSocket) {
        mServerSocket->close();
    }
}

} // End namespace
