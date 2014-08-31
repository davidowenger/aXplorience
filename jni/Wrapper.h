#ifndef __Wrapper_H__
#define __Wrapper_H__

namespace NSDEVICE
{

class Wrapper : public NWrapper
{
public:
    String sFileDir;
	LinearLayout* layout;
	NActivity* activity;

    DBHandler* dbh;

    String mac;
    String sServiceName;
    String sUuid;
    String sUuidSuffix;
	BluetoothAdapter* dBluetoothAdapter;
	vector<BluetoothDevice*> aDiscoveredDevice;
	unsigned long long cNextClientUuid;
	unsigned long long cNextServerUuid;

	int cMaxOpUnit;
	OpSquad* opSquad;
	OpUnitCore* opUnitCore;
	OpUnitServer* opUnitServer;
	OpUnitPeer** aPeer;

	BOHandlerDrop* boHandlerDrop;
	DBCollection* aBOSeed;
	vector<BODrop*> aBODrop;
};

} // End namespace

#endif
