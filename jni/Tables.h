#ifndef __Tables_H__
#define __Tables_H__

namespace NSDEVICE
{

class Table_Message : public DBTable
{
	void init() {
		aField = {
			"id",
			"mac",
			"id_drop",
            "in",
			"id_cat",
			"date",
			"title",
			"text",
			"link",
			"sEnabled",
            "sDeleted",
            "sArchivedAuto",
            "sArchivedUser",
            "sBuzzed",
            "sBuzzedIndex",
		};
	}
};

class Table_Application : public DBTable
{
	void init() {
		aField = {
			"id",
            "sDBObjectId",
            "sView",
			"sSort",
			"sAscending",
			"sBluetooth",
			"sDiscoverable",
			"sCategory0",
			"sCategory1",
			"sCategory2",
			"sCategory3",
		};
	}
};

} // End namespace

#endif
