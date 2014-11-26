#include "Common.h"

namespace NSDEVICE
{

OpUnitServer::OpUnitServer(Wrapper* w)
	: OpUnit(w), mw(w)
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
	String buffer("");
	//if (mAlive && mode == w->dBluetoothAdapter->SCAN_MODE_CONNECTABLE_DISCOVERABLE && !w->OpUnitServer->mAlive) {

    while (mAlive) {
		error = 0;
    	buffer = "";
		mClientSocket = nullptr;
		mServerSocket = ((Wrapper*)w)->dBluetoothAdapter->listenUsingInsecureRfcommWithServiceRecord(((Wrapper*)w)->sServiceName, ((Wrapper*)w)->sUuid + ((Wrapper*)w)->sUuidSuffix);

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
		if (((Wrapper*)w)->cNextClientUuid > ((Wrapper*)w)->cNextServerUuid) {
			((Wrapper*)w)->cNextServerUuid = ((Wrapper*)w)->cNextClientUuid;
		}
		if (!error) {
			error = mOutputStream->write(to_string(((Wrapper*)w)->cNextServerUuid));
		}
		if (!error) {
			error = mInputStream->read(buffer, 1024);
		}
		if (!error) {
			error = to_long(buffer, nextUuid) || nextUuid > 999999999999;
		}
		if (!error && nextUuid > ((Wrapper*)w)->cNextServerUuid) {
			((Wrapper*)w)->cNextServerUuid = nextUuid;
		}
		if (!error) {
			buffer = to_string(((Wrapper*)w)->cNextServerUuid);
			buffer = ((Wrapper*)w)->sUuidSuffix.substr(0, 12 - buffer.length()) + buffer;
			mClientSocket = nullptr;
			mServerSocket = ((Wrapper*)w)->dBluetoothAdapter->listenUsingInsecureRfcommWithServiceRecord(((Wrapper*)w)->sServiceName, ((Wrapper*)w)->sUuid + buffer);

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
				OpUnitPeer* peer = new OpUnitPeer(((Wrapper*)w), mClientSocket, ((Wrapper*)w)->cNextServerUuid++);
				((Wrapper*)w)->opSquad->add(peer);
				((Wrapper*)w)->aPeer[peer->mId] = peer;
				peer->start();
			}
		}
    	this_thread::sleep_for(chrono::milliseconds(300));
    }
}

void OpUnitServer::cancel()
{
	mAlive = false;
}

} // End namespace
