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
    bool vGo;
    nint vChannel;
    BluetoothSocket* vBluetoothSocket;

    while (mAlive) {
        //LOGE("OpUnitServer::run");
        if (mWrapper->dBluetoothAdapter->getScanMode() == mWrapper->dBluetoothAdapter->SCAN_MODE_CONNECTABLE_DISCOVERABLE) {
            vGo = false;
            vChannel = -1;
            vBluetoothSocket = nullptr;
            mServerSocket = mWrapper->dBluetoothAdapter->listenUsingInsecureRfcommWithServiceRecord(mWrapper->sServiceName, mWrapper->sUuidService + mWrapper->sUuidSuffix);

            if (mServerSocket && mAlive) {
                vBluetoothSocket = mServerSocket->accept();
            }
            if (vBluetoothSocket) {
                vGo = (DBCollection*)sendOpForResult(0, mWrapper->mOpUnitCoreId, w->mNTau00, new OpParamForResult((NParam)vBluetoothSocket->getRemoteDevice()));
            }
            if (vGo) {
                LOGD(("Server accepted client with mac : #" + vBluetoothSocket->getRemoteDevice()->getAddress()).c_str());
                vChannel = mServerSocket->getChannel();
            }
            if (vGo && vChannel == -1) {
                vChannel = vBluetoothSocket->getPort();
            }
            if (mServerSocket) {
                mServerSocket->close();
            }
            if (vBluetoothSocket) {
                vBluetoothSocket->close();
                vBluetoothSocket = nullptr;
            }
            if (vChannel != -1) {
                mServerSocket = mWrapper->dBluetoothAdapter->listenUsingInsecureRfcommOn(vChannel);
            }
            if (vChannel != -1 && mServerSocket) {
                LOGD(("Server accepting client on channel : #" + to_string(vChannel)).c_str());
                vBluetoothSocket = mServerSocket->accept(7500);
                mServerSocket->close();
            }
            if (vBluetoothSocket) {
                LOGD(("Server accepted client on channel : #" + to_string(vChannel)).c_str());
                (DBCollection*)sendOp(0, mWrapper->mOpUnitCoreId, w->mNPhi00, new OpParam((NParam)vBluetoothSocket));
            }
        } else {
            LOGW("SERVER NOT DISCOVERABLE");
            if (mServerSocket) {
                mServerSocket->close();
                mServerSocket = nullptr;
            }
        }
        this_thread::sleep_for(mWrapper->mcSleep*50);
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
