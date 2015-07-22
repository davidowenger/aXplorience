#ifndef __BOHandlerMessage_H__
#define __BOHandlerMessage_H__

namespace NSDEVICE
{

class BOHandlerMessage : public DBHelper
{
public:
    BOHandlerMessage(Wrapper* w);
    virtual ~BOHandlerMessage();

    nuint addDrop(String packed);
    nuint addSeed(const String& id_cat, const String& title, const String& text, const String& link);
    DBObject* get(nuint id);
    DBCollection* getDrops();
  //DBCollection* getMessages();
  //DBCollection* getMessagesSorted();
    DBCollection* getMessagesToBroadcast();
    DBCollection* getMessagesToDisplay();
    DBCollection* getSeeds();
    String pack(DBObject* vDBObject);
    void setMessage(nuint id, const String& id_cat, const String& title, const String& text, const String& link);

    Wrapper* w;
    DBTableHandler* h;
};

//class BOMessage : public DBHelper
//{
//public:
//    virtual ~BOMessage();
//
//    String pack();
//
//    Wrapper* w;
//    DBTableHandler* h;
//    DBObject* mDBObject;
//
//protected:
//    BOMessage(Wrapper* w);
//    BOMessage(Wrapper* w, DBObject* vDBObject);
//};
//
//class BOSeed : public BOMessage
//{
//public:
//    BOSeed(Wrapper* w, DBObject* vDBObject);
//    BOSeed(Wrapper* w, const String& id_cat, const String& title, const String& text);
//    virtual ~BOSeed();
//};
//
//class BODrop : public BOMessage
//{
//public:
//	BODrop(Wrapper* w, DBObject* vDBObject);
//    BODrop(Wrapper* w, String packed);
//    virtual ~BODrop();
//};

} // End namespace

#endif
