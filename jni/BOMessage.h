#ifndef __BOHandlerMessage_H__
#define __BOHandlerMessage_H__

namespace NSDEVICE
{

class BOHandlerMessage : public DBHelper
{
public:
    BOHandlerMessage(Wrapper* w);
    virtual ~BOHandlerMessage();

    DBCollection* getDrops();
    DBCollection* getSeeds();
    DBObject* addSeed(const String& id_cat, const String& title, const String& text);
    DBObject* addDrop(String packed);
    String pack(DBObject* vDBObject);

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
