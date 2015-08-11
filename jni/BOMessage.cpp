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

void BOHandlerMessage::addDrop(OpUnitUI* vOpUnitUI, String packed)
{
    //FIXME: UTF8 compatibility
    nint i;
    DBCollection* vDBCollection;
    DBObject* vExisting;
    DBObject* vReceived;
    vector<string> aValue = split(packed, String("1#"));
    nulong vSize = aValue.size();

    if (vSize >= 5) {
        vDBCollection = h->getCollection()->filter("sIdMessage", aValue[0], "=")->filter("mac", aValue[1], "=");

        if (vDBCollection->count()) {
            vExisting = vDBCollection->get(0);

            if (vExisting->is("sIn") && vExisting->count("sRevBuzz") == to_long(aValue[3]) && vExisting->count("sRevRemote") < to_long(aValue[4])) {
                // Remote buzz request on INBOUND message
                ++w->mcInterrupt;
                vExisting->set("sRevRemote", aValue[4]);
                w->maMessageBuzz->add(new String("2#" + packId(vExisting) + "3#"));
            }
            if (!vExisting->is("sIn") && !vExisting->is("sArchivedUser") && vExisting->get("sRevBuzz") == aValue[3] && vExisting->get("sRevRemote") != aValue[4]) {
                // Buzzed OUTBOUND message
                ++w->mcInterrupt;
                vOpUnitUI->sendOp(w->mOpUnitAnimId, nullptr, new OpParam(vExisting->mId));
                vExisting->set("sRevBuzz", vExisting->count("sRevBuzz") + 1);
                vExisting->set("sRevRemote", "1");
                w->maMessageBuzz->add(new String("2#" + packId(vExisting) + "3#"));
                vExisting->set("sBuzzed", kTrue);
                vOpUnitUI->sendOp(w->mOpUnitAppId, w->w->mNEta01, new OpParam((NParam)get(vExisting->mId)));
            }
            if (vExisting->is("sIn") && vExisting->count("sRevSource") < to_long(aValue[2])) {
                // Alive INBOUND message
                bool vIsArchivedAuto = vExisting->is("sArchivedAuto");
                vExisting->set("sRevSource", aValue[2]);
                vExisting->set("date", vOpUnitUI->mcTimeStampNow);
                vExisting->set("sArchivedAuto", kFalse);

                if (vSize > 5) {
                    // Updated INBOUND message
                    w->maMessageUpdate->add(new String("2#" + packed + "3#"));
                    //TODO: apply regex at split
                    i = vSize;

                    while (--i >= 0) {
                        aValue[i] = regex_replace(aValue[i], regex("@(@|#)"), String("$1"));
                    }
                    //FIXME: do not use temporary database object
                    vReceived = h->getInstance()->set(aValue.data(), vSize);
                    vExisting->set("sArchivedUser", vReceived->get("sArchivedUser"));
                    setMessage(vExisting, vReceived->get("sCategoryId"), vReceived->get("sTitle"), vReceived->get("text"), vReceived->get("link"));
                    vReceived->drop();
                    vOpUnitUI->sendOp(w->mOpUnitAppId, w->w->mNGamma01, new OpParam((NParam)getMessagesToDisplay()->sort(w->maSort)));
                    delete vReceived;
                }
                if (vSize == 5 && vIsArchivedAuto && !vExisting->is("sArchivedUser") && !vExisting->is("sDelete")) {
                    vOpUnitUI->sendOp(w->mOpUnitAppId, w->w->mNGamma01, new OpParam((NParam)getMessagesToDisplay()->sort(w->maSort)));
                }
            }
            if (vExisting->is("sIn") && vExisting->count("sRevBuzz") < to_long(aValue[3])) {
                // Response to buzzed INBOUND message
                ++w->mcInterrupt;
                vExisting->set("sRevBuzz", aValue[3]);
                vExisting->set("sRevRemote", aValue[4]);
                w->maMessageBuzz->add(new String("2#" + packId(vExisting) + "3#"));
                vExisting->set("sBuzzed", kFalse);
                vOpUnitUI->sendOp(w->mOpUnitAppId, w->w->mNEta01, new OpParam((NParam)get(vExisting->mId)));
            }
        } else if (vSize > 5) {
            // New INBOUND message
            //TODO: apply regex at split
            i = vSize;

            while (--i >= 0) {
                aValue[i] = regex_replace(aValue[i], regex("@(@|#)"), String("$1"));
            }
            //FIXME: do not use temporary database object values
            vReceived = h->getInstance()->set(aValue.data(), aValue.size());
            vReceived->set("sIn", kTrue);
            vReceived->set("date", vOpUnitUI->mcTimeStampNow);
            vReceived->set("sEnabled", kTrue);
            vReceived->set("sBuzzed", kFalse);
            vReceived->set("sDeleted", kFalse);
            vReceived->set("sArchivedAuto", kFalse);
            w->maMessageUpdate->add(new String("2#" + pack(vReceived) + "3#"));
            vOpUnitUI->sendOp(w->mOpUnitAppId, w->w->mNGamma01, new OpParam((NParam)getMessagesToDisplay()->sort(w->maSort)));
            delete vReceived;
        }
        delete vDBCollection;
    }
}

