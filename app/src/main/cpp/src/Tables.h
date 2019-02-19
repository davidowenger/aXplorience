#ifndef __Tables_H__
#define __Tables_H__

namespace NSDEVICE
{

class Table_Message : public DBTable
{
    void init() {
        aField = {
            "sId",
            "sIdMessage",
            "mac",
            "sRevSource",
            "sRevBuzz",
            "sRevRemote",
            "sArchivedUser",
            "sCategoryId",
            "sTitle",
            "text",
            "link",
            "sIn",
            "date",
            "sEnabled",
            "sBuzzed",
            "sDeleted",
            "sArchivedAuto",
        };
    }
};

class Table_Application : public DBTable
{
    void init() {
        aField = {
            "sId",
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
            "sPseudoMac",
        };
    }
};

} // End namespace

#endif
