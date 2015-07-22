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
            "sIn",
			"sCategoryId",
			"date",
			"sTitle",
			"text",
			"link",
			"sEnabled",
            "sDeleted",
            "sArchivedAuto",
            "sArchivedUser",
            "sBuzzed",
            "sBuzzedIndex",
            "sBuzzing",
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
            "sSort0",
            "sAscending0",
            "sSort1",
            "sAscending1",
            "sSort2",
            "sAscending2",
			"sCategory0",
			"sCategory1",
			"sCategory2",
			"sCategory3",
		};
	}
};

} // End namespace

#endif
