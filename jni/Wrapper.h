#ifndef __Wrapper_H__
#define __Wrapper_H__

namespace NSDEVICE
{

class Wrapper
{
public:
    static const int OPUNIT_TYPE_NONE = 0;
    static const int OPUNIT_TYPE_DEFAULT = OPUNIT_TYPE_NONE + 1;
    static const int OPUNIT_TYPE_PEER = OPUNIT_TYPE_DEFAULT + 1;
    static const int OPUNIT_TYPE_LISTENER = OPUNIT_TYPE_PEER + 1;

	NWrapper* w;

    String sFileDir;
	LinearLayout* layout;
    DBHandler* dbh;

    std::string mac;
    std::string sServiceName;
    std::string sUuidService;
    std::string sUuidPeer;
    std::string sUuidSuffix;
    std::string sUuidMacSuffix;
	BluetoothAdapter* dBluetoothAdapter;
    Col<BluetoothDevice*> aDiscoveredDevice;

	int cMaxOpUnit;
	OpSquad* opSquad;
	OpUnitCore* opUnitCore;
	OpUnitServer* opUnitServer;
	OpUnitPeer** aPeer;

	Mutex mMutexDiscovery;
    TimeStamp mcTimeStampStart;
    TimeStamp mcTimeStampStop;

	BOHandlerMessage* mBOHandlerMessage;
	DBCollection* aBOSeed;
	vector<DBObject*> aBODrop;
};

} // End namespace

#endif
