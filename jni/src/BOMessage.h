#ifndef __BOMessage_H__
#define __BOMessage_H__

namespace NSDEVICE
{

class BOMessageHandler : public DBHelper
{
public:
    BOMessageHandler(Wrapper* w);
    virtual ~BOMessageHandler();

    void add(const String& vMac, nfloat vLat, nfloat vLong, const String& vTitle, const String& vType);
    DBObject* add(const String& vMac, nfloat vLat, nfloat vLong, const String& vCategoryId, const String& vTitle, const String& vText, const String& vLink, const String& vType);
    DBObject* add(const String& vMac, nfloat x, nfloat y, nfloat z, const String& vCategoryId, const String& vTitle, const String& vText, const String& vLink, const String& vType);
    void addDrop(OpUnitDB* vOpUnitDB, String packed);
    DBObject* addSeed(const String& id_cat, const String& title, const String& text, const String& link);
    void clean();
    DBObject* get(nuint id);
    DBCollection* getMessagesStatic();
    DBCollection* getMessagesDynamic();
    DBCollection* getMessagesToBroadcast();
    DBCollection* getMessagesToDisplay();
    DBCollection* getMessagesToList();
    DBCollection* getMessagesToPosition();
    String pack(DBObject* vDBObject);
    String packId(DBObject* vDBObject);
    void setPOI(const String& vMac, nfloat vLat, nfloat vLong, const String& title, const String& text);
    void setMessage(DBObject* vDBObject, const String& id_cat, const String& title, const String& text, const String& link);
    DBObject* setMessage(nuint vcDBObjectId, const String& id_cat, const String& title, const String& text, const String& link);

    Wrapper* w;
    DBTableHandler* mTableMessageHandler;
    NArray<String> maKey;
};

} // End namespace

#endif
