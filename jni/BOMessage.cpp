#include "Common.h"

namespace NSDEVICE
{

BOHandlerMessage::BOHandlerMessage(Wrapper* w)
    : w(w)
{
    h = w->dbh->get("Drop");
}

BOHandlerMessage::~BOHandlerMessage()
{
}

DBCollection* BOHandlerMessage::getDrops()
{
    return h->getCollection()->filter(f("mac", w->mac, "!="), f("archived", w->dbh->FALSE, "="), "AND");
}

DBCollection* BOHandlerMessage::getSeeds()
{
    return h->getCollection()->filter("mac", w->mac, "=");
}

DBObject* BOHandlerMessage::addSeed(const String& id_cat, const String& title, const String& text)
{
    String aValue[] = {
        w->mac,
        "",
        id_cat,
        to_string(steady_clock::now().time_since_epoch().count()),
        title,
        text,
        w->dbh->FALSE,
    };
    DBObject* vDBObject = h->getInstance()->set(aValue, sizeof(aValue)/sizeof(string))->commit();
    vDBObject->set("id_drop", vDBObject->get("id"))->commit();
    return vDBObject;
}

DBObject* BOHandlerMessage::addDrop(String packed)
{
    //FIXME: UTF8 compatibility
    int i;
    vector<string> aValue = split(packed, String("1#"));

    for (i = 0 ; i < (int)aValue.size() ; ++i) {
        aValue[i] = regex_replace(aValue[i], regex("@(@|#)"), String("$1"));
    }
    DBObject* vDBObject = h->getInstance()->set(aValue.data(), aValue.size());
    DBCollection* c = h->getCollection()->filter(f("mac", vDBObject->get("mac"), "="), f("id_drop", vDBObject->get("id_drop"), "="), "AND");

    if (c->count() > 0) {
        delete vDBObject;
        vDBObject = h->getInstance(c->get(0)->get("id"))->set(aValue.data(), aValue.size());
    }
    delete c;
    return vDBObject->set("archived", w->dbh->FALSE)->commit();
}

String BOHandlerMessage::pack(DBObject* vDBObject)
{
    //FIXME: UTF8 compatibility
    int i;
    String packed = "";
    String first = "";
    String* aValue = vDBObject->get();

    for ( i = 1 ; i < h->mDBTable->cField ; ++i ) {
        packed += first + regex_replace(aValue[i], regex("(@|#)"), String("@$1"));
        first = "1#";
    }
    return packed;
}

} // End namespace