DBObject* BOHandlerMessage::addSeed(const String& id_cat, const String& title, const String& text, const String& link)
{
    DBObject* vDBObject = h->getInstance();
    vDBObject->set("sIdMessage", vDBObject->mId);
    vDBObject->set("mac", w->mac);
    vDBObject->set("sRevSource", "1");
    vDBObject->set("sRevBuzz", "1");
    vDBObject->set("sRevRemote", "1");
    vDBObject->set("sArchivedUser", kFalse);
    vDBObject->set("sIn", kFalse);
    vDBObject->set("date", system_clock::now().time_since_epoch().count());
    vDBObject->set("sEnabled", kTrue);
    vDBObject->set("sBuzzed", kFalse);
    vDBObject->set("sDeleted", kFalse);
    vDBObject->set("sArchivedAuto", kFalse);
    setMessage(vDBObject, id_cat, title, text, link);
    return vDBObject;
}

void BOHandlerMessage::clean()
{
    nint i;
    DBCollection* vDBCollection = h->getCollection()->filter(
        f(f("sIn", kFalse, "="), f("sDeleted", kTrue, "="), "AND"),
        f(f("sIn", kTrue, "="), f("sArchivedAuto", kTrue, "="), "AND"),
        "OR"
    );
    nint vCount = vDBCollection->count();

    for (i = 0 ; i < vCount ; ++i) {
        vDBCollection->get(i)->drop();
    }
    delete vDBCollection;
}

DBObject* BOHandlerMessage::get(nuint id)
{
    return h->getInstance(id);
}

DBCollection* BOHandlerMessage::getMessagesToBroadcast()
{
    return h->getCollection()->filter("sId", "1", "!=")
            ->filter("sArchivedAuto", kFalse, "=");
}

DBCollection* BOHandlerMessage::getMessagesToDisplay()
{
    return h->getCollection()->filter("sId", "1", "!=")
            ->filter(f("sIn", kFalse, "="), f("sArchivedAuto", kFalse, "="), "OR")
            ->filter(f("sIn", kFalse, "="), f("sArchivedUser", kFalse, "="), "OR")
            ->filter("sDeleted", kFalse, "=");
}

String BOHandlerMessage::pack(DBObject* vDBObject)
{
    //FIXME: UTF8 compatibility
    nuint i;
    String packed = "";
    String first = "";

    for ( i = 1 ; i < 11 ; ++i ) {
        packed += first + regex_replace(vDBObject->maValue[i], regex("(@|#)"), String("@$1"));
        first = "1#";
    }
    return packed;
}

String BOHandlerMessage::packId(DBObject* vDBObject)
{
    return vDBObject->maValue[1] + "1#" + vDBObject->maValue[2] + "1#" + vDBObject->maValue[3] + "1#" + vDBObject->maValue[4] + "1#" + vDBObject->maValue[5];
}

void BOHandlerMessage::setMessage(DBObject* vDBObject, const String& id_cat, const String& title, const String& text, const String& link)
{
    vDBObject->set("sCategoryId", id_cat);
    vDBObject->set("sTitle", title);
    vDBObject->set("text", text);
    vDBObject->set("link", link);
}

DBObject* BOHandlerMessage::setMessage(nuint vcDBObjectId, const String& id_cat, const String& title, const String& text, const String& link)
{
    DBObject* vDBObject = h->getInstance(vcDBObjectId);
    setMessage(vDBObject, id_cat, title, text, link);
    vDBObject->set("sRevSource", vDBObject->count("sRevSource") + 1);
    return vDBObject;
}

} // End namespace
