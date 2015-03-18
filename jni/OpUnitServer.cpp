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
    while (mAlive) {
        //FIXME
        //if ( mode == w->dBluetoothAdapter->SCAN_MODE_CONNECTABLE_DISCOVERABLE) {
    	BluetoothSocket* vBluetoothSocket = nullptr;
		mServerSocket = mWrapper->dBluetoothAdapter->listenUsingInsecureRfcommWithServiceRecord(mWrapper->sServiceName, mWrapper->sUuidService + mWrapper->sUuidSuffix);

		while (mAlive && mServerSocket && !vBluetoothSocket) {
			vBluetoothSocket = mServerSocket->accept();
		}
		if (mServerSocket) {
			mServerSocket->close();
		}
        if (mAlive && vBluetoothSocket) {
            sendOp(mWrapper->opUnitCore->mId, mWrapper->w->mNBeta00, new OpParam((NParam)vBluetoothSocket));
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
