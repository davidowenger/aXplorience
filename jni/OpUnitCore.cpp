#include "Common.h"

namespace NSDEVICE
{

OpUnitCore::OpUnitCore(Wrapper* w)
	: OpUnit(w), w(w), mcProcessedDevice(0)
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

	w->dbh = new DBHandler(w);
	w->dbh->add<Table_Drop>("Drop");

	w->boHandlerDrop = new BOHandlerDrop(w);
	w->layout = new LinearLayout(w->activity);
	w->dBluetoothAdapter = new BluetoothAdapter();
	w->opUnitServer = new OpUnitServer(w);
	w->aPeer = new OpUnitPeer*[w->cMaxOpUnit];
	w->sServiceName = "Proximity service";
	w->sUuid = "0000F9B3-0000-0000-0000-";
	w->sUuidSuffix = "000000000000";
	w->cNextClientUuid = 1;

	for ( i = 0 ; i < w->cMaxOpUnit ; ++i ) {
		w->aPeer[i] = nullptr;
	}
	w->boHandlerDrop->addSeed("1", "droped message", "Hello World!");
	w->activity->setContentView((View*)w->layout);
	w->mac = w->dBluetoothAdapter->getAddress();
	w->dBluetoothAdapter->enable();
	w->dBluetoothAdapter->discoverable();
	w->opSquad->add(w->opUnitServer)->start();

    while (mAlive) {
    	if (w->dBluetoothAdapter->isEnabled()) {
    		w->dBluetoothAdapter->startDiscovery();

			while (mAlive && w->aDiscoveredDevice.size() > mcProcessedDevice) {
				error = 0;
		    	buffer = "";
				mClientSocket = w->aDiscoveredDevice[mcProcessedDevice]->createInsecureRfcommSocketToServiceRecord(w->sUuid + w->sUuidSuffix);

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
				if (w->cNextServerUuid > w->cNextClientUuid) {
					w->cNextClientUuid = w->cNextServerUuid;
				}
				if (!error) {
			    	error = mOutputStream->write(to_string(w->cNextClientUuid));
				}
				if (!error) {
			    	error = mInputStream->read(buffer, 1024);
				}
				if (!error) {
		            error = to_long(buffer, nextUuid) || nextUuid > 999999999999;
				}
				if (!error && nextUuid > w->cNextClientUuid) {
	            	w->cNextClientUuid = nextUuid;
				}
				if (!error) {
					buffer = to_string(w->cNextClientUuid);
					buffer = w->sUuidSuffix.substr(0, 12 - buffer.length()) + buffer;
					mClientSocket = w->aDiscoveredDevice[mcProcessedDevice]->createInsecureRfcommSocketToServiceRecord(w->sUuid + buffer);

					if (mClientSocket) {
						error = mClientSocket->connect();
					}
					if (error) {
						mClientSocket->close();
						mClientSocket = nullptr;
					}
					if (mClientSocket) {
						OpUnitPeer* peer = new OpUnitPeer(w, mClientSocket, w->cNextClientUuid++);
						w->opSquad->add(peer);
						w->aPeer[peer->mId] = peer;
						peer->start();
					}
				}
				mcProcessedDevice++;
			}
			for (i = 0 ; i < w->cMaxOpUnit ; ++i) {
				if (w->aPeer[i] && !w->aPeer[i]->mAlive) {
					delete w->aPeer[i];
					w->aPeer[i] = nullptr;
				}
				if (w->aPeer[i]) {
					for (i = 0 ; i < w->aBOSeed->count() ; ++i) {
						error = w->aPeer[i]->write(BODrop(w, w->aBOSeed->get(i)).pack());
					}
				}
			}
    		w->dBluetoothAdapter->cancelDiscovery();
    	}
    	this_thread::sleep_for(chrono::milliseconds(300));
    }
}

NReturn OpUnitCore::visit(NAlpha00* element, NParam a, NParam b, NParam c, NParam d)
{
	TextView* textViewDrop = new TextView(w->activity);
	textViewDrop->setTextSize(20);
	textViewDrop->setText(((BODrop*)a)->o->get("text"));
	w->layout->addView(textViewDrop);
	return 0;
}

} // End namespace
