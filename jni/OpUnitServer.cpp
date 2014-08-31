#include "Common.h"

namespace NSDEVICE
{

OpUnitServer::OpUnitServer(Wrapper* w)
	: OpUnit(w), w(w)
{
	mClientSocket = nullptr;
	mServerSocket = nullptr;
	mInputStream = nullptr;
	mOutputStream = nullptr;
	mAlive = false;
}

OpUnitServer::~OpUnitServer()
{
}

void OpUnitServer::run()
{
	int i = 0;
	int error = 0;
	unsigned long long nextUuid = 0;
	string buffer("");
	//if (mAlive && mode == w->dBluetoothAdapter->SCAN_MODE_CONNECTABLE_DISCOVERABLE && !w->OpUnitServer->mAlive) {

    while (mAlive) {
		error = 0;
    	buffer = "";
		mClientSocket = nullptr;
		mServerSocket = w->dBluetoothAdapter->listenUsingInsecureRfcommWithServiceRecord(w->sServiceName, w->sUuid + w->sUuidSuffix);

		while (mAlive && mServerSocket && !mClientSocket) {
			mClientSocket = mServerSocket->accept();
		}
		if (mServerSocket) {
			mServerSocket->close();
		}
		if (mClientSocket) {
			error = mClientSocket->connect();
		}
		if (error) {
			mClientSocket->close();
			mClientSocket = nullptr;
		}
		if (!mClientSocket) {
			error = 1;
		}
		if (!error) {
			mInputStream = mClientSocket->getInputStream();
			mOutputStream = mClientSocket->getOutputStream();
			error = !mInputStream || !mOutputStream;
		}
		if (w->cNextClientUuid > w->cNextServerUuid) {
			w->cNextServerUuid = w->cNextClientUuid;
		}
		if (!error) {
			error = mOutputStream->write(to_string(w->cNextServerUuid));
		}
		if (!error) {
			error = mInputStream->read(buffer, 1024);
		}
		if (!error) {
			error = to_long(buffer, nextUuid) || nextUuid > 999999999999;
		}
		if (!error && nextUuid > w->cNextServerUuid) {
			w->cNextServerUuid = nextUuid;
		}
		if (!error) {
			buffer = to_string(w->cNextServerUuid);
			buffer = w->sUuidSuffix.substr(0, 12 - buffer.length()) + buffer;
			mClientSocket = nullptr;
			mServerSocket = w->dBluetoothAdapter->listenUsingInsecureRfcommWithServiceRecord(w->sServiceName, w->sUuid + buffer);

			while (mAlive && mServerSocket && !mClientSocket) {
				mClientSocket = mServerSocket->accept();
			}
			if (mServerSocket) {
				mServerSocket->close();
			}
			if (mClientSocket) {
				error = mClientSocket->connect();
			}
			if (mClientSocket && error) {
				mClientSocket->close();
				mClientSocket = nullptr;
			}
			if (mClientSocket) {
				OpUnitPeer* peer = new OpUnitPeer(w, mClientSocket, w->cNextServerUuid++);
				w->opSquad->add(peer);
				w->aPeer[peer->mId] = peer;
				peer->start();
			}
		}
    }
}

void OpUnitServer::cancel()
{
	mAlive = false;
}

} // End namespace
