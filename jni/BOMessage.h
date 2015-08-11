#ifndef __BOHandlerMessage_H__
#define __BOHandlerMessage_H__

namespace NSDEVICE
{

class BOHandlerMessage : public DBHelper
{
public:
    BOHandlerMessage(Wrapper* w);
    virtual ~BOHandlerMessage();

    void addDrop(OpUnitUI* vOpUnitUI, String packed);
    DBObject* addSeed(const String& id_cat, const String& title, const String& text, const String& link);
    void clean();
    DBObject* get(nuint id);
    DBCollection* getMessagesToBroadcast();
    DBCollection* getMessagesToDisplay();
    String pack(DBObject* vDBObject);
    String packId(DBObject* vDBObject);
    void setMessage(DBObject* vDBObject, const String& id_cat, const String& title, const String& text, const String& link);
    DBObject* setMessage(nuint vcDBObjectId, const String& id_cat, const String& title, const String& text, const String& link);

    Wrapper* w;
    DBTableHandler* h;
};

} // End namespace

#endif
