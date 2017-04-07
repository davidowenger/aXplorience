#ifndef __Tables_H__
#define __Tables_H__

namespace NSDEVICE
{

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
        };
    }
};

class Table_Message : public DBTable
{
    void init() {
        aField = {
            "Id",
            // Key
            "MacSrc",
            "MacDst",
            "MessageId",
            "RevSrc",
            // Keep-alive
            "EarthCoordX",
            "EarthCoordY",
            "EarthCoordZ",
            // Source Data
            "CategoryId",
            "Title",
            "Text",
            "Link",
            "ArchivedSrc",
            // User Data
            "Type",
            "Date",
            "Buzzed",
            "Enabled",
            "Deleted"
        };
    }
};

} // End namespace

#endif
