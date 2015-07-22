#include "Common.h"

namespace NSDEVICE
{

BOHandlerMessage::BOHandlerMessage(Wrapper* w)
    : w(w)
{
    h = w->dbh->get("Message");
}

BOHandlerMessage::~BOHandlerMessage()
{
}

nuint BOHandlerMessage::addDrop(String packed)
{
    //FIXME: UTF8 compatibility
    int i;
    TimeStamp vcTimeStampNow = system_clock::now().time_since_epoch().count();
    vector<string> aValue = split(packed, String("1#"));
    nuint vcDBObjectId = 0;

    for (i = 0 ; i < (int)aValue.size() ; ++i) {
        aValue[i] = regex_replace(aValue[i], regex("@(@|#)"), String("$1"));
    }
    DBObject* vReceived = h->getInstance()->set(aValue.data(), aValue.size());
    DBCollection* c = h->getCollection()->filter("mac", vReceived->get("mac"), "=")->filter("id_drop", vReceived->get("id_drop"), "=");

    if (c->count() > 0) {
        DBObject* vExisting = c->get(0);
        vcDBObjectId = (nuint)to_long(vExisting->get("id"));

        if (!vExisting->is("sIn")) {
            if (!vExisting->is("sBuzzed") && vReceived->is("sBuzzed") && vExisting->get("sBuzzedIndex") == vReceived->get("sBuzzedIndex")) {
                if (!vExisting->is("sArchivedUser")) vExisting->set("sBuzzed", true);
                vExisting->set("sBuzzedIndex", (nuint)vExisting->count("sBuzzedIndex") + 1);
                vExisting->set("sBuzzing", true);
            }
        } else {
            setMessage(vcDBObjectId, vReceived->get("sCategoryId"), vReceived->get("sTitle"), vReceived->get("text"), vReceived->get("link"));
            vExisting->set("date", vReceived->get("date"));
            vExisting->set("sArchivedAuto", vcTimeStampNow - vReceived->count("date") > 6*w->mc10Secondes);
            vExisting->set("sArchivedUser", vReceived->get("sArchivedUser"));

            if (vExisting->is("sBuzzed") && !vReceived->is("sBuzzed") && vExisting->count("sBuzzedIndex") < vReceived->count("sBuzzedIndex")) {
                vExisting->set("sBuzzed", false);
            }
            if (!vExisting->is("sBuzzed")) {
                vExisting->set("sBuzzedIndex", vReceived->get("sBuzzedIndex"));
            }
        }
        vExisting->commit();
    } else {
        vReceived->set("sIn", true);
        vReceived->set("sEnabled", true);
        vReceived->set("sDeleted", false);
        vReceived->set("sArchivedAuto", vcTimeStampNow - vReceived->count("date") > 6*w->mc10Secondes);
        vReceived->set("sArchivedUser", false);
        vReceived->set("sBuzzed", false);
        vReceived->commit();
        vcDBObjectId = (nuint)to_long(vReceived->get("id"));
    }
    delete vReceived;
    delete c;
    return vcDBObjectId;
}

nuint BOHandlerMessage::addSeed(const String& id_cat, const String& title, const String& text, const String& link)
{
    DBObject* vDBObject = h->getInstance();
    vDBObject->set("mac", w->mac);
    vDBObject->set("sIn", false);
    vDBObject->set("date", system_clock::now().time_since_epoch().count());
    vDBObject->set("sEnabled", true);
    vDBObject->set("sDeleted", false);
    vDBObject->set("sArchivedAuto", false);
    vDBObject->set("sArchivedUser", false);
    vDBObject->set("sBuzzed", false);
    vDBObject->set("sBuzzedIndex", 0);
    vDBObject->commit();

    String vsDBObjectId = vDBObject->get("id");
    vDBObject->set("id_drop", vsDBObjectId);
    vDBObject->commit();
    delete vDBObject;

    nuint vcDBObjectId = (nuint)to_long(vsDBObjectId);
    setMessage(vcDBObjectId, id_cat, title, text, link);

    return vcDBObjectId;
}

DBObject* BOHandlerMessage::get(nuint id)
{
    return h->getInstance(to_string(id));
}

DBCollection* BOHandlerMessage::getDrops()
{
    return h->getCollection()->filter("id", "1", "!=")->filter("sDeleted", false, "=")->filter("sIn", true, "=");
}

//DBCollection* BOHandlerMessage::getMessages()
//{
//    return h->getCollection()->filter("id", "1", "!=")->filter("sArchivedAuto", false, "=");
//}

//DBCollection* BOHandlerMessage::getMessagesSorted()
//{
//    DBHelper n;
//    return h->getCollection()->filter("id", "1", "!=")->filter("sDeleted", false, "=")->filter("sArchivedAuto", false, "=")
//            ->filter(n.f("sIn", false, "="), n.f("sArchivedUser", false, "="), "OR")
//            ->sort(w->mDBObjectApplication->get("sSort"), w->mDBObjectApplication->is("sAscending"));
//}

DBCollection* BOHandlerMessage::getMessagesToBroadcast()
{
    return h->getCollection()->filter("id", "1", "!=")->filter("sArchivedAuto", false, "=")
            ->filter(f("sIn", false, "="), f("sArchivedUser", false, "="), "OR");
}

DBCollection* BOHandlerMessage::getMessagesToDisplay()
{
    return h->getCollection()->filter("id", "1", "!=")->filter("sDeleted", false, "=")->filter("sArchivedAuto", false, "=")
            ->filter(f("sIn", false, "="), f("sArchivedUser", false, "="), "OR");
}

DBCollection* BOHandlerMessage::getSeeds()
{
    return h->getCollection()->filter("id", "1", "!=")->filter("sDeleted", false, "=")->filter("sIn", false, "=");
}

String BOHandlerMessage::pack(DBObject* vDBObject)
{
    //FIXME: UTF8 compatibility
    nuint i;
    String packed = "";
    String first = "";
    String* aValue = vDBObject->get();

    for ( i = 1 ; i < h->mDBTable->cField ; ++i ) {
        packed += first + regex_replace(aValue[i], regex("(@|#)"), String("@$1"));
        first = "1#";
    }
    return packed;
}

void BOHandlerMessage::setMessage(nuint id, const String& id_cat, const String& title, const String& text, const String& link)
{
    DBObject* vDBObject = h->getInstance(to_string(id));
    vDBObject->set("sCategoryId", id_cat);
    vDBObject->set("sTitle", title);
    vDBObject->set("text", text);
    vDBObject->set("link", link);
    vDBObject->commit();
    delete vDBObject;
}

} // End namespace
