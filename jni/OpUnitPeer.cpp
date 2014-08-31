#include "Common.h"

namespace NSDEVICE
{

OpUnitPeer::OpUnitPeer(Wrapper* w, BluetoothSocket* dPeerSocket, int cUuid)
	: OpUnit(w), w(w)
{
    mcUuid = cUuid;
	mPeerSocket = dPeerSocket;
	mPeerDevice = mPeerSocket->getRemoteDevice();
	mInputStream = mPeerSocket->getInputStream();
	mOutputStream = mPeerSocket->getOutputStream();
    mDropHandler = w->dbh->get("Drop");
	mcProcessedPacket = 0;
	mAlive = false;
}

OpUnitPeer::~OpUnitPeer()
{
	if (mInputStream) {
		delete mInputStream;
	}
	if (mOutputStream) {
		delete mOutputStream;
	}
	if (mPeerDevice) {
		delete mPeerDevice;
	}
	if (mPeerSocket) {
		delete mPeerSocket;
	}
}

void OpUnitPeer::run()
{
	int i = 0;
	int error = 0;

	string buffer = "";
	mAlive = mInputStream && mOutputStream;

    while (mAlive) {
    	error = mInputStream->read(buffer, 1024);

    	if (error) {
    		mAlive = false;
    	}
    	if (!error) {
			BODrop* boDrop = w->boHandlerDrop->unpack(buffer);
			w->aBODrop.push_back(boDrop);
			w->activity->send((NParam)w->alpha00, (NParam)boDrop);
		}
    	this_thread::sleep_for(chrono::milliseconds(300));
    }
	cancel();
}

int OpUnitPeer::write(String packet)
{
	int error = 1;

    if (mAlive) {
    	error = mOutputStream->write(packet);
    }
	if (error) {
		mAlive = false;
	}
    return error;
}

void OpUnitPeer::cancel()
{
	mAlive = false;
	mInputStream->close();
	mOutputStream->close();
	mPeerSocket->close();
}

} // End namespace
