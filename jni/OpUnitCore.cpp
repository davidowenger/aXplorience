#include "Common.h"

namespace NSDEVICE
{

OpUnitCore::OpUnitCore(Wrapper* w)
	: OpUnit(w), mw(w), mcProcessedDevice(0)
{
	mClientSocket = nullptr;
	mInputStream = nullptr;
	mOutputStream = nullptr;
	mAlive = false;
}

OpUnitCore::~OpUnitCore()
{
}

void OpUnitCore::run()
{
	//00000000-0000-07da-0000-0000000007d0
	//UUID(2010L,2000L);
	//00000000-0000-07db-0000-0000000007d0
	//UUID(2010L,2000L);
	//00000000-0000-07dc-0000-0000000007d0
	//00001101-0000-1000-8000-00805F9B34FB
	//00001101-0000-1000-8000-00805F9B34FB
	//00001101-0000-1000-8000-00805F9B34FB
	//

	int i = 0;
	int error = 0;
	unsigned long long nextUuid = 0;
	String buffer("");

	mw->dbh = new DBHandler(mw);
	mw->dbh->add<Table_Drop>("Drop");

	mw->boHandlerDrop = new BOHandlerDrop(mw);
	mw->opUnitServer = new OpUnitServer(mw);
	mw->aPeer = new OpUnitPeer*[mw->cMaxOpUnit];
	mw->sServiceName = "Proximity service";
	mw->sUuid = "0000F9B3-0000-0000-0000-";
	mw->sUuidSuffix = "000000000000";
	mw->cNextClientUuid = 1;

	for ( i = 0 ; i < mw->cMaxOpUnit ; ++i ) {
		mw->aPeer[i] = nullptr;
	}
	mw->boHandlerDrop->addSeed("1", "droped message", "Hello World!");
	mw->mac = mw->dBluetoothAdapter->getAddress();
	mw->dBluetoothAdapter->enable();
	mw->dBluetoothAdapter->discoverable();
	mw->opSquad->add(mw->opUnitServer)->start();

	steady_clock::time_point cTimeStart = steady_clock::time_point();
	steady_clock::time_point cTimeStop = steady_clock::time_point();
	steady_clock::time_point cTimeBroadcast = steady_clock::time_point();

    while (mAlive) {
    	if (mw->dBluetoothAdapter->isEnabled()) {
    		if (steady_clock::now() - cTimeStop > seconds(20)) {
    			cTimeStart = steady_clock::now();
    			mw->dBluetoothAdapter->startDiscovery();
    		}
    		if (steady_clock::now() - cTimeStart > seconds(10)) {
    			cTimeStop = steady_clock::now();
    			mw->dBluetoothAdapter->cancelDiscovery();
    		}
    		if (steady_clock::now() - cTimeBroadcast > seconds(10)) {
    			cTimeBroadcast = steady_clock::now();

				for (i = 0 ; i < mw->cMaxOpUnit ; ++i) {
					if (mw->aPeer[i] && !mw->aPeer[i]->mAlive) {
						delete mw->aPeer[i];
						mw->aPeer[i] = nullptr;
					}
					if (mw->aPeer[i]) {
						for (i = 0 ; i < mw->aBOSeed->count() ; ++i) {
							error = mw->aPeer[i]->write(BODrop(mw, mw->aBOSeed->get(i)).pack());
						}
					}
				}
			}
			while (mAlive && mw->aDiscoveredDevice.size() > mcProcessedDevice) {
				error = 0;
		    	buffer = "";
				mClientSocket = mw->aDiscoveredDevice[mcProcessedDevice]->createInsecureRfcommSocketToServiceRecord(mw->sUuid + mw->sUuidSuffix);

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
					mOutputStream = mClientSocket->getOutputStream();
					mInputStream = mClientSocket->getInputStream();
					error = !mInputStream || !mOutputStream;
				}
				if (mw->cNextServerUuid > mw->cNextClientUuid) {
					mw->cNextClientUuid = mw->cNextServerUuid;
				}
				if (!error) {
			    	error = mOutputStream->write(to_string(mw->cNextClientUuid));
				}
				if (!error) {
			    	error = mInputStream->read(buffer, 1024);
				}
				if (!error) {
		            error = to_long(buffer, nextUuid) || nextUuid > 999999999999;
				}
				if (!error && nextUuid > mw->cNextClientUuid) {
	            	mw->cNextClientUuid = nextUuid;
				}
				if (!error) {
					buffer = to_string(mw->cNextClientUuid);
					buffer = mw->sUuidSuffix.substr(0, 12 - buffer.length()) + buffer;
					mClientSocket = mw->aDiscoveredDevice[mcProcessedDevice]->createInsecureRfcommSocketToServiceRecord(mw->sUuid + buffer);

					if (mClientSocket) {
						error = mClientSocket->connect();
					}
					if (error) {
						mClientSocket->close();
						mClientSocket = nullptr;
					}
					if (mClientSocket) {
						OpUnitPeer* peer = new OpUnitPeer(mw, mClientSocket, mw->cNextClientUuid++);
						mw->opSquad->add(peer);
						mw->aPeer[peer->mId] = peer;
						peer->start();
					}
				}
				mcProcessedDevice++;
			}
    	}
    	this_thread::sleep_for(chrono::milliseconds(300));
    }
}

NReturn OpUnitCore::visit(NAlpha00* element, NParam a, NParam b, NParam c, NParam d)
{
	TextView* textViewDrop = new TextView(mw->dActivity);
	textViewDrop->setTextSize(20);
	textViewDrop->setText(((BODrop*)a)->o->get("text"));
	mw->layout->addView(textViewDrop);
	return 0;
}

} // End namespace
